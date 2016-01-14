#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

#include "doRoutines.h"
#include "Form1.h"
#include "OpenCalDialog.h"

//#include "DefineListDialog.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for PhotometrySettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PhotometrySettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static PhotometrySettingsDialog ^ FormPtr;
		PhotometrySettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			PhotometrySettingsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PhotometrySettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			PhotometrySettingsDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  AperatureRadiusTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  ZeroPointTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  SkyInnerRadiusTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  SkyOuterRadiusTextBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  SkySigmaCutTextBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  FindRadiusTextBox;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  MinPeakTextBox;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  MinFWHMTextBox;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  MaxFWHMTextBox;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  MinSeparationTextBox;

	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  LogFileBaseNameTextBox;

	private: System::Windows::Forms::CheckBox^  PlotResultsCheckBox;
	private: System::Windows::Forms::CheckBox^  CCDAutoCheckBox;


	private: System::Windows::Forms::CheckBox^  OffsetSkyCheckBox;

	private: System::Windows::Forms::CheckBox^  AutoFindCheckBox;
	private: System::Windows::Forms::Button^  StopBatchButton;
	private: System::Windows::Forms::Button^  StartBatchButton;


	private: System::Windows::Forms::Button^  SelectLogFolderButton;
	private: System::Windows::Forms::TextBox^  LogDirTextBox;
	private: System::Windows::Forms::CheckBox^  UseAstrometryCheckBox;
	private: System::Windows::Forms::CheckBox^  CalibrateCheckBox;
	private: System::Windows::Forms::CheckBox^  AAVSOCheckBox;
	private: System::Windows::Forms::CheckBox^  InteractiveCheckBox;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  MaxPeakTextBox;

	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::RadioButton^  FWHMRadioButton;
	private: System::Windows::Forms::RadioButton^  PixelRadioButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::TextBox^  ApRadiusFWHMTextBox;






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
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->InteractiveCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LogDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SelectLogFolderButton = (gcnew System::Windows::Forms::Button());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->LogFileBaseNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StartBatchButton = (gcnew System::Windows::Forms::Button());
			this->StopBatchButton = (gcnew System::Windows::Forms::Button());
			this->UseAstrometryCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CalibrateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->OffsetSkyCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoFindCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CCDAutoCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AAVSOCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PlotResultsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->MaxPeakTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->FindRadiusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->MinPeakTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->MinSeparationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->MaxFWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->MinFWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SkyInnerRadiusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SkyOuterRadiusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SkySigmaCutTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ZeroPointTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FWHMRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->PixelRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ApRadiusFWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AperatureRadiusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90.50132F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.498681F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(419, 407);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 371);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(413, 33);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(272, 5);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 4;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &PhotometrySettingsDialog::CancelButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(65, 5);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 1;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &PhotometrySettingsDialog::OkButton_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.73124F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.26876F)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox4, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30.38674F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 69.61326F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(413, 362);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel7);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(196, 112);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(214, 247);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Misc. Parameters";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.84615F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.15385F)));
			this->tableLayoutPanel7->Controls->Add(this->InteractiveCheckBox, 1, 3);
			this->tableLayoutPanel7->Controls->Add(this->LogDirTextBox, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->SelectLogFolderButton, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->label20, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->LogFileBaseNameTextBox, 1, 1);
			this->tableLayoutPanel7->Controls->Add(this->StartBatchButton, 0, 6);
			this->tableLayoutPanel7->Controls->Add(this->StopBatchButton, 1, 6);
			this->tableLayoutPanel7->Controls->Add(this->UseAstrometryCheckBox, 0, 5);
			this->tableLayoutPanel7->Controls->Add(this->CalibrateCheckBox, 1, 5);
			this->tableLayoutPanel7->Controls->Add(this->OffsetSkyCheckBox, 1, 4);
			this->tableLayoutPanel7->Controls->Add(this->AutoFindCheckBox, 0, 4);
			this->tableLayoutPanel7->Controls->Add(this->CCDAutoCheckBox, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->AAVSOCheckBox, 0, 3);
			this->tableLayoutPanel7->Controls->Add(this->PlotResultsCheckBox, 1, 2);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 7;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.70833F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.0625F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15.10417F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.09756F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15.12195F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.95122F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(208, 228);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// InteractiveCheckBox
			// 
			this->InteractiveCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->InteractiveCheckBox->AutoSize = true;
			this->InteractiveCheckBox->Location = System::Drawing::Point(114, 97);
			this->InteractiveCheckBox->Name = L"InteractiveCheckBox";
			this->InteractiveCheckBox->Size = System::Drawing::Size(76, 17);
			this->InteractiveCheckBox->TabIndex = 20;
			this->InteractiveCheckBox->Text = L"Interactive";
			this->InteractiveCheckBox->UseVisualStyleBackColor = true;
			// 
			// LogDirTextBox
			// 
			this->LogDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LogDirTextBox->BackColor = System::Drawing::Color::White;
			this->LogDirTextBox->Location = System::Drawing::Point(114, 7);
			this->LogDirTextBox->Name = L"LogDirTextBox";
			this->LogDirTextBox->Size = System::Drawing::Size(91, 20);
			this->LogDirTextBox->TabIndex = 16;
			this->LogDirTextBox->WordWrap = false;
			// 
			// SelectLogFolderButton
			// 
			this->SelectLogFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SelectLogFolderButton->Location = System::Drawing::Point(6, 6);
			this->SelectLogFolderButton->Name = L"SelectLogFolderButton";
			this->SelectLogFolderButton->Size = System::Drawing::Size(98, 21);
			this->SelectLogFolderButton->TabIndex = 15;
			this->SelectLogFolderButton->Text = L"Select Log Folder";
			this->SelectLogFolderButton->UseVisualStyleBackColor = true;
			this->SelectLogFolderButton->Click += gcnew System::EventHandler(this, &PhotometrySettingsDialog::SelectLogFolderButton_Clicked);
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(9, 41);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(99, 13);
			this->label20->TabIndex = 2;
			this->label20->Text = L"Log file base name:";
			// 
			// LogFileBaseNameTextBox
			// 
			this->LogFileBaseNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LogFileBaseNameTextBox->BackColor = System::Drawing::Color::White;
			this->LogFileBaseNameTextBox->Location = System::Drawing::Point(114, 37);
			this->LogFileBaseNameTextBox->Name = L"LogFileBaseNameTextBox";
			this->LogFileBaseNameTextBox->Size = System::Drawing::Size(91, 20);
			this->LogFileBaseNameTextBox->TabIndex = 6;
			this->LogFileBaseNameTextBox->Text = L"photometry.log";
			this->LogFileBaseNameTextBox->WordWrap = false;
			// 
			// StartBatchButton
			// 
			this->StartBatchButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StartBatchButton->Location = System::Drawing::Point(18, 199);
			this->StartBatchButton->Name = L"StartBatchButton";
			this->StartBatchButton->Size = System::Drawing::Size(75, 22);
			this->StartBatchButton->TabIndex = 13;
			this->StartBatchButton->Text = L"Start Batch";
			this->StartBatchButton->UseVisualStyleBackColor = true;
			this->StartBatchButton->Click += gcnew System::EventHandler(this, &PhotometrySettingsDialog::StartBatchButton_Click);
			// 
			// StopBatchButton
			// 
			this->StopBatchButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StopBatchButton->Location = System::Drawing::Point(122, 199);
			this->StopBatchButton->Name = L"StopBatchButton";
			this->StopBatchButton->Size = System::Drawing::Size(75, 22);
			this->StopBatchButton->TabIndex = 14;
			this->StopBatchButton->Text = L"Stop Batch";
			this->StopBatchButton->UseVisualStyleBackColor = true;
			this->StopBatchButton->Click += gcnew System::EventHandler(this, &PhotometrySettingsDialog::StopBatchButton_Click);
			// 
			// UseAstrometryCheckBox
			// 
			this->UseAstrometryCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->UseAstrometryCheckBox->AutoSize = true;
			this->UseAstrometryCheckBox->Location = System::Drawing::Point(3, 162);
			this->UseAstrometryCheckBox->Name = L"UseAstrometryCheckBox";
			this->UseAstrometryCheckBox->Size = System::Drawing::Size(97, 17);
			this->UseAstrometryCheckBox->TabIndex = 17;
			this->UseAstrometryCheckBox->Text = L"Use Astrometry";
			this->UseAstrometryCheckBox->UseVisualStyleBackColor = true;
			// 
			// CalibrateCheckBox
			// 
			this->CalibrateCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CalibrateCheckBox->AutoSize = true;
			this->CalibrateCheckBox->Location = System::Drawing::Point(114, 162);
			this->CalibrateCheckBox->Name = L"CalibrateCheckBox";
			this->CalibrateCheckBox->Size = System::Drawing::Size(67, 17);
			this->CalibrateCheckBox->TabIndex = 18;
			this->CalibrateCheckBox->Text = L"Calibrate";
			this->CalibrateCheckBox->UseVisualStyleBackColor = true;
			// 
			// OffsetSkyCheckBox
			// 
			this->OffsetSkyCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OffsetSkyCheckBox->AutoSize = true;
			this->OffsetSkyCheckBox->Location = System::Drawing::Point(114, 127);
			this->OffsetSkyCheckBox->Name = L"OffsetSkyCheckBox";
			this->OffsetSkyCheckBox->Size = System::Drawing::Size(75, 17);
			this->OffsetSkyCheckBox->TabIndex = 10;
			this->OffsetSkyCheckBox->Text = L"Offset Sky";
			this->OffsetSkyCheckBox->UseVisualStyleBackColor = true;
			// 
			// AutoFindCheckBox
			// 
			this->AutoFindCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AutoFindCheckBox->AutoSize = true;
			this->AutoFindCheckBox->Location = System::Drawing::Point(3, 127);
			this->AutoFindCheckBox->Name = L"AutoFindCheckBox";
			this->AutoFindCheckBox->Size = System::Drawing::Size(71, 17);
			this->AutoFindCheckBox->TabIndex = 9;
			this->AutoFindCheckBox->Text = L"Auto Find";
			this->AutoFindCheckBox->UseVisualStyleBackColor = true;
			// 
			// CCDAutoCheckBox
			// 
			this->CCDAutoCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDAutoCheckBox->AutoSize = true;
			this->CCDAutoCheckBox->Location = System::Drawing::Point(3, 67);
			this->CCDAutoCheckBox->Name = L"CCDAutoCheckBox";
			this->CCDAutoCheckBox->Size = System::Drawing::Size(105, 17);
			this->CCDAutoCheckBox->TabIndex = 7;
			this->CCDAutoCheckBox->Text = L"CCDAuto Format";
			this->CCDAutoCheckBox->UseVisualStyleBackColor = true;
			// 
			// AAVSOCheckBox
			// 
			this->AAVSOCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AAVSOCheckBox->AutoSize = true;
			this->AAVSOCheckBox->Location = System::Drawing::Point(3, 97);
			this->AAVSOCheckBox->Name = L"AAVSOCheckBox";
			this->AAVSOCheckBox->Size = System::Drawing::Size(97, 17);
			this->AAVSOCheckBox->TabIndex = 19;
			this->AAVSOCheckBox->Text = L"AAVSO Format";
			this->AAVSOCheckBox->UseVisualStyleBackColor = true;
			// 
			// PlotResultsCheckBox
			// 
			this->PlotResultsCheckBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->PlotResultsCheckBox->AutoSize = true;
			this->PlotResultsCheckBox->Location = System::Drawing::Point(114, 67);
			this->PlotResultsCheckBox->Name = L"PlotResultsCheckBox";
			this->PlotResultsCheckBox->Size = System::Drawing::Size(82, 17);
			this->PlotResultsCheckBox->TabIndex = 8;
			this->PlotResultsCheckBox->Text = L"Plot Results";
			this->PlotResultsCheckBox->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel6);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(3, 112);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(187, 247);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Find Parameters";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 3;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				27.22222F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				22.77778F)));
			this->tableLayoutPanel6->Controls->Add(this->label22, 2, 2);
			this->tableLayoutPanel6->Controls->Add(this->MaxPeakTextBox, 1, 2);
			this->tableLayoutPanel6->Controls->Add(this->label21, 0, 2);
			this->tableLayoutPanel6->Controls->Add(this->label10, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->FindRadiusTextBox, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->label11, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->label12, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->MinPeakTextBox, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->label13, 2, 1);
			this->tableLayoutPanel6->Controls->Add(this->label18, 0, 5);
			this->tableLayoutPanel6->Controls->Add(this->MinSeparationTextBox, 1, 5);
			this->tableLayoutPanel6->Controls->Add(this->label19, 2, 5);
			this->tableLayoutPanel6->Controls->Add(this->label16, 0, 4);
			this->tableLayoutPanel6->Controls->Add(this->MaxFWHMTextBox, 1, 4);
			this->tableLayoutPanel6->Controls->Add(this->label17, 2, 4);
			this->tableLayoutPanel6->Controls->Add(this->label14, 0, 3);
			this->tableLayoutPanel6->Controls->Add(this->MinFWHMTextBox, 1, 3);
			this->tableLayoutPanel6->Controls->Add(this->label15, 2, 3);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 6;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(181, 228);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(142, 86);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(36, 13);
			this->label22->TabIndex = 21;
			this->label22->Text = L"(ADU)";
			// 
			// MaxPeakTextBox
			// 
			this->MaxPeakTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MaxPeakTextBox->BackColor = System::Drawing::Color::White;
			this->MaxPeakTextBox->Location = System::Drawing::Point(93, 82);
			this->MaxPeakTextBox->Name = L"MaxPeakTextBox";
			this->MaxPeakTextBox->Size = System::Drawing::Size(41, 20);
			this->MaxPeakTextBox->TabIndex = 20;
			this->MaxPeakTextBox->Text = L"00000";
			this->MaxPeakTextBox->WordWrap = false;
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(29, 86);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(58, 13);
			this->label21->TabIndex = 19;
			this->label21->Text = L"Max Peak:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(21, 12);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(66, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Find Radius:";
			// 
			// FindRadiusTextBox
			// 
			this->FindRadiusTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FindRadiusTextBox->BackColor = System::Drawing::Color::White;
			this->FindRadiusTextBox->Location = System::Drawing::Point(93, 8);
			this->FindRadiusTextBox->Name = L"FindRadiusTextBox";
			this->FindRadiusTextBox->Size = System::Drawing::Size(41, 20);
			this->FindRadiusTextBox->TabIndex = 5;
			this->FindRadiusTextBox->Text = L"000.0";
			this->FindRadiusTextBox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(142, 12);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(26, 13);
			this->label11->TabIndex = 6;
			this->label11->Text = L"(pix)";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(32, 49);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(55, 13);
			this->label12->TabIndex = 7;
			this->label12->Text = L"Min Peak:";
			// 
			// MinPeakTextBox
			// 
			this->MinPeakTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MinPeakTextBox->BackColor = System::Drawing::Color::White;
			this->MinPeakTextBox->Location = System::Drawing::Point(93, 45);
			this->MinPeakTextBox->Name = L"MinPeakTextBox";
			this->MinPeakTextBox->Size = System::Drawing::Size(41, 20);
			this->MinPeakTextBox->TabIndex = 8;
			this->MinPeakTextBox->Text = L"00000";
			this->MinPeakTextBox->WordWrap = false;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(142, 49);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(36, 13);
			this->label13->TabIndex = 9;
			this->label13->Text = L"(ADU)";
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 200);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(81, 13);
			this->label18->TabIndex = 16;
			this->label18->Text = L"Min Separation:";
			// 
			// MinSeparationTextBox
			// 
			this->MinSeparationTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MinSeparationTextBox->BackColor = System::Drawing::Color::White;
			this->MinSeparationTextBox->Location = System::Drawing::Point(93, 196);
			this->MinSeparationTextBox->Name = L"MinSeparationTextBox";
			this->MinSeparationTextBox->Size = System::Drawing::Size(36, 20);
			this->MinSeparationTextBox->TabIndex = 17;
			this->MinSeparationTextBox->Text = L"000.0";
			this->MinSeparationTextBox->WordWrap = false;
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(142, 200);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(26, 13);
			this->label19->TabIndex = 18;
			this->label19->Text = L"(pix)";
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(20, 160);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(67, 13);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Max FWHM:";
			// 
			// MaxFWHMTextBox
			// 
			this->MaxFWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MaxFWHMTextBox->BackColor = System::Drawing::Color::White;
			this->MaxFWHMTextBox->Location = System::Drawing::Point(93, 156);
			this->MaxFWHMTextBox->Name = L"MaxFWHMTextBox";
			this->MaxFWHMTextBox->Size = System::Drawing::Size(41, 20);
			this->MaxFWHMTextBox->TabIndex = 14;
			this->MaxFWHMTextBox->Text = L"000.0";
			this->MaxFWHMTextBox->WordWrap = false;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(142, 160);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(26, 13);
			this->label17->TabIndex = 15;
			this->label17->Text = L"(pix)";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(23, 123);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(64, 13);
			this->label14->TabIndex = 10;
			this->label14->Text = L"Min FWHM:";
			// 
			// MinFWHMTextBox
			// 
			this->MinFWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MinFWHMTextBox->BackColor = System::Drawing::Color::White;
			this->MinFWHMTextBox->Location = System::Drawing::Point(93, 119);
			this->MinFWHMTextBox->Name = L"MinFWHMTextBox";
			this->MinFWHMTextBox->Size = System::Drawing::Size(41, 20);
			this->MinFWHMTextBox->TabIndex = 11;
			this->MinFWHMTextBox->Text = L"000.0";
			this->MinFWHMTextBox->WordWrap = false;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(142, 123);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(26, 13);
			this->label15->TabIndex = 12;
			this->label15->Text = L"(pix)";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel5);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(196, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(214, 103);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sky Parameters";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.84689F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.5311F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				31.10048F)));
			this->tableLayoutPanel5->Controls->Add(this->label9, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->SkyInnerRadiusTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->label6, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->label7, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->SkyOuterRadiusTextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->label8, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->SkySigmaCutTextBox, 1, 2);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(208, 84);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(17, 63);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(79, 13);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Sky Sigma Cut:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(5, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Sky Inner Radius:";
			// 
			// SkyInnerRadiusTextBox
			// 
			this->SkyInnerRadiusTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SkyInnerRadiusTextBox->BackColor = System::Drawing::Color::White;
			this->SkyInnerRadiusTextBox->Location = System::Drawing::Point(102, 4);
			this->SkyInnerRadiusTextBox->Name = L"SkyInnerRadiusTextBox";
			this->SkyInnerRadiusTextBox->Size = System::Drawing::Size(37, 20);
			this->SkyInnerRadiusTextBox->TabIndex = 5;
			this->SkyInnerRadiusTextBox->Text = L"000.0";
			this->SkyInnerRadiusTextBox->WordWrap = false;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(146, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"(pix)";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Sky Outer Radius:";
			// 
			// SkyOuterRadiusTextBox
			// 
			this->SkyOuterRadiusTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SkyOuterRadiusTextBox->BackColor = System::Drawing::Color::White;
			this->SkyOuterRadiusTextBox->Location = System::Drawing::Point(102, 32);
			this->SkyOuterRadiusTextBox->Name = L"SkyOuterRadiusTextBox";
			this->SkyOuterRadiusTextBox->Size = System::Drawing::Size(37, 20);
			this->SkyOuterRadiusTextBox->TabIndex = 8;
			this->SkyOuterRadiusTextBox->Text = L"000.0";
			this->SkyOuterRadiusTextBox->WordWrap = false;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(146, 35);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"(pix)";
			// 
			// SkySigmaCutTextBox
			// 
			this->SkySigmaCutTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SkySigmaCutTextBox->BackColor = System::Drawing::Color::White;
			this->SkySigmaCutTextBox->Location = System::Drawing::Point(102, 60);
			this->SkySigmaCutTextBox->Name = L"SkySigmaCutTextBox";
			this->SkySigmaCutTextBox->Size = System::Drawing::Size(37, 20);
			this->SkySigmaCutTextBox->TabIndex = 11;
			this->SkySigmaCutTextBox->Text = L"00.0";
			this->SkySigmaCutTextBox->WordWrap = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel4);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(187, 103);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Star Parameters";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				36.46409F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.96685F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				37.56906F)));
			this->tableLayoutPanel4->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->ZeroPointTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label4, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel8, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel9, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 66.66666F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(181, 84);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Aperature Radius:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Zero Point:";
			// 
			// ZeroPointTextBox
			// 
			this->ZeroPointTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ZeroPointTextBox->BackColor = System::Drawing::Color::White;
			this->ZeroPointTextBox->Location = System::Drawing::Point(69, 60);
			this->ZeroPointTextBox->Name = L"ZeroPointTextBox";
			this->ZeroPointTextBox->Size = System::Drawing::Size(37, 20);
			this->ZeroPointTextBox->TabIndex = 6;
			this->ZeroPointTextBox->Text = L"000.0";
			this->ZeroPointTextBox->WordWrap = false;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(115, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"(mag)";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 1;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->Controls->Add(this->FWHMRadioButton, 0, 1);
			this->tableLayoutPanel8->Controls->Add(this->PixelRadioButton, 0, 0);
			this->tableLayoutPanel8->Location = System::Drawing::Point(115, 3);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 2;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(63, 49);
			this->tableLayoutPanel8->TabIndex = 8;
			// 
			// FWHMRadioButton
			// 
			this->FWHMRadioButton->AutoSize = true;
			this->FWHMRadioButton->Location = System::Drawing::Point(3, 27);
			this->FWHMRadioButton->Name = L"FWHMRadioButton";
			this->FWHMRadioButton->Size = System::Drawing::Size(50, 17);
			this->FWHMRadioButton->TabIndex = 1;
			this->FWHMRadioButton->TabStop = true;
			this->FWHMRadioButton->Text = L"fwhm";
			this->FWHMRadioButton->UseVisualStyleBackColor = true;
			// 
			// PixelRadioButton
			// 
			this->PixelRadioButton->AutoSize = true;
			this->PixelRadioButton->Location = System::Drawing::Point(3, 3);
			this->PixelRadioButton->Name = L"PixelRadioButton";
			this->PixelRadioButton->Size = System::Drawing::Size(46, 17);
			this->PixelRadioButton->TabIndex = 0;
			this->PixelRadioButton->TabStop = true;
			this->PixelRadioButton->Text = L"pixel";
			this->PixelRadioButton->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 1;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel9->Controls->Add(this->ApRadiusFWHMTextBox, 0, 1);
			this->tableLayoutPanel9->Controls->Add(this->AperatureRadiusTextBox, 0, 0);
			this->tableLayoutPanel9->Location = System::Drawing::Point(69, 3);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 2;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(40, 49);
			this->tableLayoutPanel9->TabIndex = 9;
			// 
			// ApRadiusFWHMTextBox
			// 
			this->ApRadiusFWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ApRadiusFWHMTextBox->BackColor = System::Drawing::Color::White;
			this->ApRadiusFWHMTextBox->Location = System::Drawing::Point(3, 27);
			this->ApRadiusFWHMTextBox->Name = L"ApRadiusFWHMTextBox";
			this->ApRadiusFWHMTextBox->Size = System::Drawing::Size(34, 20);
			this->ApRadiusFWHMTextBox->TabIndex = 5;
			this->ApRadiusFWHMTextBox->Text = L"1.4";
			this->ApRadiusFWHMTextBox->WordWrap = false;
			// 
			// AperatureRadiusTextBox
			// 
			this->AperatureRadiusTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AperatureRadiusTextBox->BackColor = System::Drawing::Color::White;
			this->AperatureRadiusTextBox->Location = System::Drawing::Point(3, 3);
			this->AperatureRadiusTextBox->Name = L"AperatureRadiusTextBox";
			this->AperatureRadiusTextBox->Size = System::Drawing::Size(34, 20);
			this->AperatureRadiusTextBox->TabIndex = 4;
			this->AperatureRadiusTextBox->Text = L"10.0";
			this->AperatureRadiusTextBox->WordWrap = false;
			// 
			// PhotometrySettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 407);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"PhotometrySettingsDialog";
			this->Text = L"Photometry Settings Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 GetPhotometrySettingsDialogValues();
			 PhotometrySettingsDialog::FormPtr->Hide();
			 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 PhotometrySettingsDialog::FormPtr->Hide();
		 }
private: System::Void StartBatchButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char *cptr, buffer[MAX_SIZE_PATH_CHARS+80], dirName[MAX_SIZE_PATH_CHARS], fileName[MAX_SIZE_PATH_CHARS],
				 DarkDir[MAX_SIZE_PATH_CHARS], FlatDir[MAX_SIZE_PATH_CHARS];
			 int nFiles, success, reTry, answer, iFile, i, DarkOption, FlatOption, MaxiFile;
			 FILE *names_fptr=NULL;

			 GetPhotometrySettingsDialogValues();
			 strcpy_s(CurrentImageFileName, sizeof(CurrentImageFileName),
						ccd->Image.FileName);
			 sprintf_s(buffer, sizeof(buffer), "*** DEBUG - Batch file name: %s\n",
				 CurrentImageFileName);
			 Form1::CCDAutoForm->StatusPrint(buffer);
			 cptr = strrchr(CurrentImageFileName, '\\');
			 if (cptr == NULL) {
				 Form1::CCDAutoForm->StatusPrint("*** WARNING - Can't extract current directory...\n");
				 Form1::CCDAutoForm->StatusPrint("              Aborting batch image processing...\n");
				 return;
			 }
			 strncpy_s(dirName, sizeof(dirName), CurrentImageFileName, (cptr-CurrentImageFileName)+1);
			 dirName[(cptr-CurrentImageFileName)+1] = 0;
			 String^ dir = gcnew String(dirName);

			 sprintf_s(buffer, sizeof(buffer),
				 "*** INFO - Starting batch image processing in dir: %s\n", dirName);
			 Form1::CCDAutoForm->StatusPrint(buffer);

			 nFiles = 0;

			 /* Get a list of fits files in directory */

			 array<String^>^ files = Directory::GetFiles(dir,"*.fits");

			 reTry = false;
			 UserStopBatch = false;
			 iFile = -1;
			 MaxiFile = files->Length;
			 
			 do {
				 if (! reTry) {
					 iFile++;
					 if (iFile >= MaxiFile)
						 break;
					 for (i=0; i<files[iFile]->Length; i++)
						 fileName[i] = (char) files[iFile][i];
					 fileName[i] = 0;
					 sprintf_s(buffer, sizeof(buffer), "*** INFO - Processing fits file: %s\n",
						 fileName); 
					 Form1::CCDAutoForm->StatusPrint(buffer);
					 readLight(fileName, &ccd->Image);
					 
					 // Do required calibrations
					 
					 if (photometrySettings.CalibrateImages) {
						 DarkOption = OpenCalDialog::FormPtr->DarkOption;
						 FlatOption = OpenCalDialog::FormPtr->FlatOption;
						 OpenCalDialog::FormPtr->GetDarkDirTextBox(DarkDir);
						 OpenCalDialog::FormPtr->GetFlatDirTextBox(FlatDir);
						 DoCalibrations(DarkDir, DarkOption, FlatDir, FlatOption, ccd);
					 }

//					 removeHotPixels(&ccd->Image.light_frame);
					 loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
						 ccd->Image.light_frame.y, ccd->Image.light_frame.w,
						 ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
					 ccd->Image.saved = true;
					 if (PhotometrySettingsDialog::FormPtr->UseAstrometryCheckBox->Checked) {
						 memcpy_s(&ccd->Image.plateSolution, sizeof(ccd->Image.plateSolution), &plateSolution,
							 sizeof(plateSolution));
					 }
				 } else {
					 sprintf_s(buffer, sizeof(buffer),
						 "*** INFO - ReProcessing fits file: %s\n", fileName);
					 Form1::CCDAutoForm->StatusPrint(buffer);
					 reTry = false;
				 }
				 updateStatusInfo();
				 if (photometrySettings.Interactive) {
					 answer = MessageBox("Want to measure this image (Yes=yes, No=skip, Cancel=abort?", YESNO, true);
					 if (answer == CANCEL)
						 return;
					 else if (answer == NO) {
						 reTry = false;
						 continue;
					 }
				 }
				 success = updateListStars(&ccd->Image, CurrentStarList);
				 if (! success) {
					 sprintf_s(buffer, sizeof(buffer),
						 "*** WARNING - Aborting batch after file: %s\n", fileName);
					 Form1::CCDAutoForm->StatusPrint(buffer);
					 answer = MessageBox("Want to redefine star list (Yes=redefine, "
						 "No=skip this image, Cancel=Abort)?", YESNO, true);
					 if (answer == CANCEL)
						 return;
					 else if (answer == YES) {
						 loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
							 ccd->Image.light_frame.y, ccd->Image.light_frame.w,
							 ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
						 clearListStars();
						 ShowDefineListDialog();
						 while (! CurrentStarListDefined) {
							 Application::DoEvents();
							 usleep(100000);
						 }
						 reTry = true;
						 continue;
					 } else { /* NO */
						 reTry = false;
						 continue;
					 }
				 }
				 if (PhotometrySettingsDialog::FormPtr->UseAstrometryCheckBox->Checked)
					 UpdatePlateSolution(ccd);
				 success = measureListStars(&ccd->Image, CurrentStarList);
				 if (! success) {
					 sprintf_s(buffer, sizeof(buffer),
						 "*** WARNING - Problem with photometry at file: %s\n", fileName);
					 Form1::CCDAutoForm->StatusPrint(buffer);
					 answer = MessageBox("Want to redefine star list (Yes=redefine, "
						 "No=skip this image, Cancel=Abort)?", YESNO, true);
					 if (answer == CANCEL)
						 return;
					 else if (answer == YES) {
						 clearListStars();
						 ShowDefineListDialog();
						 while (! CurrentStarListDefined) {
							 usleep(100000);
						 }
						 reTry = true;
						 continue;
					 } else { /* NO */
						 reTry = false;
						 continue;
					 }
				 }
				 nFiles++;
				 DoMainEvents();
			 } while (! UserStopBatch);

			 if (UserStopBatch) {
				 sprintf_s(buffer, sizeof(buffer), 
					 "*** INFO - User stopped  batch image processing at file #%d.\n", nFiles);
			 } else {
				 sprintf_s(buffer, sizeof(buffer),
			 		 "*** INFO - Finished batch image processing of %d files.\n", nFiles);
			 }
			 Form1::CCDAutoForm->StatusPrint(buffer);

			 return;
		 }
private: System::Void StopBatchButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 UserStopBatch = true;
		 }
public:  static void ShowTheDialog() {
			 PhotometrySettingsDialog::FormPtr->Show();
		 }
public:  static void SetAperatureRadiusTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->AperatureRadiusTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetAperatureRadiusTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->AperatureRadiusTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetApRadiusFWHMTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->ApRadiusFWHMTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetApRadiusFWHMTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->ApRadiusFWHMTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetZeroPointTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->ZeroPointTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetZeroPointTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->ZeroPointTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetFindRadiusTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->FindRadiusTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetFindRadiusTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->FindRadiusTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetMinPeakTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->MinPeakTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetMinPeakTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->MinPeakTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetMaxPeakTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->MaxPeakTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetMaxPeakTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->MaxPeakTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetMinFWHMTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->MinFWHMTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetMinFWHMTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->MinFWHMTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetMaxFWHMTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->MaxFWHMTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetMaxFWHMTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->MaxFWHMTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetMinSeparationTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->MinSeparationTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetMinSeparationTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->MinSeparationTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetSkyInnerRadiusTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->SkyInnerRadiusTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetSkyInnerRadiusTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->SkyInnerRadiusTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetSkyOuterRadiusTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->SkyOuterRadiusTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetSkyOuterRadiusTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->SkyOuterRadiusTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetSkySigmaCutTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->SkySigmaCutTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetSkySigmaCutTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->SkySigmaCutTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetLogFileBaseNameTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->LogFileBaseNameTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetLogFileBaseNameTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->LogFileBaseNameTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetLogDirTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 PhotometrySettingsDialog::FormPtr->LogDirTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetLogDirTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = PhotometrySettingsDialog::FormPtr->LogDirTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetCCDAutoCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->CCDAutoCheckBox->Checked = state;
		 }
public:  static void SetAAVSOCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->AAVSOCheckBox->Checked = state;
		 }
public:  static void SetPlotResultsCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->PlotResultsCheckBox->Checked = state;
		 }
public:  static void SetAutoFindCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->AutoFindCheckBox->Checked = state;
		 }
public:  static void SetOffsetSkyCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->OffsetSkyCheckBox->Checked = state;
		 }
public:  static void GetCCDAutoCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->CCDAutoCheckBox->Checked;
		 }
public:  static void GetAAVSOCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->AAVSOCheckBox->Checked;
		 }
public:  static void GetPlotResultsCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->PlotResultsCheckBox->Checked;
		 }
public:  static void GetAutoFindCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->AutoFindCheckBox->Checked;
		 }
public:  static void GetOffsetSkyCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->OffsetSkyCheckBox->Checked;
		 }
public:  static void GetCalibrateCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->CalibrateCheckBox->Checked;
		 }
public:  static void SetCalibrateCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->CalibrateCheckBox->Checked = state;
		 }
public:  static void GetInteractiveCheckBox(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->InteractiveCheckBox->Checked;
		 }
public:  static void SetInteractiveCheckBox(bool state) {
			 PhotometrySettingsDialog::FormPtr->InteractiveCheckBox->Checked = state;
		 }
public:  static void SetPixelRadioButton(bool state) {
			 PhotometrySettingsDialog::FormPtr->PixelRadioButton->Checked = state;
		 }
public:  static void GetPixelRadioButton(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->PixelRadioButton->Checked;
		 }
public:  static void SetFWHMRadioButton(bool state) {
			 PhotometrySettingsDialog::FormPtr->FWHMRadioButton->Checked = state;
		 }
public:  static void GetFWHMRadioButton(bool *state) {
			 *state = PhotometrySettingsDialog::FormPtr->FWHMRadioButton->Checked;
		 }
private: System::Void SelectLogFolderButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char path[MAX_SIZE_PATH_CHARS], *cptr;
			 
			 cptr = strrchr(ccd->Image.FileName, '\\');
			 strncpy_s(path, sizeof(path), ccd->Image.FileName, (cptr - ccd->Image.FileName) + 1);
			 GetAFolder("Select Photometry Log Folder", path);
			 strcpy_s(photometrySettings.logDir, sizeof(photometrySettings.logDir), path);
			 this->FormPtr->SetLogDirTextBox(photometrySettings.logDir);
			 return;
		 }
};
}
