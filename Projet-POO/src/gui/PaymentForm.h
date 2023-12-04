#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PaymentForm
	/// </summary>
	public ref class PaymentForm : public System::Windows::Forms::Form
	{
	public:
		PaymentForm(void)
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
		~PaymentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ labelAmount;
	private: System::Windows::Forms::Label^ labelDate;
	private: System::Windows::Forms::Label^ labelType;
	private: System::Windows::Forms::TextBox^ textBoxAmount;
	private: System::Windows::Forms::TextBox^ textBoxDate;


	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ buttonValidate;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::CheckBox^ checkBoxValidPayment;
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
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelAmount = (gcnew System::Windows::Forms::Label());
			this->labelDate = (gcnew System::Windows::Forms::Label());
			this->labelType = (gcnew System::Windows::Forms::Label());
			this->textBoxAmount = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDate = (gcnew System::Windows::Forms::TextBox());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonValidate = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBoxValidPayment = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15.18325F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 84.81676F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 58)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(660, 437);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->labelAmount, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelDate, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->labelType, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBoxAmount, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBoxDate, 0, 5);
			this->tableLayoutPanel2->Controls->Add(this->comboBox1, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->checkBoxValidPayment, 0, 6);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 60);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 7;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.75F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.25F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 53)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(654, 315);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// labelAmount
			// 
			this->labelAmount->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelAmount->AutoSize = true;
			this->labelAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelAmount->Location = System::Drawing::Point(10, 7);
			this->labelAmount->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelAmount->Name = L"labelAmount";
			this->labelAmount->Size = System::Drawing::Size(187, 25);
			this->labelAmount->TabIndex = 0;
			this->labelAmount->Text = L"Valeur du payement";
			// 
			// labelDate
			// 
			this->labelDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelDate->AutoSize = true;
			this->labelDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelDate->Location = System::Drawing::Point(10, 192);
			this->labelDate->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelDate->Name = L"labelDate";
			this->labelDate->Size = System::Drawing::Size(171, 25);
			this->labelDate->TabIndex = 2;
			this->labelDate->Text = L"Date du payement";
			// 
			// labelType
			// 
			this->labelType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelType->AutoSize = true;
			this->labelType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelType->Location = System::Drawing::Point(10, 90);
			this->labelType->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelType->Name = L"labelType";
			this->labelType->Size = System::Drawing::Size(175, 25);
			this->labelType->TabIndex = 1;
			this->labelType->Text = L"Type de payement";
			// 
			// textBoxAmount
			// 
			this->textBoxAmount->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBoxAmount->Location = System::Drawing::Point(10, 44);
			this->textBoxAmount->Margin = System::Windows::Forms::Padding(10, 3, 3, 3);
			this->textBoxAmount->Name = L"textBoxAmount";
			this->textBoxAmount->Size = System::Drawing::Size(339, 30);
			this->textBoxAmount->TabIndex = 3;
			// 
			// textBoxDate
			// 
			this->textBoxDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBoxDate->Location = System::Drawing::Point(10, 238);
			this->textBoxDate->Margin = System::Windows::Forms::Padding(10, 3, 3, 3);
			this->textBoxDate->Name = L"textBoxDate";
			this->textBoxDate->Size = System::Drawing::Size(339, 30);
			this->textBoxDate->TabIndex = 4;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(245, 9);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(170, 39);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Payement";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->buttonValidate, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->buttonCancel, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 381);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(654, 53);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// buttonValidate
			// 
			this->buttonValidate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonValidate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonValidate->Location = System::Drawing::Point(538, 7);
			this->buttonValidate->Margin = System::Windows::Forms::Padding(7);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = System::Drawing::Size(109, 39);
			this->buttonValidate->TabIndex = 1;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonCancel->Location = System::Drawing::Point(7, 7);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(7);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(109, 39);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(10, 138);
			this->comboBox1->Margin = System::Windows::Forms::Padding(10, 0, 3, 7);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(339, 33);
			this->comboBox1->TabIndex = 5;
			// 
			// checkBoxValidPayment
			// 
			this->checkBoxValidPayment->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->checkBoxValidPayment->AutoSize = true;
			this->checkBoxValidPayment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->checkBoxValidPayment->Location = System::Drawing::Point(10, 281);
			this->checkBoxValidPayment->Margin = System::Windows::Forms::Padding(10, 3, 3, 3);
			this->checkBoxValidPayment->Name = L"checkBoxValidPayment";
			this->checkBoxValidPayment->Size = System::Drawing::Size(128, 29);
			this->checkBoxValidPayment->TabIndex = 6;
			this->checkBoxValidPayment->Text = L"checkBox1";
			this->checkBoxValidPayment->UseVisualStyleBackColor = true;
			// 
			// PaymentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"PaymentForm";
			this->Text = L"PaymentForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
