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
	/// Summary for SeriesSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SeriesSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static SeriesSettingsDialog^ FormPtr;
		SeriesSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			SeriesSettingsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SeriesSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			SeriesSettingsDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  CancelButton;

	private: System::Windows::Forms::Button^  ExecuteButton;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::RadioButton^  TrackingCCDButton;
	private: System::Windows::Forms::RadioButton^  ImagingCCDButton;





	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::ComboBox^  DarkFrameOptionComboBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;

	private: System::Windows::Forms::TextBox^  DarkDirTextBox;


	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::ComboBox^  FlatFrameOptionComboBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::TextBox^  FlatDirTextBox;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  Binning3x3Button;
	private: System::Windows::Forms::RadioButton^  Binning1x1Button;
	private: System::Windows::Forms::RadioButton^  Binning2x2Button;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  FrameTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  ObjectNameTextBox;
	private: System::Windows::Forms::TextBox^  ImageDirTextBox;
	private: System::Windows::Forms::CheckBox^  AutoBumpCheckBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel14;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  SeqNumTextBox;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::CheckBox^  StartASAPCheckBox;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  StartTimeTextBox;
	private: System::Windows::Forms::TextBox^  DurationTextBox;
	private: System::Windows::Forms::TextBox^  IntervalTextBox;



	private: System::Windows::Forms::Label^  label11;

	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::CheckBox^  HCheckBox;

	private: System::Windows::Forms::CheckBox^  BCheckBox;
	private: System::Windows::Forms::CheckBox^  VCheckBox;
	private: System::Windows::Forms::CheckBox^  RCheckBox;
	private: System::Windows::Forms::CheckBox^  ICheckBox;




	private: System::Windows::Forms::TextBox^  IExpTimeTextBox;
	private: System::Windows::Forms::TextBox^  RExpTimeTextBox;
	private: System::Windows::Forms::TextBox^  VExpTimeTextBox;
	private: System::Windows::Forms::TextBox^  BExpTimeTextBox;
private: System::Windows::Forms::TextBox^  HExpTimeTextBox;

private: System::Windows::Forms::Button^  PickDarkFolderButton;
private: System::Windows::Forms::Button^  PickFlatFolderButton;
private: System::Windows::Forms::Button^  PickImageFolderButton;
private: System::Windows::Forms::CheckBox^  CCheckBox;
private: System::Windows::Forms::TextBox^  CExpTimeTextBox;
private: System::Windows::Forms::CheckBox^  RawCheckBox;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel16;
private: System::Windows::Forms::CheckBox^  CloseObsCheckBox;
private: System::Windows::Forms::Label^  label1;















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
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Binning3x3Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning1x1Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning2x2Button = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FlatFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FlatDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickFlatFolderButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DarkFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DarkDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickDarkFolderButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->TrackingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->ImagingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickImageFolderButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->FrameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ObjectNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ImageDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RawCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel14 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SeqNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StartASAPCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->StartTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DurationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IntervalTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel16 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CloseObsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel15 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->HCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AutoBumpCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->RCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ICheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tableLayoutPanel12->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel14->SuspendLayout();
			this->tableLayoutPanel16->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->tableLayoutPanel15->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel9, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30.56995F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60.71429F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.928572F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(496, 399);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel2->Controls->Add(this->ExecuteButton, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 365);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(490, 31);
			this->tableLayoutPanel2->TabIndex = 4;
			// 
			// ExecuteButton
			// 
			this->ExecuteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ExecuteButton->Location = System::Drawing::Point(207, 4);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(75, 23);
			this->ExecuteButton->TabIndex = 1;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			this->ExecuteButton->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::ExecuteButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(44, 4);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(370, 4);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::CancelButton_Click);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				24.08163F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				19.59184F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				28.51153F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				28.09224F)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox2, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox5, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox3, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 115)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(490, 115);
			this->tableLayoutPanel4->TabIndex = 5;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel6);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(120, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(89, 109);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"CCD Binning\?";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel6->Controls->Add(this->Binning3x3Button, 0, 2);
			this->tableLayoutPanel6->Controls->Add(this->Binning1x1Button, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->Binning2x2Button, 0, 1);
			this->tableLayoutPanel6->Location = System::Drawing::Point(0, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 3;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(59, 78);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// Binning3x3Button
			// 
			this->Binning3x3Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning3x3Button->AutoSize = true;
			this->Binning3x3Button->Location = System::Drawing::Point(3, 56);
			this->Binning3x3Button->Name = L"Binning3x3Button";
			this->Binning3x3Button->Size = System::Drawing::Size(42, 17);
			this->Binning3x3Button->TabIndex = 3;
			this->Binning3x3Button->TabStop = true;
			this->Binning3x3Button->Text = L"3x3";
			this->Binning3x3Button->UseVisualStyleBackColor = true;
			this->Binning3x3Button->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::BinningButton_Click);
			// 
			// Binning1x1Button
			// 
			this->Binning1x1Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning1x1Button->AutoSize = true;
			this->Binning1x1Button->Location = System::Drawing::Point(3, 4);
			this->Binning1x1Button->Name = L"Binning1x1Button";
			this->Binning1x1Button->Size = System::Drawing::Size(42, 17);
			this->Binning1x1Button->TabIndex = 1;
			this->Binning1x1Button->TabStop = true;
			this->Binning1x1Button->Text = L"1x1";
			this->Binning1x1Button->UseVisualStyleBackColor = true;
			this->Binning1x1Button->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::BinningButton_Click);
			// 
			// Binning2x2Button
			// 
			this->Binning2x2Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning2x2Button->AutoSize = true;
			this->Binning2x2Button->Location = System::Drawing::Point(3, 30);
			this->Binning2x2Button->Name = L"Binning2x2Button";
			this->Binning2x2Button->Size = System::Drawing::Size(42, 17);
			this->Binning2x2Button->TabIndex = 2;
			this->Binning2x2Button->TabStop = true;
			this->Binning2x2Button->Text = L"2x2";
			this->Binning2x2Button->UseVisualStyleBackColor = true;
			this->Binning2x2Button->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::BinningButton_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel10);
			this->groupBox5->Location = System::Drawing::Point(354, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(129, 108);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Flat Frame Options";
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 1;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel10->Controls->Add(this->FlatFrameOptionComboBox, 0, 0);
			this->tableLayoutPanel10->Controls->Add(this->FlatDirTextBox, 0, 2);
			this->tableLayoutPanel10->Controls->Add(this->tableLayoutPanel11, 0, 1);
			this->tableLayoutPanel10->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 3;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 38.70968F)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.03226F)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(127, 93);
			this->tableLayoutPanel10->TabIndex = 1;
			// 
			// FlatFrameOptionComboBox
			// 
			this->FlatFrameOptionComboBox->FormattingEnabled = true;
			this->FlatFrameOptionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Don\'t do flat frame", L"Reuse current flat frame", 
				L"Use flat frame from file"});
			this->FlatFrameOptionComboBox->Location = System::Drawing::Point(3, 3);
			this->FlatFrameOptionComboBox->Name = L"FlatFrameOptionComboBox";
			this->FlatFrameOptionComboBox->Size = System::Drawing::Size(121, 21);
			this->FlatFrameOptionComboBox->TabIndex = 0;
			// 
			// FlatDirTextBox
			// 
			this->FlatDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FlatDirTextBox->Location = System::Drawing::Point(16, 69);
			this->FlatDirTextBox->Name = L"FlatDirTextBox";
			this->FlatDirTextBox->Size = System::Drawing::Size(95, 20);
			this->FlatDirTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 2;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				46.79803F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.20197F)));
			this->tableLayoutPanel11->Controls->Add(this->PickFlatFolderButton, 0, 0);
			this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel11->Location = System::Drawing::Point(3, 33);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				29)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(121, 29);
			this->tableLayoutPanel11->TabIndex = 1;
			// 
			// PickFlatFolderButton
			// 
			this->PickFlatFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel11->SetColumnSpan(this->PickFlatFolderButton, 2);
			this->PickFlatFolderButton->Location = System::Drawing::Point(14, 4);
			this->PickFlatFolderButton->Name = L"PickFlatFolderButton";
			this->PickFlatFolderButton->Size = System::Drawing::Size(93, 21);
			this->PickFlatFolderButton->TabIndex = 11;
			this->PickFlatFolderButton->Text = L"Pick Flat Folder";
			this->PickFlatFolderButton->UseVisualStyleBackColor = true;
			this->PickFlatFolderButton->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::PickFlatFolderButton_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel7);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(215, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(133, 109);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Dark Frame Options";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 1;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel7->Controls->Add(this->DarkFrameOptionComboBox, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->DarkDirTextBox, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->tableLayoutPanel8, 0, 1);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 39.32584F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.08989F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(127, 90);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// DarkFrameOptionComboBox
			// 
			this->DarkFrameOptionComboBox->FormattingEnabled = true;
			this->DarkFrameOptionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Automatic dark frame", L"Force new dark frame", 
				L"Use dark frame from file", L"Don\'t use dark frame"});
			this->DarkFrameOptionComboBox->Location = System::Drawing::Point(3, 3);
			this->DarkFrameOptionComboBox->Name = L"DarkFrameOptionComboBox";
			this->DarkFrameOptionComboBox->Size = System::Drawing::Size(117, 21);
			this->DarkFrameOptionComboBox->TabIndex = 0;
			// 
			// DarkDirTextBox
			// 
			this->DarkDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DarkDirTextBox->Location = System::Drawing::Point(16, 67);
			this->DarkDirTextBox->Name = L"DarkDirTextBox";
			this->DarkDirTextBox->Size = System::Drawing::Size(95, 20);
			this->DarkDirTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 2;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.33333F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				46.66667F)));
			this->tableLayoutPanel8->Controls->Add(this->PickDarkFolderButton, 0, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 32);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(121, 29);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// PickDarkFolderButton
			// 
			this->PickDarkFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel8->SetColumnSpan(this->PickDarkFolderButton, 2);
			this->PickDarkFolderButton->Location = System::Drawing::Point(9, 4);
			this->PickDarkFolderButton->Name = L"PickDarkFolderButton";
			this->PickDarkFolderButton->Size = System::Drawing::Size(103, 21);
			this->PickDarkFolderButton->TabIndex = 3;
			this->PickDarkFolderButton->Text = L"Pick Dark Folder";
			this->PickDarkFolderButton->UseVisualStyleBackColor = true;
			this->PickDarkFolderButton->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::PickDarkFolderButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(108, 108);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Which CCD\?";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel5->Controls->Add(this->TrackingCCDButton, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->ImagingCCDButton, 0, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(100, 49);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// TrackingCCDButton
			// 
			this->TrackingCCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TrackingCCDButton->AutoSize = true;
			this->TrackingCCDButton->Location = System::Drawing::Point(3, 28);
			this->TrackingCCDButton->Name = L"TrackingCCDButton";
			this->TrackingCCDButton->Size = System::Drawing::Size(92, 17);
			this->TrackingCCDButton->TabIndex = 1;
			this->TrackingCCDButton->TabStop = true;
			this->TrackingCCDButton->Text = L"Tracking CCD";
			this->TrackingCCDButton->UseVisualStyleBackColor = true;
			// 
			// ImagingCCDButton
			// 
			this->ImagingCCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ImagingCCDButton->AutoSize = true;
			this->ImagingCCDButton->Location = System::Drawing::Point(3, 3);
			this->ImagingCCDButton->Name = L"ImagingCCDButton";
			this->ImagingCCDButton->Size = System::Drawing::Size(87, 17);
			this->ImagingCCDButton->TabIndex = 0;
			this->ImagingCCDButton->TabStop = true;
			this->ImagingCCDButton->Text = L"Imaging CCD";
			this->ImagingCCDButton->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 2;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				61.83673F)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				38.16327F)));
			this->tableLayoutPanel9->Controls->Add(this->tableLayoutPanel12, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->groupBox7, 1, 0);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 124);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 235)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(490, 235);
			this->tableLayoutPanel9->TabIndex = 6;
			// 
			// tableLayoutPanel12
			// 
			this->tableLayoutPanel12->ColumnCount = 1;
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel12->Controls->Add(this->groupBox6, 0, 1);
			this->tableLayoutPanel12->Controls->Add(this->groupBox4, 0, 0);
			this->tableLayoutPanel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel12->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
			this->tableLayoutPanel12->RowCount = 2;
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 53.71179F)));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.28821F)));
			this->tableLayoutPanel12->Size = System::Drawing::Size(296, 229);
			this->tableLayoutPanel12->TabIndex = 0;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tableLayoutPanel13);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox6->Location = System::Drawing::Point(3, 125);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(290, 101);
			this->groupBox6->TabIndex = 3;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Frame Parameters";
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->ColumnCount = 3;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				39.77695F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				39.62963F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20.74074F)));
			this->tableLayoutPanel13->Controls->Add(this->PickImageFolderButton, 0, 2);
			this->tableLayoutPanel13->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel13->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel13->Controls->Add(this->FrameTextBox, 1, 0);
			this->tableLayoutPanel13->Controls->Add(this->label6, 0, 1);
			this->tableLayoutPanel13->Controls->Add(this->ObjectNameTextBox, 1, 1);
			this->tableLayoutPanel13->Controls->Add(this->ImageDirTextBox, 1, 2);
			this->tableLayoutPanel13->Controls->Add(this->RawCheckBox, 2, 2);
			this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel13->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 3;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel13->Size = System::Drawing::Size(284, 82);
			this->tableLayoutPanel13->TabIndex = 0;
			// 
			// PickImageFolderButton
			// 
			this->PickImageFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PickImageFolderButton->Location = System::Drawing::Point(5, 57);
			this->PickImageFolderButton->Name = L"PickImageFolderButton";
			this->PickImageFolderButton->Size = System::Drawing::Size(101, 21);
			this->PickImageFolderButton->TabIndex = 12;
			this->PickImageFolderButton->Text = L"Pick Image Folder";
			this->PickImageFolderButton->UseVisualStyleBackColor = true;
			this->PickImageFolderButton->Click += gcnew System::EventHandler(this, &SeriesSettingsDialog::PickImageFolderButton_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(57, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"x, y, h, w:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(227, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"pixels";
			// 
			// FrameTextBox
			// 
			this->FrameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FrameTextBox->Location = System::Drawing::Point(115, 3);
			this->FrameTextBox->Name = L"FrameTextBox";
			this->FrameTextBox->Size = System::Drawing::Size(100, 20);
			this->FrameTextBox->TabIndex = 6;
			this->FrameTextBox->Text = L"0,0,1024,1024";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(49, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Obj. Name:";
			// 
			// ObjectNameTextBox
			// 
			this->ObjectNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectNameTextBox->Location = System::Drawing::Point(115, 30);
			this->ObjectNameTextBox->Name = L"ObjectNameTextBox";
			this->ObjectNameTextBox->Size = System::Drawing::Size(100, 20);
			this->ObjectNameTextBox->TabIndex = 8;
			// 
			// ImageDirTextBox
			// 
			this->ImageDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ImageDirTextBox->Location = System::Drawing::Point(115, 58);
			this->ImageDirTextBox->Name = L"ImageDirTextBox";
			this->ImageDirTextBox->Size = System::Drawing::Size(100, 20);
			this->ImageDirTextBox->TabIndex = 9;
			// 
			// RawCheckBox
			// 
			this->RawCheckBox->AutoSize = true;
			this->RawCheckBox->Location = System::Drawing::Point(227, 57);
			this->RawCheckBox->Name = L"RawCheckBox";
			this->RawCheckBox->Size = System::Drawing::Size(48, 17);
			this->RawCheckBox->TabIndex = 13;
			this->RawCheckBox->Text = L"Raw";
			this->RawCheckBox->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel14);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(290, 116);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Series Timing";
			// 
			// tableLayoutPanel14
			// 
			this->tableLayoutPanel14->ColumnCount = 3;
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				24.74916F)));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20.73579F)));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				54.51505F)));
			this->tableLayoutPanel14->Controls->Add(this->label10, 0, 3);
			this->tableLayoutPanel14->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel14->Controls->Add(this->SeqNumTextBox, 1, 0);
			this->tableLayoutPanel14->Controls->Add(this->StartASAPCheckBox, 2, 0);
			this->tableLayoutPanel14->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel14->Controls->Add(this->label9, 0, 2);
			this->tableLayoutPanel14->Controls->Add(this->StartTimeTextBox, 1, 1);
			this->tableLayoutPanel14->Controls->Add(this->DurationTextBox, 1, 2);
			this->tableLayoutPanel14->Controls->Add(this->IntervalTextBox, 1, 3);
			this->tableLayoutPanel14->Controls->Add(this->label11, 2, 1);
			this->tableLayoutPanel14->Controls->Add(this->label13, 2, 3);
			this->tableLayoutPanel14->Controls->Add(this->tableLayoutPanel16, 2, 2);
			this->tableLayoutPanel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel14->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel14->Name = L"tableLayoutPanel14";
			this->tableLayoutPanel14->RowCount = 4;
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 23.46939F)));
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.57143F)));
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.44898F)));
			this->tableLayoutPanel14->Size = System::Drawing::Size(284, 97);
			this->tableLayoutPanel14->TabIndex = 0;
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(22, 78);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(45, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Interval:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Start Seq. #:";
			// 
			// SeqNumTextBox
			// 
			this->SeqNumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SeqNumTextBox->Location = System::Drawing::Point(73, 3);
			this->SeqNumTextBox->Name = L"SeqNumTextBox";
			this->SeqNumTextBox->Size = System::Drawing::Size(49, 20);
			this->SeqNumTextBox->TabIndex = 7;
			this->SeqNumTextBox->Text = L"1";
			// 
			// StartASAPCheckBox
			// 
			this->StartASAPCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StartASAPCheckBox->AutoSize = true;
			this->StartASAPCheckBox->Location = System::Drawing::Point(151, 3);
			this->StartASAPCheckBox->Name = L"StartASAPCheckBox";
			this->StartASAPCheckBox->Size = System::Drawing::Size(109, 17);
			this->StartASAPCheckBox->TabIndex = 12;
			this->StartASAPCheckBox->Text = L"Start series ASAP";
			this->StartASAPCheckBox->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Start Time:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(17, 53);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Duration:";
			// 
			// StartTimeTextBox
			// 
			this->StartTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StartTimeTextBox->Location = System::Drawing::Point(73, 27);
			this->StartTimeTextBox->Name = L"StartTimeTextBox";
			this->StartTimeTextBox->Size = System::Drawing::Size(49, 20);
			this->StartTimeTextBox->TabIndex = 16;
			this->StartTimeTextBox->Text = L"00:00:00";
			// 
			// DurationTextBox
			// 
			this->DurationTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DurationTextBox->Location = System::Drawing::Point(73, 49);
			this->DurationTextBox->Name = L"DurationTextBox";
			this->DurationTextBox->Size = System::Drawing::Size(49, 20);
			this->DurationTextBox->TabIndex = 17;
			this->DurationTextBox->Text = L"00:00:00";
			// 
			// IntervalTextBox
			// 
			this->IntervalTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->IntervalTextBox->Location = System::Drawing::Point(73, 76);
			this->IntervalTextBox->Name = L"IntervalTextBox";
			this->IntervalTextBox->Size = System::Drawing::Size(49, 20);
			this->IntervalTextBox->TabIndex = 18;
			this->IntervalTextBox->Text = L"60.0";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(131, 28);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"(hh:mm:ss)";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(131, 78);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(53, 13);
			this->label13->TabIndex = 21;
			this->label13->Text = L"(seconds)";
			// 
			// tableLayoutPanel16
			// 
			this->tableLayoutPanel16->ColumnCount = 2;
			this->tableLayoutPanel16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				45.45454F)));
			this->tableLayoutPanel16->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				54.54546F)));
			this->tableLayoutPanel16->Controls->Add(this->CloseObsCheckBox, 0, 0);
			this->tableLayoutPanel16->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel16->Location = System::Drawing::Point(131, 49);
			this->tableLayoutPanel16->Name = L"tableLayoutPanel16";
			this->tableLayoutPanel16->RowCount = 1;
			this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel16->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				21)));
			this->tableLayoutPanel16->Size = System::Drawing::Size(150, 21);
			this->tableLayoutPanel16->TabIndex = 22;
			// 
			// CloseObsCheckBox
			// 
			this->CloseObsCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseObsCheckBox->AutoSize = true;
			this->CloseObsCheckBox->Location = System::Drawing::Point(72, 3);
			this->CloseObsCheckBox->Name = L"CloseObsCheckBox";
			this->CloseObsCheckBox->Size = System::Drawing::Size(74, 15);
			this->CloseObsCheckBox->TabIndex = 21;
			this->CloseObsCheckBox->Text = L"Close Obs";
			this->CloseObsCheckBox->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"(hh:mm:ss)";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->tableLayoutPanel15);
			this->groupBox7->Location = System::Drawing::Point(305, 3);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(181, 223);
			this->groupBox7->TabIndex = 1;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Filter Sequence Settings";
			// 
			// tableLayoutPanel15
			// 
			this->tableLayoutPanel15->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->tableLayoutPanel15->ColumnCount = 2;
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				39.88095F)));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				60.11905F)));
			this->tableLayoutPanel15->Controls->Add(this->label14, 0, 0);
			this->tableLayoutPanel15->Controls->Add(this->label15, 1, 0);
			this->tableLayoutPanel15->Controls->Add(this->HCheckBox, 0, 5);
			this->tableLayoutPanel15->Controls->Add(this->CCheckBox, 0, 6);
			this->tableLayoutPanel15->Controls->Add(this->HExpTimeTextBox, 1, 5);
			this->tableLayoutPanel15->Controls->Add(this->AutoBumpCheckBox, 0, 7);
			this->tableLayoutPanel15->Controls->Add(this->CExpTimeTextBox, 1, 6);
			this->tableLayoutPanel15->Controls->Add(this->BCheckBox, 0, 1);
			this->tableLayoutPanel15->Controls->Add(this->RCheckBox, 0, 3);
			this->tableLayoutPanel15->Controls->Add(this->VCheckBox, 0, 2);
			this->tableLayoutPanel15->Controls->Add(this->ICheckBox, 0, 4);
			this->tableLayoutPanel15->Controls->Add(this->BExpTimeTextBox, 1, 1);
			this->tableLayoutPanel15->Controls->Add(this->VExpTimeTextBox, 1, 2);
			this->tableLayoutPanel15->Controls->Add(this->RExpTimeTextBox, 1, 3);
			this->tableLayoutPanel15->Controls->Add(this->IExpTimeTextBox, 1, 4);
			this->tableLayoutPanel15->Location = System::Drawing::Point(2, 19);
			this->tableLayoutPanel15->Name = L"tableLayoutPanel15";
			this->tableLayoutPanel15->RowCount = 7;
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.49938F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.50187F)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.50187F)));
			this->tableLayoutPanel15->Size = System::Drawing::Size(168, 199);
			this->tableLayoutPanel15->TabIndex = 0;
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(4, 5);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(57, 13);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Use Filter\?";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(76, 5);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(82, 13);
			this->label15->TabIndex = 7;
			this->label15->Text = L"Exposure (secs)";
			// 
			// HCheckBox
			// 
			this->HCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HCheckBox->AutoSize = true;
			this->HCheckBox->Location = System::Drawing::Point(16, 123);
			this->HCheckBox->Name = L"HCheckBox";
			this->HCheckBox->Size = System::Drawing::Size(34, 17);
			this->HCheckBox->TabIndex = 8;
			this->HCheckBox->Text = L"H";
			this->HCheckBox->UseVisualStyleBackColor = true;
			// 
			// CCheckBox
			// 
			this->CCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CCheckBox->AutoSize = true;
			this->CCheckBox->Location = System::Drawing::Point(16, 147);
			this->CCheckBox->Name = L"CCheckBox";
			this->CCheckBox->Size = System::Drawing::Size(33, 17);
			this->CCheckBox->TabIndex = 24;
			this->CCheckBox->Text = L"C";
			this->CCheckBox->UseVisualStyleBackColor = true;
			// 
			// HExpTimeTextBox
			// 
			this->HExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HExpTimeTextBox->Location = System::Drawing::Point(89, 123);
			this->HExpTimeTextBox->Name = L"HExpTimeTextBox";
			this->HExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->HExpTimeTextBox->TabIndex = 19;
			// 
			// AutoBumpCheckBox
			// 
			this->AutoBumpCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AutoBumpCheckBox->AutoSize = true;
			this->tableLayoutPanel15->SetColumnSpan(this->AutoBumpCheckBox, 2);
			this->AutoBumpCheckBox->Location = System::Drawing::Point(45, 175);
			this->AutoBumpCheckBox->Name = L"AutoBumpCheckBox";
			this->AutoBumpCheckBox->Size = System::Drawing::Size(78, 17);
			this->AutoBumpCheckBox->TabIndex = 11;
			this->AutoBumpCheckBox->Text = L"Auto Bump";
			this->AutoBumpCheckBox->UseVisualStyleBackColor = true;
			// 
			// CExpTimeTextBox
			// 
			this->CExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CExpTimeTextBox->Location = System::Drawing::Point(89, 147);
			this->CExpTimeTextBox->Name = L"CExpTimeTextBox";
			this->CExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->CExpTimeTextBox->TabIndex = 25;
			// 
			// BCheckBox
			// 
			this->BCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BCheckBox->AutoSize = true;
			this->BCheckBox->Location = System::Drawing::Point(16, 27);
			this->BCheckBox->Name = L"BCheckBox";
			this->BCheckBox->Size = System::Drawing::Size(33, 17);
			this->BCheckBox->TabIndex = 9;
			this->BCheckBox->Text = L"B";
			this->BCheckBox->UseVisualStyleBackColor = true;
			// 
			// RCheckBox
			// 
			this->RCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RCheckBox->AutoSize = true;
			this->RCheckBox->Location = System::Drawing::Point(16, 75);
			this->RCheckBox->Name = L"RCheckBox";
			this->RCheckBox->Size = System::Drawing::Size(34, 17);
			this->RCheckBox->TabIndex = 11;
			this->RCheckBox->Text = L"R";
			this->RCheckBox->UseVisualStyleBackColor = true;
			// 
			// VCheckBox
			// 
			this->VCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VCheckBox->AutoSize = true;
			this->VCheckBox->Location = System::Drawing::Point(16, 51);
			this->VCheckBox->Name = L"VCheckBox";
			this->VCheckBox->Size = System::Drawing::Size(33, 17);
			this->VCheckBox->TabIndex = 10;
			this->VCheckBox->Text = L"V";
			this->VCheckBox->UseVisualStyleBackColor = true;
			// 
			// ICheckBox
			// 
			this->ICheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ICheckBox->AutoSize = true;
			this->ICheckBox->Location = System::Drawing::Point(17, 99);
			this->ICheckBox->Name = L"ICheckBox";
			this->ICheckBox->Size = System::Drawing::Size(32, 17);
			this->ICheckBox->TabIndex = 12;
			this->ICheckBox->Text = L" I";
			this->ICheckBox->UseVisualStyleBackColor = true;
			// 
			// BExpTimeTextBox
			// 
			this->BExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BExpTimeTextBox->Location = System::Drawing::Point(89, 27);
			this->BExpTimeTextBox->Name = L"BExpTimeTextBox";
			this->BExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->BExpTimeTextBox->TabIndex = 20;
			// 
			// VExpTimeTextBox
			// 
			this->VExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VExpTimeTextBox->Location = System::Drawing::Point(89, 51);
			this->VExpTimeTextBox->Name = L"VExpTimeTextBox";
			this->VExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->VExpTimeTextBox->TabIndex = 21;
			// 
			// RExpTimeTextBox
			// 
			this->RExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RExpTimeTextBox->Location = System::Drawing::Point(89, 75);
			this->RExpTimeTextBox->Name = L"RExpTimeTextBox";
			this->RExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->RExpTimeTextBox->TabIndex = 22;
			// 
			// IExpTimeTextBox
			// 
			this->IExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->IExpTimeTextBox->Location = System::Drawing::Point(89, 99);
			this->IExpTimeTextBox->Name = L"IExpTimeTextBox";
			this->IExpTimeTextBox->Size = System::Drawing::Size(56, 20);
			this->IExpTimeTextBox->TabIndex = 23;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25)));
			this->tableLayoutPanel3->Controls->Add(this->button1, 3, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(200, 100);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(153, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(44, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Location = System::Drawing::Point(65, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(25, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Apply";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// SeriesSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 399);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"SeriesSettingsDialog";
			this->Text = L"SeriesSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->tableLayoutPanel11->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel12->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel14->ResumeLayout(false);
			this->tableLayoutPanel14->PerformLayout();
			this->tableLayoutPanel16->ResumeLayout(false);
			this->tableLayoutPanel16->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->tableLayoutPanel15->ResumeLayout(false);
			this->tableLayoutPanel15->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

public: static void SetFrameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->FrameTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFrameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->FrameTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSeqNumTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->SeqNumTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSeqNumTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->SeqNumTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetStartTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->StartTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStartTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->StartTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetDurationTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->DurationTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDurationTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->DurationTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetIntervalTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->IntervalTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetIntervalTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->IntervalTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetObjectNameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->ObjectNameTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetObjectNameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->ObjectNameTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetImageDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->ImageDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetImageDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->ImageDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDarkDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->DarkDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDarkDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->DarkDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFlatDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->FlatDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFlatDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->FlatDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDarkFrameOptionComboBox(int index) {
		SeriesSettingsDialog::FormPtr->DarkFrameOptionComboBox->SelectedIndex = index-1;
		}
public: static int GetDarkFrameOptionComboBox(void) {
		int index;
		index = SeriesSettingsDialog::FormPtr->DarkFrameOptionComboBox->SelectedIndex+1;
		return index;
		}
public: static void SetFlatFrameOptionComboBox(int index) {
		SeriesSettingsDialog::FormPtr->FlatFrameOptionComboBox->SelectedIndex = index-1;
		}
public: static int GetFlatFrameOptionComboBox(void) {
		int index;
		index = SeriesSettingsDialog::FormPtr->FlatFrameOptionComboBox->SelectedIndex+1;
		return index;
		}
public: static void SetWhichCCDButton(int which) {
			if (which == 0) {
				SeriesSettingsDialog::FormPtr->ImagingCCDButton->Checked = true;
				SeriesSettingsDialog::FormPtr->TrackingCCDButton->Checked = false;
			} else {
				SeriesSettingsDialog::FormPtr->ImagingCCDButton->Checked = false;
				SeriesSettingsDialog::FormPtr->TrackingCCDButton->Checked = true;
			}
		}
public: static int GetWhichCCDButton(void) {
			if (SeriesSettingsDialog::FormPtr->ImagingCCDButton->Checked) {
				return 0;
			} else {
				return 1;
			}
		}
public: static void SetWhichBinningButton(int binning) {
			if (binning == 0) {
				SeriesSettingsDialog::FormPtr->Binning1x1Button->Checked = true;
				SeriesSettingsDialog::FormPtr->Binning2x2Button->Checked = false;
				SeriesSettingsDialog::FormPtr->Binning3x3Button->Checked = false;
			} else if (binning == 1) {
				SeriesSettingsDialog::FormPtr->Binning1x1Button->Checked = false;
				SeriesSettingsDialog::FormPtr->Binning2x2Button->Checked = true;
				SeriesSettingsDialog::FormPtr->Binning3x3Button->Checked = false;
			} else {
				SeriesSettingsDialog::FormPtr->Binning1x1Button->Checked = false;
				SeriesSettingsDialog::FormPtr->Binning2x2Button->Checked = false;
				SeriesSettingsDialog::FormPtr->Binning3x3Button->Checked = true;
			}
		}
public: static int GetWhichBinningButton(void) {

			if (SeriesSettingsDialog::FormPtr->Binning1x1Button->Checked) {
				return 0;
			} else if (SeriesSettingsDialog::FormPtr->Binning2x2Button->Checked) {
				return 1;
			} else {
				return 2;
			}
		}
public: static void SetHExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->HExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetHExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->HExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetBExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->BExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetBExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->BExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetVExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->VExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetVExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->VExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetRExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->RExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetRExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->RExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetIExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->IExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetIExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->IExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SeriesSettingsDialog::FormPtr->CExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SeriesSettingsDialog::FormPtr->CExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static int GetFilterCheckBoxState(char filter) {
		int state;
		switch (filter) {
		  case 'B':
			state = (SeriesSettingsDialog::FormPtr->BCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'V':
			state = (SeriesSettingsDialog::FormPtr->VCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'R':
			state = (SeriesSettingsDialog::FormPtr->RCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'I':
			state = (SeriesSettingsDialog::FormPtr->ICheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'H':
			state = (SeriesSettingsDialog::FormPtr->HCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  case 'C':
			state = (SeriesSettingsDialog::FormPtr->CCheckBox->CheckState ==
				CheckState::Checked);
			break;
		  default:
		    state = false;
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
		    buffer = SeriesSettingsDialog::FormPtr->BExpTimeTextBox->Text;
			break;
		  case 'V':
		    buffer = SeriesSettingsDialog::FormPtr->VExpTimeTextBox->Text;
			break;
		  case 'R':
		    buffer = SeriesSettingsDialog::FormPtr->RExpTimeTextBox->Text;
			break;
		  case 'I':
		    buffer = SeriesSettingsDialog::FormPtr->IExpTimeTextBox->Text;
			break;
		  case 'H':
		    buffer = SeriesSettingsDialog::FormPtr->HExpTimeTextBox->Text;
			break;
		  case 'C':
		    buffer = SeriesSettingsDialog::FormPtr->CExpTimeTextBox->Text;
			break;
		  default:
			break;
		}
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public:  static int GetSeriesSettings(void) {

			 char buffer[80];
			 float value;
			 unsigned short hours, minutes, seconds;

			 /* Get starting sequence # */

			 SeriesSettingsDialog::GetSeqNumTextBox(buffer);
			 sscanf_s(buffer, "%d", &seriesSettings.startSeqNum);

			 /* Get starting time */

			 SeriesSettingsDialog::GetStartTimeTextBox(buffer);
			 sscanf_s(buffer, "%hd:%hd:%hd", &hours, &minutes, &seconds);
			 seriesSettings.startHours = (float) hours + (float) (minutes/60.0) + (float) (seconds/3600.0);

			 /* Get duration */

			 SeriesSettingsDialog::GetDurationTextBox(buffer);
			 sscanf_s(buffer, "%hd:%hd:%hd", &hours, &minutes, &seconds);
			 seriesSettings.duration = (float) hours + (float) (minutes/60.0) + (float) (seconds/3600.0);

			 /* Get interval */

			 SeriesSettingsDialog::GetIntervalTextBox(buffer);
			 sscanf_s(buffer, "%f", &value);
			 seriesSettings.interval = value;

			 /* Get object name */

			 SeriesSettingsDialog::GetObjectNameTextBox(seriesSettings.objectName);

			 /* Which ccd */

		     if (ccd->make == SBIG_MAKE)
				 seriesSettings.whichCCD = SeriesSettingsDialog::GetWhichCCDButton();
			 else
				 seriesSettings.whichCCD = 0;
			 
			 /* Binning */

			 seriesSettings.binning = SeriesSettingsDialog::FormPtr->GetWhichBinningButton();

			 /* ccd Frame size */

			 SeriesSettingsDialog::FormPtr->GetFrameTextBox(buffer);
			 sscanf_s(buffer, "%d, %d, %d, %d", &seriesSettings.x, &seriesSettings.y,
				 &seriesSettings.h, &seriesSettings.w);

			 /* Get dark frame option */

			 seriesSettings.darkOption = SeriesSettingsDialog::FormPtr->GetDarkFrameOptionComboBox();
			 SeriesSettingsDialog::FormPtr->GetDarkDirTextBox(seriesSettings.DarkDir);

			 /* Get flat frame option */

			 seriesSettings.flatOption = SeriesSettingsDialog::FormPtr->GetFlatFrameOptionComboBox();
			 SeriesSettingsDialog::FormPtr->GetFlatDirTextBox(seriesSettings.FlatDir);

			 /* Get which filters to do & exposure times for each */

			 if (SeriesSettingsDialog::FormPtr->HCheckBox->Checked) {
				 seriesSettings.filterSeq.Use[HFILTERNUM] = true;
				 SeriesSettingsDialog::FormPtr->GetHExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 seriesSettings.filterSeq.exposures[HFILTERNUM] = value;
			 } else {
				 seriesSettings.filterSeq.Use[HFILTERNUM] = false;
			 }
			 if (SeriesSettingsDialog::FormPtr->BCheckBox->Checked) {
				 seriesSettings.filterSeq.Use[BFILTERNUM] = true;
				 SeriesSettingsDialog::FormPtr->GetBExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 seriesSettings.filterSeq.exposures[BFILTERNUM] = value;
			 } else {
				 seriesSettings.filterSeq.Use[BFILTERNUM] = false;
			 }
			 if (SeriesSettingsDialog::FormPtr->VCheckBox->Checked) {
				 seriesSettings.filterSeq.Use[VFILTERNUM] = true;
				 SeriesSettingsDialog::FormPtr->GetVExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 seriesSettings.filterSeq.exposures[VFILTERNUM] = value;
			 } else {
				 seriesSettings.filterSeq.Use[VFILTERNUM] = false;
			 }
			 if (SeriesSettingsDialog::FormPtr->RCheckBox->Checked) {
				 seriesSettings.filterSeq.Use[RFILTERNUM] = true;
				 SeriesSettingsDialog::FormPtr->GetRExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 seriesSettings.filterSeq.exposures[RFILTERNUM] = value;
			 } else {
				 seriesSettings.filterSeq.Use[RFILTERNUM] = false;
			 }
			 if (SeriesSettingsDialog::FormPtr->ICheckBox->Checked) {
				 seriesSettings.filterSeq.Use[IFILTERNUM] = true;
				 SeriesSettingsDialog::FormPtr->GetIExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 seriesSettings.filterSeq.exposures[IFILTERNUM] = value;
			 } else {
				 seriesSettings.filterSeq.Use[IFILTERNUM] = false;
			 }
			 if (SeriesSettingsDialog::FormPtr->CCheckBox->Checked) {
				 seriesSettings.filterSeq.Use[CFILTERNUM] = true;
				 SeriesSettingsDialog::FormPtr->GetCExpTimeTextBox(buffer);
				 sscanf_s(buffer, "%f", &value);
				 seriesSettings.filterSeq.exposures[CFILTERNUM] = value;
			 } else {
				 seriesSettings.filterSeq.Use[CFILTERNUM] = false;
			 }

			 seriesSettings.AutoBumpScope = SeriesSettingsDialog::FormPtr->AutoBumpCheckBox->Checked;
			 seriesSettings.StartSeriesASAP = SeriesSettingsDialog::FormPtr->StartASAPCheckBox->Checked;
			 seriesSettings.SaveRawImages = SeriesSettingsDialog::FormPtr->RawCheckBox->Checked;
			 seriesSettings.CloseObservatoryWhenDone = SeriesSettingsDialog::FormPtr->CloseObsCheckBox->Checked;

			 return true;
		 }
public:  void HideCCDTrackingButton(void) {
			 SeriesSettingsDialog::FormPtr->TrackingCCDButton->Hide();
		 }
public:  void ShowCCDTrackingButton(void) {
			 SeriesSettingsDialog::FormPtr->TrackingCCDButton->Show();
		 }

public: static void SetSeriesSettings(void) {

			char buffer[80];
			unsigned short hours, minutes, seconds;

			/* Set starting sequence # */

			sprintf_s(buffer, sizeof(buffer), "%d", seriesSettings.startSeqNum);
			SeriesSettingsDialog::SetSeqNumTextBox(buffer);

			 /* Set starting time */

			hours = ((int) seriesSettings.startHours);
			minutes = ((int) ((seriesSettings.startHours-hours)*60.0));
			seconds = ((int) ((seriesSettings.startHours-hours-((float) minutes)/60.0)*3600.0));
			sprintf_s(buffer, sizeof(buffer), "%d:%d:%d", hours, minutes, seconds);
			SeriesSettingsDialog::SetStartTimeTextBox(buffer);
			FormPtr->StartASAPCheckBox->Checked = seriesSettings.StartSeriesASAP;
			FormPtr->CloseObsCheckBox->Checked = seriesSettings.CloseObservatoryWhenDone;

			 /* Set duration */

			hours = ((int) seriesSettings.duration);
			minutes = ((int) ((seriesSettings.duration-hours)*60.0));
			seconds = ((int) ((seriesSettings.duration-hours-((float) minutes)/60.0)*3600.0));
			sprintf_s(buffer, sizeof(buffer), "%d:%d:%d", hours, minutes, seconds);
			SeriesSettingsDialog::SetDurationTextBox(buffer);

			 /* Set interval */

			sprintf_s(buffer, sizeof(buffer), "%7.2f", seriesSettings.interval);
			SeriesSettingsDialog::SetIntervalTextBox(buffer);

			/* Set object name */

			SeriesSettingsDialog::FormPtr->SetObjectNameTextBox(seriesSettings.objectName);
			FormPtr->SetImageDirTextBox(seriesSettings.imageDir);
			FormPtr->RawCheckBox->Checked = seriesSettings.SaveRawImages;

			 /* Which ccd */

		    if (ccd->make != SBIG_MAKE) {
				SeriesSettingsDialog::FormPtr->HideCCDTrackingButton();
				SeriesSettingsDialog::FormPtr->SetWhichCCDButton(0);
			} else {
				SeriesSettingsDialog::FormPtr->ShowCCDTrackingButton();
				SeriesSettingsDialog::FormPtr->SetWhichCCDButton(seriesSettings.whichCCD);
			}
			 
			 /* Binning */

			SeriesSettingsDialog::FormPtr->SetWhichBinningButton(seriesSettings.binning);

			 /* ccd Frame size */

			if (seriesSettings.w <= 0) {
				GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
					&seriesSettings.w, &seriesSettings.h, &seriesSettings.binning);
			}
			sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", seriesSettings.x,
				 seriesSettings.y, seriesSettings.h, seriesSettings.w);
			SeriesSettingsDialog::FormPtr->SetFrameTextBox(buffer);

			 /* Dark frame option */

			SeriesSettingsDialog::FormPtr->SetDarkFrameOptionComboBox(seriesSettings.darkOption);
			SeriesSettingsDialog::FormPtr->SetDarkDirTextBox(seriesSettings.DarkDir);

			 /* Flat frame option */

			SeriesSettingsDialog::FormPtr->SetFlatFrameOptionComboBox(seriesSettings.flatOption);
			SeriesSettingsDialog::FormPtr->SetFlatDirTextBox(seriesSettings.FlatDir);

			 /* Which filters to do & exposure times for each */

			if (seriesSettings.filterSeq.Use[HFILTERNUM]) {
				SeriesSettingsDialog::FormPtr->HCheckBox->Checked = true;
				sprintf_s(buffer, sizeof(buffer), "%6.2f", seriesSettings.filterSeq.exposures[HFILTERNUM]);
				SeriesSettingsDialog::FormPtr->SetHExpTimeTextBox(buffer);
			} else {
				SeriesSettingsDialog::FormPtr->HCheckBox->Checked = false;
			}
			if (seriesSettings.filterSeq.Use[BFILTERNUM]) {
				SeriesSettingsDialog::FormPtr->BCheckBox->Checked = true;
				sprintf_s(buffer, sizeof(buffer), "%6.2f", seriesSettings.filterSeq.exposures[BFILTERNUM]);
				SeriesSettingsDialog::FormPtr->SetBExpTimeTextBox(buffer);
			} else {
				SeriesSettingsDialog::FormPtr->BCheckBox->Checked = false;
			}
			if (seriesSettings.filterSeq.Use[VFILTERNUM]) {
				SeriesSettingsDialog::FormPtr->VCheckBox->Checked = true;
				sprintf_s(buffer, sizeof(buffer), "%6.2f", seriesSettings.filterSeq.exposures[VFILTERNUM]);
				SeriesSettingsDialog::FormPtr->SetVExpTimeTextBox(buffer);
			} else {
				SeriesSettingsDialog::FormPtr->VCheckBox->Checked = false;
			}
			if (seriesSettings.filterSeq.Use[RFILTERNUM]) {
				SeriesSettingsDialog::FormPtr->RCheckBox->Checked = true;
				sprintf_s(buffer, sizeof(buffer), "%6.2f", seriesSettings.filterSeq.exposures[RFILTERNUM]);
				SeriesSettingsDialog::FormPtr->SetRExpTimeTextBox(buffer);
			} else {
				SeriesSettingsDialog::FormPtr->RCheckBox->Checked = false;
			}
			if (seriesSettings.filterSeq.Use[IFILTERNUM]) {
				SeriesSettingsDialog::FormPtr->ICheckBox->Checked = true;
				sprintf_s(buffer, sizeof(buffer), "%6.2f", seriesSettings.filterSeq.exposures[IFILTERNUM]);
				SeriesSettingsDialog::FormPtr->SetIExpTimeTextBox(buffer);
			} else {
				SeriesSettingsDialog::FormPtr->ICheckBox->Checked = false;
			}
			if (seriesSettings.filterSeq.Use[CFILTERNUM]) {
				SeriesSettingsDialog::FormPtr->CCheckBox->Checked = true;
				sprintf_s(buffer, sizeof(buffer), "%6.2f", seriesSettings.filterSeq.exposures[CFILTERNUM]);
				SeriesSettingsDialog::FormPtr->SetCExpTimeTextBox(buffer);
			} else {
				SeriesSettingsDialog::FormPtr->CCheckBox->Checked = false;
			}

			return;
		}
public: static void ShowTheDialog(void) {
			SeriesSettingsDialog::FormPtr->ShowDialog();
		}
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 SeriesSettingsDialog::FormPtr->Hide();
			 GetSeriesSettings();
			 return;
		 }
private: System::Void ExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 SeriesSettingsDialog::FormPtr->Hide();
			 GetSeriesSettings();
			 PleaseStartSeries = true;
			 return;
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Restore old settings */
			 
			 memcpy(&seriesSettings, &seriesSettings_Save, sizeof(seriesSettings));
			 SeriesSettingsDialog::Hide();
			 return;
		 }
private: System::Void ImagingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void TrackingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void PickDarkFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Pick Dark Frame Folder", path);
			 strcpy_s(seriesSettings.DarkDir, sizeof(seriesSettings.DarkDir), path);
			 this->FormPtr->SetDarkDirTextBox(seriesSettings.DarkDir);
			 return;
		 }
private: System::Void PickFlatFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Pick Flat Frame Folder", path);
			 strcpy_s(seriesSettings.FlatDir, sizeof(seriesSettings.FlatDir), path);
			 this->FormPtr->SetFlatDirTextBox(seriesSettings.FlatDir);
			 return;
		 }
private: System::Void PickImageFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Pick Image Folder", path);
			 strcpy_s(seriesSettings.imageDir, sizeof(seriesSettings.imageDir), path);
			 this->FormPtr->SetImageDirTextBox(seriesSettings.imageDir);
			 return;
		 }
private: System::Void BinningButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[40];
			 if (SeriesSettingsDialog::FormPtr->Binning1x1Button->Checked) {
				 seriesSettings.binning = 0;
				 GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
					 &seriesSettings.w, &seriesSettings.h, &seriesSettings.binning);
				 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
					 seriesSettings.h, seriesSettings.w);
				 SeriesSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 } else if (SeriesSettingsDialog::FormPtr->Binning2x2Button->Checked) {
				 seriesSettings.binning = 1;
				 GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
					 &seriesSettings.w, &seriesSettings.h, &seriesSettings.binning);
				 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
					 seriesSettings.h, seriesSettings.w);
				 SeriesSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 } else if (SeriesSettingsDialog::FormPtr->Binning3x3Button->Checked) {
				 seriesSettings.binning = 2;
				 GetCCDFrameSettings(ccd, &seriesSettings.x, &seriesSettings.y,
					 &seriesSettings.w, &seriesSettings.h, &seriesSettings.binning);
				 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", seriesSettings.x, seriesSettings.y,
					 seriesSettings.h, seriesSettings.w);
				 SeriesSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 }
		 }
};
}
