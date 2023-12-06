#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class OrdersPage : public Form
	{
		public:
			OrdersPage()
			{
				initialize();
				reloadOrdersGridView();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
			TableLayoutPanel^ tableLayoutPanel3;

			Label^ labelTitle;

			DataGridView^ dataGridViewOrders;

			CheckBox^ checkBoxDeleted;

			Button^ buttonPayments;
			Button^ buttonOrderDetails;
			Button^ buttonEdit;
			Button^ buttonAdd;
			Button^ buttonDelete;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->tableLayoutPanel3 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();

				this->dataGridViewOrders = gcnew DataGridView();

				this->checkBoxDeleted = gcnew CheckBox();

				this->buttonPayments = gcnew Button();
				this->buttonOrderDetails = gcnew Button();
				this->buttonAdd = gcnew Button();
				this->buttonDelete = gcnew Button();
				this->buttonEdit = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewOrders, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Location = Point(13, 13);
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
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 3, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 4, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 5, 0);
				this->tableLayoutPanel2->Location = Point(2, 487);
				this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(959, 150);

				/*-------------------- tableLayoutPanel3 --------------------*/
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Controls->Add(this->buttonPayments, 0, 0);
				this->tableLayoutPanel3->Controls->Add(this->buttonOrderDetails, 0, 1);
				this->tableLayoutPanel3->Location = Point(13, 13);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 2;
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel3->Size = Drawing::Size(963, 639);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(420, 34);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(122, 39);
				this->labelTitle->Text = L"Commandes";

				/*-------------------- dataGridViewOrders --------------------*/
				this->dataGridViewOrders->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewOrders->Location = Point(11, 119);
				this->dataGridViewOrders->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->dataGridViewOrders->Name = L"dataGridViewOrders";
				this->dataGridViewOrders->Size = Drawing::Size(941, 354);
				this->dataGridViewOrders->TabIndex = 0;
				this->dataGridViewOrders->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewOrders->ReadOnly = true;
				this->dataGridViewOrders->AllowUserToResizeRows = false;
				this->dataGridViewOrders->AllowUserToAddRows = false;
				this->dataGridViewOrders->RowHeadersVisible = false;
				this->dataGridViewOrders->AllowUserToDeleteRows = false;
				this->dataGridViewOrders->MultiSelect = false;
				this->dataGridViewOrders->ColumnHeadersDefaultCellStyle->WrapMode = DataGridViewTriState::False;
				this->dataGridViewOrders->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->dataGridViewOrders->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewOrders->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
				this->dataGridViewOrders->ColumnHeadersHeight = 40;

				auto idOrder = gcnew DataGridViewTextBoxColumn();
				idOrder->Visible = false;
				this->dataGridViewOrders->Columns->Add(idOrder);

				auto reference = gcnew DataGridViewTextBoxColumn();
				reference->Name = "Reference";
				this->dataGridViewOrders->Columns->Add(reference);

				auto lastName = gcnew DataGridViewTextBoxColumn();
				lastName->Name = "Nom";
				this->dataGridViewOrders->Columns->Add(lastName);

				auto firstName = gcnew DataGridViewTextBoxColumn();
				firstName->Name = "Prenom";
				this->dataGridViewOrders->Columns->Add(firstName);

				auto birthdate = gcnew DataGridViewTextBoxColumn();
				birthdate->Visible = false;
				this->dataGridViewOrders->Columns->Add(birthdate);
				
				auto issueDate = gcnew DataGridViewTextBoxColumn();
				issueDate->Name = "Date d'emission";
				this->dataGridViewOrders->Columns->Add(issueDate);

				auto expectedDeliveryDate = gcnew DataGridViewTextBoxColumn();
				expectedDeliveryDate->Name = "Date de livraison prevue";
				this->dataGridViewOrders->Columns->Add(expectedDeliveryDate);

				auto billingAddress = gcnew DataGridViewTextBoxColumn();
				billingAddress->Visible = false;
				this->dataGridViewOrders->Columns->Add(billingAddress);

				auto deliveryAddress = gcnew DataGridViewTextBoxColumn();
				deliveryAddress->Visible = false;
				this->dataGridViewOrders->Columns->Add(deliveryAddress);
				
				auto totalAmount = gcnew DataGridViewTextBoxColumn();
				totalAmount->Name = "Montant total";
				this->dataGridViewOrders->Columns->Add(totalAmount);
				
				auto payedAmount = gcnew DataGridViewTextBoxColumn();
				payedAmount->Name = "Montant paye";
				this->dataGridViewOrders->Columns->Add(payedAmount);

				auto paymentDate = gcnew DataGridViewTextBoxColumn();
				paymentDate->Name = "Date de payement";
				this->dataGridViewOrders->Columns->Add(paymentDate);

				auto vatAmount = gcnew DataGridViewTextBoxColumn();
				vatAmount->Visible = false;
				this->dataGridViewOrders->Columns->Add(vatAmount);

				auto tfAmount = gcnew DataGridViewTextBoxColumn();
				tfAmount->Visible = false;
				this->dataGridViewOrders->Columns->Add(tfAmount);

				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->checkBoxDeleted->Location = Point(10, 60);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(10, 6, 10, 6);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(247, 29);
				this->checkBoxDeleted->TabIndex = 1;
				this->checkBoxDeleted->Text = L"Montrer les commandes\nsupprimees";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;
				this->checkBoxDeleted->CheckedChanged += gcnew EventHandler(this, &OrdersPage::checkBoxDeleted_Click);

				/*-------------------- buttonPayments --------------------*/
				this->buttonPayments->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonPayments->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonPayments->Location = Point(278, 12);
				this->buttonPayments->Margin = Windows::Forms::Padding(11, 6, 11, 6);
				this->buttonPayments->Name = L"buttonPayments";
				this->buttonPayments->Size = Drawing::Size(269, 126);
				this->buttonPayments->TabIndex = 2;
				this->buttonPayments->Text = L"Paiements";
				this->buttonPayments->UseVisualStyleBackColor = true;
				this->buttonPayments->Click += gcnew EventHandler(this, &OrdersPage::buttonPayments_Click);

				/*-------------------- buttonOrderDetails --------------------*/
				this->buttonOrderDetails->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonOrderDetails->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonOrderDetails->Location = Point(278, 12);
				this->buttonOrderDetails->Margin = Windows::Forms::Padding(11, 6, 11, 6);
				this->buttonOrderDetails->Name = L"buttonOrderDetails";
				this->buttonOrderDetails->Size = Drawing::Size(269, 126);
				this->buttonOrderDetails->TabIndex = 2;
				this->buttonOrderDetails->Text = L"Details";
				this->buttonOrderDetails->UseVisualStyleBackColor = true;
				this->buttonOrderDetails->Click += gcnew EventHandler(this, &OrdersPage::buttonOrderDetails_Click);

				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonAdd->Location = Point(595, 106);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(107, 38);
				this->buttonAdd->TabIndex = 3;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &OrdersPage::buttonAdd_Click);

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
				this->buttonEdit->Click += gcnew EventHandler(this, &OrdersPage::buttonEdit_Click);

				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonDelete->Location = Point(829, 106);
				this->buttonDelete->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(125, 38);
				this->buttonDelete->TabIndex = 5;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				this->buttonDelete->Click += gcnew EventHandler(this, &OrdersPage::buttonDelete_Click);

				/*-------------------- OrdersPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(984, 661);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"OrdersPage";
				this->Text = L"OrdersPage";
			}

			Void reloadOrdersGridView();
			Void openOrderForm();
			Void checkBoxDeleted_Click(Object^ sender, EventArgs^ e);
			Void buttonPayments_Click(Object^ sender, EventArgs^ e);
			Void buttonOrderDetails_Click(Object^ sender, EventArgs^ e);
			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
	};
}
