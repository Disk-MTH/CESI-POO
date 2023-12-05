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
			OrderDetails(String^ orderId, String^ reference, String^ customer, String^ birthdate, String^ billingAddress, String^ deliveryAddress, String^ issueDate, String^ expectedDeliveryDate, String^ totalAmount, String^ vatAmount, String^ tfAmount)
			{
				this->orderId = orderId;
				this->reference = reference;
				this->customer = customer;
				this->birthdate = birthdate;
				this->billingAddress = billingAddress;
				this->deliveryAddress = deliveryAddress;
				this->issueDate = issueDate;
				this->expectedDeliveryDate = expectedDeliveryDate;
				this->totalAmount = totalAmount;
				this->vatAmount = vatAmount;
				this->tfAmount = tfAmount;
				initialize();
				reloadProductsGridView();
			}

		private:
			String^ orderId;
			String^ reference;
			String^ customer;
			String^ birthdate;
			String^ billingAddress;
			String^ deliveryAddress;
			String^ issueDate;
			String^ expectedDeliveryDate;
			String^ totalAmount;
			String^ vatAmount;
			String^ tfAmount;

			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;
			TableLayoutPanel^ tableLayoutPanel4;

			Label^ labelTitle;
			Label^ labelCustomer;
			Label^ labelBirthdate;
			Label^ labelBillingAddress;
			Label^ labelDeliveryAddress;
			Label^ labelIssueDate;
			Label^ labelExpectedDeliveryDate;
			Label^ labelTotalPrice;
			Label^ labelTfPrice;
			Label^ labelVatPrice;

			DataGridView^ dataGridViewTieredPrices;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();
				this->tableLayoutPanel4 = gcnew TableLayoutPanel();
				
				this->labelTitle = gcnew Label();
				this->labelCustomer = gcnew Label();
				this->labelBirthdate = gcnew Label();
				this->labelBillingAddress = gcnew Label();
				this->labelDeliveryAddress = gcnew Label();
				this->labelIssueDate = gcnew Label();
				this->labelExpectedDeliveryDate = gcnew Label();
				this->labelTotalPrice = gcnew Label();
				this->labelTfPrice = gcnew Label();
				this->labelVatPrice = gcnew Label();

				this->dataGridViewTieredPrices = gcnew DataGridView();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Location = Point(12, 12);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 2;
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 18.30664F)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 81.69337F)));
				this->tableLayoutPanel1->Size = Drawing::Size(660, 437);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent, 60.24465F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent, 39.75535F)));
				this->tableLayoutPanel2->Controls->Add(this->dataGridViewTieredPrices, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->labelTotalPrice, 0, 1);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 1);
				this->tableLayoutPanel2->Location = Point(3, 83);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 2;
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 79.19075F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 20.80925F)));
				this->tableLayoutPanel2->Size = Drawing::Size(654, 351);

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Controls->Add(this->labelExpectedDeliveryDate, 0, 5);
				this->tableLayoutPanel3->Controls->Add(this->labelIssueDate, 0, 4);
				this->tableLayoutPanel3->Controls->Add(this->labelDeliveryAddress, 0, 3);
				this->tableLayoutPanel3->Controls->Add(this->labelBillingAddress, 0, 2);
				this->tableLayoutPanel3->Controls->Add(this->labelBirthdate, 0, 1);
				this->tableLayoutPanel3->Controls->Add(this->labelCustomer, 0, 0);
				this->tableLayoutPanel3->Location = Point(3, 3);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 6;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 43));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 42));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 45));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 46));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 43));
				this->tableLayoutPanel3->Size = Drawing::Size(388, 271);

				/*-------------------- tableLayoutPanel4 --------------------*/
				this->tableLayoutPanel4->ColumnCount = 1;
				this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel4->Controls->Add(this->labelVatPrice, 0, 1);
				this->tableLayoutPanel4->Controls->Add(this->labelTfPrice, 0, 0);
				this->tableLayoutPanel4->Location = Point(397, 280);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 2;
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel4->Size = Drawing::Size(254, 68);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(111, 20);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(438, 39);
				this->labelTitle->Text = L"Details de la commande: " + reference;

				/*-------------------- labelCustomer --------------------*/
				this->labelCustomer->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelCustomer->AutoSize = true;
				this->labelCustomer->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->labelCustomer->Location = Point(10, 16);
				this->labelCustomer->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelCustomer->Name = L"labelCustomer";
				this->labelCustomer->Size = Drawing::Size(368, 20);
				this->labelCustomer->Text = L"Client : " + customer;

				/*-------------------- labelBirthdate --------------------*/
				this->labelBirthdate->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelBirthdate->AutoSize = true;
				this->labelBirthdate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->labelBirthdate->Location = Point(10, 63);
				this->labelBirthdate->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelBirthdate->Name = L"labelBirthdate";
				this->labelBirthdate->Size = Drawing::Size(368, 20);
				this->labelBirthdate->Text = L"Date de naissance : " + birthdate;

				/*-------------------- labelBillingAddress --------------------*/
				this->labelBillingAddress->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelBillingAddress->AutoSize = true;
				this->labelBillingAddress->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->labelBillingAddress->Location = Point(10, 106);
				this->labelBillingAddress->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelBillingAddress->Name = L"labelBillingAddress";
				this->labelBillingAddress->Size = Drawing::Size(368, 20);
				this->labelBillingAddress->Text = L"Adr facturation : " + billingAddress;

				/*-------------------- labelDeliveryAddress --------------------*/
				this->labelDeliveryAddress->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelDeliveryAddress->AutoSize = true;
				this->labelDeliveryAddress->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->labelDeliveryAddress->Location = Point(10, 149);
				this->labelDeliveryAddress->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelDeliveryAddress->Name = L"labelDeliveryAddress";
				this->labelDeliveryAddress->Size = Drawing::Size(368, 20);
				this->labelDeliveryAddress->Text = L"Adr livraison : " + deliveryAddress;

				/*-------------------- labelIssueDate --------------------*/
				this->labelIssueDate->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelIssueDate->AutoSize = true;
				this->labelIssueDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->labelIssueDate->Location = Point(10, 195);
				this->labelIssueDate->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelIssueDate->Name = L"labelIssueDate";
				this->labelIssueDate->Size = Drawing::Size(368, 20);
				this->labelIssueDate->Text = L"Date d\'emission : " + issueDate;

				/*-------------------- labelExpectedDeliveryDate --------------------*/
				this->labelExpectedDeliveryDate->Anchor = AnchorStyles::Left | AnchorStyles::Right;
				this->labelExpectedDeliveryDate->AutoSize = true;
				this->labelExpectedDeliveryDate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5F);
				this->labelExpectedDeliveryDate->Location = Point(10, 239);
				this->labelExpectedDeliveryDate->Margin = Windows::Forms::Padding(10, 0, 10, 0);
				this->labelExpectedDeliveryDate->Name = L"labelExpectedDeliveryDate";
				this->labelExpectedDeliveryDate->Size = Drawing::Size(368, 20);
				this->labelExpectedDeliveryDate->Text = L"Date de livraison estimee : " + expectedDeliveryDate;

				/*-------------------- labelTotalPrice --------------------*/
				this->labelTotalPrice->Anchor = AnchorStyles::None;
				this->labelTotalPrice->AutoSize = true;
				this->labelTotalPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->labelTotalPrice->Location = Point(110, 298);
				this->labelTotalPrice->Name = L"labelTotalPrice";
				this->labelTotalPrice->Size = Drawing::Size(173, 31);
				this->labelTotalPrice->Text = L"Prix TTC : " + totalAmount + "$";

				/*-------------------- labelTfPrice --------------------*/
				this->labelTfPrice->Anchor = AnchorStyles::None;
				this->labelTfPrice->AutoSize = true;
				this->labelTfPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelTfPrice->Location = Point(69, 4);
				this->labelTfPrice->Name = L"labelTfPrice";
				this->labelTfPrice->Size = Drawing::Size(115, 25);
				this->labelTfPrice->Text = L"Prix HT : " + tfAmount + "$";

				/*-------------------- labelVatPrice --------------------*/
				this->labelVatPrice->Anchor = AnchorStyles::None;
				this->labelVatPrice->AutoSize = true;
				this->labelVatPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelVatPrice->Location = Point(81, 38);
				this->labelVatPrice->Name = L"labelVatPrice";
				this->labelVatPrice->Size = Drawing::Size(91, 25);
				this->labelVatPrice->Text = L"TVA : " + vatAmount + "$";

				/*-------------------- dataGridViewTieredPrices --------------------*/
				this->dataGridViewTieredPrices->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewTieredPrices->Location = Point(397, 3);
				this->dataGridViewTieredPrices->Name = L"dataGridViewTieredPrices";
				this->dataGridViewTieredPrices->Size = Drawing::Size(254, 271);
				this->dataGridViewTieredPrices->TabIndex = 0;
				this->dataGridViewTieredPrices->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewTieredPrices->ReadOnly = true;
				this->dataGridViewTieredPrices->AllowUserToResizeRows = false;
				this->dataGridViewTieredPrices->AllowUserToAddRows = false;
				this->dataGridViewTieredPrices->RowHeadersVisible = false;
				this->dataGridViewTieredPrices->AllowUserToDeleteRows = false;
				this->dataGridViewTieredPrices->MultiSelect = false;
				this->dataGridViewTieredPrices->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewTieredPrices->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->dataGridViewTieredPrices->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
				this->dataGridViewTieredPrices->ColumnHeadersHeight = 40;

				auto type = gcnew DataGridViewTextBoxColumn();
				type->Name = L"Nature";
				this->dataGridViewTieredPrices->Columns->Add(type);

				auto name = gcnew DataGridViewTextBoxColumn();
				name->Name = L"Nom";
				this->dataGridViewTieredPrices->Columns->Add(name);

				auto colour = gcnew DataGridViewTextBoxColumn();
				colour->Name = L"Couleur";
				this->dataGridViewTieredPrices->Columns->Add(colour);

				auto Quantity = gcnew DataGridViewTextBoxColumn();
				Quantity->Name = L"Quantite";
				this->dataGridViewTieredPrices->Columns->Add(Quantity);

				auto tfPrice = gcnew DataGridViewTextBoxColumn();
				tfPrice->Name = L"Prix HT";
				this->dataGridViewTieredPrices->Columns->Add(tfPrice);

				auto price = gcnew DataGridViewTextBoxColumn();
				price->Name = L"Pric TTC";
				this->dataGridViewTieredPrices->Columns->Add(price);
				
				/*-------------------- OrderDetails --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayoutPanel1);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Name = L"OrderDetails";
				this->Text = L"OrderDetails";
			}

			Void reloadProductsGridView();
	};
}
