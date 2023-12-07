#pragma once

using namespace System;
using namespace Collections;
using namespace Windows::Forms;
using namespace Data;
using namespace Drawing;

namespace Projet_POO
{
	public ref class StatsPage : public Form
	{
		public:
			StatsPage()
			{
				initialize();
				reloadLeastSoldGridView();
				reloadMostSoldGridView();
				reloadUnderThresholdGridView();
				reloadAverageCart();
				reloadStockValue();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;
			TableLayoutPanel^ tableLayoutPanel5;
			TableLayoutPanel^ tableLayoutPanel6;
			TableLayoutPanel^ tableLayoutPanel7;
			TableLayoutPanel^ tableLayoutPanel8;
			TableLayoutPanel^ tableLayoutPanel9;
			TableLayoutPanel^ tableLayoutPanel10;
			TableLayoutPanel^ tableLayoutPanel11;
		
			Label^ labelTitle;
			Label^ labelAverageCart;
			Label^ labelLastName;
			Label^ labelFirstName;
			Label^ labelBirthDate;
			Label^ labelCustomer;
			Label^ labelCustomerTotal;
			Label^ labelValueStock;
			Label^ labelMostSold;
			Label^ labelLeastSold;
			Label^ labelUnderThreshold;
			Label^ labelValue;
			Label^ labelVat;
			Label^ labelMargin;
			Label^ labelReduction;
			Label^ labelLosses;
			Label^ labelStock;
			Label^ labelCalculatedValue;
			Label^ labelTurnover;
			Label^ labelMonth;
			Label^ labelYear;
			Label^ labelValueTurnover;

			DataGridView^ dataGridViewMostSold;
			DataGridView^ dataGridViewLeastSold;
			DataGridView^ dataGridViewUnderThreshold;

			ComboBox^ comboBoxLastName;
			ComboBox^ comboBoxFirstName;
			ComboBox^ comboBoxBirthdate;
			ComboBox^ comboBoxVat;
			ComboBox^ comboBoxMargin;
			ComboBox^ comboBoxReduction;
			ComboBox^ comboBoxLosses;
			TextBox^ textBoxMonth;
			TextBox^ textBoxYear;

			Button^ buttonCustomer;
			Button^ buttonValue;
			Button^ buttonTurnover;


			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();
				this->tableLayoutPanel4 = gcnew TableLayoutPanel();
				this->tableLayoutPanel5 = gcnew TableLayoutPanel();
				this->tableLayoutPanel6 = gcnew TableLayoutPanel();
				this->tableLayoutPanel7 = gcnew TableLayoutPanel();
				this->tableLayoutPanel8 = gcnew TableLayoutPanel();
				this->tableLayoutPanel9 = gcnew TableLayoutPanel();
				this->tableLayoutPanel10 = gcnew TableLayoutPanel();
				this->tableLayoutPanel11 = gcnew TableLayoutPanel();
				
				this->labelTitle = gcnew Label();
				this->labelAverageCart = gcnew Label();
				this->labelLastName = gcnew Label();
				this->labelFirstName = gcnew Label();
				this->labelBirthDate = gcnew Label();
				this->labelCustomer = gcnew Label();
				this->labelCustomerTotal = gcnew Label();
				this->labelValueStock = gcnew Label();
				this->labelMostSold = gcnew Label();
				this->labelLeastSold = gcnew Label();
				this->labelUnderThreshold = gcnew Label();
				this->labelValue = gcnew Label();
				this->labelVat = gcnew Label();
				this->labelMargin = gcnew Label();
				this->labelReduction = gcnew Label();
				this->labelLosses = gcnew Label();
				this->labelStock = gcnew Label();
				this->labelCalculatedValue = gcnew Label();
				this->labelTurnover = gcnew Label();
				this->labelMonth = gcnew Label();
				this->labelYear = gcnew Label();
				this->labelValueTurnover = gcnew Label();

				this->dataGridViewMostSold = gcnew DataGridView();
				this->dataGridViewLeastSold = gcnew DataGridView();
				this->dataGridViewUnderThreshold = gcnew DataGridView();

				this->comboBoxLastName = gcnew ComboBox();
				this->comboBoxFirstName = gcnew ComboBox();
				this->comboBoxBirthdate = gcnew ComboBox();
				this->comboBoxVat = gcnew ComboBox();
				this->comboBoxMargin = gcnew ComboBox();
				this->comboBoxReduction = gcnew ComboBox();
				this->comboBoxLosses = gcnew ComboBox();
				this->textBoxMonth = gcnew TextBox();
				this->textBoxYear = gcnew TextBox();

				this->buttonCustomer = gcnew Button();
				this->buttonValue = gcnew Button();
				this->buttonTurnover = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Location = Point(13, 13);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 2;
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 8.176101F)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 91.8239F)));
				this->tableLayoutPanel1->Size = Drawing::Size(959, 636);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 59.18153F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 40.81847F));
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 0);
				this->tableLayoutPanel2->Location = Point(3, 55);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel2->Size = Drawing::Size(953, 578);

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel9, 0, 3);
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel10, 0, 1);
				this->tableLayoutPanel3->Controls->Add(this->labelValue, 0, 0);
				this->tableLayoutPanel3->Controls->Add(this->labelTurnover, 0, 2);
				this->tableLayoutPanel3->Location = Point(567, 3);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 4;
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 13.29305F)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 86.70695F)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 54)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 174)));
				this->tableLayoutPanel3->Size = Drawing::Size(383, 572);

				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 1;
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 5);
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel6, 0, 2);
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel7, 0, 3);
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel8, 0, 4);
				this->tableLayoutPanel4->Controls->Add(this->dataGridViewUnderThreshold, 0, 7);
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel11, 0, 0);
				this->tableLayoutPanel4->Controls->Add(this->labelUnderThreshold, 0, 6);
				this->tableLayoutPanel4->Location = Point(3, 3);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 8;
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 91.39785F));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 8.602151F));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 54));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 56));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 50));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 154));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 32));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 132));
				this->tableLayoutPanel4->Size = Drawing::Size(558, 572);

				/*-------------------- tableLayoutPanel5 --------------------*/
				this->tableLayoutPanel5->ColumnCount = 2;
				this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel5->Controls->Add(this->labelLeastSold, 1, 0);
				this->tableLayoutPanel5->Controls->Add(this->dataGridViewMostSold, 0, 1);
				this->tableLayoutPanel5->Controls->Add(this->dataGridViewLeastSold, 1, 1);
				this->tableLayoutPanel5->Controls->Add(this->labelMostSold, 0, 0);
				this->tableLayoutPanel5->Location = Point(3, 256);
				this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				this->tableLayoutPanel5->RowCount = 2;
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 29.37063F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 70.62937F)));
				this->tableLayoutPanel5->Size = Drawing::Size(552, 148);

				/*-------------------- tableLayoutPanel6 --------------------*/
				this->tableLayoutPanel6->ColumnCount = 3;
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 182));
				this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 163));
				this->tableLayoutPanel6->Controls->Add(this->labelBirthDate, 2, 0);
				this->tableLayoutPanel6->Controls->Add(this->labelFirstName, 1, 0);
				this->tableLayoutPanel6->Controls->Add(this->labelLastName, 0, 0);
				this->tableLayoutPanel6->Location = Point(3, 96);
				this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
				this->tableLayoutPanel6->RowCount = 1;
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel6->Size = Drawing::Size(552, 48);

				/*-------------------- tableLayoutPanel7 --------------------*/
				this->tableLayoutPanel7->ColumnCount = 3;
				this->tableLayoutPanel7->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 52.9563F));
				this->tableLayoutPanel7->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 47.0437F));
				this->tableLayoutPanel7->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 163));
				this->tableLayoutPanel7->Controls->Add(this->comboBoxBirthdate, 2, 0);
				this->tableLayoutPanel7->Controls->Add(this->comboBoxLastName, 0, 0);
				this->tableLayoutPanel7->Controls->Add(this->comboBoxFirstName, 1, 0);
				this->tableLayoutPanel7->Location = Point(3, 150);
				this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
				this->tableLayoutPanel7->RowCount = 1;
				this->tableLayoutPanel7->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel7->Size = Drawing::Size(552, 50);

				/*-------------------- tableLayoutPanel8 --------------------*/
				this->tableLayoutPanel8->ColumnCount = 2;
				this->tableLayoutPanel8->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 37.31884F));
				this->tableLayoutPanel8->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 62.68116F));
				this->tableLayoutPanel8->Controls->Add(this->buttonCustomer, 0, 0);
				this->tableLayoutPanel8->Controls->Add(this->labelCustomerTotal, 1, 0);
				this->tableLayoutPanel8->Location = Point(3, 206);
				this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
				this->tableLayoutPanel8->RowCount = 1;
				this->tableLayoutPanel8->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel8->Size = Drawing::Size(552, 44);

				/*-------------------- tableLayoutPanel9 --------------------*/
				this->tableLayoutPanel9->ColumnCount = 2;
				this->tableLayoutPanel9->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 43.50133F));
				this->tableLayoutPanel9->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 56.49867F));
				this->tableLayoutPanel9->Controls->Add(this->buttonTurnover, 0, 2);
				this->tableLayoutPanel9->Controls->Add(this->textBoxYear, 1, 1);
				this->tableLayoutPanel9->Controls->Add(this->textBoxMonth, 1, 0);
				this->tableLayoutPanel9->Controls->Add(this->labelValueTurnover, 1, 2);
				this->tableLayoutPanel9->Controls->Add(this->labelMonth, 0, 0);
				this->tableLayoutPanel9->Controls->Add(this->labelYear, 0, 1);
				this->tableLayoutPanel9->Location = Point(3, 400);
				this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
				this->tableLayoutPanel9->RowCount = 3;
				this->tableLayoutPanel9->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 43.39622F)));
				this->tableLayoutPanel9->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 56.60378F)));
				this->tableLayoutPanel9->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 56)));
				this->tableLayoutPanel9->Size = Drawing::Size(377, 169);

				/*-------------------- tableLayoutPanel10 --------------------*/
				this->tableLayoutPanel10->ColumnCount = 2;
				this->tableLayoutPanel10->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 44.03183F));
				this->tableLayoutPanel10->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 55.96817F));
				this->tableLayoutPanel10->Controls->Add(this->comboBoxLosses, 1, 3);
				this->tableLayoutPanel10->Controls->Add(this->comboBoxReduction, 1, 2);
				this->tableLayoutPanel10->Controls->Add(this->comboBoxMargin, 1, 1);
				this->tableLayoutPanel10->Controls->Add(this->labelValueStock, 1, 4);
				this->tableLayoutPanel10->Controls->Add(this->labelVat, 0, 0);
				this->tableLayoutPanel10->Controls->Add(this->labelReduction, 0, 2);
				this->tableLayoutPanel10->Controls->Add(this->labelMargin, 0, 1);
				this->tableLayoutPanel10->Controls->Add(this->labelLosses, 0, 3);
				this->tableLayoutPanel10->Controls->Add(this->labelStock, 0, 4);
				this->tableLayoutPanel10->Controls->Add(this->labelCalculatedValue, 1, 5);
				this->tableLayoutPanel10->Controls->Add(this->comboBoxVat, 1, 0);
				this->tableLayoutPanel10->Controls->Add(this->buttonValue, 0, 5);
				this->tableLayoutPanel10->Location = Point(3, 48);
				this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
				this->tableLayoutPanel10->RowCount = 6;
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 48.97959F));
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 51.02041F));
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 50));
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 52));
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 44));
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 47));
				this->tableLayoutPanel10->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
				this->tableLayoutPanel10->Size = Drawing::Size(377, 292);

				/*-------------------- tableLayoutPanel11 --------------------*/
				this->tableLayoutPanel11->ColumnCount = 1;
				this->tableLayoutPanel11->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel11->Controls->Add(this->labelCustomer, 0, 1);
				this->tableLayoutPanel11->Controls->Add(this->labelAverageCart, 0, 0);
				this->tableLayoutPanel11->Location = Point(3, 3);
				this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
				this->tableLayoutPanel11->RowCount = 2;
				this->tableLayoutPanel11->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 51.89874F)));
				this->tableLayoutPanel11->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 48.10126F)));
				this->tableLayoutPanel11->Size = Drawing::Size(549, 79);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 30);
				this->labelTitle->Location = Point(366, 3);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(226, 46);
				this->labelTitle->Text = L"Statistiques";

				/*-------------------- labelAverageCart --------------------*/
				this->labelAverageCart->Anchor = AnchorStyles::Left;
				this->labelAverageCart->AutoSize = true;
				this->labelAverageCart->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelAverageCart->Location = Point(10, 8);
				this->labelAverageCart->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelAverageCart->Name = L"labelAverageCart";
				this->labelAverageCart->Size = Drawing::Size(204, 25);
				this->labelAverageCart->Text = L"Panier moyen : xxxx $";

				/*-------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::None;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelFirstName->Location = Point(258, 11);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->Text = L"Prenom";

				/*-------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::None;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLastName->Location = Point(77, 11);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->Text = L"Nom";

				/*-------------------- labelBirthDate --------------------*/
				this->labelBirthDate->Anchor = AnchorStyles::None;
				this->labelBirthDate->AutoSize = true;
				this->labelBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBirthDate->Location = Point(418, 11);
				this->labelBirthDate->Name = L"labelBirthDate";
				this->labelBirthDate->Size = Drawing::Size(104, 25);
				this->labelBirthDate->Text = L"Naissance";

				/*-------------------- labelCustomer --------------------*/
				this->labelCustomer->Anchor = AnchorStyles::Left;
				this->labelCustomer->AutoSize = true;
				this->labelCustomer->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelCustomer->Location = Point(10, 47);
				this->labelCustomer->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelCustomer->Name = L"labelCustomer";
				this->labelCustomer->Size = Drawing::Size(365, 25);
				this->labelCustomer->Text = L"Montant total des commandes d\'un client";
				
				/*-------------------- labelCustomerTotal --------------------*/
				this->labelCustomerTotal->Anchor = AnchorStyles::Left;
				this->labelCustomerTotal->AutoSize = true;
				this->labelCustomerTotal->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelCustomerTotal->Location = Point(216, 9);
				this->labelCustomerTotal->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelCustomerTotal->Name = L"labelCustomerTotal";
				this->labelCustomerTotal->Size = Drawing::Size(68, 25);
				this->labelCustomerTotal->Text = L"xxxx $";

				/*-------------------- labelValueStock --------------------*/
				this->labelValueStock->Anchor = AnchorStyles::Left;
				this->labelValueStock->AutoSize = true;
				this->labelValueStock->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueStock->Location = Point(176, 209);
				this->labelValueStock->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelValueStock->Name = L"labelValueStock";
				this->labelValueStock->Size = Drawing::Size(108, 25);
				this->labelValueStock->Text = L"xxxxxxxx $";

				/*-------------------- labelMostSold --------------------*/
				this->labelMostSold->Anchor = AnchorStyles::None;
				this->labelMostSold->AutoSize = true;
				this->labelMostSold->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelMostSold->Location = Point(26, 9);
				this->labelMostSold->Name = L"labelMostSold";
				this->labelMostSold->Size = Drawing::Size(223, 25);
				this->labelMostSold->Text = L"Produits les plus vendus";
				
				/*-------------------- labelLeastSold --------------------*/
				this->labelLeastSold->Anchor = AnchorStyles::None;
				this->labelLeastSold->AutoSize = true;
				this->labelLeastSold->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLeastSold->Location = Point(294, 9);
				this->labelLeastSold->Name = L"labelLeastSold";
				this->labelLeastSold->Size = Drawing::Size(239, 25);
				this->labelLeastSold->Text = L"Produits les moins vendus";
				
				/*-------------------- labelUnderThreshold --------------------*/
				this->labelUnderThreshold->Anchor = AnchorStyles::None;
				this->labelUnderThreshold->AutoSize = true;
				this->labelUnderThreshold->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelUnderThreshold->Location = Point(74, 410);
				this->labelUnderThreshold->Name = L"labelUnderThreshold";
				this->labelUnderThreshold->Size = Drawing::Size(409, 25);
				this->labelUnderThreshold->Text = L"Produits sous le seuil de reapprovisionnement";
				
				/*-------------------- labelValue --------------------*/
				this->labelValue->Anchor = AnchorStyles::Left;
				this->labelValue->AutoSize = true;
				this->labelValue->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValue->Location = Point(10, 10);
				this->labelValue->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelValue->Name = L"labelValue";
				this->labelValue->Size = Drawing::Size(287, 25);
				this->labelValue->Text = L"Calcul de la valeur commerciale";
				
				/*-------------------- labelVat --------------------*/
				this->labelVat->Anchor = AnchorStyles::Left;
				this->labelVat->AutoSize = true;
				this->labelVat->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelVat->Location = Point(10, 11);
				this->labelVat->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelVat->Name = L"labelVat";
				this->labelVat->Size = Drawing::Size(90, 25);
				this->labelVat->Text = L"TVA (%)";
				
				/*-------------------- labelMargin --------------------*/
				this->labelMargin->Anchor = AnchorStyles::Left;
				this->labelMargin->AutoSize = true;
				this->labelMargin->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelMargin->Location = Point(10, 60);
				this->labelMargin->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelMargin->Name = L"labelMargin";
				this->labelMargin->Size = Drawing::Size(105, 25);
				this->labelMargin->Text = L"Marge (%)";
				
				/*-------------------- labelReduction --------------------*/
				this->labelReduction->Anchor = AnchorStyles::Left;
				this->labelReduction->AutoSize = true;
				this->labelReduction->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelReduction->Location = Point(10, 110);
				this->labelReduction->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelReduction->Name = L"labelReduction";
				this->labelReduction->Size = Drawing::Size(124, 25);
				this->labelReduction->Text = L"Remises (%)";

				/*-------------------- labelLosses --------------------*/
				this->labelLosses->Anchor = AnchorStyles::Left;
				this->labelLosses->AutoSize = true;
				this->labelLosses->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLosses->Location = Point(10, 161);
				this->labelLosses->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelLosses->Name = L"labelLosses";
				this->labelLosses->Size = Drawing::Size(140, 25);
				this->labelLosses->Text = L"Demarque (%)";

				/*-------------------- labelStock --------------------*/
				this->labelStock->Anchor = AnchorStyles::Left;
				this->labelStock->AutoSize = true;
				this->labelStock->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelStock->Location = Point(10, 209);
				this->labelStock->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelStock->Name = L"labelStock";
				this->labelStock->Size = Drawing::Size(147, 25);
				this->labelStock->Text = L"Valeur du stock";

				/*-------------------- labelCalculatedValue --------------------*/
				this->labelCalculatedValue->Anchor = AnchorStyles::Left;
				this->labelCalculatedValue->AutoSize = true;
				this->labelCalculatedValue->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelCalculatedValue->Location = Point(176, 255);
				this->labelCalculatedValue->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelCalculatedValue->Name = L"labelCalculatedValue";
				this->labelCalculatedValue->Size = Drawing::Size(98, 25);
				this->labelCalculatedValue->Text = L"xxxxxxx $";

				/*-------------------- labelTurnover --------------------*/
				this->labelTurnover->Anchor = AnchorStyles::Left;
				this->labelTurnover->AutoSize = true;
				this->labelTurnover->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelTurnover->Location = Point(10, 357);
				this->labelTurnover->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelTurnover->Name = L"labelTurnover";
				this->labelTurnover->Size = Drawing::Size(319, 25);
				this->labelTurnover->Text = L"Chiffre d\'affaire pour un mois donne";
				
				/*-------------------- labelMonth --------------------*/
				this->labelMonth->Anchor = AnchorStyles::Left;
				this->labelMonth->AutoSize = true;
				this->labelMonth->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelMonth->Location = Point(10, 12);
				this->labelMonth->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelMonth->Name = L"labelMonth";
				this->labelMonth->Size = Drawing::Size(54, 25);
				this->labelMonth->Text = L"Mois";

				/*-------------------- labelYear --------------------*/
				this->labelYear->Anchor = AnchorStyles::Left;
				this->labelYear->AutoSize = true;
				this->labelYear->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelYear->Location = Point(10, 68);
				this->labelYear->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelYear->Name = L"labelYear";
				this->labelYear->Size = Drawing::Size(70, 25);
				this->labelYear->Text = L"Annee";

				/*-------------------- labelValueTurnover --------------------*/
				this->labelValueTurnover->Anchor = AnchorStyles::Left;
				this->labelValueTurnover->AutoSize = true;
				this->labelValueTurnover->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelValueTurnover->Location = Point(174, 128);
				this->labelValueTurnover->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelValueTurnover->Name = L"labelValueTurnover";
				this->labelValueTurnover->Size = Drawing::Size(98, 25);
				this->labelValueTurnover->Text = L"xxxxxxx $";
				
				/*-------------------- dataGridViewMostSold --------------------*/
				this->dataGridViewMostSold->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewMostSold->Location = Point(3, 46);
				this->dataGridViewMostSold->Name = L"dataGridViewMostSold";
				this->dataGridViewMostSold->Size = Drawing::Size(270, 98);
				this->dataGridViewMostSold->TabIndex = 4;
				this->dataGridViewMostSold->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewMostSold->ReadOnly = true;
				this->dataGridViewMostSold->AllowUserToResizeRows = false;
				this->dataGridViewMostSold->AllowUserToAddRows = false;
				this->dataGridViewMostSold->RowHeadersVisible = false;
				this->dataGridViewMostSold->AllowUserToDeleteRows = false;
				this->dataGridViewMostSold->MultiSelect = false;
				this->dataGridViewMostSold->ColumnHeadersDefaultCellStyle->WrapMode = DataGridViewTriState::False;
				this->dataGridViewMostSold->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewMostSold->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->dataGridViewMostSold->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
				this->dataGridViewMostSold->ColumnHeadersHeight = 40;

				auto referenceMost = gcnew DataGridViewTextBoxColumn();
				referenceMost->Visible = false;
				this->dataGridViewMostSold->Columns->Add(referenceMost);

				auto typeMost = gcnew DataGridViewTextBoxColumn();
				typeMost->Name = "Nature";
				this->dataGridViewMostSold->Columns->Add(typeMost);

				auto nameMost = gcnew DataGridViewTextBoxColumn();
				nameMost->Name = "Nom";
				this->dataGridViewMostSold->Columns->Add(nameMost);

				auto colourMost = gcnew DataGridViewTextBoxColumn();
				colourMost->Name = "Couleur";
				this->dataGridViewMostSold->Columns->Add(colourMost);

				auto buyPriceMost = gcnew DataGridViewTextBoxColumn();
				buyPriceMost->Name = "Prix d'achat";
				this->dataGridViewMostSold->Columns->Add(buyPriceMost);

				auto vatRateMost = gcnew DataGridViewTextBoxColumn();
				vatRateMost->Visible = false;
				this->dataGridViewMostSold->Columns->Add(vatRateMost);

				auto quantityMost = gcnew DataGridViewTextBoxColumn();
				quantityMost->Name = "Quantite";
				this->dataGridViewMostSold->Columns->Add(quantityMost);

				auto provisionningThresholdMost = gcnew DataGridViewTextBoxColumn();
				provisionningThresholdMost->Visible = false;
				this->dataGridViewMostSold->Columns->Add(provisionningThresholdMost);

				auto quantitySoldMost = gcnew DataGridViewTextBoxColumn();
				quantitySoldMost->Name = "Quantite vendue";
				this->dataGridViewMostSold->Columns->Add(quantitySoldMost);

				/*-------------------- dataGridViewLeastSold --------------------*/
				this->dataGridViewLeastSold->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewLeastSold->Location = Point(279, 46);
				this->dataGridViewLeastSold->Name = L"dataGridViewLeastSold";
				this->dataGridViewLeastSold->Size = Drawing::Size(270, 98);
				this->dataGridViewLeastSold->TabIndex = 5;
				this->dataGridViewLeastSold->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewLeastSold->ReadOnly = true;
				this->dataGridViewLeastSold->AllowUserToResizeRows = false;
				this->dataGridViewLeastSold->AllowUserToAddRows = false;
				this->dataGridViewLeastSold->RowHeadersVisible = false;
				this->dataGridViewLeastSold->AllowUserToDeleteRows = false;
				this->dataGridViewLeastSold->MultiSelect = false;
				this->dataGridViewLeastSold->ColumnHeadersDefaultCellStyle->WrapMode = DataGridViewTriState::False;
				this->dataGridViewLeastSold->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewLeastSold->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->dataGridViewLeastSold->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
				this->dataGridViewLeastSold->ColumnHeadersHeight = 40;

				auto referenceLeast = gcnew DataGridViewTextBoxColumn();
				referenceLeast->Visible = false;
				this->dataGridViewLeastSold->Columns->Add(referenceLeast);

				auto typeLeast = gcnew DataGridViewTextBoxColumn();
				typeLeast->Name = "Nature";
				this->dataGridViewLeastSold->Columns->Add(typeLeast);

				auto nameLeast = gcnew DataGridViewTextBoxColumn();
				nameLeast->Name = "Nom";
				this->dataGridViewLeastSold->Columns->Add(nameLeast);

				auto colourLeast = gcnew DataGridViewTextBoxColumn();
				colourLeast->Name = "Couleur";
				this->dataGridViewLeastSold->Columns->Add(colourLeast);

				auto buyPriceLeast = gcnew DataGridViewTextBoxColumn();
				buyPriceLeast->Name = "Prix d'achat";
				this->dataGridViewLeastSold->Columns->Add(buyPriceLeast);

				auto vatRateLeast = gcnew DataGridViewTextBoxColumn();
				vatRateLeast->Visible = false;
				this->dataGridViewLeastSold->Columns->Add(vatRateLeast);

				auto quantityLeast = gcnew DataGridViewTextBoxColumn();
				quantityLeast->Name = "Quantite";
				this->dataGridViewLeastSold->Columns->Add(quantityLeast);

				auto provisionningThresholdLeast = gcnew DataGridViewTextBoxColumn();
				provisionningThresholdLeast->Visible = false;
				this->dataGridViewLeastSold->Columns->Add(provisionningThresholdLeast);

				auto quantitySoldLeast = gcnew DataGridViewTextBoxColumn();
				quantitySoldLeast->Name = "Quantite vendue";
				this->dataGridViewLeastSold->Columns->Add(quantitySoldLeast);

				/*-------------------- dataGridViewUnderThreshold --------------------*/
				this->dataGridViewUnderThreshold->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewUnderThreshold->Location = Point(3, 442);
				this->dataGridViewUnderThreshold->Name = L"dataGridViewUnderThreshold";
				this->dataGridViewUnderThreshold->Size = Drawing::Size(552, 127);
				this->dataGridViewUnderThreshold->TabIndex = 6;
				this->dataGridViewUnderThreshold->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewUnderThreshold->ReadOnly = true;
				this->dataGridViewUnderThreshold->AllowUserToResizeRows = false;
				this->dataGridViewUnderThreshold->AllowUserToAddRows = false;
				this->dataGridViewUnderThreshold->RowHeadersVisible = false;
				this->dataGridViewUnderThreshold->AllowUserToDeleteRows = false;
				this->dataGridViewUnderThreshold->MultiSelect = false;
				this->dataGridViewUnderThreshold->ColumnHeadersDefaultCellStyle->WrapMode = DataGridViewTriState::False;
				this->dataGridViewUnderThreshold->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->dataGridViewUnderThreshold->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewUnderThreshold->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
				this->dataGridViewUnderThreshold->ColumnHeadersHeight = 40;

				auto productId = gcnew DataGridViewTextBoxColumn();
				productId->Visible = false;
				this->dataGridViewUnderThreshold->Columns->Add(productId);

				auto reference = gcnew DataGridViewTextBoxColumn();
				reference->Visible = false;
				this->dataGridViewUnderThreshold->Columns->Add(reference);

				auto type = gcnew DataGridViewTextBoxColumn();
				type->Name = "Nature";
				this->dataGridViewUnderThreshold->Columns->Add(type);

				auto name = gcnew DataGridViewTextBoxColumn();
				name->Name = "Nom";
				this->dataGridViewUnderThreshold->Columns->Add(name);

				auto colour = gcnew DataGridViewTextBoxColumn();
				colour->Name = "Couleur";
				this->dataGridViewUnderThreshold->Columns->Add(colour);

				auto buyPrice = gcnew DataGridViewTextBoxColumn();
				buyPrice->Name = "Prix d'achat";
				this->dataGridViewUnderThreshold->Columns->Add(buyPrice);

				auto vatRate = gcnew DataGridViewTextBoxColumn();
				vatRate->Visible = false;
				this->dataGridViewUnderThreshold->Columns->Add(vatRate);

				auto quantity = gcnew DataGridViewTextBoxColumn();
				quantity->Name = "Quantite";
				this->dataGridViewUnderThreshold->Columns->Add(quantity);

				auto provisionningThreshold = gcnew DataGridViewTextBoxColumn();
				provisionningThreshold->Name = "Limite de restock";
				this->dataGridViewUnderThreshold->Columns->Add(provisionningThreshold);
				
				/*-------------------- comboBoxLastName --------------------*/
				this->comboBoxLastName->Anchor = AnchorStyles::None;
				this->comboBoxLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxLastName->FormattingEnabled = true;
				this->comboBoxLastName->Location = Point(17, 3);
				this->comboBoxLastName->Margin = Windows::Forms::Padding(3, 3, 3, 3);
				this->comboBoxLastName->Name = L"comboBoxLastName";
				this->comboBoxLastName->Size = Drawing::Size(172, 33);
				this->comboBoxLastName->TabIndex = 0;
				this->comboBoxLastName->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::comboBox_keyPress);

				/*-------------------- comboBoxFirstName --------------------*/
				this->comboBoxFirstName->Anchor = AnchorStyles::None;
				this->comboBoxFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxFirstName->FormattingEnabled = true;
				this->comboBoxFirstName->Location = Point(214, 8);
				this->comboBoxFirstName->Name = L"comboBoxFirstName";
				this->comboBoxFirstName->Size = Drawing::Size(167, 33);
				this->comboBoxFirstName->TabIndex = 1;
				this->comboBoxFirstName->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::comboBox_keyPress);

				/*-------------------- comboBoxBirthdate --------------------*/
				this->comboBoxBirthdate->Anchor = AnchorStyles::None;
				this->comboBoxBirthdate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxBirthdate->FormattingEnabled = true;
				this->comboBoxBirthdate->Location = Point(401, 8);
				this->comboBoxBirthdate->Name = L"comboBoxBirthdate";
				this->comboBoxBirthdate->Size = Drawing::Size(139, 33);
				this->comboBoxBirthdate->TabIndex = 2;
				this->comboBoxBirthdate->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::comboBox_keyPress);
				this->comboBoxBirthdate->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxDate_KeyPress);

				/*-------------------- comboBoxVat --------------------*/
				this->comboBoxVat->Anchor = AnchorStyles::Left;
				this->comboBoxVat->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxVat->Location = Point(176, 9);
				this->comboBoxVat->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxVat->Name = L"comboBoxVat";
				this->comboBoxVat->Size = Drawing::Size(191, 30);
				this->comboBoxVat->TabIndex = 7;
				this->comboBoxVat->Items->Add("5");
				this->comboBoxVat->Items->Add("10");
				this->comboBoxVat->Items->Add("20");
				this->comboBoxVat->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxFloat_KeyPress);

				/*-------------------- comboBoxMargin --------------------*/
				this->comboBoxMargin->Anchor = AnchorStyles::Left;
				this->comboBoxMargin->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxMargin->Location = Point(176, 58);
				this->comboBoxMargin->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxMargin->Name = L"comboBoxMargin";
				this->comboBoxMargin->Size = Drawing::Size(191, 30);
				this->comboBoxMargin->TabIndex = 8;
				this->comboBoxMargin->Items->Add("5");
				this->comboBoxMargin->Items->Add("10");
				this->comboBoxMargin->Items->Add("15");
				this->comboBoxMargin->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxFloat_KeyPress);
				
				/*-------------------- comboBoxReduction --------------------*/
				this->comboBoxReduction->Anchor = AnchorStyles::Left;
				this->comboBoxReduction->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxReduction->Location = Point(176, 108);
				this->comboBoxReduction->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxReduction->Name = L"comboBoxReduction";
				this->comboBoxReduction->Size = Drawing::Size(191, 30);
				this->comboBoxReduction->TabIndex = 9;
				this->comboBoxMargin->TabIndex = 8;
				this->comboBoxReduction->Items->Add("5");
				this->comboBoxReduction->Items->Add("6");
				this->comboBoxReduction->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxFloat_KeyPress);

				/*-------------------- comboBoxLosses --------------------*/
				this->comboBoxLosses->Anchor = AnchorStyles::Left;
				this->comboBoxLosses->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->comboBoxLosses->Location = Point(176, 159);
				this->comboBoxLosses->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxLosses->Name = L"comboBoxLosses";
				this->comboBoxLosses->Size = Drawing::Size(191, 30);
				this->comboBoxLosses->TabIndex = 10;
				this->comboBoxLosses->Items->Add("2");
				this->comboBoxLosses->Items->Add("3");
				this->comboBoxLosses->Items->Add("5");
				this->comboBoxLosses->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxFloat_KeyPress);
				
				/*-------------------- textBoxMonth --------------------*/
				this->textBoxMonth->Anchor = AnchorStyles::Left;
				this->textBoxMonth->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxMonth->Location = Point(174, 9);
				this->textBoxMonth->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxMonth->Name = L"textBoxMonth";
				this->textBoxMonth->Size = Drawing::Size(191, 30);
				this->textBoxMonth->TabIndex = 12;
				this->textBoxMonth->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxInt_KeyPress);
				
				/*-------------------- textBoxYear --------------------*/
				this->textBoxYear->Anchor = AnchorStyles::Left;
				this->textBoxYear->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->textBoxYear->Location = Point(174, 65);
				this->textBoxYear->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxYear->Name = L"textBoxYear";
				this->textBoxYear->Size = Drawing::Size(191, 30);
				this->textBoxYear->TabIndex = 13;
				this->textBoxYear->KeyPress += gcnew KeyPressEventHandler(this, &StatsPage::boxInt_KeyPress);
				
				/*-------------------- buttonCustomer --------------------*/
				this->buttonCustomer->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCustomer->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonCustomer->Location = Point(7, 7);
				this->buttonCustomer->Margin = Windows::Forms::Padding(7);
				this->buttonCustomer->Name = L"button1";
				this->buttonCustomer->Size = Drawing::Size(192, 32);
				this->buttonCustomer->TabIndex = 3;
				this->buttonCustomer->Text = L"Calcul du total";
				this->buttonCustomer->UseVisualStyleBackColor = true;
				this->buttonCustomer->Click += gcnew EventHandler(this, &StatsPage::buttonCustomer_Click);

				/*-------------------- buttonValue --------------------*/
				this->buttonValue->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonValue->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonValue->Location = Point(7, 251);
				this->buttonValue->Margin = Windows::Forms::Padding(7);
				this->buttonValue->Name = L"buttonValue";
				this->buttonValue->Size = Drawing::Size(152, 34);
				this->buttonValue->TabIndex = 11;
				this->buttonValue->Text = L"Calcul valeur";
				this->buttonValue->UseVisualStyleBackColor = true;
				this->buttonValue->Click += gcnew EventHandler(this, &StatsPage::buttonValue_Click);

				/*-------------------- buttonTurnover --------------------*/
				this->buttonTurnover->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonTurnover->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonTurnover->Location = Point(7, 119);
				this->buttonTurnover->Margin = Windows::Forms::Padding(7);
				this->buttonTurnover->Name = L"buttonTurnover";
				this->buttonTurnover->Size = Drawing::Size(150, 43);
				this->buttonTurnover->TabIndex = 14;
				this->buttonTurnover->Text = L"Calcul CA";
				this->buttonTurnover->UseVisualStyleBackColor = true;
				this->buttonTurnover->Click += gcnew EventHandler(this, &StatsPage::buttonTurnover_Click);

				/*-------------------- StatsPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(984, 661);
				this->Controls->Add(this->tableLayoutPanel1);
				this->MaximizeBox = false;
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->Name = L"StatsPage";
				this->Text = L"StatsPage";
			}

			Void reloadMostSoldGridView();
			Void reloadLeastSoldGridView();
			Void reloadUnderThresholdGridView();
			Void retrieveSuggestion(ComboBox^ comboBox, String^ query);
			Void comboBox_keyPress(Object^ sender, KeyPressEventArgs^ e);
			Void boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e);
			Void boxFloat_KeyPress(Object^ sender, KeyPressEventArgs^ e);
			Void boxDate_KeyPress(Object^ sender, KeyPressEventArgs^ e);
			Void buttonTurnover_Click(Object^ sender, EventArgs^ e);
			Void buttonCustomer_Click(Object^ sender, EventArgs^ e);
			Void buttonValue_Click(Object^ sender, EventArgs^ e);
			Void reloadAverageCart();
			Void reloadStockValue();

	};
}
