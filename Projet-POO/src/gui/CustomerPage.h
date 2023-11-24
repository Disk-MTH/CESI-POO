#pragma once
#include "AddCustomerForm.h"
#include "CustomerAdressesPage.h"

namespace Projet_POO
{
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

		private:
			System::Windows::Forms::Button^ button2;

		private:
			System::Windows::Forms::Label^ labelTitle;

		private:
			System::Windows::Forms::Button^ button3;

		private:
			System::Windows::Forms::Button^ button6;


			System::ComponentModel::Container^ components;

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
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->labelTitle = (gcnew System::Windows::Forms::Label());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->button6 = (gcnew System::Windows::Forms::Button());
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
				this->tableLayout1->Location = System::Drawing::Point(12, 12);
				this->tableLayout1->Name = L"tableLayout1";
				this->tableLayout1->RowCount = 2;
				this->tableLayout1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 387)));
				this->tableLayout1->Size = System::Drawing::Size(660, 437);
				this->tableLayout1->TabIndex = 1;
				// 
				// tableLayout2
				// 
				this->tableLayout2->ColumnCount = 2;
				this->tableLayout2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 72.47707F)));
				this->tableLayout2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.52294F)));
				this->tableLayout2->Controls->Add(this->customersGridView, 0, 0);
				this->tableLayout2->Controls->Add(this->tableLayout3, 1, 0);
				this->tableLayout2->Location = System::Drawing::Point(3, 53);
				this->tableLayout2->Name = L"tableLayout2";
				this->tableLayout2->RowCount = 1;
				this->tableLayout2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 380)));
				this->tableLayout2->Size = System::Drawing::Size(654, 380);
				this->tableLayout2->TabIndex = 1;
				// 
				// customersGridView
				// 
				this->customersGridView->AllowUserToResizeColumns = false;
				this->customersGridView->AllowUserToResizeRows = false;
				this->customersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
				this->customersGridView->ColumnHeadersHeight = 29;
				this->customersGridView->Dock = System::Windows::Forms::DockStyle::Fill;
				this->customersGridView->Location = System::Drawing::Point(3, 3);
				this->customersGridView->Name = L"customersGridView";
				this->customersGridView->RowHeadersVisible = false;
				this->customersGridView->RowHeadersWidth = 51;
				this->customersGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
				this->customersGridView->Size = System::Drawing::Size(468, 374);
				this->customersGridView->TabIndex = 0;
				this->customersGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerPage::customersGridView_CellEndEdit);
				this->customersGridView->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &CustomerPage::customersGridView_RowDeleting);
				this->customersGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerPage::addressesCount_Click);

				fillCustomersGridView();
				// 
				// tableLayout3
				// 
				this->tableLayout3->ColumnCount = 1;
				this->tableLayout3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout3->Controls->Add(this->buttonAdd, 0, 2);
				this->tableLayout3->Controls->Add(this->button1, 0, 1);
				this->tableLayout3->Controls->Add(this->labelFiters, 0, 0);
				this->tableLayout3->Location = System::Drawing::Point(477, 3);
				this->tableLayout3->Name = L"tableLayout3";
				this->tableLayout3->RowCount = 3;
				this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 69)));
				this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 69)));
				this->tableLayout3->Size = System::Drawing::Size(174, 374);
				this->tableLayout3->TabIndex = 1;
				// 
				// buttonAdd
				// 
				this->buttonAdd->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->buttonAdd->Location = System::Drawing::Point(18, 312);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = System::Drawing::Size(137, 55);
				this->buttonAdd->TabIndex = 1;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew System::EventHandler(this, &CustomerPage::buttonAdd_Click);
				// 
				// button1
				// 
				this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->button1->Location = System::Drawing::Point(18, 243);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(137, 55);
				this->button1->TabIndex = 0;
				this->button1->Text = L"button1";
				this->button1->UseVisualStyleBackColor = true;
				// 
				// labelFiters
				// 
				this->labelFiters->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->labelFiters->AutoSize = true;
				this->labelFiters->Location = System::Drawing::Point(67, 20);
				this->labelFiters->Margin = System::Windows::Forms::Padding(3, 20, 3, 0);
				this->labelFiters->Name = L"labelFiters";
				this->labelFiters->Size = System::Drawing::Size(40, 13);
				this->labelFiters->TabIndex = 2;
				this->labelFiters->Text = L"Filtres :";
				// 
				// tableLayout4
				// 
				this->tableLayout4->ColumnCount = 5;
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					46)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					468)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					46)));
				this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					48)));
				this->tableLayout4->Controls->Add(this->button2, 4, 0);
				this->tableLayout4->Controls->Add(this->button6, 3, 0);
				this->tableLayout4->Controls->Add(this->labelTitle, 2, 0);
				this->tableLayout4->Location = System::Drawing::Point(3, 3);
				this->tableLayout4->Name = L"tableLayout4";
				this->tableLayout4->RowCount = 1;
				this->tableLayout4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				this->tableLayout4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
				this->tableLayout4->Size = System::Drawing::Size(654, 44);
				this->tableLayout4->TabIndex = 2;
				// 
				// button2
				// 
				this->button2->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button2->Location = System::Drawing::Point(609, 3);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(39, 37);
				this->button2->TabIndex = 10;
				this->button2->Text = L"-->";
				this->button2->UseVisualStyleBackColor = true;
				// 
				// labelTitle
				// 
				this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
				this->labelTitle->Location = System::Drawing::Point(204, 6);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = System::Drawing::Size(244, 31);
				this->labelTitle->TabIndex = 9;
				this->labelTitle->Text = L"Gestion des clients";
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
				// button6
				// 
				this->button6->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button6->Location = System::Drawing::Point(563, 3);
				this->button6->Name = L"button6";
				this->button6->Size = System::Drawing::Size(39, 37);
				this->button6->TabIndex = 14;
				this->button6->Text = L"( )";
				this->button6->UseVisualStyleBackColor = true;
				// 
				// CustomerPage
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayout1);
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
				birthdate->Name = L"Date de naissance";
				this->customersGridView->Columns->Add(birthdate);

				DataGridViewTextBoxColumn^ addressesCount = gcnew DataGridViewTextBoxColumn();
				addressesCount->Name = L"Nombre d'adresses";
				addressesCount->ReadOnly = true;
				this->customersGridView->Columns->Add(addressesCount);

				customers = App::app->db->query(
					"SELECT c.id_customer, c.first_name, c.last_name, CONVERT(VARCHAR, c.birthdate, 103) AS birthdate, ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount FROM customer c LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount FROM customerHasBillingAddresses GROUP BY id_customer) b ON c.id_customer = b.id_customer LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount FROM customerHasDeliveryAddresses GROUP BY id_customer) d ON c.id_customer = d.id_customer;");

				for (int i = 0; i < customers->Tables[0]->Rows->Count; i++)
				{
					this->customersGridView->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
				}
			}

			Void customerPage_Close(Object^ sender, FormClosingEventArgs^ e)
			{
				if (!this->back)
				{
					Application::Exit();
				}
			}

			Void buttonBack_Click(Object^ sender, EventArgs^ e)
			{
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

			Void addressesCount_Click(Object^ sender, DataGridViewCellEventArgs^ e)
			{
				int^ idCustomer = safe_cast<int^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[0]->Value);
				String^ firstName = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[1]->Value);
				String^ lastName = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[2]->Value);
				String^ birthdate = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[3]->Value);
				int^ addressesCount = safe_cast<int^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[4]->Value);
				CustomerAdressesForm^ addressesCountForm = gcnew CustomerAdressesForm();
				addressesCountForm->ShowDialog();
			}

	};
}
