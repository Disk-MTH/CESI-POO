#pragma once

#include "../forms/AddCustomerForm.h"
#include "CustomerAddressesPage.h"

using namespace Projet_POO;
using namespace Data;
using namespace System;
using namespace Drawing;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class CustomersPage sealed : public Form
	{
		public:
			CustomersPage()
			{
				initialize();
				fillGridViewCustomers();
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
			Label^ labelFilters;

			DataGridView^ gridViewCustomers;

			Button^ buttonReload;
			Button^ buttonBack;
			Button^ buttonFilters;
			Button^ buttonAdd;

			void initialize()
			{
				this->tableLayout1 = gcnew TableLayoutPanel();
				this->tableLayout2 = gcnew TableLayoutPanel();
				this->tableLayout3 = gcnew TableLayoutPanel();
				this->tableLayout4 = gcnew TableLayoutPanel();

				this->labelTitle = gcnew Label();
				this->labelFilters = gcnew Label();

				this->gridViewCustomers = gcnew DataGridView();

				this->buttonBack = gcnew Button();
				this->buttonReload = gcnew Button();
				this->buttonFilters = gcnew Button();
				this->buttonAdd = gcnew Button();

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
				this->tableLayout2->Controls->Add(this->gridViewCustomers, 0, 0);
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
				this->tableLayout3->Controls->Add(this->labelFilters, 0, 0);
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
				this->labelFilters->Anchor = AnchorStyles::Top;
				this->labelFilters->AutoSize = true;
				this->labelFilters->Location = Point(67, 20);
				this->labelFilters->Margin = Windows::Forms::Padding(3, 20, 3, 0);
				this->labelFilters->Name = L"labelFiters";
				this->labelFilters->Size = Drawing::Size(40, 13);
				this->labelFilters->TabIndex = 2;
				this->labelFilters->Text = L"Filtres :";

				/* -------------------- customersGridView --------------------*/
				this->gridViewCustomers->AllowUserToResizeColumns = false;
				this->gridViewCustomers->AllowUserToResizeRows = false;
				this->gridViewCustomers->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
				this->gridViewCustomers->ColumnHeadersHeight = 29;
				this->gridViewCustomers->Dock = DockStyle::Fill;
				this->gridViewCustomers->Location = Point(3, 3);
				this->gridViewCustomers->Name = L"customersGridView";
				this->gridViewCustomers->RowHeadersVisible = false;
				this->gridViewCustomers->RowHeadersWidth = 51;
				this->gridViewCustomers->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
				this->gridViewCustomers->Size = Drawing::Size(468, 374);
				this->gridViewCustomers->TabIndex = 0;
				this->gridViewCustomers->CellEndEdit += gcnew DataGridViewCellEventHandler(this, &CustomersPage::customersGridView_CellEndEdit);
				this->gridViewCustomers->UserDeletingRow += gcnew DataGridViewRowCancelEventHandler(this, &CustomersPage::customersGridView_RowDeleting);
				this->gridViewCustomers->CellClick += gcnew DataGridViewCellEventHandler(this, &CustomersPage::addressesCount_Click);

				/* -------------------- buttonReload --------------------*/
				this->buttonReload->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, 0);
				this->buttonReload->Location = Point(563, 3);
				this->buttonReload->Name = L"buttonReload";
				this->buttonReload->Size = Drawing::Size(39, 37);
				this->buttonReload->TabIndex = 14;
				this->buttonReload->Text = L"( )";
				this->buttonReload->UseVisualStyleBackColor = true;
				this->buttonReload->Click += gcnew EventHandler(this, &CustomersPage::buttonReload_Click);

				/* -------------------- buttonBack --------------------*/
				this->buttonBack->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, 0);
				this->buttonBack->Location = Point(609, 3);
				this->buttonBack->Name = L"buttonBack";
				this->buttonBack->Size = Drawing::Size(39, 37);
				this->buttonBack->TabIndex = 10;
				this->buttonBack->Text = L"-->";
				this->buttonBack->UseVisualStyleBackColor = true;
				this->buttonBack->Click += gcnew EventHandler(this, &CustomersPage::buttonBack_Click);

				/* -------------------- buttonFilters --------------------*/
				this->buttonFilters->Anchor = AnchorStyles::None;
				this->buttonFilters->Location = Point(18, 243);
				this->buttonFilters->Name = L"buttonFilters";
				this->buttonFilters->Size = Drawing::Size(137, 55);
				this->buttonFilters->TabIndex = 0;
				this->buttonFilters->Text = L"Filtrer";
				this->buttonFilters->UseVisualStyleBackColor = true;

				/* -------------------- buttonAdd --------------------*/
				this->buttonAdd->Anchor = AnchorStyles::None;
				this->buttonAdd->Location = Point(18, 312);
				this->buttonAdd->Name = L"buttonAdd";
				this->buttonAdd->Size = Drawing::Size(137, 55);
				this->buttonAdd->TabIndex = 1;
				this->buttonAdd->Text = L"Ajouter";
				this->buttonAdd->UseVisualStyleBackColor = true;
				this->buttonAdd->Click += gcnew EventHandler(this, &CustomersPage::buttonAdd_Click);

				/* -------------------- CustomerPage --------------------*/
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayout1);
				this->MaximizeBox = false;
				this->Name = L"CustomerPage";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->Text = L"CustomerPage";
				this->FormClosing += gcnew FormClosingEventHandler(this, &CustomersPage::customerPage_Close);
			}

			Void fillGridViewCustomers()
			{
				this->gridViewCustomers->Columns->Clear();

				DataGridViewTextBoxColumn^ idCustomer = gcnew DataGridViewTextBoxColumn();
				idCustomer->Name = L"id_customer";
				idCustomer->Visible = false;
				this->gridViewCustomers->Columns->Add(idCustomer);

				DataGridViewTextBoxColumn^ lastName = gcnew DataGridViewTextBoxColumn();
				lastName->Name = L"Nom";
				this->gridViewCustomers->Columns->Add(lastName);

				DataGridViewTextBoxColumn^ firstName = gcnew DataGridViewTextBoxColumn();
				firstName->Name = L"Prenom";
				this->gridViewCustomers->Columns->Add(firstName);

				DataGridViewTextBoxColumn^ birthdate = gcnew DataGridViewTextBoxColumn();
				birthdate->Name = L"Date de naissance";
				this->gridViewCustomers->Columns->Add(birthdate);

				DataGridViewTextBoxColumn^ addressesCount = gcnew DataGridViewTextBoxColumn();
				addressesCount->Name = L"Nombre d'adresses";
				addressesCount->ReadOnly = true;
				this->gridViewCustomers->Columns->Add(addressesCount);

				customers = App::app->db->query(
					"SELECT c.id_customer, c.first_name, c.last_name, CONVERT(VARCHAR, c.birthdate, 103) AS birthdate, ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount FROM customer c LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount FROM customerHasBillingAddresses GROUP BY id_customer) b ON c.id_customer = b.id_customer LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount FROM customerHasDeliveryAddresses GROUP BY id_customer) d ON c.id_customer = d.id_customer WHERE c.deleted = 0;");

				for (int i = 0; i < customers->Tables[0]->Rows->Count; i++)
				{
					this->gridViewCustomers->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
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
				int^ idCustomer = safe_cast<int^>(this->gridViewCustomers->Rows[e->RowIndex]->Cells[0]->Value);
				String^ newValue = safe_cast<String^>(this->gridViewCustomers->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
				String^ columnName;

				if (newValue == nullptr || newValue->Trim()->Length == 0)
				{
					App::app->logger->warn("Invalid value: empty");
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
								App::app->logger->warn("Invalid birthdate: wrong format (\"" + newValue + "\")");
								MessageBox::Show("       La date est invalide !\n\"dd/mm/yyyy\" ou \"dd-mm-yyyy\"", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
								return;
							}
							newValue = date.ToString("yyyy-MM-dd");
							break;
						}
					default :
						return;
				}

				try
				{
					App::app->db->execute("UPDATE customer SET " + columnName + " = '" + newValue + "' WHERE id_customer = " + idCustomer);
					App::app->toastMessage(this, "Donnees mises a jour", Color::Green, 3000);
					App::app->logger->log("Data updated: \"" + columnName + "\" = \"" + newValue + "\"");
				}
				catch (Exception^ exception)
				{
					App::app->toastMessage(this, "Erreur lors de la mise a jour des donnees", Color::Red, 3000);
					App::app->logger->error("Error while updating data: \"" + columnName + "\" = \"" + newValue + "\"");
					App::app->logger->error(exception->Message);
				}
			}

			Void customersGridView_RowDeleting(Object^ sender, DataGridViewRowCancelEventArgs^ e)
			{
				if (pendingCount == 0)
				{
					pendingResult = MessageBox::Show("Voulez-vous vraiment supprimer la selection ?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
					if (pendingResult == Windows::Forms::DialogResult::Yes || pendingResult == Windows::Forms::DialogResult::No)
					{
						pendingCount = this->gridViewCustomers->SelectedRows->Count;
					}
				}

				if (pendingResult == Windows::Forms::DialogResult::Yes)
				{
					auto idCustomer = safe_cast<int^>(this->gridViewCustomers->Rows[e->Row->Index]->Cells[0]->Value);
					App::app->db->execute("UPDATE customer SET deleted = 1 WHERE id_customer = " + idCustomer);
					App::app->toastMessage(this, "Donnees supprimees", Color::Green, 3000);
					App::app->logger->log("Data deleted: \"id_customer\" = \"" + idCustomer + "\"");

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
				fillGridViewCustomers();
				App::app->toastMessage(this, "Donnees actualisees", Color::Green, 3000);
				App::app->logger->log("Data reloaded");
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
				auto addCustomerForm = gcnew AddCustomerForm(&firstName, &lastName, &birthdate);

				if (addCustomerForm->ShowDialog() == Windows::Forms::DialogResult::OK)
				{
					try
					{
						App::app->db->insert("INSERT INTO customer (first_name, last_name, birthdate) VALUES ('" + firstName + "', '" + lastName + "', '" + birthdate + "')");
						App::app->App::toastMessage(this, "Donnees ajoutees", Color::Green, 3000);
						App::app->logger->log("Data inserted: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
					}
					catch (Exception^ exception)
					{
						App::app->toastMessage(this, "Erreur lors de l'ajout des donnees", Color::Red, 3000);
						App::app->logger->error("Error while inserting data: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
						App::app->logger->error(exception->Message);
						return;
					}

					fillGridViewCustomers();
				}
			}

			Void addressesCount_Click(Object^ sender, DataGridViewCellEventArgs^ e)
			{
				if (e->ColumnIndex == 4)
				{
					/*int^ idCustomer = safe_cast<int^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[0]->Value);
					String^ firstName = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[1]->Value);
					String^ lastName = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[2]->Value);
					String^ birthdate = safe_cast<String^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[3]->Value);
					int^ addressesCount = safe_cast<int^>(this->customersGridView->Rows[this->customersGridView->CurrentCell->RowIndex]->Cells[4]->Value);*/
					this->Hide();
					auto customerAddressesForm = gcnew CustomerAddressesPage();
					customerAddressesForm->ShowDialog();
					this->Show();
				}
			}

	};
}
