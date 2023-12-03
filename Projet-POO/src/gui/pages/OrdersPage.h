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
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;

			Label^ labelTitle;
		
			DataGridView^ dataGridViewOrders;
		
			CheckBox^ checkBoxDeleted;

			Button^ buttonOrderDetails;
			Button^ buttonEdit;
			Button^ buttonAdd;
			Button^ buttonDelete;
		
			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				
				this->labelTitle = gcnew Label();
				
				this->dataGridViewOrders = gcnew DataGridView();
				
				this->checkBoxDeleted = gcnew CheckBox();
				
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
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 17.52768F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 82.47233F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 90));
				this->tableLayoutPanel1->Size = Drawing::Size(959, 636);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 5;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 60.46128F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 39.53872F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 107));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 118));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 123));
				this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 3, 0);
				this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 2, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 4, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonOrderDetails, 1, 0);
				this->tableLayoutPanel2->Location = Point(3, 548);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(953, 85);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(374, 28);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(210, 39);
				this->labelTitle->Text = L"Commandes";
				
				/*-------------------- dataGridViewOrders --------------------*/
				this->dataGridViewOrders->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewOrders->Location = Point(15, 110);
				this->dataGridViewOrders->Margin = Windows::Forms::Padding(15);
				this->dataGridViewOrders->Name = L"dataGridViewOrders";
				this->dataGridViewOrders->Size = Drawing::Size(929, 420);
				this->dataGridViewOrders->TabIndex = 0;
				
				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::Left;
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->checkBoxDeleted->Location = Point(10, 28);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(10, 3, 3, 3);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(346, 29);
				this->checkBoxDeleted->TabIndex = 1;
				this->checkBoxDeleted->Text = L"Montrer les commandes supprimees";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;

				/*-------------------- buttonOrderDetails --------------------*/
				this->buttonOrderDetails->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonOrderDetails->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonOrderDetails->Location = Point(375, 10);
				this->buttonOrderDetails->Margin = Windows::Forms::Padding(10);
				this->buttonOrderDetails->Name = L"buttonOrderDetails";
				this->buttonOrderDetails->Size = Drawing::Size(219, 65);
				this->buttonOrderDetails->TabIndex = 2;
				this->buttonOrderDetails->Text = L"Details";
				this->buttonOrderDetails->UseVisualStyleBackColor = true;
				
				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonAdd->Location = Point(618, 43);
				this->buttonAdd->Margin = Windows::Forms::Padding(7);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(86, 35);
				this->buttonAdd->TabIndex = 3;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonEdit->Location = Point(721, 43);
				this->buttonEdit->Margin = Windows::Forms::Padding(7);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(101, 35);
				this->buttonEdit->TabIndex = 4;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;

				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonDelete->Location = Point(836, 43);
				this->buttonDelete->Margin = Windows::Forms::Padding(7);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(110, 35);
				this->buttonDelete->TabIndex = 5;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				
				/*-------------------- OrdersPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(984, 661);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"OrdersPage";
				this->Text = L"OrdersPage";
			}
	};
}
