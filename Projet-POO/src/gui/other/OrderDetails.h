#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class OrderDetails : public Form
	{
		public:
			OrderDetails()
			{
				InitializeComponent();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;

			DataGridView^ dataGridViewProducts;

			Label^ labelTitle;

			Label^ labelValueDelivery;
			Label^ labelValueBilling;
			Label^ labelValueBirthDate;
			Label^ labelValueFirstName;
			Label^ labelValueLastName;
			Label^ labelValueTFTotalPrice;
			Label^ labelValueVAT;
			Label^ labelValueTotalPrice;

			Label^ labelDelivery;
			Label^ labelBilling;
			Label^ labelBirthDate;
			Label^ labelFirstName;
			Label^ labelLastName;
			Label^ labelVAT;
			Label^ labelTFTotalPrice;
			Label^ labelTotalPrice;


			void InitializeComponent()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();
				this->tableLayoutPanel4 = gcnew TableLayoutPanel();

				this->dataGridViewProducts = gcnew DataGridView();

				this->labelTitle = gcnew Label();

				this->labelValueDelivery = gcnew Label();
				this->labelValueBilling = gcnew Label();
				this->labelValueBirthDate = gcnew Label();
				this->labelValueFirstName = gcnew Label();
				this->labelValueLastName = gcnew Label();
				this->labelValueTFTotalPrice = gcnew Label();
				this->labelValueVAT = gcnew Label();
				this->labelValueTotalPrice = gcnew Label();

				this->labelDelivery = gcnew Label();
				this->labelBilling = gcnew Label();
				this->labelBirthDate = gcnew Label();
				this->labelFirstName = gcnew Label();
				this->labelLastName = gcnew Label();
				this->labelTFTotalPrice = gcnew Label();
				this->labelVAT = gcnew Label();
				this->labelTotalPrice = gcnew Label();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Location = Point(10, 11);
				this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 20.33333F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 79.66666F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 82));
				this->tableLayoutPanel1->Size = Drawing::Size(663, 439);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 4;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 130));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 150));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 105));
				this->tableLayoutPanel2->Controls->Add(this->labelValueVAT, 3, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelVAT, 2, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelTFTotalPrice, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelTotalPrice, 2, 1);
				this->tableLayoutPanel2->Controls->Add(this->labelValueTFTotalPrice, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelValueTotalPrice, 3, 1);
				this->tableLayoutPanel2->Location = Point(2, 358);
				this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 2;
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel2->Size = Drawing::Size(659, 78);

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 2;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 52.50379F));
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 47.49621F));
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
				this->tableLayoutPanel3->Controls->Add(this->dataGridViewProducts, 1, 0);
				this->tableLayoutPanel3->Location = Point(2, 74);
				this->tableLayoutPanel3->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 1;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Size = Drawing::Size(659, 280);

				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 2;
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 37.7193F));
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 62.2807F));
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
				this->tableLayoutPanel4->Location = Point(2, 2);
				this->tableLayoutPanel4->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 5;
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 45.71429F));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 54.28571F));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 55));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 56));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
				this->tableLayoutPanel4->Size = Drawing::Size(342, 276);

				/*-------------------- dataGridViewProducts --------------------*/
				this->dataGridViewProducts->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewProducts->Location = Point(348, 2);
				this->dataGridViewProducts->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->dataGridViewProducts->Name = L"dataGridViewProducts";
				this->dataGridViewProducts->RowHeadersWidth = 51;
				this->dataGridViewProducts->RowTemplate->Height = 24;
				this->dataGridViewProducts->Size = Drawing::Size(309, 276);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->labelTitle->Location = Point(137, 20);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(388, 31);
				this->labelTitle->Text = L"Details de la commande + REF";

				/*-------------------- labelValueDelivery --------------------*/
				this->labelValueDelivery->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueDelivery->AutoSize = true;
				this->labelValueDelivery->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueDelivery->Location = Point(131, 216);
				this->labelValueDelivery->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueDelivery->Name = L"labelValueDelivery";
				this->labelValueDelivery->Size = Drawing::Size(209, 60);
				this->labelValueDelivery->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueBilling --------------------*/
				this->labelValueBilling->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueBilling->AutoSize = true;
				this->labelValueBilling->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueBilling->Location = Point(131, 160);
				this->labelValueBilling->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueBilling->Name = L"labelValueBilling";
				this->labelValueBilling->Size = Drawing::Size(209, 56);
				this->labelValueBilling->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueBirthDate --------------------*/
				this->labelValueBirthDate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueBirthDate->AutoSize = true;
				this->labelValueBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueBirthDate->Location = Point(131, 105);
				this->labelValueBirthDate->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueBirthDate->Name = L"labelValueBirthDate";
				this->labelValueBirthDate->Size = Drawing::Size(209, 55);
				this->labelValueBirthDate->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueFirstName --------------------*/
				this->labelValueFirstName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueFirstName->AutoSize = true;
				this->labelValueFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueFirstName->Location = Point(131, 48);
				this->labelValueFirstName->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueFirstName->Name = L"labelValueFirstName";
				this->labelValueFirstName->Size = Drawing::Size(209, 57);
				this->labelValueFirstName->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueLastName --------------------*/
				this->labelValueLastName->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueLastName->AutoSize = true;
				this->labelValueLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueLastName->Location = Point(131, 0);
				this->labelValueLastName->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueLastName->Name = L"labelValueLastName";
				this->labelValueLastName->Size = Drawing::Size(209, 48);
				this->labelValueLastName->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueTFTotalPrice --------------------*/
				this->labelValueTFTotalPrice->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueTFTotalPrice->AutoSize = true;
				this->labelValueTFTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueTFTotalPrice->Location = Point(276, 0);
				this->labelValueTFTotalPrice->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueTFTotalPrice->Name = L"labelValueTFTotalPrice";
				this->labelValueTFTotalPrice->Size = Drawing::Size(126, 39);
				this->labelValueTFTotalPrice->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueVAT --------------------*/
				this->labelValueVAT->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueVAT->AutoSize = true;
				this->labelValueVAT->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueVAT->Location = Point(556, 0);
				this->labelValueVAT->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueVAT->Name = L"labelValueVAT";
				this->labelValueVAT->Size = Drawing::Size(101, 39);
				this->labelValueVAT->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelValueTotalPrice --------------------*/
				this->labelValueTotalPrice->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->labelValueTotalPrice->AutoSize = true;
				this->labelValueTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueTotalPrice->Location = Point(556, 39);
				this->labelValueTotalPrice->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelValueTotalPrice->Name = L"labelValueTotalPrice";
				this->labelValueTotalPrice->Size = Drawing::Size(101, 39);
				this->labelValueTotalPrice->TextAlign = ContentAlignment::MiddleLeft;

				/*-------------------- labelDelivery --------------------*/
				this->labelDelivery->Anchor = AnchorStyles::Left;
				this->labelDelivery->AutoSize = true;
				this->labelDelivery->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelDelivery->Location = Point(8, 233);
				this->labelDelivery->Margin = Windows::Forms::Padding(8, 0, 8, 0);
				this->labelDelivery->Name = L"labelDelivery";
				this->labelDelivery->Size = Drawing::Size(90, 25);
				this->labelDelivery->Text = L"Livraison";

				/*-------------------- labelBilling --------------------*/
				this->labelBilling->Anchor = AnchorStyles::Left;
				this->labelBilling->AutoSize = true;
				this->labelBilling->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBilling->Location = Point(8, 175);
				this->labelBilling->Margin = Windows::Forms::Padding(8, 0, 8, 0);
				this->labelBilling->Name = L"labelBilling";
				this->labelBilling->Size = Drawing::Size(109, 25);
				this->labelBilling->Text = L"Facturation";

				/*-------------------- labelBirthDate --------------------*/
				this->labelBirthDate->Anchor = AnchorStyles::Left;
				this->labelBirthDate->AutoSize = true;
				this->labelBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBirthDate->Location = Point(8, 120);
				this->labelBirthDate->Margin = Windows::Forms::Padding(8, 0, 8, 0);
				this->labelBirthDate->Name = L"labelBirthDate";
				this->labelBirthDate->Size = Drawing::Size(104, 25);
				this->labelBirthDate->Text = L"Naissance";

				/*-------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::Left;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelFirstName->Location = Point(8, 64);
				this->labelFirstName->Margin = Windows::Forms::Padding(8, 0, 8, 0);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->Text = L"Prenom";

				/*-------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::Left;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLastName->Location = Point(8, 11);
				this->labelLastName->Margin = Windows::Forms::Padding(8, 0, 8, 0);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->Text = L"Nom";

				/*-------------------- labelTFTotalPrice --------------------*/
				this->labelTFTotalPrice->Anchor = AnchorStyles::Right;
				this->labelTFTotalPrice->AutoSize = true;
				this->labelTFTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelTFTotalPrice->Location = Point(184, 7);
				this->labelTFTotalPrice->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTFTotalPrice->Name = L"labelTFTotalPrice";
				this->labelTFTotalPrice->Size = Drawing::Size(88, 25);
				this->labelTFTotalPrice->Text = L"Total HT";

				/*-------------------- labelVAT --------------------*/
				this->labelVAT->Anchor = AnchorStyles::Right;
				this->labelVAT->AutoSize = true;
				this->labelVAT->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelVAT->Location = Point(499, 7);
				this->labelVAT->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelVAT->Name = L"labelVAT";
				this->labelVAT->Size = Drawing::Size(53, 25);
				this->labelVAT->Text = L"TVA";

				/*-------------------- labelTotalPrice --------------------*/
				this->labelTotalPrice->Anchor = AnchorStyles::Right;
				this->labelTotalPrice->AutoSize = true;
				this->labelTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelTotalPrice->Location = Point(450, 46);
				this->labelTotalPrice->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTotalPrice->Name = L"labelTotalPrice";
				this->labelTotalPrice->Size = Drawing::Size(102, 25);
				this->labelTotalPrice->Text = L"Total TTC";

				/*-------------------- OrderDetails --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->Name = L"OrderDetails";
				this->Text = L"OrderDetails";
			}
	};
}
