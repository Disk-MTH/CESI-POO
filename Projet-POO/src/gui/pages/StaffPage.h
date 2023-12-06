#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class StaffPage : public Form
	{
		public:
			StaffPage()
			{
				initialize();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;

			Label^ labelTitle;

			DataGridView^ dataGridViewStaff;
			CheckBox^ checkBoxDeleted;

			Button^ buttonAdd;
			Button^ buttonEdit;
			Button^ buttonDelete;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();

				this->dataGridViewStaff = gcnew DataGridView();

				this->checkBoxDeleted = gcnew CheckBox();

				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewStaff, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Location = Point(10, 11);
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
				this->labelTitle->Text = L"Personnel";

				/*-------------------- dataGridViewStaff --------------------*/
				this->dataGridViewStaff->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewStaff->Location = Point(11, 119);
				this->dataGridViewStaff->Margin = Windows::Forms::Padding(11, 12, 11, 12);
				this->dataGridViewStaff->Name = L"dataGridViewStaff";
				this->dataGridViewStaff->Size = Drawing::Size(941, 354);
				this->dataGridViewStaff->TabIndex = 0;
				
				/*-------------------- checkBoxDeleted --------------------*/
				this->checkBoxDeleted->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
				this->checkBoxDeleted->AutoSize = true;
				this->checkBoxDeleted->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->checkBoxDeleted->Location = Point(10, 60);
				this->checkBoxDeleted->Margin = Windows::Forms::Padding(10, 6, 10, 6);
				this->checkBoxDeleted->Name = L"checkBoxDeleted";
				this->checkBoxDeleted->Size = Drawing::Size(247, 29);
				this->checkBoxDeleted->TabIndex = 1;
				this->checkBoxDeleted->Text = L"Montrer le personnel\nsupprime";
				this->checkBoxDeleted->UseVisualStyleBackColor = true;

				/*-------------------- buttonDelete --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonAdd->Location = Point(595, 106);
				this->buttonAdd->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonAdd->Name = L"buttonDelete";
				this->buttonAdd->Size = Drawing::Size(107, 38);
				this->buttonAdd->TabIndex = 2;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonEdit->Location = Point(712, 106);
				this->buttonEdit->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(107, 38);
				this->buttonEdit->TabIndex = 3;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;

				/*-------------------- buttonAdd --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonDelete->Location = Point(829, 106);
				this->buttonDelete->Margin = Windows::Forms::Padding(5, 6, 5, 6);
				this->buttonDelete->Name = L"buttonAdd";
				this->buttonDelete->Size = Drawing::Size(125, 38);
				this->buttonDelete->TabIndex = 4;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;
				
				/*-------------------- StaffPage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(984, 661);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Margin = Windows::Forms::Padding(2);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Name = L"StaffPage";
				this->Text = L"StaffPage";
			}
	};
}
