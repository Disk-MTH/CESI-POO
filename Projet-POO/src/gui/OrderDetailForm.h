#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de OrderDetailForm
	/// </summary>
	public ref class OrderDetailForm : public System::Windows::Forms::Form
	{
	public:
		OrderDetailForm(void)
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
		~OrderDetailForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Label^ labelLastName;
	private: System::Windows::Forms::DataGridView^ dataGridViewProducts;


	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelValueDelivery;
	private: System::Windows::Forms::Label^ labelValueBilling;
	private: System::Windows::Forms::Label^ labelValueBirthDate;
	private: System::Windows::Forms::Label^ labelValueFirstName;
	private: System::Windows::Forms::Label^ labelBirthDate;
	private: System::Windows::Forms::Label^ labelFirstName;
	private: System::Windows::Forms::Label^ labelBilling;
	private: System::Windows::Forms::Label^ labelDelivery;
	private: System::Windows::Forms::Label^ labelValueLastName;
	private: System::Windows::Forms::Label^ labelValueVAT;
	private: System::Windows::Forms::Label^ labelVAT;
	private: System::Windows::Forms::Label^ labelTFTotalPrice;
	private: System::Windows::Forms::Label^ labelTotalPrice;
	private: System::Windows::Forms::Label^ labelValueTFTotalPrice;
	private: System::Windows::Forms::Label^ labelValueTotalPrice;


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
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridViewProducts = (gcnew System::Windows::Forms::DataGridView());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->labelBilling = (gcnew System::Windows::Forms::Label());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->labelDelivery = (gcnew System::Windows::Forms::Label());
			this->labelBirthDate = (gcnew System::Windows::Forms::Label());
			this->labelValueLastName = (gcnew System::Windows::Forms::Label());
			this->labelValueFirstName = (gcnew System::Windows::Forms::Label());
			this->labelValueBirthDate = (gcnew System::Windows::Forms::Label());
			this->labelValueBilling = (gcnew System::Windows::Forms::Label());
			this->labelValueDelivery = (gcnew System::Windows::Forms::Label());
			this->labelTFTotalPrice = (gcnew System::Windows::Forms::Label());
			this->labelTotalPrice = (gcnew System::Windows::Forms::Label());
			this->labelVAT = (gcnew System::Windows::Forms::Label());
			this->labelValueTFTotalPrice = (gcnew System::Windows::Forms::Label());
			this->labelValueVAT = (gcnew System::Windows::Forms::Label());
			this->labelValueTotalPrice = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 79.66666F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 101)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(657, 428);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				114)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				200)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				127)));
			this->tableLayoutPanel2->Controls->Add(this->labelValueVAT, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelVAT, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelTFTotalPrice, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelTotalPrice, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->labelValueTFTotalPrice, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelValueTotalPrice, 3, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 329);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(651, 96);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				59.44701F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40.55299F)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->dataGridViewProducts, 1, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 69);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(651, 254);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				41.81818F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				58.18182F)));
			this->tableLayoutPanel4->Controls->Add(this->labelValueDelivery, 1, 4);
			this->tableLayoutPanel4->Controls->Add(this->labelValueBilling, 1, 3);
			this->tableLayoutPanel4->Controls->Add(this->labelValueBirthDate, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->labelValueFirstName, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->labelBirthDate, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->labelFirstName, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->labelLastName, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->labelBilling, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->labelDelivery, 0, 4);
			this->tableLayoutPanel4->Controls->Add(this->labelValueLastName, 1, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 5;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 47.72727F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52.27273F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 58)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 48)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 41)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(381, 248);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// dataGridViewProducts
			// 
			this->dataGridViewProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewProducts->Location = System::Drawing::Point(390, 3);
			this->dataGridViewProducts->Name = L"dataGridViewProducts";
			this->dataGridViewProducts->RowHeadersWidth = 51;
			this->dataGridViewProducts->RowTemplate->Height = 24;
			this->dataGridViewProducts->Size = System::Drawing::Size(258, 248);
			this->dataGridViewProducts->TabIndex = 1;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->labelTitle->Location = System::Drawing::Point(84, 13);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(489, 39);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Details de la commande + REF";
			// 
			// labelLastName
			// 
			this->labelLastName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelLastName->AutoSize = true;
			this->labelLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelLastName->Location = System::Drawing::Point(10, 9);
			this->labelLastName->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(67, 29);
			this->labelLastName->TabIndex = 0;
			this->labelLastName->Text = L"Nom";
			// 
			// labelBilling
			// 
			this->labelBilling->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelBilling->AutoSize = true;
			this->labelBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelBilling->Location = System::Drawing::Point(10, 167);
			this->labelBilling->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->labelBilling->Name = L"labelBilling";
			this->labelBilling->Size = System::Drawing::Size(139, 29);
			this->labelBilling->TabIndex = 1;
			this->labelBilling->Text = L"Facturation";
			// 
			// labelFirstName
			// 
			this->labelFirstName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelFirstName->Location = System::Drawing::Point(10, 59);
			this->labelFirstName->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(102, 29);
			this->labelFirstName->TabIndex = 2;
			this->labelFirstName->Text = L"Prenom";
			// 
			// labelDelivery
			// 
			this->labelDelivery->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelDelivery->AutoSize = true;
			this->labelDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelDelivery->Location = System::Drawing::Point(10, 212);
			this->labelDelivery->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->labelDelivery->Name = L"labelDelivery";
			this->labelDelivery->Size = System::Drawing::Size(115, 29);
			this->labelDelivery->TabIndex = 3;
			this->labelDelivery->Text = L"Livraison";
			// 
			// labelBirthDate
			// 
			this->labelBirthDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelBirthDate->AutoSize = true;
			this->labelBirthDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelBirthDate->Location = System::Drawing::Point(10, 114);
			this->labelBirthDate->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->labelBirthDate->Name = L"labelBirthDate";
			this->labelBirthDate->Size = System::Drawing::Size(132, 29);
			this->labelBirthDate->TabIndex = 4;
			this->labelBirthDate->Text = L"Naissance";
			// 
			// labelValueLastName
			// 
			this->labelValueLastName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueLastName->AutoSize = true;
			this->labelValueLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueLastName->Location = System::Drawing::Point(162, 0);
			this->labelValueLastName->Name = L"labelValueLastName";
			this->labelValueLastName->Size = System::Drawing::Size(216, 48);
			this->labelValueLastName->TabIndex = 5;
			this->labelValueLastName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValueFirstName
			// 
			this->labelValueFirstName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueFirstName->AutoSize = true;
			this->labelValueFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueFirstName->Location = System::Drawing::Point(162, 48);
			this->labelValueFirstName->Name = L"labelValueFirstName";
			this->labelValueFirstName->Size = System::Drawing::Size(216, 52);
			this->labelValueFirstName->TabIndex = 6;
			this->labelValueFirstName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValueBirthDate
			// 
			this->labelValueBirthDate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueBirthDate->AutoSize = true;
			this->labelValueBirthDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueBirthDate->Location = System::Drawing::Point(162, 100);
			this->labelValueBirthDate->Name = L"labelValueBirthDate";
			this->labelValueBirthDate->Size = System::Drawing::Size(216, 58);
			this->labelValueBirthDate->TabIndex = 7;
			this->labelValueBirthDate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValueBilling
			// 
			this->labelValueBilling->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueBilling->AutoSize = true;
			this->labelValueBilling->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueBilling->Location = System::Drawing::Point(162, 158);
			this->labelValueBilling->Name = L"labelValueBilling";
			this->labelValueBilling->Size = System::Drawing::Size(216, 48);
			this->labelValueBilling->TabIndex = 8;
			this->labelValueBilling->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValueDelivery
			// 
			this->labelValueDelivery->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueDelivery->AutoSize = true;
			this->labelValueDelivery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueDelivery->Location = System::Drawing::Point(162, 206);
			this->labelValueDelivery->Name = L"labelValueDelivery";
			this->labelValueDelivery->Size = System::Drawing::Size(216, 42);
			this->labelValueDelivery->TabIndex = 9;
			this->labelValueDelivery->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelTFTotalPrice
			// 
			this->labelTFTotalPrice->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelTFTotalPrice->AutoSize = true;
			this->labelTFTotalPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelTFTotalPrice->Location = System::Drawing::Point(98, 9);
			this->labelTFTotalPrice->Name = L"labelTFTotalPrice";
			this->labelTFTotalPrice->Size = System::Drawing::Size(109, 29);
			this->labelTFTotalPrice->TabIndex = 0;
			this->labelTFTotalPrice->Text = L"Total HT";
			// 
			// labelTotalPrice
			// 
			this->labelTotalPrice->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelTotalPrice->AutoSize = true;
			this->labelTotalPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelTotalPrice->Location = System::Drawing::Point(397, 57);
			this->labelTotalPrice->Name = L"labelTotalPrice";
			this->labelTotalPrice->Size = System::Drawing::Size(124, 29);
			this->labelTotalPrice->TabIndex = 1;
			this->labelTotalPrice->Text = L"Total TTC";
			// 
			// labelVAT
			// 
			this->labelVAT->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelVAT->AutoSize = true;
			this->labelVAT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelVAT->Location = System::Drawing::Point(459, 9);
			this->labelVAT->Name = L"labelVAT";
			this->labelVAT->Size = System::Drawing::Size(62, 29);
			this->labelVAT->TabIndex = 2;
			this->labelVAT->Text = L"TVA";
			// 
			// labelValueTFTotalPrice
			// 
			this->labelValueTFTotalPrice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueTFTotalPrice->AutoSize = true;
			this->labelValueTFTotalPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueTFTotalPrice->Location = System::Drawing::Point(213, 0);
			this->labelValueTFTotalPrice->Name = L"labelValueTFTotalPrice";
			this->labelValueTFTotalPrice->Size = System::Drawing::Size(108, 48);
			this->labelValueTFTotalPrice->TabIndex = 3;
			this->labelValueTFTotalPrice->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValueVAT
			// 
			this->labelValueVAT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueVAT->AutoSize = true;
			this->labelValueVAT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueVAT->Location = System::Drawing::Point(527, 0);
			this->labelValueVAT->Name = L"labelValueVAT";
			this->labelValueVAT->Size = System::Drawing::Size(121, 48);
			this->labelValueVAT->TabIndex = 4;
			this->labelValueVAT->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelValueTotalPrice
			// 
			this->labelValueTotalPrice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelValueTotalPrice->AutoSize = true;
			this->labelValueTotalPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelValueTotalPrice->Location = System::Drawing::Point(527, 48);
			this->labelValueTotalPrice->Name = L"labelValueTotalPrice";
			this->labelValueTotalPrice->Size = System::Drawing::Size(121, 48);
			this->labelValueTotalPrice->TabIndex = 5;
			this->labelValueTotalPrice->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// OrderDetailForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 453);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"OrderDetailForm";
			this->Text = L"OrderDetailForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProducts))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
