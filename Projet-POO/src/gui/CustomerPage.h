#pragma once

namespace Projet_POO {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class CustomerPage : public Form
	{
		public:
			CustomerPage(Database^ db)
			{
				this->db = db;
				initialize();
			}
		
			~CustomerPage()
			{
				if (components)
				{
					delete components;
				}
			}

		bool back = false;
		Windows::Forms::DialogResult pendingResult = Windows::Forms::DialogResult::None;
		int pendingCount = 0;
		
		DataSet^ customers;
		Database^ db;
		
		TableLayoutPanel^ tableLayout1;
		TableLayoutPanel^ tableLayout2;
		TableLayoutPanel^ tableLayout3;
		TableLayoutPanel^ tableLayout4;
		FlowLayoutPanel^ flowLayout1;

		Label^ labelTitle;
		DataGridView^ customersGridView;
		
		Button^ buttonBack;
		Button^ button1;
		Button^ button2;
		Button^ button3;
		Button^ button4;
		
		System::ComponentModel::Container ^components;
		
		void initialize()
		{
			/* -------------------- instantiation -------------------- */
			this->tableLayout1 = gcnew TableLayoutPanel();
			this->tableLayout2 = gcnew TableLayoutPanel();
			this->tableLayout3 = gcnew TableLayoutPanel();
			this->tableLayout4 = gcnew TableLayoutPanel();
			this->flowLayout1 = gcnew FlowLayoutPanel();

			this->labelTitle = gcnew Label();
			this->customersGridView = gcnew DataGridView();
			
			this->buttonBack = gcnew Button();
			this->button1 = gcnew Button();
			this->button2 = gcnew Button();
			this->button3 = gcnew Button();
			this->button4 = gcnew Button();

			/* -------------------- tableLayout1 -------------------- */
			this->tableLayout1->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->tableLayout1->ColumnCount = 1;
			this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayout1->Controls->Add(this->tableLayout2, 0, 1);
			this->tableLayout1->Controls->Add(this->tableLayout4, 0, 0);
			this->tableLayout1->Location = Point(12, 12);
			this->tableLayout1->Name = L"tableLayoutPanel1";
			this->tableLayout1->RowCount = 2;
			this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 387));
			this->tableLayout1->Size = Drawing::Size(660, 437);
			this->tableLayout1->TabIndex = 1;
	
			/* -------------------- tableLayout2 -------------------- */
			this->tableLayout2->ColumnCount = 2;
			this->tableLayout2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 72.47707F));
			this->tableLayout2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 27.52294F));
			this->tableLayout2->Controls->Add(this->customersGridView, 0, 0);
			this->tableLayout2->Controls->Add(this->tableLayout3, 1, 0);
			this->tableLayout2->Location = Point(3, 53);
			this->tableLayout2->Name = L"tableLayoutPanel2";
			this->tableLayout2->RowCount = 1;
			this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayout2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 381));
			this->tableLayout2->Size = Drawing::Size(654, 381);
			this->tableLayout2->TabIndex = 1;

			/* -------------------- tableLayout3 -------------------- */
			this->tableLayout3->ColumnCount = 1;
			this->tableLayout3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayout3->Controls->Add(this->flowLayout1, 0, 1);
			this->tableLayout3->Location = Point(477, 3);
			this->tableLayout3->Name = L"tableLayoutPanel3";
			this->tableLayout3->RowCount = 3;
			this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 239));
			this->tableLayout3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 66));
			this->tableLayout3->Size = Drawing::Size(174, 375);
			this->tableLayout3->TabIndex = 1;

			/* -------------------- tableLayout4 -------------------- */
			this->tableLayout4->ColumnCount = 3;
			this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 563));
			this->tableLayout4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 45));
			this->tableLayout4->Controls->Add(this->labelTitle, 1, 0);
			this->tableLayout4->Controls->Add(this->buttonBack, 2, 0);
			this->tableLayout4->Location = Point(3, 3);
			this->tableLayout4->Name = L"tableLayoutPanel4";
			this->tableLayout4->RowCount = 1;
			this->tableLayout4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayout4->Size = Drawing::Size(654, 44);
			this->tableLayout4->TabIndex = 2;

			/* -------------------- flowLayout1 -------------------- */
			this->flowLayout1->Controls->Add(this->button1);
			this->flowLayout1->Controls->Add(this->button2);
			this->flowLayout1->Controls->Add(this->button3);
			this->flowLayout1->Controls->Add(this->button4);
			this->flowLayout1->FlowDirection = FlowDirection::TopDown;
			this->flowLayout1->Location = Point(30, 73);
			this->flowLayout1->Margin = Windows::Forms::Padding(30, 3, 30, 3);
			this->flowLayout1->Name = L"flowLayoutPanel1";
			this->flowLayout1->Size = Drawing::Size(114, 232);
			this->flowLayout1->TabIndex = 0;

			/* -------------------- labelTitle -------------------- */
			this->labelTitle->Anchor = AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
			this->labelTitle->Location = Point(205, 6);
			this->labelTitle->Name = L"label_title";
			this->labelTitle->Size = Drawing::Size(244, 31);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Gestion des clients";
			
			/* -------------------- customersGridView -------------------- */
			cli::safe_cast<ISupportInitialize^>(this->customersGridView)->BeginInit();
			this->customersGridView->Dock = DockStyle::Fill;
			this->customersGridView->Location = Point(3, 3);
			this->customersGridView->Name = L"dataGridView1";
			this->customersGridView->Size = Drawing::Size(468, 375);
			this->customersGridView->TabIndex = 0;
			this->customersGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->customersGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->customersGridView->RowHeadersVisible = false;
			this->customersGridView->AllowUserToResizeColumns = false;
			this->customersGridView->AllowUserToResizeRows = false;
			this->customersGridView->CellEndEdit += gcnew DataGridViewCellEventHandler(this, &CustomerPage::customersGridView_CellEndEdit);
			this->customersGridView->UserDeletingRow += gcnew DataGridViewRowCancelEventHandler(this, &CustomerPage::customersGridView_RowDeleting);

			DataGridViewTextBoxColumn^ idCustomer = gcnew DataGridViewTextBoxColumn();
			idCustomer->Name = "id_customer";
			idCustomer->Visible = false;
			this->customersGridView->Columns->Add(idCustomer);
			
			DataGridViewTextBoxColumn^ firstName = gcnew DataGridViewTextBoxColumn();
			firstName->Name = "Nom";
			this->customersGridView->Columns->Add(firstName);
			
			DataGridViewTextBoxColumn^ lastName = gcnew DataGridViewTextBoxColumn();
			lastName->Name = "Prenom";
			this->customersGridView->Columns->Add(lastName);
			
			DataGridViewTextBoxColumn^ birthdate = gcnew DataGridViewTextBoxColumn();
			birthdate->Name = "Date de naissance";
			this->customersGridView->Columns->Add(birthdate);

			DataGridViewTextBoxColumn^ addressesCount = gcnew DataGridViewTextBoxColumn();
			addressesCount->Name = "Nombre d'adresses";
			addressesCount->ReadOnly = true;
			this->customersGridView->Columns->Add(addressesCount);
			
			customers = db->query("SELECT c.id_customer, c.first_name, c.last_name, CONVERT(VARCHAR, c.birthdate, 101) AS birthdate, ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount FROM customer c LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount FROM customerHasBillingAddresses GROUP BY id_customer) b ON c.id_customer = b.id_customer LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount FROM customerHasDeliveryAddresses GROUP BY id_customer) d ON c.id_customer = d.id_customer;");
			
			for (int i = 0; i < customers->Tables[0]->Rows->Count; i++) {
				this->customersGridView->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
			}

			/* -------------------- buttonBack -------------------- */
			this->buttonBack->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->buttonBack->Location = Point(612, 3);
			this->buttonBack->Name = L"button_back_Click";
			this->buttonBack->Size = Drawing::Size(39, 38);
			this->buttonBack->TabIndex = 4;
			this->buttonBack->Text = L"-->";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew EventHandler(this, &CustomerPage::buttonBack_Click);

			/* -------------------- button1 -------------------- */
			this->button1->Location = Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = Drawing::Size(110, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;

			/* -------------------- button2 -------------------- */
			this->button2->Location = Point(3, 61);
			this->button2->Name = L"button2";
			this->button2->Size = Drawing::Size(110, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;

			/* -------------------- button3 -------------------- */
			this->button3->Location = Point(3, 119);
			this->button3->Name = L"button3";
			this->button3->Size = Drawing::Size(110, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
	
			/* -------------------- button4 -------------------- */
			this->button4->Location = Point(3, 177);
			this->button4->Name = L"button4";
			this->button4->Size = Drawing::Size(110, 52);
			this->button4->TabIndex = 3;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;

			/* -------------------- form -------------------- */
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

		Void customerPage_Close(Object^ sender, FormClosingEventArgs^ e) {
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
					columnName = "birthdate";
					if (!DateTime::TryParse(newValue, Globalization::CultureInfo::InvariantCulture, Globalization::DateTimeStyles::None, DateTime()))
					{
						Console::WriteLine("Wrong date format: \"" + newValue + "\"");
						MessageBox::Show("La date entree est invalide !", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
					break;
				default :
					return;
			}
			
			this->db->execute("UPDATE customer SET " + columnName + " = '" + newValue + "' WHERE id_customer = " + idCustomer);
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
				this->db->execute("DELETE FROM customer WHERE id_customer = " + idCustomer);
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
	};
}
