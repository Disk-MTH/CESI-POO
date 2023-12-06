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
        OrderForm(String^ orderId, String^ lastName, String^ firstName, String^ birthdate, String^ billingAddress, String^ deliveryAddress, String^ deliveryDate)
        {
            this->orderId = orderId;
            this->lastName = lastName;
            this->firstName = firstName;
            this->birthdate = birthdate;
            this->billingAddress = billingAddress;
            this->deliveryAddress = deliveryAddress;
            this->deliveryDate = deliveryDate;
            this->mode = orderId == "" ? "0" : "1"; //0 = add, 1 = edit
            
            initialize();
            reloadProductsGridView();
            comboBoxUser_keyPress(nullptr, nullptr);
        }

    private:
        String^ orderId;
        String^ lastName;
        String^ firstName;
        String^ birthdate;
        String^ billingAddress;
        String^ deliveryAddress;
        String^ deliveryDate;
        String^ mode;
        
        TableLayoutPanel^ tableLayoutPanel1;
        TableLayoutPanel^ tableLayoutPanel2;
        TableLayoutPanel^ tableLayoutPanel3;
        TableLayoutPanel^ tableLayoutPanel4;
        TableLayoutPanel^ tableLayoutPanel5;
        TableLayoutPanel^ tableLayoutPanel6;
        TableLayoutPanel^ tableLayoutPanel7;

        Label^ labelTitle;
        Label^ labelLastName;
        Label^ labelFirstName;
        Label^ labelBirthDate;
        Label^ labelBillingAddress;
        Label^ labelDeliveryAddress;
        Label^ labelDeliveryDate;
        Label^ labelType;
        Label^ labelProductName;
        Label^ labelColour;
        Label^ labelQuantity;

        DataGridView^ dataGridViewProducts;

        ComboBox^ comboBoxLastName;
        ComboBox^ comboBoxFirstName;
        ComboBox^ comboBoxBirthdate;
        ComboBox^ comboBoxBillingAddress;
        ComboBox^ comboBoxDeliveryAddress;
        TextBox^ textBoxDeliveryDate;
        ComboBox^ comboBoxType;
        ComboBox^ comboBoxProductName;
        ComboBox^ comboBoxColour;
        TextBox^ textBoxQuantity;

        Button^ buttonAdd;
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
            this->tableLayoutPanel7 = gcnew TableLayoutPanel();
            
            this->labelTitle = gcnew Label();
            this->labelLastName = gcnew Label();
            this->labelFirstName = gcnew Label();
            this->labelBirthDate = gcnew Label();
            this->labelBillingAddress = gcnew Label();
            this->labelDeliveryAddress = gcnew Label();
            this->labelDeliveryDate = gcnew Label();
            this->labelType = gcnew Label();
            this->labelProductName = gcnew Label();
            this->labelColour = gcnew Label();
            this->labelQuantity = gcnew Label();

            this->dataGridViewProducts = gcnew DataGridView();

            this->comboBoxLastName = gcnew ComboBox();
            this->comboBoxFirstName = gcnew ComboBox();
            this->comboBoxBirthdate = gcnew ComboBox();
            this->comboBoxBillingAddress = gcnew ComboBox();
            this->comboBoxDeliveryAddress = gcnew ComboBox();
            this->textBoxDeliveryDate = gcnew TextBox();
            this->comboBoxType = gcnew ComboBox();
            this->comboBoxProductName = gcnew ComboBox();
            this->comboBoxColour = gcnew ComboBox();
            this->textBoxQuantity = gcnew TextBox();

            this->buttonAdd = gcnew Button();
            this->buttonDelete = gcnew Button();
            this->buttonCancel = gcnew Button();
            this->buttonValidate = gcnew Button();

            /*-------------------- tableLayoutPanel1 --------------------*/
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
            this->tableLayoutPanel1->Location = Point(13, 13);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 12));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 88));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 97));
            this->tableLayoutPanel1->Size = Drawing::Size(659, 916);

            /*-------------------- tableLayoutPanel2 --------------------*/
            this->tableLayoutPanel2->ColumnCount = 3;
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 233));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 211));
            this->tableLayoutPanel2->Controls->Add(this->buttonCancel, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->buttonValidate, 2, 0);
            this->tableLayoutPanel2->Location = Point(3, 821);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 1;
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->Size = Drawing::Size(653, 92);

            /*-------------------- tableLayoutPanel3 --------------------*/
            this->tableLayoutPanel3->ColumnCount = 2;
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 41.19449F));
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 58.80551F));
            this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 1, 0);
            this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 0);
            this->tableLayoutPanel3->Location = Point(3, 101);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 1;
            this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel3->Size = Drawing::Size(653, 714);

            /*-------------------- tableLayoutPanel4 --------------------*/
            this->tableLayoutPanel4->ColumnCount = 1;
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 1);
            this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel7, 0, 2);
            this->tableLayoutPanel4->Controls->Add(this->dataGridViewProducts, 0, 0);
            this->tableLayoutPanel4->Location = Point(272, 3);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 3;
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 55));
            this->tableLayoutPanel4->Size = Drawing::Size(378, 708);

            /*-------------------- tableLayoutPanel5 --------------------*/
            this->tableLayoutPanel5->ColumnCount = 1;
            this->tableLayoutPanel5->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel5->Controls->Add(this->comboBoxColour, 0, 5);
            this->tableLayoutPanel5->Controls->Add(this->comboBoxType, 0, 1);
            this->tableLayoutPanel5->Controls->Add(this->labelType, 0, 0);
            this->tableLayoutPanel5->Controls->Add(this->labelProductName, 0, 2);
            this->tableLayoutPanel5->Controls->Add(this->labelColour, 0, 4);
            this->tableLayoutPanel5->Controls->Add(this->labelQuantity, 0, 6);
            this->tableLayoutPanel5->Controls->Add(this->comboBoxProductName, 0, 3);
            this->tableLayoutPanel5->Controls->Add(this->textBoxQuantity, 0, 7);
            this->tableLayoutPanel5->Location = Point(3, 329);
            this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
            this->tableLayoutPanel5->RowCount = 8;
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 46.66667F));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 53.33333F));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 43));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 37));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 43));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 41));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
            this->tableLayoutPanel5->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 36));
            this->tableLayoutPanel5->Size = Drawing::Size(372, 320);

            /*-------------------- tableLayoutPanel6 --------------------*/
            this->tableLayoutPanel6->ColumnCount = 1;
            this->tableLayoutPanel6->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel6->Controls->Add(this->comboBoxBillingAddress, 0, 7);
            this->tableLayoutPanel6->Controls->Add(this->comboBoxFirstName, 0, 3);
            this->tableLayoutPanel6->Controls->Add(this->labelBirthDate, 0, 4);
            this->tableLayoutPanel6->Controls->Add(this->labelFirstName, 0, 2);
            this->tableLayoutPanel6->Controls->Add(this->labelLastName, 0, 0);
            this->tableLayoutPanel6->Controls->Add(this->labelDeliveryAddress, 0, 8);
            this->tableLayoutPanel6->Controls->Add(this->labelBillingAddress, 0, 6);
            this->tableLayoutPanel6->Controls->Add(this->comboBoxLastName, 0, 1);
            this->tableLayoutPanel6->Controls->Add(this->comboBoxDeliveryAddress, 0, 9);
            this->tableLayoutPanel6->Controls->Add(this->comboBoxBirthdate, 0, 5);
            this->tableLayoutPanel6->Controls->Add(this->textBoxDeliveryDate, 0, 11);
            this->tableLayoutPanel6->Controls->Add(this->labelDeliveryDate, 0, 10);
            this->tableLayoutPanel6->Location = Point(3, 3);
            this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
            this->tableLayoutPanel6->RowCount = 12;
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 59));
            this->tableLayoutPanel6->Size = Drawing::Size(263, 708);

            /*-------------------- tableLayoutPanel7 --------------------*/
            this->tableLayoutPanel7->ColumnCount = 2;
            this->tableLayoutPanel7->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel7->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel7->Controls->Add(this->buttonDelete, 1, 0);
            this->tableLayoutPanel7->Controls->Add(this->buttonAdd, 0, 0);
            this->tableLayoutPanel7->Location = Point(3, 655);
            this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
            this->tableLayoutPanel7->RowCount = 1;
            this->tableLayoutPanel7->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
            this->tableLayoutPanel7->Size = Drawing::Size(372, 50);
            
            /*-------------------- labelTitle --------------------*/
            this->labelTitle->Anchor = AnchorStyles::None;
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
            this->labelTitle->Location = Point(233, 29);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = Drawing::Size(193, 39);
            this->labelTitle->Text = L"Commande";
            
            /*-------------------- labelLastName --------------------*/
            this->labelLastName->Anchor = AnchorStyles::Left;
            this->labelLastName->AutoSize = true;
            this->labelLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelLastName->Location = Point(10, 15);
            this->labelLastName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelLastName->Name = L"labelLastName";
            this->labelLastName->Size = Drawing::Size(53, 25);
            this->labelLastName->Text = L"Nom";

            /*-------------------- labelFirstName --------------------*/
            this->labelFirstName->Anchor = AnchorStyles::Left;
            this->labelFirstName->AutoSize = true;
            this->labelFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelFirstName->Location = Point(10, 151);
            this->labelFirstName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelFirstName->Name = L"labelFirstName";
            this->labelFirstName->Size = Drawing::Size(80, 25);
            this->labelFirstName->Text = L"Prenom";

            /*-------------------- labelBirthDate --------------------*/
            this->labelBirthDate->Anchor = AnchorStyles::Left;
            this->labelBirthDate->AutoSize = true;
            this->labelBirthDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelBirthDate->Location = Point(10, 303);
            this->labelBirthDate->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelBirthDate->Name = L"labelBirthDate";
            this->labelBirthDate->Size = Drawing::Size(174, 25);
            this->labelBirthDate->Text = L"Date de naissance";

            /*-------------------- labelBillingAddress --------------------*/
            this->labelBillingAddress->Anchor = AnchorStyles::Left;
            this->labelBillingAddress->AutoSize = true;
            this->labelBillingAddress->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelBillingAddress->Location = Point(10, 444);
            this->labelBillingAddress->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelBillingAddress->Name = L"labelBillingAddress";
            this->labelBillingAddress->Size = Drawing::Size(188, 25);
            this->labelBillingAddress->Text = L"Adresse de facturation";
            
            /*-------------------- labelDeliveryAddress --------------------*/
            this->labelDeliveryAddress->Anchor = AnchorStyles::Left;
            this->labelDeliveryAddress->AutoSize = true;
            this->labelDeliveryAddress->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelDeliveryAddress->Location = Point(10, 602);
            this->labelDeliveryAddress->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelDeliveryAddress->Name = L"labelDeliveryAddress";
            this->labelDeliveryAddress->Size = Drawing::Size(207, 25);
            this->labelDeliveryAddress->Text = L"Adresse de livraison";

            /*-------------------- labelDeliveryDate --------------------*/
            this->labelDeliveryDate->Anchor = AnchorStyles::Left;
            this->labelDeliveryDate->AutoSize = true;
            this->labelDeliveryDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelDeliveryDate->Location = Point(10, 760);
            this->labelDeliveryDate->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelDeliveryDate->Name = L"labelDeliveryDate";
            this->labelDeliveryDate->Size = Drawing::Size(174, 25);
            this->labelDeliveryDate->Text = L"Date de livraison";
            
            /*-------------------- labelType --------------------*/
            this->labelType->Anchor = AnchorStyles::Left;
            this->labelType->AutoSize = true;
            this->labelType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelType->Location = Point(10, 6);
            this->labelType->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelType->Name = L"labelType";
            this->labelType->Size = Drawing::Size(70, 25);
            this->labelType->Text = L"Nature";

            /*-------------------- labelProductName --------------------*/
            this->labelProductName->Anchor = AnchorStyles::Left;
            this->labelProductName->AutoSize = true;
            this->labelProductName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelProductName->Location = Point(10, 88);
            this->labelProductName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelProductName->Name = L"labelProductName";
            this->labelProductName->Size = Drawing::Size(70, 25);
            this->labelProductName->Text = L"Produit";

            /*-------------------- labelColour --------------------*/
            this->labelColour->Anchor = AnchorStyles::Left;
            this->labelColour->AutoSize = true;
            this->labelColour->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelColour->Location = Point(10, 168);
            this->labelColour->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelColour->Name = L"labelColour";
            this->labelColour->Size = Drawing::Size(81, 25);
            this->labelColour->Text = L"Couleur";

            /*-------------------- labelQuantity --------------------*/
            this->labelQuantity->Anchor = AnchorStyles::Left;
            this->labelQuantity->AutoSize = true;
            this->labelQuantity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelQuantity->Location = Point(10, 250);
            this->labelQuantity->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelQuantity->Name = L"labelQuantity";
            this->labelQuantity->Size = Drawing::Size(86, 25);
            this->labelQuantity->Text = L"Quantite";
            
            /*-------------------- dataGridViewProducts --------------------*/
            this->dataGridViewProducts->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewProducts->Location = Point(3, 3);
            this->dataGridViewProducts->Name = L"dataGridViewProducts";
            this->dataGridViewProducts->Size = Drawing::Size(372, 320);
            this->dataGridViewProducts->TabIndex = 6;
            this->dataGridViewProducts->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            this->dataGridViewProducts->ReadOnly = true;
            this->dataGridViewProducts->AllowUserToResizeRows = false;
            this->dataGridViewProducts->AllowUserToAddRows = false;
            this->dataGridViewProducts->RowHeadersVisible = false;
            this->dataGridViewProducts->AllowUserToDeleteRows = false;
            this->dataGridViewProducts->MultiSelect = false;
            this->dataGridViewProducts->ColumnHeadersDefaultCellStyle->WrapMode = DataGridViewTriState::False;
            this->dataGridViewProducts->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->dataGridViewProducts->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->dataGridViewProducts->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
            this->dataGridViewProducts->ColumnHeadersHeight = 40;

            auto idProduct = gcnew DataGridViewTextBoxColumn();
            idProduct->Visible = false;
            this->dataGridViewProducts->Columns->Add(idProduct);
            
            auto type = gcnew DataGridViewTextBoxColumn();
            type->Name = "Nature";
            this->dataGridViewProducts->Columns->Add(type);

            auto name = gcnew DataGridViewTextBoxColumn();
            name->Name = "Nom";
            this->dataGridViewProducts->Columns->Add(name);

            auto colour = gcnew DataGridViewTextBoxColumn();
            colour->Name = "Couleur";
            this->dataGridViewProducts->Columns->Add(colour);

            auto quantity = gcnew DataGridViewTextBoxColumn();
            quantity->Name = "Quantity";
            this->dataGridViewProducts->Columns->Add(quantity);

            auto price = gcnew DataGridViewTextBoxColumn();
            price->Name = "Prix";
            this->dataGridViewProducts->Columns->Add(price);
            
            auto idOrderHasProduct = gcnew DataGridViewTextBoxColumn();
            idOrderHasProduct->Visible = false;
            this->dataGridViewProducts->Columns->Add(idOrderHasProduct);

            /*-------------------- comboBoxLastName --------------------*/
            this->comboBoxLastName->Anchor = AnchorStyles::Left;
            this->comboBoxLastName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->comboBoxLastName->FormattingEnabled = true;
            this->comboBoxLastName->Location = Point(10, 82);
            this->comboBoxLastName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxLastName->Name = L"comboBoxLastName";
            this->comboBoxLastName->Size = Drawing::Size(243, 33);
            this->comboBoxLastName->TabIndex = 0;
            this->comboBoxLastName->Text = lastName;
            this->comboBoxLastName->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxUser_keyPress);
            
            /*-------------------- comboBoxFirstName --------------------*/
            this->comboBoxFirstName->Anchor = AnchorStyles::Left;
            this->comboBoxFirstName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->comboBoxFirstName->FormattingEnabled = true;
            this->comboBoxFirstName->Location = Point(10, 220);
            this->comboBoxFirstName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxFirstName->Name = L"comboBoxFirstName";
            this->comboBoxFirstName->Size = Drawing::Size(243, 33);
            this->comboBoxFirstName->TabIndex = 1;
            this->comboBoxFirstName->Text = firstName;
            this->comboBoxFirstName->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxUser_keyPress);
            
            /*-------------------- comboBoxBirthdate --------------------*/
            this->comboBoxBirthdate->Anchor = AnchorStyles::Left;
            this->comboBoxBirthdate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->comboBoxFirstName->FormattingEnabled = true;
            this->comboBoxBirthdate->Location = Point(10, 373);
            this->comboBoxBirthdate->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxBirthdate->Name = L"comboBoxBirthdate";
            this->comboBoxBirthdate->Size = Drawing::Size(243, 30);
            this->comboBoxBirthdate->TabIndex = 2;
            this->comboBoxBirthdate->Text = birthdate;
            this->comboBoxBirthdate->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxUser_keyPress);
            this->comboBoxBirthdate->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxBirthdate_KeyPress);

            /*-------------------- comboBoxBillingAddress --------------------*/
            this->comboBoxBillingAddress->Anchor = AnchorStyles::Left;
            this->comboBoxBillingAddress->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->comboBoxBillingAddress->FormattingEnabled = true;
            this->comboBoxBillingAddress->Location = Point(10, 521);
            this->comboBoxBillingAddress->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxBillingAddress->Name = L"comboBoxBillingAddress";
            this->comboBoxBillingAddress->Size = Drawing::Size(243, 33);
            this->comboBoxBillingAddress->TabIndex = 3;
            this->comboBoxBillingAddress->Text = billingAddress;
            this->comboBoxBillingAddress->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxUser_keyPress);
            
            /*-------------------- comboBoxDeliveryAddress --------------------*/
            this->comboBoxDeliveryAddress->Anchor = AnchorStyles::Left;
            this->comboBoxDeliveryAddress->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->comboBoxDeliveryAddress->FormattingEnabled = true;
            this->comboBoxDeliveryAddress->Location = Point(10, 660);
            this->comboBoxDeliveryAddress->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxDeliveryAddress->Name = L"comboBoxDeliveryAddress";
            this->comboBoxDeliveryAddress->Size = Drawing::Size(243, 33);
            this->comboBoxDeliveryAddress->TabIndex = 4;
            this->comboBoxDeliveryAddress->Text = deliveryAddress;
            this->comboBoxDeliveryAddress->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxUser_keyPress);
            
            /*-------------------- textBoxDeliveryDate --------------------*/
            this->textBoxDeliveryDate->Anchor = AnchorStyles::Left;
            this->textBoxDeliveryDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->textBoxDeliveryDate->Location = Point(10, 799);
            this->textBoxDeliveryDate->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxDeliveryDate->Name = L"textBoxDeliveryDate";
            this->textBoxDeliveryDate->Size = Drawing::Size(243, 26);
            this->textBoxDeliveryDate->TabIndex = 5;
            this->textBoxDeliveryDate->Text = deliveryDate;

            /*-------------------- comboBoxType --------------------*/
            this->comboBoxType->Anchor = AnchorStyles::Left;
            this->comboBoxType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->comboBoxType->FormattingEnabled = true;
            this->comboBoxType->Location = Point(10, 47);
            this->comboBoxType->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxType->Name = L"comboBoxType";
            this->comboBoxType->Size = Drawing::Size(352, 24);
            this->comboBoxType->TabIndex = 8;
            this->comboBoxType->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxProduct_keyPress);
            
            /*-------------------- comboBoxProductName --------------------*/
            this->comboBoxProductName->Anchor = AnchorStyles::Left;
            this->comboBoxProductName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->comboBoxProductName->FormattingEnabled = true;
            this->comboBoxProductName->Location = Point(10, 128);
            this->comboBoxProductName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxProductName->Name = L"comboBoxProductName";
            this->comboBoxProductName->Size = Drawing::Size(352, 24);
            this->comboBoxProductName->TabIndex = 7;
            this->comboBoxProductName->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxProduct_keyPress);

            /*-------------------- comboBoxColour --------------------*/
            this->comboBoxColour->Anchor = AnchorStyles::Left;
            this->comboBoxColour->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->comboBoxColour->FormattingEnabled = true;
            this->comboBoxColour->Location = Point(10, 210);
            this->comboBoxColour->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxColour->Name = L"comboBoxColour";
            this->comboBoxColour->Size = Drawing::Size(352, 24);
            this->comboBoxColour->TabIndex = 9;
            this->comboBoxColour->KeyPress += gcnew KeyPressEventHandler(this, &OrderForm::comboBoxProduct_keyPress);

            /*-------------------- textBoxQuantity --------------------*/
            this->textBoxQuantity->Anchor = AnchorStyles::Left;
            this->textBoxQuantity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->textBoxQuantity->Location = Point(10, 290);
            this->textBoxQuantity->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxQuantity->Name = L"textBoxQuantity";
            this->textBoxQuantity->Size = Drawing::Size(352, 23);
            this->textBoxQuantity->TabIndex = 10;

            /*-------------------- buttonAdd --------------------*/
            this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
            this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonAdd->Location = Point(7, 7);
            this->buttonAdd->Margin = Windows::Forms::Padding(7);
            this->buttonAdd->Name = L"buttonDelete";
            this->buttonAdd->Size = Drawing::Size(112, 36);
            this->buttonAdd->TabIndex = 11;
            this->buttonAdd->Text = L"Ajouter";
            this->buttonAdd->UseVisualStyleBackColor = true;
            this->buttonAdd->Click += gcnew EventHandler(this, &OrderForm::buttonAdd_Click);
            
            /*-------------------- buttonDelete --------------------*/
            this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
            this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonDelete->Location = Point(252, 7);
            this->buttonDelete->Margin = Windows::Forms::Padding(7);
            this->buttonDelete->Name = L"buttonAdd";
            this->buttonDelete->Size = Drawing::Size(113, 36);
            this->buttonDelete->TabIndex = 12;
            this->buttonDelete->Text = L"Supprimer";
            this->buttonDelete->UseVisualStyleBackColor = true;
            this->buttonDelete->Click += gcnew EventHandler(this, &OrderForm::buttonDelete_Click);

            /*-------------------- buttonCancel --------------------*/
            this->buttonCancel->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonCancel->Location = Point(7, 52);
            this->buttonCancel->Margin = Windows::Forms::Padding(7);
            this->buttonCancel->Name = L"buttonCancel";
            this->buttonCancel->Size = Drawing::Size(112, 33);
            this->buttonCancel->TabIndex = 13;
            this->buttonCancel->Text = L"Annuler";
            this->buttonCancel->UseVisualStyleBackColor = true;
            this->buttonCancel->Click += gcnew EventHandler(this, &OrderForm::buttonCancel_Click);

            /*-------------------- buttonValidate --------------------*/
            this->buttonValidate->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonValidate->Location = Point(534, 52);
            this->buttonValidate->Margin = Windows::Forms::Padding(7);
            this->buttonValidate->Name = L"buttonValidate";
            this->buttonValidate->Size = Drawing::Size(112, 33);
            this->buttonValidate->TabIndex = 14;
            this->buttonValidate->Text = L"Valider";
            this->buttonValidate->UseVisualStyleBackColor = true;
            this->buttonValidate->Click += gcnew EventHandler(this, &OrderForm::buttonValidate_Click);

            /*-------------------- OrderForm --------------------*/
            this->StartPosition = FormStartPosition::Manual;
            this->AutoScaleDimensions = SizeF(6, 13);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(684, 890);
            this->Location = Point(Screen::PrimaryScreen->Bounds.Width / 2 - this->Width / 2, Screen::PrimaryScreen->Bounds.Height / 2 - this->Height / 2 - 50);
            this->Controls->Add(this->tableLayoutPanel1);
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"OrderForm";
            this->Text = L"OrderForm";
        }

        Void reloadProductsGridView();
        int^ createOrder();
        Void retreiveSuggestion(ComboBox^ comboBox, String^ query);
        Void comboBoxUser_keyPress(Object^ sender, KeyPressEventArgs^ e);
        Void comboBoxProduct_keyPress(Object^ sender, KeyPressEventArgs^ e);
        Void comboBoxBirthdate_KeyPress(Object^ sender, KeyPressEventArgs^ e);
        Void textBoxDeliveryDate_KeyPress(Object^ sender, KeyPressEventArgs^ e);
        Void buttonAdd_Click(Object^ sender, EventArgs^ e);
        Void buttonDelete_Click(Object^ sender, EventArgs^ e);
        Void buttonCancel_Click(Object^ sender, EventArgs^ e);
        Void buttonValidate_Click(Object^ sender, EventArgs^ e);
    };
}
