#pragma once

using namespace Projet_POO;
using namespace Data;
using namespace System;
using namespace Drawing;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class CustomerAddressesPage sealed : public Form
	{
		public:
			CustomerAddressesPage()
			{
				initialize();
				fillGridViewDeliveryAdresses();
				fillGridViewBillingAdresses();
			}

		private:
			bool back = false;

			DataSet^ customerAdresses;

			TableLayoutPanel^ tableLayout1;
			TableLayoutPanel^ tableLayout2;
			TableLayoutPanel^ tableLayout3;

			Label^ labelTitle;

			DataGridView^ gridViewDeliveryAddresses;
			DataGridView^ gridViewBillingAddresses;

			Button^ buttonBack;
			Button^ buttonReload;
			Button^ buttonBilling;
			Button^ buttonDelivery;

			void initialize()
			{
				this->tableLayout1 = gcnew TableLayoutPanel();
				this->tableLayout2 = gcnew TableLayoutPanel();
				this->tableLayout3 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();

				this->gridViewDeliveryAddresses = gcnew DataGridView();
				this->gridViewBillingAddresses = gcnew DataGridView();

				this->buttonReload = gcnew Button();
				this->buttonBack = gcnew Button();
				this->buttonDelivery = gcnew Button();
				this->buttonBilling = gcnew Button();

				/* -------------------- tableLayout1 --------------------*/
				this->tableLayout1->ColumnCount = 2;
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->Controls->Add(this->gridViewDeliveryAddresses, 1, 0);
				this->tableLayout1->Controls->Add(this->buttonBilling, 1, 1);
				this->tableLayout1->Controls->Add(this->buttonDelivery, 0, 1);
				this->tableLayout1->Controls->Add(this->gridViewBillingAddresses, 0, 0);
				this->tableLayout1->Location = Point(3, 50);
				this->tableLayout1->Name = L"tableLayoutPanel1";
				this->tableLayout1->RowCount = 2;
				this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 84.73684F));
				this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 15.26316F));
				this->tableLayout1->Size = Drawing::Size(654, 380);
				this->tableLayout1->TabIndex = 3;

				/* -------------------- tableLayout2 --------------------*/
				this->tableLayout2->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->tableLayout2->ColumnCount = 1;
				this->tableLayout2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout2->Controls->Add(this->tableLayout3, 0, 0);
				this->tableLayout2->Controls->Add(this->tableLayout1, 0, 1);
				this->tableLayout2->Location = Point(12, 16);
				this->tableLayout2->Name = L"tableLayout1";
				this->tableLayout2->RowCount = 2;
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 386));
				this->tableLayout2->Size = Drawing::Size(660, 433);
				this->tableLayout2->TabIndex = 7;

				/* -------------------- tableLayout3 --------------------*/
				this->tableLayout3->ColumnCount = 5;
				this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 46));
				this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 468));
				this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 46));
				this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 48));
				this->tableLayout3->Controls->Add(this->buttonBack, 4, 0);
				this->tableLayout3->Controls->Add(this->buttonReload, 3, 0);
				this->tableLayout3->Controls->Add(this->labelTitle, 2, 0);
				this->tableLayout3->Location = Point(3, 3);
				this->tableLayout3->Name = L"tableLayout4";
				this->tableLayout3->RowCount = 1;
				this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
				this->tableLayout3->Size = Drawing::Size(654, 40);
				this->tableLayout3->TabIndex = 2;

				/* -------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->labelTitle->Location = Point(265, 4);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(122, 31);
				this->labelTitle->TabIndex = 9;
				this->labelTitle->Text = L"AAAAAA";

				/* -------------------- gridViewDeliveryAddresses --------------------*/
				this->gridViewDeliveryAddresses->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->gridViewDeliveryAddresses->Location = Point(337, 10);
				this->gridViewDeliveryAddresses->Margin = Windows::Forms::Padding(10);
				this->gridViewDeliveryAddresses->Name = L"dataGridView2";
				this->gridViewDeliveryAddresses->Size = Drawing::Size(307, 301);
				this->gridViewDeliveryAddresses->TabIndex = 5;

				/* -------------------- gridViewBillingAddresses --------------------*/
				this->gridViewBillingAddresses->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->gridViewBillingAddresses->Location = Point(10, 10);
				this->gridViewBillingAddresses->Margin = Windows::Forms::Padding(10);
				this->gridViewBillingAddresses->Name = L"dataGridView1";
				this->gridViewBillingAddresses->Size = Drawing::Size(307, 301);
				this->gridViewBillingAddresses->TabIndex = 4;

				/* -------------------- buttonReload --------------------*/
				this->buttonReload->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
				this->buttonReload->Location = Point(563, 3);
				this->buttonReload->Name = L"button6";
				this->buttonReload->Size = Drawing::Size(39, 34);
				this->buttonReload->TabIndex = 14;
				this->buttonReload->Text = L"( )";
				this->buttonReload->UseVisualStyleBackColor = true;
				this->buttonReload->Click += gcnew EventHandler(this, &CustomerAddressesPage::buttonReload_Click);

				/* -------------------- buttonBack --------------------*/
				this->buttonBack->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
				this->buttonBack->Location = Point(609, 3);
				this->buttonBack->Name = L"button2";
				this->buttonBack->Size = Drawing::Size(39, 34);
				this->buttonBack->TabIndex = 10;
				this->buttonBack->Text = L"-->";
				this->buttonBack->UseVisualStyleBackColor = true;
				this->buttonBack->Click += gcnew EventHandler(this, &CustomerAddressesPage::buttonBack_Click);

				/* -------------------- buttonDelivery --------------------*/
				this->buttonDelivery->Anchor = AnchorStyles::None;
				this->buttonDelivery->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonDelivery->Location = Point(121, 330);
				this->buttonDelivery->Name = L"button1";
				this->buttonDelivery->Size = Drawing::Size(307, 41);
				this->buttonDelivery->TabIndex = 0;
				this->buttonDelivery->Text = L"Ajouter adresse de livraison";
				this->buttonDelivery->UseVisualStyleBackColor = true;

				/* -------------------- buttonBilling --------------------*/
				this->buttonBilling->Anchor = AnchorStyles::None;
				this->buttonBilling->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonBilling->Location = Point(448, 330);
				this->buttonBilling->Name = L"button7";
				this->buttonBilling->Size = Drawing::Size(307, 41);
				this->buttonBilling->TabIndex = 3;
				this->buttonBilling->Text = L"Ajouter adresse de facturation";
				this->buttonBilling->UseVisualStyleBackColor = true;

				/* -------------------- CustomerAddressesPage --------------------*/
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayout2);
				this->MaximizeBox = false;
				this->Margin = Windows::Forms::Padding(2);
				this->Name = L"CustomerAddressesPage";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->Text = L"CustomerAddressesPage";
				this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerAddressesPage::customerAddressesForm_Close);
			}

			void fillGridViewDeliveryAdresses()
			{
				this->gridViewDeliveryAddresses->Columns->Clear();

				DataGridViewTextBoxColumn^ idAddress = gcnew DataGridViewTextBoxColumn();
				idAddress->Name = L"id_address";
				idAddress->Visible = false;
				this->gridViewDeliveryAddresses->Columns->Add(idAddress);

				DataGridViewTextBoxColumn^ address = gcnew DataGridViewTextBoxColumn();
				address->Name = L"address";
				this->gridViewDeliveryAddresses->Columns->Add(address);

				DataGridViewTextBoxColumn^ city = gcnew DataGridViewTextBoxColumn();
				city->Name = L"city";
				this->gridViewDeliveryAddresses->Columns->Add(city);

				DataGridViewTextBoxColumn^ zipCode = gcnew DataGridViewTextBoxColumn();
				zipCode->Name = L"zip_code";
				this->gridViewDeliveryAddresses->Columns->Add(zipCode);

				DataGridViewTextBoxColumn^ country = gcnew DataGridViewTextBoxColumn();
				country->Name = L"country";
				this->gridViewDeliveryAddresses->Columns->Add(country);

				this->gridViewDeliveryAddresses->Rows->Add("1", "18 rue charcuterie", "Toulouses", "83000", "France");
			}

			void fillGridViewBillingAdresses()
			{
				this->gridViewBillingAddresses->Columns->Clear();

				DataGridViewTextBoxColumn^ idAddress = gcnew DataGridViewTextBoxColumn();
				idAddress->Name = L"id_address";
				idAddress->Visible = false;
				this->gridViewBillingAddresses->Columns->Add(idAddress);

				DataGridViewTextBoxColumn^ address = gcnew DataGridViewTextBoxColumn();
				address->Name = L"address";
				this->gridViewBillingAddresses->Columns->Add(address);

				DataGridViewTextBoxColumn^ city = gcnew DataGridViewTextBoxColumn();
				city->Name = L"city";
				this->gridViewBillingAddresses->Columns->Add(city);

				DataGridViewTextBoxColumn^ zipCode = gcnew DataGridViewTextBoxColumn();
				zipCode->Name = L"zip_code";
				this->gridViewBillingAddresses->Columns->Add(zipCode);

				DataGridViewTextBoxColumn^ country = gcnew DataGridViewTextBoxColumn();
				country->Name = L"country";
				this->gridViewBillingAddresses->Columns->Add(country);

				this->gridViewBillingAddresses->Rows->Add("1", "25 rue choucroute", "Paris", "75000", "France");
			}

			void customerAddressesForm_Close(Object^ sender, FormClosingEventArgs^ e)
			{
				if (!this->back)
				{
					Application::Exit();
				}
			}

			void buttonBack_Click(Object^ sender, EventArgs^ e)
			{
				this->back = true;
				this->Close();
			}

			void buttonReload_Click(Object^ sender, EventArgs^ e)
			{
				fillGridViewDeliveryAdresses();
				fillGridViewBillingAdresses();
				App::app->toastMessage(this, "Donnees actualisees", Color::Green, 3000);
				App::app->logger->log("Data reloaded");
			}
	};
}
