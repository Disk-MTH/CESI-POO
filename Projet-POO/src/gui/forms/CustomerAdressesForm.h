#pragma once

using namespace Projet_POO;
using namespace Data;
using namespace System;
using namespace Drawing;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class CustomerAddressesForm : public System::Windows::Forms::Form
	{
		public:
			CustomerAddressesForm()
			{
				initialize();
				fillDeliveryAdressesGridView();
				fillBillingAdressesGridView();
			}

		private:

			bool back = false;
		
			DataSet^ customerAdresses;

			TableLayoutPanel^ tableLayout1;
			TableLayoutPanel^ tableLayout2;
			TableLayoutPanel^ tableLayout3;

			Label^ labelTitle;

			DataGridView^ BillingAdressGridView;
			DataGridView^ DeliveryAdressGridView;

			Button^ buttonDelivery;
			Button^ buttonBack;
			Button^ buttonReload;
			Button^ buttonBilling;


			void initialize()
			{
				this->tableLayout1 = gcnew TableLayoutPanel();
				this->tableLayout2 = gcnew TableLayoutPanel();
				this->tableLayout3 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();

				this->BillingAdressGridView = gcnew DataGridView();
				this->DeliveryAdressGridView = gcnew DataGridView();

				this->buttonDelivery = gcnew Button();
				this->buttonBack = gcnew Button();
				this->buttonReload = gcnew Button();
				this->buttonBilling = gcnew Button();

				/* -------------------- tableLayout1 --------------------*/
				this->tableLayout1->ColumnCount = 2;
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->Controls->Add(this->DeliveryAdressGridView, 1, 0);
				this->tableLayout1->Controls->Add(this->buttonBilling, 1, 1);
				this->tableLayout1->Controls->Add(this->buttonDelivery, 0, 1);
				this->tableLayout1->Controls->Add(this->BillingAdressGridView, 0, 0);
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
				this->tableLayout3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute, 46)));
				this->tableLayout3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute, 468)));
				this->tableLayout3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute, 46)));
				this->tableLayout3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute, 48)));
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
				this->labelTitle->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 20));
				this->labelTitle->Location = Point(265, 4);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(122, 31);
				this->labelTitle->TabIndex = 9;
				this->labelTitle->Text = L"AAAAAA";

				/* -------------------- DeliveryAdressGridView --------------------*/
				this->DeliveryAdressGridView->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->DeliveryAdressGridView->Location = Point(337, 10);
				this->DeliveryAdressGridView->Margin = Windows::Forms::Padding(10);
				this->DeliveryAdressGridView->Name = L"dataGridView2";
				this->DeliveryAdressGridView->Size = Drawing::Size(307, 301);
				this->DeliveryAdressGridView->TabIndex = 5;

				/* -------------------- BillingAdressGridView --------------------*/
				this->BillingAdressGridView->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->BillingAdressGridView->Location = Point(10, 10);
				this->BillingAdressGridView->Margin = Windows::Forms::Padding(10);
				this->BillingAdressGridView->Name = L"dataGridView1";
				this->BillingAdressGridView->Size = Drawing::Size(307, 301);
				this->BillingAdressGridView->TabIndex = 4;

				/* -------------------- buttonBilling --------------------*/
				this->buttonBilling->Anchor = AnchorStyles::None;
				this->buttonBilling->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonBilling->Location = Point(448, 330);
				this->buttonBilling->Name = L"button7";
				this->buttonBilling->Size = Drawing::Size(307, 41);
				this->buttonBilling->TabIndex = 3;
				this->buttonBilling->Text = L"Ajouter adresse de facturation";
				this->buttonBilling->UseVisualStyleBackColor = true;

				/* -------------------- buttonDelivery --------------------*/
				this->buttonDelivery->Anchor = AnchorStyles::None;
				this->buttonDelivery->Font = (gcnew Drawing::Font(L"Microsoft Sans Serif", 15));
				this->buttonDelivery->Location = Point(121, 330);
				this->buttonDelivery->Name = L"button1";
				this->buttonDelivery->Size = Drawing::Size(307, 41);
				this->buttonDelivery->TabIndex = 0;
				this->buttonDelivery->Text = L"Ajouter adresse de livraison";
				this->buttonDelivery->UseVisualStyleBackColor = true;

				/* -------------------- buttonBack --------------------*/
				this->buttonBack->Font = gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(0));
				this->buttonBack->Location = System::Drawing::Point(609, 3);
				this->buttonBack->Name = L"button2";
				this->buttonBack->Size = System::Drawing::Size(39, 34);
				this->buttonBack->TabIndex = 10;
				this->buttonBack->Text = L"-->";
				this->buttonBack->UseVisualStyleBackColor = true;
				this->buttonBack->Click += gcnew System::EventHandler(this, &CustomerAddressesForm::buttonBack_Click);

				/* -------------------- buttonReload --------------------*/
				this->buttonReload->Font = gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(0));
				this->buttonReload->Location = System::Drawing::Point(563, 3);
				this->buttonReload->Name = L"button6";
				this->buttonReload->Size = System::Drawing::Size(39, 34);
				this->buttonReload->TabIndex = 14;
				this->buttonReload->Text = L"( )";
				this->buttonReload->UseVisualStyleBackColor = true;
				this->buttonReload->Click += gcnew System::EventHandler(this, &CustomerAddressesForm::buttonReload_Click);
				
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayout2);
				this->Margin = Windows::Forms::Padding(2);
				this->Name = L"CustomerAdressesForm";
				this->Text = L"CustomerAdressesForm";
			}

			void fillBillingAdressesGridView()
			{
				this->BillingAdressGridView->Columns->Clear();

				DataGridViewTextBoxColumn^ idAddress = gcnew DataGridViewTextBoxColumn();
				idAddress->Name = L"id_address";
				idAddress->Visible = false;
				this->BillingAdressGridView->Columns->Add(idAddress);

				DataGridViewTextBoxColumn^ address = gcnew DataGridViewTextBoxColumn();
				address->Name = L"address";
				this->BillingAdressGridView->Columns->Add(address);

				DataGridViewTextBoxColumn^ city = gcnew DataGridViewTextBoxColumn();
				city->Name = L"city";
				this->BillingAdressGridView->Columns->Add(city);

				DataGridViewTextBoxColumn^ zipCode = gcnew DataGridViewTextBoxColumn();
				zipCode->Name = L"zip_code";
				this->BillingAdressGridView->Columns->Add(zipCode);

				DataGridViewTextBoxColumn^ country = gcnew DataGridViewTextBoxColumn();
				country->Name = L"country";
				this->BillingAdressGridView->Columns->Add(country);
				
				this->BillingAdressGridView->Rows->Add("1", "25 rue choucroute", "Paris", "75000", "France");
			}

			void fillDeliveryAdressesGridView()
			{
				this->DeliveryAdressGridView->Columns->Clear();

				DataGridViewTextBoxColumn^ idAddress = gcnew DataGridViewTextBoxColumn();
				idAddress->Name = L"id_address";
				idAddress->Visible = false;
				this->DeliveryAdressGridView->Columns->Add(idAddress);

				DataGridViewTextBoxColumn^ address = gcnew DataGridViewTextBoxColumn();
				address->Name = L"address";
				this->DeliveryAdressGridView->Columns->Add(address);

				DataGridViewTextBoxColumn^ city = gcnew DataGridViewTextBoxColumn();
				city->Name = L"city";
				this->DeliveryAdressGridView->Columns->Add(city);

				DataGridViewTextBoxColumn^ zipCode = gcnew DataGridViewTextBoxColumn();
				zipCode->Name = L"zip_code";
				this->DeliveryAdressGridView->Columns->Add(zipCode);

				DataGridViewTextBoxColumn^ country = gcnew DataGridViewTextBoxColumn();
				country->Name = L"country";
				this->DeliveryAdressGridView->Columns->Add(country);

				this->DeliveryAdressGridView->Rows->Add("1", "18 rue charcuterie", "Toulouses", "83000", "France");
			}

			void CustomerAddressesForm_Close()
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
				fillDeliveryAdressesGridView();
				fillBillingAdressesGridView();
				App::app->toastMessage(this, "Donnees actualisees", Color::Green, 3000);
				App::app->logger->log("Data reloaded");
			}
	};
}
