#pragma once

using namespace Data;
using namespace System;
using namespace Drawing;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class HomePage sealed : public Form
	{
		public:
			HomePage()
			{
				initialize();
			}

		private:
			TableLayoutPanel^ tableLayout1;
			TableLayoutPanel^ tableLayout2;

			Label^ labelTitle;

			Button^ buttonStats;
			Button^ buttonAddresses;
			Button^ buttonCustomers;
			Button^ buttonStocks;
			Button^ buttonStaff;
			Button^ buttonOrders;

			void initialize()
			{
				this->tableLayout1 = (gcnew TableLayoutPanel());
				this->tableLayout2 = (gcnew TableLayoutPanel());
				this->labelTitle = (gcnew Label());
				this->buttonCustomers = (gcnew Button());
				this->buttonOrders = (gcnew Button());
				this->buttonStaff = (gcnew Button());
				this->buttonStocks = (gcnew Button());
				this->buttonAddresses = (gcnew Button());
				this->buttonStats = (gcnew Button());
				this->tableLayout1->SuspendLayout();
				this->tableLayout2->SuspendLayout();
				this->SuspendLayout();
				// 
				// tableLayoutPanel1
				// 
				this->tableLayout1->ColumnCount = 1;
				this->tableLayout1->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayout1->Controls->Add(this->tableLayout2, 0, 1);
				this->tableLayout1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayout1->Location = Point(12, 12);
				this->tableLayout1->Name = L"tableLayoutPanel1";
				this->tableLayout1->RowCount = 2;
				this->tableLayout1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 20.36613F)));
				this->tableLayout1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 79.63387F)));
				this->tableLayout1->Size = Drawing::Size(660, 437);
				this->tableLayout1->TabIndex = 0;
				// 
				// tableLayoutPanel2
				// 
				this->tableLayout2->ColumnCount = 2;
				this->tableLayout2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayout2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayout2->Controls->Add(this->buttonStats, 1, 2);
				this->tableLayout2->Controls->Add(this->buttonAddresses, 0, 2);
				this->tableLayout2->Controls->Add(this->buttonStocks, 1, 1);
				this->tableLayout2->Controls->Add(this->buttonStaff, 0, 1);
				this->tableLayout2->Controls->Add(this->buttonOrders, 1, 0);
				this->tableLayout2->Controls->Add(this->buttonCustomers, 0, 0);
				this->tableLayout2->Location = Point(3, 92);
				this->tableLayout2->Name = L"tableLayoutPanel2";
				this->tableLayout2->RowCount = 3;
				this->tableLayout2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 46.84685F)));
				this->tableLayout2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 53.15315F)));
				this->tableLayout2->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 110)));
				this->tableLayout2->Size = Drawing::Size(654, 342);
				this->tableLayout2->TabIndex = 0;
				// 
				// label1
				// 
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 25));
				this->labelTitle->Location = Point(235, 25);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(190, 39);
				this->labelTitle->TabIndex = 1;
				this->labelTitle->Text = L"Projet POO";
				// 
				// buttonCustomers
				// 
				this->buttonCustomers->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCustomers->Location = Point(15, 15);
				this->buttonCustomers->Margin = Windows::Forms::Padding(15);
				this->buttonCustomers->Name = L"buttonCustomers";
				this->buttonCustomers->Size = Drawing::Size(297, 78);
				this->buttonCustomers->TabIndex = 0;
				this->buttonCustomers->Text = L"buttonCustomers";
				this->buttonCustomers->UseVisualStyleBackColor = true;
				// 
				// buttonOrders
				// 
				this->buttonOrders->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonOrders->Location = Point(342, 15);
				this->buttonOrders->Margin = Windows::Forms::Padding(15);
				this->buttonOrders->Name = L"buttonOrders";
				this->buttonOrders->Size = Drawing::Size(297, 78);
				this->buttonOrders->TabIndex = 1;
				this->buttonOrders->Text = L"buttonOrders";
				this->buttonOrders->UseVisualStyleBackColor = true;
				// 
				// buttonStaff
				// 
				this->buttonStaff->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonStaff->Location = Point(15, 123);
				this->buttonStaff->Margin = Windows::Forms::Padding(15);
				this->buttonStaff->Name = L"buttonStaff";
				this->buttonStaff->Size = Drawing::Size(297, 93);
				this->buttonStaff->TabIndex = 2;
				this->buttonStaff->Text = L"buttonStaff";
				this->buttonStaff->UseVisualStyleBackColor = true;
				// 
				// buttonStocks
				// 
				this->buttonStocks->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonStocks->Location = Point(342, 123);
				this->buttonStocks->Margin = Windows::Forms::Padding(15);
				this->buttonStocks->Name = L"buttonStocks";
				this->buttonStocks->Size = Drawing::Size(297, 93);
				this->buttonStocks->TabIndex = 3;
				this->buttonStocks->Text = L"buttonStocks";
				this->buttonStocks->UseVisualStyleBackColor = true;
				// 
				// buttonAddresses
				// 
				this->buttonAddresses->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonAddresses->Location = Point(15, 246);
				this->buttonAddresses->Margin = Windows::Forms::Padding(15);
				this->buttonAddresses->Name = L"buttonAddresses";
				this->buttonAddresses->Size = Drawing::Size(297, 81);
				this->buttonAddresses->TabIndex = 4;
				this->buttonAddresses->Text = L"buttonAddresses";
				this->buttonAddresses->UseVisualStyleBackColor = true;
				// 
				// buttonStats
				// 
				this->buttonStats->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonStats->Location = Point(342, 246);
				this->buttonStats->Margin = Windows::Forms::Padding(15);
				this->buttonStats->Name = L"buttonStats";
				this->buttonStats->Size = Drawing::Size(297, 81);
				this->buttonStats->TabIndex = 5;
				this->buttonStats->Text = L"buttonStats";
				this->buttonStats->UseVisualStyleBackColor = true;
				// 
				// HomePage1
				// 
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayout1);
				this->MaximizeBox = false;
				this->Name = L"HomePage1";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->Text = L"HomePage1";
				this->Load += gcnew EventHandler(this, &HomePage::HomePage_Load);
				this->tableLayout1->ResumeLayout(false);
				this->tableLayout1->PerformLayout();
				this->tableLayout2->ResumeLayout(false);
				this->ResumeLayout(false);

			}

			Void HomePage_Load(Object^ sender, EventArgs^ e)
			{
			}
	};
}
