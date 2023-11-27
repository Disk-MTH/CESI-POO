#pragma once

using namespace System;
using namespace Drawing;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class LoadingScreen : public Form
	{
		public:
			LoadingScreen()
			{
				initialize();
			}

			~LoadingScreen()
			{
				timer->Stop();
			}

		private:
			String^ text = "Chargement";
			int tickCount = 0;

			Timer^ timer;

			TableLayoutPanel^ tableLayout1;

			Label^ labelLoading;

			void initialize()
			{
				this->timer = gcnew Timer();

				this->tableLayout1 = gcnew TableLayoutPanel();

				this->labelLoading = gcnew Label();

				/* -------------------- timer --------------------*/
				this->timer->Interval = 500;
				this->timer->Tick += gcnew EventHandler(this, &LoadingScreen::timer_Tick);
				this->timer->Start();

				/* -------------------- tableLayout1 --------------------*/
				this->tableLayout1->ColumnCount = 1;
				this->tableLayout1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50));
				this->tableLayout1->Controls->Add(this->labelLoading, 0, 0);
				this->tableLayout1->Location = Point(12, 12);
				this->tableLayout1->Name = L"tableLayout1";
				this->tableLayout1->RowCount = 1;
				this->tableLayout1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
				this->tableLayout1->Size = Drawing::Size(160, 37);
				this->tableLayout1->TabIndex = 0;

				/* -------------------- labelLoading --------------------*/
				this->labelLoading->Anchor = AnchorStyles::None;
				this->labelLoading->AutoSize = true;
				this->labelLoading->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelLoading->Location = Point(12, 6);
				this->labelLoading->Name = L"labelLoading";
				this->labelLoading->Size = Drawing::Size(135, 25);
				this->labelLoading->TabIndex = 0;
				this->labelLoading->Text = text;

				/* -------------------- LoadingScreen --------------------*/
				this->AutoScaleDimensions = SizeF(6, 13);
				this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = Drawing::Size(184, 61);
				this->Controls->Add(this->tableLayout1);
				this->MaximizeBox = false;
				this->Name = L"LoadingScreen";
				this->StartPosition = FormStartPosition::CenterScreen;
			}

			void timer_Tick(Object^ sender, EventArgs^ e)
			{
				tickCount = (tickCount + 1) % 4;
				String^ loadingText = text;
				for (int i = 0; i < tickCount; i++)
				{
					loadingText += ".";
				}
				this->labelLoading->Text = loadingText;
			}
	};
}
