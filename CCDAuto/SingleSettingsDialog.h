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
	/// Summary for SingleSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class SingleSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static SingleSettingsDialog^ FormPtr;
		SingleSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			SingleSettingsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SingleSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			SingleSettingsDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  CancelButton;



	private: System::Windows::Forms::Button^  ExecuteButton;

	private: System::Windows::Forms::Button^  OkButton;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::RadioButton^  ImagingCCDButton;
	private: System::Windows::Forms::RadioButton^  TrackingCCDButton;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  Binning3x3Button;

	private: System::Windows::Forms::RadioButton^  Binning1x1Button;
	private: System::Windows::Forms::RadioButton^  Binning2x2Button;



	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::ComboBox^  DarkFrameOptionComboBox;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;


	private: System::Windows::Forms::CheckBox^  SaveDarkButton;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  ExpTimeTextBox;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  FrameTextBox;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  ObjectNameTextBox;








	private: System::Windows::Forms::Button^  SelectDarkFolderButton;
	private: System::Windows::Forms::TextBox^  DarkDirTextBox;

	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::ComboBox^  FlatFrameOptionComboBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel14;
	private: System::Windows::Forms::Button^  SelectFlatFolderButton;
	private: System::Windows::Forms::TextBox^  FlatDirTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel15;
private: System::Windows::Forms::Button^  SelectImageFolderButton;
private: System::Windows::Forms::TextBox^  ImageDirTextBox;












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
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->FrameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ObjectNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DarkFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SelectDarkFolderButton = (gcnew System::Windows::Forms::Button());
			this->DarkDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveDarkButton = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Binning3x3Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning1x1Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning2x2Button = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->TrackingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->ImagingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FlatFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel14 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SelectFlatFolderButton = (gcnew System::Windows::Forms::Button());
			this->FlatDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel15 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SelectImageFolderButton = (gcnew System::Windows::Forms::Button());
			this->ImageDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->tableLayoutPanel14->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->tableLayoutPanel15->SuspendLayout();
			this->tableLayoutPanel12->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.62952F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.37047F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(503, 317);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->ExecuteButton, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 277);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(497, 37);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(376, 7);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::CancelButton_Click);
			// 
			// ExecuteButton
			// 
			this->ExecuteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ExecuteButton->Location = System::Drawing::Point(210, 7);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(75, 23);
			this->ExecuteButton->TabIndex = 1;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			this->ExecuteButton->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::ExecuteButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(45, 7);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::OkButton_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox4, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel10, 1, 1);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(497, 268);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel9);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 115);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(242, 150);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Frame Parameters";
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 3;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				28.38983F)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.38983F)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				17.79661F)));
			this->tableLayoutPanel9->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel9->Controls->Add(this->ExpTimeTextBox, 1, 0);
			this->tableLayoutPanel9->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel9->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel9->Controls->Add(this->FrameTextBox, 1, 1);
			this->tableLayoutPanel9->Controls->Add(this->label6, 0, 2);
			this->tableLayoutPanel9->Controls->Add(this->ObjectNameTextBox, 1, 2);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 3;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(236, 131);
			this->tableLayoutPanel9->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Exposure:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(196, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"secs";
			// 
			// ExpTimeTextBox
			// 
			this->ExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ExpTimeTextBox->Location = System::Drawing::Point(70, 11);
			this->ExpTimeTextBox->Name = L"ExpTimeTextBox";
			this->ExpTimeTextBox->Size = System::Drawing::Size(113, 20);
			this->ExpTimeTextBox->TabIndex = 3;
			this->ExpTimeTextBox->Text = L"1.000";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"x, y, h, w:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(196, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"pixels";
			// 
			// FrameTextBox
			// 
			this->FrameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FrameTextBox->Location = System::Drawing::Point(70, 54);
			this->FrameTextBox->Name = L"FrameTextBox";
			this->FrameTextBox->Size = System::Drawing::Size(113, 20);
			this->FrameTextBox->TabIndex = 6;
			this->FrameTextBox->Text = L"0,0,1024,1024";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 102);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(60, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Obj. Name:";
			// 
			// ObjectNameTextBox
			// 
			this->ObjectNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectNameTextBox->Location = System::Drawing::Point(70, 98);
			this->ObjectNameTextBox->Name = L"ObjectNameTextBox";
			this->ObjectNameTextBox->Size = System::Drawing::Size(113, 20);
			this->ObjectNameTextBox->TabIndex = 8;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel7);
			this->groupBox3->Location = System::Drawing::Point(251, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(243, 106);
			this->groupBox3->TabIndex = 1;
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
			this->tableLayoutPanel7->Controls->Add(this->tableLayoutPanel8, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->SaveDarkButton, 0, 2);
			this->tableLayoutPanel7->Location = System::Drawing::Point(0, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 32.32323F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(237, 99);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// DarkFrameOptionComboBox
			// 
			this->DarkFrameOptionComboBox->FormattingEnabled = true;
			this->DarkFrameOptionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Automatic dark frame", L"Force new dark frame", 
				L"Use dark frame from file", L"Don\'t use dark frame"});
			this->DarkFrameOptionComboBox->Location = System::Drawing::Point(3, 3);
			this->DarkFrameOptionComboBox->Name = L"DarkFrameOptionComboBox";
			this->DarkFrameOptionComboBox->Size = System::Drawing::Size(121, 21);
			this->DarkFrameOptionComboBox->TabIndex = 0;
			this->DarkFrameOptionComboBox->Tag = L"";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 2;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				36.79654F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				122)));
			this->tableLayoutPanel8->Controls->Add(this->SelectDarkFolderButton, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->DarkDirTextBox, 1, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 35);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(231, 27);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// SelectDarkFolderButton
			// 
			this->SelectDarkFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SelectDarkFolderButton->Location = System::Drawing::Point(3, 3);
			this->SelectDarkFolderButton->Name = L"SelectDarkFolderButton";
			this->SelectDarkFolderButton->Size = System::Drawing::Size(103, 21);
			this->SelectDarkFolderButton->TabIndex = 0;
			this->SelectDarkFolderButton->Text = L"Select Dark Folder";
			this->SelectDarkFolderButton->UseVisualStyleBackColor = true;
			this->SelectDarkFolderButton->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::SelectDarkFolderButton_Click);
			// 
			// DarkDirTextBox
			// 
			this->DarkDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DarkDirTextBox->Location = System::Drawing::Point(112, 3);
			this->DarkDirTextBox->Name = L"DarkDirTextBox";
			this->DarkDirTextBox->Size = System::Drawing::Size(116, 20);
			this->DarkDirTextBox->TabIndex = 1;
			// 
			// SaveDarkButton
			// 
			this->SaveDarkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveDarkButton->AutoSize = true;
			this->SaveDarkButton->Location = System::Drawing::Point(52, 73);
			this->SaveDarkButton->Name = L"SaveDarkButton";
			this->SaveDarkButton->Size = System::Drawing::Size(132, 17);
			this->SaveDarkButton->TabIndex = 2;
			this->SaveDarkButton->Text = L"Save Dark Frame Also";
			this->SaveDarkButton->UseVisualStyleBackColor = true;
			this->SaveDarkButton->CheckedChanged += gcnew System::EventHandler(this, &SingleSettingsDialog::SaveDarkButton_CheckedChanged);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 106)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(242, 106);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel6);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(124, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(115, 100);
			this->groupBox2->TabIndex = 1;
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
			this->tableLayoutPanel6->Size = System::Drawing::Size(118, 78);
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
			this->Binning3x3Button->Text = L"3x3";
			this->Binning3x3Button->UseVisualStyleBackColor = true;
			this->Binning3x3Button->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::BinningButton_Clicked);
			// 
			// Binning1x1Button
			// 
			this->Binning1x1Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning1x1Button->AutoSize = true;
			this->Binning1x1Button->Location = System::Drawing::Point(3, 4);
			this->Binning1x1Button->Name = L"Binning1x1Button";
			this->Binning1x1Button->Size = System::Drawing::Size(42, 17);
			this->Binning1x1Button->TabIndex = 1;
			this->Binning1x1Button->Text = L"1x1";
			this->Binning1x1Button->UseVisualStyleBackColor = true;
			this->Binning1x1Button->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::BinningButton_Clicked);
			// 
			// Binning2x2Button
			// 
			this->Binning2x2Button->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Binning2x2Button->AutoSize = true;
			this->Binning2x2Button->Checked = true;
			this->Binning2x2Button->Location = System::Drawing::Point(3, 30);
			this->Binning2x2Button->Name = L"Binning2x2Button";
			this->Binning2x2Button->Size = System::Drawing::Size(42, 17);
			this->Binning2x2Button->TabIndex = 2;
			this->Binning2x2Button->TabStop = true;
			this->Binning2x2Button->Text = L"2x2";
			this->Binning2x2Button->UseVisualStyleBackColor = true;
			this->Binning2x2Button->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::BinningButton_Clicked);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(115, 100);
			this->groupBox1->TabIndex = 0;
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(109, 49);
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
			this->TrackingCCDButton->Text = L"Tracking CCD";
			this->TrackingCCDButton->UseVisualStyleBackColor = true;
			this->TrackingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &SingleSettingsDialog::TrackingCCDButton_CheckedChanged);
			// 
			// ImagingCCDButton
			// 
			this->ImagingCCDButton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ImagingCCDButton->AutoSize = true;
			this->ImagingCCDButton->Checked = true;
			this->ImagingCCDButton->Location = System::Drawing::Point(3, 3);
			this->ImagingCCDButton->Name = L"ImagingCCDButton";
			this->ImagingCCDButton->Size = System::Drawing::Size(87, 17);
			this->ImagingCCDButton->TabIndex = 0;
			this->ImagingCCDButton->TabStop = true;
			this->ImagingCCDButton->Text = L"Imaging CCD";
			this->ImagingCCDButton->UseVisualStyleBackColor = true;
			this->ImagingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &SingleSettingsDialog::ImagingCCDButton_CheckedChanged);
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 1;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel10->Controls->Add(this->groupBox5, 0, 0);
			this->tableLayoutPanel10->Controls->Add(this->groupBox7, 0, 1);
			this->tableLayoutPanel10->Location = System::Drawing::Point(251, 115);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 2;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 61.33333F)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 38.66667F)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(243, 150);
			this->tableLayoutPanel10->TabIndex = 3;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel11);
			this->groupBox5->Location = System::Drawing::Point(3, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(237, 85);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Flat Frame Options";
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 1;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel11->Controls->Add(this->FlatFrameOptionComboBox, 0, 0);
			this->tableLayoutPanel11->Controls->Add(this->tableLayoutPanel14, 0, 1);
			this->tableLayoutPanel11->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 2;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 37.87879F)));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 62.12121F)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(237, 66);
			this->tableLayoutPanel11->TabIndex = 1;
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
			this->FlatFrameOptionComboBox->Tag = L"";
			// 
			// tableLayoutPanel14
			// 
			this->tableLayoutPanel14->ColumnCount = 2;
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				47.18615F)));
			this->tableLayoutPanel14->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				52.81385F)));
			this->tableLayoutPanel14->Controls->Add(this->SelectFlatFolderButton, 0, 0);
			this->tableLayoutPanel14->Controls->Add(this->FlatDirTextBox, 1, 0);
			this->tableLayoutPanel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel14->Location = System::Drawing::Point(3, 28);
			this->tableLayoutPanel14->Name = L"tableLayoutPanel14";
			this->tableLayoutPanel14->RowCount = 1;
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel14->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				35)));
			this->tableLayoutPanel14->Size = System::Drawing::Size(231, 35);
			this->tableLayoutPanel14->TabIndex = 1;
			// 
			// SelectFlatFolderButton
			// 
			this->SelectFlatFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SelectFlatFolderButton->Location = System::Drawing::Point(3, 7);
			this->SelectFlatFolderButton->Name = L"SelectFlatFolderButton";
			this->SelectFlatFolderButton->Size = System::Drawing::Size(102, 21);
			this->SelectFlatFolderButton->TabIndex = 2;
			this->SelectFlatFolderButton->Text = L"Select Flat Folder";
			this->SelectFlatFolderButton->UseVisualStyleBackColor = true;
			this->SelectFlatFolderButton->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::SelectFlatFolderButton_Click);
			// 
			// FlatDirTextBox
			// 
			this->FlatDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FlatDirTextBox->Location = System::Drawing::Point(112, 7);
			this->FlatDirTextBox->Name = L"FlatDirTextBox";
			this->FlatDirTextBox->Size = System::Drawing::Size(116, 20);
			this->FlatDirTextBox->TabIndex = 1;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->tableLayoutPanel15);
			this->groupBox7->Location = System::Drawing::Point(3, 94);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(237, 47);
			this->groupBox7->TabIndex = 5;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Image Folder";
			// 
			// tableLayoutPanel15
			// 
			this->tableLayoutPanel15->ColumnCount = 2;
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				36.79654F)));
			this->tableLayoutPanel15->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				114)));
			this->tableLayoutPanel15->Controls->Add(this->SelectImageFolderButton, 0, 0);
			this->tableLayoutPanel15->Controls->Add(this->ImageDirTextBox, 1, 0);
			this->tableLayoutPanel15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel15->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel15->Name = L"tableLayoutPanel15";
			this->tableLayoutPanel15->RowCount = 1;
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel15->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				28)));
			this->tableLayoutPanel15->Size = System::Drawing::Size(231, 28);
			this->tableLayoutPanel15->TabIndex = 2;
			// 
			// SelectImageFolderButton
			// 
			this->SelectImageFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SelectImageFolderButton->Location = System::Drawing::Point(3, 3);
			this->SelectImageFolderButton->Name = L"SelectImageFolderButton";
			this->SelectImageFolderButton->Size = System::Drawing::Size(110, 21);
			this->SelectImageFolderButton->TabIndex = 0;
			this->SelectImageFolderButton->Text = L"Select Image Folder";
			this->SelectImageFolderButton->UseVisualStyleBackColor = true;
			this->SelectImageFolderButton->Click += gcnew System::EventHandler(this, &SingleSettingsDialog::SelectImageFolderButton_Click);
			// 
			// ImageDirTextBox
			// 
			this->ImageDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ImageDirTextBox->Location = System::Drawing::Point(120, 4);
			this->ImageDirTextBox->Name = L"ImageDirTextBox";
			this->ImageDirTextBox->Size = System::Drawing::Size(108, 20);
			this->ImageDirTextBox->TabIndex = 1;
			// 
			// groupBox6
			// 
			this->groupBox6->Location = System::Drawing::Point(0, 0);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(200, 100);
			this->groupBox6->TabIndex = 0;
			this->groupBox6->TabStop = false;
			// 
			// tableLayoutPanel12
			// 
			this->tableLayoutPanel12->ColumnCount = 1;
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel12->Controls->Add(this->comboBox1, 0, 0);
			this->tableLayoutPanel12->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
			this->tableLayoutPanel12->RowCount = 2;
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel12->Size = System::Drawing::Size(200, 100);
			this->tableLayoutPanel12->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Don\'t do flat frame", L"Reuse current flat frame", 
				L"Use flat frame from file"});
			this->comboBox1->Location = System::Drawing::Point(3, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Tag = L"";
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->ColumnCount = 2;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				47.18615F)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				52.81385F)));
			this->tableLayoutPanel13->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel13->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel13->Location = System::Drawing::Point(3, 30);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 1;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				26)));
			this->tableLayoutPanel13->Size = System::Drawing::Size(194, 67);
			this->tableLayoutPanel13->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(3, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 21);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Select Flat Folder";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox1->Location = System::Drawing::Point(94, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(97, 20);
			this->textBox1->TabIndex = 1;
			// 
			// SingleSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(503, 317);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"SingleSettingsDialog";
			this->Text = L"SingleSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel10->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel11->ResumeLayout(false);
			this->tableLayoutPanel14->ResumeLayout(false);
			this->tableLayoutPanel14->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->tableLayoutPanel15->ResumeLayout(false);
			this->tableLayoutPanel15->PerformLayout();
			this->tableLayoutPanel12->ResumeLayout(false);
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
public:  int GetSingleSettings(void) {

			 char buffer[80];

			 /* exposure time */

			 SingleSettingsDialog::FormPtr->GetExpTimeTextBox(buffer);
			 sscanf_s(buffer, "%f", &singleSettings.exposureTime);

			 /* Which ccd */

		     if (ccd->make == SBIG_MAKE)
				 singleSettings.whichCCD = SingleSettingsDialog::GetWhichCCDButton();
			 
			 /* Binning */

			 singleSettings.binning = SingleSettingsDialog::FormPtr->GetWhichBinningButton();

			 /* ccd Frame size */

			 SingleSettingsDialog::FormPtr->GetFrameTextBox(buffer);
			 sscanf_s(buffer, "%d, %d, %d, %d", &singleSettings.x,
				 &singleSettings.y, &singleSettings.h, &singleSettings.w);

			 /* Get dark frame option */

			 singleSettings.darkOption = SingleSettingsDialog::FormPtr->GetDarkFrameOptionComboBox();
			 SingleSettingsDialog::FormPtr->GetDarkDirTextBox(singleSettings.DarkDir);

			 /* Get flat frame option */

			 singleSettings.flatOption = SingleSettingsDialog::FormPtr->GetFlatFrameOptionComboBox();
			 SingleSettingsDialog::FormPtr->GetFlatDirTextBox(singleSettings.FlatDir);

			 /* Object Name */

			 SingleSettingsDialog::FormPtr->GetObjectNameTextBox(singleSettings.ObjectName);

			 /* Image Directory */

			 SingleSettingsDialog::FormPtr->GetImageDirTextBox(singleSettings.ImageDir);

			 return true;
		 }
public:  int SetSingleSettings(void) {

			 char buffer[80];

			 /* exposure time */

			 sprintf_s(buffer, sizeof(buffer), "%-7.2f", singleSettings.exposureTime);
			 SingleSettingsDialog::FormPtr->SetExpTimeTextBox(buffer);

			    /* Which ccd */

		     if (ccd->make != SBIG_MAKE) {
				 SingleSettingsDialog::HideCCDTrackingButton();
				 SingleSettingsDialog::SetWhichCCDButton(0);
			 } else {
				 SingleSettingsDialog::ShowCCDTrackingButton();
				 SingleSettingsDialog::SetWhichCCDButton(singleSettings.whichCCD);
			 }
			 
				/* Binning */

			 if (singleSettings.whichCCD == 0)
				 SingleSettingsDialog::FormPtr->SetWhichBinningButton(singleSettings.binning);

				/* ccd Frame size */

			 if (singleSettings.w <= 0) {
				 GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
					 &singleSettings.w, &singleSettings.h, &singleSettings.binning);
			 }
			 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", singleSettings.x,
				 singleSettings.y, singleSettings.h, singleSettings.w);
			 SingleSettingsDialog::FormPtr->SetFrameTextBox(buffer);

				/* Set dark frame option */

			 SingleSettingsDialog::FormPtr->SetDarkFrameOptionComboBox(singleSettings.darkOption);
			 SingleSettingsDialog::FormPtr->SetDarkDirTextBox(singleSettings.DarkDir);

				/* Set flat frame option */

			 SingleSettingsDialog::FormPtr->SetFlatFrameOptionComboBox(singleSettings.flatOption);
			 SingleSettingsDialog::FormPtr->SetFlatDirTextBox(singleSettings.FlatDir);

				/* Object Name */

			 SingleSettingsDialog::FormPtr->SetObjectNameTextBox(singleSettings.ObjectName);

				/* Image Directory */

			 SingleSettingsDialog::FormPtr->SetImageDirTextBox(singleSettings.ImageDir);

			 return true;
		 }
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 SingleSettingsDialog::FormPtr->Hide();
			 GetSingleSettings();
			 return;
		 }
private: System::Void ExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 SingleSettingsDialog::FormPtr->Hide();
			 GetSingleSettings();
			 RunMainIteration(0.5);
			 ExposeSingleFrame();
			 return;
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Restore old settings */
			 
			 memcpy(&singleSettings, &singleSettings_Save, sizeof(singleSettings));
			 SingleSettingsDialog::Hide();
			 return;
		 }
private: System::Void ImagingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 if (SingleSettingsDialog::FormPtr->ImagingCCDButton->Checked) {
				 SingleSettingsDialog::FormPtr->Show3x3Button();
				 singleSettings.whichCCD = 0;
			 } else {
				 singleSettings.whichCCD = 1;
				 SingleSettingsDialog::FormPtr->Hide3x3Button();
			 }
			 GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
								&singleSettings.w, &singleSettings.h, &singleSettings.binning);
			 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", singleSettings.x, singleSettings.y,
					   singleSettings.h, singleSettings.w);
			 SingleSettingsDialog::FormPtr->SetFrameTextBox(buffer);
		 }
private: System::Void TrackingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void BinningButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[40];
			 if (SingleSettingsDialog::FormPtr->Binning1x1Button->Checked) {
				 singleSettings.binning = 0;
				 GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
					 &singleSettings.w, &singleSettings.h, &singleSettings.binning);
				 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", singleSettings.x, singleSettings.y,
					 singleSettings.h, singleSettings.w);
				 SingleSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 } else if (SingleSettingsDialog::FormPtr->Binning2x2Button->Checked) {
				 singleSettings.binning = 1;
				 GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
					 &singleSettings.w, &singleSettings.h, &singleSettings.binning);
				 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", singleSettings.x, singleSettings.y,
					 singleSettings.h, singleSettings.w);
				 SingleSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 } else if (SingleSettingsDialog::FormPtr->Binning3x3Button->Checked) {
				 singleSettings.binning = 2;
				 GetCCDFrameSettings(ccd, &singleSettings.x, &singleSettings.y,
					 &singleSettings.w, &singleSettings.h, &singleSettings.binning);
				 sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", singleSettings.x, singleSettings.y,
					 singleSettings.h, singleSettings.w);
				 SingleSettingsDialog::FormPtr->SetFrameTextBox(buffer);
			 }
		 }
private: System::Void SaveDarkButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
public:  void ShowTheDialog(void) {
			 SingleSettingsDialog::FormPtr->ShowDialog();
		 }
public:  void HideCCDTrackingButton(void) {
			 SingleSettingsDialog::FormPtr->TrackingCCDButton->Hide();
		 }
public:  void ShowCCDTrackingButton(void) {
			 SingleSettingsDialog::FormPtr->TrackingCCDButton->Show();
		 }
public: static void SetExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SingleSettingsDialog::FormPtr->ExpTimeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SingleSettingsDialog::FormPtr->ExpTimeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFrameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SingleSettingsDialog::FormPtr->FrameTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFrameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SingleSettingsDialog::FormPtr->FrameTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDarkDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SingleSettingsDialog::FormPtr->DarkDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDarkDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SingleSettingsDialog::FormPtr->DarkDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetImageDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SingleSettingsDialog::FormPtr->ImageDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetImageDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SingleSettingsDialog::FormPtr->ImageDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetObjectNameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SingleSettingsDialog::FormPtr->ObjectNameTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetObjectNameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SingleSettingsDialog::FormPtr->ObjectNameTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFlatDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		SingleSettingsDialog::FormPtr->FlatDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFlatDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = SingleSettingsDialog::FormPtr->FlatDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDarkFrameOptionComboBox(int index) {
		SingleSettingsDialog::FormPtr->DarkFrameOptionComboBox->SelectedIndex = index-1;
		}
public: static int GetDarkFrameOptionComboBox(void) {
		int index;
		index = SingleSettingsDialog::FormPtr->DarkFrameOptionComboBox->SelectedIndex+1;
		return index;
		}
public: static void SetFlatFrameOptionComboBox(int index) {
		SingleSettingsDialog::FormPtr->FlatFrameOptionComboBox->SelectedIndex = index-1;
		}
public: static int GetFlatFrameOptionComboBox(void) {
		int index;
		index = SingleSettingsDialog::FormPtr->FlatFrameOptionComboBox->SelectedIndex+1;
		return index;
		}
public: static void SetWhichCCDButton(int which) {
			if (which == 0) {
				SingleSettingsDialog::FormPtr->ImagingCCDButton->Checked = true;
				SingleSettingsDialog::FormPtr->TrackingCCDButton->Checked = false;
			} else {
				SingleSettingsDialog::FormPtr->ImagingCCDButton->Checked = false;
				SingleSettingsDialog::FormPtr->TrackingCCDButton->Checked = true;
			}
		}
public: static int GetWhichCCDButton(void) {
			if (SingleSettingsDialog::FormPtr->ImagingCCDButton->Checked) {
				return 0;
			} else {
				return 1;
			}
		}
public: static void SetWhichBinningButton(int binning) {
			if (binning == 0) {
				SingleSettingsDialog::FormPtr->Binning1x1Button->Checked = true;
				SingleSettingsDialog::FormPtr->Binning2x2Button->Checked = false;
				SingleSettingsDialog::FormPtr->Binning3x3Button->Checked = false;
			} else if (binning == 1) {
				SingleSettingsDialog::FormPtr->Binning1x1Button->Checked = false;
				SingleSettingsDialog::FormPtr->Binning2x2Button->Checked = true;
				SingleSettingsDialog::FormPtr->Binning3x3Button->Checked = false;
			} else {
				SingleSettingsDialog::FormPtr->Binning1x1Button->Checked = false;
				SingleSettingsDialog::FormPtr->Binning2x2Button->Checked = false;
				SingleSettingsDialog::FormPtr->Binning3x3Button->Checked = true;
			}
		}
public: static int GetWhichBinningButton(void) {

			if (SingleSettingsDialog::FormPtr->Binning1x1Button->Checked) {
				return 0;
			} else if (SingleSettingsDialog::FormPtr->Binning2x2Button->Checked) {
				return 1;
			} else {
				return 2;
			}
		}
public: static void Hide3x3Button(void) {
			SingleSettingsDialog::FormPtr->Binning3x3Button->Hide();
		}
public: static void Show3x3Button(void) {
			SingleSettingsDialog::FormPtr->Binning3x3Button->Show();
		}
private: System::Void SelectDarkFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Select Dark Frame Folder", path);
			 strcpy_s(singleSettings.DarkDir, sizeof(singleSettings.DarkDir), path);
			 this->FormPtr->SetDarkDirTextBox(singleSettings.DarkDir);
			 return;

		 }
private: System::Void SelectFlatFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Select Flat Frame Folder", path);
			 strcpy_s(singleSettings.FlatDir, sizeof(singleSettings.FlatDir), path);
			 this->FormPtr->SetFlatDirTextBox(singleSettings.FlatDir);
			 return;
		 }
private: System::Void SelectImageFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Select Image Folder", path);
			 strcpy_s(singleSettings.ImageDir, sizeof(singleSettings.ImageDir), path);
			 this->FormPtr->SetImageDirTextBox(singleSettings.ImageDir);
			 return;
		 }
};
}
