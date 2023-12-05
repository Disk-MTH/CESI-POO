#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class PaymentForm : public Form
	{
		public:
			PaymentForm()
			{
				initialize();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;

			Label^ labelTitle;
			Label^ labelAmount;
			Label^ labelDate;
			Label^ labelType;

			TextBox^ textBoxAmount;
			TextBox^ textBoxDate;
			CheckBox^ checkBoxValidPayment;
			ComboBox^ comboBox1;

			Button^ buttonCancel;
			Button^ buttonValidate;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();
				this->labelAmount = gcnew Label();
				this->labelDate = gcnew Label();
				this->labelType = gcnew Label();

				this->textBoxAmount = gcnew TextBox();
				this->textBoxDate = gcnew TextBox();
				this->buttonValidate = gcnew Button();
				this->comboBox1 = gcnew ComboBox();

				this->buttonCancel = gcnew Button();
				this->checkBoxValidPayment = gcnew CheckBox();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
				this->tableLayoutPanel1->Location = Point(12, 12);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 15.18325F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 84.81676F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 58));
				this->tableLayoutPanel1->Size = Drawing::Size(370, 437);
				this->tableLayoutPanel1->TabIndex = 0;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 1;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Controls->Add(this->labelAmount, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelDate, 0, 4);
				this->tableLayoutPanel2->Controls->Add(this->labelType, 0, 2);
				this->tableLayoutPanel2->Controls->Add(this->textBoxAmount, 0, 1);
				this->tableLayoutPanel2->Controls->Add(this->textBoxDate, 0, 5);
				this->tableLayoutPanel2->Controls->Add(this->comboBox1, 0, 3);
				this->tableLayoutPanel2->Controls->Add(this->checkBoxValidPayment, 0, 6);
				this->tableLayoutPanel2->Location = Point(3, 60);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 7;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 48.75F));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 51.25F));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 46));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 53));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 52));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 38));
				this->tableLayoutPanel2->Size = Drawing::Size(654, 315);
				this->tableLayoutPanel2->TabIndex = 0;

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 2;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Controls->Add(this->buttonValidate, 1, 0);
				this->tableLayoutPanel3->Controls->Add(this->buttonCancel, 0, 0);
				this->tableLayoutPanel3->Location = Point(3, 381);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 1;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Size = Drawing::Size(654, 53);
				this->tableLayoutPanel3->TabIndex = 2;

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(245, 9);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(170, 39);
				this->labelTitle->TabIndex = 1;
				this->labelTitle->Text = L"Payement";

				/*-------------------- labelAmount --------------------*/
				this->labelAmount->Anchor = AnchorStyles::Left;
				this->labelAmount->AutoSize = true;
				this->labelAmount->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelAmount->Location = Point(10, 7);
				this->labelAmount->Margin = Windows::Forms::Padding(7, 0, 7, 0);
				this->labelAmount->Name = L"labelAmount";
				this->labelAmount->Size = Drawing::Size(187, 25);
				this->labelAmount->TabIndex = 0;
				this->labelAmount->Text = L"Valeur du payement";

				/*-------------------- labelDate --------------------*/
				this->labelDate->Anchor = AnchorStyles::Left;
				this->labelDate->AutoSize = true;
				this->labelDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelDate->Location = Point(10, 192);
				this->labelDate->Margin = Windows::Forms::Padding(7, 0, 7, 0);
				this->labelDate->Name = L"labelDate";
				this->labelDate->Size = Drawing::Size(171, 25);
				this->labelDate->TabIndex = 2;
				this->labelDate->Text = L"Date du payement";

				/*-------------------- labelType --------------------*/
				this->labelType->Anchor = AnchorStyles::Left;
				this->labelType->AutoSize = true;
				this->labelType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelType->Location = Point(10, 90);
				this->labelType->Margin = Windows::Forms::Padding(7, 0, 7, 0);
				this->labelType->Name = L"labelType";
				this->labelType->Size = Drawing::Size(175, 25);
				this->labelType->TabIndex = 1;
				this->labelType->Text = L"Type de payement";

				/*-------------------- textBoxAmount --------------------*/
				this->textBoxAmount->Anchor = AnchorStyles::Left; //TODO
				this->textBoxAmount->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxAmount->Location = Point(10, 44);
				this->textBoxAmount->Margin = Windows::Forms::Padding(9, 3, 0, 3);
				this->textBoxAmount->Name = L"textBoxAmount";
				this->textBoxAmount->Size = Drawing::Size(339, 30);
				this->textBoxAmount->TabIndex = 3;

				/*-------------------- textBoxDate --------------------*/
				this->textBoxDate->Anchor = AnchorStyles::Left;
				this->textBoxDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxDate->Location = Point(10, 238);
				this->textBoxDate->Margin = Windows::Forms::Padding(9, 3, 0, 3);
				this->textBoxDate->Name = L"textBoxDate";
				this->textBoxDate->Size = Drawing::Size(339, 30);
				this->textBoxDate->TabIndex = 4;

				/*-------------------- comboBox1 --------------------*/
				this->comboBox1->Anchor = AnchorStyles::Left;
				this->comboBox1->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBox1->FormattingEnabled = true;
				this->comboBox1->Location = Point(10, 138);
				this->comboBox1->Margin = Windows::Forms::Padding(9, 3, 0, 3);
				this->comboBox1->Name = L"comboBox1";
				this->comboBox1->Size = Drawing::Size(339, 33);
				this->comboBox1->TabIndex = 5;

				/*-------------------- checkBoxValidPayment --------------------*/
				this->checkBoxValidPayment->Anchor = AnchorStyles::Left;
				this->checkBoxValidPayment->AutoSize = true;
				this->checkBoxValidPayment->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->checkBoxValidPayment->Location = Point(10, 281);
				this->checkBoxValidPayment->Margin = Windows::Forms::Padding(9, 3, 0, 3);
				this->checkBoxValidPayment->Name = L"checkBoxValidPayment";
				this->checkBoxValidPayment->Size = Drawing::Size(128, 29);
				this->checkBoxValidPayment->TabIndex = 6;
				this->checkBoxValidPayment->Text = L"checkBox1";
				this->checkBoxValidPayment->UseVisualStyleBackColor = true;

				/*-------------------- buttonCancel --------------------*/
				this->buttonCancel->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonCancel->Location = Point(7, 7);
				this->buttonCancel->Margin = Windows::Forms::Padding(7);
				this->buttonCancel->Name = L"buttonCancel";
				this->buttonCancel->Size = Drawing::Size(109, 39);
				this->buttonCancel->TabIndex = 0;
				this->buttonCancel->Text = L"Annuler";
				this->buttonCancel->UseVisualStyleBackColor = true;

				/*-------------------- buttonValidate --------------------*/
				this->buttonValidate->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonValidate->Location = Point(538, 7);
				this->buttonValidate->Margin = Windows::Forms::Padding(7);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(109, 39);
				this->buttonValidate->TabIndex = 1;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;

				/*-------------------- PaymentForm --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(390, 460); //684
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"PaymentForm";
				this->Text = L"PaymentForm";
			}

			Void buttonCancel_Click(Object^ sender, EventArgs^ e);
			Void buttonValidate_Click(Object^ sender, EventArgs^ e);
	};
}
