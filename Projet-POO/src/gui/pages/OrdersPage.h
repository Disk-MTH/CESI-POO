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
			Button^ buttonAdd;
			Button^ buttonEdit;
			Button^ buttonDelete;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->labelTitle = gcnew Label();
				this->dataGridViewOrders = gcnew DataGridView();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				this->checkBoxDeleted = gcnew CheckBox();
				this->buttonOrderDetails = gcnew Button();
				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewOrders, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Location = Point(10, 10);
				this->tableLayoutPanel1->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 22.1519F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 77.8481F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 124));
				this->tableLayoutPanel1->Size = Drawing::Size(718, 510);
				this->tableLayoutPanel1->TabIndex = 1;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 6;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 183));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 34));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 91));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 96));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 117));
				this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonOrderDetails, 1, 0);
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
				this->labelTitle->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 25));
				this->labelTitle->Location = Point(254, 23);
				this->labelTitle->Margin = Windows::Forms::Padding(2, 0, 2, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(210, 39);
				this->labelTitle->TabIndex = 0;
				this->labelTitle->Text = L"Commandes";

				/*-------------------- dataGridViewOrders --------------------*/
				this->dataGridViewOrders->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewOrders->Location = Point(11, 97);
				this->dataGridViewOrders->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->dataGridViewOrders->Name = L"dataGridViewOrders";
				this->dataGridViewOrders->RowHeadersWidth = 51;
				this->dataGridViewOrders->RowTemplate->Height = 24;
				this->dataGridViewOrders->Size = Drawing::Size(695, 275);
				this->dataGridViewOrders->TabIndex = 1;

				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::None;
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Location = Point(2, 51);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(188, 17);
				this->checkBoxDeleted->TabIndex = 0;
				this->checkBoxDeleted->Text = L"Afficher les commandes supprim�es";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;

				/*-------------------- buttonOrderDetails --------------------*/
				this->buttonOrderDetails->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonOrderDetails->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 20));
				this->buttonOrderDetails->Location = Point(203, 12);
				this->buttonOrderDetails->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->buttonOrderDetails->Name = L"buttonOrderDetails";
				this->buttonOrderDetails->Size = Drawing::Size(161, 96);
				this->buttonOrderDetails->TabIndex = 1;
				this->buttonOrderDetails->Text = L"Details ";
				this->buttonOrderDetails->UseVisualStyleBackColor = true;
	
				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 13);
				this->buttonAdd->Location = Point(414, 76);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(81, 38);
				this->buttonAdd->TabIndex = 2;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
		
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
	
				/*-------------------- OrdersPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(736, 531);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2, 2, 2, 2);
				this->Name = L"OrdersPage";
				this->Text = L"OrdersPage";
			}
	};
}
