#pragma once
#include "../../App.h"

using namespace Projet_POO;
using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class HomePage : public Form
	{
		public:
			HomePage()
			{
				initialize();
			}

		private:
			TableLayoutPanel^ tableLayoutPanel1;
			TableLayoutPanel^ tableLayoutPanel2;

			Label^ labelTitle;

			Button^ buttonCustomers;
			Button^ buttonStaff;
			Button^ buttonCatalog;
			Button^ buttonStats;
			Button^ buttonOrders;

			void initialize()
			{
				this->tableLayoutPanel1 = gcnew TableLayoutPanel();
				this->tableLayoutPanel2 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();

				this->buttonCustomers = gcnew Button();
				this->buttonStaff = gcnew Button();
				this->buttonCatalog = gcnew Button();
				this->buttonStats = gcnew Button();
				this->buttonOrders = gcnew Button();

				/*-------------------- tableLayoutPanel1 --------------------*/
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel1->Controls->Add(this->buttonOrders, 0, 2);
				this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Location = Point(13, 13);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 3;
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 22.1519F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 77.8481F));
				this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 153));
				this->tableLayoutPanel1->Size = Drawing::Size(957, 628);
				this->tableLayoutPanel1->TabIndex = 0;

				/*-------------------- tableLayoutPanel2 --------------------*/
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Controls->Add(this->buttonStats, 1, 1);
				this->tableLayoutPanel2->Controls->Add(this->buttonStaff, 0, 1);
				this->tableLayoutPanel2->Controls->Add(this->buttonCatalog, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->buttonCustomers, 0, 0);
				this->tableLayoutPanel2->Location = Point(3, 108);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 2;
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayoutPanel2->Size = Drawing::Size(951, 363);
				this->tableLayoutPanel2->TabIndex = 1;

				/*-------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 30);
				this->labelTitle->Location = Point(338, 23);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(280, 58);
				this->labelTitle->TabIndex = 0;
				this->labelTitle->Text = L"Projet POO";

				/*-------------------- buttonCustomers --------------------*/
				this->buttonCustomers->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCustomers->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonCustomers->Location = Point(20, 20);
				this->buttonCustomers->Margin = Windows::Forms::Padding(20);
				this->buttonCustomers->Name = L"buttonCustomers";
				this->buttonCustomers->Size = Drawing::Size(435, 141);
				this->buttonCustomers->TabIndex = 0;
				this->buttonCustomers->Text = L"Clients";
				this->buttonCustomers->UseVisualStyleBackColor = true;
				this->buttonCustomers->Click += gcnew EventHandler(this, &HomePage::buttonCustomers_Click);

				/*-------------------- buttonStaff --------------------*/
				this->buttonStaff->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonStaff->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonStaff->Location = Point(20, 201);
				this->buttonStaff->Margin = Windows::Forms::Padding(20);
				this->buttonStaff->Name = L"buttonStaff";
				this->buttonStaff->Size = Drawing::Size(435, 142);
				this->buttonStaff->TabIndex = 2;
				this->buttonStaff->Text = L"Personnel";
				this->buttonStaff->UseVisualStyleBackColor = true;
				this->buttonStaff->Click += gcnew EventHandler(this, &HomePage::buttonStaff_Click);

				/*-------------------- buttonCatalog --------------------*/
				this->buttonCatalog->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonCatalog->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonCatalog->Location = Point(495, 20);
				this->buttonCatalog->Margin = Windows::Forms::Padding(20);
				this->buttonCatalog->Name = L"buttonCatalog";
				this->buttonCatalog->Size = Drawing::Size(436, 141);
				this->buttonCatalog->TabIndex = 1;
				this->buttonCatalog->Text = L"Catalogue";
				this->buttonCatalog->UseVisualStyleBackColor = true;
				this->buttonCatalog->Click += gcnew EventHandler(this, &HomePage::buttonCatalog_Click);

				/*-------------------- buttonStats --------------------*/
				this->buttonStats->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonStats->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->buttonStats->Location = Point(495, 201);
				this->buttonStats->Margin = Windows::Forms::Padding(20);
				this->buttonStats->Name = L"buttonStats";
				this->buttonStats->Size = Drawing::Size(436, 142);
				this->buttonStats->TabIndex = 3;
				this->buttonStats->Text = L"Statistiques";
				this->buttonStats->UseVisualStyleBackColor = true;
				this->buttonStats->Click += gcnew EventHandler(this, &HomePage::buttonStats_Click);

				/*-------------------- buttonOrders --------------------*/
				this->buttonOrders->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->buttonOrders->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
				this->buttonOrders->Location = Point(20, 494);
				this->buttonOrders->Margin = Windows::Forms::Padding(20);
				this->buttonOrders->Name = L"buttonOrders";
				this->buttonOrders->Size = Drawing::Size(917, 114);
				this->buttonOrders->TabIndex = 2;
				this->buttonOrders->Text = L"Commandes";
				this->buttonOrders->UseVisualStyleBackColor = true;
				this->buttonOrders->Click += gcnew EventHandler(this, &HomePage::buttonOrders_Click);

				/*-------------------- HomePage --------------------*/
				this->StartPosition = FormStartPosition::CenterScreen;
				this->AutoScaleDimensions = SizeF(8, 16);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(982, 653);
				this->Controls->Add(this->tableLayoutPanel1);
				this->MaximizeBox = false;
				this->Name = L"HomePage";
				this->Text = L"HomePage";
			}

			Void buttonCustomers_Click(Object^ sender, EventArgs^ e);
			Void buttonStaff_Click(Object^ sender, EventArgs^ e);
			Void buttonCatalog_Click(Object^ sender, EventArgs^ e);
			Void buttonStats_Click(Object^ sender, EventArgs^ e);
			Void buttonOrders_Click(Object^ sender, EventArgs^ e);
	};
}
