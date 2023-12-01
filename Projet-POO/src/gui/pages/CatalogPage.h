#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
    public ref class CatalogPage : public Form
    {
    public:
        CatalogPage()
        {
            initialize();
            reloadCatalogGridView();
        }

    private:
        TableLayoutPanel^ tableLayoutPanel1;
        TableLayoutPanel^ tableLayoutPanel2;
        
        Label^ labelTitle;
        
        DataGridView^ dataGridViewCatalog;
        
        CheckBox^ checkBoxDeleted;
        
        Button^ buttonAdd;
        Button^ buttonEdit;
        Button^ buttonDelete;
        
        void initialize()
        {
            this->tableLayoutPanel1 = gcnew TableLayoutPanel();
            this->tableLayoutPanel2 = gcnew TableLayoutPanel();
            
            this->labelTitle = gcnew Label();
            
            this->dataGridViewCatalog = gcnew DataGridView();
            
            this->checkBoxDeleted = gcnew CheckBox();
            
            this->buttonAdd = gcnew Button();
            this->buttonEdit = gcnew Button();
            this->buttonDelete = gcnew Button();
           
            /*-------------------- tableLayoutPanel1 --------------------*/
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent,50));
            this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->dataGridViewCatalog, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
            this->tableLayoutPanel1->Location = Point(13, 12);
            this->tableLayoutPanel1->Margin = Windows::Forms::Padding(3, 2, 3, 2);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 3;
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 22.1519F));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 77.8481F));
            this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 153));
            this->tableLayoutPanel1->Size = Drawing::Size(957, 628);
            this->tableLayoutPanel1->TabIndex = 1;

            /*-------------------- tableLayoutPanel2 --------------------*/
            this->tableLayoutPanel2->ColumnCount = 6;
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 261));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 63));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 121));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 127));
            this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 156));
            this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 3, 0);
            this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 4, 0);
            this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 5, 0);
            this->tableLayoutPanel2->Location = Point(3, 476);
            this->tableLayoutPanel2->Margin = Windows::Forms::Padding(3, 2, 3, 2);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 1;
            this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            this->tableLayoutPanel2->Size = Drawing::Size(951, 148);
            this->tableLayoutPanel2->TabIndex = 2;
            
            /*-------------------- labelTitle --------------------*/
            this->labelTitle->Anchor = AnchorStyles::None;
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
            this->labelTitle->Location = Point(373, 28);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = Drawing::Size(210, 48);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Catalogue";
            
            /*-------------------- dataGridViewCatalog --------------------*/
            this->dataGridViewCatalog->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewCatalog->Location = Point(15, 120);
            this->dataGridViewCatalog->Margin = Windows::Forms::Padding(15);
            this->dataGridViewCatalog->Name = L"dataGridViewCatalog";
            this->dataGridViewCatalog->RowHeadersWidth = 51;
            this->dataGridViewCatalog->RowTemplate->Height = 24;
            this->dataGridViewCatalog->Size = Drawing::Size(927, 338);
            this->dataGridViewCatalog->TabIndex = 1;
            this->dataGridViewCatalog->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            this->dataGridViewCatalog->ReadOnly = true;
            this->dataGridViewCatalog->AllowUserToResizeRows = false;
            this->dataGridViewCatalog->AllowUserToAddRows = false;
            this->dataGridViewCatalog->RowHeadersVisible = false;
            this->dataGridViewCatalog->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
            this->dataGridViewCatalog->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
            this->dataGridViewCatalog->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            this->dataGridViewCatalog->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
            this->dataGridViewCatalog->ColumnHeadersHeight = 40;
            
            auto idProduct = gcnew DataGridViewTextBoxColumn();
            idProduct->Visible = false;
            this->dataGridViewCatalog->Columns->Add(idProduct);

            auto deleted = gcnew DataGridViewTextBoxColumn();
            deleted->Visible = false;
            this->dataGridViewCatalog->Columns->Add(deleted);

            auto reference = gcnew DataGridViewTextBoxColumn();
            reference->Name = L"Reference";
            this->dataGridViewCatalog->Columns->Add(reference);

            auto type = gcnew DataGridViewTextBoxColumn();
            type->Name = L"Nature";
            this->dataGridViewCatalog->Columns->Add(type);

            auto name = gcnew DataGridViewTextBoxColumn();
            name->Name = L"Nom";
            this->dataGridViewCatalog->Columns->Add(name);

            auto addressesCount = gcnew DataGridViewTextBoxColumn();
            addressesCount->Name = L"Couleur";
            this->dataGridViewCatalog->Columns->Add(addressesCount);

            auto buyPrice = gcnew DataGridViewTextBoxColumn();
            buyPrice->Name = L"Prix d'achat";
            this->dataGridViewCatalog->Columns->Add(buyPrice);

            auto vatRate = gcnew DataGridViewTextBoxColumn();
            vatRate->Name = L"TVA";
            this->dataGridViewCatalog->Columns->Add(vatRate);

            auto quantity = gcnew DataGridViewTextBoxColumn();
            quantity->Name = L"Stock";
            this->dataGridViewCatalog->Columns->Add(quantity);

            auto provisioningThreshold = gcnew DataGridViewTextBoxColumn();
            provisioningThreshold->Name = L"Limite de reapprovisionnement";
            this->dataGridViewCatalog->Columns->Add(provisioningThreshold);
            
            /*-------------------- checkBoxDeleted --------------------*/
            this->checkBoxDeleted->Anchor = AnchorStyles::None;
            this->checkBoxDeleted->AutoSize = true;
            this->checkBoxDeleted->Location = Point(11, 64);
            this->checkBoxDeleted->Margin = Windows::Forms::Padding(3, 2, 3, 2);
            this->checkBoxDeleted->Name = L"checkBoxDeleted";
            this->checkBoxDeleted->Size = Drawing::Size(201, 20);
            this->checkBoxDeleted->TabIndex = 0;
            this->checkBoxDeleted->Text = L"Afficher les clients supprim�s";
            this->checkBoxDeleted->UseVisualStyleBackColor = true;
            
            /*-------------------- buttonAdd --------------------*/
            this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
            this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
            this->buttonAdd->Location = Point(554, 94);
            this->buttonAdd->Margin = Windows::Forms::Padding(7);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = Drawing::Size(107, 47);
            this->buttonAdd->TabIndex = 2;
            this->buttonAdd->Text = L"Ajouter";
            this->buttonAdd->UseVisualStyleBackColor = true;
            this->buttonAdd->Click += gcnew EventHandler(this, &CatalogPage::buttonAdd_Click);
            
            /*-------------------- buttonEdit --------------------*/
            this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
            this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
            this->buttonEdit->Location = Point(675, 94);
            this->buttonEdit->Margin = Windows::Forms::Padding(7);
            this->buttonEdit->Name = L"buttonEdit";
            this->buttonEdit->Size = Drawing::Size(113, 47);
            this->buttonEdit->TabIndex = 3;
            this->buttonEdit->Text = L"Modifier";
            this->buttonEdit->UseVisualStyleBackColor = true;
            this->buttonEdit->Click += gcnew EventHandler(this, &CatalogPage::buttonEdit_Click);
            
            /*-------------------- buttonDelete --------------------*/
            this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
            this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
            this->buttonDelete->Location = Point(802, 94);
            this->buttonDelete->Margin = Windows::Forms::Padding(7);
            this->buttonDelete->Name = L"buttonDelete";
            this->buttonDelete->Size = Drawing::Size(142, 47);
            this->buttonDelete->TabIndex = 4;
            this->buttonDelete->Text = L"Supprimer";
            this->buttonDelete->UseVisualStyleBackColor = true;
            this->buttonDelete->Click += gcnew EventHandler(this, &CatalogPage::buttonDelete_Click);
            
            /*-------------------- CatalogPage --------------------*/
            this->StartPosition = FormStartPosition::CenterScreen;
            this->AutoScaleDimensions = SizeF(8, 16);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(982, 653);
            this->Controls->Add(this->tableLayoutPanel1);
            this->MaximizeBox = false;
            this->Name = L"CatalogPage";
            this->Text = L"CatalogPage";
        }

        Void reloadCatalogGridView();
        Void buttonAdd_Click(Object^ sender, EventArgs^ e);
        Void buttonEdit_Click(Object^ sender, EventArgs^ e);
        Void buttonDelete_Click(Object^ sender, EventArgs^ e);
    };
}
