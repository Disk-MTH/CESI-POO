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
		Database^ db;
		
		public:
			CustomerPage(Database^ db)
			{
				InitializeComponent();
				this->db = db;
				


				DataSet^ data_set = db->query("SELECT * FROM customer");

				for each (DataRow^ row in data_set->Tables[0]->Rows)
				{

					int id = (int)row[0];
					System::Diagnostics::Debug::WriteLine("id " + id);
					String^ nom = (String^)row[1];
					System::Diagnostics::Debug::WriteLine("nom " + nom);
					String^ MailAdress = (String^)row[2];
					System::Diagnostics::Debug::WriteLine("adresse mail " + MailAdress);

					DataGridViewRow^ dgvr = gcnew DataGridViewRow();
					DataGridViewTextBoxCell^ dgvc = gcnew DataGridViewTextBoxCell();
					dgvc->Value = Convert::ToString(id);
					dgvr->Cells->Add(dgvc);
					DataGridViewTextBoxCell^ dgvc2 = gcnew DataGridViewTextBoxCell();
					dgvc2->Value = nom;
					dgvr->Cells->Add(dgvc2);
					DataGridViewTextBoxCell^ dgvc3 = gcnew DataGridViewTextBoxCell();
					dgvc3->Value = MailAdress;
					dgvr->Cells->Add(dgvc3);
					this->gridView->Rows->Add(dgvr);
				}
			}

		protected:
			~CustomerPage()
			{
				if (components)
				{
					delete components;
				}
			}
		private: TableLayoutPanel^ tableLayoutPanel1;
		protected:


		private: TableLayoutPanel^ tableLayoutPanel2;
		DataGridView^ gridView;
		TableLayoutPanel^ tableLayoutPanel3;
		FlowLayoutPanel^ flowLayoutPanel1;
		Button^ button1;

		TableLayoutPanel^ tableLayoutPanel4;
		Label^ label_title;
		Button^ button_back_Click;

		Button^ button2;
		Button^ button3;
		Button^ button4;
		private:
			/// <summary>
			/// Variable n�cessaire au concepteur.
			/// </summary>
			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			void InitializeComponent()
			{
				this->tableLayoutPanel1 = (gcnew TableLayoutPanel());
				this->tableLayoutPanel2 = (gcnew TableLayoutPanel());
				this->gridView = (gcnew DataGridView());
				this->tableLayoutPanel3 = (gcnew TableLayoutPanel());
				this->flowLayoutPanel1 = (gcnew FlowLayoutPanel());
				this->button1 = (gcnew Button());
				this->button2 = (gcnew Button());
				this->button3 = (gcnew Button());
				this->button4 = (gcnew Button());
				this->tableLayoutPanel4 = (gcnew TableLayoutPanel());
				this->label_title = (gcnew Label());
				this->button_back_Click = (gcnew Button());
				this->tableLayoutPanel1->SuspendLayout();
				this->tableLayoutPanel2->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridView))->BeginInit();
				this->tableLayoutPanel3->SuspendLayout();
				this->flowLayoutPanel1->SuspendLayout();
				this->tableLayoutPanel4->SuspendLayout();
				this->SuspendLayout();
				// 
				// tableLayoutPanel1
				// 
				this->tableLayoutPanel1->Anchor = static_cast<AnchorStyles>((((AnchorStyles::Top | AnchorStyles::Bottom)
					| AnchorStyles::Left)
					| AnchorStyles::Right));
				this->tableLayoutPanel1->ColumnCount = 1;
				this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 0);
				this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 2;
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 387)));
				this->tableLayoutPanel1->Size = System::Drawing::Size(660, 437);
				this->tableLayoutPanel1->TabIndex = 1;
				// 
				// tableLayoutPanel2
				// 
				this->tableLayoutPanel2->ColumnCount = 2;
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					72.47707F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					27.52294F)));
				this->tableLayoutPanel2->Controls->Add(this->gridView, 0, 0);
				this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
				this->tableLayoutPanel2->Location = Point(3, 53);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 1;
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 381)));
				this->tableLayoutPanel2->Size = Drawing::Size(654, 381);
				this->tableLayoutPanel2->TabIndex = 1;
				// 
				// dataGridView1
				// 
				this->gridView->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->gridView->Dock = DockStyle::Fill;
				this->gridView->Location = Point(3, 3);
				this->gridView->Name = L"dataGridView1";
				this->gridView->Size = Drawing::Size(468, 375);
				this->gridView->TabIndex = 0;
				this->gridView->CellContentClick += gcnew DataGridViewCellEventHandler(this, &CustomerPage::dataGridView1_CellContentClick);
				DataGridViewTextBoxColumn^ dataColumnFirstName = gcnew DataGridViewTextBoxColumn();
				dataColumnFirstName->Name = "Nom";
				this->gridView->Columns->Add(dataColumnFirstName);
				DataGridViewTextBoxColumn^ dataColumnLastName = gcnew DataGridViewTextBoxColumn();
				dataColumnLastName->Name = "Prénom";
				this->gridView->Columns->Add(dataColumnLastName);
				
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel3->Controls->Add(this->flowLayoutPanel1, 0, 1);
				this->tableLayoutPanel3->Location = System::Drawing::Point(477, 3);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 3;
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 239)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 66)));
				this->tableLayoutPanel3->Size = System::Drawing::Size(174, 375);
				this->tableLayoutPanel3->TabIndex = 1;
				// 
				// flowLayoutPanel1
				// 
				this->flowLayoutPanel1->Controls->Add(this->button1);
				this->flowLayoutPanel1->Controls->Add(this->button2);
				this->flowLayoutPanel1->Controls->Add(this->button3);
				this->flowLayoutPanel1->Controls->Add(this->button4);
				this->flowLayoutPanel1->FlowDirection = FlowDirection::TopDown;
				this->flowLayoutPanel1->Location = System::Drawing::Point(30, 73);
				this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(30, 3, 30, 3);
				this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
				this->flowLayoutPanel1->Size = System::Drawing::Size(114, 232);
				this->flowLayoutPanel1->TabIndex = 0;
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(3, 3);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(110, 52);
				this->button1->TabIndex = 0;
				this->button1->Text = L"button1";
				this->button1->UseVisualStyleBackColor = true;
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(3, 61);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(110, 52);
				this->button2->TabIndex = 1;
				this->button2->Text = L"button2";
				this->button2->UseVisualStyleBackColor = true;
				// 
				// button3
				// 
				this->button3->Location = System::Drawing::Point(3, 119);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(110, 52);
				this->button3->TabIndex = 2;
				this->button3->Text = L"button3";
				this->button3->UseVisualStyleBackColor = true;
				// 
				// button4
				// 
				this->button4->Location = System::Drawing::Point(3, 177);
				this->button4->Name = L"button4";
				this->button4->Size = System::Drawing::Size(110, 52);
				this->button4->TabIndex = 3;
				this->button4->Text = L"button4";
				this->button4->UseVisualStyleBackColor = true;
				// 
				// tableLayoutPanel4
				// 
				this->tableLayoutPanel4->ColumnCount = 3;
				this->tableLayoutPanel4->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Percent,
					50)));
				this->tableLayoutPanel4->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute,
					563)));
				this->tableLayoutPanel4->ColumnStyles->Add((gcnew ColumnStyle(SizeType::Absolute,
					45)));
				this->tableLayoutPanel4->Controls->Add(this->label_title, 1, 0);
				this->tableLayoutPanel4->Controls->Add(this->button_back_Click, 2, 0);
				this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 1;
				this->tableLayoutPanel4->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 50)));
				this->tableLayoutPanel4->Size = System::Drawing::Size(654, 44);
				this->tableLayoutPanel4->TabIndex = 2;
				// 
				// label_title
				// 
				this->label_title->Anchor = AnchorStyles::None;
				this->label_title->AutoSize = true;
				this->label_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
				this->label_title->Location = System::Drawing::Point(205, 6);
				this->label_title->Name = L"label_title";
				this->label_title->Size = System::Drawing::Size(244, 31);
				this->label_title->TabIndex = 1;
				this->label_title->Text = L"Gestion des clients";
				// 
				// button_back_Click
				// 
				this->button_back_Click->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->button_back_Click->Location = System::Drawing::Point(612, 3);
				this->button_back_Click->Name = L"button_back_Click";
				this->button_back_Click->Size = System::Drawing::Size(39, 38);
				this->button_back_Click->TabIndex = 4;
				this->button_back_Click->Text = L"-->";
				this->button_back_Click->UseVisualStyleBackColor = true;
				this->button_back_Click->Click += gcnew System::EventHandler(this, &CustomerPage::button_back_Click_Click);
				// 
				// CustomerPage
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(684, 461);
				this->Controls->Add(this->tableLayoutPanel1);
				this->MaximizeBox = false;
				this->Name = L"CustomerPage";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->Text = L"CustomerPage";
				this->tableLayoutPanel1->ResumeLayout(false);
				this->tableLayoutPanel2->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridView))->EndInit();
				this->tableLayoutPanel3->ResumeLayout(false);
				this->flowLayoutPanel1->ResumeLayout(false);
				this->tableLayoutPanel4->ResumeLayout(false);
				this->tableLayoutPanel4->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion
		private: System::Void button_back_Click_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
	}
};
}
