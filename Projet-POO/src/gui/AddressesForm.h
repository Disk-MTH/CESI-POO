#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de AddressesForm
	/// </summary>
	public ref class AddressesForm : public System::Windows::Forms::Form
	{
	public:
		AddressesForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~AddressesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ labelCity;
	private: System::Windows::Forms::Label^ labelZipCode;
	private: System::Windows::Forms::Label^ labelWording;
	private: System::Windows::Forms::TextBox^ textBoxStreetName;

	private: System::Windows::Forms::TextBox^ textBoxZipCode;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ labelAdressType;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::CheckBox^ checkBoxDelivery;
	private: System::Windows::Forms::CheckBox^ checkBoxBilling;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonValidate;
	private: System::Windows::Forms::ComboBox^ comboBoxCity;









	protected:

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelCity = (gcnew System::Windows::Forms::Label());
			this->labelZipCode = (gcnew System::Windows::Forms::Label());
			this->labelWording = (gcnew System::Windows::Forms::Label());
			this->textBoxStreetName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxZipCode = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxCity = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelAdressType = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBoxDelivery = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxBilling = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonValidate = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 0, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(10, 11);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 37.98077F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 62.01923F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 172)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 58)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(663, 439);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AddressesForm::tableLayoutPanel1_Paint);
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(252, 20);
			this->labelTitle->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(159, 39);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Adresses";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				130)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				245)));
			this->tableLayoutPanel2->Controls->Add(this->labelCity, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelZipCode, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelWording, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBoxStreetName, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBoxZipCode, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->comboBoxCity, 2, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(2, 81);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42.01681F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 57.98319F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(659, 120);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// labelCity
			// 
			this->labelCity->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelCity->AutoSize = true;
			this->labelCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelCity->Location = System::Drawing::Point(422, 12);
			this->labelCity->Margin = System::Windows::Forms::Padding(8, 0, 2, 0);
			this->labelCity->Name = L"labelCity";
			this->labelCity->Size = System::Drawing::Size(49, 25);
			this->labelCity->TabIndex = 2;
			this->labelCity->Text = L"Ville";
			// 
			// labelZipCode
			// 
			this->labelZipCode->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelZipCode->AutoSize = true;
			this->labelZipCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelZipCode->Location = System::Drawing::Point(292, 12);
			this->labelZipCode->Margin = System::Windows::Forms::Padding(8, 0, 2, 0);
			this->labelZipCode->Name = L"labelZipCode";
			this->labelZipCode->Size = System::Drawing::Size(117, 25);
			this->labelZipCode->TabIndex = 1;
			this->labelZipCode->Text = L"Code postal";
			// 
			// labelWording
			// 
			this->labelWording->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelWording->AutoSize = true;
			this->labelWording->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelWording->Location = System::Drawing::Point(8, 12);
			this->labelWording->Margin = System::Windows::Forms::Padding(8, 0, 2, 0);
			this->labelWording->Name = L"labelWording";
			this->labelWording->Size = System::Drawing::Size(68, 25);
			this->labelWording->TabIndex = 0;
			this->labelWording->Text = L"Libelle";
			// 
			// textBoxStreetName
			// 
			this->textBoxStreetName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBoxStreetName->Location = System::Drawing::Point(8, 58);
			this->textBoxStreetName->Margin = System::Windows::Forms::Padding(8);
			this->textBoxStreetName->Name = L"textBoxStreetName";
			this->textBoxStreetName->Size = System::Drawing::Size(268, 30);
			this->textBoxStreetName->TabIndex = 3;
			// 
			// textBoxZipCode
			// 
			this->textBoxZipCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBoxZipCode->Location = System::Drawing::Point(292, 58);
			this->textBoxZipCode->Margin = System::Windows::Forms::Padding(8);
			this->textBoxZipCode->Name = L"textBoxZipCode";
			this->textBoxZipCode->Size = System::Drawing::Size(112, 30);
			this->textBoxZipCode->TabIndex = 4;
			// 
			// comboBoxCity
			// 
			this->comboBoxCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->comboBoxCity->FormattingEnabled = true;
			this->comboBoxCity->Location = System::Drawing::Point(422, 58);
			this->comboBoxCity->Margin = System::Windows::Forms::Padding(8);
			this->comboBoxCity->Name = L"comboBoxCity";
			this->comboBoxCity->Size = System::Drawing::Size(229, 33);
			this->comboBoxCity->TabIndex = 5;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->labelAdressType, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel3->Location = System::Drawing::Point(2, 210);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43.75F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 56.25F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(659, 168);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// labelAdressType
			// 
			this->labelAdressType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelAdressType->AutoSize = true;
			this->labelAdressType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->labelAdressType->Location = System::Drawing::Point(8, 21);
			this->labelAdressType->Margin = System::Windows::Forms::Padding(8, 0, 2, 0);
			this->labelAdressType->Name = L"labelAdressType";
			this->labelAdressType->Size = System::Drawing::Size(199, 31);
			this->labelAdressType->TabIndex = 0;
			this->labelAdressType->Text = L"Type d\'adresse";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				37.40458F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				62.59542F)));
			this->tableLayoutPanel4->Controls->Add(this->checkBoxDelivery, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->checkBoxBilling, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(2, 75);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(655, 91);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// checkBoxDelivery
			// 
			this->checkBoxDelivery->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->checkBoxDelivery->AutoSize = true;
			this->checkBoxDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->checkBoxDelivery->Location = System::Drawing::Point(253, 31);
			this->checkBoxDelivery->Margin = System::Windows::Forms::Padding(8, 2, 8, 2);
			this->checkBoxDelivery->Name = L"checkBoxDelivery";
			this->checkBoxDelivery->Size = System::Drawing::Size(207, 29);
			this->checkBoxDelivery->TabIndex = 1;
			this->checkBoxDelivery->Text = L"Adresse de livraison";
			this->checkBoxDelivery->UseVisualStyleBackColor = true;
			// 
			// checkBoxBilling
			// 
			this->checkBoxBilling->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->checkBoxBilling->AutoSize = true;
			this->checkBoxBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->checkBoxBilling->Location = System::Drawing::Point(8, 31);
			this->checkBoxBilling->Margin = System::Windows::Forms::Padding(8, 2, 8, 2);
			this->checkBoxBilling->Name = L"checkBoxBilling";
			this->checkBoxBilling->Size = System::Drawing::Size(226, 29);
			this->checkBoxBilling->TabIndex = 0;
			this->checkBoxBilling->Text = L"Adresse de facturation";
			this->checkBoxBilling->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Controls->Add(this->buttonValidate, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->buttonCancel, 0, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(2, 382);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(659, 54);
			this->tableLayoutPanel5->TabIndex = 3;
			// 
			// buttonValidate
			// 
			this->buttonValidate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonValidate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonValidate->Location = System::Drawing::Point(562, 17);
			this->buttonValidate->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = System::Drawing::Size(92, 31);
			this->buttonValidate->TabIndex = 2;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonCancel->Location = System::Drawing::Point(5, 17);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(103, 31);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// AddressesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayoutPanel1); 
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddressesForm";
			this->Text = L"AddressesForm";
			this->Load += gcnew System::EventHandler(this, &AddressesForm::AddressesForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AddressesForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
