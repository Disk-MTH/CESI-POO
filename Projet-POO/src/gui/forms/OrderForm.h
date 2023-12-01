#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class OrderForm : public Form
	{
		public:
			OrderForm()
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
			TableLayoutPanel^ tableLayoutPanel7;
		
			DataGridView^ dataGridViewProductList;

			Label^ labelTitle;
			
			Label^ labelBirthDate;
			Label^ labelFirstName;
			Label^ labelLastName;
			Label^ labelBillingAddress;
			Label^ labelDeliveryAddress;
			Label^ labelProductName;
			Label^ labelType;
			Label^ labelColour;
			Label^ labelQuantity;

			TextBox^ textBoxBirthDate;
			TextBox^ textBoxQuantity;
		
			ComboBox^ comboBoxDeliveryAddress;
			ComboBox^ comboBoxBillingAddress;
			ComboBox^ comboBoxLastName;
			ComboBox^ comboBoxFirstName;
			ComboBox^ comboBoxProductName;
			ComboBox^ comboBoxType;
			ComboBox^ comboBoxColour;

			Button^ buttonDelete;
			Button^ buttonCancel;
			Button^ buttonAdd;
			Button^ buttonValidate;

			void initialize()
			{
				this->tableLayoutPanel1 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel2 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel3 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel4 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel5 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel6 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel7 = (gcnew TableLayoutPanel());

				this->dataGridViewProductList = (gcnew DataGridView());

				this->labelTitle = (gcnew Label());

				this->labelBirthDate = (gcnew Label());
				this->labelLastName = (gcnew Label());
				this->labelFirstName = (gcnew Label());
				this->labelBillingAddress = (gcnew Label());
				this->labelDeliveryAddress = (gcnew Label());
				this->labelProductName = (gcnew Label());
				this->labelColour = (gcnew Label());
				this->labelType = (gcnew Label());
				this->labelQuantity = (gcnew Label());

				this->textBoxQuantity = (gcnew TextBox());
				this->textBoxBirthDate = (gcnew TextBox());
				
				this->comboBoxLastName = (gcnew ComboBox());
				this->comboBoxFirstName = (gcnew ComboBox());
				this->comboBoxBillingAddress = (gcnew ComboBox());
				this->comboBoxDeliveryAddress = (gcnew ComboBox());
				this->comboBoxProductName = (gcnew ComboBox());
				this->comboBoxType = (gcnew ComboBox());
				this->comboBoxColour = (gcnew ComboBox());

				this->buttonDelete = (gcnew Button());
				this->buttonCancel = (gcnew Button());
				this->buttonAdd = (gcnew Button());
				this->buttonValidate = (gcnew Button());
				
				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Location = Point(13, 13);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 11.98044F)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 88.01956F)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 97)));
				this->tableLayoutPanel1->Size = Drawing::Size(659, 916);
				this->tableLayoutPanel1->TabIndex = 0;
				
				/*-------------------- tableLayoutPanel2 --------------------*/ 
				this->tableLayoutPanel2->ColumnCount = 3;
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute,
					233)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute,
					211)));
				this->tableLayoutPanel2->Controls->Add(this->buttonCancel, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonValidate, 2, 0);
				this->tableLayoutPanel2->Location = Point(3, 821);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel2->Size = Drawing::Size(653, 92);
				this->tableLayoutPanel2->TabIndex = 0;
				
				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 2;
				this->tableLayoutPanel3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					41.19449F)));
				this->tableLayoutPanel3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					58.80551F)));
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 1, 0);
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 0);
				this->tableLayoutPanel3->Location = Point(3, 101);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 1;
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel3->Size = Drawing::Size(653, 714);
				this->tableLayoutPanel3->TabIndex = 1;
				
				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 1;
				this->tableLayoutPanel4->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 1);
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel7, 0, 2);
				this->tableLayoutPanel4->Controls->Add(this->dataGridViewProductList, 0, 0);
				this->tableLayoutPanel4->Location = Point(272, 3);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 3;
				this->tableLayoutPanel4->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel4->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel4->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 55)));
				this->tableLayoutPanel4->Size = Drawing::Size(378, 708);
				this->tableLayoutPanel4->TabIndex = 0;
				
				/*-------------------- tableLayoutPanel5 --------------------*/
				this->tableLayoutPanel5->ColumnCount = 1;
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel5->Controls->Add(this->comboBoxColour, 0, 5);
				this->tableLayoutPanel5->Controls->Add(this->comboBoxType, 0, 3);
				this->tableLayoutPanel5->Controls->Add(this->labelType, 0, 2);
				this->tableLayoutPanel5->Controls->Add(this->labelProductName, 0, 0);
				this->tableLayoutPanel5->Controls->Add(this->labelColour, 0, 4);
				this->tableLayoutPanel5->Controls->Add(this->labelQuantity, 0, 6);
				this->tableLayoutPanel5->Controls->Add(this->comboBoxProductName, 0, 1);
				this->tableLayoutPanel5->Controls->Add(this->textBoxQuantity, 0, 7);
				this->tableLayoutPanel5->Location = Point(3, 329);
				this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				this->tableLayoutPanel5->RowCount = 8;
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 46.66667F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 53.33333F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 43)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 37)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 43)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 41)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 40)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 36)));
				this->tableLayoutPanel5->Size = Drawing::Size(372, 320);
				this->tableLayoutPanel5->TabIndex = 0;
				
				/*-------------------- tableLayoutPanel6 --------------------*/
				this->tableLayoutPanel6->ColumnCount = 1;
				this->tableLayoutPanel6->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel6->Controls->Add(this->comboBoxDeliveryAddress, 0, 7);
				this->tableLayoutPanel6->Controls->Add(this->comboBoxFirstName, 0, 3);
				this->tableLayoutPanel6->Controls->Add(this->labelBirthDate, 0, 4);
				this->tableLayoutPanel6->Controls->Add(this->labelFirstName, 0, 2);
				this->tableLayoutPanel6->Controls->Add(this->labelLastName, 0, 0);
				this->tableLayoutPanel6->Controls->Add(this->labelBillingAddress, 0, 8);
				this->tableLayoutPanel6->Controls->Add(this->labelDeliveryAddress, 0, 6);
				this->tableLayoutPanel6->Controls->Add(this->comboBoxLastName, 0, 1);
				this->tableLayoutPanel6->Controls->Add(this->comboBoxBillingAddress, 0, 9);
				this->tableLayoutPanel6->Controls->Add(this->textBoxBirthDate, 0, 5);
				this->tableLayoutPanel6->Location = Point(3, 3);
				this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
				this->tableLayoutPanel6->RowCount = 10;
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 43.28358F)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 56.71642F)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 69)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 78)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 79)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 66)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 71)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 92)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 61)));
				this->tableLayoutPanel6->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 62)));
				this->tableLayoutPanel6->Size = Drawing::Size(263, 708);
				this->tableLayoutPanel6->TabIndex = 1;
				
				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 25));
				this->labelTitle->Location = Point(233, 29);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(193, 39);
				this->labelTitle->TabIndex = 2;
				this->labelTitle->Text = L"Commande";
				
				/*-------------------- labelLastName --------------------*/
				this->labelLastName->Anchor = AnchorStyles::Left;
				this->labelLastName->AutoSize = true;
				this->labelLastName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelLastName->Location = Point(10, 15);
				this->labelLastName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelLastName->Name = L"labelLastName";
				this->labelLastName->Size = Drawing::Size(53, 25);
				this->labelLastName->TabIndex = 0;
				this->labelLastName->Text = L"Nom";
				
				/*-------------------- labelDeliveryAddress --------------------*/
				this->labelDeliveryAddress->Anchor = AnchorStyles::Left;
				this->labelDeliveryAddress->AutoSize = true;
				this->labelDeliveryAddress->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelDeliveryAddress->Location = Point(10, 444);
				this->labelDeliveryAddress->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelDeliveryAddress->Name = L"labelDeliveryAddress";
				this->labelDeliveryAddress->Size = Drawing::Size(188, 25);
				this->labelDeliveryAddress->TabIndex = 1;
				this->labelDeliveryAddress->Text = L"Adresse de livraison";
				
				/*-------------------- labelFirstName --------------------*/
				this->labelFirstName->Anchor = AnchorStyles::Left;
				this->labelFirstName->AutoSize = true;
				this->labelFirstName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelFirstName->Location = Point(10, 151);
				this->labelFirstName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelFirstName->Name = L"labelFirstName";
				this->labelFirstName->Size = Drawing::Size(80, 25);
				this->labelFirstName->TabIndex = 2;
				this->labelFirstName->Text = L"Prenom";
				
				/*-------------------- labelBillingAddress --------------------*/
				this->labelBillingAddress->Anchor = AnchorStyles::Left;
				this->labelBillingAddress->AutoSize = true;
				this->labelBillingAddress->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelBillingAddress->Location = Point(10, 602);
				this->labelBillingAddress->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelBillingAddress->Name = L"labelBillingAddress";
				this->labelBillingAddress->Size = Drawing::Size(207, 25);
				this->labelBillingAddress->TabIndex = 3;
				this->labelBillingAddress->Text = L"Adresse de facturation";
				
				/*-------------------- labelBirthDate --------------------*/
				this->labelBirthDate->Anchor = AnchorStyles::Left;
				this->labelBirthDate->AutoSize = true;
				this->labelBirthDate->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelBirthDate->Location = Point(10, 303);
				this->labelBirthDate->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelBirthDate->Name = L"labelBirthDate";
				this->labelBirthDate->Size = Drawing::Size(174, 25);
				this->labelBirthDate->TabIndex = 4;
				this->labelBirthDate->Text = L"Date de naissance";
				
				/*-------------------- labelProductName --------------------*/
				this->labelProductName->Anchor = AnchorStyles::Left;
				this->labelProductName->AutoSize = true;
				this->labelProductName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelProductName->Location = Point(10, 6);
				this->labelProductName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelProductName->Name = L"labelProductName";
				this->labelProductName->Size = Drawing::Size(73, 25);
				this->labelProductName->TabIndex = 0;
				this->labelProductName->Text = L"Produit";
				
				/*-------------------- labelColour --------------------*/
				this->labelColour->Anchor = AnchorStyles::Left;
				this->labelColour->AutoSize = true;
				this->labelColour->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelColour->Location = Point(10, 168);
				this->labelColour->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelColour->Name = L"labelColour";
				this->labelColour->Size = Drawing::Size(81, 25);
				this->labelColour->TabIndex = 1;
				this->labelColour->Text = L"Couleur";
				
				/*-------------------- labelType --------------------*/
				this->labelType->Anchor = AnchorStyles::Left;
				this->labelType->AutoSize = true;
				this->labelType->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelType->Location = Point(10, 88);
				this->labelType->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelType->Name = L"labelType";
				this->labelType->Size = Drawing::Size(70, 25);
				this->labelType->TabIndex = 2;
				this->labelType->Text = L"Nature";
				
				/*-------------------- labelQuantity --------------------*/
				this->labelQuantity->Anchor = AnchorStyles::Left;
				this->labelQuantity->AutoSize = true;
				this->labelQuantity->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->labelQuantity->Location = Point(10, 250);
				this->labelQuantity->Margin = Windows::Forms::Padding(10, 0, 3, 0);
				this->labelQuantity->Name = L"labelQuantity";
				this->labelQuantity->Size = Drawing::Size(86, 25);
				this->labelQuantity->TabIndex = 3;
				this->labelQuantity->Text = L"Quantite";
				
				/*-------------------- tableLayoutPanel7 --------------------*/
				this->tableLayoutPanel7->ColumnCount = 2;
				this->tableLayoutPanel7->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel7->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel7->Controls->Add(this->buttonAdd, 1, 0);
				this->tableLayoutPanel7->Controls->Add(this->buttonDelete, 0, 0);
				this->tableLayoutPanel7->Location = Point(3, 655);
				this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
				this->tableLayoutPanel7->RowCount = 1;
				this->tableLayoutPanel7->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel7->Size = Drawing::Size(372, 50);
				this->tableLayoutPanel7->TabIndex = 1;

				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Left));
				this->buttonDelete->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonDelete->Location = Point(7, 7);
				this->buttonDelete->Margin = Windows::Forms::Padding(7);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(112, 36);
				this->buttonDelete->TabIndex = 0;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				
				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Right));
				this->buttonAdd->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonAdd->Location = Point(252, 7);
				this->buttonAdd->Margin = Windows::Forms::Padding(7);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(113, 36);
				this->buttonAdd->TabIndex = 1;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				
				/*-------------------- buttonCancel --------------------*/
				this->buttonCancel->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Left));
				this->buttonCancel->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonCancel->Location = Point(7, 52);
				this->buttonCancel->Margin = Windows::Forms::Padding(7);
				this->buttonCancel->Name = L"buttonCancel";
				this->buttonCancel->Size = Drawing::Size(112, 33);
				this->buttonCancel->TabIndex = 0;
				this->buttonCancel->Text = L"Annuler";
				this->buttonCancel->UseVisualStyleBackColor = true;
				
				/*-------------------- buttonValidate --------------------*/
				this->buttonValidate->Anchor = static_cast<AnchorStyles>((AnchorStyles::Bottom | AnchorStyles::Right));
				this->buttonValidate->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonValidate->Location = Point(534, 52);
				this->buttonValidate->Margin = Windows::Forms::Padding(7);
				this->buttonValidate->Name = L"buttonValidate";
				this->buttonValidate->Size = Drawing::Size(112, 33);
				this->buttonValidate->TabIndex = 1;
				this->buttonValidate->Text = L"Valider";
				this->buttonValidate->UseVisualStyleBackColor = true;
				
				/*-------------------- dataGridViewProductList --------------------*/
				this->dataGridViewProductList->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewProductList->Location = Point(3, 3);
				this->dataGridViewProductList->Name = L"dataGridViewProductList";
				this->dataGridViewProductList->Size = Drawing::Size(372, 320);
				this->dataGridViewProductList->TabIndex = 2;
				
				/*-------------------- comboBoxLastName --------------------*/
				this->comboBoxLastName->Anchor = AnchorStyles::Left;
				this->comboBoxLastName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->comboBoxLastName->FormattingEnabled = true;
				this->comboBoxLastName->Location = Point(10, 82);
				this->comboBoxLastName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxLastName->Name = L"comboBoxLastName";
				this->comboBoxLastName->Size = Drawing::Size(243, 33);
				this->comboBoxLastName->TabIndex = 5;
				
				/*-------------------- comboBoxFirstName --------------------*/
				this->comboBoxFirstName->Anchor = AnchorStyles::Left;
				this->comboBoxFirstName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->comboBoxFirstName->FormattingEnabled = true;
				this->comboBoxFirstName->Location = Point(10, 220);
				this->comboBoxFirstName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxFirstName->Name = L"comboBoxFirstName";
				this->comboBoxFirstName->Size = Drawing::Size(243, 33);
				this->comboBoxFirstName->TabIndex = 6;
				
				/*-------------------- comboBoxBillingAddress --------------------*/
				this->comboBoxBillingAddress->Anchor = AnchorStyles::Left;
				this->comboBoxBillingAddress->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->comboBoxBillingAddress->FormattingEnabled = true;
				this->comboBoxBillingAddress->Location = Point(10, 660);
				this->comboBoxBillingAddress->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxBillingAddress->Name = L"comboBoxBillingAddress";
				this->comboBoxBillingAddress->Size = Drawing::Size(243, 33);
				this->comboBoxBillingAddress->TabIndex = 7;
				
				/*-------------------- comboBoxDeliveryAddress --------------------*/
				this->comboBoxDeliveryAddress->Anchor = AnchorStyles::Left;
				this->comboBoxDeliveryAddress->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->comboBoxDeliveryAddress->FormattingEnabled = true;
				this->comboBoxDeliveryAddress->Location = Point(10, 521);
				this->comboBoxDeliveryAddress->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxDeliveryAddress->Name = L"comboBoxDeliveryAddress";
				this->comboBoxDeliveryAddress->Size = Drawing::Size(243, 33);
				this->comboBoxDeliveryAddress->TabIndex = 8;
				
				/*-------------------- comboBoxProductName --------------------*/
				this->comboBoxProductName->Anchor = AnchorStyles::Left;
				this->comboBoxProductName->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->comboBoxProductName->FormattingEnabled = true;
				this->comboBoxProductName->Location = Point(10, 47);
				this->comboBoxProductName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxProductName->Name = L"comboBoxProductName";
				this->comboBoxProductName->Size = Drawing::Size(352, 24);
				this->comboBoxProductName->TabIndex = 4;
				
				/*-------------------- comboBoxType --------------------*/
				this->comboBoxType->Anchor = AnchorStyles::Left;
				this->comboBoxType->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->comboBoxType->FormattingEnabled = true;
				this->comboBoxType->Location = Point(10, 128);
				this->comboBoxType->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxType->Name = L"comboBoxType";
				this->comboBoxType->Size = Drawing::Size(352, 24);
				this->comboBoxType->TabIndex = 5;
				
				/*-------------------- comboBoxColour --------------------*/
				this->comboBoxColour->Anchor = AnchorStyles::Left;
				this->comboBoxColour->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->comboBoxColour->FormattingEnabled = true;
				this->comboBoxColour->Location = Point(10, 210);
				this->comboBoxColour->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->comboBoxColour->Name = L"comboBoxColour";
				this->comboBoxColour->Size = Drawing::Size(352, 24);
				this->comboBoxColour->TabIndex = 6;
				
				/*-------------------- textBoxQuantity --------------------*/
				this->textBoxQuantity->Anchor = AnchorStyles::Left;
				this->textBoxQuantity->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 10));
				this->textBoxQuantity->Location = Point(10, 290);
				this->textBoxQuantity->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxQuantity->Name = L"textBoxQuantity";
				this->textBoxQuantity->Size = Drawing::Size(352, 23);
				this->textBoxQuantity->TabIndex = 7;
				
				/*-------------------- textBoxBirthDate --------------------*/
				this->textBoxBirthDate->Anchor = AnchorStyles::Left;
				this->textBoxBirthDate->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->textBoxBirthDate->Location = Point(10, 373);
				this->textBoxBirthDate->Margin = Windows::Forms::Padding(10, 3, 10, 3);
				this->textBoxBirthDate->Name = L"textBoxBirthDate";
				this->textBoxBirthDate->Size = Drawing::Size(243, 30);
				this->textBoxBirthDate->TabIndex = 9;
				
				/*-------------------- OrderForm --------------------*/
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 941);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"OrderForm";
				this->Text = L"OrderForm";
			}

	};
}
