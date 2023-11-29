#pragma once
#include "../../App.h"

using namespace Projet_POO;
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
				this->labelTitle = gcnew Label();
				this->dataGridViewCustomers = gcnew DataGridView();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
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
				this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 22.1519F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 77.8481F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 124));
				this->tableLayoutPanel1->Size = Drawing::Size(718, 510);
				this->tableLayoutPanel1->TabIndex = 0;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 6;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 196));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 47));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 91));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 95));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 117));
				this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonCreateOrder, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 3, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 4, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 5, 0);
				this->tableLayoutPanel2->Location = Point(2, 387);
				this->tableLayoutPanel2->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(713, 120);
				this->tableLayoutPanel2->TabIndex = 2;

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(298, 23);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(122, 39);
				this->labelTitle->TabIndex = 0;
				this->labelTitle->Text = L"Clients";

				/*-------------------- dataGridViewCustomers --------------------*/
				this->dataGridViewCustomers->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewCustomers->Location = Point(11, 97);
				this->dataGridViewCustomers->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->dataGridViewCustomers->Name = L"dataGridViewCustomers";
				this->dataGridViewCustomers->RowHeadersWidth = 51;
				this->dataGridViewCustomers->RowTemplate->Height = 24;
				this->dataGridViewCustomers->Size = Drawing::Size(695, 275);
				this->dataGridViewCustomers->TabIndex = 1;

				auto idCustomer = gcnew DataGridViewTextBoxColumn();
				idCustomer->Name = L"id_customer";
				idCustomer->Visible = false;
				this->dataGridViewCustomers->Columns->Add(idCustomer);

				auto lastName = gcnew DataGridViewTextBoxColumn();
				lastName->Name = L"Nom";
				this->dataGridViewCustomers->Columns->Add(lastName);

				auto firstName = gcnew DataGridViewTextBoxColumn();
				firstName->Name = L"Prenom";
				this->dataGridViewCustomers->Columns->Add(firstName);

				auto birthdate = gcnew DataGridViewTextBoxColumn();
				birthdate->Name = L"Date de naissance";
				this->dataGridViewCustomers->Columns->Add(birthdate);

				auto addressesCount = gcnew DataGridViewTextBoxColumn();
				addressesCount->Name = L"Nombre d'adresses";
				addressesCount->ReadOnly = true;
				this->dataGridViewCustomers->Columns->Add(addressesCount);

				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::None;
				this->checkBoxDeleted->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 10);
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Location = Point(3, 51);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(161, 17);
				this->checkBoxDeleted->TabIndex = 0;
				this->checkBoxDeleted->Text = L"Afficher les\nclients supprimes";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;

				/*-------------------- buttonCreateOrder --------------------*/
				this->buttonCreateOrder->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCreateOrder->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonCreateOrder->Location = Point(178, 12);
				this->buttonCreateOrder->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->buttonCreateOrder->Name = L"buttonCreateOrder";
				this->buttonCreateOrder->Size = Drawing::Size(174, 96);
				this->buttonCreateOrder->TabIndex = 1;
				this->buttonCreateOrder->Text = L"Commander";
				this->buttonCreateOrder->UseVisualStyleBackColor = true;
				this->buttonCreateOrder->Click += gcnew EventHandler(this, &CustomersPage::buttonCreateOrder_Click);

				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
				this->buttonAdd->Location = Point(415, 76);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(81, 38);
				this->buttonAdd->TabIndex = 2;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &CustomersPage::buttonAdd_Click);

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
				this->buttonEdit->Location = Point(506, 76);
				this->buttonEdit->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(85, 38);
				this->buttonEdit->TabIndex = 3;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;
				this->buttonEdit->Click += gcnew EventHandler(this, &CustomersPage::buttonEdit_Click);

				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
				this->buttonDelete->Location = Point(601, 76);
				this->buttonDelete->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(107, 38);
				this->buttonDelete->TabIndex = 4;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				this->buttonDelete->Click += gcnew EventHandler(this, &CustomersPage::buttonDelete_Click);

				/*-------------------- checkBoxDeleted --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(736, 531);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->MaximizeBox = false;
				this->Name = L"CustomersPage";
				this->Text = L"CustomersPage";
			}
			Void reloadCustomersGridView();
			Void buttonCreateOrder_Click(Object^ sender, EventArgs^ e);
			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
	};
}