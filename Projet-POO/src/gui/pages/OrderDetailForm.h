#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
    public ref class OrderDetailForm : public Form
    {
    public:
        OrderDetailForm()
        {
            initialize();
        }

    private:
        TableLayoutPanel^ tableLayoutPanel1;
        TableLayoutPanel^ tableLayoutPanel2;
        TableLayoutPanel^ tableLayoutPanel3;
        TableLayoutPanel^ tableLayoutPanel4;
        
        Label^ labelLastName;
        Label^ labelTitle;
        Label^ labelValueDelivery;
        Label^ labelValueBilling;
        Label^ labelValueBirthDate;
        Label^ labelValueFirstName;
        Label^ labelBirthDate;
        Label^ labelFirstName;
        Label^ labelBilling;
        Label^ labelDelivery;
        Label^ labelValueLastName;
        Label^ labelValueVAT;
        Label^ labelVAT;
        Label^ labelTFTotalPrice;
        Label^ labelTotalPrice;
        Label^ labelValueTFTotalPrice;
        Label^ labelValueTotalPrice;

        DataGridView^ dataGridViewProducts;

        void initialize()
        {
            this->tableLayoutPanel1 = gcnew TableLayoutPanel();
            this->tableLayoutPanel2 = gcnew TableLayoutPanel();
            this->tableLayoutPanel3 = gcnew TableLayoutPanel();
            this->tableLayoutPanel4 = gcnew TableLayoutPanel();
            this->dataGridViewProducts = gcnew DataGridView();
            this->labelTitle = gcnew Label();
            this->labelLastName = gcnew Label();
            this->labelBilling = gcnew Label();
            this->labelFirstName = gcnew Label();
            this->labelDelivery = gcnew Label();
            this->labelBirthDate = gcnew Label();
            this->labelValueLastName = gcnew Label();
            this->labelValueFirstName = gcnew Label();
            this->labelValueBirthDate = gcnew Label();
            this->labelValueBilling = gcnew Label();
            this->labelValueDelivery = gcnew Label();
            this->labelTFTotalPrice = gcnew Label();
            this->labelTotalPrice = gcnew Label();
            this->labelVAT = gcnew Label();
            this->labelValueTFTotalPrice = gcnew Label();
            this->labelValueVAT = gcnew Label();
            this->labelValueTotalPrice = gcnew Label();
            
            /*-------------------- tableLayoutPanel1 --------------------*/
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent,50));
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
            this->tableLayoutPanel1->Location = Point(13, 13);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 20.33333F));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 79.66666F));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 101));
            this->tableLayoutPanel1->Size = Drawing::Size(657, 428);
            this->tableLayoutPanel1->TabIndex = 0;
          
            /*-------------------- tableLayoutPanel2 --------------------*/
            this->tableLayoutPanel2->ColumnCount = 4;
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 114));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 200));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 127));
            this->tableLayoutPanel2->Controls->Add(this->labelValueVAT, 3, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelVAT, 2, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelTFTotalPrice, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelTotalPrice, 2, 1);
            this->tableLayoutPanel2->Controls->Add(this->labelValueTFTotalPrice, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelValueTotalPrice, 3, 1);
            this->tableLayoutPanel2->Location = Point(3, 329);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 2;
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->Size = Drawing::Size(651, 96);
            this->tableLayoutPanel2->TabIndex = 0;
        
            /*-------------------- tableLayoutPanel3 --------------------*/
            this->tableLayoutPanel3->ColumnCount = 2;
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 59.44701F));
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 40.55299F));
            this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
            this->tableLayoutPanel3->Controls->Add(this->dataGridViewProducts, 1, 0);
            this->tableLayoutPanel3->Location = Point(3, 69);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 1;
            this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel3->Size = Drawing::Size(651, 254);
            this->tableLayoutPanel3->TabIndex = 1;
            
            /*-------------------- tableLayoutPanel4 --------------------*/
            this->tableLayoutPanel4->ColumnCount = 2;
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 41.81818F));
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 58.18182F));
            this->tableLayoutPanel4->Controls->Add(this->labelValueDelivery, 1, 4);
            this->tableLayoutPanel4->Controls->Add(this->labelValueBilling, 1, 3);
            this->tableLayoutPanel4->Controls->Add(this->labelValueBirthDate, 1, 2);
            this->tableLayoutPanel4->Controls->Add(this->labelValueFirstName, 1, 1);
            this->tableLayoutPanel4->Controls->Add(this->labelBirthDate, 0, 2);
            this->tableLayoutPanel4->Controls->Add(this->labelFirstName, 0, 1);
            this->tableLayoutPanel4->Controls->Add(this->labelLastName, 0, 0);
            this->tableLayoutPanel4->Controls->Add(this->labelBilling, 0, 3);
            this->tableLayoutPanel4->Controls->Add(this->labelDelivery, 0, 4);
            this->tableLayoutPanel4->Controls->Add(this->labelValueLastName, 1, 0);
            this->tableLayoutPanel4->Location = Point(3, 3);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 5;
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 47.72727F));
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 52.27273F));
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 58));
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 48));
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 41));
            this->tableLayoutPanel4->Size = Drawing::Size(381, 248);
            this->tableLayoutPanel4->TabIndex = 0;
           
            /*-------------------- labelTitle --------------------*/
            this->labelTitle->Anchor = AnchorStyles::None;
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
            this->labelTitle->Location = Point(84, 13);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = Drawing::Size(489, 39);
            this->labelTitle->TabIndex = 2;
            this->labelTitle->Text = L"Details de la commande + REF";
           
            /*-------------------- labelLastName --------------------*/
            this->labelLastName->Anchor = AnchorStyles::Left;
            this->labelLastName->AutoSize = true;
            this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelLastName->Location = Point(10, 9);
            this->labelLastName->Margin = Windows::Forms::Padding(10, 0, 10, 0);
            this->labelLastName->Name = L"labelLastName";
            this->labelLastName->Size = Drawing::Size(67, 29);
            this->labelLastName->TabIndex = 0;
            this->labelLastName->Text = L"Nom";
            
            /*-------------------- labelBilling --------------------*/
            this->labelBilling->Anchor = AnchorStyles::Left;
            this->labelBilling->AutoSize = true;
            this->labelBilling->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelBilling->Location = Point(10, 167);
            this->labelBilling->Margin = Windows::Forms::Padding(10, 0, 10, 0);
            this->labelBilling->Name = L"labelBilling";
            this->labelBilling->Size = Drawing::Size(139, 29);
            this->labelBilling->TabIndex = 1;
            this->labelBilling->Text = L"Facturation";
           
            /*-------------------- labelFirstName --------------------*/
            this->labelFirstName->Anchor = AnchorStyles::Left;
            this->labelFirstName->AutoSize = true;
            this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelFirstName->Location = Point(10, 59);
            this->labelFirstName->Margin = Windows::Forms::Padding(10, 0, 10, 0);
            this->labelFirstName->Name = L"labelFirstName";
            this->labelFirstName->Size = Drawing::Size(102, 29);
            this->labelFirstName->TabIndex = 2;
            this->labelFirstName->Text = L"Prenom";
          
            /*-------------------- labelDelivery --------------------*/
            this->labelDelivery->Anchor = AnchorStyles::Left;
            this->labelDelivery->AutoSize = true;
            this->labelDelivery->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelDelivery->Location = Point(10, 212);
            this->labelDelivery->Margin = Windows::Forms::Padding(10, 0, 10, 0);
            this->labelDelivery->Name = L"labelDelivery";
            this->labelDelivery->Size = Drawing::Size(115, 29);
            this->labelDelivery->TabIndex = 3;
            this->labelDelivery->Text = L"Livraison";
           
            /*-------------------- labelBirthDate --------------------*/
            this->labelBirthDate->Anchor = AnchorStyles::Left;
            this->labelBirthDate->AutoSize = true;
            this->labelBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelBirthDate->Location = Point(10, 114);
            this->labelBirthDate->Margin = Windows::Forms::Padding(10, 0, 10, 0);
            this->labelBirthDate->Name = L"labelBirthDate";
            this->labelBirthDate->Size = Drawing::Size(132, 29);
            this->labelBirthDate->TabIndex = 4;
            this->labelBirthDate->Text = L"Naissance";
          
            /*-------------------- labelValueLastName --------------------*/
            this->labelValueLastName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueLastName->AutoSize = true;
            this->labelValueLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueLastName->Location = Point(162, 0);
            this->labelValueLastName->Name = L"labelValueLastName";
            this->labelValueLastName->Size = Drawing::Size(216, 48);
            this->labelValueLastName->TabIndex = 5;
            this->labelValueLastName->TextAlign = ContentAlignment::MiddleLeft;
           
            /*-------------------- labelValueFirstName --------------------*/
            this->labelValueFirstName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueFirstName->AutoSize = true;
            this->labelValueFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueFirstName->Location = Point(162, 48);
            this->labelValueFirstName->Name = L"labelValueFirstName";
            this->labelValueFirstName->Size = Drawing::Size(216, 52);
            this->labelValueFirstName->TabIndex = 6;
            this->labelValueFirstName->TextAlign = ContentAlignment::MiddleLeft;
            
            /*-------------------- labelValueBirthDate --------------------*/
            this->labelValueBirthDate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueBirthDate->AutoSize = true;
            this->labelValueBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueBirthDate->Location = Point(162, 100);
            this->labelValueBirthDate->Name = L"labelValueBirthDate";
            this->labelValueBirthDate->Size = Drawing::Size(216, 58);
            this->labelValueBirthDate->TabIndex = 7;
            this->labelValueBirthDate->TextAlign = ContentAlignment::MiddleLeft;
            
            /*-------------------- labelValueBilling --------------------*/
            this->labelValueBilling->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueBilling->AutoSize = true;
            this->labelValueBilling->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueBilling->Location = Point(162, 158);
            this->labelValueBilling->Name = L"labelValueBilling";
            this->labelValueBilling->Size = Drawing::Size(216, 48);
            this->labelValueBilling->TabIndex = 8;
            this->labelValueBilling->TextAlign = ContentAlignment::MiddleLeft;
            
            /*-------------------- labelValueDelivery --------------------*/
            this->labelValueDelivery->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueDelivery->AutoSize = true;
            this->labelValueDelivery->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueDelivery->Location = Point(162, 206);
            this->labelValueDelivery->Name = L"labelValueDelivery";
            this->labelValueDelivery->Size = Drawing::Size(216, 42);
            this->labelValueDelivery->TabIndex = 9;
            this->labelValueDelivery->TextAlign = ContentAlignment::MiddleLeft;
            
            /*-------------------- labelTFTotalPrice --------------------*/
            this->labelTFTotalPrice->Anchor = AnchorStyles::Right;
            this->labelTFTotalPrice->AutoSize = true;
            this->labelTFTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelTFTotalPrice->Location = Point(98, 9);
            this->labelTFTotalPrice->Name = L"labelTFTotalPrice";
            this->labelTFTotalPrice->Size = Drawing::Size(109, 29);
            this->labelTFTotalPrice->TabIndex = 0;
            this->labelTFTotalPrice->Text = L"Total HT";
            
            /*-------------------- labelTotalPrice --------------------*/
            this->labelTotalPrice->Anchor = AnchorStyles::Right;
            this->labelTotalPrice->AutoSize = true;
            this->labelTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelTotalPrice->Location = Point(397, 57);
            this->labelTotalPrice->Name = L"labelTotalPrice";
            this->labelTotalPrice->Size = Drawing::Size(124, 29);
            this->labelTotalPrice->TabIndex = 1;
            this->labelTotalPrice->Text = L"Total TTC";
            
            /*-------------------- labelVAT --------------------*/
            this->labelVAT->Anchor = AnchorStyles::Right;
            this->labelVAT->AutoSize = true;
            this->labelVAT->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelVAT->Location = Point(459, 9);
            this->labelVAT->Name = L"labelVAT";
            this->labelVAT->Size = Drawing::Size(62, 29);
            this->labelVAT->TabIndex = 2;
            this->labelVAT->Text = L"TVA";
            
            /*-------------------- labelValueTFTotalPrice --------------------*/
            this->labelValueTFTotalPrice->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueTFTotalPrice->AutoSize = true;
            this->labelValueTFTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueTFTotalPrice->Location = Point(213, 0);
            this->labelValueTFTotalPrice->Name = L"labelValueTFTotalPrice";
            this->labelValueTFTotalPrice->Size = Drawing::Size(108, 48);
            this->labelValueTFTotalPrice->TabIndex = 3;
            this->labelValueTFTotalPrice->TextAlign = ContentAlignment::MiddleLeft;
            
            /*-------------------- labelValueVAT --------------------*/
            this->labelValueVAT->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueVAT->AutoSize = true;
            this->labelValueVAT->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueVAT->Location = Point(527, 0);
            this->labelValueVAT->Name = L"labelValueVAT";
            this->labelValueVAT->Size = Drawing::Size(121, 48);
            this->labelValueVAT->TabIndex = 4;
            this->labelValueVAT->TextAlign = ContentAlignment::MiddleLeft;
            
            /*-------------------- labelValueTotalPrice --------------------*/
            this->labelValueTotalPrice->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->labelValueTotalPrice->AutoSize = true;
            this->labelValueTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelValueTotalPrice->Location = Point(527, 48);
            this->labelValueTotalPrice->Name = L"labelValueTotalPrice";
            this->labelValueTotalPrice->Size = Drawing::Size(121, 48);
            this->labelValueTotalPrice->TabIndex = 5;
            this->labelValueTotalPrice->TextAlign = ContentAlignment::MiddleLeft;

            /*-------------------- dataGridViewProducts --------------------*/
            this->dataGridViewProducts->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewProducts->Location = Point(390, 3);
            this->dataGridViewProducts->Name = L"dataGridViewProducts";
            this->dataGridViewProducts->RowHeadersWidth = 51;
            this->dataGridViewProducts->RowTemplate->Height = 24;
            this->dataGridViewProducts->Size = Drawing::Size(258, 248);
            this->dataGridViewProducts->TabIndex = 1;
            
            /*-------------------- OrderDetailForm --------------------*/
            this->AutoScaleDimensions = SizeF(8, 16);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(682, 453);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Name = L"OrderDetailForm";
            this->Text = L"OrderDetailForm";
        }
    };
}
