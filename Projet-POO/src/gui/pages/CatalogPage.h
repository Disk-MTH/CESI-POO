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

			Button^ buttonProductDetails;
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

				this->buttonProductDetails = gcnew Button();
				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewCatalog, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Location = Point(10, 11);
				this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 22.1519F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 77.8481F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 153));
				this->tableLayoutPanel1->Size = Drawing::Size(963, 639);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 6;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 291));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 30));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 119));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 117));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 135));
				this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonProductDetails, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 3, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 4, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 5, 0);
				this->tableLayoutPanel2->Location = Point(2, 487);
				this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(959, 150);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(420, 34);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(122, 39);
				this->labelTitle->Text = L"Catalogue";

				/*-------------------- dataGridViewCatalog --------------------*/
				this->dataGridViewCatalog->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewCatalog->Location = Point(11, 119);
				this->dataGridViewCatalog->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->dataGridViewCatalog->Name = L"dataGridViewCatalog";
				this->dataGridViewCatalog->Size = Drawing::Size(941, 354);
				this->dataGridViewCatalog->TabIndex = 0;
				this->dataGridViewCatalog->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewCatalog->ReadOnly = true;
				this->dataGridViewCatalog->AllowUserToResizeRows = false;
				this->dataGridViewCatalog->AllowUserToAddRows = false;
				this->dataGridViewCatalog->RowHeadersVisible = false;
				this->dataGridViewCatalog->AllowUserToDeleteRows = false;
				this->dataGridViewCatalog->MultiSelect = false;
				this->dataGridViewCatalog->ColumnHeadersDefaultCellStyle->WrapMode = DataGridViewTriState::False;
				this->dataGridViewCatalog->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->dataGridViewCatalog->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
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
				provisioningThreshold->Name = L"Limite de restock";
				provisioningThreshold->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				this->dataGridViewCatalog->Columns->Add(provisioningThreshold);

				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->checkBoxDeleted->Location = Point(10, 60);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(10, 6, 10, 6);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(247, 29);
				this->checkBoxDeleted->TabIndex = 1;
				this->checkBoxDeleted->Text = L"Afficher les produits\nsupprimes";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;
				//this->checkBoxDeleted->Click += gcnew EventHandler(this, &CustomersPage::checkBoxDeleted_Click);

				/*-------------------- buttonProductDetails --------------------*/
				this->buttonProductDetails->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonProductDetails->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonProductDetails->Location = Point(278, 12);
				this->buttonProductDetails->Margin = Windows::Forms::Padding(11, 6, 11, 6);
				this->buttonProductDetails->Name = L"buttonProductDetails";
				this->buttonProductDetails->Size = Drawing::Size(269, 126);
				this->buttonProductDetails->TabIndex = 2;
				this->buttonProductDetails->Text = L"Details";
				this->buttonProductDetails->UseVisualStyleBackColor = true;
				this->buttonProductDetails->Click += gcnew EventHandler(this, &CatalogPage::buttonProductDetails_Click);

				/*-------------------- buttonDelete --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonAdd->Location = Point(595, 106);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonDelete";
				this->buttonAdd->Size = Drawing::Size(107, 38);
				this->buttonAdd->TabIndex = 3;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &CatalogPage::buttonAdd_Click);

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonEdit->Location = Point(712, 106);
				this->buttonEdit->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(107, 38);
				this->buttonEdit->TabIndex = 4;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;
				this->buttonEdit->Click += gcnew EventHandler(this, &CatalogPage::buttonEdit_Click);

				/*-------------------- buttonAdd --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonDelete->Location = Point(829, 106);
				this->buttonDelete->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonDelete->Name = L"buttonAdd";
				this->buttonDelete->Size = Drawing::Size(125, 38);
				this->buttonDelete->TabIndex = 5;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				this->buttonDelete->Click += gcnew EventHandler(this, &CatalogPage::buttonDelete_Click);

				/*-------------------- CatalogPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(984, 661);
				this->Controls->Add(this->tableLayoutPanel1);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Name = L"CatalogPage";
				this->Text = L"CatalogPage";
			}

			Void reloadCatalogGridView();
			Void buttonProductDetails_Click(Object^ sender, EventArgs^ e);
			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
	};
}
