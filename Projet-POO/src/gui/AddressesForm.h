#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
    public ref class AddressesForm : public Form
    {
    public:
        AddressesForm()
        {
            initialize();
        }

    private:
        TableLayoutPanel^ tableLayoutPanel1;
        TableLayoutPanel^ tableLayoutPanel2;
        TableLayoutPanel^ tableLayoutPanel3;
        TableLayoutPanel^ tableLayoutPanel4;
        TableLayoutPanel^ tableLayoutPanel5;

        Label^ labelTitle;
        Label^ labelCity;
        Label^ labelZipCode;
        Label^ labelWording;
        Label^ labelAdressType;

        TextBox^ textBoxStreetName;
        TextBox^ textBoxZipCode;

        CheckBox^ checkBoxDelivery;
        CheckBox^ checkBoxBilling;

        ComboBox^ comboBoxCity;

        Button^ buttonValidate;
        Button^ buttonCancel;

        void initialize()
        {
            this->tableLayoutPanel1 = gcnew TableLayoutPanel();
            this->tableLayoutPanel2 = gcnew TableLayoutPanel();
            this->tableLayoutPanel3 = gcnew TableLayoutPanel();
            this->tableLayoutPanel4 = gcnew TableLayoutPanel();
            this->tableLayoutPanel5 = gcnew TableLayoutPanel();
            this->labelTitle = gcnew Label();
            this->labelCity = gcnew Label();
            this->labelZipCode = gcnew Label();
            this->labelWording = gcnew Label();
            this->labelAdressType = gcnew Label();
            this->textBoxStreetName = gcnew TextBox();
            this->textBoxZipCode = gcnew TextBox();
            this->checkBoxDelivery = gcnew CheckBox();
            this->checkBoxBilling = gcnew CheckBox();
            this->comboBoxCity = gcnew ComboBox();
            this->buttonValidate = gcnew Button();
            this->buttonCancel = gcnew Button();

            /*-------------------- tableLayoutPanel1 --------------------*/
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 0, 3);
            this->tableLayoutPanel1->Location = Point(10, 11);
            this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2, 2, 2, 2);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 4;
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 51.58371F));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 48.41629F));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 109));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 58));
            this->tableLayoutPanel1->Size = Drawing::Size(493, 348);
            this->tableLayoutPanel1->TabIndex = 0;

            /*-------------------- tableLayoutPanel2 --------------------*/
            this->tableLayoutPanel2->ColumnCount = 3;
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 128));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 164));
            this->tableLayoutPanel2->Controls->Add(this->labelCity, 2, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelZipCode, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelWording, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->textBoxStreetName, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->textBoxZipCode, 1, 1);
            this->tableLayoutPanel2->Controls->Add(this->comboBoxCity, 2, 1);
            this->tableLayoutPanel2->Location = Point(2, 95);
            this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2, 2, 2, 2);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 2;
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 42.01681F));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 57.98319F));
            this->tableLayoutPanel2->Size = Drawing::Size(488, 82);
            this->tableLayoutPanel2->TabIndex = 1;

            /*-------------------- tableLayoutPanel3 --------------------*/
            this->tableLayoutPanel3->ColumnCount = 1;
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel3->Controls->Add(this->labelAdressType, 0, 0);
            this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 1);
            this->tableLayoutPanel3->Location = Point(2, 182);
            this->tableLayoutPanel3->Margin = Windows::Forms::Padding(2, 2, 2, 2);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 2;
            this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 43.75F));
            this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 56.25F));
            this->tableLayoutPanel3->Size = Drawing::Size(488, 104);
            this->tableLayoutPanel3->TabIndex = 2;

            /*-------------------- tableLayoutPanel4 --------------------*/
            this->tableLayoutPanel4->ColumnCount = 2;
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 38.42975F));
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 61.57025F));
            this->tableLayoutPanel4->Controls->Add(this->checkBoxDelivery, 1, 0);
            this->tableLayoutPanel4->Controls->Add(this->checkBoxBilling, 0, 0);
            this->tableLayoutPanel4->Location = Point(2, 47);
            this->tableLayoutPanel4->Margin = Windows::Forms::Padding(2, 2, 2, 2);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 1;
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel4->Size = Drawing::Size(484, 54);
            this->tableLayoutPanel4->TabIndex = 1;

            /*-------------------- tableLayoutPanel5 --------------------*/
            this->tableLayoutPanel5->ColumnCount = 2;
            this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel5->Controls->Add(this->buttonValidate, 0, 0);
            this->tableLayoutPanel5->Controls->Add(this->buttonCancel, 0, 0);
            this->tableLayoutPanel5->Location = Point(2, 291);
            this->tableLayoutPanel5->Margin = Windows::Forms::Padding(2, 2, 2, 2);
            this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
            this->tableLayoutPanel5->RowCount = 1;
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel5->Size = Drawing::Size(488, 54);
            this->tableLayoutPanel5->TabIndex = 3;

            /*-------------------- labelTitle --------------------*/
            this->labelTitle->Anchor = AnchorStyles::None;
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
            this->labelTitle->Location = Point(182, 31);
            this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = Drawing::Size(128, 31);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Adresses";

            /*-------------------- labelCity --------------------*/
            this->labelCity->Anchor = AnchorStyles::Left;
            this->labelCity->AutoSize = true;
            this->labelCity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelCity->Location = Point(332, 4);
            this->labelCity->Margin = Windows::Forms::Padding(8, 0, 2, 0);
            this->labelCity->Name = L"labelCity";
            this->labelCity->Size = Drawing::Size(49, 25);
            this->labelCity->TabIndex = 2;
            this->labelCity->Text = L"Ville";

            /*-------------------- labelZipCode --------------------*/
            this->labelZipCode->Anchor = AnchorStyles::Left;
            this->labelZipCode->AutoSize = true;
            this->labelZipCode->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelZipCode->Location = Point(204, 4);
            this->labelZipCode->Margin = Windows::Forms::Padding(8, 0, 2, 0);
            this->labelZipCode->Name = L"labelZipCode";
            this->labelZipCode->Size = Drawing::Size(117, 25);
            this->labelZipCode->TabIndex = 1;
            this->labelZipCode->Text = L"Code postal";

            /*-------------------- labelWording --------------------*/
            this->labelWording->Anchor = AnchorStyles::Left;
            this->labelWording->AutoSize = true;
            this->labelWording->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelWording->Location = Point(8, 4);
            this->labelWording->Margin = Windows::Forms::Padding(8, 0, 2, 0);
            this->labelWording->Name = L"labelWording";
            this->labelWording->Size = Drawing::Size(68, 25);
            this->labelWording->TabIndex = 0;
            this->labelWording->Text = L"Libelle";

            /*-------------------- labelAdressType --------------------*/
            this->labelAdressType->Anchor = AnchorStyles::Left;
            this->labelAdressType->AutoSize = true;
            this->labelAdressType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelAdressType->Location = Point(8, 10);
            this->labelAdressType->Margin = Windows::Forms::Padding(8, 0, 2, 0);
            this->labelAdressType->Name = L"labelAdressType";
            this->labelAdressType->Size = Drawing::Size(147, 25);
            this->labelAdressType->TabIndex = 0;
            this->labelAdressType->Text = L"Type d\'adresse";

            /*-------------------- textBoxStreetName --------------------*/
            this->textBoxStreetName->Location = Point(8, 42);
            this->textBoxStreetName->Margin = Windows::Forms::Padding(8, 8, 8, 8);
            this->textBoxStreetName->Name = L"textBoxStreetName";
            this->textBoxStreetName->Size = Drawing::Size(177, 20);
            this->textBoxStreetName->TabIndex = 3;
            
            /*-------------------- textBoxZipCode --------------------*/
            this->textBoxZipCode->Location = Point(204, 42);
            this->textBoxZipCode->Margin = Windows::Forms::Padding(8, 8, 8, 8);
            this->textBoxZipCode->Name = L"textBoxZipCode";
            this->textBoxZipCode->Size = Drawing::Size(112, 20);
            this->textBoxZipCode->TabIndex = 4;

            /*-------------------- checkBoxDelivery --------------------*/
            this->checkBoxDelivery->Anchor = AnchorStyles::Left;
            this->checkBoxDelivery->AutoSize = true;
            this->checkBoxDelivery->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
            this->checkBoxDelivery->Location = Point(194, 16);
            this->checkBoxDelivery->Margin = Windows::Forms::Padding(8, 2, 8, 2);
            this->checkBoxDelivery->Name = L"checkBoxDelivery";
            this->checkBoxDelivery->Size = Drawing::Size(155, 21);
            this->checkBoxDelivery->TabIndex = 1;
            this->checkBoxDelivery->Text = L"Adresse de livraison";
            this->checkBoxDelivery->UseVisualStyleBackColor = true;

            /*-------------------- checkBoxBilling --------------------*/
            this->checkBoxBilling->Anchor = AnchorStyles::Left;
            this->checkBoxBilling->AutoSize = true;
            this->checkBoxBilling->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
            this->checkBoxBilling->Location = Point(8, 16);
            this->checkBoxBilling->Margin = Windows::Forms::Padding(8, 2, 8, 2);
            this->checkBoxBilling->Name = L"checkBoxBilling";
            this->checkBoxBilling->Size = Drawing::Size(170, 21);
            this->checkBoxBilling->TabIndex = 0;
            this->checkBoxBilling->Text = L"Adresse de facturation";
            this->checkBoxBilling->UseVisualStyleBackColor = true;

            /*-------------------- comboBoxCity --------------------*/
            this->comboBoxCity->FormattingEnabled = true;
            this->comboBoxCity->Location = Point(332, 42);
            this->comboBoxCity->Margin = Windows::Forms::Padding(8, 8, 8, 8);
            this->comboBoxCity->Name = L"comboBoxCity";
            this->comboBoxCity->Size = Drawing::Size(148, 21);
            this->comboBoxCity->TabIndex = 5;


            /*-------------------- buttonValidate --------------------*/
            this->buttonValidate->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
            this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonValidate->Location = Point(399, 17);
            this->buttonValidate->Margin = Windows::Forms::Padding(5, 6, 5, 6);
            this->buttonValidate->Name = L"buttonValidate";
            this->buttonValidate->Size = Drawing::Size(84, 31);
            this->buttonValidate->TabIndex = 2;
            this->buttonValidate->Text = L"Valider";
            this->buttonValidate->UseVisualStyleBackColor = true;

            /*-------------------- buttonCancel --------------------*/
            this->buttonCancel->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
            this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonCancel->Location = Point(5, 17);
            this->buttonCancel->Margin = Windows::Forms::Padding(5, 6, 5, 6);
            this->buttonCancel->Name = L"buttonCancel";
            this->buttonCancel->Size = Drawing::Size(95, 31);
            this->buttonCancel->TabIndex = 1;
            this->buttonCancel->Text = L"Annuler";
            this->buttonCancel->UseVisualStyleBackColor = true;
            
            /*-------------------- AddressesForm --------------------*/
            this->AutoScaleDimensions = SizeF(6, 13);
            this->AutoScaleMode = AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(512, 368);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Margin = Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"AddressesForm";
            this->Text = L"AddressesForm";
        }
    };
}
