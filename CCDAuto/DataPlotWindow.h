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
	/// Summary for DataPlotWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DataPlotWindow : public System::Windows::Forms::Form
	{
	public:
		static DataPlotWindow^ FormPtr;
		static int numDataPts, numFitPts;
		static float *xData=NULL, *yData, *xFit, *yFit;
		DataPlotWindow(void)
		{
			InitializeComponent();
			FormPtr = this;
			PlotWindowExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DataPlotWindow()
		{
			if (components)
			{
				delete components;
			}
			PlotWindowExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  OkButton;
	private: componentXtra::XYGraph^  xyGraph;

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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.78679F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.21321F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(504, 333);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(214, 299);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 2;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &DataPlotWindow::OkButton_Click);
			// 
			// xyGraph
			// 
			this->xyGraph->BackColor = System::Drawing::Color::White;
			this->xyGraph->Dock = System::Windows::Forms::DockStyle::Fill;
			this->xyGraph->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->xyGraph->Location = System::Drawing::Point(3, 3);
			this->xyGraph->Name = L"xyGraph";
			this->xyGraph->Size = System::Drawing::Size(498, 283);
			this->xyGraph->TabIndex = 3;
			this->xyGraph->XtraAutoScale = true;
			this->xyGraph->XtraClassicLabels = true;
			this->xyGraph->XtraLabelX = L"Radius (pixels)";
			this->xyGraph->XtraLabelY = L"Pixel Value (ADUs)";
			this->xyGraph->XtraLogX = false;
			this->xyGraph->XtraLogY = false;
			this->xyGraph->XtraMinLeftMargin = 0;
			this->xyGraph->XtraSelectPoint = false;
			this->xyGraph->XtraShowGrid = true;
			this->xyGraph->XtraShowLegend = true;
			this->xyGraph->XtraTitle = L"Star PSF";
			this->xyGraph->XtraUpdateCursor = true;
			this->xyGraph->XtraXdigits = 0;
			this->xyGraph->XtraXmax = 0;
			this->xyGraph->XtraXmin = 0;
			this->xyGraph->XtraXstep = 0;
			this->xyGraph->XtraYdigits = 0;
			this->xyGraph->XtraYmax = 0;
			this->xyGraph->XtraYmin = 0;
			this->xyGraph->XtraYstep = 0;
			this->xyGraph->Load += gcnew System::EventHandler(this, &DataPlotWindow::xyGraph_Load);
			// 
			// DataPlotWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 333);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"DataPlotWindow";
			this->Text = L"DataPlotWindow";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataPlotWindow::FormPtr->Hide();
		 }
public: static void ShowTheDialog(void) {
			DataPlotWindow::FormPtr->ShowDialog();
		}
private: System::Void xyGraph_Load(System::Object^  sender, System::EventArgs^  e) {
		    int nData, nFit;

			if (this->xData == NULL)
				return;

			this->xyGraph->RemoveGraphs();
			nData = this->xyGraph->AddGraph("Data",
				System::Drawing::Drawing2D::DashStyle::Solid,
				System::Drawing::Color::Red, 4, true);

            nFit = this->xyGraph->AddGraph("Fit",
				System::Drawing::Drawing2D::DashStyle::Solid,
				System::Drawing::Color::Blue, 1, false);

			for (int i=0; i<this->numDataPts; i++)
               this->xyGraph->AddValue(nData,this->xData[i],this->yData[i]);

			for (int i=0; i<this->numFitPts; i++)
               this->xyGraph->AddValue(nFit,this->xFit[i],this->yFit[i]);

			this->xyGraph->DrawAll();
		 }
};
}
