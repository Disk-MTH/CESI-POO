#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de AddressesForm
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
		/// Nettoyage des ressources utilisées.
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
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelWording = (gcnew System::Windows::Forms::Label());
			this->labelZipCode = (gcnew System::Windows::Forms::Label());
			this->labelCity = (gcnew System::Windows::Forms::Label());
			this->textBoxStreetName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxZipCode = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelAdressType = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBoxBilling = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxDelivery = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonValidate = (gcnew System::Windows::Forms::Button());
			this->comboBoxCity = (gcnew System::Windows::Forms::ComboBox());
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.58371F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.41629F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 134)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 72)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(657, 428);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->labelTitle->Location = System::Drawing::Point(249, 37);
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
				170)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				219)));
			this->tableLayoutPanel2->Controls->Add(this->labelCity, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelZipCode, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelWording, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBoxStreetName, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBoxZipCode, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->comboBoxCity, 2, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 117);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42.01681F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 57.98319F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(651, 101);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// labelWording
			// 
			this->labelWording->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelWording->AutoSize = true;
			this->labelWording->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelWording->Location = System::Drawing::Point(10, 6);
			this->labelWording->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelWording->Name = L"labelWording";
			this->labelWording->Size = System::Drawing::Size(87, 29);
			this->labelWording->TabIndex = 0;
			this->labelWording->Text = L"Libelle";
			// 
			// labelZipCode
			// 
			this->labelZipCode->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelZipCode->AutoSize = true;
			this->labelZipCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelZipCode->Location = System::Drawing::Point(272, 6);
			this->labelZipCode->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelZipCode->Name = L"labelZipCode";
			this->labelZipCode->Size = System::Drawing::Size(148, 29);
			this->labelZipCode->TabIndex = 1;
			this->labelZipCode->Text = L"Code postal";
			// 
			// labelCity
			// 
			this->labelCity->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelCity->AutoSize = true;
			this->labelCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelCity->Location = System::Drawing::Point(442, 6);
			this->labelCity->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelCity->Name = L"labelCity";
			this->labelCity->Size = System::Drawing::Size(62, 29);
			this->labelCity->TabIndex = 2;
			this->labelCity->Text = L"Ville";
			// 
			// textBoxStreetName
			// 
			this->textBoxStreetName->Location = System::Drawing::Point(10, 52);
			this->textBoxStreetName->Margin = System::Windows::Forms::Padding(10);
			this->textBoxStreetName->Name = L"textBoxStreetName";
			this->textBoxStreetName->Size = System::Drawing::Size(235, 22);
			this->textBoxStreetName->TabIndex = 3;
			// 
			// textBoxZipCode
			// 
			this->textBoxZipCode->Location = System::Drawing::Point(272, 52);
			this->textBoxZipCode->Margin = System::Windows::Forms::Padding(10);
			this->textBoxZipCode->Name = L"textBoxZipCode";
			this->textBoxZipCode->Size = System::Drawing::Size(148, 22);
			this->textBoxZipCode->TabIndex = 4;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->labelAdressType, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 224);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43.75F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 56.25F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(651, 128);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// labelAdressType
			// 
			this->labelAdressType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelAdressType->AutoSize = true;
			this->labelAdressType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelAdressType->Location = System::Drawing::Point(10, 13);
			this->labelAdressType->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelAdressType->Name = L"labelAdressType";
			this->labelAdressType->Size = System::Drawing::Size(185, 29);
			this->labelAdressType->TabIndex = 0;
			this->labelAdressType->Text = L"Type d\'adresse";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				34.26357F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				65.73643F)));
			this->tableLayoutPanel4->Controls->Add(this->checkBoxDelivery, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->checkBoxBilling, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 59);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(645, 66);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// checkBoxBilling
			// 
			this->checkBoxBilling->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->checkBoxBilling->AutoSize = true;
			this->checkBoxBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->checkBoxBilling->Location = System::Drawing::Point(10, 21);
			this->checkBoxBilling->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->checkBoxBilling->Name = L"checkBoxBilling";
			this->checkBoxBilling->Size = System::Drawing::Size(200, 24);
			this->checkBoxBilling->TabIndex = 0;
			this->checkBoxBilling->Text = L"Adresse de facturation";
			this->checkBoxBilling->UseVisualStyleBackColor = true;
			// 
			// checkBoxDelivery
			// 
			this->checkBoxDelivery->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->checkBoxDelivery->AutoSize = true;
			this->checkBoxDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->checkBoxDelivery->Location = System::Drawing::Point(231, 21);
			this->checkBoxDelivery->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->checkBoxDelivery->Name = L"checkBoxDelivery";
			this->checkBoxDelivery->Size = System::Drawing::Size(183, 24);
			this->checkBoxDelivery->TabIndex = 1;
			this->checkBoxDelivery->Text = L"Adresse de livraison";
			this->checkBoxDelivery->UseVisualStyleBackColor = true;
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
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 358);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(651, 67);
			this->tableLayoutPanel5->TabIndex = 3;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonCancel->Location = System::Drawing::Point(7, 22);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(7);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(112, 38);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonValidate
			// 
			this->buttonValidate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonValidate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonValidate->Location = System::Drawing::Point(532, 22);
			this->buttonValidate->Margin = System::Windows::Forms::Padding(7);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = System::Drawing::Size(112, 38);
			this->buttonValidate->TabIndex = 2;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			// 
			// comboBoxCity
			// 
			this->comboBoxCity->FormattingEnabled = true;
			this->comboBoxCity->Location = System::Drawing::Point(442, 52);
			this->comboBoxCity->Margin = System::Windows::Forms::Padding(10);
			this->comboBoxCity->Name = L"comboBoxCity";
			this->comboBoxCity->Size = System::Drawing::Size(199, 24);
			this->comboBoxCity->TabIndex = 5;
			// 
			// AddressesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 453);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AddressesForm";
			this->Text = L"AddressesForm";
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
	};
}
