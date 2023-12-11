#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace OrderEase
{
    public ref class ProductForm : public Form
    {
    public:
        ProductForm(String^ productId, String^ restockThreshold, String^ vat, String^ quantity, String^ buyPrice, String^ name, String^ type, String^ colour)
        {
            this->productId = productId;
            this->restockThreshold = restockThreshold;
            this->vat = vat;
            this->quantity = quantity;
            this->buyPrice = buyPrice;
            this->name = name;
            this->type = type;
            this->colour = colour;
            this->mode = productId == "" ? "0" : "1"; //0 = add, 1 = edit
            
            initialize();
            reloadGridViewTieredPrice();
        }

    private:
        String^ productId;
        String^ restockThreshold;
        String^ vat;
        String^ quantity;
        String^ buyPrice;
        String^ name;
        String^ type;
        String^ colour;
        String^ mode;
        
        TableLayoutPanel^ tableLayoutPanel1;
        TableLayoutPanel^ tableLayoutPanel2;
        TableLayoutPanel^ tableLayoutPanel3;
        TableLayoutPanel^ tableLayoutPanel4;
        
        Label^ labelTitle;
        Label^ labelName;
        Label^ labelBuyPrice;
        Label^ labelQuantity;
        Label^ labelType;
        Label^ labelVat;
        Label^ labelRestockThreshold;
        Label^ labelColour;

        DataGridView^ dataGridViewTieredPrice;

        TextBox^ textBoxName;
        TextBox^ textBoxBuyPrice;
        TextBox^ textBoxQuantity;
        ComboBox^ comboBoxType;
        TextBox^ textBoxVat;
        TextBox^ textBoxRestockThreshold;
        ComboBox^ comboBoxColour;
        
        Button^ buttonAdd;
        Button^ buttonDelete;
        Button^ buttonEdit;
        Button^ buttonCancel;
        Button^ buttonValidate;

        void initialize()
        {
            this->tableLayoutPanel1 = gcnew TableLayoutPanel();
            this->tableLayoutPanel2 = gcnew TableLayoutPanel();
            this->tableLayoutPanel3 = gcnew TableLayoutPanel();
            this->tableLayoutPanel4 = gcnew TableLayoutPanel();
            
            this->labelTitle = gcnew Label();
            this->labelName = gcnew Label();
            this->labelBuyPrice = gcnew Label();
            this->labelQuantity = gcnew Label();
            this->labelType = gcnew Label();
            this->labelVat = gcnew Label();
            this->labelRestockThreshold = gcnew Label();
            this->labelColour = gcnew Label();

            this->dataGridViewTieredPrice = gcnew DataGridView();

            this->textBoxName = gcnew TextBox();
            this->textBoxBuyPrice = gcnew TextBox();
            this->textBoxQuantity = gcnew TextBox();
            this->comboBoxType = gcnew ComboBox();
            this->textBoxVat = gcnew TextBox();
            this->textBoxRestockThreshold = gcnew TextBox();
            this->comboBoxColour = gcnew ComboBox();
            
            this->buttonAdd = gcnew Button();
            this->buttonDelete = gcnew Button();
            this->buttonEdit = gcnew Button();
            this->buttonCancel = gcnew Button();
            this->buttonValidate = gcnew Button();

            /*-------------------- tableLayoutPanel1 --------------------*/
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->dataGridViewTieredPrice, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 3);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 4);
            this->tableLayoutPanel1->Location = Point(13, 13);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 5;
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 75));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 300));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 290));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 75));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 50));
            this->tableLayoutPanel1->Size = Drawing::Size(657, 928);

            /*-------------------- tableLayoutPanel2 --------------------*/
            this->tableLayoutPanel2->ColumnCount = 3;
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 40.29227F));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 59.70773F));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 185));
            this->tableLayoutPanel2->Controls->Add(this->textBoxRestockThreshold, 2, 3);
            this->tableLayoutPanel2->Controls->Add(this->textBoxVat, 1, 3);
            this->tableLayoutPanel2->Controls->Add(this->textBoxQuantity, 2, 1);
            this->tableLayoutPanel2->Controls->Add(this->textBoxBuyPrice, 1, 1);
            this->tableLayoutPanel2->Controls->Add(this->labelType, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->labelQuantity, 2, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelBuyPrice, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelName, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->labelColour, 0, 4);
            this->tableLayoutPanel2->Controls->Add(this->labelVat, 1, 2);
            this->tableLayoutPanel2->Controls->Add(this->labelRestockThreshold, 2, 2);
            this->tableLayoutPanel2->Controls->Add(this->textBoxName, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->comboBoxType, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->comboBoxColour, 0, 5);
            this->tableLayoutPanel2->Location = Point(3, 120);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 6;
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 47.82609F));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 52.17391F));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 51));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 60));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 52));
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
            this->tableLayoutPanel2->Size = Drawing::Size(651, 306);

            /*-------------------- tableLayoutPanel3 --------------------*/
            this->tableLayoutPanel3->ColumnCount = 3;
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 125));
            this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 154));
            this->tableLayoutPanel3->Controls->Add(this->buttonDelete, 2, 0);
            this->tableLayoutPanel3->Controls->Add(this->buttonEdit, 1, 0);
            this->tableLayoutPanel3->Controls->Add(this->buttonAdd, 0, 0);
            this->tableLayoutPanel3->Location = Point(3, 522);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 1;
            this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 50));
            this->tableLayoutPanel3->Size = Drawing::Size(651, 98);

            /*-------------------- tableLayoutPanel4 --------------------*/
            this->tableLayoutPanel4->ColumnCount = 3;
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 48.67257F));
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 51.32743F));
            this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 198));
            this->tableLayoutPanel4->Controls->Add(this->buttonValidate, 2, 0);
            this->tableLayoutPanel4->Controls->Add(this->buttonCancel, 0, 0);
            this->tableLayoutPanel4->Location = Point(3, 626);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 1;
            this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel4->Size = Drawing::Size(651, 99);

            /*-------------------- labelTitle --------------------*/
            this->labelTitle->Anchor = AnchorStyles::None;
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
            this->labelTitle->Location = Point(252, 34);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = Drawing::Size(153, 48);
            this->labelTitle->Text = L"Produit";

            /*-------------------- labelName --------------------*/
            this->labelName->Anchor = AnchorStyles::Left;
            this->labelName->AutoSize = true;
            this->labelName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelName->Location = Point(10, 10);
            this->labelName->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelName->Name = L"labelName";
            this->labelName->Size = Drawing::Size(67, 29);
            this->labelName->Text = L"Nom";

            /*-------------------- labelBuyPrice --------------------*/
            this->labelBuyPrice->Anchor = AnchorStyles::Left;
            this->labelBuyPrice->AutoSize = true;
            this->labelBuyPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelBuyPrice->Location = Point(197, 10);
            this->labelBuyPrice->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelBuyPrice->Name = L"labelBuyPrice";
            this->labelBuyPrice->Size = Drawing::Size(144, 29);
            this->labelBuyPrice->Text = L"Prix d\'achat";

            /*-------------------- labelQuantity --------------------*/
            this->labelQuantity->Anchor = AnchorStyles::Left;
            this->labelQuantity->AutoSize = true;
            this->labelQuantity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelQuantity->Location = Point(475, 10);
            this->labelQuantity->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelQuantity->Name = L"labelQuantity";
            this->labelQuantity->Size = Drawing::Size(108, 29);
            this->labelQuantity->Text = L"Quantite";

            /*-------------------- labelType --------------------*/
            this->labelType->Anchor = AnchorStyles::Left;
            this->labelType->AutoSize = true;
            this->labelType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelType->Location = Point(10, 113);
            this->labelType->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelType->Name = L"labelType";
            this->labelType->Size = Drawing::Size(88, 29);
            this->labelType->Text = L"Nature";

            /*-------------------- labelVat --------------------*/
            this->labelVat->Anchor = AnchorStyles::Left;
            this->labelVat->AutoSize = true;
            this->labelVat->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelVat->Location = Point(197, 113);
            this->labelVat->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelVat->Name = L"labelVat";
            this->labelVat->Size = Drawing::Size(159, 29);
            this->labelVat->Text = L"Taux de TVA";

            /*-------------------- labelRestockThreshold --------------------*/
            this->labelRestockThreshold->Anchor = AnchorStyles::Left;
            this->labelRestockThreshold->AutoSize = true;
            this->labelRestockThreshold->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelRestockThreshold->Location = Point(475, 113);
            this->labelRestockThreshold->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelRestockThreshold->Name = L"labelRestockThreshold";
            this->labelRestockThreshold->Size = Drawing::Size(105, 29);
            this->labelRestockThreshold->Text = L"Restock";
            
            /*-------------------- labelColour --------------------*/
            this->labelColour->Anchor = AnchorStyles::Left;
            this->labelColour->AutoSize = true;
            this->labelColour->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->labelColour->Location = Point(10, 224);
            this->labelColour->Margin = Windows::Forms::Padding(10, 0, 3, 0);
            this->labelColour->Name = L"labelColour";
            this->labelColour->Size = Drawing::Size(101, 29);
            this->labelColour->Text = L"Couleur";
            
            /*-------------------- dataGridViewTieredPrice --------------------*/
            this->dataGridViewTieredPrice->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewTieredPrice->Location = Point(15, 444);
            this->dataGridViewTieredPrice->Name = L"dataGridViewTieredPrice";
            this->dataGridViewTieredPrice->RowHeadersWidth = 51;
            this->dataGridViewTieredPrice->RowTemplate->Height = 24;
            this->dataGridViewTieredPrice->Size = Drawing::Size(627, 260);
            this->dataGridViewTieredPrice->TabIndex = 7;
            this->dataGridViewTieredPrice->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            this->dataGridViewTieredPrice->ReadOnly = true;
            this->dataGridViewTieredPrice->AllowUserToResizeRows = false;
            this->dataGridViewTieredPrice->AllowUserToAddRows = false;
            this->dataGridViewTieredPrice->RowHeadersVisible = false;
            this->dataGridViewTieredPrice->MultiSelect = false;
            this->dataGridViewTieredPrice->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->dataGridViewTieredPrice->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->dataGridViewTieredPrice->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridViewTieredPrice->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridViewTieredPrice->ColumnHeadersHeight = 40;

            auto minimalQuantity = gcnew DataGridViewTextBoxColumn();
            minimalQuantity->Name = L"Quantite";
            minimalQuantity->Resizable = DataGridViewTriState::False;
            this->dataGridViewTieredPrice->Columns->Add(minimalQuantity);

            auto tfPrice = gcnew DataGridViewTextBoxColumn();
            tfPrice->Name = L"Prix";
            tfPrice->Resizable = DataGridViewTriState::False;
            this->dataGridViewTieredPrice->Columns->Add(tfPrice);

            auto tieredPriceId = gcnew DataGridViewTextBoxColumn();
            tieredPriceId->Visible = false;
            this->dataGridViewTieredPrice->Columns->Add(tieredPriceId);

            /*-------------------- textBoxName --------------------*/
            this->textBoxName->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->textBoxName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->textBoxName->Location = Point(10, 64);
            this->textBoxName->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxName->Name = L"textBoxName";
            this->textBoxName->Size = Drawing::Size(167, 22);
            this->textBoxName->TabIndex = 0;
            this->textBoxName->Text = this->name;
            
            /*-------------------- textBoxBuyPrice --------------------*/
            this->textBoxBuyPrice->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->textBoxBuyPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->textBoxBuyPrice->Location = Point(197, 64);
            this->textBoxBuyPrice->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxBuyPrice->Name = L"textBoxBuyPrice";
            this->textBoxBuyPrice->Size = Drawing::Size(258, 22);
            this->textBoxBuyPrice->TabIndex = 1;
            this->textBoxBuyPrice->Text = this->buyPrice;
            this->textBoxBuyPrice->KeyPress += gcnew KeyPressEventHandler(this, &ProductForm::boxFloat_KeyPress);

            /*-------------------- textBoxQuantity --------------------*/
            this->textBoxQuantity->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->textBoxQuantity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->textBoxQuantity->Location = Point(475, 64);
            this->textBoxQuantity->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxQuantity->Name = L"textBoxQuantity";
            this->textBoxQuantity->Size = Drawing::Size(166, 22);
            this->textBoxQuantity->TabIndex = 2;
            this->textBoxQuantity->Text = this->quantity;
            this->textBoxQuantity->KeyPress += gcnew KeyPressEventHandler(this, &ProductForm::boxInt_KeyPress);

            /*-------------------- comboBoxType --------------------*/
            this->comboBoxType->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->comboBoxType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->comboBoxType->FormattingEnabled = true;
            this->comboBoxType->Location = Point(10, 171);
            this->comboBoxType->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxType->Name = L"comboBoxType";
            this->comboBoxType->Size = Drawing::Size(167, 24);
            this->comboBoxType->TabIndex = 3;
            this->comboBoxType->Text = this->type;
            retrieveSuggestion(this->comboBoxType, "SELECT DISTINCT type FROM product");

            /*-------------------- textBoxVat --------------------*/
            this->textBoxVat->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->textBoxVat->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->textBoxVat->Location = Point(197, 172);
            this->textBoxVat->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxVat->Name = L"textBoxVat";
            this->textBoxVat->Size = Drawing::Size(258, 22);
            this->textBoxVat->TabIndex = 4;
            this->textBoxVat->Text = this->vat;
            this->textBoxVat->KeyPress += gcnew KeyPressEventHandler(this, &ProductForm::boxFloat_KeyPress);

            /*-------------------- textBoxRestockThreshold --------------------*/
            this->textBoxRestockThreshold->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->textBoxRestockThreshold->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->textBoxRestockThreshold->Location = Point(475, 172);
            this->textBoxRestockThreshold->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->textBoxRestockThreshold->Name = L"textBoxRestockThreshold";
            this->textBoxRestockThreshold->Size = Drawing::Size(166, 22);
            this->textBoxRestockThreshold->TabIndex = 5;
            this->textBoxRestockThreshold->Text = this->restockThreshold;
            this->textBoxRestockThreshold->KeyPress += gcnew KeyPressEventHandler(this, &ProductForm::boxInt_KeyPress);

            /*-------------------- comboBoxColour --------------------*/
            this->comboBoxColour->Anchor = AnchorStyles::Top | AnchorStyles::Left;
            this->comboBoxColour->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->comboBoxColour->FormattingEnabled = true;
            this->comboBoxColour->Location = Point(10, 273);
            this->comboBoxColour->Margin = Windows::Forms::Padding(10, 3, 10, 3);
            this->comboBoxColour->Name = L"comboBoxColour";
            this->comboBoxColour->Size = Drawing::Size(167, 24);
            this->comboBoxColour->TabIndex = 6;
            this->comboBoxColour->Text = this->colour;
            retrieveSuggestion(this->comboBoxColour, "SELECT DISTINCT colour FROM product");

            /*-------------------- buttonAdd --------------------*/
            this->buttonAdd->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonAdd->Location = Point(252, 7);
            this->buttonAdd->Margin = Windows::Forms::Padding(7);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = Drawing::Size(113, 39);
            this->buttonAdd->TabIndex = 8;
            this->buttonAdd->Text = L"Ajouter";
            this->buttonAdd->UseVisualStyleBackColor = true;
            this->buttonAdd->Click += gcnew EventHandler(this, &ProductForm::buttonAdd_Click);

            /*-------------------- buttonEdit --------------------*/
            this->buttonEdit->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonEdit->Location = Point(379, 7);
            this->buttonEdit->Margin = Windows::Forms::Padding(7);
            this->buttonEdit->Name = L"buttonEdit";
            this->buttonEdit->Size = Drawing::Size(111, 39);
            this->buttonEdit->TabIndex = 9;
            this->buttonEdit->Text = L"Modifier";
            this->buttonEdit->UseVisualStyleBackColor = true;
            this->buttonEdit->Click += gcnew EventHandler(this, &ProductForm::buttonEdit_Click);

            /*-------------------- buttonDelete --------------------*/
            this->buttonDelete->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonDelete->Location = Point(504, 7);
            this->buttonDelete->Margin = Windows::Forms::Padding(7);
            this->buttonDelete->Name = L"buttonDelete";
            this->buttonDelete->Size = Drawing::Size(140, 39);
            this->buttonDelete->TabIndex = 10;
            this->buttonDelete->Text = L"Supprimer";
            this->buttonDelete->UseVisualStyleBackColor = true;
            this->buttonDelete->Click += gcnew EventHandler(this, &ProductForm::buttonDelete_Click);
            
            /*-------------------- buttonCancel --------------------*/
            this->buttonCancel->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonCancel->Location = Point(15, 15);
            this->buttonCancel->Margin = Windows::Forms::Padding(15);
            this->buttonCancel->Name = L"buttonCancel";
            this->buttonCancel->Size = Drawing::Size(190, 69);
            this->buttonCancel->TabIndex = 11;
            this->buttonCancel->Text = L"Annuler";
            this->buttonCancel->UseVisualStyleBackColor = true;
            this->buttonCancel->Click += gcnew EventHandler(this, &ProductForm::buttonCancel_Click);

            /*-------------------- buttonValidate --------------------*/
            this->buttonValidate->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
            this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->buttonValidate->Location = Point(467, 15);
            this->buttonValidate->Margin = Windows::Forms::Padding(15);
            this->buttonValidate->Name = L"buttonValidate";
            this->buttonValidate->Size = Drawing::Size(169, 69);
            this->buttonValidate->TabIndex = 12;
            this->buttonValidate->Text = L"Valider";
            this->buttonValidate->UseVisualStyleBackColor = true;
            this->buttonValidate->Click += gcnew EventHandler(this, &ProductForm::buttonValidate_Click);

            /*-------------------- ProductForm --------------------*/
            this->StartPosition = FormStartPosition::CenterScreen;
            this->AutoScaleDimensions = SizeF(8, 16);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(682, 860);
            this->Controls->Add(this->tableLayoutPanel1);
            this->MaximizeBox = false;
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->name = L"ProductForm";
            this->Text = L"ProductForm";
        }

        Void reloadGridViewTieredPrice();
        int^ createProduct();
        Void retrieveSuggestion(ComboBox^ comboBox, String^ query);
        Void openTieredPriceForm(String^ tieredpriceId, String^ quantity, String^ tfprice);
        Void boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e);
        Void boxFloat_KeyPress(Object^ sender, KeyPressEventArgs^ e);
        Void buttonAdd_Click(Object^ sender, EventArgs^ e);
        Void buttonEdit_Click(Object^ sender, EventArgs^ e);
        Void buttonDelete_Click(Object^ sender, EventArgs^ e);
        Void buttonCancel_Click(Object^ sender, EventArgs^ e);
        Void buttonValidate_Click(Object^ sender, EventArgs^ e);
    };
}
