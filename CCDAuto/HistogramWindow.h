#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "stdlib.h"
#include "doRoutines.h"


namespace CCDAuto {

	/// <summary>
	/// Summary for HistogramWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class HistogramWindow : public System::Windows::Forms::Form
	{
	public:
		static HistogramWindow ^FormPtr;
		static CCD *ccd;
		HistogramWindow(void)
		{
			InitializeComponent();
			FormPtr = this;
			HistogramWindowExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HistogramWindow()
		{
			if (components)
			{
				delete components;
				HistogramWindowExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: componentXtra::XYGraph^  xyGraph;
	private: System::Windows::Forms::Button^  OkButton;
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
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->xyGraph = (gcnew componentXtra::XYGraph());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->OkButton, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->xyGraph, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 89.26174F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.73826F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(547, 335);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(236, 305);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 5;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &HistogramWindow::OkButton_Clicked);
			// 
			// xyGraph
			// 
			this->xyGraph->BackColor = System::Drawing::Color::White;
			this->xyGraph->Dock = System::Windows::Forms::DockStyle::Fill;
			this->xyGraph->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->xyGraph->Location = System::Drawing::Point(3, 3);
			this->xyGraph->Name = L"xyGraph";
			this->xyGraph->Size = System::Drawing::Size(541, 293);
			this->xyGraph->TabIndex = 4;
			this->xyGraph->XtraAutoScale = true;
			this->xyGraph->XtraClassicLabels = true;
			this->xyGraph->XtraLabelX = L"Pixel Value (ADUs)";
			this->xyGraph->XtraLabelY = L"Frequency (pixels)";
			this->xyGraph->XtraLogX = false;
			this->xyGraph->XtraLogY = false;
			this->xyGraph->XtraMinLeftMargin = 0;
			this->xyGraph->XtraSelectPoint = false;
			this->xyGraph->XtraShowGrid = true;
			this->xyGraph->XtraShowLegend = true;
			this->xyGraph->XtraTitle = L"Histogram of Current Image Pixel Values";
			this->xyGraph->XtraUpdateCursor = true;
			this->xyGraph->XtraXdigits = 0;
			this->xyGraph->XtraXmax = 0;
			this->xyGraph->XtraXmin = 0;
			this->xyGraph->XtraXstep = 0;
			this->xyGraph->XtraYdigits = 0;
			this->xyGraph->XtraYmax = 0;
			this->xyGraph->XtraYmin = 0;
			this->xyGraph->XtraYstep = 0;
			// 
			// HistogramWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(547, 335);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"HistogramWindow";
			this->Text = L"Pixel Histogram Window";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
public: System::Void ShowTheWindow(void) {

			FormPtr->Show();
			FormPtr->xyGraph_Load();
		}

private: System::Void xyGraph_Load(void) {

			 int Hist[1000], i, nPixels, maxx;
			 unsigned short *pptr, val, index;
			 FRAME *framePtr;

			 FormPtr->xyGraph->RemoveGraphs();
			 FormPtr->xyGraph->AddGraph("LightFrame", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Blue, 1, false);
			 FormPtr->xyGraph->AddGraph("DarkFrame", System::Drawing::Drawing2D::DashStyle::Solid,
				 System::Drawing::Color::Red, 1, false);

			 if (FormPtr->ccd == NULL)
				 return;

			 // Histogram light frame

			 framePtr = &ccd->Image.light_frame;
			 nPixels = framePtr->h * framePtr->w;

			 for (i=0; i<1000; i++) Hist[i] = 0;
			 pptr = framePtr->frame;
			 if (pptr == NULL)
				 return;
			 for (i=0; i<nPixels; i++) {
				 val = *pptr++;
				 index = val/50;
				 if (index > 999)
					 index = 999;
				 Hist[index]++;
			 }
			 maxx = 0;
			 for (i=0; i<1000; i++) {
				 FormPtr->xyGraph->AddValue(0, (float) (i*50), (float) Hist[i]);
				 if (Hist[i] > 0)
					 maxx = i;
			 }
			 FormPtr->xyGraph->XtraXmax;
			 FormPtr->xyGraph->XtraLogY = true;
			 FormPtr->xyGraph->DrawAll();

			 // Histogram dark frame

			 framePtr = &ccd->Image.dark_frame;
			 nPixels = framePtr->h * framePtr->w;

			 for (i=0; i<1000; i++) Hist[i] = 0;
			 pptr = framePtr->frame;
			 if (pptr == NULL)
				 return;
			 for (i=0; i<nPixels; i++) {
				 val = *pptr++;
				 index = val/50;
				 if (index > 999)
					 index = 999;
				 Hist[index]++;
			 }
			 maxx = 0;
			 for (i=0; i<1000; i++) {
				 FormPtr->xyGraph->AddValue(1, (float) (i*50), (float) Hist[i]);
				 if (Hist[i] > 0)
					 maxx = i;
			 }
			 FormPtr->xyGraph->XtraXmax;
			 FormPtr->xyGraph->XtraLogY = true;
			 FormPtr->xyGraph->XtraLogX = true;
			 FormPtr->xyGraph->DrawAll();
			 return;

		 }
};
}
