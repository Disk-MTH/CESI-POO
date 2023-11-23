#pragma once

namespace Projet_POO {
	using namespace Data;
	using namespace System;
	using namespace Drawing;
	using namespace Windows::Forms;
	
	public ref class CustomerPage : public Form
	{
		public:
			CustomerPage(Database^ db)
			{
				this->db = db;
				InitializeComponent();
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
		
		System::Windows::Forms::TableLayoutPanel^ tableLayout1;
		System::Windows::Forms::TableLayoutPanel^ tableLayout2;
		System::Windows::Forms::TableLayoutPanel^ tableLayout3;
		System::Windows::Forms::TableLayoutPanel^ tableLayout4;
		System::Windows::Forms::FlowLayoutPanel^ flowLayout1;

		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::DataGridView^ customersGridView;
		
		System::Windows::Forms::Button^ buttonBack;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
	
		System::ComponentModel::Container ^components;
		
		void InitializeComponent()
		{
			/* -------------------- instantiation -------------------- */
			this->tableLayout1 = gcnew System::Windows::Forms::TableLayoutPanel();
			this->tableLayout2 = gcnew System::Windows::Forms::TableLayoutPanel();
			this->tableLayout3 = gcnew System::Windows::Forms::TableLayoutPanel();
			this->tableLayout4 = gcnew System::Windows::Forms::TableLayoutPanel();
			this->flowLayout1 = gcnew System::Windows::Forms::FlowLayoutPanel();

			this->labelTitle = gcnew System::Windows::Forms::Label();
			this->customersGridView = gcnew System::Windows::Forms::DataGridView();
			
			this->buttonBack = gcnew System::Windows::Forms::Button();
			this->button1 = gcnew System::Windows::Forms::Button();
			this->button2 = gcnew System::Windows::Forms::Button();
			this->button3 = gcnew System::Windows::Forms::Button();
			this->button4 = gcnew System::Windows::Forms::Button();

			/* -------------------- tableLayout1 -------------------- */
			this->tableLayout1->Anchor =
				System::Windows::Forms::AnchorStyles::Top |
				System::Windows::Forms::AnchorStyles::Bottom |
				System::Windows::Forms::AnchorStyles::Left |
				System::Windows::Forms::AnchorStyles::Right;
			this->tableLayout1->ColumnCount = 1;
			this->tableLayout1->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout1->Controls->Add(this->tableLayout2, 0, 1);
			this->tableLayout1->Controls->Add(this->tableLayout4, 0, 0);
			this->tableLayout1->Location = System::Drawing::Point(12, 12);
			this->tableLayout1->Name = L"tableLayoutPanel1";
			this->tableLayout1->RowCount = 2;
			this->tableLayout1->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout1->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 387));
			this->tableLayout1->Size = System::Drawing::Size(660, 437);
			this->tableLayout1->TabIndex = 1;
	
			/* -------------------- tableLayout2 -------------------- */
			this->tableLayout2->ColumnCount = 2;
			this->tableLayout2->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 72.47707F));
			this->tableLayout2->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.52294F));
			this->tableLayout2->Controls->Add(this->customersGridView, 0, 0);
			this->tableLayout2->Controls->Add(this->tableLayout3, 1, 0);
			this->tableLayout2->Location = System::Drawing::Point(3, 53);
			this->tableLayout2->Name = L"tableLayoutPanel2";
			this->tableLayout2->RowCount = 1;
			this->tableLayout2->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout2->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 381));
			this->tableLayout2->Size = System::Drawing::Size(654, 381);
			this->tableLayout2->TabIndex = 1;

			/* -------------------- tableLayout3 -------------------- */
			this->tableLayout3->ColumnCount = 1;
			this->tableLayout3->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout3->Controls->Add(this->flowLayout1, 0, 1);
			this->tableLayout3->Location = System::Drawing::Point(477, 3);
			this->tableLayout3->Name = L"tableLayoutPanel3";
			this->tableLayout3->RowCount = 3;
			this->tableLayout3->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout3->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 239));
			this->tableLayout3->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 66));
			this->tableLayout3->Size = System::Drawing::Size(174, 375);
			this->tableLayout3->TabIndex = 1;

			/* -------------------- tableLayout4 -------------------- */
			this->tableLayout4->ColumnCount = 3;
			this->tableLayout4->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout4->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 563));
			this->tableLayout4->ColumnStyles->Add(gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 45));
			this->tableLayout4->Controls->Add(this->labelTitle, 1, 0);
			this->tableLayout4->Controls->Add(this->buttonBack, 2, 0);
			this->tableLayout4->Location = System::Drawing::Point(3, 3);
			this->tableLayout4->Name = L"tableLayoutPanel4";
			this->tableLayout4->RowCount = 1;
			this->tableLayout4->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50));
			this->tableLayout4->Size = System::Drawing::Size(654, 44);
			this->tableLayout4->TabIndex = 2;

			/* -------------------- flowLayout1 -------------------- */
			this->flowLayout1->Controls->Add(this->button1);
			this->flowLayout1->Controls->Add(this->button2);
			this->flowLayout1->Controls->Add(this->button3);
			this->flowLayout1->Controls->Add(this->button4);
			this->flowLayout1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayout1->Location = System::Drawing::Point(30, 73);
			this->flowLayout1->Margin = System::Windows::Forms::Padding(30, 3, 30, 3);
			this->flowLayout1->Name = L"flowLayoutPanel1";
			this->flowLayout1->Size = System::Drawing::Size(114, 232);
			this->flowLayout1->TabIndex = 0;

			/* -------------------- labelTitle -------------------- */
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20);
			this->labelTitle->Location = System::Drawing::Point(205, 6);
			this->labelTitle->Name = L"label_title";
			this->labelTitle->Size = System::Drawing::Size(244, 31);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Gestion des clients";
			
			/* -------------------- customersGridView -------------------- */
			//cli::safe_cast<ISupportInitialize^>(this->customersGridView)->BeginInit();
			this->customersGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->customersGridView->Location = System::Drawing::Point(3, 3);
			this->customersGridView->Name = L"dataGridView1";
			this->customersGridView->Size = System::Drawing::Size(468, 375);
			this->customersGridView->TabIndex = 0;
			this->customersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->customersGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->customersGridView->RowHeadersVisible = false;
			this->customersGridView->AllowUserToResizeColumns = false;
			this->customersGridView->AllowUserToResizeRows = false;
			this->customersGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerPage::customersGridView_CellEndEdit);
			this->customersGridView->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &CustomerPage::customersGridView_RowDeleting);

			fillCustomersGridView();

			/* -------------------- buttonBack -------------------- */
			this->buttonBack->Font = gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 0);
			this->buttonBack->Location = System::Drawing::Point(612, 3);
			this->buttonBack->Name = L"button_back_Click";
			this->buttonBack->Size = System::Drawing::Size(39, 38);
			this->buttonBack->TabIndex = 4;
			this->buttonBack->Text = L"-->";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &CustomerPage::buttonBack_Click);

			/* -------------------- button1 -------------------- */
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;

			/* -------------------- button2 -------------------- */
			this->button2->Location = System::Drawing::Point(3, 61);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;

			/* -------------------- button3 -------------------- */
			this->button3->Location = System::Drawing::Point(3, 119);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
	
			/* -------------------- button4 -------------------- */
			this->button4->Location = System::Drawing::Point(3, 177);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 52);
			this->button4->TabIndex = 3;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;

			/* -------------------- form -------------------- */
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayout1);
			this->MaximizeBox = false;
			this->Name = L"CustomerPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CustomerPage";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CustomerPage::customerPage_Close);
		}

		Void fillCustomersGridView()
		{
			this->customersGridView->Columns->Clear();
			
			System::Windows::Forms::DataGridViewTextBoxColumn^ idCustomer = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			idCustomer->Name = L"id_customer";
			idCustomer->Visible = false;
			this->customersGridView->Columns->Add(idCustomer);
			
			System::Windows::Forms::DataGridViewTextBoxColumn^ firstName = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			firstName->Name = L"Nom";
			this->customersGridView->Columns->Add(firstName);
			
			System::Windows::Forms::DataGridViewTextBoxColumn^ lastName = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			lastName->Name = L"Prenom";
			this->customersGridView->Columns->Add(lastName);
			
			System::Windows::Forms::DataGridViewTextBoxColumn^ birthdate = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			birthdate->Name = L"Datede";
			this->customersGridView->Columns->Add(birthdate);

			System::Windows::Forms::DataGridViewTextBoxColumn^ addressesCount = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			addressesCount->Name = L"yyyy";
			addressesCount->ReadOnly = true;
			this->customersGridView->Columns->Add(addressesCount);
			
			customers = db->query("SELECT c.id_customer, c.first_name, c.last_name, CONVERT(VARCHAR, c.birthdate, 101) AS birthdate, ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount FROM customer c LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount FROM customerHasBillingAddresses GROUP BY id_customer) b ON c.id_customer = b.id_customer LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount FROM customerHasDeliveryAddresses GROUP BY id_customer) d ON c.id_customer = d.id_customer;");
			
			for (int i = 0; i < customers->Tables[0]->Rows->Count; i++) {
				this->customersGridView->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
			}
		}

		Void customerPage_Close(Object^ sender,  System::Windows::Forms::FormClosingEventArgs^ e) {
			if (!this->back) {
				Application::Exit();
			}
		}
		
		Void buttonBack_Click(Object^ sender, System::EventArgs^ e) {
			this->back = true;
			this->Close();
		}
		
		Void customersGridView_CellEndEdit(Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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

		Void customersGridView_RowDeleting(Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e)
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
