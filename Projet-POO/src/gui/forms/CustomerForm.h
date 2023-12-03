#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Data;
using namespace Drawing;

namespace Projet_POO
{
	public ref class CustomerForm : public Form
	{
		public:
			CustomerForm(String^ customerId, String^ lastName, String^ firstName, String^ birthdate)
			{
				this->customerId = customerId;
				this->firstName = firstName;
				this->lastName = lastName;
				this->birthdate = birthdate;
				
				initialize();
				reloadAddressesGridView();
			}

		private:
			String^ customerId;
			String^ lastName;
			String^ firstName;
			String^ birthdate;
			int^ mode = customerId == "" ? 0 : 1; //0 = add, 1 = edit

			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;
			TableLayoutPanel^ tableLayoutPanel5;
			TableLayoutPanel^ tableLayoutPanel6;

			DataGridView^ dataGridViewAddresses;

			Label^ labelTitle;
			Label^ labelLastName;
			Label^ labelFirstName;
			Label^ labelBirthDate;

			TextBox^ textBoxLastName;
			TextBox^ textBoxFirstName;
			TextBox^ textBoxBirthdate;

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
				
				this->dataGridViewAddresses = gcnew DataGridView();
				
				this->labelTitle = gcnew Label();
				this->labelLastName = gcnew Label();
				this->labelFirstName = gcnew Label();
				this->labelBirthDate = gcnew Label();
				
				this->textBoxFirstName = gcnew TextBox();
				this->textBoxLastName = gcnew TextBox();
				this->textBoxBirthdate = gcnew TextBox();
				
				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();
				this->buttonCancel = gcnew Button();
				this->buttonValidate = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel6, 0, 2);
				this->tableLayoutPanel1->Location = Point(13, 13);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 15.18072F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 84.81927F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 66));
				this->tableLayoutPanel1->Size = Drawing::Size(659, 436);
				this->tableLayoutPanel1->TabIndex = 0;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 43.03216F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 56.96784F));
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 0, 0);
				this->tableLayoutPanel2->Location = Point(3, 59);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(653, 307);
				this->tableLayoutPanel2->TabIndex = 0;

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 1);
				this->tableLayoutPanel3->Controls->Add(this->dataGridViewAddresses, 0, 0);
				this->tableLayoutPanel3->Location = Point(284, 3);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 2;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 75.08091F));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 24.91909F));
				this->tableLayoutPanel3->Size = Drawing::Size(366, 301);
				this->tableLayoutPanel3->TabIndex = 0;

				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 3;
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 49.56897F));
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50.43103F));
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 125));
				this->tableLayoutPanel4->Controls->Add(this->buttonDelete, 2, 0);
				this->tableLayoutPanel4->Controls->Add(this->buttonEdit, 1, 0);
				this->tableLayoutPanel4->Controls->Add(this->buttonAdd, 0, 0);
				this->tableLayoutPanel4->Location = Point(3, 228);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 1;
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel4->Size = Drawing::Size(358, 70);
				this->tableLayoutPanel4->TabIndex = 0;

				/*-------------------- tableLayoutPanel5 --------------------*/
				this->tableLayoutPanel5->ColumnCount = 1;
				this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel5->Controls->Add(this->textBoxBirthdate, 0, 5);
				this->tableLayoutPanel5->Controls->Add(this->textBoxFirstName, 0, 3);
				this->tableLayoutPanel5->Controls->Add(this->labelLastName, 0, 0);
				this->tableLayoutPanel5->Controls->Add(this->labelBirthDate, 0, 4);
				this->tableLayoutPanel5->Controls->Add(this->labelFirstName, 0, 2);
				this->tableLayoutPanel5->Controls->Add(this->textBoxLastName, 0, 1);
				this->tableLayoutPanel5->Location = Point(3, 3);
				this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				this->tableLayoutPanel5->RowCount = 6;
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 49));
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 52));
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 52));
				this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 48));
				this->tableLayoutPanel5->Size = Drawing::Size(275, 301);
				this->tableLayoutPanel5->TabIndex = 1;

				/*-------------------- tableLayoutPanel6 --------------------*/
				this->tableLayoutPanel6->ColumnCount = 2;
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->Controls->Add(this->buttonValidate, 1, 0);
				this->tableLayoutPanel6->Controls->Add(this->buttonCancel, 0, 0);
				this->tableLayoutPanel6->Location = Point(3, 372);
				this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
				this->tableLayoutPanel6->RowCount = 1;
				this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->Size = Drawing::Size(653, 61);
				this->tableLayoutPanel6->TabIndex = 2;

				/*-------------------- dataGridViewAddresses --------------------*/
				this->dataGridViewAddresses->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewAddresses->Location = Point(3, 3);
				this->dataGridViewAddresses->Name = L"dataGridViewAddresses";
				this->dataGridViewAddresses->Size = Drawing::Size(358, 219);
				this->dataGridViewAddresses->TabIndex = 1;
				this->dataGridViewAddresses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewAddresses->ReadOnly = true;
				this->dataGridViewAddresses->AllowUserToResizeRows = false;
				this->dataGridViewAddresses->AllowUserToAddRows = false;
				this->dataGridViewAddresses->RowHeadersVisible = false;
				this->dataGridViewAddresses->MultiSelect = false;
				this->dataGridViewAddresses->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->dataGridViewAddresses->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewAddresses->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
				this->dataGridViewAddresses->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
				this->dataGridViewAddresses->ColumnHeadersHeight = 40;

				auto idAddress = gcnew DataGridViewTextBoxColumn();
				idAddress->Name = L"id_address";
				idAddress->Visible = false;
				this->dataGridViewAddresses->Columns->Add(idAddress);

				auto address = gcnew DataGridViewTextBoxColumn();
				address->Name = L"Libelle";
				this->dataGridViewAddresses->Columns->Add(address);

				auto zipCode = gcnew DataGridViewTextBoxColumn();
				zipCode->Name = L"Code postal";
				this->dataGridViewAddresses->Columns->Add(zipCode);

				auto city = gcnew DataGridViewTextBoxColumn();
				city->Name = L"Ville";
				this->dataGridViewAddresses->Columns->Add(city);

				auto idType = gcnew DataGridViewTextBoxColumn();
				idType->Name = L"id_address_type";
				idType->Visible = false;
				this->dataGridViewAddresses->Columns->Add(idType);

				auto type = gcnew DataGridViewTextBoxColumn();
				type->Name = L"Type d'adresse";
				this->dataGridViewAddresses->Columns->Add(type);
				
				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(277, 8);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(105, 39);
				this->labelTitle->TabIndex = 1;
				this->labelTitle->Text = L"Client";
				
				/*-------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::Left;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLastName->Location = Point(10, 12);
				this->labelLastName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->TabIndex = 0;
				this->labelLastName->Text = L"Nom";

				/*-------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::Left;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelFirstName->Location = Point(10, 112);
				this->labelFirstName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->TabIndex = 1;
				this->labelFirstName->Text = L"Prenom";

				/*-------------------- labelBirthDate --------------------*/
				this->labelBirthDate->Anchor = AnchorStyles::Left;
				this->labelBirthDate->AutoSize = true;
				this->labelBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBirthDate->Location = Point(10, 214);
				this->labelBirthDate->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelBirthDate->Name = L"labelBirthDate";
				this->labelBirthDate->Size = Drawing::Size(174, 25);
				this->labelBirthDate->TabIndex = 2;
				this->labelBirthDate->Text = L"Date de naissance";

				/*-------------------- textBoxLastName --------------------*/
				this->textBoxLastName->Anchor = AnchorStyles::Left;
				this->textBoxLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxLastName->Location = Point(10, 60);
				this->textBoxLastName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxLastName->Name = L"textBoxLastName";
				this->textBoxLastName->Size = Drawing::Size(255, 30);
				this->textBoxLastName->TabIndex = 3;
				this->textBoxLastName->Text = this->lastName;

				/*-------------------- textBoxFirstName --------------------*/
				this->textBoxFirstName->Anchor = AnchorStyles::Left;
				this->textBoxFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxFirstName->Location = Point(10, 160);
				this->textBoxFirstName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxFirstName->Name = L"textBoxFirstName";
				this->textBoxFirstName->Size = Drawing::Size(255, 30);
				this->textBoxFirstName->TabIndex = 4;
				this->textBoxFirstName->Text = this->firstName;

				/*-------------------- textBoxBirthdate --------------------*/
				this->textBoxBirthdate->Anchor = AnchorStyles::Left;
				this->textBoxBirthdate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxBirthdate->Location = Point(10, 262);
				this->textBoxBirthdate->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxBirthdate->Name = L"textBoxBirthdate";
				this->textBoxBirthdate->Size = Drawing::Size(255, 30);
				this->textBoxBirthdate->TabIndex = 5;
				this->textBoxBirthdate->Text = this->birthdate;

				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonAdd->Location = Point(7, 7);
				this->buttonAdd->Margin = Windows::Forms::Padding(7);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(101, 56);
				this->buttonAdd->TabIndex = 0;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &CustomerForm::buttonAdd_Click);

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonEdit->Location = Point(122, 7);
				this->buttonEdit->Margin = Windows::Forms::Padding(7);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(103, 56);
				this->buttonEdit->TabIndex = 1;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;
				this->buttonEdit->Click += gcnew EventHandler(this, &CustomerForm::buttonEdit_Click);
				
				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonDelete->Location = Point(239, 7);
				this->buttonDelete->Margin = Windows::Forms::Padding(7);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(112, 56);
				this->buttonDelete->TabIndex = 2;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				this->buttonDelete->Click += gcnew EventHandler(this, &CustomerForm::buttonDelete_Click);

				/*-------------------- buttonCancel --------------------*/
				this->buttonCancel->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonCancel->Location = Point(7, 18);
				this->buttonCancel->Margin = Windows::Forms::Padding(7);
				this->buttonCancel->Name = L"buttonCancel";
				this->buttonCancel->Size = Drawing::Size(136, 36);
				this->buttonCancel->TabIndex = 0;
				this->buttonCancel->Text = L"Annuler";
				this->buttonCancel->UseVisualStyleBackColor = true;
				this->buttonCancel->Click += gcnew EventHandler(this, &CustomerForm::buttonCancel_Click);

				/*-------------------- buttonValidate --------------------*/
				this->buttonValidate->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonValidate->Location = Point(510, 18);
				this->buttonValidate->Margin = Windows::Forms::Padding(7);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(136, 36);
				this->buttonValidate->TabIndex = 1;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;
				this->buttonValidate->Click += gcnew EventHandler(this, &CustomerForm::buttonValidate_Click);
				
				/*-------------------- CustomerForm --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"CustomerForm";
				this->Text = L"CustomerForm";
				this->Closed += gcnew EventHandler(this, &CustomerForm::buttonCancel_Click);
			}

			Void reloadAddressesGridView();
			int^ createCustomer();
			Void openAddressesForm(String^ addressId, String^ address, String^ zipCode, String^ city, String^ type);
			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
			Void buttonCancel_Click(Object^ sender, EventArgs^ e);
			Void buttonValidate_Click(Object^ sender, EventArgs^ e);
	};
}
