#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//#include "Form1.h"
#include "doRoutines.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for FlatFrameSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FlatFrameSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static FlatFrameSettingsDialog^ FormPtr;
		FlatFrameSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			FlatFrameSettingsDialogExists = TRUE;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FlatFrameSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			FlatFrameSettingsDialogExists = FALSE;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  TrackingCCDButton;
	private: System::Windows::Forms::RadioButton^  ImagingCCDButton;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::RadioButton^  Binning3x3Button;
	private: System::Windows::Forms::RadioButton^  Binning1x1Button;
	private: System::Windows::Forms::RadioButton^  Binning2x2Button;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::RadioButton^  MeanButton;
	private: System::Windows::Forms::RadioButton^  MedianButton;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::ComboBox^  DarkFrameOptionComboBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;

	private: System::Windows::Forms::TextBox^  DarkDirTextBox;
	private: System::Windows::Forms::CheckBox^  SaveDarkCheckBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  CancelButton;

	private: System::Windows::Forms::Button^  ExecuteButton;
	private: System::Windows::Forms::Button^  OkButton;







	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel15;

	private: System::Windows::Forms::TextBox^  RExpTimeTextBox;
	private: System::Windows::Forms::TextBox^  VExpTimeTextBox;
	private: System::Windows::Forms::TextBox^  BExpTimeTextBox;
	private: System::Windows::Forms::TextBox^  HExpTimeTextBox;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::CheckBox^  HCheckBox;

	private: System::Windows::Forms::CheckBox^  BCheckBox;
	private: System::Windows::Forms::CheckBox^  VCheckBox;
	private: System::Windows::Forms::CheckBox^  RCheckBox;
	private: System::Windows::Forms::CheckBox^  ICheckBox;




	private: System::Windows::Forms::TextBox^  IExpTimeTextBox;
	private: System::Windows::Forms::CheckBox^  SaveEachFlatCheckBox;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  FrameTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  NumFramesTextBox;
	private: System::Windows::Forms::TextBox^  FlatDirTextBox;


	private: System::Windows::Forms::Button^  PickDarkFolderButton;
	private: System::Windows::Forms::Button^  PickFlatFolderButton;
	private: System::Windows::Forms::CheckBox^  CCheckBox;
	private: System::Windows::Forms::TextBox^  CExpTimeTextBox;










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
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->MeanButton = (gcnew System::Windows::Forms::RadioButton());
			this->MedianButton = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Binning3x3Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning1x1Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning2x2Button = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->TrackingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->ImagingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel15 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->SaveEachFlatCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->RExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ICheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->IExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickFlatFolderButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->FrameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->NumFramesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FlatDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DarkFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickDarkFolderButton = (gcnew System::Windows::Forms::Button());
			this->DarkDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveDarkCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->tableLayoutPanel15->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.28409F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 64.77273F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.659091F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(460, 371);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->Controls->Add(this->ExecuteButton, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->CancelButton, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 337);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(454, 31);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// ExecuteButton
			// 
			this->ExecuteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ExecuteButton->Location = System::Drawing::Point(189, 4);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(75, 23);
			this->ExecuteButton->TabIndex = 1;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			this->ExecuteButton->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::ExecuteButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(38, 4);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(340, 4);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::CancelButton_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				29.07489F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				37.6652F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(454, 88);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel8);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(285, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(166, 82);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Combine Method";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 1;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel8->Controls->Add(this->MeanButton, 0, 1);
			this->tableLayoutPanel8->Controls->Add(this->MedianButton, 0, 0);
			this->tableLayoutPanel8->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 2;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(109, 51);
			this->tableLayoutPanel8->TabIndex = 0;
			// 
			// MeanButton
			// 
			this->MeanButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MeanButton->AutoSize = true;
			this->MeanButton->Location = System::Drawing::Point(3, 29);
			this->MeanButton->Name = L"MeanButton";
			this->MeanButton->Size = System::Drawing::Size(52, 17);
			this->MeanButton->TabIndex = 1;
			this->MeanButton->TabStop = true;
			this->MeanButton->Text = L"Mean";
			this->MeanButton->UseVisualStyleBackColor = true;
			this->MeanButton->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::MeanButton_CheckedChanged);
			// 
			// MedianButton
			// 
			this->MedianButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MedianButton->AutoSize = true;
			this->MedianButton->Location = System::Drawing::Point(3, 4);
			this->MedianButton->Name = L"MedianButton";
			this->MedianButton->Size = System::Drawing::Size(60, 17);
			this->MedianButton->TabIndex = 0;
			this->MedianButton->TabStop = true;
			this->MedianButton->Text = L"Median";
			this->MedianButton->UseVisualStyleBackColor = true;
			this->MedianButton->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::MedianButton_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel7);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(154, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(125, 82);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"CCD Binning\?";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 1;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel7->Controls->Add(this->Binning3x3Button, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->Binning1x1Button, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->Binning2x2Button, 0, 1);
			this->tableLayoutPanel7->Location = System::Drawing::Point(0, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(118, 65);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// Binning3x3Button
			// 
			this->Binning3x3Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning3x3Button->AutoSize = true;
			this->Binning3x3Button->Location = System::Drawing::Point(3, 45);
			this->Binning3x3Button->Name = L"Binning3x3Button";
			this->Binning3x3Button->Size = System::Drawing::Size(42, 17);
			this->Binning3x3Button->TabIndex = 3;
			this->Binning3x3Button->TabStop = true;
			this->Binning3x3Button->Text = L"3x3";
			this->Binning3x3Button->UseVisualStyleBackColor = true;
			this->Binning3x3Button->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::BinningButton_Click);
			this->Binning3x3Button->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::Binning3x3Button_CheckedChanged);
			// 
			// Binning1x1Button
			// 
			this->Binning1x1Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning1x1Button->AutoSize = true;
			this->Binning1x1Button->Location = System::Drawing::Point(3, 3);
			this->Binning1x1Button->Name = L"Binning1x1Button";
			this->Binning1x1Button->Size = System::Drawing::Size(42, 15);
			this->Binning1x1Button->TabIndex = 1;
			this->Binning1x1Button->TabStop = true;
			this->Binning1x1Button->Text = L"1x1";
			this->Binning1x1Button->UseVisualStyleBackColor = true;
			this->Binning1x1Button->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::BinningButton_Click);
			this->Binning1x1Button->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::Binning1x1Button_CheckedChanged);
			// 
			// Binning2x2Button
			// 
			this->Binning2x2Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning2x2Button->AutoSize = true;
			this->Binning2x2Button->Location = System::Drawing::Point(3, 24);
			this->Binning2x2Button->Name = L"Binning2x2Button";
			this->Binning2x2Button->Size = System::Drawing::Size(42, 15);
			this->Binning2x2Button->TabIndex = 2;
			this->Binning2x2Button->TabStop = true;
			this->Binning2x2Button->Text = L"2x2";
			this->Binning2x2Button->UseVisualStyleBackColor = true;
			this->Binning2x2Button->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::BinningButton_Click);
			this->Binning2x2Button->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::Binning2x2Button_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel6);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(145, 82);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Which CCD\?";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel6->Controls->Add(this->TrackingCCDButton, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->ImagingCCDButton, 0, 0);
			this->tableLayoutPanel6->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(109, 51);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// TrackingCCDButton
			// 
			this->TrackingCCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TrackingCCDButton->AutoSize = true;
			this->TrackingCCDButton->Location = System::Drawing::Point(3, 29);
			this->TrackingCCDButton->Name = L"TrackingCCDButton";
			this->TrackingCCDButton->Size = System::Drawing::Size(92, 17);
			this->TrackingCCDButton->TabIndex = 1;
			this->TrackingCCDButton->TabStop = true;
			this->TrackingCCDButton->Text = L"Tracking CCD";
			this->TrackingCCDButton->UseVisualStyleBackColor = true;
			this->TrackingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::TrackingCCDButton_CheckedChanged);
			// 
			// ImagingCCDButton
			// 
			this->ImagingCCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ImagingCCDButton->AutoSize = true;
			this->ImagingCCDButton->Location = System::Drawing::Point(3, 4);
			this->ImagingCCDButton->Name = L"ImagingCCDButton";
			this->ImagingCCDButton->Size = System::Drawing::Size(87, 17);
			this->ImagingCCDButton->TabIndex = 0;
			this->ImagingCCDButton->TabStop = true;
			this->ImagingCCDButton->Text = L"Imaging CCD";
			this->ImagingCCDButton->UseVisualStyleBackColor = true;
			this->ImagingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::ImagingCCDButton_CheckedChanged);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				61.45374F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				38.54626F)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox7, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel5, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 97);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(454, 234);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->tableLayoutPanel15);
			this->groupBox7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox7->Location = System::Drawing::Point(281, 3);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(170, 228);
			this->groupBox7->TabIndex = 2;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Filter Sequence Settings";
			// 
			// tableLayoutPanel15
			// 
			this->tableLayoutPanel15->ColumnCount = 2;
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				40.23669F)));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				59.76331F)));
			this->tableLayoutPanel15->Controls->Add(this->CCheckBox, 0, 6);
			this->tableLayoutPanel15->Controls->Add(this->CExpTimeTextBox, 1, 6);
			this->tableLayoutPanel15->Controls->Add(this->label14, 0, 0);
			this->tableLayoutPanel15->Controls->Add(this->label15, 1, 0);
			this->tableLayoutPanel15->Controls->Add(this->SaveEachFlatCheckBox, 0, 7);
			this->tableLayoutPanel15->Controls->Add(this->HExpTimeTextBox, 1, 5);
			this->tableLayoutPanel15->Controls->Add(this->BCheckBox, 0, 1);
			this->tableLayoutPanel15->Controls->Add(this->BExpTimeTextBox, 1, 1);
			this->tableLayoutPanel15->Controls->Add(this->VCheckBox, 0, 2);
			this->tableLayoutPanel15->Controls->Add(this->HCheckBox);
			this->tableLayoutPanel15->Controls->Add(this->VExpTimeTextBox, 1, 2);
			this->tableLayoutPanel15->Controls->Add(this->RCheckBox, 0, 3);
			this->tableLayoutPanel15->Controls->Add(this->RExpTimeTextBox, 1, 3);
			this->tableLayoutPanel15->Controls->Add(this->ICheckBox, 0, 4);
			this->tableLayoutPanel15->Controls->Add(this->IExpTimeTextBox, 1, 4);
			this->tableLayoutPanel15->Location = System::Drawing::Point(6, 16);
			this->tableLayoutPanel15->Name = L"tableLayoutPanel15";
			this->tableLayoutPanel15->RowCount = 8;
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.50187F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.50187F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel15->Size = System::Drawing::Size(157, 202);
			this->tableLayoutPanel15->TabIndex = 0;
			// 
			// CCheckBox
			// 
			this->CCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CCheckBox->AutoSize = true;
			this->CCheckBox->Location = System::Drawing::Point(15, 154);
			this->CCheckBox->Name = L"CCheckBox";
			this->CCheckBox->Size = System::Drawing::Size(33, 17);
			this->CCheckBox->TabIndex = 27;
			this->CCheckBox->Text = L"C";
			this->CCheckBox->UseVisualStyleBackColor = true;
			// 
			// CExpTimeTextBox
			// 
			this->CExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CExpTimeTextBox->Location = System::Drawing::Point(82, 153);
			this->CExpTimeTextBox->Name = L"CExpTimeTextBox";
			this->CExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->CExpTimeTextBox->TabIndex = 28;
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(3, 6);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(57, 13);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Use Filter\?";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(69, 6);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(82, 13);
			this->label15->TabIndex = 7;
			this->label15->Text = L"Exposure (secs)";
			// 
			// SaveEachFlatCheckBox
			// 
			this->SaveEachFlatCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveEachFlatCheckBox->AutoSize = true;
			this->tableLayoutPanel15->SetColumnSpan(this->SaveEachFlatCheckBox, 2);
			this->SaveEachFlatCheckBox->Location = System::Drawing::Point(13, 180);
			this->SaveEachFlatCheckBox->Name = L"SaveEachFlatCheckBox";
			this->SaveEachFlatCheckBox->Size = System::Drawing::Size(131, 17);
			this->SaveEachFlatCheckBox->TabIndex = 26;
			this->SaveEachFlatCheckBox->Text = L"Save Each Flat Frame";
			this->SaveEachFlatCheckBox->UseVisualStyleBackColor = true;
			this->SaveEachFlatCheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::SaveEachFlatCheckBox_CheckedChanged);
			// 
			// HExpTimeTextBox
			// 
			this->HExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HExpTimeTextBox->Location = System::Drawing::Point(82, 128);
			this->HExpTimeTextBox->Name = L"HExpTimeTextBox";
			this->HExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->HExpTimeTextBox->TabIndex = 19;
			// 
			// BCheckBox
			// 
			this->BCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BCheckBox->AutoSize = true;
			this->BCheckBox->Location = System::Drawing::Point(15, 29);
			this->BCheckBox->Name = L"BCheckBox";
			this->BCheckBox->Size = System::Drawing::Size(33, 17);
			this->BCheckBox->TabIndex = 9;
			this->BCheckBox->Text = L"B";
			this->BCheckBox->UseVisualStyleBackColor = true;
			this->BCheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::BCheckBox_CheckedChanged);
			// 
			// BExpTimeTextBox
			// 
			this->BExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BExpTimeTextBox->Location = System::Drawing::Point(82, 28);
			this->BExpTimeTextBox->Name = L"BExpTimeTextBox";
			this->BExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->BExpTimeTextBox->TabIndex = 20;
			// 
			// VCheckBox
			// 
			this->VCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VCheckBox->AutoSize = true;
			this->VCheckBox->Location = System::Drawing::Point(15, 54);
			this->VCheckBox->Name = L"VCheckBox";
			this->VCheckBox->Size = System::Drawing::Size(33, 17);
			this->VCheckBox->TabIndex = 10;
			this->VCheckBox->Text = L"V";
			this->VCheckBox->UseVisualStyleBackColor = true;
			this->VCheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::VCheckBox_CheckedChanged);
			// 
			// HCheckBox
			// 
			this->HCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HCheckBox->AutoSize = true;
			this->HCheckBox->Location = System::Drawing::Point(14, 129);
			this->HCheckBox->Name = L"HCheckBox";
			this->HCheckBox->Size = System::Drawing::Size(34, 17);
			this->HCheckBox->TabIndex = 8;
			this->HCheckBox->Text = L"H";
			this->HCheckBox->UseVisualStyleBackColor = true;
			this->HCheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::HCheckBox_CheckedChanged);
			// 
			// VExpTimeTextBox
			// 
			this->VExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VExpTimeTextBox->Location = System::Drawing::Point(82, 53);
			this->VExpTimeTextBox->Name = L"VExpTimeTextBox";
			this->VExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->VExpTimeTextBox->TabIndex = 21;
			// 
			// RCheckBox
			// 
			this->RCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RCheckBox->AutoSize = true;
			this->RCheckBox->Location = System::Drawing::Point(14, 79);
			this->RCheckBox->Name = L"RCheckBox";
			this->RCheckBox->Size = System::Drawing::Size(34, 17);
			this->RCheckBox->TabIndex = 11;
			this->RCheckBox->Text = L"R";
			this->RCheckBox->UseVisualStyleBackColor = true;
			this->RCheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::RCheckBox_CheckedChanged);
			// 
			// RExpTimeTextBox
			// 
			this->RExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RExpTimeTextBox->Location = System::Drawing::Point(82, 78);
			this->RExpTimeTextBox->Name = L"RExpTimeTextBox";
			this->RExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->RExpTimeTextBox->TabIndex = 22;
			// 
			// ICheckBox
			// 
			this->ICheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ICheckBox->AutoSize = true;
			this->ICheckBox->Location = System::Drawing::Point(17, 104);
			this->ICheckBox->Name = L"ICheckBox";
			this->ICheckBox->Size = System::Drawing::Size(29, 17);
			this->ICheckBox->TabIndex = 12;
			this->ICheckBox->Text = L"I";
			this->ICheckBox->UseVisualStyleBackColor = true;
			this->ICheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::ICheckBox_CheckedChanged);
			// 
			// IExpTimeTextBox
			// 
			this->IExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->IExpTimeTextBox->Location = System::Drawing::Point(82, 103);
			this->IExpTimeTextBox->Name = L"IExpTimeTextBox";
			this->IExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->IExpTimeTextBox->TabIndex = 25;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel5->Controls->Add(this->groupBox6, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->groupBox4, 0, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 53.08057F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.91943F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(272, 228);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tableLayoutPanel13);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox6->Location = System::Drawing::Point(3, 124);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(266, 101);
			this->groupBox6->TabIndex = 5;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Frame Parameters";
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->ColumnCount = 3;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				38.07692F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				45.76923F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				15.76923F)));
			this->tableLayoutPanel13->Controls->Add(this->PickFlatFolderButton, 0, 2);
			this->tableLayoutPanel13->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel13->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel13->Controls->Add(this->FrameTextBox, 1, 0);
			this->tableLayoutPanel13->Controls->Add(this->label6, 0, 1);
			this->tableLayoutPanel13->Controls->Add(this->NumFramesTextBox, 1, 1);
			this->tableLayoutPanel13->Controls->Add(this->FlatDirTextBox, 1, 2);
			this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel13->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 3;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel13->Size = System::Drawing::Size(260, 82);
			this->tableLayoutPanel13->TabIndex = 0;
			// 
			// PickFlatFolderButton
			// 
			this->PickFlatFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PickFlatFolderButton->Location = System::Drawing::Point(3, 57);
			this->PickFlatFolderButton->Name = L"PickFlatFolderButton";
			this->PickFlatFolderButton->Size = System::Drawing::Size(93, 21);
			this->PickFlatFolderButton->TabIndex = 10;
			this->PickFlatFolderButton->Text = L"Pick Flat Folder";
			this->PickFlatFolderButton->UseVisualStyleBackColor = true;
			this->PickFlatFolderButton->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::PickFlatFolderButton_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(44, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"x, y, h, w:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(221, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"pixels";
			// 
			// FrameTextBox
			// 
			this->FrameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FrameTextBox->Location = System::Drawing::Point(102, 3);
			this->FrameTextBox->Name = L"FrameTextBox";
			this->FrameTextBox->Size = System::Drawing::Size(113, 20);
			this->FrameTextBox->TabIndex = 6;
			this->FrameTextBox->Text = L"0,0,1024,1024";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(42, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"# Frames:";
			// 
			// NumFramesTextBox
			// 
			this->NumFramesTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NumFramesTextBox->Location = System::Drawing::Point(102, 30);
			this->NumFramesTextBox->Name = L"NumFramesTextBox";
			this->NumFramesTextBox->Size = System::Drawing::Size(113, 20);
			this->NumFramesTextBox->TabIndex = 8;
			// 
			// FlatDirTextBox
			// 
			this->FlatDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FlatDirTextBox->Location = System::Drawing::Point(102, 58);
			this->FlatDirTextBox->Name = L"FlatDirTextBox";
			this->FlatDirTextBox->Size = System::Drawing::Size(113, 20);
			this->FlatDirTextBox->TabIndex = 9;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel9);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(266, 115);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Dark Frame Options";
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 1;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel9->Controls->Add(this->DarkFrameOptionComboBox, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->tableLayoutPanel10, 0, 1);
			this->tableLayoutPanel9->Controls->Add(this->SaveDarkCheckBox, 0, 2);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 3;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.88506F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.17647F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.41176F)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(260, 96);
			this->tableLayoutPanel9->TabIndex = 0;
			// 
			// DarkFrameOptionComboBox
			// 
			this->DarkFrameOptionComboBox->FormattingEnabled = true;
			this->DarkFrameOptionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Automatic dark frame", L"Force new dark frame", 
				L"Use dark frame from file", L"Don\'t use dark frame"});
			this->DarkFrameOptionComboBox->Location = System::Drawing::Point(3, 3);
			this->DarkFrameOptionComboBox->Name = L"DarkFrameOptionComboBox";
			this->DarkFrameOptionComboBox->Size = System::Drawing::Size(173, 21);
			this->DarkFrameOptionComboBox->TabIndex = 0;
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 2;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				43.65482F)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				56.34518F)));
			this->tableLayoutPanel10->Controls->Add(this->PickDarkFolderButton, 0, 0);
			this->tableLayoutPanel10->Controls->Add(this->DarkDirTextBox, 1, 0);
			this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel10->Location = System::Drawing::Point(3, 31);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 1;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				33)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(254, 33);
			this->tableLayoutPanel10->TabIndex = 1;
			// 
			// PickDarkFolderButton
			// 
			this->PickDarkFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PickDarkFolderButton->Location = System::Drawing::Point(3, 6);
			this->PickDarkFolderButton->Name = L"PickDarkFolderButton";
			this->PickDarkFolderButton->Size = System::Drawing::Size(103, 21);
			this->PickDarkFolderButton->TabIndex = 2;
			this->PickDarkFolderButton->Text = L"Pick Dark Folder";
			this->PickDarkFolderButton->UseVisualStyleBackColor = true;
			this->PickDarkFolderButton->Click += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::PickDarkFolderButton_Click);
			// 
			// DarkDirTextBox
			// 
			this->DarkDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DarkDirTextBox->Location = System::Drawing::Point(113, 6);
			this->DarkDirTextBox->Name = L"DarkDirTextBox";
			this->DarkDirTextBox->Size = System::Drawing::Size(95, 20);
			this->DarkDirTextBox->TabIndex = 1;
			this->DarkDirTextBox->Text = L"Darks";
			// 
			// SaveDarkCheckBox
			// 
			this->SaveDarkCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveDarkCheckBox->AutoSize = true;
			this->SaveDarkCheckBox->Location = System::Drawing::Point(64, 73);
			this->SaveDarkCheckBox->Name = L"SaveDarkCheckBox";
			this->SaveDarkCheckBox->Size = System::Drawing::Size(132, 17);
			this->SaveDarkCheckBox->TabIndex = 2;
			this->SaveDarkCheckBox->Text = L"Save Dark Frame Also";
			this->SaveDarkCheckBox->UseVisualStyleBackColor = true;
			this->SaveDarkCheckBox->CheckedChanged += gcnew System::EventHandler(this, &FlatFrameSettingsDialog::SaveDarkCheckBox_CheckedChanged);
			// 
			// FlatFrameSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(460, 371);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"FlatFrameSettingsDialog";
			this->Text = L"FlatFrameSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->tableLayoutPanel15->ResumeLayout(false);
			this->tableLayoutPanel15->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

public:  void ShowTheDialog(void) {
			 FlatFrameSettingsDialog::FormPtr->ShowDialog();
		 }

private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 FlatFrameSettingsDialog::FormPtr->Hide();
			 GetFlatFrameSettings();
			 return;
}
private: System::Void ExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 FlatFrameSettingsDialog::FormPtr->Hide();
			 GetFlatFrameSettings();
			 DoFlatFrameSeries();
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Restore old settings */
			 
			 memcpy(&flatFrameSettings, &flatFrameSettings_Save, sizeof(flatFrameSettings));
			 FlatFrameSettingsDialog::Hide();
			 return;
		 }
private: System::Void ImagingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void TrackingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Binning1x1Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Binning2x2Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Binning3x3Button_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void BinningButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[40];
			 if (FlatFrameSettingsDialog::FormPtr->Binning1x1Button->Checked) {
				 flatFrameSettings.binning = 0;
			 } else if (FlatFrameSettingsDialog::FormPtr->Binning2x2Button->Checked) {
				 flatFrameSettings.binning = 1;
			 } else if (FlatFrameSettingsDialog::FormPtr->Binning3x3Button->Checked) {
				 flatFrameSettings.binning = 2;
			 }
			 GetCCDFrameSettings(ccd, &flatFrameSettings.x, &flatFrameSettings.y,
					 &flatFrameSettings.w, &flatFrameSettings.h, &flatFrameSettings.binning);
			 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", flatFrameSettings.x,
					 flatFrameSettings.y, flatFrameSettings.h, flatFrameSettings.w);
			 FlatFrameSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 }
private: System::Void MedianButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void MeanButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void SaveDarkCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void BCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void VCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void RCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ICheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void HCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void SaveEachFlatCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
public: static void SetDarkFrameOptionComboBox(int index) {
		FlatFrameSettingsDialog::FormPtr->DarkFrameOptionComboBox->SelectedIndex = index-1;
		}
public: static int GetDarkFrameOptionComboBox(void) {
		int index;
		index = FlatFrameSettingsDialog::FormPtr->DarkFrameOptionComboBox->SelectedIndex;
		return index;
		}
public: static void SetFrameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->FrameTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFrameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->FrameTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFlatDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->FlatDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFlatDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->FlatDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDarkDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->DarkDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDarkDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->DarkDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetNumFramesTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->NumFramesTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetNumFramesTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->NumFramesTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetHExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->HExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetHExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->HExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetBExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->BExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetBExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->BExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetVExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->VExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetVExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->VExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetRExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->RExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetRExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->RExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetIExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->IExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetIExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->IExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FlatFrameSettingsDialog::FormPtr->CExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FlatFrameSettingsDialog::FormPtr->CExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static int GetFilterCheckBoxState(char filter) {
		int state;
		switch (filter) {
		  case 'B':
			state = (FlatFrameSettingsDialog::FormPtr->BCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'V':
			state = (FlatFrameSettingsDialog::FormPtr->VCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'R':
			state = (FlatFrameSettingsDialog::FormPtr->RCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'I':
			state = (FlatFrameSettingsDialog::FormPtr->ICheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'H':
			state = (FlatFrameSettingsDialog::FormPtr->HCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'C':
			state = (FlatFrameSettingsDialog::FormPtr->CCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  default:
		    state = FALSE;
			break;
		}
		return state;
		}
public: static void GetFilterExpTimeTextBox(char filter, char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		switch (filter) {
		  case 'B':
		    buffer = FlatFrameSettingsDialog::FormPtr->BExpTimeTextBox->Text;
			break;
		  case 'V':
		    buffer = FlatFrameSettingsDialog::FormPtr->VExpTimeTextBox->Text;
			break;
		  case 'R':
		    buffer = FlatFrameSettingsDialog::FormPtr->RExpTimeTextBox->Text;
			break;
		  case 'I':
		    buffer = FlatFrameSettingsDialog::FormPtr->IExpTimeTextBox->Text;
			break;
		  case 'H':
		    buffer = FlatFrameSettingsDialog::FormPtr->HExpTimeTextBox->Text;
			break;
		  case 'C':
		    buffer = FlatFrameSettingsDialog::FormPtr->CExpTimeTextBox->Text;
			break;
		  default:
			break;
		}
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public:  void HideCCDTrackingButton(void) {
			 FlatFrameSettingsDialog::FormPtr->TrackingCCDButton->Hide();
		 }
public:  void ShowCCDTrackingButton(void) {
			 FlatFrameSettingsDialog::FormPtr->TrackingCCDButton->Show();
		 }

public: static void Hide3x3Button(void) {
			FlatFrameSettingsDialog::FormPtr->Binning3x3Button->Hide();
		}
public: static void Show3x3Button(void) {
			FlatFrameSettingsDialog::FormPtr->Binning3x3Button->Show();
		}

public: static void SetWhichCCDButton(int which) {
			if (which == 0) {
				FlatFrameSettingsDialog::FormPtr->ImagingCCDButton->Checked = true;
				FlatFrameSettingsDialog::FormPtr->TrackingCCDButton->Checked = false;
			} else {
				FlatFrameSettingsDialog::FormPtr->ImagingCCDButton->Checked = false;
				FlatFrameSettingsDialog::FormPtr->TrackingCCDButton->Checked = true;
			}
		}
public: static int GetWhichCCDButton(void) {
			if (FlatFrameSettingsDialog::FormPtr->ImagingCCDButton->Checked) {
				return 0;
			} else {
				return 1;
			}
		}
public: static void SetWhichBinningButton(int binning) {
			if (binning == 0) {
				FlatFrameSettingsDialog::FormPtr->Binning1x1Button->Checked = true;
				FlatFrameSettingsDialog::FormPtr->Binning2x2Button->Checked = false;
				FlatFrameSettingsDialog::FormPtr->Binning3x3Button->Checked = false;
			} else if (binning == 1) {
				FlatFrameSettingsDialog::FormPtr->Binning1x1Button->Checked = false;
				FlatFrameSettingsDialog::FormPtr->Binning2x2Button->Checked = true;
				FlatFrameSettingsDialog::FormPtr->Binning3x3Button->Checked = false;
			} else {
				FlatFrameSettingsDialog::FormPtr->Binning1x1Button->Checked = false;
				FlatFrameSettingsDialog::FormPtr->Binning2x2Button->Checked = false;
				FlatFrameSettingsDialog::FormPtr->Binning3x3Button->Checked = true;
			}
		}
public: static int GetWhichBinningButton(void) {

			if (FlatFrameSettingsDialog::FormPtr->Binning1x1Button->Checked) {
				return 0;
			} else if (FlatFrameSettingsDialog::FormPtr->Binning2x2Button->Checked) {
				return 1;
			} else {
				return 2;
			}
		}
private: System::Void PickDarkFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Select Dark Frame Folder", path);
			 strcpy_s(flatFrameSettings.imageDir, sizeof(flatFrameSettings.imageDir), path);
			 this->FormPtr->SetDarkDirTextBox(flatFrameSettings.imageDir);
			 return;
		 }
private: System::Void PickFlatFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Select Flat Frame Folder", path);
			 strcpy_s(flatFrameSettings.imageDir, sizeof(flatFrameSettings.imageDir), path);
			 this->FormPtr->SetFlatDirTextBox(flatFrameSettings.imageDir);
			 return;
		 }
public:  int SetFlatFrameSettings(void) {

			 char buffer[80];

			 /* # of frames */

			 sprintf_s(buffer, sizeof(buffer), "%d", flatFrameSettings.numFrames);
			 FlatFrameSettingsDialog::FormPtr->SetNumFramesTextBox(buffer);

			 /* Which ccd */

		     if (ccd->make != SBIG_MAKE) {
				 FlatFrameSettingsDialog::HideCCDTrackingButton();
				 FlatFrameSettingsDialog::SetWhichCCDButton(0);
			 } else {
				 FlatFrameSettingsDialog::ShowCCDTrackingButton();
				 FlatFrameSettingsDialog::SetWhichCCDButton(flatFrameSettings.whichCCD);
			 }
			 
				/* Binning */

				 FlatFrameSettingsDialog::FormPtr->SetWhichBinningButton(flatFrameSettings.binning);

				/* ccd Frame size */

			 if (flatFrameSettings.w <= 0) {
				 GetCCDFrameSettings(ccd, &flatFrameSettings.x, &flatFrameSettings.y,
					 &flatFrameSettings.w, &flatFrameSettings.h, &flatFrameSettings.binning);
			 }
			 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", flatFrameSettings.x,
				 flatFrameSettings.y, flatFrameSettings.h, flatFrameSettings.w);
			 FlatFrameSettingsDialog::FormPtr->SetFrameTextBox(buffer);

			 /* Dark frame option */

			 FlatFrameSettingsDialog::FormPtr->SetDarkFrameOptionComboBox(flatFrameSettings.darkOption);
			 FlatFrameSettingsDialog::FormPtr->SetDarkDirTextBox(flatFrameSettings.DarkDir);

			 /* Which filters to do & exposure times for each */

			 if (flatFrameSettings.filterSeq.Use[HFILTERNUM]) {
				 FlatFrameSettingsDialog::FormPtr->HCheckBox->Checked = true;
				 sprintf_s(buffer, sizeof(buffer), "%6.2f", flatFrameSettings.filterSeq.exposures[HFILTERNUM]);
				 FlatFrameSettingsDialog::FormPtr->SetHExpTimeTextBox(buffer);
			 } else {
				 FlatFrameSettingsDialog::FormPtr->HCheckBox->Checked = false;
			 }
			 if (flatFrameSettings.filterSeq.Use[BFILTERNUM]) {
				 FlatFrameSettingsDialog::FormPtr->BCheckBox->Checked = true;
				 sprintf_s(buffer, sizeof(buffer), "%6.2f", flatFrameSettings.filterSeq.exposures[BFILTERNUM]);
				 FlatFrameSettingsDialog::FormPtr->SetBExpTimeTextBox(buffer);
			 } else {
				 FlatFrameSettingsDialog::FormPtr->BCheckBox->Checked = false;
			 }
			 if (flatFrameSettings.filterSeq.Use[VFILTERNUM]) {
				 FlatFrameSettingsDialog::FormPtr->VCheckBox->Checked = true;
				 sprintf_s(buffer, sizeof(buffer), "%6.2f", flatFrameSettings.filterSeq.exposures[VFILTERNUM]);
				 FlatFrameSettingsDialog::FormPtr->SetVExpTimeTextBox(buffer);
			 } else {
				 FlatFrameSettingsDialog::FormPtr->VCheckBox->Checked = false;
			 }
			 if (flatFrameSettings.filterSeq.Use[RFILTERNUM]) {
				 FlatFrameSettingsDialog::FormPtr->RCheckBox->Checked = true;
				 sprintf_s(buffer, sizeof(buffer), "%6.2f", flatFrameSettings.filterSeq.exposures[RFILTERNUM]);
				 FlatFrameSettingsDialog::FormPtr->SetRExpTimeTextBox(buffer);
			 } else {
				 FlatFrameSettingsDialog::FormPtr->RCheckBox->Checked = false;
			 }
			 if (flatFrameSettings.filterSeq.Use[IFILTERNUM]) {
				 FlatFrameSettingsDialog::FormPtr->ICheckBox->Checked = true;
				 sprintf_s(buffer, sizeof(buffer), "%6.2f", flatFrameSettings.filterSeq.exposures[IFILTERNUM]);
				 FlatFrameSettingsDialog::FormPtr->SetIExpTimeTextBox(buffer);
			 } else {
				 FlatFrameSettingsDialog::FormPtr->ICheckBox->Checked = false;
			 }
			 if (flatFrameSettings.filterSeq.Use[CFILTERNUM]) {
				 FlatFrameSettingsDialog::FormPtr->CCheckBox->Checked = true;
				 sprintf_s(buffer, sizeof(buffer), "%6.2f", flatFrameSettings.filterSeq.exposures[CFILTERNUM]);
				 FlatFrameSettingsDialog::FormPtr->SetCExpTimeTextBox(buffer);
			 } else {
				 FlatFrameSettingsDialog::FormPtr->CCheckBox->Checked = false;
			 }

			 /* Save each frame? */

			 FlatFrameSettingsDialog::FormPtr->SaveEachFlatCheckBox->Checked =
					FlatSaveEachDarkFrame;

			 /* combine method */

			 if (flatFrameSettings.combineMethod == 1)
				 FlatFrameSettingsDialog::FormPtr->MedianButton->Checked = true;
			 else
				 FlatFrameSettingsDialog::FormPtr->MeanButton->Checked = true;

			 return true;
		 }

public:  int GetFlatFrameSettings(void) {

			 char buffer[80];
			 float value;

			 /* # frames */

			 FlatFrameSettingsDialog::FormPtr->GetNumFramesTextBox(buffer);
			 sscanf_s(buffer, "%d", &flatFrameSettings.numFrames);

			 /* Which ccd */

		     if (ccd->make == SBIG_MAKE)
				 flatFrameSettings.whichCCD = FlatFrameSettingsDialog::GetWhichCCDButton();
			 else
				 flatFrameSettings.whichCCD = 0;
			 
			 /* Binning */

			 flatFrameSettings.binning = FlatFrameSettingsDialog::FormPtr->GetWhichBinningButton();

			 /* ccd Frame size */

			 FlatFrameSettingsDialog::FormPtr->GetFrameTextBox(buffer);
			 sscanf_s(buffer, "%d, %d, %d, %d", &flatFrameSettings.x,
				 &flatFrameSettings.y, &flatFrameSettings.h, &flatFrameSettings.w);

			 /* Get dark frame option */

			 flatFrameSettings.darkOption = FlatFrameSettingsDialog::FormPtr->GetDarkFrameOptionComboBox()+1;
			 FlatFrameSettingsDialog::FormPtr->GetDarkDirTextBox(flatFrameSettings.DarkDir);

			 /* Get which filters to do & exposure times for each */

			 if (FlatFrameSettingsDialog::FormPtr->HCheckBox->Checked) {
				 flatFrameSettings.filterSeq.Use[HFILTERNUM] = true;
				 FlatFrameSettingsDialog::FormPtr->GetHExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 flatFrameSettings.filterSeq.exposures[HFILTERNUM] = value;
			 } else
				 flatFrameSettings.filterSeq.Use[HFILTERNUM] = false;

			 if (FlatFrameSettingsDialog::FormPtr->BCheckBox->Checked) {
				 flatFrameSettings.filterSeq.Use[BFILTERNUM] = true;
				 FlatFrameSettingsDialog::FormPtr->GetBExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 flatFrameSettings.filterSeq.exposures[BFILTERNUM] = value;
			 } else
				 flatFrameSettings.filterSeq.Use[BFILTERNUM] = false;

			 if (FlatFrameSettingsDialog::FormPtr->VCheckBox->Checked) {
				 flatFrameSettings.filterSeq.Use[VFILTERNUM] = true;
				 FlatFrameSettingsDialog::FormPtr->GetVExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 flatFrameSettings.filterSeq.exposures[VFILTERNUM] = value;
			 } else
				 flatFrameSettings.filterSeq.Use[VFILTERNUM] = false;

			 if (FlatFrameSettingsDialog::FormPtr->RCheckBox->Checked) {
				 flatFrameSettings.filterSeq.Use[RFILTERNUM] = true;
				 FlatFrameSettingsDialog::FormPtr->GetRExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 flatFrameSettings.filterSeq.exposures[RFILTERNUM] = value;
			 } else
				 flatFrameSettings.filterSeq.Use[RFILTERNUM] = false;

			 if (FlatFrameSettingsDialog::FormPtr->ICheckBox->Checked) {
				 flatFrameSettings.filterSeq.Use[IFILTERNUM] = true;
				 FlatFrameSettingsDialog::FormPtr->GetIExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 flatFrameSettings.filterSeq.exposures[IFILTERNUM] = value;
			 } else
				 flatFrameSettings.filterSeq.Use[IFILTERNUM] = false;

			 if (FlatFrameSettingsDialog::FormPtr->CCheckBox->Checked) {
				 flatFrameSettings.filterSeq.Use[CFILTERNUM] = true;
				 FlatFrameSettingsDialog::FormPtr->GetCExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 flatFrameSettings.filterSeq.exposures[CFILTERNUM] = value;
			 } else
				 flatFrameSettings.filterSeq.Use[CFILTERNUM] = false;

			 /* Save each frame? */

			 FlatSaveEachDarkFrame =
					FlatFrameSettingsDialog::FormPtr->SaveEachFlatCheckBox->Checked;

			 /* combine method */

			 if (FlatFrameSettingsDialog::FormPtr->MedianButton->Checked)
				 flatFrameSettings.combineMethod = 1;
			 else
				 flatFrameSettings.combineMethod = 2;

			 return true;
		 }

};
}
