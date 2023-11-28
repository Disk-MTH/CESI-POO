#pragma once

namespace Projet_POO {

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
	private: System::Windows::Forms::Button^ buttonOrders;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ buttonStats;
	private: System::Windows::Forms::Button^ buttonStaff;
	private: System::Windows::Forms::Button^ buttonCatalog;
	private: System::Windows::Forms::Button^ buttonCustomers;
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonCustomers = (gcnew System::Windows::Forms::Button());
			this->buttonCatalog = (gcnew System::Windows::Forms::Button());
			this->buttonStaff = (gcnew System::Windows::Forms::Button());
			this->buttonStats = (gcnew System::Windows::Forms::Button());
			this->buttonOrders = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->buttonOrders, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.1519F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.8481F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 153)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(957, 628);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30));
			this->labelTitle->Location = System::Drawing::Point(338, 23);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(280, 58);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Projet POO";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->buttonStats, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->buttonStaff, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->buttonCatalog, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonCustomers, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 108);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(951, 363);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// buttonCustomers
			// 
			this->buttonCustomers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonCustomers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->buttonCustomers->Location = System::Drawing::Point(20, 20);
			this->buttonCustomers->Margin = System::Windows::Forms::Padding(20);
			this->buttonCustomers->Name = L"buttonCustomers";
			this->buttonCustomers->Size = System::Drawing::Size(435, 141);
			this->buttonCustomers->TabIndex = 0;
			this->buttonCustomers->Text = L"Clients";
			this->buttonCustomers->UseVisualStyleBackColor = true;
			// 
			// buttonCatalog
			// 
			this->buttonCatalog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonCatalog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->buttonCatalog->Location = System::Drawing::Point(495, 20);
			this->buttonCatalog->Margin = System::Windows::Forms::Padding(20);
			this->buttonCatalog->Name = L"buttonCatalog";
			this->buttonCatalog->Size = System::Drawing::Size(436, 141);
			this->buttonCatalog->TabIndex = 1;
			this->buttonCatalog->Text = L"Catalogue";
			this->buttonCatalog->UseVisualStyleBackColor = true;
			// 
			// buttonStaff
			// 
			this->buttonStaff->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonStaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->buttonStaff->Location = System::Drawing::Point(20, 201);
			this->buttonStaff->Margin = System::Windows::Forms::Padding(20);
			this->buttonStaff->Name = L"buttonStaff";
			this->buttonStaff->Size = System::Drawing::Size(435, 142);
			this->buttonStaff->TabIndex = 2;
			this->buttonStaff->Text = L"Personnel";
			this->buttonStaff->UseVisualStyleBackColor = true;
			// 
			// buttonStats
			// 
			this->buttonStats->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonStats->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->buttonStats->Location = System::Drawing::Point(495, 201);
			this->buttonStats->Margin = System::Windows::Forms::Padding(20);
			this->buttonStats->Name = L"buttonStats";
			this->buttonStats->Size = System::Drawing::Size(436, 142);
			this->buttonStats->TabIndex = 3;
			this->buttonStats->Text = L"Statistiques";
			this->buttonStats->UseVisualStyleBackColor = true;
			// 
			// buttonOrders
			// 
			this->buttonOrders->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonOrders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->buttonOrders->Location = System::Drawing::Point(20, 494);
			this->buttonOrders->Margin = System::Windows::Forms::Padding(20);
			this->buttonOrders->Name = L"buttonOrders";
			this->buttonOrders->Size = System::Drawing::Size(917, 114);
			this->buttonOrders->TabIndex = 2;
			this->buttonOrders->Text = L"Commandes";
			this->buttonOrders->UseVisualStyleBackColor = true;
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->Name = L"HomePage";
			this->Text = L"HomePage";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	};
}
