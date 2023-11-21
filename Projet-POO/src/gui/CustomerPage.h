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
				InitializeComponent();
				this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerPage::customerPage_Close);
			}
		
		protected:
			~CustomerPage()
			{
				if (components)
				{
					delete components;
				}
			}

		bool back = false;
		
		DataSet^ customers;
		Database^ db;
		
		TableLayoutPanel^ tableLayoutPanel1;
		TableLayoutPanel^ tableLayoutPanel2;
		TableLayoutPanel^ tableLayoutPanel3;
		TableLayoutPanel^ tableLayoutPanel4;
		FlowLayoutPanel^ flowLayoutPanel1;
		
		DataGridView^ customersGridView;
		Label^ labelTitle;
		
		Button^ buttonBack;
		Button^ button1;
		Button^ button2;
		Button^ button3;
		Button^ button4;
		
		System::ComponentModel::Container ^components;
		
		void InitializeComponent()
		{
			/* -------------------- instantiation -------------------- */
			this->tableLayoutPanel1 = gcnew TableLayoutPanel();
			this->tableLayoutPanel2 = gcnew TableLayoutPanel();
			this->customersGridView = gcnew DataGridView();
			this->tableLayoutPanel3 = gcnew TableLayoutPanel();
			this->flowLayoutPanel1 = gcnew FlowLayoutPanel();
			this->button1 = gcnew Button();
			this->button2 = gcnew Button();
			this->button3 = gcnew Button();
			this->button4 = gcnew Button();
			this->tableLayoutPanel4 = gcnew TableLayoutPanel();
			this->labelTitle = gcnew Label();
			this->buttonBack = gcnew Button();

			/* -------------------- tableLayoutPanel1 -------------------- */
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel1->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel1->Location = Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 387));
			this->tableLayoutPanel1->Size = Drawing::Size(660, 437);
			this->tableLayoutPanel1->TabIndex = 1;
	
			/* -------------------- tableLayoutPanel2 -------------------- */
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 72.47707F));
			this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 27.52294F));
			this->tableLayoutPanel2->Controls->Add(this->customersGridView, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
			this->tableLayoutPanel2->Location = Point(3, 53);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 381));
			this->tableLayoutPanel2->Size = Drawing::Size(654, 381);
			this->tableLayoutPanel2->TabIndex = 1;

			/* -------------------- gridView -------------------- */
			cli::safe_cast<ISupportInitialize^>(this->customersGridView)->BeginInit();
			this->customersGridView->Dock = DockStyle::Fill;
			this->customersGridView->Location = Point(3, 3);
			this->customersGridView->Name = L"dataGridView1";
			this->customersGridView->Size = Drawing::Size(468, 375);
			this->customersGridView->TabIndex = 0;
			this->customersGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->customersGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->customersGridView->AllowUserToAddRows = false;
			this->customersGridView->AllowUserToDeleteRows = false;
			this->customersGridView->AllowUserToResizeColumns = false;
			this->customersGridView->AllowUserToResizeRows = false;
			this->customersGridView->CellEndEdit += gcnew DataGridViewCellEventHandler(this, &CustomerPage::customersGridView_CellEndEdit);
			
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
				this->customersGridView->Rows->Add
				(
					customers->Tables[0]->Rows[i]->ItemArray[1],
					customers->Tables[0]->Rows[i]->ItemArray[2],
					customers->Tables[0]->Rows[i]->ItemArray[3],
					customers->Tables[0]->Rows[i]->ItemArray[4]
				);
			}

			/* -------------------- tableLayoutPanel3 -------------------- */
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel3->Controls->Add(this->flowLayoutPanel1, 0, 1);
			this->tableLayoutPanel3->Location = Point(477, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 239));
			this->tableLayoutPanel3->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 66));
			this->tableLayoutPanel3->Size = Drawing::Size(174, 375);
			this->tableLayoutPanel3->TabIndex = 1;

			/* -------------------- flowLayoutPanel1 -------------------- */
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->button3);
			this->flowLayoutPanel1->Controls->Add(this->button4);
			this->flowLayoutPanel1->FlowDirection = FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = Point(30, 73);
			this->flowLayoutPanel1->Margin = Windows::Forms::Padding(30, 3, 30, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = Drawing::Size(114, 232);
			this->flowLayoutPanel1->TabIndex = 0;

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
	
			/* -------------------- tableLayoutPanel4 -------------------- */
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 563));
			this->tableLayoutPanel4->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Absolute, 45));
			this->tableLayoutPanel4->Controls->Add(this->labelTitle, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->buttonBack, 2, 0);
			this->tableLayoutPanel4->Location = Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel4->Size = Drawing::Size(654, 44);
			this->tableLayoutPanel4->TabIndex = 2;

			/* -------------------- labelTitle -------------------- */
			this->labelTitle->Anchor = AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 20);
			this->labelTitle->Location = Point(205, 6);
			this->labelTitle->Name = L"label_title";
			this->labelTitle->Size = Drawing::Size(244, 31);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Gestion des clients";

			/* -------------------- buttonBack -------------------- */
			this->buttonBack->Font = gcnew Drawing::Font(L"Arial Black", 8.25F, FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->buttonBack->Location = Point(612, 3);
			this->buttonBack->Name = L"button_back_Click";
			this->buttonBack->Size = Drawing::Size(39, 38);
			this->buttonBack->TabIndex = 4;
			this->buttonBack->Text = L"-->";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew EventHandler(this, &CustomerPage::buttonBack_Click);

			/* -------------------- window -------------------- */
			this->SuspendLayout();
			this->AutoScaleDimensions = SizeF(6, 13);
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->Name = L"CustomerPage";
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = L"CustomerPage";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			cli::safe_cast<ISupportInitialize^>(this->customersGridView)->EndInit();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->ResumeLayout(false);
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
			int^ customerId = safe_cast<int^>(this->customers->Tables[0]->Rows[e->RowIndex]->ItemArray[0]);
			String^ newValue = safe_cast<String^>(this->customersGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
			String^ columnName;
			
			switch (e->ColumnIndex)
			{
				case 0 :
					columnName = "first_name";
					break;
				case 1 :
					columnName = "last_name";
					break;
				case 2 :
					columnName = "birthdate";
					if (!DateTime::TryParse(newValue, DateTime()))
					{
						Console::WriteLine("Wrong date format: \"" + newValue + "\"");
						MessageBox::Show("La date entree est invalide !", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
					break;
				default :
					return;
			}
			
			this->db->execute("UPDATE customer SET " + columnName + " = '" + newValue + "' WHERE id_customer = " + customerId);
			Console::WriteLine("Data updated: \"" + columnName + "\" = \"" + newValue + "\"");
		}
	};
}
