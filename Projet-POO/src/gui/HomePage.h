#pragma once
#include "CustomerPage.h"

namespace Projet_POO {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class HomePage : public Form
	{
		public:
			HomePage(Database^ db)
			{
				InitializeComponent();
				this->db = db;
			}

		protected:
			~HomePage()
			{
				if (components)
				{
					delete components;
				}
			}
		
		Database^ db;
		TableLayoutPanel^ tableLayoutPanel1;
		Label^ labelTitle;
		TableLayoutPanel^ tableLayoutPanel2;
		Button^ buttonCustomers;
		Button^ buttonStats;
		Button^ buttonStocks;
		Button^ buttonOrders;
		Button^ buttonStaff;
		System::ComponentModel::Container ^components;
		
		void InitializeComponent()
		{
			/* -------------------- instantiation -------------------- */
			this->tableLayoutPanel1 = gcnew TableLayoutPanel();
			this->buttonStats = gcnew Button();
			this->labelTitle = gcnew Label();
			this->tableLayoutPanel2 = gcnew TableLayoutPanel();
			this->buttonStocks = gcnew Button();
			this->buttonOrders = gcnew Button();
			this->buttonStaff = gcnew Button();
			this->buttonCustomers = gcnew Button();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
	
			/* -------------------- tableLayoutPanel1 -------------------- */
			this->tableLayoutPanel1->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel1->Controls->Add(this->buttonStats, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Location = Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 243));
			this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 105));
			this->tableLayoutPanel1->Size = Drawing::Size(660, 437);
			this->tableLayoutPanel1->TabIndex = 0;
	
			/* -------------------- buttonStats -------------------- */
			this->buttonStats->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->buttonStats->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
			this->buttonStats->Location = Point(10, 342);
			this->buttonStats->Margin = Windows::Forms::Padding(10);
			this->buttonStats->Name = L"buttonStats";
			this->buttonStats->Size = Drawing::Size(640, 85);
			this->buttonStats->TabIndex = 2;
			this->buttonStats->Text = L"Statistiques";
			this->buttonStats->UseVisualStyleBackColor = true;

			/* -------------------- labelTitle -------------------- */
			this->labelTitle->Anchor = AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
			this->labelTitle->Location = Point(234, 25);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = Drawing::Size(192, 39);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Projet-POO";

			/* -------------------- tableLayoutPanel2 -------------------- */
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->Controls->Add(this->buttonStocks, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->buttonOrders, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->buttonStaff, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonCustomers, 0, 0);
			this->tableLayoutPanel2->Location = Point(3, 92);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 20));
			this->tableLayoutPanel2->Size = Drawing::Size(654, 237);
			this->tableLayoutPanel2->TabIndex = 1;

			/* -------------------- buttonStocks -------------------- */
			this->buttonStocks->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->buttonStocks->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->buttonStocks->Location = Point(337, 128);
			this->buttonStocks->Margin = Windows::Forms::Padding(10);
			this->buttonStocks->Name = L"buttonStocks";
			this->buttonStocks->Size = Drawing::Size(307, 99);
			this->buttonStocks->TabIndex = 3;
			this->buttonStocks->Text = L"Stocks";
			this->buttonStocks->UseVisualStyleBackColor = true;

			/* -------------------- buttonOrders -------------------- */
			this->buttonOrders->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->buttonOrders->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->buttonOrders->Location = Point(10, 128);
			this->buttonOrders->Margin = Windows::Forms::Padding(10);
			this->buttonOrders->Name = L"buttonOrders";
			this->buttonOrders->Size = Drawing::Size(307, 99);
			this->buttonOrders->TabIndex = 2;
			this->buttonOrders->Text = L"Commandes";
			this->buttonOrders->UseVisualStyleBackColor = true;
			
			/* -------------------- buttonStaff -------------------- */
			this->buttonStaff->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->buttonStaff->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->buttonStaff->Location = Point(337, 10);
			this->buttonStaff->Margin = Windows::Forms::Padding(10);
			this->buttonStaff->Name = L"buttonStaff";
			this->buttonStaff->Size = Drawing::Size(307, 98);
			this->buttonStaff->TabIndex = 1;
			this->buttonStaff->Text = L"Personnel";
			this->buttonStaff->UseVisualStyleBackColor = true;

			/* -------------------- buttonCustomers -------------------- */
			this->buttonCustomers->Anchor = AnchorStyles::Top |AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->buttonCustomers->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->buttonCustomers->Location = Point(10, 10);
			this->buttonCustomers->Margin = Windows::Forms::Padding(10);
			this->buttonCustomers->Name = L"buttonCustomers";
			this->buttonCustomers->Size = Drawing::Size(307, 98);
			this->buttonCustomers->TabIndex = 0;
			this->buttonCustomers->Text = L"Clients";
			this->buttonCustomers->UseVisualStyleBackColor = true;
			this->buttonCustomers->Click += gcnew EventHandler(this, &HomePage::button_customers_Click);

			/* -------------------- window -------------------- */
			this->AutoScaleDimensions = SizeF(6, 13);
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->Name = L"HomePage";
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = L"HomePage";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
		}

		Void button_customers_Click(Object^ sender, EventArgs^ e) {
			CustomerPage^ customerPage = gcnew CustomerPage(db);
			this->Hide();
			customerPage->ShowDialog();
			this->Show();
		}
	};
}
