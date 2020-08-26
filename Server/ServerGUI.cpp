/* Server side. */
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#undef UNICODE
#define _WINSOCKAPI_   
#define WIN32_LEAN_AND_MEAN

#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <msclr/marshal_cppstd.h>
#include "ServerGUI.h"
#include "NewCarForm.h"
#include <list>


#pragma comment (lib, "Ws2_32.lib")

using namespace Server;
using namespace std;


// struct do carro produzido

struct palavraCar {
	string modelo;
	string versao;
	string motorizacao;
	string cor;
	string cabine;
	string mutimidia;
	string rodasLeve;
	string quantidade;
	int enviado;
};

//vetor das palavras
std::list<palavraCar> cList;
std::list<palavraCar>::iterator it;

// Função para iniciar o ambiente Winsock
bool InitWinsock2();
void ChangeText(System::Windows::Forms::RichTextBox^ textBox, System::String^ s);


// Função da Thread de comunicação
BOOL WINAPI ConnectionThread (LPVOID param);

// permite a thread alterar controle do windows forms
void bufferiza(System::String^ s);

System::String^ CharToString (char* c);
char* StringToChar(System::String^ s);
HANDLE hConnectionThread;

// Estrutura para armazenar info dos clientes
struct MISC_INFO
{
	SOCKET _sock;            // fd para o cliente
	gcroot<System::Windows::Forms::RichTextBox^> _textBox;

};

SOCKET hServerSocket;                              // fd para o socket do servidor (listening socket)
SOCKET hClientSocket;                              // fd para o socket do cliente
struct sockaddr_in serverAddr;                     // estrutura que comporta o enndereço do servidor

void ServerGUI::SetButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->SetButton->Enabled = false;
	this->CloseButton->Enabled = true;
	this->GetButton->Enabled = true;
	this->ArkButton->Enabled = true;
	this->SetCarButton->Enabled = true;
	//se bando de dados com itens
	this->DataButton->Enabled = true;

	this->trocaDados->Clear();

#pragma region InitWinsock
	/* Inicialização Winsock. */
	if (!InitWinsock2())
	{
		this->trocaDados->AppendText("Cant initialise winsock environment. Error: " + WSAGetLastError() + "\n"); 
		Close();
	}

#pragma endregion

#pragma region InitServer

	// inicializa o fd do servidor (infos)
	hServerSocket = socket(
		AF_INET,                     // Familia de endereços. AF_INET especifica TCP/IP
		SOCK_STREAM,                 // Tipo de protocolo (TCP/IP)
		0);                          // Nome do protocolo. Deve ser 0 se familia = AF_INET

	// verifica se deu certo
	if (hServerSocket == INVALID_SOCKET)
	{
		this->trocaDados->AppendText("Server socket could not be initd. Error: " + WSAGetLastError() + "\n"); 
		WSACleanup();    // limpa o ambiente Winsock
		Close();
	}

#pragma endregion

#pragma region ConfigServer

	/* Definição das propriedades do servidor. */
	string str = msclr::interop::marshal_as<string>(this->textBox1->Text);
	char *ip = new char[str.length() + 1];
	//strcpy(ip, str.c_str());
	strcpy_s(ip, str.length() + 1, str.c_str());

	int port = atoi(msclr::interop::marshal_as<string>(this->textBox2->Text).c_str());


	serverAddr.sin_family = AF_INET;                     // ipv4 como protocolo de rede
	serverAddr.sin_addr.s_addr = inet_addr(ip);          // ip local (por enquanto)
	serverAddr.sin_port = htons(port);                   // porta socket (1111)

	this->trocaDados->AppendText("Server has been configured successfully.\n");
	cout << "Server has been configured with address " << ip << " at port " << port << endl;

#pragma endregion

#pragma region BindServer

	/* Hora de fazer o bind do servidor. */
	if (bind(hServerSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Couldnt bind to port " << port << ". Error: " << WSAGetLastError() << endl; 
		closesocket(hServerSocket);
		WSACleanup();
		delete [] ip;
		Close();
	}

	this->trocaDados->AppendText("Server has been binded.\n");

#pragma endregion

#pragma region ListenServer

	/* Hora de fazer servidor escutar na porta especificada. */
	if (listen(hServerSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << "Couldnt listen at port " << port << ". Error: " << WSAGetLastError() << endl; 
		// limpar o ambiente Winsock
		closesocket(hServerSocket);
		WSACleanup();
		delete [] ip;
		Close();

	}

	this->trocaDados->AppendText("Listener has been set.\n");


#pragma endregion

#pragma region ConnClient

	/* for accepting connection, we have to throw a new thread, responsible for that
	stuff needed for accepting connections:
	- server's socket fd;
	*/
	DWORD dwThreadID;

	MISC_INFO *ms = new MISC_INFO;
	ms->_sock = hServerSocket;
	ms->_textBox = this->trocaDados;

	hConnectionThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ConnectionThread, (LPVOID)ms, 0, &dwThreadID);
	this->GetButton->Enabled = true;

#pragma endregion

#pragma region KillServer

	/*
	closesocket(hServerSocket);
	WSACleanup();
	*/

#pragma endregion

}

void ServerGUI::CloseButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->SetButton->Enabled = true;
	this->CloseButton->Enabled = false;
	this->GetButton->Enabled = false;
	this->ArkButton->Enabled = false;
	this->SetCarButton->Enabled = false;
	//se bando de dados com itens
	this->DataButton->Enabled = true;



	closesocket(hServerSocket);
	CloseHandle(hConnectionThread);
	this->trocaDados->AppendText("Server has been closed. \n");
	WSACleanup();
}

int contCheck = 0;
//Mudando o pedido requerido
void ServerGUI::GetButton_Click(System::Object^ sender, System::EventArgs^ e)
{

	// agora vem a parte de escrever no socket (mandar msg pro cliente)
	int nCntSend = 0;
	System::String^ out_msg = "MandaNudes";
	char* pBuffer = StringToChar(out_msg);
	int nLength = strlen(pBuffer);

	if (send(hClientSocket, pBuffer, nLength, 0) == SOCKET_ERROR)
	{
		// falhou o envio
		this->trocaDados->AppendText("Client seems to have disconnected.\n");

	}
	else
	{
		this->trocaDados->AppendText("Sent: '" + out_msg + "'\n");
	}

	contCheck = 1;
}


//Get arquivo de login do diretorio
System::Void Server::ServerGUI::ArkButton_Click(System::Object^ sender, System::EventArgs^ e) {
}

// Cadastro novo carro	
System::Void Server::ServerGUI::SetCarButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Form^ rgForm = gcnew Server::NewCarForm(this);
	rgForm->Show();
}

//Mostra bando de Dados Atualizado
System::Void Server::ServerGUI::DataButton_Click(System::Object^ sender, System::EventArgs^ e) {
}


bool InitWinsock2()
{
	WSADATA wsData;
	WORD wsaVersion = MAKEWORD(2, 0);    // usar a versão 2.0 do ambiente Winsock

	// retorna true se a inicialização foi bem sucedida
	if( ! WSAStartup(wsaVersion, &wsData) )
		return true;

	return false;

}

delegate void ChangeTextBoxDelegate (System::Windows::Forms::RichTextBox^ textBox, System::String^ s);

BOOL WINAPI ConnectionThread (LPVOID param)
{
	MISC_INFO *ms = (MISC_INFO*)param;

	SOCKET hServerSocket = ms->_sock;
	gcroot<System::Windows::Forms::RichTextBox^> STATUS_BOX = ms->_textBox;

	while (true)
	{
		struct sockaddr_in clientAddr;     // estrutura que contem os dados de endereço do cliente
		int nSize = sizeof(clientAddr);    // para usar em accept()

		// Aguarda até que um fdp se conecte
		cout << "Waiting for connection... " << endl;
		hClientSocket = accept(hServerSocket, (struct sockaddr*)&clientAddr, &nSize);
		if (hClientSocket == INVALID_SOCKET)
		{
			cout << "accept() has thrown an error: " << WSAGetLastError() << endl; 
			closesocket(hServerSocket);
			closesocket(hClientSocket);
			return FALSE;
			break;
		}

		std::string clientip(inet_ntoa(clientAddr.sin_addr));
		ChangeText(STATUS_BOX, "Client has connected!\n");

		// agora temos acesso às infos do cliente que se conectou
		char buffer[1024];       // armazena as mesnagens enviadas/recebidas pelo socket
		int nLength;             // armazena número de bytes lidos

		// servidor roda continuamente (aplicar métodos de parada)
		while (true)
		{
			nLength = recv(hClientSocket, buffer, sizeof(buffer), 0);   // lê o socket
			if (nLength > 0)
			{
				buffer[nLength] = '\0';   // finaliza o buffer até onde chegou info
				System::String^ message = "Recebe: " + CharToString(buffer) + " from " + CharToString(inet_ntoa(clientAddr.sin_addr)) + "\n";
				if (contCheck == 1)
				{
					bufferiza(CharToString(buffer));
				}

				ChangeText(STATUS_BOX, message);

				// Aqui é a parte que fazemos o eco (mandamos a mesma coisa pro cliente, só que em maiúsculo)
				//strupr(buffer);
				_strupr_s(buffer , strlen(buffer));

				// se for QUIT, o cliente quer fechar o socket
				if (strcmp(buffer, "QUIT") == 0)
				{
					closesocket(hClientSocket);
					ChangeText(STATUS_BOX, "Client has disconnected\n");
					break;
					return TRUE;

				}
			} else
			{
				std::cout << "Cant read data from: " << inet_ntoa(clientAddr.sin_addr) << std::endl;
				return FALSE;
			}

		} // fim do while (true)

		ExitThread(0);
		return 0;
	}
}

void ChangeText (System::Windows::Forms::RichTextBox^ textBox, System::String^ s)
{
	if (textBox->InvokeRequired)
	{
		ChangeTextBoxDelegate^ del = gcnew ChangeTextBoxDelegate(ChangeText);
		textBox->Invoke(del, textBox, s);
	} else 
	{
		textBox->AppendText(s);

	}
}

System::String^ CharToString (char* c)
{
	string str(c);
	return msclr::interop::marshal_as<String^>(str);
}

char* StringToChar(System::String^ s)
{
	string  str = msclr::interop::marshal_as<string>(s);
	char *c = new char[ str.size() ];
	//strcpy(c, str.c_str() );
	strcpy_s(c, str.length() + 1, str.c_str());
	return c;
}


//Bufferizador incompleto para criptografar os dados
void bufferiza(System::String^ s) {
	string str = msclr::interop::marshal_as<string>(s);
	palavraCar key;
	//lista vazia

#pragma region

	if (str.substr(0, 1) == "0") {
		//modelo Argo	
		key.modelo = "Argo";

	}
	else if (str.substr(0, 1) == "1") {
		//modelo strada
		key.modelo = "Strada";

	}
#pragma endregion

#pragma region

	if (str.substr(1, 1) == "0") {
		//versão Drive
		key.versao = "Drive";

	}
	else if (str.substr(1, 1) == "1") {
		//Treking
		key.versao = "Treking";

	}
	else if (str.substr(1, 1) == "2") {
		//HGT
		key.versao = "HGT";

	}
	else if (str.substr(1, 1) == "3") {
		//Endurance
		key.versao = "Endurace";

	}
	else if (str.substr(1, 1) == "4") {
		//Vulcano
		key.versao = "Vulcano";

	}
#pragma endregion

#pragma region

	if (str.substr(2, 1) == "0") {
		//motorizacao 1.0
		key.motorizacao = "1.0";

	}
	else if (str.substr(2, 1) == "1") {
		//Motor 1.3
		key.motorizacao = "1.3";

	}
	else if (str.substr(2, 1) == "2") {
		//Motor 1.8
		key.motorizacao = "1.8";

	}
#pragma endregion

#pragma region

	if (str.substr(3, 1) == "0") {
		//Cor Preto Vulcano
		key.cor = "Preto Vulcano";

	}
	else if (str.substr(3, 1) == "1") {
		key.cor = "Vermelho Monte Carlo";

		//Vermelho Monte Cralo
	}
	else if (str.substr(3, 1) == "2") {
		//Branco Banchista
		key.cor = "Branco Banchista";

	}
	else if (str.substr(3, 1) == "3") {
		//Prata Bari
		key.cor = "Prata Bari";

	}
	else if (str.substr(3, 1) == "4") {
		//Branco Alaska
		key.cor = "Branca Alaska";

	}
#pragma endregion

#pragma region

	if (str.substr(4, 1) == "0") {
		//Cabine Simples
		key.cabine = "Cabine Simples";

	}
	else if (str.substr(4, 1) == "1") {
		//Cabine Multipla
		key.cabine = "Cabine Multipla";

	}
#pragma endregion

#pragma region

	if (str.substr(5, 1) == "0") {
		//Sem Multimidia
		key.mutimidia = "nao";

	}
	else if (str.substr(5, 1) == "1") {
		//com Multimidia
		key.mutimidia = "sim";

	}
#pragma endregion

#pragma region

	if (str.substr(6, 1) == "0") {
		//sem rodas de liga leve
		key.rodasLeve = "nao";

	}
	else if (str.substr(6, 1) == "1") {
		//com rodas de liga leve 
		key.rodasLeve = "sim";

	}
#pragma endregion

#pragma region
	key.quantidade = str.substr(7, 1);
	cList.push_back(key);
	//A ultima variavel é alocada diretamente em quantidade

#pragma endregion

}




