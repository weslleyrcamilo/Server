#pragma once

namespace Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ServerGUI
	/// </summary>
	public ref class ServerGUI : public System::Windows::Forms::Form
	{
	public:
		ServerGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SetButton;
	protected:

	protected:

	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RichTextBox^  trocaDados;
	private: System::Windows::Forms::Button^ GetButton;



	private: System::Windows::Forms::Button^ CloseButton;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ ArkButton;
	private: System::Windows::Forms::Button^ SetCarButton;
	private: System::Windows::Forms::Button^ DataButton;










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ServerGUI::typeid));
			this->SetButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->trocaDados = (gcnew System::Windows::Forms::RichTextBox());
			this->GetButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->SetCarButton = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->DataButton = (gcnew System::Windows::Forms::Button());
			this->ArkButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// SetButton
			// 
			this->SetButton->Location = System::Drawing::Point(13, 71);
			this->SetButton->Name = L"SetButton";
			this->SetButton->Size = System::Drawing::Size(76, 36);
			this->SetButton->TabIndex = 0;
			this->SetButton->Text = L"SetServer";
			this->SetButton->UseVisualStyleBackColor = true;
			this->SetButton->Click += gcnew System::EventHandler(this, &ServerGUI::SetButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(76, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"127.0.0.1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(76, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"1111";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Server IP";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Server Port";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->CloseButton);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->SetButton);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Location = System::Drawing::Point(12, 188);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(195, 159);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Server Properties";
			// 
			// CloseButton
			// 
			this->CloseButton->Enabled = false;
			this->CloseButton->Location = System::Drawing::Point(95, 71);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(81, 36);
			this->CloseButton->TabIndex = 5;
			this->CloseButton->Text = L"CloseServer";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &ServerGUI::CloseButton_Click);
			// 
			// trocaDados
			// 
			this->trocaDados->Location = System::Drawing::Point(8, 19);
			this->trocaDados->Name = L"trocaDados";
			this->trocaDados->Size = System::Drawing::Size(223, 195);
			this->trocaDados->TabIndex = 6;
			this->trocaDados->Text = L"";
			// 
			// GetButton
			// 
			this->GetButton->Enabled = false;
			this->GetButton->Location = System::Drawing::Point(6, 226);
			this->GetButton->Name = L"GetButton";
			this->GetButton->Size = System::Drawing::Size(223, 28);
			this->GetButton->TabIndex = 5;
			this->GetButton->Text = L"Requisitar Dados";
			this->GetButton->UseVisualStyleBackColor = true;
			this->GetButton->Click += gcnew System::EventHandler(this, &ServerGUI::GetButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(34, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(136, 112);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(34, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"SERVER HOST";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->DataButton);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Location = System::Drawing::Point(456, 14);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(199, 333);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Registro e Banco de Dados";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(106, 218);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(68, 20);
			this->textBox9->TabIndex = 20;
			// 
			// SetCarButton
			// 
			this->SetCarButton->Enabled = false;
			this->SetCarButton->Location = System::Drawing::Point(8, 294);
			this->SetCarButton->Name = L"SetCarButton";
			this->SetCarButton->Size = System::Drawing::Size(221, 28);
			this->SetCarButton->TabIndex = 7;
			this->SetCarButton->Text = L"Requisitar Carro";
			this->SetCarButton->UseVisualStyleBackColor = true;
			this->SetCarButton->Click += gcnew System::EventHandler(this, &ServerGUI::SetCarButton_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(16, 221);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(65, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Quantidade:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(16, 195);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 13);
			this->label11->TabIndex = 17;
			this->label11->Text = L"Rodas:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(106, 192);
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(68, 20);
			this->textBox10->TabIndex = 18;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(106, 166);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(68, 20);
			this->textBox7->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(16, 169);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Multimidia:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(16, 143);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Cabine:";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(106, 140);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(68, 20);
			this->textBox8->TabIndex = 14;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(106, 114);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(68, 20);
			this->textBox5->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(16, 117);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Cor:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 91);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Motorização:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(106, 88);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(68, 20);
			this->textBox6->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(64, 62);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(110, 20);
			this->textBox4->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Versão:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Modelo:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(64, 36);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(110, 20);
			this->textBox3->TabIndex = 6;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->ArkButton);
			this->groupBox3->Controls->Add(this->trocaDados);
			this->groupBox3->Controls->Add(this->SetCarButton);
			this->groupBox3->Controls->Add(this->GetButton);
			this->groupBox3->Location = System::Drawing::Point(213, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(237, 335);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Visor de Conexão";
			// 
			// DataButton
			// 
			this->DataButton->Enabled = false;
			this->DataButton->Location = System::Drawing::Point(19, 277);
			this->DataButton->Name = L"DataButton";
			this->DataButton->Size = System::Drawing::Size(155, 28);
			this->DataButton->TabIndex = 9;
			this->DataButton->Text = L"Mostrar Banco";
			this->DataButton->UseVisualStyleBackColor = true;
			this->DataButton->Click += gcnew System::EventHandler(this, &ServerGUI::DataButton_Click);
			// 
			// ArkButton
			// 
			this->ArkButton->Enabled = false;
			this->ArkButton->Location = System::Drawing::Point(6, 260);
			this->ArkButton->Name = L"ArkButton";
			this->ArkButton->Size = System::Drawing::Size(223, 28);
			this->ArkButton->TabIndex = 8;
			this->ArkButton->Text = L"Requisitar Relatório";
			this->ArkButton->UseVisualStyleBackColor = true;
			this->ArkButton->Click += gcnew System::EventHandler(this, &ServerGUI::ArkButton_Click);
			// 
			// ServerGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(667, 362);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Name = L"ServerGUI";
			this->Text = L"ServerGUI";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SetButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void GetButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void SetCarButton_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void ArkButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DataButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
