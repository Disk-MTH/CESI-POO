#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Data;
using namespace Drawing;

namespace Projet_POO
{
	public ref class StaffForm : public Form
	{
		public:
			StaffForm()
			{
				initialize();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;

			Label^ labelTitle;
			Label^ labelLastName;
			Label^ labelFirstName;
			Label^ labelBirthdate;
			Label^ labelBossLastName;
			Label^ labelBossFirstName;
			Label^ labelWording;
			Label^ labelZipCode;
			Label^ labelCity;

			TextBox^ textBoxLastName;
			TextBox^ textBoxFirstName;
			TextBox^ textBoxBirthdate;
			ComboBox^ comboBoxBossLastName;
			ComboBox^ comboBoxBossFirstName;
			TextBox^ textBoxWording;
			ComboBox^ comboBoxZipCode;
			ComboBox^ comboBoxCity;

			Button^ buttonCancel;
			Button^ buttonValidate;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();
				this->tableLayoutPanel4 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();
				this->labelLastName = gcnew Label();
				this->labelFirstName = gcnew Label();
				this->labelBirthdate = gcnew Label();
				this->labelBossLastName = gcnew Label();
				this->labelBossFirstName = gcnew Label();
				this->labelWording = gcnew Label();
				this->labelZipCode = gcnew Label();
				this->labelCity = gcnew Label();

				this->textBoxLastName = gcnew TextBox();
				this->textBoxFirstName = gcnew TextBox();
				this->textBoxBirthdate = gcnew TextBox();
				this->comboBoxBossLastName = gcnew ComboBox();
				this->comboBoxBossFirstName = gcnew ComboBox();
				this->textBoxWording = gcnew TextBox();
				this->comboBoxZipCode = gcnew ComboBox();
				this->comboBoxCity = gcnew ComboBox();

				this->buttonCancel = gcnew Button();
				this->buttonValidate = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 3);
				this->tableLayoutPanel1->Location = Point(12, 12);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 4;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 15));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 55));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 65));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 80));
				this->tableLayoutPanel1->Size = Drawing::Size(660, 560);
				this->tableLayoutPanel1->TabIndex = 0;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Controls->Add(this->comboBoxBossFirstName, 1, 3);
				this->tableLayoutPanel2->Controls->Add(this->labelBossLastName, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelLastName, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelFirstName, 0, 2);
				this->tableLayoutPanel2->Controls->Add(this->labelBirthdate, 0, 4);
				this->tableLayoutPanel2->Controls->Add(this->labelBossFirstName, 1, 2);
				this->tableLayoutPanel2->Controls->Add(this->textBoxLastName, 0, 1);
				this->tableLayoutPanel2->Controls->Add(this->textBoxFirstName, 0, 3);
				this->tableLayoutPanel2->Controls->Add(this->textBoxBirthdate, 0, 5);
				this->tableLayoutPanel2->Controls->Add(this->comboBoxBossLastName, 1, 1);
				this->tableLayoutPanel2->Location = Point(3, 81);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 6;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->Size = Drawing::Size(654, 300);
				this->tableLayoutPanel2->TabIndex = 1;

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 3;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 59.27505F));
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 40.72495F));
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 201));
				this->tableLayoutPanel3->Controls->Add(this->labelWording, 0, 0);
				this->tableLayoutPanel3->Controls->Add(this->labelZipCode, 1, 0);
				this->tableLayoutPanel3->Controls->Add(this->labelCity, 2, 0);
				this->tableLayoutPanel3->Controls->Add(this->comboBoxZipCode, 1, 1);
				this->tableLayoutPanel3->Controls->Add(this->textBoxWording, 0, 1);
				this->tableLayoutPanel3->Controls->Add(this->comboBoxCity, 2, 1);
				this->tableLayoutPanel3->Location = Point(3, 358);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 2;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Size = Drawing::Size(654, 76);
				this->tableLayoutPanel3->TabIndex = 2;

				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 3;
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 33));
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 34));
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 33));
				this->tableLayoutPanel4->Controls->Add(this->buttonCancel, 0, 0);
				this->tableLayoutPanel4->Controls->Add(this->buttonValidate, 2, 0);
				this->tableLayoutPanel4->Location = Point(3, 358);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 1;
				this->tableLayoutPanel4->Size = Drawing::Size(654, 50);
				this->tableLayoutPanel4->TabIndex = 2;

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(244, 19);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(171, 39);
				this->labelTitle->TabIndex = 0;
				this->labelTitle->Text = L"Personnel";

				/*-------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::None;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLastName->Location = Point(137, 9);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->TabIndex = 0;
				this->labelLastName->Text = L"Nom";

				/*-------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::None;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelFirstName->Location = Point(123, 100);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->TabIndex = 1;
				this->labelFirstName->Text = L"Prenom";

				/*-------------------- labelBirthdate --------------------*/
				this->labelBirthdate->Anchor = AnchorStyles::None;
				this->labelBirthdate->AutoSize = true;
				this->labelBirthdate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBirthdate->Location = Point(76, 192);
				this->labelBirthdate->Name = L"labelBirthdate";
				this->labelBirthdate->Size = Drawing::Size(174, 25);
				this->labelBirthdate->TabIndex = 2;
				this->labelBirthdate->Text = L"Date de naissance";

				/*-------------------- labelBossLastName --------------------*/
				this->labelBossLastName->Anchor = AnchorStyles::None;
				this->labelBossLastName->AutoSize = true;
				this->labelBossLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBossLastName->Location = Point(421, 9);
				this->labelBossLastName->Name = L"labelBossLastName";
				this->labelBossLastName->Size = Drawing::Size(139, 25);
				this->labelBossLastName->TabIndex = 3;
				this->labelBossLastName->Text = L"Nom superieur";

				/*-------------------- labelBossFirstName --------------------*/
				this->labelBossFirstName->Anchor = AnchorStyles::None;
				this->labelBossFirstName->AutoSize = true;
				this->labelBossFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBossFirstName->Location = Point(407, 100);
				this->labelBossFirstName->Name = L"labelBossFirstName";
				this->labelBossFirstName->Size = Drawing::Size(166, 25);
				this->labelBossFirstName->TabIndex = 4;
				this->labelBossFirstName->Text = L"Prenom superieur";

				/*-------------------- labelWording --------------------*/
				this->labelWording->Anchor = AnchorStyles::None;
				this->labelWording->AutoSize = true;
				this->labelWording->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelWording->Location = Point(100, 6);
				this->labelWording->Name = L"labelWording";
				this->labelWording->Size = Drawing::Size(68, 25);
				this->labelWording->TabIndex = 5;
				this->labelWording->Text = L"Libelle";

				/*-------------------- labelZipCode --------------------*/
				this->labelZipCode->Anchor = AnchorStyles::None;
				this->labelZipCode->AutoSize = true;
				this->labelZipCode->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelZipCode->Location = Point(301, 6);
				this->labelZipCode->Name = L"labelZipCode";
				this->labelZipCode->Size = Drawing::Size(117, 25);
				this->labelZipCode->TabIndex = 6;
				this->labelZipCode->Text = L"Code postal";

				/*-------------------- labelCity --------------------*/
				this->labelCity->Anchor = AnchorStyles::None;
				this->labelCity->AutoSize = true;
				this->labelCity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelCity->Location = Point(528, 6);
				this->labelCity->Name = L"labelCity";
				this->labelCity->Size = Drawing::Size(49, 25);
				this->labelCity->TabIndex = 7;
				this->labelCity->Text = L"Ville";

				/*-------------------- textBoxLastName --------------------*/
				this->textBoxLastName->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->textBoxLastName->Location = Point(10, 54);
				this->textBoxLastName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxLastName->Name = L"textBoxLastName";
				this->textBoxLastName->Size = Drawing::Size(307, 26);
				this->textBoxLastName->TabIndex = 5;

				/*-------------------- textBoxFirstName --------------------*/
				this->textBoxFirstName->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->textBoxFirstName->Location = Point(10, 145);
				this->textBoxFirstName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxFirstName->Name = L"textBoxFirstName";
				this->textBoxFirstName->Size = Drawing::Size(307, 26);
				this->textBoxFirstName->TabIndex = 6;

				/*-------------------- textBoxBirthdate --------------------*/
				this->textBoxBirthdate->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxBirthdate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->textBoxBirthdate->Location = Point(10, 236);
				this->textBoxBirthdate->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxBirthdate->Name = L"textBoxBirthdate";
				this->textBoxBirthdate->Size = Drawing::Size(307, 26);
				this->textBoxBirthdate->TabIndex = 7;

				/*-------------------- textBoxWording --------------------*/
				this->textBoxWording->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->textBoxWording->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->textBoxWording->Location = Point(10, 44);
				this->textBoxWording->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxWording->Name = L"textBoxWording";
				this->textBoxWording->Size = Drawing::Size(248, 26);
				this->textBoxWording->TabIndex = 8;

				/*-------------------- comboBoxBossLastName --------------------*/
				this->comboBoxBossLastName->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->comboBoxBossLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->comboBoxBossLastName->FormattingEnabled = true;
				this->comboBoxBossLastName->Location = Point(337, 56);
				this->comboBoxBossLastName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxBossLastName->Name = L"comboBoxBossLastName";
				this->comboBoxBossLastName->Size = Drawing::Size(307, 24);
				this->comboBoxBossLastName->TabIndex = 8;

				/*-------------------- comboBoxBossFirstName --------------------*/
				this->comboBoxBossFirstName->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->comboBoxBossFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->comboBoxBossFirstName->FormattingEnabled = true;
				this->comboBoxBossFirstName->Location = Point(337, 147);
				this->comboBoxBossFirstName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxBossFirstName->Name = L"comboBoxBossFirstName";
				this->comboBoxBossFirstName->Size = Drawing::Size(307, 24);
				this->comboBoxBossFirstName->TabIndex = 9;

				/*-------------------- comboBoxZipCode --------------------*/
				this->comboBoxZipCode->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->comboBoxZipCode->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->comboBoxZipCode->FormattingEnabled = true;
				this->comboBoxZipCode->Location = Point(278, 46);
				this->comboBoxZipCode->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxZipCode->Name = L"comboBoxZipCode";
				this->comboBoxZipCode->Size = Drawing::Size(164, 24);
				this->comboBoxZipCode->TabIndex = 10;

				/*-------------------- comboBoxCity --------------------*/
				this->comboBoxCity->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->comboBoxCity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->comboBoxCity->FormattingEnabled = true;
				this->comboBoxCity->Location = Point(462, 46);
				this->comboBoxCity->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxCity->Name = L"comboBoxCity";
				this->comboBoxCity->Size = Drawing::Size(182, 24);
				this->comboBoxCity->TabIndex = 11;

				/*-------------------- buttonCancel --------------------*/
				this->buttonCancel->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonCancel->Location = Point(12, 12);
				this->buttonCancel->Margin = Windows::Forms::Padding(3, 15, 3, 3);
				this->buttonCancel->Name = L"buttonCancel";
				this->buttonCancel->Size = Drawing::Size(75, 30);
				this->buttonCancel->TabIndex = 1;
				this->buttonCancel->Text = L"Annuler";
				this->buttonCancel->UseVisualStyleBackColor = true;
				
				/*-------------------- buttonValidate --------------------*/
				this->buttonValidate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonValidate->Location = Point(597, 12);
				this->buttonValidate->Margin = Windows::Forms::Padding(3, 15, 3, 3);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(75, 30);
				this->buttonValidate->TabIndex = 2;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;

				/*-------------------- StaffForm --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 560);
				this->Controls->Add(this->tableLayoutPanel1);
				this->MaximizeBox = false;
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->Name = L"StaffForm";
				this->Text = L"StaffForm";
			}
	};
}
