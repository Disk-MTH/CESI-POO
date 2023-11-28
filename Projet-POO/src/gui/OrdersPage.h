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
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::DataGridView^ dataGridViewOrders;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::CheckBox^ checkBoxDeleted;
	private: System::Windows::Forms::Button^ buttonOrderDetails;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Button^ buttonDelete;

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
			this->dataGridViewOrders = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBoxDeleted = (gcnew System::Windows::Forms::CheckBox());
			this->buttonOrderDetails = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->dataGridViewOrders, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.1519F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.8481F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 153)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(957, 628);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(350, 28);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(256, 48);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Commandes";
			// 
			// dataGridViewOrders
			// 
			this->dataGridViewOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewOrders->Location = System::Drawing::Point(15, 120);
			this->dataGridViewOrders->Margin = System::Windows::Forms::Padding(15);
			this->dataGridViewOrders->Name = L"dataGridViewOrders";
			this->dataGridViewOrders->RowHeadersWidth = 51;
			this->dataGridViewOrders->RowTemplate->Height = 24;
			this->dataGridViewOrders->Size = System::Drawing::Size(927, 339);
			this->dataGridViewOrders->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 6;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				244)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				57)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				129)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				127)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				137)));
			this->tableLayoutPanel2->Controls->Add(this->checkBoxDeleted, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonOrderDetails, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 4, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 5, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 477);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(951, 148);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// checkBoxDeleted
			// 
			this->checkBoxDeleted->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->checkBoxDeleted->AutoSize = true;
			this->checkBoxDeleted->Location = System::Drawing::Point(5, 64);
			this->checkBoxDeleted->Name = L"checkBoxDeleted";
			this->checkBoxDeleted->Size = System::Drawing::Size(246, 20);
			this->checkBoxDeleted->TabIndex = 0;
			this->checkBoxDeleted->Text = L"Afficher les commandes supprimées";
			this->checkBoxDeleted->UseVisualStyleBackColor = true;
			// 
			// buttonOrderDetails
			// 
			this->buttonOrderDetails->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonOrderDetails->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->buttonOrderDetails->Location = System::Drawing::Point(272, 15);
			this->buttonOrderDetails->Margin = System::Windows::Forms::Padding(15);
			this->buttonOrderDetails->Name = L"buttonOrderDetails";
			this->buttonOrderDetails->Size = System::Drawing::Size(214, 118);
			this->buttonOrderDetails->TabIndex = 1;
			this->buttonOrderDetails->Text = L"Details ";
			this->buttonOrderDetails->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->buttonAdd->Location = System::Drawing::Point(567, 94);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(7);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(113, 47);
			this->buttonAdd->TabIndex = 2;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->buttonEdit->Location = System::Drawing::Point(694, 94);
			this->buttonEdit->Margin = System::Windows::Forms::Padding(7);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(113, 47);
			this->buttonEdit->TabIndex = 3;
			this->buttonEdit->Text = L"Modifier";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->buttonDelete->Location = System::Drawing::Point(823, 94);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(7);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(121, 47);
			this->buttonDelete->TabIndex = 4;
			this->buttonDelete->Text = L"Supprimer";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// OrdersPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"OrdersPage";
			this->Text = L"OrdersPage";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOrders))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
