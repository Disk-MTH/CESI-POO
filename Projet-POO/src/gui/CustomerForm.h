#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de CustomerForm
	/// </summary>
	public ref class CustomerForm : public System::Windows::Forms::Form
	{
	public:
		CustomerForm(void)
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
		~CustomerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
	private: System::Windows::Forms::Label^ labelLastName;
	private: System::Windows::Forms::Label^ labelFirstName;
	private: System::Windows::Forms::Label^ labelBirthDate;

	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TextBox^ textBoxBirthDate;

	private: System::Windows::Forms::TextBox^ textBoxFirstName;

	private: System::Windows::Forms::TextBox^ textBoxLastName;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::DataGridView^ dataGridViewAddresses;
	private: System::Windows::Forms::Button^ buttonValidate;
	private: System::Windows::Forms::Button^ buttonCancel;


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
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->labelBirthDate = (gcnew System::Windows::Forms::Label());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBirthDate = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewAddresses = (gcnew System::Windows::Forms::DataGridView());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonValidate = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAddresses))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel6, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.13483F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 82.86517F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 71)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(657, 428);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				39.17051F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60.82949F)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 64);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(651, 289);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->textBoxBirthDate, 0, 5);
			this->tableLayoutPanel3->Controls->Add(this->textBoxFirstName, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->labelLastName, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->labelFirstName, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->labelBirthDate, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->textBoxLastName, 0, 1);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 6;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 47.31183F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52.68817F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 47)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 48)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(249, 283);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->dataGridViewAddresses, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(258, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 74.91166F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.08834F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(390, 283);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				61.31387F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				38.68613F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				109)));
			this->tableLayoutPanel5->Controls->Add(this->buttonDelete, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->buttonEdit, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->buttonAdd, 0, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 215);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(384, 65);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->buttonValidate, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->buttonCancel, 0, 0);
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 359);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(651, 66);
			this->tableLayoutPanel6->TabIndex = 1;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->labelTitle->Location = System::Drawing::Point(276, 11);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(105, 39);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Client";
			// 
			// labelLastName
			// 
			this->labelLastName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelLastName->AutoSize = true;
			this->labelLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelLastName->Location = System::Drawing::Point(10, 7);
			this->labelLastName->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(67, 29);
			this->labelLastName->TabIndex = 0;
			this->labelLastName->Text = L"Nom";
			// 
			// labelFirstName
			// 
			this->labelFirstName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelFirstName->Location = System::Drawing::Point(10, 102);
			this->labelFirstName->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(102, 29);
			this->labelFirstName->TabIndex = 1;
			this->labelFirstName->Text = L"Prenom";
			// 
			// labelBirthDate
			// 
			this->labelBirthDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelBirthDate->AutoSize = true;
			this->labelBirthDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelBirthDate->Location = System::Drawing::Point(10, 200);
			this->labelBirthDate->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelBirthDate->Name = L"labelBirthDate";
			this->labelBirthDate->Size = System::Drawing::Size(223, 29);
			this->labelBirthDate->TabIndex = 2;
			this->labelBirthDate->Text = L"Date de naissance";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxLastName->Location = System::Drawing::Point(10, 57);
			this->textBoxLastName->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(223, 22);
			this->textBoxLastName->TabIndex = 3;
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxFirstName->Location = System::Drawing::Point(10, 153);
			this->textBoxFirstName->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(223, 22);
			this->textBoxFirstName->TabIndex = 4;
			// 
			// textBoxBirthDate
			// 
			this->textBoxBirthDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxBirthDate->Location = System::Drawing::Point(10, 251);
			this->textBoxBirthDate->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxBirthDate->Name = L"textBoxBirthDate";
			this->textBoxBirthDate->Size = System::Drawing::Size(223, 22);
			this->textBoxBirthDate->TabIndex = 5;
			// 
			// dataGridViewAddresses
			// 
			this->dataGridViewAddresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAddresses->Location = System::Drawing::Point(3, 3);
			this->dataGridViewAddresses->Name = L"dataGridViewAddresses";
			this->dataGridViewAddresses->RowHeadersWidth = 51;
			this->dataGridViewAddresses->RowTemplate->Height = 24;
			this->dataGridViewAddresses->Size = System::Drawing::Size(384, 206);
			this->dataGridViewAddresses->TabIndex = 1;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonAdd->Location = System::Drawing::Point(72, 26);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(7);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(89, 32);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonEdit->Location = System::Drawing::Point(178, 26);
			this->buttonEdit->Margin = System::Windows::Forms::Padding(7);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(89, 32);
			this->buttonEdit->TabIndex = 1;
			this->buttonEdit->Text = L"Modifier";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->buttonDelete->Location = System::Drawing::Point(281, 26);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(7);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(96, 32);
			this->buttonDelete->TabIndex = 2;
			this->buttonDelete->Text = L"Supprimer";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonCancel->Location = System::Drawing::Point(7, 21);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(7);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(112, 38);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonValidate
			// 
			this->buttonValidate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonValidate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonValidate->Location = System::Drawing::Point(532, 21);
			this->buttonValidate->Margin = System::Windows::Forms::Padding(7);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = System::Drawing::Size(112, 38);
			this->buttonValidate->TabIndex = 1;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			// 
			// CustomerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 453);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CustomerForm";
			this->Text = L"CustomerForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAddresses))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
