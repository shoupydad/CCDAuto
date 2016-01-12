#pragma once

//#include "Form1.h"
#include "doRoutines.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CCDAuto {

	/// <summary>
	/// Summary for SlitGuideSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SlitGuideSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static SlitGuideSettingsDialog ^FormPtr;
		SlitGuideSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			SlitGuideSettingsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SlitGuideSettingsDialog()
		{
			if (components)
			{
				delete components;
				SlitGuideSettingsDialogExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ExposureTextBox;
	private: System::Windows::Forms::TextBox^  IntervalTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  YScaleTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  XScaleTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TextBox^  SlitRightYTextBox;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  SlitRightXTextBox;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  SlitLeftYTextBox;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  SlitLeftXTextBox;
	private: System::Windows::Forms::Button^  SetLeftEndButton;


	private: System::Windows::Forms::Button^  CalibrateGuidingButton;
	private: System::Windows::Forms::Button^  SetRightEndButton;






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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SetRightEndButton = (gcnew System::Windows::Forms::Button());
			this->SlitRightYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SlitRightXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SlitLeftYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SlitLeftXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SetLeftEndButton = (gcnew System::Windows::Forms::Button());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalibrateGuidingButton = (gcnew System::Windows::Forms::Button());
			this->YScaleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->XScaleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->IntervalTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ExposureTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				44.93151F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				55.06849F)));
			this->tableLayoutPanel1->Controls->Add(this->OkayButton, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->CancelButton, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 81.57895F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.42105F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(365, 216);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel3);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(167, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(195, 170);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Slit Position";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				49.69325F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50.30675F)));
			this->tableLayoutPanel3->Controls->Add(this->SetRightEndButton, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->SlitRightYTextBox, 1, 3);
			this->tableLayoutPanel3->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->SlitRightXTextBox, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->label6, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->SlitLeftYTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->label7, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->SlitLeftXTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->SetLeftEndButton, 0, 4);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 5;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(189, 151);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// SetRightEndButton
			// 
			this->SetRightEndButton->Location = System::Drawing::Point(96, 123);
			this->SetRightEndButton->Name = L"SetRightEndButton";
			this->SetRightEndButton->Size = System::Drawing::Size(87, 23);
			this->SetRightEndButton->TabIndex = 9;
			this->SetRightEndButton->Text = L"Set Right End";
			this->SetRightEndButton->UseVisualStyleBackColor = true;
			this->SetRightEndButton->Click += gcnew System::EventHandler(this, &SlitGuideSettingsDialog::SetRightEndButton_Clicked);
			// 
			// SlitRightYTextBox
			// 
			this->SlitRightYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SlitRightYTextBox->Location = System::Drawing::Point(96, 95);
			this->SlitRightYTextBox->Name = L"SlitRightYTextBox";
			this->SlitRightYTextBox->Size = System::Drawing::Size(52, 20);
			this->SlitRightYTextBox->TabIndex = 7;
			this->SlitRightYTextBox->Text = L"99.999";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Slit Right Y:";
			// 
			// SlitRightXTextBox
			// 
			this->SlitRightXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SlitRightXTextBox->Location = System::Drawing::Point(96, 65);
			this->SlitRightXTextBox->Name = L"SlitRightXTextBox";
			this->SlitRightXTextBox->Size = System::Drawing::Size(52, 20);
			this->SlitRightXTextBox->TabIndex = 5;
			this->SlitRightXTextBox->Text = L"99.999";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(28, 68);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Slit Right X:";
			// 
			// SlitLeftYTextBox
			// 
			this->SlitLeftYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SlitLeftYTextBox->Location = System::Drawing::Point(96, 35);
			this->SlitLeftYTextBox->Name = L"SlitLeftYTextBox";
			this->SlitLeftYTextBox->Size = System::Drawing::Size(52, 20);
			this->SlitLeftYTextBox->TabIndex = 3;
			this->SlitLeftYTextBox->Text = L"999.999";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 38);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Slit Left Y:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(35, 8);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Slit Left X:";
			// 
			// SlitLeftXTextBox
			// 
			this->SlitLeftXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SlitLeftXTextBox->Location = System::Drawing::Point(96, 5);
			this->SlitLeftXTextBox->Name = L"SlitLeftXTextBox";
			this->SlitLeftXTextBox->Size = System::Drawing::Size(52, 20);
			this->SlitLeftXTextBox->TabIndex = 1;
			this->SlitLeftXTextBox->Text = L"999.999";
			// 
			// SetLeftEndButton
			// 
			this->SetLeftEndButton->Location = System::Drawing::Point(3, 123);
			this->SetLeftEndButton->Name = L"SetLeftEndButton";
			this->SetLeftEndButton->Size = System::Drawing::Size(87, 23);
			this->SetLeftEndButton->TabIndex = 8;
			this->SetLeftEndButton->Text = L"Set Left End";
			this->SetLeftEndButton->UseVisualStyleBackColor = true;
			this->SetLeftEndButton->Click += gcnew System::EventHandler(this, &SlitGuideSettingsDialog::SetLeftEndButton_Clicked);
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(44, 184);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 0;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &SlitGuideSettingsDialog::OkayButton_Clicked);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(227, 184);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &SlitGuideSettingsDialog::CancelButton_Clicked);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(158, 170);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Guiding";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				57.51634F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				42.48366F)));
			this->tableLayoutPanel2->Controls->Add(this->CalibrateGuidingButton, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->YScaleTextBox, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->XScaleTextBox, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->IntervalTextBox, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->ExposureTextBox, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 5;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(152, 151);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// CalibrateGuidingButton
			// 
			this->CalibrateGuidingButton->Location = System::Drawing::Point(3, 123);
			this->CalibrateGuidingButton->Name = L"CalibrateGuidingButton";
			this->CalibrateGuidingButton->Size = System::Drawing::Size(75, 23);
			this->CalibrateGuidingButton->TabIndex = 9;
			this->CalibrateGuidingButton->Text = L"Calibrate";
			this->CalibrateGuidingButton->UseVisualStyleBackColor = true;
			this->CalibrateGuidingButton->Click += gcnew System::EventHandler(this, &SlitGuideSettingsDialog::CalibrateGuidingButton_Clicked);
			// 
			// YScaleTextBox
			// 
			this->YScaleTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->YScaleTextBox->Location = System::Drawing::Point(90, 95);
			this->YScaleTextBox->Name = L"YScaleTextBox";
			this->YScaleTextBox->Size = System::Drawing::Size(52, 20);
			this->YScaleTextBox->TabIndex = 7;
			this->YScaleTextBox->Text = L"99.999";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 98);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Y Scale (\"/pix):";
			// 
			// XScaleTextBox
			// 
			this->XScaleTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->XScaleTextBox->Location = System::Drawing::Point(90, 65);
			this->XScaleTextBox->Name = L"XScaleTextBox";
			this->XScaleTextBox->Size = System::Drawing::Size(52, 20);
			this->XScaleTextBox->TabIndex = 5;
			this->XScaleTextBox->Text = L"99.999";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"X Scale (\"/pix):";
			// 
			// IntervalTextBox
			// 
			this->IntervalTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->IntervalTextBox->Location = System::Drawing::Point(90, 35);
			this->IntervalTextBox->Name = L"IntervalTextBox";
			this->IntervalTextBox->Size = System::Drawing::Size(52, 20);
			this->IntervalTextBox->TabIndex = 3;
			this->IntervalTextBox->Text = L"999.999";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Interval (s):";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Exposure (s):";
			// 
			// ExposureTextBox
			// 
			this->ExposureTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ExposureTextBox->Location = System::Drawing::Point(90, 5);
			this->ExposureTextBox->Name = L"ExposureTextBox";
			this->ExposureTextBox->Size = System::Drawing::Size(52, 20);
			this->ExposureTextBox->TabIndex = 1;
			this->ExposureTextBox->Text = L"999.999";
			// 
			// SlitGuideSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(365, 216);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"SlitGuideSettingsDialog";
			this->Text = L"Slit Guide Settings Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 FormPtr->GetExposureTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.exposure);
			 FormPtr->GetIntervalTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.interval);
			 FormPtr->GetXScaleTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.XScale);
			 FormPtr->GetYScaleTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.YScale);
			 FormPtr->GetSlitLeftXTextBox(buffer);
			 sscanf_s(buffer, "%d", &GuidingSlitSettings.slitX0);
			 FormPtr->GetSlitLeftYTextBox(buffer);
			 sscanf_s(buffer, "%d", &GuidingSlitSettings.slitY0);
			 FormPtr->GetSlitRightXTextBox(buffer);
			 sscanf_s(buffer, "%d", &GuidingSlitSettings.slitX1);
			 FormPtr->GetSlitRightYTextBox(buffer);
			 sscanf_s(buffer, "%d", &GuidingSlitSettings.slitY1);
			 FormPtr->Hide();

			 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
public: static void ShowTheDialog(void) {

			char buffer[80];

			sprintf_s(buffer, sizeof(buffer), "%7.3f", GuidingSlitSettings.exposure);
			FormPtr->SetExposureTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%7.3f", GuidingSlitSettings.interval);
			FormPtr->SetIntervalTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%6.3f", GuidingSlitSettings.XScale);
			FormPtr->SetXScaleTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%6.3f", GuidingSlitSettings.YScale);
			FormPtr->SetYScaleTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%d", GuidingSlitSettings.slitX0);
			FormPtr->SetSlitLeftXTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%d", GuidingSlitSettings.slitY0);
			FormPtr->SetSlitLeftYTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%d", GuidingSlitSettings.slitX1);
			FormPtr->SetSlitRightXTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%d", GuidingSlitSettings.slitY1);
			FormPtr->SetSlitRightYTextBox(buffer);

			FormPtr->Show();
		}
public: static void SetExposureTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->ExposureTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetExposureTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->ExposureTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetIntervalTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->IntervalTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetIntervalTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->IntervalTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetXScaleTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->XScaleTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetXScaleTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->XScaleTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetYScaleTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->YScaleTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetYScaleTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->YScaleTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitLeftXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitLeftXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitLeftXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitLeftXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitLeftYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitLeftYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitLeftYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitLeftYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitRightXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitRightXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitRightXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitRightXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitRightYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitRightYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitRightYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitRightYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
private: System::Void CalibrateGuidingButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void SetLeftEndButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];
			 int x, y;

			 CalibrateSlitEnd(&x, &y);
			 sprintf_s(buffer, sizeof(buffer), "%d", x);
			 FormPtr->SetSlitLeftXTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", y);
			 FormPtr->SetSlitLeftYTextBox(buffer);
		 }
private: System::Void SetRightEndButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];
			 int x, y;

			 CalibrateSlitEnd(&x, &y);
			 sprintf_s(buffer, sizeof(buffer), "%d", x);
			 FormPtr->SetSlitRightXTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", y);
			 FormPtr->SetSlitRightYTextBox(buffer);
		 }
};
}
