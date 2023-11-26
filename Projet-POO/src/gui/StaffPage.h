#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Projet_POO {
	/// <summary>
	/// Description r�sum�e de StaffPage
	/// </summary>
	public ref class StaffPage : public System::Windows::Forms::Form
	{
	public:
		StaffPage(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~StaffPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayout1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayout2;
	private: System::Windows::Forms::DataGridView^ customersGridView;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayout3;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ labelFiters;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayout4;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ labelTitle;

	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayout1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayout2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->customersGridView = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayout3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelFiters = (gcnew System::Windows::Forms::Label());
			this->tableLayout4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayout1->SuspendLayout();
			this->tableLayout2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customersGridView))->BeginInit();
			this->tableLayout3->SuspendLayout();
			this->tableLayout4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayout1
			// 
			this->tableLayout1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayout1->ColumnCount = 1;
			this->tableLayout1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout1->Controls->Add(this->tableLayout2, 0, 1);
			this->tableLayout1->Controls->Add(this->tableLayout4, 0, 0);
			this->tableLayout1->Location = System::Drawing::Point(12, 12);
			this->tableLayout1->Name = L"tableLayout1";
			this->tableLayout1->RowCount = 2;
			this->tableLayout1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 387)));
			this->tableLayout1->Size = System::Drawing::Size(660, 437);
			this->tableLayout1->TabIndex = 2;
			// 
			// tableLayout2
			// 
			this->tableLayout2->ColumnCount = 2;
			this->tableLayout2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 72.47707F)));
			this->tableLayout2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.52294F)));
			this->tableLayout2->Controls->Add(this->customersGridView, 0, 0);
			this->tableLayout2->Controls->Add(this->tableLayout3, 1, 0);
			this->tableLayout2->Location = System::Drawing::Point(3, 53);
			this->tableLayout2->Name = L"tableLayout2";
			this->tableLayout2->RowCount = 1;
			this->tableLayout2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 380)));
			this->tableLayout2->Size = System::Drawing::Size(654, 380);
			this->tableLayout2->TabIndex = 1;
			// 
			// customersGridView
			// 
			this->customersGridView->AllowUserToResizeColumns = false;
			this->customersGridView->AllowUserToResizeRows = false;
			this->customersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->customersGridView->ColumnHeadersHeight = 29;
			this->customersGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->customersGridView->Location = System::Drawing::Point(3, 3);
			this->customersGridView->Name = L"customersGridView";
			this->customersGridView->RowHeadersVisible = false;
			this->customersGridView->RowHeadersWidth = 51;
			this->customersGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->customersGridView->Size = System::Drawing::Size(468, 374);
			this->customersGridView->TabIndex = 0;
			// 
			// tableLayout3
			// 
			this->tableLayout3->ColumnCount = 1;
			this->tableLayout3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout3->Controls->Add(this->buttonAdd, 0, 2);
			this->tableLayout3->Controls->Add(this->button1, 0, 1);
			this->tableLayout3->Controls->Add(this->labelFiters, 0, 0);
			this->tableLayout3->Location = System::Drawing::Point(477, 3);
			this->tableLayout3->Name = L"tableLayout3";
			this->tableLayout3->RowCount = 3;
			this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 69)));
			this->tableLayout3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 69)));
			this->tableLayout3->Size = System::Drawing::Size(174, 374);
			this->tableLayout3->TabIndex = 1;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonAdd->Location = System::Drawing::Point(18, 312);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(137, 55);
			this->buttonAdd->TabIndex = 1;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(18, 243);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 55);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// labelFiters
			// 
			this->labelFiters->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelFiters->AutoSize = true;
			this->labelFiters->Location = System::Drawing::Point(67, 20);
			this->labelFiters->Margin = System::Windows::Forms::Padding(3, 20, 3, 0);
			this->labelFiters->Name = L"labelFiters";
			this->labelFiters->Size = System::Drawing::Size(40, 13);
			this->labelFiters->TabIndex = 2;
			this->labelFiters->Text = L"Filtres :";
			// 
			// tableLayout4
			// 
			this->tableLayout4->ColumnCount = 5;
			this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				46)));
			this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				468)));
			this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				46)));
			this->tableLayout4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				48)));
			this->tableLayout4->Controls->Add(this->button2, 3, 0);
			this->tableLayout4->Controls->Add(this->button3, 3, 0);
			this->tableLayout4->Controls->Add(this->labelTitle, 2, 0);
			this->tableLayout4->Location = System::Drawing::Point(3, 3);
			this->tableLayout4->Name = L"tableLayout4";
			this->tableLayout4->RowCount = 1;
			this->tableLayout4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayout4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayout4->Size = System::Drawing::Size(654, 44);
			this->tableLayout4->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(563, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(39, 37);
			this->button2->TabIndex = 10;
			this->button2->Text = L"-->";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->labelTitle->Location = System::Drawing::Point(190, 6);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(271, 31);
			this->labelTitle->TabIndex = 9;
			this->labelTitle->Text = L"Gestion du personnel";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(609, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(39, 37);
			this->button3->TabIndex = 6;
			this->button3->Text = L"-->";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// StaffPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayout1);
			this->Name = L"StaffPage";
			this->Text = L"StaffPage";
			this->tableLayout1->ResumeLayout(false);
			this->tableLayout2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customersGridView))->EndInit();
			this->tableLayout3->ResumeLayout(false);
			this->tableLayout3->PerformLayout();
			this->tableLayout4->ResumeLayout(false);
			this->tableLayout4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
