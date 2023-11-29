#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de ProductForm
	/// </summary>
	public ref class ProductForm : public System::Windows::Forms::Form
	{
	public:
		ProductForm(void)
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
		~ProductForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ labelType;
	private: System::Windows::Forms::Label^ labelQuantity;
	private: System::Windows::Forms::Label^ labelBuyPrice;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelColour;
	private: System::Windows::Forms::Label^ labelVAT;
	private: System::Windows::Forms::Label^ labelRestockThreshold;
	private: System::Windows::Forms::TextBox^ textBoxRestockThreshold;
	private: System::Windows::Forms::TextBox^ textBoxVAT;
	private: System::Windows::Forms::TextBox^ textBoxQuantity;
	private: System::Windows::Forms::TextBox^ textBoxBuyPrice;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::ComboBox^ comboBoxType;
	private: System::Windows::Forms::ComboBox^ comboBoxColour;
	private: System::Windows::Forms::DataGridView^ dataGridViewTieredPrice;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonValidate;

	private: System::Windows::Forms::Button^ buttonApply;





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
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelBuyPrice = (gcnew System::Windows::Forms::Label());
			this->labelQuantity = (gcnew System::Windows::Forms::Label());
			this->labelColour = (gcnew System::Windows::Forms::Label());
			this->labelVAT = (gcnew System::Windows::Forms::Label());
			this->labelRestockThreshold = (gcnew System::Windows::Forms::Label());
			this->labelType = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBuyPrice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxQuantity = (gcnew System::Windows::Forms::TextBox());
			this->textBoxVAT = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRestockThreshold = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxColour = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridViewTieredPrice = (gcnew System::Windows::Forms::DataGridView());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->buttonValidate = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTieredPrice))->BeginInit();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->dataGridViewTieredPrice, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 4);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 27.2997F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 72.70029F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 290)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 104)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 104)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(657, 928);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(252, 34);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(153, 48);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Produit";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40.29227F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				59.70773F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				185)));
			this->tableLayoutPanel2->Controls->Add(this->textBoxRestockThreshold, 2, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBoxVAT, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBoxQuantity, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBoxBuyPrice, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->labelType, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->labelQuantity, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelBuyPrice, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelName, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelColour, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->labelVAT, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->labelRestockThreshold, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBoxName, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->comboBoxType, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->comboBoxColour, 0, 5);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 120);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 6;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 47.82609F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52.17391F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 51)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(651, 306);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// labelName
			// 
			this->labelName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelName->Location = System::Drawing::Point(10, 10);
			this->labelName->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(67, 29);
			this->labelName->TabIndex = 0;
			this->labelName->Text = L"Nom";
			// 
			// labelBuyPrice
			// 
			this->labelBuyPrice->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelBuyPrice->AutoSize = true;
			this->labelBuyPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelBuyPrice->Location = System::Drawing::Point(197, 10);
			this->labelBuyPrice->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelBuyPrice->Name = L"labelBuyPrice";
			this->labelBuyPrice->Size = System::Drawing::Size(144, 29);
			this->labelBuyPrice->TabIndex = 1;
			this->labelBuyPrice->Text = L"Prix d\'achat";
			// 
			// labelQuantity
			// 
			this->labelQuantity->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelQuantity->AutoSize = true;
			this->labelQuantity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelQuantity->Location = System::Drawing::Point(475, 10);
			this->labelQuantity->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelQuantity->Name = L"labelQuantity";
			this->labelQuantity->Size = System::Drawing::Size(108, 29);
			this->labelQuantity->TabIndex = 2;
			this->labelQuantity->Text = L"Quantité";
			// 
			// labelColour
			// 
			this->labelColour->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelColour->AutoSize = true;
			this->labelColour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelColour->Location = System::Drawing::Point(10, 224);
			this->labelColour->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelColour->Name = L"labelColour";
			this->labelColour->Size = System::Drawing::Size(101, 29);
			this->labelColour->TabIndex = 3;
			this->labelColour->Text = L"Couleur";
			// 
			// labelVAT
			// 
			this->labelVAT->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelVAT->AutoSize = true;
			this->labelVAT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelVAT->Location = System::Drawing::Point(197, 113);
			this->labelVAT->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelVAT->Name = L"labelVAT";
			this->labelVAT->Size = System::Drawing::Size(159, 29);
			this->labelVAT->TabIndex = 4;
			this->labelVAT->Text = L"Taux de TVA";
			// 
			// labelRestockThreshold
			// 
			this->labelRestockThreshold->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelRestockThreshold->AutoSize = true;
			this->labelRestockThreshold->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelRestockThreshold->Location = System::Drawing::Point(475, 113);
			this->labelRestockThreshold->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelRestockThreshold->Name = L"labelRestockThreshold";
			this->labelRestockThreshold->Size = System::Drawing::Size(105, 29);
			this->labelRestockThreshold->TabIndex = 5;
			this->labelRestockThreshold->Text = L"Restock";
			// 
			// labelType
			// 
			this->labelType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelType->AutoSize = true;
			this->labelType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelType->Location = System::Drawing::Point(10, 113);
			this->labelType->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelType->Name = L"labelType";
			this->labelType->Size = System::Drawing::Size(88, 29);
			this->labelType->TabIndex = 6;
			this->labelType->Text = L"Nature";
			// 
			// textBoxName
			// 
			this->textBoxName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxName->Location = System::Drawing::Point(10, 64);
			this->textBoxName->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(167, 22);
			this->textBoxName->TabIndex = 7;
			// 
			// textBoxBuyPrice
			// 
			this->textBoxBuyPrice->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxBuyPrice->Location = System::Drawing::Point(197, 64);
			this->textBoxBuyPrice->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxBuyPrice->Name = L"textBoxBuyPrice";
			this->textBoxBuyPrice->Size = System::Drawing::Size(258, 22);
			this->textBoxBuyPrice->TabIndex = 8;
			// 
			// textBoxQuantity
			// 
			this->textBoxQuantity->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxQuantity->Location = System::Drawing::Point(475, 64);
			this->textBoxQuantity->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxQuantity->Name = L"textBoxQuantity";
			this->textBoxQuantity->Size = System::Drawing::Size(166, 22);
			this->textBoxQuantity->TabIndex = 9;
			// 
			// textBoxVAT
			// 
			this->textBoxVAT->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxVAT->Location = System::Drawing::Point(197, 172);
			this->textBoxVAT->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxVAT->Name = L"textBoxVAT";
			this->textBoxVAT->Size = System::Drawing::Size(258, 22);
			this->textBoxVAT->TabIndex = 11;
			// 
			// textBoxRestockThreshold
			// 
			this->textBoxRestockThreshold->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxRestockThreshold->Location = System::Drawing::Point(475, 172);
			this->textBoxRestockThreshold->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxRestockThreshold->Name = L"textBoxRestockThreshold";
			this->textBoxRestockThreshold->Size = System::Drawing::Size(166, 22);
			this->textBoxRestockThreshold->TabIndex = 12;
			// 
			// comboBoxType
			// 
			this->comboBoxType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Location = System::Drawing::Point(10, 171);
			this->comboBoxType->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(167, 24);
			this->comboBoxType->TabIndex = 13;
			// 
			// comboBoxColour
			// 
			this->comboBoxColour->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxColour->FormattingEnabled = true;
			this->comboBoxColour->Location = System::Drawing::Point(10, 273);
			this->comboBoxColour->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxColour->Name = L"comboBoxColour";
			this->comboBoxColour->Size = System::Drawing::Size(167, 24);
			this->comboBoxColour->TabIndex = 14;
			// 
			// dataGridViewTieredPrice
			// 
			this->dataGridViewTieredPrice->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTieredPrice->Location = System::Drawing::Point(15, 444);
			this->dataGridViewTieredPrice->Margin = System::Windows::Forms::Padding(15);
			this->dataGridViewTieredPrice->Name = L"dataGridViewTieredPrice";
			this->dataGridViewTieredPrice->RowHeadersWidth = 51;
			this->dataGridViewTieredPrice->RowTemplate->Height = 24;
			this->dataGridViewTieredPrice->Size = System::Drawing::Size(627, 260);
			this->dataGridViewTieredPrice->TabIndex = 2;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				125)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				154)));
			this->tableLayoutPanel3->Controls->Add(this->buttonDelete, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->buttonEdit, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->buttonAdd, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 722);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(651, 98);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonAdd->Location = System::Drawing::Point(252, 7);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(7);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(113, 39);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonEdit->Location = System::Drawing::Point(379, 7);
			this->buttonEdit->Margin = System::Windows::Forms::Padding(7);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(111, 39);
			this->buttonEdit->TabIndex = 1;
			this->buttonEdit->Text = L"Modifier";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonDelete->Location = System::Drawing::Point(504, 7);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(7);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(140, 39);
			this->buttonDelete->TabIndex = 2;
			this->buttonDelete->Text = L"Supprimer";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.67257F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.32743F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				198)));
			this->tableLayoutPanel4->Controls->Add(this->buttonValidate, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->buttonApply, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->buttonCancel, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 826);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(651, 99);
			this->tableLayoutPanel4->TabIndex = 4;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonCancel->Location = System::Drawing::Point(15, 15);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(15);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(190, 69);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonApply
			// 
			this->buttonApply->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonApply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonApply->Location = System::Drawing::Point(235, 15);
			this->buttonApply->Margin = System::Windows::Forms::Padding(15);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(202, 69);
			this->buttonApply->TabIndex = 1;
			this->buttonApply->Text = L"Appliquer";
			this->buttonApply->UseVisualStyleBackColor = true;
			// 
			// buttonValidate
			// 
			this->buttonValidate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonValidate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonValidate->Location = System::Drawing::Point(467, 15);
			this->buttonValidate->Margin = System::Windows::Forms::Padding(15);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = System::Drawing::Size(169, 69);
			this->buttonValidate->TabIndex = 2;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			// 
			// ProductForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 953);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->Name = L"ProductForm";
			this->Text = L"ProductForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTieredPrice))->EndInit();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
