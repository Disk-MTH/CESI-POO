#pragma once

using namespace Projet_POO;
using namespace System;
using namespace Windows::Forms;
using namespace Drawing;
using namespace Data;

namespace Projet_POO
{
	public ref class ToastMessage sealed : public Form
	{
		public:
			ToastMessage(Form^ parent, String^ message, Color color, const int displayTime)
			{
				this->parent = parent;
				this->message = message;
				this->color = color;
				this->displayTime = displayTime;
				initialize();
			}

			void show()
			{
				this->Visible = true;
			}

			void close()
			{
				this->Visible = false;
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
				auto textSize = TextRenderer::MeasureText(message, labelMessage->Font);
				this->FormBorderStyle = Windows::Forms::FormBorderStyle::None;
				this->StartPosition = FormStartPosition::Manual;
				this->MinimumSize = Drawing::Size(100, 50);
				this->Size = Drawing::Size(textSize.Width + 10, textSize.Height);
				this->Location = Point(this->parent->Location.X + this->parent->Width / 2 - this->Width / 2, this->parent->Location.Y + this->parent->Height + 10);
				this->Controls->Add(this->tableLayout1);

				auto path = gcnew Drawing2D::GraphicsPath();
				path->AddArc(0, 0, 25, 25, 180, 90);
				path->AddArc(this->Width - 25, 0, 25, 25, -90, 90);
				path->AddArc(this->Width - 25, this->Height - 25, 25, 25, 0, 90);
				path->AddArc(0, this->Height - 25, 25, 25, 90, 90);
				path->CloseAllFigures();

				this->Region = gcnew Drawing::Region(path);
			}

			void timer_Tick(Object^ sender, EventArgs^ e)
			{
				this->close();
				this->timer->Stop();
			}
	};
}
