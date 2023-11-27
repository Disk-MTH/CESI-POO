#pragma once

#include "../../App.h"

using namespace System;
using namespace Drawing;
using namespace Data;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class AddCustomerForm sealed : public Form
	{
		public:
			AddCustomerForm(String^* firstName, String^* lastName, String^* birthdate)
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
		
			TableLayoutPanel^ tableLayout1;
			TableLayoutPanel^ tableLayout2;

			Label^ labelFirstName;
			Label^ labelLastName;
			Label^ labelBirthdate;

			TextBox^ textBoxFirstName;
			TextBox^ textBoxLastName;
			TextBox^ textBoxBirthdate;

			Button^ buttonValidate;


			void initialize()
			{
				this->tableLayout1 = gcnew TableLayoutPanel();
				this->tableLayout2 = gcnew TableLayoutPanel();

				this->labelFirstName = gcnew Label();
				this->labelLastName = gcnew Label();
				this->labelBirthdate = gcnew Label();

				this->textBoxFirstName = gcnew TextBox();
				this->textBoxLastName = gcnew TextBox();
				this->textBoxBirthdate = gcnew TextBox();

				this->buttonValidate = gcnew Button();

				/* -------------------- tableLayout1 --------------------*/
				this->tableLayout1->ColumnCount = 2;
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 96));
				this->tableLayout1->Controls->Add(this->tableLayout2, 0, 0);
				this->tableLayout1->Controls->Add(this->buttonValidate, 1, 0);
				this->tableLayout1->Location = Point(12, 12);
				this->tableLayout1->Name = L"tableLayout1";
				this->tableLayout1->RowCount = 1;
				this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout1->Size = Drawing::Size(287, 186);
				this->tableLayout1->TabIndex = 0;

				/* -------------------- tableLayout2 --------------------*/
				this->tableLayout2->ColumnCount = 1;
				this->tableLayout2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout2->Controls->Add(this->textBoxBirthdate, 0, 5);
				this->tableLayout2->Controls->Add(this->textBoxFirstName, 0, 3);
				this->tableLayout2->Controls->Add(this->labelFirstName, 0, 0);
				this->tableLayout2->Controls->Add(this->labelBirthdate, 0, 4);
				this->tableLayout2->Controls->Add(this->textBoxLastName, 0, 1);
				this->tableLayout2->Controls->Add(this->labelLastName, 0, 2);
				this->tableLayout2->Location = Point(3, 3);
				this->tableLayout2->Name = L"tableLayout2";
				this->tableLayout2->RowCount = 6;
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 37.87879F));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 62.12121F));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 25));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 38));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 26));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 23));
				this->tableLayout2->Size = Drawing::Size(184, 180);
				this->tableLayout2->TabIndex = 0;

				/* -------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Location = Point(3, 3);
				this->labelFirstName->Margin = Windows::Forms::Padding(3);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(178, 19);
				this->labelFirstName->TabIndex = 0;
				this->labelFirstName->Text = L"Nom :";
				this->labelFirstName->TextAlign = ContentAlignment::MiddleCenter;

				/* -------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Location = Point(3, 70);
				this->labelLastName->Margin = Windows::Forms::Padding(3);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(178, 19);
				this->labelLastName->TabIndex = 1;
				this->labelLastName->Text = L"Prenom :";
				this->labelLastName->TextAlign = ContentAlignment::MiddleCenter;

				/* -------------------- labelBirthdate --------------------*/
				this->labelBirthdate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelBirthdate->AutoSize = true;
				this->labelBirthdate->Location = Point(3, 133);
				this->labelBirthdate->Margin = Windows::Forms::Padding(3);
				this->labelBirthdate->Name = L"labelBirthdate";
				this->labelBirthdate->Size = Drawing::Size(178, 20);
				this->labelBirthdate->TabIndex = 2;
				this->labelBirthdate->Text = L"Date de naissance :";
				this->labelBirthdate->TextAlign = ContentAlignment::MiddleCenter;

				/* -------------------- textBoxLastName --------------------*/
				this->textBoxFirstName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxFirstName->Location = Point(3, 95);
				this->textBoxFirstName->Name = L"textBoxBirthdate";
				this->textBoxFirstName->Size = Drawing::Size(178, 20);
				this->textBoxFirstName->TabIndex = 4;

				/* -------------------- textBoxFirstName --------------------*/
				this->textBoxLastName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxLastName->Location = Point(3, 28);
				this->textBoxLastName->Name = L"textBoxFirstName";
				this->textBoxLastName->Size = Drawing::Size(178, 20);
				this->textBoxLastName->TabIndex = 3;

				/* -------------------- textBoxBirthdate --------------------*/
				this->textBoxBirthdate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxBirthdate->Location = Point(3, 159);
				this->textBoxBirthdate->Name = L"textBoxLastName";
				this->textBoxBirthdate->Size = Drawing::Size(178, 20);
				this->textBoxBirthdate->TabIndex = 5;

				/* -------------------- buttonValidate --------------------*/
				this->buttonValidate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonValidate->Location = Point(201, 65);
				this->buttonValidate->Margin = Windows::Forms::Padding(10, 65, 10, 65);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(76, 56);
				this->buttonValidate->TabIndex = 1;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;
				this->buttonValidate->Click += gcnew EventHandler(this, &AddCustomerForm::buttonValidate_Click);

				/* -------------------- AddCustomerForm --------------------*/
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(311, 210);
				this->Controls->Add(this->tableLayout1);
				this->MaximizeBox = false;
				this->Name = L"AddCustomerForm";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->Text = L"AddCustomerForm";
			}

			Void buttonValidate_Click(Object^ sender, EventArgs^ e)
			{
				if (this->textBoxLastName->Text == nullptr || this->textBoxLastName->Text->Trim()->Length == 0)
				{
					App::app->logger->warn("Invalid last name: empty");
					MessageBox::Show("Le nom ne peux pas etre vide !", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				if (this->textBoxFirstName->Text == nullptr || this->textBoxFirstName->Text->Trim()->Length == 0)
				{
					App::app->logger->warn("Invalid first name: empty");
					MessageBox::Show("Le prenom ne peux pas etre vide !", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				DateTime date;
				if (!DateTime::TryParseExact(this->textBoxBirthdate->Text, "dd/MM/yyyy", nullptr, Globalization::DateTimeStyles::None, date))
				{
					App::app->logger->warn("Invalid birthdate: wrong format (\"" + this->textBoxBirthdate->Text + "\")");
					MessageBox::Show("       La date est invalide !\n\"dd/mm/yyyy\" ou \"dd-mm-yyyy\"", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				*this->firstName = this->textBoxLastName->Text;
				*this->lastName = this->textBoxFirstName->Text;
				*this->birthdate = date.ToString("yyyy-MM-dd");
				this->DialogResult = Windows::Forms::DialogResult::OK;
				this->Close();
			}
	};
}
