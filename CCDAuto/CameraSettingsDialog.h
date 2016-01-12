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
	/// Summary for CameraSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CameraSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static CameraSettingsDialog ^FormPtr;
		CameraSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			CameraSettingsDialogExists = TRUE;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CameraSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			CameraSettingsDialogExists = FALSE;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 



	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  ImagingCameraComboBox;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  SpectroCameraComboBox;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label4;
//	private: System::Windows::Forms::ComboBox^  TrackingCameraComboBox;
	private: System::Windows::Forms::ComboBox^  TrackingCameraComboBox;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;


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
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->TrackingCameraComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SpectroCameraComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ImagingCameraComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox4, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(224, 251);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel6);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 127);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(218, 56);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Tracking CCD";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25.66372F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				74.33628F)));
			this->tableLayoutPanel6->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->TrackingCameraComboBox, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(212, 37);
			this->tableLayoutPanel6->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Camera:";
			// 
			// TrackingCameraComboBox
			// 
			this->TrackingCameraComboBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TrackingCameraComboBox->FormattingEnabled = true;
			this->TrackingCameraComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Apogee AP-47p", L"Apogee U8300", 
				L"Starlight Xpress MX-916", L"Meade LPI #2", L"Canon 350D", L"StarShoot Pro", L"StarShoot Autoguider"});
			this->TrackingCameraComboBox->Location = System::Drawing::Point(57, 8);
			this->TrackingCameraComboBox->Name = L"TrackingCameraComboBox";
			this->TrackingCameraComboBox->Size = System::Drawing::Size(149, 21);
			this->TrackingCameraComboBox->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 189);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(218, 59);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(126, 18);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 5;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &CameraSettingsDialog::CancelButton_Clicked);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(17, 18);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 2;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &CameraSettingsDialog::OkButton_Clicked);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel4);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 65);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(218, 56);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Spectrograph CCD";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25.66372F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				74.33628F)));
			this->tableLayoutPanel4->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->SpectroCameraComboBox, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(212, 37);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Camera:";
			// 
			// SpectroCameraComboBox
			// 
			this->SpectroCameraComboBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SpectroCameraComboBox->FormattingEnabled = true;
			this->SpectroCameraComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Apogee AP-47p", L"Apogee U8300", 
				L"Starlight Xpress MX-916", L"Meade LPI #2", L"Canon 350D", L"StarShoot Pro", L"StarShoot AutoGuider"});
			this->SpectroCameraComboBox->Location = System::Drawing::Point(57, 8);
			this->SpectroCameraComboBox->Name = L"SpectroCameraComboBox";
			this->SpectroCameraComboBox->Size = System::Drawing::Size(149, 21);
			this->SpectroCameraComboBox->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel3);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(218, 56);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Imaging CCD";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25.66372F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				74.33628F)));
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->ImagingCameraComboBox, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(212, 37);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Camera:";
			// 
			// ImagingCameraComboBox
			// 
			this->ImagingCameraComboBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ImagingCameraComboBox->FormattingEnabled = true;
			this->ImagingCameraComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Apogee AP-47p", L"Apogee U8300", 
				L"Starlight Xpress MX-916", L"Meade LPI #2", L"Canon 350D", L"StarShoot Pro", L"StarShoot Autoguider"});
			this->ImagingCameraComboBox->Location = System::Drawing::Point(57, 8);
			this->ImagingCameraComboBox->Name = L"ImagingCameraComboBox";
			this->ImagingCameraComboBox->Size = System::Drawing::Size(149, 21);
			this->ImagingCameraComboBox->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->Location = System::Drawing::Point(0, 0);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 100);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25.66372F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				74.33628F)));
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(200, 100);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 26);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Camera:";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Apogee AP-47p", L"Starlight Xpress MX-916"});
			this->comboBox1->Location = System::Drawing::Point(57, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(149, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// CameraSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 251);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CameraSettingsDialog";
			this->Text = L"CameraSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int index;

			 index = FormPtr->ImagingCameraComboBox->SelectedIndex;
			 switch (index) {
				 case 0: // Apogee AP-47p
					 strcpy_s(ccdSettings.ImagingType, APOGEE47PCCD);
					 strcpy_s(ccdSettings.ImagingPort, "LP1");
					 break;
				 case 1: // Apogee U8300
					 strcpy_s(ccdSettings.ImagingType, APOGEEU8300CCD);
					 strcpy_s(ccdSettings.ImagingPort, "USB");
					 break;
				 case 2: // Starlight XPress
					 strcpy_s(ccdSettings.ImagingType, STARLIGHTXPRESSCCD);
					 strcpy_s(ccdSettings.ImagingPort, "USB");
					 break;
				 case 3: // Meade LPI
					 strcpy_s(ccdSettings.ImagingType, MEADECCD);
					 strcpy_s(ccdSettings.ImagingPort, "USB");
					 break;
				 case 4: // Canon 350D
					 strcpy_s(ccdSettings.ImagingType, CANONCCD);
					 strcpy_s(ccdSettings.ImagingPort, "USB");
					 break;
				 case 5: // StarShoot Pro
					 strcpy_s(ccdSettings.ImagingType, STARSHOOTPRO);
					 strcpy_s(ccdSettings.ImagingPort, "USB");
					 break;
				 case 6: // StarShoot Autoguider
					 strcpy_s(ccdSettings.ImagingType, STARSHOOTAUTOGUIDER);
					 strcpy_s(ccdSettings.ImagingPort, "USB");
					 break;
			 }

			 index = FormPtr->SpectroCameraComboBox->SelectedIndex;
			 switch (index) {
				 case 0: // Apogee AP-47p
					 strcpy_s(ccdSettings.SpectroType, APOGEE47PCCD);
					 strcpy_s(ccdSettings.SpectroPort, "LP1");
					 break;
				 case 1: // Apogee U8300
					 strcpy_s(ccdSettings.SpectroType, APOGEEU8300CCD);
					 strcpy_s(ccdSettings.SpectroPort, "LP1");
					 break;
				 case 2: // Starlight XPress
					 strcpy_s(ccdSettings.SpectroType, STARLIGHTXPRESSCCD);
					 strcpy_s(ccdSettings.SpectroPort, "USB");
					 break;
				 case 3: // Meade LPI
					 strcpy_s(ccdSettings.SpectroType, MEADECCD);
					 strcpy_s(ccdSettings.SpectroPort, "USB");
					 break;
				 case 4: // Canon 350D
					 strcpy_s(ccdSettings.SpectroType, CANONCCD);
					 strcpy_s(ccdSettings.SpectroPort, "USB");
					 break;
				 case 5: // StarShoot Pro
					 strcpy_s(ccdSettings.SpectroType, STARSHOOTPRO);
					 strcpy_s(ccdSettings.SpectroPort, "USB");
					 break;
				 case 6: // StarShoot Autoguider
					 strcpy_s(ccdSettings.SpectroType, STARSHOOTAUTOGUIDER);
					 strcpy_s(ccdSettings.SpectroPort, "USB");
					 break;
			 }

			 index = FormPtr->TrackingCameraComboBox->SelectedIndex;
			 switch (index) {
				 case 0: // Apogee AP-47p
					 strcpy_s(ccdSettings.TrackingType, APOGEE47PCCD);
					 strcpy_s(ccdSettings.TrackingPort, "LP1");
					 break;
				 case 1: // Apogee U8300
					 strcpy_s(ccdSettings.TrackingType, APOGEEU8300CCD);
					 strcpy_s(ccdSettings.TrackingPort, "LP1");
					 break;
				 case 2: // Starlight XPress
					 strcpy_s(ccdSettings.TrackingType, STARLIGHTXPRESSCCD);
					 strcpy_s(ccdSettings.TrackingPort, "USB");
					 break;
				 case 3: // Meade LPI
					 strcpy_s(ccdSettings.TrackingType, MEADECCD);
					 strcpy_s(ccdSettings.TrackingPort, "USB");
					 break;
				 case 4: // Canon 350D
					 strcpy_s(ccdSettings.TrackingType, CANONCCD);
					 strcpy_s(ccdSettings.TrackingPort, "USB");
					 break;
				 case 5: // StarShoot Pro
					 strcpy_s(ccdSettings.TrackingType, STARSHOOTPRO);
					 strcpy_s(ccdSettings.TrackingPort, "USB");
					 break;
				 case 6: // StarShoot Autoguider
					 strcpy_s(ccdSettings.TrackingType, STARSHOOTAUTOGUIDER);
					 strcpy_s(ccdSettings.TrackingPort, "USB");
					 break;
			 }
			 FormPtr->Hide();
		 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 CameraSettingsDialog::FormPtr->Hide();
		 }
public: static void ShowTheDialog() {

			if (strstr(ImagingCCD.name,"47p") != NULL) { // Apogee AP-47p
				FormPtr->ImagingCameraComboBox->SelectedIndex = 0;
			} else if (strstr(ImagingCCD.name,"U8300") != NULL) {  // Apogee U8300
				FormPtr->ImagingCameraComboBox->SelectedIndex = 1;
			} else if (strstr(ImagingCCD.name,"Starlight") != NULL) {
				FormPtr->ImagingCameraComboBox->SelectedIndex = 2;
			} else if (strstr(ImagingCCD.name,"Meade") != NULL) {
				FormPtr->ImagingCameraComboBox->SelectedIndex = 3;
			} else if (strstr(ImagingCCD.name,"Canon") != NULL) {
				FormPtr->ImagingCameraComboBox->SelectedIndex = 4;
			}

			if (strstr(TrackingCCD.name,"47p") != NULL) {  // Apogee AP-47p
				FormPtr->TrackingCameraComboBox->SelectedIndex = 0;
			} else if (strstr(TrackingCCD.name,"U8300") != NULL) {  // Apogee U8300
				FormPtr->TrackingCameraComboBox->SelectedIndex = 1;
			} else if (strstr(TrackingCCD.name,"Starlight") != NULL) {
				FormPtr->TrackingCameraComboBox->SelectedIndex = 2;
			} else if (strstr(TrackingCCD.name,"Meade") != NULL) {
				FormPtr->TrackingCameraComboBox->SelectedIndex = 3;
			} else if (strstr(TrackingCCD.name,"Canon") != NULL) {
				FormPtr->TrackingCameraComboBox->SelectedIndex = 4;
			}

			if (strstr(SpectroCCD.name,"47p") != NULL) {  // Apogee AP-47p
				FormPtr->SpectroCameraComboBox->SelectedIndex = 0;
			} else if (strstr(SpectroCCD.name,"U8300") != NULL) {  // Apogee U8300
				FormPtr->SpectroCameraComboBox->SelectedIndex = 1;
			} else if (strstr(SpectroCCD.name,"Starlight") != NULL) {
				FormPtr->SpectroCameraComboBox->SelectedIndex = 2;
			} else if (strstr(SpectroCCD.name,"Meade") != NULL) {
				FormPtr->SpectroCameraComboBox->SelectedIndex = 3;
			} else if (strstr(SpectroCCD.name,"Canon") != NULL) {
				FormPtr->SpectroCameraComboBox->SelectedIndex = 4;
			}

			FormPtr->ShowDialog();
		}
};
}
