#pragma once

using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class PaymentsForm : public Form
	{
		public:
			PaymentsForm()
			{
				initialize();
				reloadPaymentsGridView();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;
		
			Label^ labelTitle;
		
			DataGridView^ dataGridViewPaymentsDetails;

			Button^ buttonAdd;
			Button^ buttonEdit;
			Button^ buttonDelete;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();
				
				this->labelTitle = gcnew Label();
				
				this->dataGridViewPaymentsDetails = gcnew DataGridView();
				
				this->buttonAdd = gcnew Button();
				this->buttonEdit = gcnew Button();
				this->buttonDelete = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->dataGridViewPaymentsDetails, 0, 1);
				this->tableLayoutPanel1->Location = Point(13, 13);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 17.52022F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 82.47978F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 67));
				this->tableLayoutPanel1->Size = Drawing::Size(659, 436);

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 3;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 79.80952F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 20.19048F));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 127));
				this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 2, 0);
				this->tableLayoutPanel2->Location = Point(3, 371);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(653, 62);

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->labelTitle->Location = Point(101, 12);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(457, 39);
				this->labelTitle->Text = L"Details des payements : REF";
				
				/*-------------------- dataGridViewPaymentsDetails --------------------*/
				this->dataGridViewPaymentsDetails->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridViewPaymentsDetails->Location = Point(3, 67);
				this->dataGridViewPaymentsDetails->Name = L"dataGridViewPaymentsDetails";
				this->dataGridViewPaymentsDetails->Size = Drawing::Size(653, 298);
				this->dataGridViewPaymentsDetails->TabIndex = 0;

				/*-------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonAdd->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonAdd->Location = Point(320, 22);
				this->buttonAdd->Margin = Windows::Forms::Padding(7);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(92, 33);
				this->buttonAdd->TabIndex = 1;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;

				/*-------------------- buttonEdit --------------------*/
				this->buttonEdit->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonEdit->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonEdit->Location = Point(426, 22);
				this->buttonEdit->Margin = Windows::Forms::Padding(7);
				this->buttonEdit->Name = L"buttonEdit";
				this->buttonEdit->Size = Drawing::Size(92, 33);
				this->buttonEdit->TabIndex = 2;
				this->buttonEdit->Text = L"Modifier";
				this->buttonEdit->UseVisualStyleBackColor = true;

				/*-------------------- buttonDelete --------------------*/
				this->buttonDelete->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
				this->buttonDelete->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->buttonDelete->Location = Point(532, 22);
				this->buttonDelete->Margin = Windows::Forms::Padding(7);
				this->buttonDelete->Name = L"buttonDelete";
				this->buttonDelete->Size = Drawing::Size(114, 33);
				this->buttonDelete->TabIndex = 3;
				this->buttonDelete->Text = L"Supprimer";
				this->buttonDelete->UseVisualStyleBackColor = true;

				/*-------------------- PaymentsForm --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
				this->MaximizeBox = false;
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"PaymentsForm";
				this->Text = L"PaymentsForm";
			}

			Void reloadPaymentsGridView();
			Void buttonAdd_Click(Object^ sender, EventArgs^ e);
			Void buttonEdit_Click(Object^ sender, EventArgs^ e);
			Void buttonDelete_Click(Object^ sender, EventArgs^ e);
	};
}