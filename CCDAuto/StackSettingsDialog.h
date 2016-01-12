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
	/// Summary for StackSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class StackSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static StackSettingsDialog^ FormPtr;
		StackSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			StackSettingsDialogExists = TRUE;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StackSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			StackSettingsDialogExists = FALSE;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  ApplyButton;
	private: System::Windows::Forms::Button^  ExecuteButton;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::RadioButton^  Binning3x3Button;
	private: System::Windows::Forms::RadioButton^  Binning1x1Button;
	private: System::Windows::Forms::RadioButton^  Binning2x2Button;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  TrackingCCDButton;
	private: System::Windows::Forms::RadioButton^  ImagingCCDButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  FrameTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  NumFramesTextBox;
	private: System::Windows::Forms::TextBox^  ImageDirTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::ComboBox^  DarkFrameComboBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  DarkDirTextBox;
	private: System::Windows::Forms::CheckBox^  SaveDarkCheckBox;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::ComboBox^  FlatFrameComboBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  ExpTimeTextBox;
	private: System::Windows::Forms::Label^  label3;


















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
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->ApplyButton = (gcnew System::Windows::Forms::Button());
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->FrameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->NumFramesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ImageDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FlatFrameComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DarkFrameComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DarkDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveDarkCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40.53156F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42.64706F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.91176F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(486, 355);
			this->tableLayoutPanel1->TabIndex = 1;
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
			this->tableLayoutPanel3->Controls->Add(this->CancelButton, 3, 0);
			this->tableLayoutPanel3->Controls->Add(this->ApplyButton, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->ExecuteButton, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 297);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(480, 55);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(382, 16);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &StackSettingsDialog::CancelButton_Click);
			// 
			// ApplyButton
			// 
			this->ApplyButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ApplyButton->Location = System::Drawing::Point(262, 16);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(75, 23);
			this->ApplyButton->TabIndex = 2;
			this->ApplyButton->Text = L"Apply";
			this->ApplyButton->UseVisualStyleBackColor = true;
			this->ApplyButton->Click += gcnew System::EventHandler(this, &StackSettingsDialog::ApplyButton_Click);
			// 
			// ExecuteButton
			// 
			this->ExecuteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ExecuteButton->Location = System::Drawing::Point(142, 16);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(75, 23);
			this->ExecuteButton->TabIndex = 1;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			this->ExecuteButton->Click += gcnew System::EventHandler(this, &StackSettingsDialog::ExecuteButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(22, 16);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &StackSettingsDialog::OkButton_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				26.45833F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				19.58333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.67793F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox6, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(480, 137);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tableLayoutPanel13);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox6->Location = System::Drawing::Point(224, 3);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(253, 131);
			this->groupBox6->TabIndex = 7;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Frame Parameters";
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->ColumnCount = 3;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				26.05586F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.13351F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20.81063F)));
			this->tableLayoutPanel13->Controls->Add(this->label7, 0, 3);
			this->tableLayoutPanel13->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel13->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel13->Controls->Add(this->FrameTextBox, 1, 1);
			this->tableLayoutPanel13->Controls->Add(this->label6, 0, 2);
			this->tableLayoutPanel13->Controls->Add(this->NumFramesTextBox, 1, 2);
			this->tableLayoutPanel13->Controls->Add(this->ImageDirTextBox, 1, 3);
			this->tableLayoutPanel13->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel13->Controls->Add(this->ExpTimeTextBox, 1, 0);
			this->tableLayoutPanel13->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel13->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 4;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.81203F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.06266F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.06266F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.06266F)));
			this->tableLayoutPanel13->Size = System::Drawing::Size(247, 112);
			this->tableLayoutPanel13->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 91);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Image Dir:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 34);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"x, y, h, w:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(198, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"(pixels)";
			// 
			// FrameTextBox
			// 
			this->FrameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FrameTextBox->Location = System::Drawing::Point(67, 31);
			this->FrameTextBox->Name = L"FrameTextBox";
			this->FrameTextBox->Size = System::Drawing::Size(112, 20);
			this->FrameTextBox->TabIndex = 6;
			this->FrameTextBox->Text = L"1023,1023,1024,1024";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 62);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"# Frames:";
			// 
			// NumFramesTextBox
			// 
			this->NumFramesTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NumFramesTextBox->Location = System::Drawing::Point(67, 59);
			this->NumFramesTextBox->Name = L"NumFramesTextBox";
			this->NumFramesTextBox->Size = System::Drawing::Size(112, 20);
			this->NumFramesTextBox->TabIndex = 8;
			// 
			// ImageDirTextBox
			// 
			this->ImageDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ImageDirTextBox->Location = System::Drawing::Point(67, 87);
			this->ImageDirTextBox->Name = L"ImageDirTextBox";
			this->ImageDirTextBox->Size = System::Drawing::Size(112, 20);
			this->ImageDirTextBox->TabIndex = 9;
			this->ImageDirTextBox->Text = L"Images";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Exposure:";
			// 
			// ExpTimeTextBox
			// 
			this->ExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ExpTimeTextBox->Location = System::Drawing::Point(67, 3);
			this->ExpTimeTextBox->Name = L"ExpTimeTextBox";
			this->ExpTimeTextBox->Size = System::Drawing::Size(113, 20);
			this->ExpTimeTextBox->TabIndex = 12;
			this->ExpTimeTextBox->Text = L"1.000";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(198, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"(secs)";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel7);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(130, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(88, 131);
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
			this->tableLayoutPanel7->Size = System::Drawing::Size(67, 65);
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
			this->Binning3x3Button->CheckedChanged += gcnew System::EventHandler(this, &StackSettingsDialog::Binning3x3Button_CheckedChanged);
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
			this->Binning1x1Button->CheckedChanged += gcnew System::EventHandler(this, &StackSettingsDialog::Binning1x1Button_CheckedChanged);
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
			this->Binning2x2Button->CheckedChanged += gcnew System::EventHandler(this, &StackSettingsDialog::Binning2x2Button_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel6);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(121, 131);
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
			this->TrackingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &StackSettingsDialog::TrackingCCDButton_CheckedChanged);
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
			this->ImagingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &StackSettingsDialog::ImagingCCDButton_CheckedChanged);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				43.93638F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				56.06362F)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox5, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox4, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 146);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(480, 145);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel5);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox5->Location = System::Drawing::Point(3, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(204, 139);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Flat Frame Options";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel5->Controls->Add(this->FlatFrameComboBox, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->tableLayoutPanel11, 0, 1);
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(209, 93);
			this->tableLayoutPanel5->TabIndex = 1;
			// 
			// FlatFrameComboBox
			// 
			this->FlatFrameComboBox->FormattingEnabled = true;
			this->FlatFrameComboBox->Location = System::Drawing::Point(3, 3);
			this->FlatFrameComboBox->Name = L"FlatFrameComboBox";
			this->FlatFrameComboBox->Size = System::Drawing::Size(173, 21);
			this->FlatFrameComboBox->TabIndex = 0;
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 2;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				39.90148F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				60.09852F)));
			this->tableLayoutPanel11->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel11->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel11->Location = System::Drawing::Point(3, 34);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				25)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(203, 25);
			this->tableLayoutPanel11->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 6);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Flat Directory:";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox1->Location = System::Drawing::Point(84, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(95, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Flats";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel9);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(213, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(264, 139);
			this->groupBox4->TabIndex = 5;
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
			this->tableLayoutPanel9->Controls->Add(this->DarkFrameComboBox, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->tableLayoutPanel10, 0, 1);
			this->tableLayoutPanel9->Controls->Add(this->SaveDarkCheckBox, 0, 2);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 3;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.88506F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.17647F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.41176F)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(258, 120);
			this->tableLayoutPanel9->TabIndex = 0;
			// 
			// DarkFrameComboBox
			// 
			this->DarkFrameComboBox->FormattingEnabled = true;
			this->DarkFrameComboBox->Location = System::Drawing::Point(3, 3);
			this->DarkFrameComboBox->Name = L"DarkFrameComboBox";
			this->DarkFrameComboBox->Size = System::Drawing::Size(173, 21);
			this->DarkFrameComboBox->TabIndex = 0;
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 2;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				34.12698F)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				65.87302F)));
			this->tableLayoutPanel10->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel10->Controls->Add(this->DarkDirTextBox, 1, 0);
			this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel10->Location = System::Drawing::Point(3, 38);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 1;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				43)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(252, 43);
			this->tableLayoutPanel10->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dark Directory:";
			// 
			// DarkDirTextBox
			// 
			this->DarkDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DarkDirTextBox->Location = System::Drawing::Point(88, 11);
			this->DarkDirTextBox->Name = L"DarkDirTextBox";
			this->DarkDirTextBox->Size = System::Drawing::Size(95, 20);
			this->DarkDirTextBox->TabIndex = 1;
			this->DarkDirTextBox->Text = L"Darks";
			// 
			// SaveDarkCheckBox
			// 
			this->SaveDarkCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveDarkCheckBox->AutoSize = true;
			this->SaveDarkCheckBox->Location = System::Drawing::Point(63, 93);
			this->SaveDarkCheckBox->Name = L"SaveDarkCheckBox";
			this->SaveDarkCheckBox->Size = System::Drawing::Size(132, 17);
			this->SaveDarkCheckBox->TabIndex = 2;
			this->SaveDarkCheckBox->Text = L"Save Dark Frame Also";
			this->SaveDarkCheckBox->UseVisualStyleBackColor = true;
			this->SaveDarkCheckBox->CheckedChanged += gcnew System::EventHandler(this, &StackSettingsDialog::SaveDarkCheckBox_CheckedChanged);
			// 
			// StackSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(486, 355);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"StackSettingsDialog";
			this->Text = L"StackSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel11->ResumeLayout(false);
			this->tableLayoutPanel11->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void ExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void ApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void SaveDarkCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
public: static void SetDarkFrameOptionComboBox(int index) {
		StackSettingsDialog::FormPtr->DarkFrameComboBox->SelectedIndex = index;
		}
public: static int GetDarkFrameOptionComboBox(void) {
		int index;
		index = StackSettingsDialog::FormPtr->DarkFrameComboBox->SelectedIndex;
		return index;
		}
public: static void SetFlatFrameOptionComboBox(int index) {
		StackSettingsDialog::FormPtr->FlatFrameComboBox->SelectedIndex = index;
		}
public: static int GetFlatFrameOptionComboBox(void) {
		int index;
		index = StackSettingsDialog::FormPtr->FlatFrameComboBox->SelectedIndex;
		return index;
		}
public: static void SetFrameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		StackSettingsDialog::FormPtr->FrameTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFrameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = StackSettingsDialog::FormPtr->FrameTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetImageDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		StackSettingsDialog::FormPtr->ImageDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetImageDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = StackSettingsDialog::FormPtr->ImageDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetNumFramesTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		StackSettingsDialog::FormPtr->NumFramesTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetNumFramesTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = StackSettingsDialog::FormPtr->NumFramesTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		StackSettingsDialog::FormPtr->ExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = StackSettingsDialog::FormPtr->ExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
};
}
