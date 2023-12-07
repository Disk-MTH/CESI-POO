#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class CustomersPage : public Form
	{
		public:
			CustomersPage()
			{
				initialize();
				reloadCustomersGridView();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;

			Label^ labelTitle;

			DataGridView^ dataGridViewCustomers;

			CheckBox^ checkBoxDeleted;

			Button^ buttonCreateOrder;
			Button^ buttonAdd;
			Button^ buttonEdit;
			Button^ buttonDelete;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();

				this->dataGridViewCustomers = gcnew DataGridView();

				this->checkBoxDeleted = gcnew CheckBox();

				this->buttonCreateOrder = gcnew Button();
				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewCustomers, 0, 1);
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
				this->tableLayoutPanel2->Controls->Add(this->buttonCreateOrder, 1, 0);
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
				this->labelTitle->Text = L"Clients";

				/*-------------------- dataGridViewCustomers --------------------*/
				this->dataGridViewCustomers->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewCustomers->Location = Point(11, 119);
				this->dataGridViewCustomers->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->dataGridViewCustomers->Name = L"dataGridViewCustomers";
				this->dataGridViewCustomers->Size = Drawing::Size(941, 354);
				this->dataGridViewCustomers->TabIndex = 0;
				this->dataGridViewCustomers->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->dataGridViewCustomers->ReadOnly = true;
				this->dataGridViewCustomers->AllowUserToResizeRows = false;
				this->dataGridViewCustomers->AllowUserToAddRows = false;
				this->dataGridViewCustomers->RowHeadersVisible = false;
				this->dataGridViewCustomers->AllowUserToDeleteRows = false;
				this->dataGridViewCustomers->MultiSelect = false;
				this->dataGridViewCustomers->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->dataGridViewCustomers->DefaultCellStyle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 12.5);
				this->dataGridViewCustomers->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
				this->dataGridViewCustomers->ColumnHeadersHeight = 40;

				auto idCustomer = gcnew DataGridViewTextBoxColumn();
				idCustomer->Visible = false;
				this->dataGridViewCustomers->Columns->Add(idCustomer);

				auto lastName = gcnew DataGridViewTextBoxColumn();
				lastName->Name = L"Nom";
				lastName->Resizable = DataGridViewTriState::False;
				this->dataGridViewCustomers->Columns->Add(lastName);
				
				auto firstName = gcnew DataGridViewTextBoxColumn();
				firstName->Name = L"Prenom";
				firstName->Resizable = DataGridViewTriState::False;
				this->dataGridViewCustomers->Columns->Add(firstName);

				auto birthdate = gcnew DataGridViewTextBoxColumn();
				birthdate->Name = L"Date de naissance";
				birthdate->Resizable = DataGridViewTriState::False;
				this->dataGridViewCustomers->Columns->Add(birthdate);
				
				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->checkBoxDeleted->Location = Point(10, 60);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(10, 6, 10, 6);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(247, 29);
				this->checkBoxDeleted->TabIndex = 1;
				this->checkBoxDeleted->Text = L"Afficher les clients\nsupprimes";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;
				this->checkBoxDeleted->Click += gcnew EventHandler(this, &CustomersPage::checkBoxDeleted_Click);

				/*-------------------- buttonCreateOrder --------------------*/
				this->buttonCreateOrder->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCreateOrder->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonCreateOrder->Location = Point(278, 12);
				this->buttonCreateOrder->Margin = Windows::Forms::Padding(11, 6, 11, 6);
				this->buttonCreateOrder->Name = L"buttonCreateOrder";
				this->buttonCreateOrder->Size = Drawing::Size(269, 126);
				this->buttonCreateOrder->TabIndex = 2;
				this->buttonCreateOrder->Text = L"Commander";
				this->buttonCreateOrder->UseVisualStyleBackColor = true;
				this->buttonCreateOrder->Click += gcnew EventHandler(this, &CustomersPage::buttonCreateOrder_Click);

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
				this->buttonAdd->Click += gcnew EventHandler(this, &CustomersPage::buttonAdd_Click);

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
				this->buttonEdit->Click += gcnew EventHandler(this, &CustomersPage::buttonEdit_Click);

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
				this->buttonDelete->Click += gcnew EventHandler(this, &CustomersPage::buttonDelete_Click);

				/*-------------------- CustomersPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(984, 661);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Name = L"CustomersPage";
				this->Text = L"CustomersPage";
			}

			Void reloadCustomersGridView();
			Void openCustomerForm(String^ customerId, String^ lastName, String^ firstName, String^ birthdate);
			Void checkBoxDeleted_Click(Object^ sender, EventArgs^ e);
			Void buttonCreateOrder_Click(Object^ sender, EventArgs^ e);
			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
	};
}
