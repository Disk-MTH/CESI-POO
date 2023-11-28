#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class CustomerForm : public Form
	{
		public:
			CustomerForm()
			{
				initialize();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;
			TableLayoutPanel^ tableLayoutPanel5;
			TableLayoutPanel^ tableLayoutPanel6;
			Label^ labelLastName;
			Label^ labelFirstName;
			Label^ labelBirthDate;

			Label^ labelTitle;
			TextBox^ textBoxBirthDate;

			TextBox^ textBoxFirstName;

			TextBox^ textBoxLastName;
			Button^ buttonDelete;
			Button^ buttonEdit;
			Button^ buttonAdd;
			DataGridView^ dataGridViewAddresses;
			Button^ buttonValidate;
			Button^ buttonCancel;

		private:
			/// <summary>
			/// Variable n�cessaire au concepteur.
			/// </summary>
			ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
			/// le contenu de cette m�thode avec l'�diteur de code.
			/// </summary>
			void initialize(void)
			{
				this->tableLayoutPanel1 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel2 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel3 = (gcnew TableLayoutPanel());
				this->textBoxBirthDate = (gcnew TextBox());
				this->textBoxFirstName = (gcnew TextBox());
				this->labelLastName = (gcnew Label());
				this->labelFirstName = (gcnew Label());
				this->labelBirthDate = (gcnew Label());
				this->textBoxLastName = (gcnew TextBox());
				this->tableLayoutPanel4 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel5 = (gcnew TableLayoutPanel());
				this->buttonDelete = (gcnew Button());
				this->buttonEdit = (gcnew Button());
				this->buttonAdd = (gcnew Button());
				this->dataGridViewAddresses = (gcnew DataGridView());
				this->tableLayoutPanel6 = (gcnew TableLayoutPanel());
				this->buttonValidate = (gcnew Button());
				this->buttonCancel = (gcnew Button());
				this->labelTitle = (gcnew Label());
				this->tableLayoutPanel1->SuspendLayout();
				this->tableLayoutPanel2->SuspendLayout();
				this->tableLayoutPanel3->SuspendLayout();
				this->tableLayoutPanel4->SuspendLayout();
				this->tableLayoutPanel5->SuspendLayout();
				(cli::safe_cast<ComponentModel::ISupportInitialize^>(this->dataGridViewAddresses))->BeginInit();
				this->tableLayoutPanel6->SuspendLayout();
				this->SuspendLayout();
				// 
				// tableLayoutPanel1
				// 
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel6, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Location = Drawing::Point(10, 11);
				this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 17.13483F)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 82.86517F)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 58)));
				this->tableLayoutPanel1->Size = Drawing::Size(493, 348);
				this->tableLayoutPanel1->TabIndex = 0;
				// 
				// tableLayoutPanel2
				// 
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					39.17051F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					60.82949F)));
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 0);
				this->tableLayoutPanel2->Location = Drawing::Point(2, 51);
				this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel2->Size = Drawing::Size(488, 235);
				this->tableLayoutPanel2->TabIndex = 0;
				// 
				// tableLayoutPanel3
				// 
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel3->Controls->Add(this->textBoxBirthDate, 0, 5);
				this->tableLayoutPanel3->Controls->Add(this->textBoxFirstName, 0, 3);
				this->tableLayoutPanel3->Controls->Add(this->labelLastName, 0, 0);
				this->tableLayoutPanel3->Controls->Add(this->labelFirstName, 0, 2);
				this->tableLayoutPanel3->Controls->Add(this->labelBirthDate, 0, 4);
				this->tableLayoutPanel3->Controls->Add(this->textBoxLastName, 0, 1);
				this->tableLayoutPanel3->Location = Drawing::Point(2, 2);
				this->tableLayoutPanel3->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 6;
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 47.31183F)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 52.68817F)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 38)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 39)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 44)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 32)));
				this->tableLayoutPanel3->Size = Drawing::Size(187, 230);
				this->tableLayoutPanel3->TabIndex = 0;
				// 
				// textBoxBirthDate
				// 
				this->textBoxBirthDate->Anchor = AnchorStyles::Left;
				this->textBoxBirthDate->Location = Drawing::Point(8, 203);
				this->textBoxBirthDate->Margin = Windows::Forms::Padding(8, 2, 8, 2);
				this->textBoxBirthDate->Name = L"textBoxBirthDate";
				this->textBoxBirthDate->Size = Drawing::Size(168, 20);
				this->textBoxBirthDate->TabIndex = 5;
				// 
				// textBoxFirstName
				// 
				this->textBoxFirstName->Anchor = AnchorStyles::Left;
				this->textBoxFirstName->Location = Drawing::Point(8, 123);
				this->textBoxFirstName->Margin = Windows::Forms::Padding(8, 2, 8, 2);
				this->textBoxFirstName->Name = L"textBoxFirstName";
				this->textBoxFirstName->Size = Drawing::Size(168, 20);
				this->textBoxFirstName->TabIndex = 4;
				// 
				// labelLastName
				// 
				this->labelLastName->Anchor = AnchorStyles::Left;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelLastName->Location = Drawing::Point(8, 5);
				this->labelLastName->Margin = Windows::Forms::Padding(8, 0, 2, 0);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->TabIndex = 0;
				this->labelLastName->Text = L"Nom";
				// 
				// labelFirstName
				// 
				this->labelFirstName->Anchor = AnchorStyles::Left;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelFirstName->Location = Drawing::Point(8, 82);
				this->labelFirstName->Margin = Windows::Forms::Padding(8, 0, 2, 0);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->TabIndex = 1;
				this->labelFirstName->Text = L"Prenom";
				// 
				// labelBirthDate
				// 
				this->labelBirthDate->Anchor = AnchorStyles::Left;
				this->labelBirthDate->AutoSize = true;
				this->labelBirthDate->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelBirthDate->Location = Drawing::Point(8, 162);
				this->labelBirthDate->Margin = Windows::Forms::Padding(8, 0, 2, 0);
				this->labelBirthDate->Name = L"labelBirthDate";
				this->labelBirthDate->Size = Drawing::Size(174, 25);
				this->labelBirthDate->TabIndex = 2;
				this->labelBirthDate->Text = L"Date de naissance";
				// 
				// textBoxLastName
				// 
				this->textBoxLastName->Anchor = AnchorStyles::Left;
				this->textBoxLastName->Location = Drawing::Point(8, 46);
				this->textBoxLastName->Margin = Windows::Forms::Padding(8, 2, 8, 2);
				this->textBoxLastName->Name = L"textBoxLastName";
				this->textBoxLastName->Size = Drawing::Size(168, 20);
				this->textBoxLastName->TabIndex = 3;
				// 
				// tableLayoutPanel4
				// 
				this->tableLayoutPanel4->ColumnCount = 1;
				this->tableLayoutPanel4->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 1);
				this->tableLayoutPanel4->Controls->Add(this->dataGridViewAddresses, 0, 0);
				this->tableLayoutPanel4->Location = Drawing::Point(193, 2);
				this->tableLayoutPanel4->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 2;
				this->tableLayoutPanel4->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 74.91166F)));
				this->tableLayoutPanel4->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 25.08834F)));
				this->tableLayoutPanel4->Size = Drawing::Size(292, 230);
				this->tableLayoutPanel4->TabIndex = 1;
				// 
				// tableLayoutPanel5
				// 
				this->tableLayoutPanel5->ColumnCount = 3;
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					59.375F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					40.625F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute,
					95)));
				this->tableLayoutPanel5->Controls->Add(this->buttonDelete, 2, 0);
				this->tableLayoutPanel5->Controls->Add(this->buttonEdit, 1, 0);
				this->tableLayoutPanel5->Controls->Add(this->buttonAdd, 0, 0);
				this->tableLayoutPanel5->Location = Drawing::Point(2, 174);
				this->tableLayoutPanel5->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				this->tableLayoutPanel5->RowCount = 1;
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel5->Size = Drawing::Size(288, 53);
				this->tableLayoutPanel5->TabIndex = 0;
				// 
				// buttonDelete
				// 
				this->buttonDelete->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Right));
				this->buttonDelete->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->buttonDelete->Location = Drawing::Point(197, 21);
				this->buttonDelete->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(86, 26);
				this->buttonDelete->TabIndex = 2;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				// 
				// buttonEdit
				// 
				this->buttonEdit->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Right));
				this->buttonEdit->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->buttonEdit->Location = Drawing::Point(120, 21);
				this->buttonEdit->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(67, 26);
				this->buttonEdit->TabIndex = 1;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;
				// 
				// buttonAdd
				// 
				this->buttonAdd->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Right));
				this->buttonAdd->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->buttonAdd->Location = Drawing::Point(42, 21);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(67, 26);
				this->buttonAdd->TabIndex = 0;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				// 
				// dataGridViewAddresses
				// 
				this->dataGridViewAddresses->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewAddresses->Location = Drawing::Point(2, 2);
				this->dataGridViewAddresses->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->dataGridViewAddresses->Name = L"dataGridViewAddresses";
				this->dataGridViewAddresses->RowHeadersWidth = 51;
				this->dataGridViewAddresses->RowTemplate->Height = 24;
				this->dataGridViewAddresses->Size = Drawing::Size(288, 167);
				this->dataGridViewAddresses->TabIndex = 1;
				// 
				// tableLayoutPanel6
				// 
				this->tableLayoutPanel6->ColumnCount = 2;
				this->tableLayoutPanel6->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel6->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel6->Controls->Add(this->buttonValidate, 1, 0);
				this->tableLayoutPanel6->Controls->Add(this->buttonCancel, 0, 0);
				this->tableLayoutPanel6->Location = Drawing::Point(2, 291);
				this->tableLayoutPanel6->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
				this->tableLayoutPanel6->RowCount = 1;
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel6->Size = Drawing::Size(488, 54);
				this->tableLayoutPanel6->TabIndex = 1;
				// 
				// buttonValidate
				// 
				this->buttonValidate->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Right));
				this->buttonValidate->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonValidate->Location = Drawing::Point(399, 17);
				this->buttonValidate->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(84, 31);
				this->buttonValidate->TabIndex = 1;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;
				// 
				// buttonCancel
				// 
				this->buttonCancel->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Left));
				this->buttonCancel->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonCancel->Location = Drawing::Point(5, 17);
				this->buttonCancel->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonCancel->Name = L"buttonCancel";
				this->buttonCancel->Size = Drawing::Size(95, 31);
				this->buttonCancel->TabIndex = 0;
				this->buttonCancel->Text = L"Annuler";
				this->buttonCancel->UseVisualStyleBackColor = true;
				// 
				// labelTitle
				// 
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 20));
				this->labelTitle->Location = Drawing::Point(204, 9);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(84, 31);
				this->labelTitle->TabIndex = 2;
				this->labelTitle->Text = L"Client";
				// 
				// CustomerForm
				// 
				this->AutoScaleDimensions = Drawing::SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(512, 368);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->Name = L"CustomerForm";
				this->Text = L"CustomerForm";
				this->tableLayoutPanel1->ResumeLayout(false);
				this->tableLayoutPanel1->PerformLayout();
				this->tableLayoutPanel2->ResumeLayout(false);
				this->tableLayoutPanel3->ResumeLayout(false);
				this->tableLayoutPanel3->PerformLayout();
				this->tableLayoutPanel4->ResumeLayout(false);
				this->tableLayoutPanel5->ResumeLayout(false);
				(cli::safe_cast<ComponentModel::ISupportInitialize^>(this->dataGridViewAddresses))->EndInit();
				this->tableLayoutPanel6->ResumeLayout(false);
				this->ResumeLayout(false);

			}
#pragma endregion
	};
}
