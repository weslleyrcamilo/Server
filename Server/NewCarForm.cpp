#include <msclr\marshal_cppstd.h>
#include <string>
#include "ServerGUI.h"
#include "NewCarForm.h"

using namespace Server;

// Seleciona op��o "Argo"
System::Void NewCarForm::checkBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Desmarca op��o "Strada"
	this->checkBox4->Checked = false;

	// Vers�o
	this->comboBox1->Items->Clear();
	this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
		L"Drive", L"Trekking", L"HGT"
	});

	// Motoriza��o
	this->comboBox2->Items->Clear();
	this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
		L"1.0", L"1.3", L"1.8"
	});

	// Cabine - N�o se aplica
	this->radioButton1->Enabled = false;
	this->radioButton2->Enabled = false;
}

// Seleciona op��o "Strada"
System::Void NewCarForm::checkBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	// Desmarca op��o "Argo"
	this->checkBox3->Checked = false;

	// Vers�o
	this->comboBox1->Items->Clear();
	this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
		L"Endurance", L"Volcano"
	});

	// Motoriza��o
	this->comboBox2->Items->Clear();
	this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
		L"1.8"
	});

	// Cabine
	this->radioButton1->Enabled = true;
	this->radioButton2->Enabled = true;
}

// Exclus�o entre op��es "Cabine simples" e "Cabine dupla"
System::Void NewCarForm::radioButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->radioButton2->Checked = false;
}
System::Void NewCarForm::radioButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->radioButton1->Checked = false;
}

// Cadastra novo carro
System::Void NewCarForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ versao = this->comboBox1->Text;
	System::String^ motorizacao = this->comboBox2->Text;
	System::String^ cor = this->comboBox3->Text;

	int modelo;
	if (this->checkBox3->Checked)
		modelo = 0;
	else if (this->checkBox4->Checked)
		modelo = 1;
	else
		modelo = -1;

	if (String::IsNullOrEmpty(versao) || String::IsNullOrEmpty(motorizacao) || String::IsNullOrEmpty(cor) || modelo == -1) {
		MessageBox::Show("Forne�a todos os dados!", "Erro");
		return;
	}

	if (versao == "HGT" && (motorizacao == "1.0" || motorizacao == "1.3")) {
		MessageBox::Show("Motoriza��o imcompat�vel com a vers�o HGT!", "Erro");
		return;
	}

	if (versao == "Trekking" && (motorizacao == "1.0" || motorizacao == "1.3")) {
		MessageBox::Show("Motoriza��o imcompat�vel com a vers�o Trekking!", "Erro");
		return;
	}

	int cabine = this->radioButton2->Checked ? 1 : 0;
	int multimidia = this->checkBox1->Checked ? 1 : 0;
	int rodas = this->checkBox2->Checked ? 1 : 0;

	int quantidade = (int)this->numericUpDown1->Value;

	//this->mainForm->addCar(modelo, versao, motorizacao, cor, cabine, multimidia, rodas, quantidade);


}

