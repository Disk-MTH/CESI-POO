#pragma once

namespace Projet_POO
{

	using namespace System;
	using namespace Drawing;
	using namespace Windows::Forms;

	public ref class ToastMessage : public Form
	{
		public:
			ToastMessage(Form^ parent, String^ message, Color color, int displayTime)
			{
				this->parent = parent;
				this->message = message;
				this->color = color;
				this->displayTime = displayTime;
				initialize();
			}

		private:
			Form^ parent;
			String^ message;
			Color color;
			int displayTime;
		
			Timer^ timer;
		
			TableLayoutPanel^ tableLayout1;

			Label^ labelMessage;
		
			void initialize()
			{
				this->timer = gcnew Timer();
				this->tableLayout1 = gcnew TableLayoutPanel();
				this->labelMessage = gcnew Label();
				
				/* -------------------- timer --------------------*/
				this->timer->Interval = this->displayTime;
				this->timer->Tick += gcnew EventHandler(this, &ToastMessage::timer_Tick);
				this->timer->Start();

				/* -------------------- tableLayout1 --------------------*/
				this->tableLayout1->ColumnCount = 1;
				this->tableLayout1->RowCount = 1;
				this->tableLayout1->Dock = DockStyle::Fill;
				this->tableLayout1->CellBorderStyle = TableLayoutPanelCellBorderStyle::None;
				this->tableLayout1->Name = "tableLayout1";
				this->tableLayout1->Controls->Add(this->labelMessage, 0, 0);
				this->tableLayout1->SetColumnSpan(this->labelMessage, 1);
				this->tableLayout1->SetRowSpan(this->labelMessage, 1);

				/* -------------------- labelMessage --------------------*/
				this->labelMessage->Anchor = AnchorStyles::None;
				this->labelMessage->AutoSize = true;
				this->labelMessage->TextAlign = ContentAlignment::MiddleCenter;
				this->labelMessage->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 15);
				this->labelMessage->Name = "labelMessage";
				this->labelMessage->ForeColor = this->color;
				this->labelMessage->Text = this->message;
				
				/* -------------------- ToastMessage --------------------*/
				Drawing::Size textSize = TextRenderer::MeasureText(message, labelMessage->Font);
				
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::None;
				this->StartPosition = FormStartPosition::Manual;
				this->MinimumSize = Drawing::Size(100, 50);
				this->Size = Drawing::Size(textSize.Width, textSize.Height);
				this->Location = Point(parent->Location.X + parent->Width / 2 - this->Width / 2, parent->Location.Y + parent->Height + 10);
				this->Controls->Add(this->tableLayout1);
				
				Drawing2D::GraphicsPath^ path = gcnew Drawing2D::GraphicsPath();
				path->AddArc(0, 0, 20, 20, 180, 90);
				path->AddArc(this->Width - 20, 0, 20, 20, -90, 90);
				path->AddArc(this->Width - 20, this->Height - 20, 20, 20, 0, 90);
				path->AddArc(0, this->Height - 20, 20, 20, 90, 90);
				path->CloseAllFigures();
				
				this->Region = gcnew Drawing::Region(path);
			}

			void timer_Tick(Object^ sender, EventArgs^ e)
			{
				this->Close();
			}
	};
}
