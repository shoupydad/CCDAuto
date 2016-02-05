#pragma once

#include "doRoutines.h"

namespace CCDAuto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BiasFrameSettingDialog
	/// </summary>
	public ref class BiasFrameSettingDialog : public System::Windows::Forms::Form
	{
	public:
		static BiasFrameSettingDialog ^FormPtr;
		BiasFrameSettingDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			FormPtr = this;
			BiasFrameSettingsDialogExists = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BiasFrameSettingDialog()
		{
			if (components)
			{
				delete components;
			}
			FormPtr = nullptr;
			BiasFrameSettingsDialogExists = false;
		}
	private: System::Windows::Forms::Label^  label4;
	protected:
	private: System::Windows::Forms::TextBox^  NumFramesTextBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  FrameTextBox;
	private: System::Windows::Forms::TextBox^  BiasDirTextBox;

	private: System::Windows::Forms::Button^  SelectBiasFolderButton;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::RadioButton^  MeanButton;
	private: System::Windows::Forms::RadioButton^  MedianButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  ExpTimeTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::RadioButton^  Binning3x3Button;
	private: System::Windows::Forms::RadioButton^  Binning1x1Button;
	private: System::Windows::Forms::RadioButton^  Binning2x2Button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::CheckBox^  SaveEachBiasButton;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  TrackingCCDButton;
	private: System::Windows::Forms::RadioButton^  ImagingCCDButton;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  ExecuteButton;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->NumFramesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->FrameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BiasDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SelectBiasFolderButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->MeanButton = (gcnew System::Windows::Forms::RadioButton());
			this->MedianButton = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ExpTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Binning3x3Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning1x1Button = (gcnew System::Windows::Forms::RadioButton());
			this->Binning2x2Button = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SaveEachBiasButton = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->TrackingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->ImagingCCDButton = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"# of Frames:";
			// 
			// NumFramesTextBox
			// 
			this->NumFramesTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NumFramesTextBox->Location = System::Drawing::Point(81, 35);
			this->NumFramesTextBox->Name = L"NumFramesTextBox";
			this->NumFramesTextBox->Size = System::Drawing::Size(95, 20);
			this->NumFramesTextBox->TabIndex = 7;
			this->NumFramesTextBox->Text = L"1.000";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(202, 69);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"(pixels)";
			// 
			// FrameTextBox
			// 
			this->FrameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FrameTextBox->Location = System::Drawing::Point(81, 65);
			this->FrameTextBox->Name = L"FrameTextBox";
			this->FrameTextBox->Size = System::Drawing::Size(113, 20);
			this->FrameTextBox->TabIndex = 11;
			this->FrameTextBox->Text = L"1023,1023,1024,1024";
			// 
			// BiasDirTextBox
			// 
			this->BiasDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->BiasDirTextBox->Location = System::Drawing::Point(365, 5);
			this->BiasDirTextBox->Name = L"BiasDirTextBox";
			this->BiasDirTextBox->Size = System::Drawing::Size(118, 20);
			this->BiasDirTextBox->TabIndex = 13;
			// 
			// SelectBiasFolderButton
			// 
			this->SelectBiasFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SelectBiasFolderButton->Location = System::Drawing::Point(252, 4);
			this->SelectBiasFolderButton->Name = L"SelectBiasFolderButton";
			this->SelectBiasFolderButton->Size = System::Drawing::Size(103, 21);
			this->SelectBiasFolderButton->TabIndex = 15;
			this->SelectBiasFolderButton->Text = L"Select Bias Folder";
			this->SelectBiasFolderButton->UseVisualStyleBackColor = true;
			this->SelectBiasFolderButton->Click += gcnew System::EventHandler(this, &BiasFrameSettingDialog::SelectBiasFolderButton_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel4);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(343, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(165, 84);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Combine Method";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel4->Controls->Add(this->MeanButton, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->MedianButton, 0, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(6, 19);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(109, 51);
			this->tableLayoutPanel4->TabIndex = 0;
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
			this->MeanButton->CheckedChanged += gcnew System::EventHandler(this, &BiasFrameSettingDialog::MeanButton_CheckedChanged);
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
			this->MedianButton->CheckedChanged += gcnew System::EventHandler(this, &BiasFrameSettingDialog::MedianButton_CheckedChanged);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Exposure:";
			// 
			// ExpTimeTextBox
			// 
			this->ExpTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ExpTimeTextBox->Location = System::Drawing::Point(81, 5);
			this->ExpTimeTextBox->Name = L"ExpTimeTextBox";
			this->ExpTimeTextBox->Size = System::Drawing::Size(113, 20);
			this->ExpTimeTextBox->TabIndex = 4;
			this->ExpTimeTextBox->Text = L"1.000";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(202, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"(secs)";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel6);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(173, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(164, 84);
			this->groupBox2->TabIndex = 2;
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
			this->tableLayoutPanel6->Size = System::Drawing::Size(118, 65);
			this->tableLayoutPanel6->TabIndex = 0;
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
			this->Binning3x3Button->CheckedChanged += gcnew System::EventHandler(this, &BiasFrameSettingDialog::BinningButton_CheckedChanged);
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
			this->Binning1x1Button->CheckedChanged += gcnew System::EventHandler(this, &BiasFrameSettingDialog::BinningButton_CheckedChanged);
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
			this->Binning2x2Button->CheckedChanged += gcnew System::EventHandler(this, &BiasFrameSettingDialog::BinningButton_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"x, y, h, w:";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 5;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15.64356F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				24.15842F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				9.306931F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				23.36634F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				28.11881F)));
			this->tableLayoutPanel7->Controls->Add(this->label1, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->ExpTimeTextBox, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->NumFramesTextBox, 1, 1);
			this->tableLayoutPanel7->Controls->Add(this->label5, 2, 2);
			this->tableLayoutPanel7->Controls->Add(this->FrameTextBox, 1, 2);
			this->tableLayoutPanel7->Controls->Add(this->BiasDirTextBox, 4, 0);
			this->tableLayoutPanel7->Controls->Add(this->SaveEachBiasButton, 4, 1);
			this->tableLayoutPanel7->Controls->Add(this->SelectBiasFolderButton, 3, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(505, 91);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// SaveEachBiasButton
			// 
			this->SaveEachBiasButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveEachBiasButton->AutoSize = true;
			this->SaveEachBiasButton->Location = System::Drawing::Point(365, 36);
			this->SaveEachBiasButton->Name = L"SaveEachBiasButton";
			this->SaveEachBiasButton->Size = System::Drawing::Size(137, 17);
			this->SaveEachBiasButton->TabIndex = 14;
			this->SaveEachBiasButton->Text = L"Save Each Dark Frame";
			this->SaveEachBiasButton->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel7);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 99);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(511, 110);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Frame Parameters";
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
			this->ImagingCCDButton->CheckedChanged += gcnew System::EventHandler(this, &BiasFrameSettingDialog::ImagingCCDButton_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(164, 84);
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(109, 51);
			this->tableLayoutPanel5->TabIndex = 0;
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
			this->tableLayoutPanel2->Controls->Add(this->groupBox3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 90)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(511, 90);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// ExecuteButton
			// 
			this->ExecuteButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ExecuteButton->Location = System::Drawing::Point(217, 12);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(75, 23);
			this->ExecuteButton->TabIndex = 1;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			this->ExecuteButton->Click += gcnew System::EventHandler(this, &BiasFrameSettingDialog::ExecuteButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(47, 12);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &BiasFrameSettingDialog::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(388, 12);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &BiasFrameSettingDialog::CancelButton_Click);
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
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 215);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 48)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(511, 48);
			this->tableLayoutPanel3->TabIndex = 3;
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
			this->tableLayoutPanel1->Controls->Add(this->groupBox4, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.09023F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43.60902F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 19.92481F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(517, 266);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// BiasFrameSettingDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(517, 266);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"BiasFrameSettingDialog";
			this->Text = L"BiasFrameSettingDialog";
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

		BiasFrameSettingDialog::FormPtr->Hide();
		GetBiasFrameSettings();
		return;

	}


	private: System::Void ExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {

		BiasFrameSettingDialog::FormPtr->Hide();
		GetBiasFrameSettings();
		usleep(500000);

		DoBiasFrameSeries();
		return;
	}


	private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

		/* Restore old settings */

		memcpy(&biasFrameSettings, &biasFrameSettings_Save, sizeof(biasFrameSettings));
		BiasFrameSettingDialog::Hide();
		return;
	}

	private: System::Void GetBiasFrameSettings() {

	}


	private: System::Void ImagingCCDButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		char buffer[80];

		if (BiasFrameSettingDialog::FormPtr->ImagingCCDButton->Checked) {
			BiasFrameSettingDialog::FormPtr->Show3x3Button();
			biasFrameSettings.whichCCD = 0;
		} else {
			biasFrameSettings.whichCCD = 1;
			BiasFrameSettingDialog::FormPtr->Hide3x3Button();
		}
		GetCCDFrameSettings(ccd, &biasFrameSettings.x, &biasFrameSettings.y,
			&biasFrameSettings.w, &biasFrameSettings.h, &biasFrameSettings.binning);
		sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", biasFrameSettings.x,
			biasFrameSettings.y, biasFrameSettings.h, biasFrameSettings.w);
		BiasFrameSettingDialog::FormPtr->SetFrameTextBox(buffer);
	}


	public: static void Hide3x3Button(void) {
		BiasFrameSettingDialog::FormPtr->Binning3x3Button->Hide();
	}


	public: static void Show3x3Button(void) {
		BiasFrameSettingDialog::FormPtr->Binning3x3Button->Show();
	}



	private: System::Void BinningButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		char buffer[40];
		if (BiasFrameSettingDialog::FormPtr->Binning1x1Button->Checked) {
			darkFrameSettings.binning = 0;
			GetCCDFrameSettings(ccd, &biasFrameSettings.x, &biasFrameSettings.y,
				&darkFrameSettings.w, &biasFrameSettings.h, &biasFrameSettings.binning);
			sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", biasFrameSettings.x,
				biasFrameSettings.y, biasFrameSettings.h, biasFrameSettings.w);
			BiasFrameSettingDialog::FormPtr->SetFrameTextBox(buffer);

		} else if (BiasFrameSettingDialog::FormPtr->Binning2x2Button->Checked) {
			biasFrameSettings.binning = 1;
			GetCCDFrameSettings(ccd, &biasFrameSettings.x, &biasFrameSettings.y,
				&biasFrameSettings.w, &biasFrameSettings.h, &biasFrameSettings.binning);
			sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", biasFrameSettings.x,
				biasFrameSettings.y, biasFrameSettings.h, biasFrameSettings.w);
			BiasFrameSettingDialog::FormPtr->SetFrameTextBox(buffer);

		} else if (BiasFrameSettingDialog::FormPtr->Binning3x3Button->Checked) {
			biasFrameSettings.binning = 2;
			GetCCDFrameSettings(ccd, &biasFrameSettings.x, &biasFrameSettings.y,
				&biasFrameSettings.w, &biasFrameSettings.h, &biasFrameSettings.binning);
			sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", biasFrameSettings.x,
				biasFrameSettings.y, biasFrameSettings.h, biasFrameSettings.w);
			BiasFrameSettingDialog::FormPtr->SetFrameTextBox(buffer);
		}
	}


	public: static void SetFrameTextBox(char *text) {

		String ^buffer;
		buffer = gcnew String(text);
		BiasFrameSettingDialog::FormPtr->FrameTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetFrameTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = BiasFrameSettingDialog::FormPtr->FrameTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	private: System::Void MedianButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (BiasFrameSettingDialog::FormPtr->MedianButton->Checked) {
			biasFrameSettings.combineMethod = 1;
		} else {
			biasFrameSettings.combineMethod = 2;
		}
		return;
	}


	private: System::Void MeanButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (BiasFrameSettingDialog::FormPtr->MeanButton->Checked) {
			biasFrameSettings.combineMethod = 2;
		} else {
			biasFrameSettings.combineMethod = 1;
		}
		return;
	}


	public: static void SetWhichBinningButton(int binning) {
		if (binning == 0) {
			BiasFrameSettingDialog::FormPtr->Binning1x1Button->Checked = true;
			BiasFrameSettingDialog::FormPtr->Binning2x2Button->Checked = false;
			BiasFrameSettingDialog::FormPtr->Binning3x3Button->Checked = false;
		} else if (binning == 1) {
			BiasFrameSettingDialog::FormPtr->Binning1x1Button->Checked = false;
			BiasFrameSettingDialog::FormPtr->Binning2x2Button->Checked = true;
			BiasFrameSettingDialog::FormPtr->Binning3x3Button->Checked = false;
		} else {
			BiasFrameSettingDialog::FormPtr->Binning1x1Button->Checked = false;
			BiasFrameSettingDialog::FormPtr->Binning2x2Button->Checked = false;
			BiasFrameSettingDialog::FormPtr->Binning3x3Button->Checked = true;
		}
	}


	public:  void ShowTheDialog(void) {

		BiasFrameSettingDialog::FormPtr->ShowDialog();
	}


	public: static void SetNumFramesTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		BiasFrameSettingDialog::FormPtr->NumFramesTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetNumFramesTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = BiasFrameSettingDialog::FormPtr->NumFramesTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetExpTimeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		BiasFrameSettingDialog::FormPtr->ExpTimeTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetExpTimeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = BiasFrameSettingDialog::FormPtr->ExpTimeTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetBiasDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		BiasFrameSettingDialog::FormPtr->BiasDirTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetBiasDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = BiasFrameSettingDialog::FormPtr->BiasDirTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public:  int SetDarkFrameSettings(void) {

		char buffer[80];

		/* exposure time */

		sprintf_s(buffer, sizeof(buffer), "%-7.2f", biasFrameSettings.exposureTime);
		BiasFrameSettingDialog::FormPtr->SetExpTimeTextBox(buffer);

		/* # of frames */

		sprintf_s(buffer, sizeof(buffer), "%d", biasFrameSettings.numFrames);
		BiasFrameSettingDialog::FormPtr->SetNumFramesTextBox(buffer);

		/* Which ccd */

		if (ccd->make != SBIG_MAKE) {
			BiasFrameSettingDialog::HideCCDTrackingButton();
			BiasFrameSettingDialog::SetWhichCCDButton(0);
		} else {
			BiasFrameSettingDialog::ShowCCDTrackingButton();
			BiasFrameSettingDialog::SetWhichCCDButton(darkFrameSettings.whichCCD);
		}

		/* Binning */

		if (biasFrameSettings.whichCCD == 0)
			BiasFrameSettingDialog::FormPtr->SetWhichBinningButton(darkFrameSettings.binning);

		/* ccd Frame size */

		if (biasFrameSettings.w <= 0) {
			GetCCDFrameSettings(ccd, &biasFrameSettings.x, &biasFrameSettings.y,
				&biasFrameSettings.w, &biasFrameSettings.h, &biasFrameSettings.binning);
		}
		sprintf_s(buffer, sizeof(buffer), "%d, %d, %d, %d", biasFrameSettings.x,
			biasFrameSettings.y, biasFrameSettings.h, biasFrameSettings.w);
		BiasFrameSettingDialog::FormPtr->SetFrameTextBox(buffer);

		/* Save each frame? */

		BiasFrameSettingDialog::FormPtr->SaveEachBiasButton->Checked =
			BiasSaveEachBiasFrame;

		/* combine method */

		if (biasFrameSettings.combineMethod == 1)
			BiasFrameSettingDialog::FormPtr->MedianButton->Checked = true;
		else
			BiasFrameSettingDialog::FormPtr->MeanButton->Checked = true;

		return true;
	}


	public:  int GetDarkFrameSettings(void) {

		char buffer[80];

		/* exposure time */

		BiasFrameSettingDialog::FormPtr->GetExpTimeTextBox(buffer);
		sscanf_s(buffer, "%f", &biasFrameSettings.exposureTime);

		/* # frames */

		BiasFrameSettingDialog::FormPtr->GetNumFramesTextBox(buffer);
		sscanf_s(buffer, "%d", &biasFrameSettings.numFrames);

		/* Which ccd */

		if (ccd->make == SBIG_MAKE)
			biasFrameSettings.whichCCD = BiasFrameSettingDialog::GetWhichCCDButton();

		/* Binning */

		biasFrameSettings.binning = BiasFrameSettingDialog::FormPtr->GetWhichBinningButton();

		/* ccd Frame size */

		BiasFrameSettingDialog::FormPtr->GetFrameTextBox(buffer);
		sscanf_s(buffer, "%d, %d, %d, %d", &biasFrameSettings.x,
			&biasFrameSettings.y, &biasFrameSettings.h, &biasFrameSettings.w);

		/* Save each frame? */

		BiasSaveEachBiasFrame =
			BiasFrameSettingDialog::FormPtr->SaveEachBiasButton->Checked;

		/* combine method */

		if (BiasFrameSettingDialog::FormPtr->MedianButton->Checked)
			biasFrameSettings.combineMethod = 1;
		else
			biasFrameSettings.combineMethod = 2;

		return true;
	}


	private: System::Void SelectBiasFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {

		char path[180];

		GetAFolder("Select Bias Frame Folder", path);
		strcpy_s(biasFrameSettings.imageDir, sizeof(biasFrameSettings.imageDir), path);
		this->SetBiasDirTextBox(biasFrameSettings.imageDir);
		return;
	}


	public: static void SetWhichCCDButton(int which) {

		if (which == 0) {
			BiasFrameSettingDialog::FormPtr->ImagingCCDButton->Checked = true;
			BiasFrameSettingDialog::FormPtr->TrackingCCDButton->Checked = false;
		} else {
			BiasFrameSettingDialog::FormPtr->ImagingCCDButton->Checked = false;
			BiasFrameSettingDialog::FormPtr->TrackingCCDButton->Checked = true;
		}
	}


	public: static int GetWhichCCDButton(void) {

		if (BiasFrameSettingDialog::FormPtr->ImagingCCDButton->Checked) {
			return 0;
		} else {
			return 1;
		}
	}


	public:  void HideCCDTrackingButton(void) {
		BiasFrameSettingDialog::FormPtr->TrackingCCDButton->Hide();
	}


	public:  void ShowCCDTrackingButton(void) {
		BiasFrameSettingDialog::FormPtr->TrackingCCDButton->Show();
	}


	public: static int GetWhichBinningButton(void) {

		if (BiasFrameSettingDialog::FormPtr->Binning1x1Button->Checked) {
			return 0;
		} else if (BiasFrameSettingDialog::FormPtr->Binning2x2Button->Checked) {
			return 1;
		} else {
			return 2;
		}
	}

};
}
