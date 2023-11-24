#pragma once
#include "AddCustomerForm.h"

namespace Projet_POO {
	using namespace Project_POO;
	using namespace Data;
	using namespace System;
	using namespace Drawing;
	using namespace Windows::Forms;
	
	public ref class CustomerPage : public Form
	{
		public:
			CustomerPage()
			{
				InitializeComponent();
			}
		
			~CustomerPage()
			{
				if (components)
				{
					delete components;
				}
			}

		private:
			bool back = false;
			Windows::Forms::DialogResult pendingResult = Windows::Forms::DialogResult::None;
			int pendingCount = 0;
			
			DataSet^ customers;
			
			System::Windows::Forms::TableLayoutPanel^ tableLayout1;
			System::Windows::Forms::TableLayoutPanel^ tableLayout2;
			System::Windows::Forms::TableLayoutPanel^ tableLayout3;
			System::Windows::Forms::TableLayoutPanel^ tableLayout4;



			System::Windows::Forms::DataGridView^ customersGridView;
			

		    System::Windows::Forms::Button^ button1;
			System::Windows::Forms::Button^ buttonAdd;
			System::Windows::Forms::Label^ labelFiters;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;




			System::ComponentModel::Container ^components;
			
			void InitializeComponent()
			{
				this->tableLayout1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->tableLayout2 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->customersGridView = (gcnew System::Windows::Forms::DataGridView());
				this->tableLayout3 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->buttonAdd = (gcnew System::Windows::Forms::Button());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->labelFiters = (gcnew System::Windows::Forms::Label());
				this->tableLayout4 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->button4 = (gcnew System::Windows::Forms::Button());
				this->labelTitle = (gcnew System::Windows::Forms::Label());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button5 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->tableLayout1->SuspendLayout();
				this->tableLayout2->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customersGridView))->BeginInit();
				this->tableLayout3->SuspendLayout();
				this->tableLayout4->SuspendLayout();
				this->SuspendLayout();
				// 
				// tableLayout1
				// 
				this->tableLayout1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->tableLayout1->ColumnCount = 1;
				this->tableLayout1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout1->Controls->Add(this->tableLayout2, 0, 1);
				this->tableLayout1->Controls->Add(this->tableLayout4, 0, 0);
				this->tableLayout1->Location = System::Drawing::Point(16, 15);
				this->tableLayout1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->tableLayout1->Name = L"tableLayout1";
				this->tableLayout1->RowCount = 2;
				this->tableLayout1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 476)));
				this->tableLayout1->Size = System::Drawing::Size(880, 538);
				this->tableLayout1->TabIndex = 1;
				// 
				// tableLayout2
				// 
				this->tableLayout2->ColumnCount = 2;
				this->tableLayout2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 72.47707F)));
				this->tableLayout2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.52294F)));
				this->tableLayout2->Controls->Add(this->customersGridView, 0, 0);
				this->tableLayout2->Controls->Add(this->tableLayout3, 1, 0);
				this->tableLayout2->Location = System::Drawing::Point(4, 66);
				this->tableLayout2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->tableLayout2->Name = L"tableLayout2";
				this->tableLayout2->RowCount = 1;
				this->tableLayout2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 469)));
				this->tableLayout2->Size = System::Drawing::Size(872, 468);
				this->tableLayout2->TabIndex = 1;
				// 
				// customersGridView
				// 
				this->customersGridView->AllowUserToResizeColumns = false;
				this->customersGridView->AllowUserToResizeRows = false;
				this->customersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
				this->customersGridView->ColumnHeadersHeight = 29;
				this->customersGridView->Dock = System::Windows::Forms::DockStyle::Fill;
				this->customersGridView->Location = System::Drawing::Point(4, 4);
				this->customersGridView->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->customersGridView->Name = L"customersGridView";
				this->customersGridView->RowHeadersVisible = false;
				this->customersGridView->RowHeadersWidth = 51;
				this->customersGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
				this->customersGridView->Size = System::Drawing::Size(624, 460);
				this->customersGridView->TabIndex = 0;
				this->customersGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerPage::customersGridView_CellEndEdit);
				this->customersGridView->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &CustomerPage::customersGridView_RowDeleting);
				// 
				// tableLayout3
				// 
				this->tableLayout3->ColumnCount = 1;
				this->tableLayout3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout3->Controls->Add(this->buttonAdd, 0, 2);
				this->tableLayout3->Controls->Add(this->button1, 0, 1);
				this->tableLayout3->Controls->Add(this->labelFiters, 0, 0);
				this->tableLayout3->Location = System::Drawing::Point(636, 4);
				this->tableLayout3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->tableLayout3->Name = L"tableLayout3";
				this->tableLayout3->RowCount = 3;
				this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 85)));
				this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 85)));
				this->tableLayout3->Size = System::Drawing::Size(232, 460);
				this->tableLayout3->TabIndex = 1;
				// 
				// buttonAdd
				// 
				this->buttonAdd->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->buttonAdd->Location = System::Drawing::Point(24, 383);
				this->buttonAdd->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = System::Drawing::Size(183, 68);
				this->buttonAdd->TabIndex = 1;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew System::EventHandler(this, &CustomerPage::buttonAdd_Click);
				// 
				// button1
				// 
				this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->button1->Location = System::Drawing::Point(24, 298);
				this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(183, 68);
				this->button1->TabIndex = 0;
				this->button1->Text = L"button1";
				this->button1->UseVisualStyleBackColor = true;
				// 
				// labelFiters
				// 
				this->labelFiters->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->labelFiters->AutoSize = true;
				this->labelFiters->Location = System::Drawing::Point(91, 25);
				this->labelFiters->Margin = System::Windows::Forms::Padding(4, 25, 4, 0);
				this->labelFiters->Name = L"labelFiters";
				this->labelFiters->Size = System::Drawing::Size(49, 16);
				this->labelFiters->TabIndex = 2;
				this->labelFiters->Text = L"Filtres :";
				// 
				// tableLayout4
				// 
				this->tableLayout4->ColumnCount = 5;
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					61)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					624)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					61)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					64)));
				this->tableLayout4->Controls->Add(this->button5, 0, 0);
				this->tableLayout4->Controls->Add(this->button2, 0, 0);
				this->tableLayout4->Controls->Add(this->labelTitle, 0, 0);
				this->tableLayout4->Controls->Add(this->button4, 0, 0);
				this->tableLayout4->Controls->Add(this->button3, 0, 0);
				this->tableLayout4->Location = System::Drawing::Point(4, 4);
				this->tableLayout4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->tableLayout4->Name = L"tableLayout4";
				this->tableLayout4->RowCount = 1;
				this->tableLayout4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				this->tableLayout4->Size = System::Drawing::Size(872, 54);
				this->tableLayout4->TabIndex = 2;
				// 
				// button4
				// 
				this->button4->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button4->Location = System::Drawing::Point(4, 4);
				this->button4->Margin = System::Windows::Forms::Padding(4);
				this->button4->Name = L"button4";
				this->button4->Size = System::Drawing::Size(52, 46);
				this->button4->TabIndex = 7;
				this->button4->Text = L"-->";
				this->button4->UseVisualStyleBackColor = true;
				// 
				// labelTitle
				// 
				this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
				this->labelTitle->Location = System::Drawing::Point(283, 7);
				this->labelTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = System::Drawing::Size(304, 39);
				this->labelTitle->TabIndex = 9;
				this->labelTitle->Text = L"Gestion des clients";
				// 
				// button2
				// 
				this->button2->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button2->Location = System::Drawing::Point(812, 4);
				this->button2->Margin = System::Windows::Forms::Padding(4);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(52, 46);
				this->button2->TabIndex = 10;
				this->button2->Text = L"-->";
				this->button2->UseVisualStyleBackColor = true;
				// 
				// button5
				// 
				this->button5->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button5->Location = System::Drawing::Point(751, 4);
				this->button5->Margin = System::Windows::Forms::Padding(4);
				this->button5->Name = L"button5";
				this->button5->Size = System::Drawing::Size(52, 46);
				this->button5->TabIndex = 11;
				this->button5->Text = L"-->";
				this->button5->UseVisualStyleBackColor = true;
				// 
				// button3
				// 
				this->button3->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button3->Location = System::Drawing::Point(66, 4);
				this->button3->Margin = System::Windows::Forms::Padding(4);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(52, 46);
				this->button3->TabIndex = 6;
				this->button3->Text = L"-->";
				this->button3->UseVisualStyleBackColor = true;
				// 
				// CustomerPage
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(912, 567);
				this->Controls->Add(this->tableLayout1);
				this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				this->MaximizeBox = false;
				this->Name = L"CustomerPage";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"CustomerPage";
				this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CustomerPage::customerPage_Close);
				this->tableLayout1->ResumeLayout(false);
				this->tableLayout2->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customersGridView))->EndInit();
				this->tableLayout3->ResumeLayout(false);
				this->tableLayout3->PerformLayout();
				this->tableLayout4->ResumeLayout(false);
				this->tableLayout4->PerformLayout();
				this->ResumeLayout(false);

			}

			Void fillCustomersGridView()
			{
				this->customersGridView->Columns->Clear();
				
				DataGridViewTextBoxColumn^ idCustomer = gcnew DataGridViewTextBoxColumn();
				idCustomer->Name = L"id_customer";
				idCustomer->Visible = false;
				this->customersGridView->Columns->Add(idCustomer);
				
				DataGridViewTextBoxColumn^ lastName = gcnew DataGridViewTextBoxColumn();
				lastName->Name = L"Nom";
				this->customersGridView->Columns->Add(lastName);
				
				DataGridViewTextBoxColumn^ firstName = gcnew DataGridViewTextBoxColumn();
				firstName->Name = L"Prenom";
				this->customersGridView->Columns->Add(firstName);
				
				DataGridViewTextBoxColumn^ birthdate = gcnew DataGridViewTextBoxColumn();
				birthdate->Name = L"Datede";
				this->customersGridView->Columns->Add(birthdate);

				DataGridViewTextBoxColumn^ addressesCount = gcnew DataGridViewTextBoxColumn();
				addressesCount->Name = L"yyyy";
				addressesCount->ReadOnly = true;
				this->customersGridView->Columns->Add(addressesCount);
				
				customers = App::app->db->query("SELECT c.id_customer, c.first_name, c.last_name, CONVERT(VARCHAR, c.birthdate, 103) AS birthdate, ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount FROM customer c LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount FROM customerHasBillingAddresses GROUP BY id_customer) b ON c.id_customer = b.id_customer LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount FROM customerHasDeliveryAddresses GROUP BY id_customer) d ON c.id_customer = d.id_customer;");
				
				for (int i = 0; i < customers->Tables[0]->Rows->Count; i++) {
					this->customersGridView->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
				}
			}

			Void customerPage_Close(Object^ sender,  FormClosingEventArgs^ e) {
				if (!this->back) {
					Application::Exit();
				}
			}
			
			Void buttonBack_Click(Object^ sender, EventArgs^ e) {
				this->back = true;
				this->Close();
			}
			
			Void customersGridView_CellEndEdit(Object^ sender, DataGridViewCellEventArgs^ e)
			{
				int^ idCustomer = safe_cast<int^>(this->customersGridView->Rows[e->RowIndex]->Cells[0]->Value);
				String^ newValue = safe_cast<String^>(this->customersGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
				String^ columnName;
				
				if (newValue == nullptr || newValue->Trim()->Length == 0)
				{
					Console::WriteLine("Empty value");
					MessageBox::Show("La valeur entree est vide !", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				
				switch (e->ColumnIndex)
				{
					case 1 :
						columnName = "first_name";
						break;
					case 2 :
						columnName = "last_name";
						break;
					case 3 :
						{
							columnName = "birthdate";
							DateTime date;
							if (!DateTime::TryParseExact(newValue, "dd/MM/yyyy", nullptr, Globalization::DateTimeStyles::None, date))
							{
								Console::WriteLine("Wrong date format: \"" + newValue + "\"");
								MessageBox::Show("       La date est invalide !\n\"dd/mm/yyyy\" ou \"dd-mm-yyyy\"", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
								return;
							}
							newValue = date.ToString("yyyy-MM-dd");
							break;
						}
					default :
						return;
				}
				
				App::app->db->execute("UPDATE customer SET " + columnName + " = '" + newValue + "' WHERE id_customer = " + idCustomer);
				Console::WriteLine("Data updated: \"" + columnName + "\" = \"" + newValue + "\"");
			}

			Void customersGridView_RowDeleting(Object^ sender, DataGridViewRowCancelEventArgs^ e)
			{
				if (pendingCount == 0)
				{
					pendingResult = MessageBox::Show("Voulez-vous vraiment supprimer la selection ?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
					if (pendingResult == Windows::Forms::DialogResult::Yes || pendingResult == Windows::Forms::DialogResult::No)
					{
						pendingCount = this->customersGridView->SelectedRows->Count;
					}
				}

				if (pendingResult == Windows::Forms::DialogResult::Yes)
				{
					int^ idCustomer = safe_cast<int^>(this->customersGridView->Rows[e->Row->Index]->Cells[0]->Value);
					App::app->db->execute("DELETE FROM customer WHERE id_customer = " + idCustomer);
					Console::WriteLine("Data deleted: \"id_customer\" = \"" + idCustomer + "\"");

					pendingCount--;
					if (pendingCount == 0)
					{
						pendingResult = Windows::Forms::DialogResult::None;
					}
				}
				else
				{
					e->Cancel = true;
					pendingCount--;
					if (pendingCount == 0)
					{
						pendingResult = Windows::Forms::DialogResult::None;
					}
				}
			}

			Void buttonAdd_Click(Object^ sender, EventArgs^ e)
			{
				String^ firstName = "";
				String^ lastName = "";
				String^ birthdate = "";
				AddCustomerForm^ addCustomerForm = gcnew AddCustomerForm(&firstName, &lastName, &birthdate);
				
				if (addCustomerForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				{
					//TODO: add try catch
					int inserted = App::app->db->insert("INSERT INTO customer (first_name, last_name, birthdate) VALUES ('" + firstName + "', '" + lastName + "', '" + birthdate + "')");
					Console::WriteLine(inserted + " data inserted: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
					
					fillCustomersGridView();
				}
			}

};
}
