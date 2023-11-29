#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de OrdersPage
	/// </summary>
	public ref class OrdersPage : public System::Windows::Forms::Form
	{
	public:
		OrdersPage(void)
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
		~OrdersPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::CheckBox^ checkBoxDeleted;
	private: System::Windows::Forms::DataGridView^ dataGridViewOrders;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonOrderDetails;

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
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridViewOrders = (gcnew System::Windows::Forms::DataGridView());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->checkBoxDeleted = (gcnew System::Windows::Forms::CheckBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonOrderDetails = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->dataGridViewOrders, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.52768F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 82.47233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 90)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(959, 636);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 5;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60.46128F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				39.53872F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				107)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				118)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				123)));
			this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 4, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonOrderDetails, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 548);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(953, 85);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// dataGridViewOrders
			// 
			this->dataGridViewOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewOrders->Location = System::Drawing::Point(15, 110);
			this->dataGridViewOrders->Margin = System::Windows::Forms::Padding(15);
			this->dataGridViewOrders->Name = L"dataGridViewOrders";
			this->dataGridViewOrders->Size = System::Drawing::Size(929, 420);
			this->dataGridViewOrders->TabIndex = 1;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(374, 28);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(210, 39);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Commandes";
			// 
			// checkBoxDeleted
			// 
			this->checkBoxDeleted->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->checkBoxDeleted->AutoSize = true;
			this->checkBoxDeleted->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->checkBoxDeleted->Location = System::Drawing::Point(10, 28);
			this->checkBoxDeleted->Margin = System::Windows::Forms::Padding(10, 3, 3, 3);
			this->checkBoxDeleted->Name = L"checkBoxDeleted";
			this->checkBoxDeleted->Size = System::Drawing::Size(346, 29);
			this->checkBoxDeleted->TabIndex = 0;
			this->checkBoxDeleted->Text = L"Montrer les commandes supprimees";
			this->checkBoxDeleted->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonAdd->Location = System::Drawing::Point(618, 43);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(7);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(86, 35);
			this->buttonAdd->TabIndex = 1;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonDelete->Location = System::Drawing::Point(836, 43);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(7);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(110, 35);
			this->buttonDelete->TabIndex = 2;
			this->buttonDelete->Text = L"Supprimer";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonEdit->Location = System::Drawing::Point(721, 43);
			this->buttonEdit->Margin = System::Windows::Forms::Padding(7);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(101, 35);
			this->buttonEdit->TabIndex = 3;
			this->buttonEdit->Text = L"Modifier";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonOrderDetails
			// 
			this->buttonOrderDetails->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonOrderDetails->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonOrderDetails->Location = System::Drawing::Point(375, 10);
			this->buttonOrderDetails->Margin = System::Windows::Forms::Padding(10);
			this->buttonOrderDetails->Name = L"buttonOrderDetails";
			this->buttonOrderDetails->Size = System::Drawing::Size(219, 65);
			this->buttonOrderDetails->TabIndex = 4;
			this->buttonOrderDetails->Text = L"Details";
			this->buttonOrderDetails->UseVisualStyleBackColor = true;
			// 
			// OrdersPage
			//
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"OrdersPage";
			this->Text = L"OrdersPage";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
