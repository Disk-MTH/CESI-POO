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
				initialize();
			}

		private:
			bool back = false;
			Windows::Forms::DialogResult pendingResult = Windows::Forms::DialogResult::None;
			int pendingCount = 0;

			DataSet^ customers;

			TableLayoutPanel^ tableLayout1;
			TableLayoutPanel^ tableLayout2;
			TableLayoutPanel^ tableLayout3;
			TableLayoutPanel^ tableLayout4;

			Label^ labelTitle;
			Label^ labelFiters;

			DataGridView^ customersGridView;

			Button^ buttonReload;
			Button^ buttonBack;
			Button^ buttonFilters;
			Button^ buttonAdd;

			void initialize()
			{
				this->tableLayout1 = (gcnew TableLayoutPanel());
				this->tableLayout2 = (gcnew TableLayoutPanel());
				this->tableLayout3 = (gcnew TableLayoutPanel());
				this->tableLayout4 = (gcnew TableLayoutPanel());

				this->labelTitle = (gcnew Label());
				this->labelFiters = (gcnew Label());

				this->customersGridView = (gcnew DataGridView());

				this->buttonBack = (gcnew Button());
				this->buttonReload = (gcnew Button());
				this->buttonFilters = (gcnew Button());
				this->buttonAdd = (gcnew Button());

				/* -------------------- tableLayout1 --------------------*/
				this->tableLayout1->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
				this->tableLayout1->ColumnCount = 1;
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->Controls->Add(this->tableLayout2, 0, 1);
				this->tableLayout1->Controls->Add(this->tableLayout4, 0, 0);
				this->tableLayout1->Location = Point(12, 12);
				this->tableLayout1->Name = L"tableLayout1";
				this->tableLayout1->RowCount = 2;
				this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 387));
				this->tableLayout1->Size = Drawing::Size(660, 437);
				this->tableLayout1->TabIndex = 1;

				/* -------------------- tableLayout2 --------------------*/
				this->tableLayout2->ColumnCount = 2;
				this->tableLayout2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 72.47707F));
				this->tableLayout2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 27.52294F));
				this->tableLayout2->Controls->Add(this->customersGridView, 0, 0);
				this->tableLayout2->Controls->Add(this->tableLayout3, 1, 0);
				this->tableLayout2->Location = Point(3, 53);
				this->tableLayout2->Name = L"tableLayout2";
				this->tableLayout2->RowCount = 1;
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 380));
				this->tableLayout2->Size = Drawing::Size(654, 380);
				this->tableLayout2->TabIndex = 1;

				/* -------------------- tableLayout3 --------------------*/
				this->tableLayout3->ColumnCount = 1;
				this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout3->Controls->Add(this->buttonAdd, 0, 2);
				this->tableLayout3->Controls->Add(this->buttonFilters, 0, 1);
				this->tableLayout3->Controls->Add(this->labelFiters, 0, 0);
				this->tableLayout3->Location = Point(477, 3);
				this->tableLayout3->Name = L"tableLayout3";
				this->tableLayout3->RowCount = 3;
				this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 69));
				this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 69));
				this->tableLayout3->Size = Drawing::Size(174, 374);
				this->tableLayout3->TabIndex = 1;

				/* -------------------- tableLayout4 --------------------*/
				this->tableLayout4->ColumnCount = 5;
				this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 46));
				this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 468));
				this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 46));
				this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 48));
				this->tableLayout4->Controls->Add(this->buttonBack, 4, 0);
				this->tableLayout4->Controls->Add(this->buttonReload, 3, 0);
				this->tableLayout4->Controls->Add(this->labelTitle, 2, 0);
				this->tableLayout4->Location = Point(3, 3);
				this->tableLayout4->Name = L"tableLayout4";
				this->tableLayout4->RowCount = 1;
				this->tableLayout4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout4->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 44));
				this->tableLayout4->Size = Drawing::Size(654, 44);
				this->tableLayout4->TabIndex = 2;

				/* -------------------- labelTitle --------------------*/
				this->labelTitle->Anchor = AnchorStyles::None;
				this->labelTitle->AutoSize = true;
				this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
				this->labelTitle->Location = Point(204, 6);
				this->labelTitle->Name = L"labelTitle";
				this->labelTitle->Size = Drawing::Size(244, 31);
				this->labelTitle->TabIndex = 9;
				this->labelTitle->Text = L"Gestion des clients";


				/* -------------------- labelFiters --------------------*/
				this->labelFiters->Anchor = AnchorStyles::Top;
				this->labelFiters->AutoSize = true;
				this->labelFiters->Location = Point(67, 20);
				this->labelFiters->Margin = Windows::Forms::Padding(3, 20, 3, 0);
				this->labelFiters->Name = L"labelFiters";
				this->labelFiters->Size = Drawing::Size(40, 13);
				this->labelFiters->TabIndex = 2;
				this->labelFiters->Text = L"Filtres :";

				/* -------------------- customersGridView --------------------*/
				this->customersGridView->AllowUserToResizeColumns = false;
				this->customersGridView->AllowUserToResizeRows = false;
				this->customersGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
				this->customersGridView->ColumnHeadersHeight = 29;
				this->customersGridView->Dock = DockStyle::Fill;
				this->customersGridView->Location = Point(3, 3);
				this->customersGridView->Name = L"customersGridView";
				this->customersGridView->RowHeadersVisible = false;
				this->customersGridView->RowHeadersWidth = 51;
				this->customersGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->customersGridView->Size = Drawing::Size(468, 374);
				this->customersGridView->TabIndex = 0;
				this->customersGridView->CellEndEdit += gcnew DataGridViewCellEventHandler(this, &CustomerPage::customersGridView_CellEndEdit);
				this->customersGridView->UserDeletingRow += gcnew DataGridViewRowCancelEventHandler(this, &CustomerPage::customersGridView_RowDeleting);
				this->customersGridView->CellClick += gcnew DataGridViewCellEventHandler(this, &CustomerPage::addressesCount_Click);
				fillCustomersGridView();

				/* -------------------- buttonReload --------------------*/
				this->buttonReload->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, 0);
				this->buttonReload->Location = Point(563, 3);
				this->buttonReload->Name = L"button6";
				this->buttonReload->Size = Drawing::Size(39, 37);
				this->buttonReload->TabIndex = 14;
				this->buttonReload->Text = L"( )";
				this->buttonReload->UseVisualStyleBackColor = true;
				this->buttonReload->Click += gcnew EventHandler(this, &CustomerPage::buttonReload_Click);

				/* -------------------- buttonBack --------------------*/
				this->buttonBack->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, 0);
				this->buttonBack->Location = Point(609, 3);
				this->buttonBack->Name = L"button2";
				this->buttonBack->Size = Drawing::Size(39, 37);
				this->buttonBack->TabIndex = 10;
				this->buttonBack->Text = L"-->";
				this->buttonBack->UseVisualStyleBackColor = true;
				this->buttonBack->Click += gcnew EventHandler(this, &CustomerPage::buttonBack_Click);

				/* -------------------- buttonFilters --------------------*/
				this->buttonFilters->Anchor = AnchorStyles::None;
				this->buttonFilters->Location = Point(18, 243);
				this->buttonFilters->Name = L"button1";
				this->buttonFilters->Size = Drawing::Size(137, 55);
				this->buttonFilters->TabIndex = 0;
				this->buttonFilters->Text = L"button1";
				this->buttonFilters->UseVisualStyleBackColor = true;

				/* -------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::None;
				this->buttonAdd->Location = Point(18, 312);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(137, 55);
				this->buttonAdd->TabIndex = 1;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &CustomerPage::buttonAdd_Click);

				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayout1);
				this->MaximizeBox = false;
				this->Name = L"CustomerPage";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->Text = L"CustomerPage";
				this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerPage::customerPage_Close);
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

				App::app->toastMessage(this, "this->Location = Point(parent->Location.X + parent->Width / 2 - this->Width / 2, parent->Location.Y + parent->Height + 10);", Color::Red, 3000);
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

			Void buttonReload_Click(Object^ sender, EventArgs^ e)
			{
				fillCustomersGridView();
			}

			Void buttonBack_Click(Object^ sender, EventArgs^ e)
			{
				this->back = true;
				this->Close();
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
				if (e->ColumnIndex == 4)
				{
					int^ idCustomer = safe_cast<int^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[0]->Value);
					String^ firstName = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[1]->Value);
					String^ lastName = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[2]->Value);
					String^ birthdate = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[3]->Value);
					int^ addressesCount = safe_cast<int^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[4]->Value);
					CustomerAdressesForm^ addressesCountForm = gcnew CustomerAdressesForm();
					addressesCountForm->ShowDialog();
				}
			}

	};
}
