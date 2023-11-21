#pragma once


namespace Project2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de HomePage
	/// </summary>
	public ref class HomePage : public System::Windows::Forms::Form
	{
	public:
		HomePage(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~HomePage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label_title;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ button_customers;

	private: System::Windows::Forms::Button^ button_stats;
	private: System::Windows::Forms::Button^ button_stocks;


	private: System::Windows::Forms::Button^ button_orders;

	private: System::Windows::Forms::Button^ button_staff;

	protected:


	protected:

	protected:

	protected:


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent()
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_stats = (gcnew System::Windows::Forms::Button());
			this->label_title = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_stocks = (gcnew System::Windows::Forms::Button());
			this->button_orders = (gcnew System::Windows::Forms::Button());
			this->button_staff = (gcnew System::Windows::Forms::Button());
			this->button_customers = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->button_stats, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_title, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 243)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 105)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(660, 437);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// button_stats
			// 
			this->button_stats->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_stats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->button_stats->Location = System::Drawing::Point(10, 342);
			this->button_stats->Margin = System::Windows::Forms::Padding(10);
			this->button_stats->Name = L"button_stats";
			this->button_stats->Size = System::Drawing::Size(640, 85);
			this->button_stats->TabIndex = 2;
			this->button_stats->Text = L"Statistiques";
			this->button_stats->UseVisualStyleBackColor = true;
			// 
			// label_title
			// 
			this->label_title->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_title->AutoSize = true;
			this->label_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->label_title->Location = System::Drawing::Point(234, 25);
			this->label_title->Name = L"label_title";
			this->label_title->Size = System::Drawing::Size(192, 39);
			this->label_title->TabIndex = 0;
			this->label_title->Text = L"Projet-POO";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->button_stocks, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->button_orders, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->button_staff, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->button_customers, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 92);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(654, 237);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// button_stocks
			// 
			this->button_stocks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_stocks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button_stocks->Location = System::Drawing::Point(337, 128);
			this->button_stocks->Margin = System::Windows::Forms::Padding(10);
			this->button_stocks->Name = L"button_stocks";
			this->button_stocks->Size = System::Drawing::Size(307, 99);
			this->button_stocks->TabIndex = 3;
			this->button_stocks->Text = L"Stocks";
			this->button_stocks->UseVisualStyleBackColor = true;
			// 
			// button_orders
			// 
			this->button_orders->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_orders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button_orders->Location = System::Drawing::Point(10, 128);
			this->button_orders->Margin = System::Windows::Forms::Padding(10);
			this->button_orders->Name = L"button_orders";
			this->button_orders->Size = System::Drawing::Size(307, 99);
			this->button_orders->TabIndex = 2;
			this->button_orders->Text = L"Commandes";
			this->button_orders->UseVisualStyleBackColor = true;
			// 
			// button_staff
			// 
			this->button_staff->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_staff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button_staff->Location = System::Drawing::Point(337, 10);
			this->button_staff->Margin = System::Windows::Forms::Padding(10);
			this->button_staff->Name = L"button_staff";
			this->button_staff->Size = System::Drawing::Size(307, 98);
			this->button_staff->TabIndex = 1;
			this->button_staff->Text = L"Personnel";
			this->button_staff->UseVisualStyleBackColor = true;
			// 
			// button_customers
			// 
			this->button_customers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_customers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button_customers->Location = System::Drawing::Point(10, 10);
			this->button_customers->Margin = System::Windows::Forms::Padding(10);
			this->button_customers->Name = L"button_customers";
			this->button_customers->Size = System::Drawing::Size(307, 98);
			this->button_customers->TabIndex = 0;
			this->button_customers->Text = L"Clients";
			this->button_customers->UseVisualStyleBackColor = true;
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->Name = L"HomePage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HomePage";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
