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
			CustomerForm(String^* firstName, String^* lastName, String^* birthdate)
			{
				this->firstName = firstName;
				this->lastName = lastName;
				this->birthdate = birthdate;
				initialize();
			}

		private:
			String^* firstName;
			String^* lastName;
			String^* birthdate;

			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;
			TableLayoutPanel^ tableLayoutPanel5;
			TableLayoutPanel^ tableLayoutPanel6;

			Label^ labelTitle;
			Label^ labelLastName;
			Label^ labelFirstName;
			Label^ labelBirthDate;

			TextBox^ textBoxLastName;
			TextBox^ textBoxFirstName;
			TextBox^ textBoxBirthDate;

			DataGridView^ dataGridViewAddresses;

			Button^ buttonAdd;
			Button^ buttonEdit;
			Button^ buttonDelete;

			Button^ buttonCancel;
			Button^ buttonValidate;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();
				this->tableLayoutPanel4 = gcnew TableLayoutPanel();
				this->tableLayoutPanel5 = gcnew TableLayoutPanel();
				this->tableLayoutPanel6 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();
				this->labelLastName = gcnew Label();
				this->labelFirstName = gcnew Label();
				this->labelBirthDate = gcnew Label();

				this->dataGridViewAddresses = gcnew DataGridView();

				this->textBoxLastName = gcnew TextBox();
				this->textBoxFirstName = gcnew TextBox();
				this->textBoxBirthDate = gcnew TextBox();

				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();

				this->buttonCancel = gcnew Button();
				this->buttonValidate = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel6, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Location = Point(10, 11);
				this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 17.13483F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 82.86517F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 58));
				this->tableLayoutPanel1->Size = Drawing::Size(493, 348);
				this->tableLayoutPanel1->TabIndex = 0;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 39.17051F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 60.82949F));
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 0);
				this->tableLayoutPanel2->Location = Point(2, 51);
				this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(488, 235);
				this->tableLayoutPanel2->TabIndex = 0;

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Controls->Add(this->textBoxBirthDate, 0, 5);
				this->tableLayoutPanel3->Controls->Add(this->textBoxFirstName, 0, 3);
				this->tableLayoutPanel3->Controls->Add(this->labelLastName, 0, 0);
				this->tableLayoutPanel3->Controls->Add(this->labelFirstName, 0, 2);
				this->tableLayoutPanel3->Controls->Add(this->labelBirthDate, 0, 4);
				this->tableLayoutPanel3->Controls->Add(this->textBoxLastName, 0, 1);
				this->tableLayoutPanel3->Location = Point(2, 2);
				this->tableLayoutPanel3->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 6;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 47.31183F));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 52.68817F));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 38));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 39));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 44));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 32));
				this->tableLayoutPanel3->Size = Drawing::Size(187, 230);
				this->tableLayoutPanel3->TabIndex = 0;

				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 1;
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 1);
				this->tableLayoutPanel4->Controls->Add(this->dataGridViewAddresses, 0, 0);
				this->tableLayoutPanel4->Location = Point(193, 2);
				this->tableLayoutPanel4->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 2;
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 74.91166F));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 25.08834F));
				this->tableLayoutPanel4->Size = Drawing::Size(292, 230);
				this->tableLayoutPanel4->TabIndex = 1;

				/*-------------------- tableLayoutPanel5 --------------------*/
				this->tableLayoutPanel5->ColumnCount = 3;
				this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 59.375F));
				this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 40.625F));
				this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 95));
				this->tableLayoutPanel5->Controls->Add(this->buttonDelete, 2, 0);
				this->tableLayoutPanel5->Controls->Add(this->buttonEdit, 1, 0);
				this->tableLayoutPanel5->Controls->Add(this->buttonAdd, 0, 0);
				this->tableLayoutPanel5->Location = Point(2, 174);
				this->tableLayoutPanel5->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				this->tableLayoutPanel5->RowCount = 1;
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel5->Size = Drawing::Size(288, 53);
				this->tableLayoutPanel5->TabIndex = 0;

				/*-------------------- tableLayoutPanel6 --------------------*/
				this->tableLayoutPanel6->ColumnCount = 2;
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->Controls->Add(this->buttonValidate, 1, 0);
				this->tableLayoutPanel6->Controls->Add(this->buttonCancel, 0, 0);
				this->tableLayoutPanel6->Location = Point(2, 291);
				this->tableLayoutPanel6->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
				this->tableLayoutPanel6->RowCount = 1;
				this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->Size = Drawing::Size(488, 54);
				this->tableLayoutPanel6->TabIndex = 1;

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->labelTitle->Location = Point(204, 9);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(84, 31);
				this->labelTitle->TabIndex = 2;
				this->labelTitle->Text = L"Client";

				/*-------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::Left;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLastName->Location = Point(8, 5);
				this->labelLastName->Margin = Windows::Forms::Padding(8, 0, 2, 0);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->TabIndex = 0;
				this->labelLastName->Text = L"Nom";

				/*-------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::Left;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelFirstName->Location = Point(8, 82);
				this->labelFirstName->Margin = Windows::Forms::Padding(8, 0, 2, 0);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->TabIndex = 1;
				this->labelFirstName->Text = L"Prenom";

				/*-------------------- labelBirthDate --------------------*/
				this->labelBirthDate->Anchor = AnchorStyles::Left;
				this->labelBirthDate->AutoSize = true;
				this->labelBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBirthDate->Location = Point(8, 162);
				this->labelBirthDate->Margin = Windows::Forms::Padding(8, 0, 2, 0);
				this->labelBirthDate->Name = L"labelBirthDate";
				this->labelBirthDate->Size = Drawing::Size(174, 25);
				this->labelBirthDate->TabIndex = 2;
				this->labelBirthDate->Text = L"Date de naissance";

				/*-------------------- dataGridViewAddresses --------------------*/
				this->dataGridViewAddresses->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewAddresses->Location = Point(2, 2);
				this->dataGridViewAddresses->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->dataGridViewAddresses->Name = L"dataGridViewAddresses";
				this->dataGridViewAddresses->RowHeadersWidth = 51;
				this->dataGridViewAddresses->RowTemplate->Height = 24;
				this->dataGridViewAddresses->Size = Drawing::Size(288, 167);
				this->dataGridViewAddresses->TabIndex = 1;

				/*-------------------- textBoxLastName --------------------*/
				this->textBoxLastName->Anchor = AnchorStyles::Left;
				this->textBoxLastName->Location = Point(8, 46);
				this->textBoxLastName->Margin = Windows::Forms::Padding(8, 2, 8, 2);
				this->textBoxLastName->Name = L"textBoxLastName";
				this->textBoxLastName->Size = Drawing::Size(168, 20);
				this->textBoxLastName->TabIndex = 3;
				this->textBoxLastName->Text = *this->lastName;

				/*-------------------- textBoxFirstName --------------------*/
				this->textBoxFirstName->Anchor = AnchorStyles::Left;
				this->textBoxFirstName->Location = Point(8, 123);
				this->textBoxFirstName->Margin = Windows::Forms::Padding(8, 2, 8, 2);
				this->textBoxFirstName->Name = L"textBoxFirstName";
				this->textBoxFirstName->Size = Drawing::Size(168, 20);
				this->textBoxFirstName->TabIndex = 4;
				this->textBoxFirstName->Text = *this->firstName;

				/*-------------------- textBoxBirthDate --------------------*/
				this->textBoxBirthDate->Anchor = AnchorStyles::Left;
				this->textBoxBirthDate->Location = Point(8, 203);
				this->textBoxBirthDate->Margin = Windows::Forms::Padding(8, 2, 8, 2);
				this->textBoxBirthDate->Name = L"textBoxBirthDate";
				this->textBoxBirthDate->Size = Drawing::Size(168, 20);
				this->textBoxBirthDate->TabIndex = 5;
				this->textBoxBirthDate->Text = *this->birthdate;

				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->buttonAdd->Location = Point(42, 21);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(67, 26);
				this->buttonAdd->TabIndex = 0;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &CustomerForm::buttonAdd_Click);

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->buttonEdit->Location = Point(120, 21);
				this->buttonEdit->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(67, 26);
				this->buttonEdit->TabIndex = 1;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;
				this->buttonEdit->Click += gcnew EventHandler(this, &CustomerForm::buttonEdit_Click);

				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->buttonDelete->Location = Point(197, 21);
				this->buttonDelete->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(86, 26);
				this->buttonDelete->TabIndex = 2;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				this->buttonDelete->Click += gcnew EventHandler(this, &CustomerForm::buttonDelete_Click);

				/*-------------------- buttonCancel --------------------*/
				this->buttonCancel->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonCancel->Location = Point(5, 17);
				this->buttonCancel->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonCancel->Name = L"buttonCancel";
				this->buttonCancel->Size = Drawing::Size(95, 31);
				this->buttonCancel->TabIndex = 0;
				this->buttonCancel->Text = L"Annuler";
				this->buttonCancel->UseVisualStyleBackColor = true;
				this->buttonCancel->Click += gcnew EventHandler(this, &CustomerForm::buttonCancel_Click);

				/*-------------------- buttonValidate --------------------*/
				this->buttonValidate->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonValidate->Location = Point(399, 17);
				this->buttonValidate->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(84, 31);
				this->buttonValidate->TabIndex = 1;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;
				this->buttonValidate->Click += gcnew EventHandler(this, &CustomerForm::buttonValidate_Click);

				/*-------------------- CustomerForm --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(512, 368);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->Name = L"CustomerForm";
				this->Text = L"CustomerForm";
			}

			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
			Void buttonCancel_Click(Object^ sender, EventArgs^ e);
			Void buttonValidate_Click(Object^ sender, EventArgs^ e);
	};
}
