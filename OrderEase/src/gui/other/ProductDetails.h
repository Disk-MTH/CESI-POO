#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace OrderEase
{
	public ref class ProductDetails : public Form
	{
		public:
			ProductDetails(String^ productId, String^ reference, String^ type, String^ name, String^ colour, String^ buyPrice, String^ vat_rate, String^ stock, String^ provisioningThreshold)
			{
				this->productId = productId;
				this->reference = reference;
				this->type = type;
				this->name = name;
				this->colour = colour;
				this->buyPrice = buyPrice;
				this->vat_rate = vat_rate;
				this->stock = stock;
				this->provisioningThreshold = provisioningThreshold;
				initialize();
				reloadTieredPricesGridView();
			}

		private:
			String^ productId;
			String^ reference;
			String^ type;
			String^ name;
			String^ colour;
			String^ buyPrice;
			String^ vat_rate;
			String^ stock;
			String^ provisioningThreshold;
		
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;

			Label^ labelTitle;
			Label^ labelReference;
			Label^ labelType;
			Label^ labelName;
			Label^ labelColour;
			Label^ labelBuyPrice;
			Label^ labelVat;
			Label^ labelStock;
			Label^ labelProvisioningThreshold;

			DataGridView^ dataGridViewTieredPrices;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();
				this->labelReference = gcnew Label();
				this->labelType = gcnew Label();
				this->labelName = gcnew Label();
				this->labelColour = gcnew Label();
				this->labelBuyPrice = gcnew Label();
				this->labelVat = gcnew Label();
				this->labelStock = gcnew Label();
				this->labelProvisioningThreshold = gcnew Label();
				
				this->dataGridViewTieredPrices = gcnew DataGridView();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewTieredPrices, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Location = Point(12, 12);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 18.55346F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 81.44654F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 118));
				this->tableLayoutPanel1->Size = Drawing::Size(660, 437);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Controls->Add(this->labelProvisioningThreshold, 1, 3);
				this->tableLayoutPanel2->Controls->Add(this->labelColour, 0, 3);
				this->tableLayoutPanel2->Controls->Add(this->labelStock, 1, 2);
				this->tableLayoutPanel2->Controls->Add(this->labelName, 0, 2);
				this->tableLayoutPanel2->Controls->Add(this->labelVat, 1, 1);
				this->tableLayoutPanel2->Controls->Add(this->labelType, 0, 1);
				this->tableLayoutPanel2->Controls->Add(this->labelBuyPrice, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelReference, 0, 0);
				this->tableLayoutPanel2->Location = Point(3, 62);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 4;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 51.5873F));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 48.4127F));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 69));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 57));
				this->tableLayoutPanel2->Size = Drawing::Size(654, 253);
				
				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(197, 10);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(265, 39);
				this->labelTitle->Text = L"Detail du produit";
			
				/*-------------------- labelReference --------------------*/
				this->labelReference->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelReference->AutoSize = true;
				this->labelReference->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelReference->Location = Point(10, 20);
				this->labelReference->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelReference->Name = L"labelReference";
				this->labelReference->Size = Drawing::Size(307, 25);
				this->labelReference->Text = L"Reference : " + this->reference;

				/*-------------------- labelType --------------------*/
				this->labelType->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelType->AutoSize = true;
				this->labelType->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelType->Location = Point(10, 83);
				this->labelType->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelType->Name = L"labelType";
				this->labelType->Size = Drawing::Size(307, 25);
				this->labelType->Text = L"Nature : " + this->type;

				/*-------------------- labelName --------------------*/
				this->labelName->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelName->AutoSize = true;
				this->labelName->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelName->Location = Point(10, 148);
				this->labelName->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelName->Name = L"labelName";
				this->labelName->Size = Drawing::Size(307, 25);
				this->labelName->Text = L"Nom : " + this->name;

				/*-------------------- labelColour --------------------*/
				this->labelColour->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelColour->AutoSize = true;
				this->labelColour->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelColour->Location = Point(10, 211);
				this->labelColour->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelColour->Name = L"labelColour";
				this->labelColour->Size = Drawing::Size(307, 25);
				this->labelColour->Text = L"Couleur : " + this->colour;
	
				/*-------------------- labelBuyPrice --------------------*/
				this->labelBuyPrice->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelBuyPrice->AutoSize = true;
				this->labelBuyPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelBuyPrice->Location = Point(337, 20);
				this->labelBuyPrice->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelBuyPrice->Name = L"labelBuyPrice";
				this->labelBuyPrice->Size = Drawing::Size(307, 25);
				this->labelBuyPrice->Text = L"Prix d\'achat : " + this->buyPrice;
				
				/*-------------------- labelVat --------------------*/
				this->labelVat->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelVat->AutoSize = true;
				this->labelVat->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelVat->Location = Point(337, 83);
				this->labelVat->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelVat->Name = L"labelVat";
				this->labelVat->Size = Drawing::Size(307, 25);
				this->labelVat->Text = L"TVA : " + this->vat_rate;

				/*-------------------- labelStock --------------------*/
				this->labelStock->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelStock->AutoSize = true;
				this->labelStock->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelStock->Location = Point(337, 148);
				this->labelStock->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelStock->Name = L"labelStock";
				this->labelStock->Size = Drawing::Size(307, 25);
				this->labelStock->Text = L"Stock : " + this->stock;
				
				/*-------------------- labelProvisioningThreshold --------------------*/
				this->labelProvisioningThreshold->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelProvisioningThreshold->AutoSize = true;
				this->labelProvisioningThreshold->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelProvisioningThreshold->Location = Point(337, 211);
				this->labelProvisioningThreshold->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelProvisioningThreshold->Name = L"labelProvisioningThreshold";
				this->labelProvisioningThreshold->Size = Drawing::Size(307, 25);
				this->labelProvisioningThreshold->Text = L"Limite de restock : " + this->provisioningThreshold;

				/*-------------------- dataGridViewTieredPrices --------------------*/
				this->dataGridViewTieredPrices->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewTieredPrices->Location = Point(3, 321);
				this->dataGridViewTieredPrices->Name = L"dataGridViewTieredPrices";
				this->dataGridViewTieredPrices->Size = Drawing::Size(654, 113);
				this->dataGridViewTieredPrices->TabIndex = 0;
				this->dataGridViewTieredPrices->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewTieredPrices->ReadOnly = true;
				this->dataGridViewTieredPrices->AllowUserToResizeRows = false;
				this->dataGridViewTieredPrices->AllowUserToAddRows = false;
				this->dataGridViewTieredPrices->RowHeadersVisible = false;
				this->dataGridViewTieredPrices->AllowUserToDeleteRows = false;
				this->dataGridViewTieredPrices->MultiSelect = false;
				this->dataGridViewTieredPrices->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->dataGridViewTieredPrices->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewTieredPrices->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
				this->dataGridViewTieredPrices->ColumnHeadersHeight = 40;

				auto minimalQuantity = gcnew DataGridViewTextBoxColumn();
				minimalQuantity->Name = L"Quantite minimale";
				minimalQuantity->Resizable = DataGridViewTriState::False;
				this->dataGridViewTieredPrices->Columns->Add(minimalQuantity);

				auto tfPrice = gcnew DataGridViewTextBoxColumn();
				tfPrice->Name = L"Prix HT";
				tfPrice->Resizable = DataGridViewTriState::False;
				this->dataGridViewTieredPrices->Columns->Add(tfPrice);

				auto price = gcnew DataGridViewTextBoxColumn();
				price->Name = L"Prix TTC";
				price->Resizable = DataGridViewTriState::False;
				this->dataGridViewTieredPrices->Columns->Add(price);
				
				/*-------------------- ProductDetails --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayoutPanel1);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Name = L"ProductDetails";
				this->Text = L"ProductDetails";
			}

			Void reloadTieredPricesGridView();
	};
}
