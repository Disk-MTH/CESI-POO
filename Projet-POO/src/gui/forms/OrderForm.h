#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de OrderForm
	/// </summary>
	public ref class OrderForm : public System::Windows::Forms::Form
	{
	public:
		OrderForm(void)
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
		~OrderForm()
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
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
	private: System::Windows::Forms::Label^ labelBirthDate;
	private: System::Windows::Forms::Label^ labelFirstName;
	private: System::Windows::Forms::Label^ labelLastName;
	private: System::Windows::Forms::Label^ labelBillingAddress;
	private: System::Windows::Forms::Label^ labelDeliveryAddress;


	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelType;
	private: System::Windows::Forms::Label^ labelProductName;
	private: System::Windows::Forms::Label^ labelColour;
	private: System::Windows::Forms::Label^ labelQuantity;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonCancel;


	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonValidate;
	private: System::Windows::Forms::DataGridView^ dataGridViewProductList;
	private: System::Windows::Forms::ComboBox^ comboBoxDeliveryAddress;

	private: System::Windows::Forms::ComboBox^ comboBoxFirstName;

	private: System::Windows::Forms::ComboBox^ comboBoxLastName;
	private: System::Windows::Forms::ComboBox^ comboBoxBillingAddress;
	private: System::Windows::Forms::ComboBox^ comboBoxColour;
	private: System::Windows::Forms::ComboBox^ comboBoxType;
	private: System::Windows::Forms::ComboBox^ comboBoxProductName;
	private: System::Windows::Forms::TextBox^ textBoxQuantity;
	private: System::Windows::Forms::TextBox^ textBoxBirthDate;





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
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->labelDeliveryAddress = (gcnew System::Windows::Forms::Label());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->labelBillingAddress = (gcnew System::Windows::Forms::Label());
			this->labelBirthDate = (gcnew System::Windows::Forms::Label());
			this->labelProductName = (gcnew System::Windows::Forms::Label());
			this->labelColour = (gcnew System::Windows::Forms::Label());
			this->labelType = (gcnew System::Windows::Forms::Label());
			this->labelQuantity = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonValidate = (gcnew System::Windows::Forms::Button());
			this->dataGridViewProductList = (gcnew System::Windows::Forms::DataGridView());
			this->comboBoxLastName = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxFirstName = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxBillingAddress = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxDeliveryAddress = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxProductName = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxColour = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxQuantity = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBirthDate = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProductList))->BeginInit();
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.98044F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 88.01956F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 97)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(659, 916);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				233)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				211)));
			this->tableLayoutPanel2->Controls->Add(this->buttonCancel, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonValidate, 2, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 821);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(653, 92);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				41.19449F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				58.80551F)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 101);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(653, 714);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel7, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->dataGridViewProductList, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(272, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(378, 708);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Controls->Add(this->comboBoxColour, 0, 5);
			this->tableLayoutPanel5->Controls->Add(this->comboBoxType, 0, 3);
			this->tableLayoutPanel5->Controls->Add(this->labelType, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->labelProductName, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->labelColour, 0, 4);
			this->tableLayoutPanel5->Controls->Add(this->labelQuantity, 0, 6);
			this->tableLayoutPanel5->Controls->Add(this->comboBoxProductName, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->textBoxQuantity, 0, 7);
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 329);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 8;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.66667F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 53.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 41)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 36)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(372, 320);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->comboBoxDeliveryAddress, 0, 7);
			this->tableLayoutPanel6->Controls->Add(this->comboBoxFirstName, 0, 3);
			this->tableLayoutPanel6->Controls->Add(this->labelBirthDate, 0, 4);
			this->tableLayoutPanel6->Controls->Add(this->labelFirstName, 0, 2);
			this->tableLayoutPanel6->Controls->Add(this->labelLastName, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->labelBillingAddress, 0, 8);
			this->tableLayoutPanel6->Controls->Add(this->labelDeliveryAddress, 0, 6);
			this->tableLayoutPanel6->Controls->Add(this->comboBoxLastName, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->comboBoxBillingAddress, 0, 9);
			this->tableLayoutPanel6->Controls->Add(this->textBoxBirthDate, 0, 5);
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 10;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43.28358F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 56.71642F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 69)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 78)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 79)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 66)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 71)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 92)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 61)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 62)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(263, 708);
			this->tableLayoutPanel6->TabIndex = 1;
			this->tableLayoutPanel6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &OrderForm::tableLayoutPanel6_Paint);
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(233, 29);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(193, 39);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Commande";
			// 
			// labelLastName
			// 
			this->labelLastName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelLastName->AutoSize = true;
			this->labelLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelLastName->Location = System::Drawing::Point(10, 15);
			this->labelLastName->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(53, 25);
			this->labelLastName->TabIndex = 0;
			this->labelLastName->Text = L"Nom";
			// 
			// labelDeliveryAddress
			// 
			this->labelDeliveryAddress->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelDeliveryAddress->AutoSize = true;
			this->labelDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelDeliveryAddress->Location = System::Drawing::Point(10, 444);
			this->labelDeliveryAddress->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelDeliveryAddress->Name = L"labelDeliveryAddress";
			this->labelDeliveryAddress->Size = System::Drawing::Size(188, 25);
			this->labelDeliveryAddress->TabIndex = 1;
			this->labelDeliveryAddress->Text = L"Adresse de livraison";
			// 
			// labelFirstName
			// 
			this->labelFirstName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelFirstName->Location = System::Drawing::Point(10, 151);
			this->labelFirstName->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(80, 25);
			this->labelFirstName->TabIndex = 2;
			this->labelFirstName->Text = L"Prenom";
			// 
			// labelBillingAddress
			// 
			this->labelBillingAddress->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelBillingAddress->AutoSize = true;
			this->labelBillingAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelBillingAddress->Location = System::Drawing::Point(10, 602);
			this->labelBillingAddress->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelBillingAddress->Name = L"labelBillingAddress";
			this->labelBillingAddress->Size = System::Drawing::Size(207, 25);
			this->labelBillingAddress->TabIndex = 3;
			this->labelBillingAddress->Text = L"Adresse de facturation";
			// 
			// labelBirthDate
			// 
			this->labelBirthDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelBirthDate->AutoSize = true;
			this->labelBirthDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelBirthDate->Location = System::Drawing::Point(10, 303);
			this->labelBirthDate->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelBirthDate->Name = L"labelBirthDate";
			this->labelBirthDate->Size = System::Drawing::Size(174, 25);
			this->labelBirthDate->TabIndex = 4;
			this->labelBirthDate->Text = L"Date de naissance";
			// 
			// labelProductName
			// 
			this->labelProductName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelProductName->AutoSize = true;
			this->labelProductName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelProductName->Location = System::Drawing::Point(10, 6);
			this->labelProductName->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelProductName->Name = L"labelProductName";
			this->labelProductName->Size = System::Drawing::Size(73, 25);
			this->labelProductName->TabIndex = 0;
			this->labelProductName->Text = L"Produit";
			// 
			// labelColour
			// 
			this->labelColour->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelColour->AutoSize = true;
			this->labelColour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelColour->Location = System::Drawing::Point(10, 168);
			this->labelColour->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelColour->Name = L"labelColour";
			this->labelColour->Size = System::Drawing::Size(81, 25);
			this->labelColour->TabIndex = 1;
			this->labelColour->Text = L"Couleur";
			// 
			// labelType
			// 
			this->labelType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelType->AutoSize = true;
			this->labelType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelType->Location = System::Drawing::Point(10, 88);
			this->labelType->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelType->Name = L"labelType";
			this->labelType->Size = System::Drawing::Size(70, 25);
			this->labelType->TabIndex = 2;
			this->labelType->Text = L"Nature";
			// 
			// labelQuantity
			// 
			this->labelQuantity->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->labelQuantity->AutoSize = true;
			this->labelQuantity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->labelQuantity->Location = System::Drawing::Point(10, 250);
			this->labelQuantity->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->labelQuantity->Name = L"labelQuantity";
			this->labelQuantity->Size = System::Drawing::Size(86, 25);
			this->labelQuantity->TabIndex = 3;
			this->labelQuantity->Text = L"Quantite";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->Controls->Add(this->buttonAdd, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->buttonDelete, 0, 0);
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 655);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(372, 50);
			this->tableLayoutPanel7->TabIndex = 1;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonDelete->Location = System::Drawing::Point(7, 7);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(7);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(112, 36);
			this->buttonDelete->TabIndex = 0;
			this->buttonDelete->Text = L"Supprimer";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonAdd->Location = System::Drawing::Point(252, 7);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(7);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(113, 36);
			this->buttonAdd->TabIndex = 1;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonCancel->Location = System::Drawing::Point(7, 52);
			this->buttonCancel->Margin = System::Windows::Forms::Padding(7);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(112, 33);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonValidate
			// 
			this->buttonValidate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonValidate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonValidate->Location = System::Drawing::Point(534, 52);
			this->buttonValidate->Margin = System::Windows::Forms::Padding(7);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = System::Drawing::Size(112, 33);
			this->buttonValidate->TabIndex = 1;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			// 
			// dataGridViewProductList
			// 
			this->dataGridViewProductList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewProductList->Location = System::Drawing::Point(3, 3);
			this->dataGridViewProductList->Name = L"dataGridViewProductList";
			this->dataGridViewProductList->Size = System::Drawing::Size(372, 320);
			this->dataGridViewProductList->TabIndex = 2;
			// 
			// comboBoxLastName
			// 
			this->comboBoxLastName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxLastName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->comboBoxLastName->FormattingEnabled = true;
			this->comboBoxLastName->Location = System::Drawing::Point(10, 82);
			this->comboBoxLastName->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxLastName->Name = L"comboBoxLastName";
			this->comboBoxLastName->Size = System::Drawing::Size(243, 33);
			this->comboBoxLastName->TabIndex = 5;
			// 
			// comboBoxFirstName
			// 
			this->comboBoxFirstName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->comboBoxFirstName->FormattingEnabled = true;
			this->comboBoxFirstName->Location = System::Drawing::Point(10, 220);
			this->comboBoxFirstName->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxFirstName->Name = L"comboBoxFirstName";
			this->comboBoxFirstName->Size = System::Drawing::Size(243, 33);
			this->comboBoxFirstName->TabIndex = 6;
			// 
			// comboBoxBillingAddress
			// 
			this->comboBoxBillingAddress->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxBillingAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->comboBoxBillingAddress->FormattingEnabled = true;
			this->comboBoxBillingAddress->Location = System::Drawing::Point(10, 660);
			this->comboBoxBillingAddress->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxBillingAddress->Name = L"comboBoxBillingAddress";
			this->comboBoxBillingAddress->Size = System::Drawing::Size(243, 33);
			this->comboBoxBillingAddress->TabIndex = 7;
			// 
			// comboBoxDeliveryAddress
			// 
			this->comboBoxDeliveryAddress->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxDeliveryAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->comboBoxDeliveryAddress->FormattingEnabled = true;
			this->comboBoxDeliveryAddress->Location = System::Drawing::Point(10, 521);
			this->comboBoxDeliveryAddress->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxDeliveryAddress->Name = L"comboBoxDeliveryAddress";
			this->comboBoxDeliveryAddress->Size = System::Drawing::Size(243, 33);
			this->comboBoxDeliveryAddress->TabIndex = 8;
			// 
			// comboBoxProductName
			// 
			this->comboBoxProductName->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxProductName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->comboBoxProductName->FormattingEnabled = true;
			this->comboBoxProductName->Location = System::Drawing::Point(10, 47);
			this->comboBoxProductName->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxProductName->Name = L"comboBoxProductName";
			this->comboBoxProductName->Size = System::Drawing::Size(352, 24);
			this->comboBoxProductName->TabIndex = 4;
			// 
			// comboBoxType
			// 
			this->comboBoxType->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Location = System::Drawing::Point(10, 128);
			this->comboBoxType->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(352, 24);
			this->comboBoxType->TabIndex = 5;
			// 
			// comboBoxColour
			// 
			this->comboBoxColour->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBoxColour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->comboBoxColour->FormattingEnabled = true;
			this->comboBoxColour->Location = System::Drawing::Point(10, 210);
			this->comboBoxColour->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->comboBoxColour->Name = L"comboBoxColour";
			this->comboBoxColour->Size = System::Drawing::Size(352, 24);
			this->comboBoxColour->TabIndex = 6;
			// 
			// textBoxQuantity
			// 
			this->textBoxQuantity->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxQuantity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->textBoxQuantity->Location = System::Drawing::Point(10, 290);
			this->textBoxQuantity->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxQuantity->Name = L"textBoxQuantity";
			this->textBoxQuantity->Size = System::Drawing::Size(352, 23);
			this->textBoxQuantity->TabIndex = 7;
			// 
			// textBoxBirthDate
			// 
			this->textBoxBirthDate->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBoxBirthDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->textBoxBirthDate->Location = System::Drawing::Point(10, 373);
			this->textBoxBirthDate->Margin = System::Windows::Forms::Padding(10, 3, 10, 3);
			this->textBoxBirthDate->Name = L"textBoxBirthDate";
			this->textBoxBirthDate->Size = System::Drawing::Size(243, 30);
			this->textBoxBirthDate->TabIndex = 9;
			// 
			// OrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 941);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"OrderForm";
			this->Text = L"OrderForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProductList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tableLayoutPanel6_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}
