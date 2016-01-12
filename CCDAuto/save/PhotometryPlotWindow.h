#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "doRoutines.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for PhotometryPlotWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PhotometryPlotWindow : public System::Windows::Forms::Form
	{
	public:
		static PhotometryPlotWindow^ FormPtr;
		static bool VersusUT=true;
	private: System::Windows::Forms::Button^  ClearButton;
	public: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::RadioButton^  VSHJDRadioButton;
	private: System::Windows::Forms::RadioButton^  VSUTRadioButton;
	public:	 static bool VersusHJD=false;
	public:	PhotometryPlotWindow(void)
		{
			InitializeComponent();
			FormPtr = this;
			PhotometryPlotWindowExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PhotometryPlotWindow()
		{
			if (components)
			{
				delete components;
			}
			PhotometryPlotWindowExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: componentXtra::XYGraph^  xyGraphTop;
	private: componentXtra::XYGraph^  xyGraphBottom;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::CheckBox^  AutoScaleCheckBox;





	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->xyGraphTop = (gcnew componentXtra::XYGraph());
			this->xyGraphBottom = (gcnew componentXtra::XYGraph());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->AutoScaleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->VSHJDRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->VSUTRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->xyGraphTop, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->xyGraphBottom, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50.00359F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 49.99641F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 57)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(705, 559);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// xyGraphTop
			// 
			this->xyGraphTop->BackColor = System::Drawing::Color::White;
			this->xyGraphTop->Dock = System::Windows::Forms::DockStyle::Fill;
			this->xyGraphTop->ForeColor = System::Drawing::Color::Black;
			this->xyGraphTop->Location = System::Drawing::Point(3, 3);
			this->xyGraphTop->Name = L"xyGraphTop";
			this->xyGraphTop->Size = System::Drawing::Size(699, 245);
			this->xyGraphTop->TabIndex = 0;
			this->xyGraphTop->XtraAutoScale = false;
			this->xyGraphTop->XtraClassicLabels = true;
			this->xyGraphTop->XtraLabelX = L"UT (Hrs)";
			this->xyGraphTop->XtraLabelY = L"-(V-C)       (mags)";
			this->xyGraphTop->XtraLogX = false;
			this->xyGraphTop->XtraLogY = false;
			this->xyGraphTop->XtraMinLeftMargin = 0;
			this->xyGraphTop->XtraSelectPoint = false;
			this->xyGraphTop->XtraShowGrid = true;
			this->xyGraphTop->XtraShowLegend = true;
			this->xyGraphTop->XtraTitle = L"Plot of -(V-C) vs UT";
			this->xyGraphTop->XtraUpdateCursor = true;
			this->xyGraphTop->XtraXdigits = 0;
			this->xyGraphTop->XtraXmax = 24;
			this->xyGraphTop->XtraXmin = 0;
			this->xyGraphTop->XtraXstep = 0;
			this->xyGraphTop->XtraYdigits = 0;
			this->xyGraphTop->XtraYmax = 1;
			this->xyGraphTop->XtraYmin = -1;
			this->xyGraphTop->XtraYstep = 0;
			this->xyGraphTop->Load += gcnew System::EventHandler(this, &PhotometryPlotWindow::xyGraphTop_Load);
			// 
			// xyGraphBottom
			// 
			this->xyGraphBottom->BackColor = System::Drawing::Color::White;
			this->xyGraphBottom->Dock = System::Windows::Forms::DockStyle::Fill;
			this->xyGraphBottom->ForeColor = System::Drawing::Color::Black;
			this->xyGraphBottom->Location = System::Drawing::Point(3, 254);
			this->xyGraphBottom->Name = L"xyGraphBottom";
			this->xyGraphBottom->Size = System::Drawing::Size(699, 244);
			this->xyGraphBottom->TabIndex = 1;
			this->xyGraphBottom->XtraAutoScale = false;
			this->xyGraphBottom->XtraClassicLabels = true;
			this->xyGraphBottom->XtraLabelX = L"UT (hrs)";
			this->xyGraphBottom->XtraLabelY = L"-(K-C)        (mags)";
			this->xyGraphBottom->XtraLogX = false;
			this->xyGraphBottom->XtraLogY = false;
			this->xyGraphBottom->XtraMinLeftMargin = 0;
			this->xyGraphBottom->XtraSelectPoint = false;
			this->xyGraphBottom->XtraShowGrid = true;
			this->xyGraphBottom->XtraShowLegend = true;
			this->xyGraphBottom->XtraTitle = L"Plot of -(K-C) vs UT";
			this->xyGraphBottom->XtraUpdateCursor = true;
			this->xyGraphBottom->XtraXdigits = 0;
			this->xyGraphBottom->XtraXmax = 24;
			this->xyGraphBottom->XtraXmin = 0;
			this->xyGraphBottom->XtraXstep = 0;
			this->xyGraphBottom->XtraYdigits = 0;
			this->xyGraphBottom->XtraYmax = 1;
			this->xyGraphBottom->XtraYmin = -1;
			this->xyGraphBottom->XtraYstep = 0;
			this->xyGraphBottom->Load += gcnew System::EventHandler(this, &PhotometryPlotWindow::xyGraphBottom_Load);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				205)));
			this->tableLayoutPanel2->Controls->Add(this->ClearButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->CloseButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->AutoScaleCheckBox, 3, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 504);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(699, 52);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseButton->Location = System::Drawing::Point(44, 14);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 3;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &PhotometryPlotWindow::CloseButton_Click);
			// 
			// AutoScaleCheckBox
			// 
			this->AutoScaleCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AutoScaleCheckBox->AutoSize = true;
			this->AutoScaleCheckBox->Location = System::Drawing::Point(558, 17);
			this->AutoScaleCheckBox->Name = L"AutoScaleCheckBox";
			this->AutoScaleCheckBox->Size = System::Drawing::Size(75, 17);
			this->AutoScaleCheckBox->TabIndex = 4;
			this->AutoScaleCheckBox->Text = L"AutoScale";
			this->AutoScaleCheckBox->UseVisualStyleBackColor = true;
			this->AutoScaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &PhotometryPlotWindow::AutoScaleCheckButton_CheckChanged);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->Controls->Add(this->VSHJDRadioButton, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->VSUTRadioButton, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(331, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(158, 46);
			this->tableLayoutPanel3->TabIndex = 6;
			// 
			// VSHJDRadioButton
			// 
			this->VSHJDRadioButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->VSHJDRadioButton->AutoSize = true;
			this->VSHJDRadioButton->Location = System::Drawing::Point(47, 26);
			this->VSHJDRadioButton->Name = L"VSHJDRadioButton";
			this->VSHJDRadioButton->Size = System::Drawing::Size(63, 17);
			this->VSHJDRadioButton->TabIndex = 1;
			this->VSHJDRadioButton->TabStop = true;
			this->VSHJDRadioButton->Text = L"VS HJD";
			this->VSHJDRadioButton->UseVisualStyleBackColor = true;
			// 
			// VSUTRadioButton
			// 
			this->VSUTRadioButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->VSUTRadioButton->AutoSize = true;
			this->VSUTRadioButton->Checked = true;
			this->VSUTRadioButton->Location = System::Drawing::Point(50, 3);
			this->VSUTRadioButton->Name = L"VSUTRadioButton";
			this->VSUTRadioButton->Size = System::Drawing::Size(57, 17);
			this->VSUTRadioButton->TabIndex = 0;
			this->VSUTRadioButton->TabStop = true;
			this->VSUTRadioButton->Text = L"VS UT";
			this->VSUTRadioButton->UseVisualStyleBackColor = true;
			// 
			// ClearButton
			// 
			this->ClearButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ClearButton->Location = System::Drawing::Point(208, 14);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 23);
			this->ClearButton->TabIndex = 7;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &PhotometryPlotWindow::ClearButton_Clicked);
			// 
			// PhotometryPlotWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 559);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"PhotometryPlotWindow";
			this->Text = L"PhotometryPlotWindow";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 PhotometryPlotWindow::Hide();
		 }
public:  static void HideTheDialog(void) {
			 PhotometryPlotWindow::FormPtr->Hide();
		 }
public:  static void ShowTheDialog(void) {

			 PhotometryPlotWindow::FormPtr->Show();
		 }
public:  static void AddGraphPoint(DIFFPHOT *pptr) {

			 int graphNum;
			 float diff, diffErr, x;
			 static bool First=true;

			 if (First || (pptr == NULL)) {
				 PhotometryPlotWindow::FormPtr->xyGraphTop->XtraXmin = ((float) (pptr->UT - 0.1));
				 PhotometryPlotWindow::FormPtr->xyGraphTop->XtraXmax = ((float) (pptr->UT + 0.1 + seriesSettings.duration));
				 PhotometryPlotWindow::FormPtr->xyGraphTop->XtraYmin = (float) 999.0;
				 PhotometryPlotWindow::FormPtr->xyGraphTop->XtraYmax = (float) -999.0;
				 PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraYmin = (float) 999.0;
				 PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraYmax = (float) -999.0;
				 PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraXmin = ((float) (pptr->UT - 0.1));
				 PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraXmax = ((float) (pptr->UT + 0.1 + seriesSettings.duration));
				 First = false;
			 }

			 switch(pptr->Filter) {
				 case 'B':
					 graphNum = 0;
					 break;
				 case 'V':
					 graphNum = 1;
					 break;
				 case 'R':
					 graphNum = 2;
					 break;
				 case 'I':
					 graphNum = 3;
			 }
			 if (PhotometryPlotWindow::FormPtr->VersusUT) {
				 x = pptr->UT;
			 } else {
				 x = ((float) (pptr->HJD - 2450000.5));
			 }
			 diff = -(pptr->VarMag - pptr->CmpMag);
			 if (diff < PhotometryPlotWindow::FormPtr->xyGraphTop->XtraYmin)
				 PhotometryPlotWindow::FormPtr->xyGraphTop->XtraYmin = ((float) (diff - 0.1));
			 if (diff > PhotometryPlotWindow::FormPtr->xyGraphTop->XtraYmax)
				 PhotometryPlotWindow::FormPtr->xyGraphTop->XtraYmax = ((float) (diff + 0.1));
			 diffErr = sqrt(pptr->VarMagErr*pptr->VarMagErr + 
				            pptr->CmpMagErr*pptr->CmpMagErr);
			 PhotometryPlotWindow::FormPtr->xyGraphTop->AddValue(graphNum, x, diff);
			 PhotometryPlotWindow::FormPtr->xyGraphTop->DrawAll();
			 diff = -(pptr->ChkMag - pptr->CmpMag);
			 if (diff < PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraYmin)
				 PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraYmin = ((float) (diff - 0.1));
			 if (diff > PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraYmax)
				 PhotometryPlotWindow::FormPtr->xyGraphBottom->XtraYmax = ((float) (diff + 0.1));
			 diffErr = sqrt(pptr->ChkMagErr*pptr->ChkMagErr + 
				            pptr->CmpMagErr*pptr->CmpMagErr);
			 PhotometryPlotWindow::FormPtr->xyGraphBottom->AddValue(graphNum, x, diff);
			 PhotometryPlotWindow::FormPtr->xyGraphBottom->DrawAll();
			 PhotometryPlotWindow::FormPtr->Refresh();
			 usleep(100000);
		 }
private: System::Void xyGraphTop_Load(System::Object^  sender, System::EventArgs^  e) {

			 this->xyGraphTop->RemoveGraphs();
			 this->xyGraphTop->AddGraph("B Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Blue, 3, true);
			 this->xyGraphTop->AddGraph("V Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Green, 3, true);
			 this->xyGraphTop->AddGraph("R Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Red, 3, true);
			 this->xyGraphTop->AddGraph("I Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Brown, 3, true);
		 }
private: System::Void xyGraphBottom_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->xyGraphBottom->RemoveGraphs();
			 this->xyGraphBottom->AddGraph("B Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Blue, 3, true);
			 this->xyGraphBottom->AddGraph("V Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Green, 3, true);
			 this->xyGraphBottom->AddGraph("R Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Red, 3, true);
			 this->xyGraphBottom->AddGraph("I Filter", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Brown, 3, true);
		 }
private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 PhotometryPlotWindow::Hide();
			 return;
		 }
private: System::Void AutoScaleCheckButton_CheckChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void VSUTButton_CheckChanged(System::Object^  sender, System::EventArgs^  e) {

				this->VersusUT =this->VSUTRadioButton->Checked;
				return;
		 }
private: System::Void VSHJDButton_CheckChanged(System::Object^  sender, System::EventArgs^  e) {

			 	this->VersusHJD =this->VSHJDRadioButton->Checked;
				return;
		 }
private: System::Void ClearButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 xyGraphTop_Load(sender, e);
			 xyGraphBottom_Load(sender, e);
			 return;
		 }
};
}
