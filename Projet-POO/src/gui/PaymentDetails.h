#pragma once

namespace Projet_POO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PaymentDetails
	/// </summary>
	public ref class PaymentDetails : public System::Windows::Forms::Form
	{
	public:
		PaymentDetails(void)
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
		~PaymentDetails()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::DataGridView^ dataGridViewPaymentDetails;
	private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonDelete;

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
			this->dataGridViewPaymentDetails = (gcnew System::Windows::Forms::DataGridView());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPaymentDetails))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->dataGridViewPaymentDetails, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 13);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.52022F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 82.47978F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 67)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(659, 436);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->labelTitle->Location = System::Drawing::Point(101, 12);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(457, 39);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Details des payements : REF";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				79.80952F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20.19048F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				127)));
			this->tableLayoutPanel2->Controls->Add(this->buttonEdit, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonAdd, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonDelete, 2, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 371);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(653, 62);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// dataGridViewPaymentDetails
			// 
			this->dataGridViewPaymentDetails->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPaymentDetails->Location = System::Drawing::Point(3, 67);
			this->dataGridViewPaymentDetails->Name = L"dataGridViewPaymentDetails";
			this->dataGridViewPaymentDetails->Size = System::Drawing::Size(653, 298);
			this->dataGridViewPaymentDetails->TabIndex = 2;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonAdd->Location = System::Drawing::Point(320, 22);
			this->buttonAdd->Margin = System::Windows::Forms::Padding(7);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(92, 33);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Ajouter";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonEdit->Location = System::Drawing::Point(426, 22);
			this->buttonEdit->Margin = System::Windows::Forms::Padding(7);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(92, 33);
			this->buttonEdit->TabIndex = 1;
			this->buttonEdit->Text = L"Modifier";
			this->buttonEdit->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->buttonDelete->Location = System::Drawing::Point(532, 22);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(7);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(114, 33);
			this->buttonDelete->TabIndex = 2;
			this->buttonDelete->Text = L"Supprimer";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// PaymentDetails
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"PaymentDetails";
			this->Text = L"PaymentDetails";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPaymentDetails))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
