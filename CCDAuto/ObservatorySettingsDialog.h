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
	/// Summary for ObservatorySettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ObservatorySettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static ObservatorySettingsDialog^ FormPtr;
		static bool ComboBoxListSet = false;
		ObservatorySettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			ObservatorySettingsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ObservatorySettingsDialog()
		{
			if (components)
			{
				delete components;
			}
			ObservatorySettingsDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox3;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::ComboBox^  ScopeComboBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ProjectTextBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  ObserverNameTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  ObservatoryNameTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  LatitudeTextBox;
	private: System::Windows::Forms::TextBox^  LongitudeTextBox;
	private: System::Windows::Forms::TextBox^  ElevationTextBox;

	private: System::Windows::Forms::TextBox^  TimeZoneTextBox;
	private: System::Windows::Forms::CheckBox^  DaylightSavingsCheckBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::TextBox^  FocalRatioTextBox;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  PrimaryDiameterTextBox;

	private: System::Windows::Forms::Label^  label8;



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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ObservatoryNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->LatitudeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LongitudeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ElevationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TimeZoneTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DaylightSavingsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FocalRatioTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->ScopeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PrimaryDiameterTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ProjectTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ObserverNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 83.45865F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.54135F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(409, 266);
			this->tableLayoutPanel1->TabIndex = 0;
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 225);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(403, 38);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(264, 7);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 6;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ObservatorySettingsDialog::CancelButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(63, 7);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 3;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &ObservatorySettingsDialog::OkButton_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				55.33499F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				44.66501F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(403, 216);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel7);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(217, 210);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Observatory";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				41.39535F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				58.60465F)));
			this->tableLayoutPanel7->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->ObservatoryNameTextBox, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->label5, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->label6, 0, 4);
			this->tableLayoutPanel7->Controls->Add(this->label7, 0, 3);
			this->tableLayoutPanel7->Controls->Add(this->LatitudeTextBox, 1, 1);
			this->tableLayoutPanel7->Controls->Add(this->LongitudeTextBox, 1, 2);
			this->tableLayoutPanel7->Controls->Add(this->ElevationTextBox, 1, 3);
			this->tableLayoutPanel7->Controls->Add(this->TimeZoneTextBox, 1, 4);
			this->tableLayoutPanel7->Controls->Add(this->DaylightSavingsCheckBox, 0, 5);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 6;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(211, 191);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(46, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Name:";
			// 
			// ObservatoryNameTextBox
			// 
			this->ObservatoryNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObservatoryNameTextBox->Location = System::Drawing::Point(90, 5);
			this->ObservatoryNameTextBox->Name = L"ObservatoryNameTextBox";
			this->ObservatoryNameTextBox->Size = System::Drawing::Size(113, 20);
			this->ObservatoryNameTextBox->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 40);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Lat (degrees):";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 71);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Long (degrees):";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 133);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Time Zone (#):";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 102);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(71, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Elevation (m):";
			// 
			// LatitudeTextBox
			// 
			this->LatitudeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LatitudeTextBox->Location = System::Drawing::Point(90, 36);
			this->LatitudeTextBox->Name = L"LatitudeTextBox";
			this->LatitudeTextBox->Size = System::Drawing::Size(78, 20);
			this->LatitudeTextBox->TabIndex = 8;
			// 
			// LongitudeTextBox
			// 
			this->LongitudeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LongitudeTextBox->Location = System::Drawing::Point(90, 67);
			this->LongitudeTextBox->Name = L"LongitudeTextBox";
			this->LongitudeTextBox->Size = System::Drawing::Size(78, 20);
			this->LongitudeTextBox->TabIndex = 9;
			// 
			// ElevationTextBox
			// 
			this->ElevationTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ElevationTextBox->Location = System::Drawing::Point(90, 98);
			this->ElevationTextBox->Name = L"ElevationTextBox";
			this->ElevationTextBox->Size = System::Drawing::Size(78, 20);
			this->ElevationTextBox->TabIndex = 10;
			// 
			// TimeZoneTextBox
			// 
			this->TimeZoneTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TimeZoneTextBox->Location = System::Drawing::Point(90, 129);
			this->TimeZoneTextBox->Name = L"TimeZoneTextBox";
			this->TimeZoneTextBox->Size = System::Drawing::Size(78, 20);
			this->TimeZoneTextBox->TabIndex = 11;
			// 
			// DaylightSavingsCheckBox
			// 
			this->DaylightSavingsCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DaylightSavingsCheckBox->AutoSize = true;
			this->tableLayoutPanel7->SetColumnSpan(this->DaylightSavingsCheckBox, 2);
			this->DaylightSavingsCheckBox->Location = System::Drawing::Point(53, 164);
			this->DaylightSavingsCheckBox->Name = L"DaylightSavingsCheckBox";
			this->DaylightSavingsCheckBox->Size = System::Drawing::Size(105, 17);
			this->DaylightSavingsCheckBox->TabIndex = 12;
			this->DaylightSavingsCheckBox->Text = L"Daylight Savings";
			this->DaylightSavingsCheckBox->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox3, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->groupBox2, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(226, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.42857F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58.57143F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(174, 210);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel5);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(3, 89);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(168, 118);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Scope";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel5->Controls->Add(this->tableLayoutPanel9, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->ScopeComboBox, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->tableLayoutPanel8, 0, 1);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(162, 99);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 2;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel9->Controls->Add(this->FocalRatioTextBox, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->label9, 0, 0);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 69);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(156, 27);
			this->tableLayoutPanel9->TabIndex = 2;
			// 
			// FocalRatioTextBox
			// 
			this->FocalRatioTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FocalRatioTextBox->Location = System::Drawing::Point(81, 3);
			this->FocalRatioTextBox->Name = L"FocalRatioTextBox";
			this->FocalRatioTextBox->Size = System::Drawing::Size(71, 20);
			this->FocalRatioTextBox->TabIndex = 5;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(11, 7);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Focal Ratio:";
			// 
			// ScopeComboBox
			// 
			this->ScopeComboBox->FormattingEnabled = true;
			this->ScopeComboBox->Location = System::Drawing::Point(3, 3);
			this->ScopeComboBox->Name = L"ScopeComboBox";
			this->ScopeComboBox->Size = System::Drawing::Size(150, 21);
			this->ScopeComboBox->TabIndex = 0;
			this->ScopeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ObservatorySettingsDialog::ScopeComboBox_SelectedIndexChanged);
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 2;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				46.15385F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.84615F)));
			this->tableLayoutPanel8->Controls->Add(this->PrimaryDiameterTextBox, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 36);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(156, 27);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// PrimaryDiameterTextBox
			// 
			this->PrimaryDiameterTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->PrimaryDiameterTextBox->Location = System::Drawing::Point(75, 3);
			this->PrimaryDiameterTextBox->Name = L"PrimaryDiameterTextBox";
			this->PrimaryDiameterTextBox->ReadOnly = true;
			this->PrimaryDiameterTextBox->Size = System::Drawing::Size(77, 20);
			this->PrimaryDiameterTextBox->TabIndex = 4;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 7);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Primary Dia.:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel6);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(168, 80);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Observer";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				30.90909F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				69.09091F)));
			this->tableLayoutPanel6->Controls->Add(this->ProjectTextBox, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->ObserverNameTextBox, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(162, 61);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// ProjectTextBox
			// 
			this->ProjectTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ProjectTextBox->Location = System::Drawing::Point(53, 35);
			this->ProjectTextBox->Name = L"ProjectTextBox";
			this->ProjectTextBox->Size = System::Drawing::Size(100, 20);
			this->ProjectTextBox->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Project:";
			// 
			// ObserverNameTextBox
			// 
			this->ObserverNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObserverNameTextBox->Location = System::Drawing::Point(53, 5);
			this->ObserverNameTextBox->Name = L"ObserverNameTextBox";
			this->ObserverNameTextBox->Size = System::Drawing::Size(100, 20);
			this->ObserverNameTextBox->TabIndex = 2;
			// 
			// ObservatorySettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 266);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"ObservatorySettingsDialog";
			this->Text = L"ObservatorySettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 ObservatorySettingsDialog::FormPtr->Hide();
			 GetObservatoryNameTextBox(ObsSettings.name);
			 GetLatitudeTextBox(buffer);
			 sscanf_s(buffer, "%f", &ObsSettings.latitude);
			 GetLongitudeTextBox(buffer);
			 sscanf_s(buffer, "%f", &ObsSettings.longitude);
			 GetElevationTextBox(buffer);
			 sscanf_s(buffer, "%f", &ObsSettings.elevation);
			 GetTimeZoneTextBox(buffer);
			 sscanf_s(buffer, "%d", &ObsSettings.TimeZone);
			 GetObserverNameTextBox(ObsSettings.Observer);
			 GetProjectTextBox(ObsSettings.Project);
			 ObsSettings.ScopeNumber = ObservatorySettingsDialog::FormPtr->ScopeComboBox->SelectedIndex;
			 memcpy_s(&ObsSettings.scope, sizeof(SCOPE), &ScopeList[ObsSettings.ScopeNumber],
				 sizeof(SCOPE));
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 ObservatorySettingsDialog::FormPtr->Hide();
		 }
public:  System::Void ShowTheDialog(void) {

			 char buffer[80];
			 String^ string;
			 int i;

			 if (! ObservatorySettingsDialogExists)
				 gcnew ObservatorySettingsDialog();

			 ObservatorySettingsDialog::FormPtr->SetObservatoryNameTextBox(ObsSettings.name);
			 sprintf_s(buffer, sizeof(buffer), "%9.5f", ObsSettings.latitude);
			 ObservatorySettingsDialog::FormPtr->SetLatitudeTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%9.5f", ObsSettings.longitude);
			 ObservatorySettingsDialog::FormPtr->SetLongitudeTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%9.5f", ObsSettings.elevation);
			 ObservatorySettingsDialog::FormPtr->SetElevationTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%d", ObsSettings.TimeZone);
			 ObservatorySettingsDialog::FormPtr->SetTimeZoneTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "%4.2fm (%4.1f\")", ObsSettings.scope.PrimaryDia,
				 ObsSettings.scope.PrimaryDia/0.0254);
			 ObservatorySettingsDialog::FormPtr->SetPrimaryDiameterTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "f-%5.2f", ObsSettings.scope.FocalRatio);
			 ObservatorySettingsDialog::FormPtr->SetFocalRatioTextBox(buffer);
			 ObservatorySettingsDialog::FormPtr->SetObserverNameTextBox(ObsSettings.Observer);
			 ObservatorySettingsDialog::FormPtr->SetProjectTextBox(ObsSettings.Project);
			 ObservatorySettingsDialog::FormPtr->DaylightSavingsCheckBox->Checked = ObsSettings.DaylightSavings;
			 if (! ObservatorySettingsDialog::FormPtr->ComboBoxListSet) {
				 for(i=0; i<5; i++) {
					 string = gcnew String(ScopeList[i].name);
					 ObservatorySettingsDialog::FormPtr->ScopeComboBox->Items->Add(string);
				 }
				 ObservatorySettingsDialog::FormPtr->ComboBoxListSet = true;
			 }
			 ObservatorySettingsDialog::FormPtr->ScopeComboBox->SelectedIndex =
				 ObsSettings.ScopeNumber;

			 ObservatorySettingsDialog::FormPtr->ShowDialog();
		 }
public: static void SetObservatoryNameTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->ObservatoryNameTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetObservatoryNameTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->ObservatoryNameTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetLatitudeTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->LatitudeTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetLatitudeTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->LatitudeTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetLongitudeTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->LongitudeTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetLongitudeTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->LongitudeTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetElevationTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->ElevationTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetElevationTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->ElevationTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetTimeZoneTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->TimeZoneTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetTimeZoneTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->TimeZoneTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetObserverNameTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->ObserverNameTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetObserverNameTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->ObserverNameTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetProjectTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->ProjectTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetProjectTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->ProjectTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetPrimaryDiameterTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->PrimaryDiameterTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetPrimaryDiameterTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->PrimaryDiameterTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetFocalRatioTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObservatorySettingsDialog::FormPtr->FocalRatioTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetFocalRatioTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObservatorySettingsDialog::FormPtr->FocalRatioTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
private: System::Void ScopeComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 char name[80], buffer[80];
			 String^ string;
			 int i, index;

			 string = (String ^) ObservatorySettingsDialog::FormPtr->ScopeComboBox->SelectedItem;
			 for (i=0; i<string->Length; i++) name[i] = (char) string[i];
			 name[i] = 0;
			 index = ObservatorySettingsDialog::FormPtr->ScopeComboBox->SelectedIndex;
			 sprintf_s(buffer, sizeof(buffer), "%4.2fm (%4.1f\")", ScopeList[index].PrimaryDia,
				 ScopeList[index].PrimaryDia/0.0254);
			 ObservatorySettingsDialog::FormPtr->SetPrimaryDiameterTextBox(buffer);
			 sprintf_s(buffer, sizeof(buffer), "f-%5.2f", ScopeList[index].FocalRatio);
			 ObservatorySettingsDialog::FormPtr->SetFocalRatioTextBox(buffer);
		 }
};
}
