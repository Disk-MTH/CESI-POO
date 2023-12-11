#pragma once

	using namespace System;
	using namespace Windows::Forms;
	using namespace Data;
	using namespace Drawing;

namespace OrderEase {
	
	public ref class TieredPriceForm : public Form
	{
	public:
		TieredPriceForm(String^ tieredpriceId, String^ quantity, String^ tfprice, String^ productId)
		{
			this->tieredpriceId = tieredpriceId;
			this->quantity = quantity;
			this->tfprice = tfprice;
			this->productId = productId;
			initialize();
		}

	private:
		String^ tieredpriceId;
		String^ quantity;
		String^ tfprice;
		String^ productId;
		
		TableLayoutPanel^ tableLayoutPanel1;
		TableLayoutPanel^ tableLayoutPanel2;

		Label^ labelTitle;
		Label^ labelQuantity;
		Label^ labelTfPrice;

		TextBox^ textBoxQuantity;
		TextBox^ textBoxTfPrice;
		
		Button^ buttonValidate;
		Button^ buttonCancel;
		
		void initialize()
		{
			this->tableLayoutPanel1 = gcnew TableLayoutPanel();
			this->tableLayoutPanel2 = gcnew TableLayoutPanel();

			this->labelTitle = gcnew Label();
			this->labelQuantity = gcnew Label();
			this->labelTfPrice = gcnew Label();
			
			this->textBoxQuantity = gcnew TextBox();
			this->textBoxTfPrice = gcnew TextBox();

			this->buttonValidate = gcnew Button();
			this->buttonCancel = gcnew Button();
		
			/*-------------------- tableLayoutPanel1 --------------------*/
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent,50));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->labelQuantity, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->labelTfPrice, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBoxQuantity, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBoxTfPrice, 0, 4);
			this->tableLayoutPanel1->Location = Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 52.38095F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Percent, 47.61905F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 42)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 42)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 48)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle(SizeType::Absolute, 69)));
			this->tableLayoutPanel1->Size = Drawing::Size(321, 289);
			
			/*-------------------- tableLayoutPanel2 --------------------*/
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->Controls->Add(this->buttonValidate, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonCancel, 0, 0);
			this->tableLayoutPanel2->Location = Point(3, 222);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
			this->tableLayoutPanel2->Size = Drawing::Size(315, 64);

			/*-------------------- labelTitle --------------------*/
			this->labelTitle->Anchor = AnchorStyles::None;
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 25);
			this->labelTitle->Location = Point(117, 7);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = Drawing::Size(86, 31);
			this->labelTitle->Text = L"Prix par palier";

			/*-------------------- labelQuantity --------------------*/
			this->labelQuantity->Anchor = AnchorStyles::Left;
			this->labelQuantity->AutoSize = true;
			this->labelQuantity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->labelQuantity->Location = Point(3, 54);
			this->labelQuantity->Name = L"labelQuantity";
			this->labelQuantity->Size = Drawing::Size(97, 25);
			this->labelQuantity->Text = L"Quantite :";

			/*-------------------- labelTfPrice --------------------*/
			this->labelTfPrice->Anchor = AnchorStyles::Left;
			this->labelTfPrice->AutoSize = true;
			this->labelTfPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->labelTfPrice->Location = Point(3, 137);
			this->labelTfPrice->Name = L"labelTfPrice";
			this->labelTfPrice->Size = Drawing::Size(156, 25);
			this->labelTfPrice->Text = L"Prix hors taxe :";

			/*-------------------- textBoxQuantity --------------------*/
			this->textBoxQuantity->Anchor = AnchorStyles::Left;
			this->textBoxQuantity->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->textBoxQuantity->Location = Point(3, 98);
			this->textBoxQuantity->Name = L"textBoxQuantity";
			this->textBoxQuantity->Size = Drawing::Size(216, 20);
			this->textBoxQuantity->TabIndex = 0;
			this->textBoxQuantity->Text = this->quantity;
			this->textBoxQuantity->KeyPress += gcnew KeyPressEventHandler(this, &TieredPriceForm::boxInt_KeyPress);
			
			/*-------------------- textBoxTfPrice --------------------*/
			this->textBoxTfPrice->Anchor = AnchorStyles::Left;
			this->textBoxTfPrice->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->textBoxTfPrice->Location = Point(3, 185);
			this->textBoxTfPrice->Name = L"textBoxTfPrice";
			this->textBoxTfPrice->Size = Drawing::Size(216, 20);
			this->textBoxTfPrice->TabIndex = 1;
			this->textBoxTfPrice->Text = this->tfprice;
			this->textBoxTfPrice->KeyPress += gcnew KeyPressEventHandler(this, &TieredPriceForm::boxFloat_KeyPress);

			/*-------------------- buttonValidate --------------------*/
			this->buttonValidate->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
			this->buttonValidate->AutoSize = true;
			this->buttonValidate->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->buttonValidate->Location = Point(223, 26);
			this->buttonValidate->Name = L"buttonValidate";
			this->buttonValidate->Size = Drawing::Size(89, 35);
			this->buttonValidate->TabIndex = 2;
			this->buttonValidate->Text = L"Valider";
			this->buttonValidate->UseVisualStyleBackColor = true;
			this->buttonValidate->Click += gcnew EventHandler(this, &TieredPriceForm::buttonValidate_Click);

			
			/*-------------------- buttonCancel --------------------*/
			this->buttonCancel->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
			this->buttonCancel->AutoSize = true;
			this->buttonCancel->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
			this->buttonCancel->Location = Point(3, 21);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = Drawing::Size(96, 40);
			this->buttonCancel->TabIndex = 3;
			this->buttonCancel->Text = L"Annuler";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew EventHandler(this, &TieredPriceForm::buttonCancel_Click);
			
			/*-------------------- TieredPriceForm --------------------*/
			this->StartPosition = FormStartPosition::CenterScreen;
			this->AutoScaleDimensions = SizeF(6, 13);
			this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = Drawing::Size(345, 313);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"TieredPriceForm";
			this->Text = L"TieredPriceForm";
		}

		Void boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e);
		Void boxFloat_KeyPress(Object^ sender, KeyPressEventArgs^ e);
		Void buttonCancel_Click(Object^ sender, EventArgs^ e);
		Void buttonValidate_Click(Object^ sender, EventArgs^ e);
	};
}
