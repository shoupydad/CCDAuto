#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "SlitGuideSettingsDialog.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for GuideFrameWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class GuideFrameWindow : public System::Windows::Forms::Form
	{
	public:
		static GuideFrameWindow^ FormPtr;
		static MARKSTAR *MarkedStarList;
		static bool SlitLeftSet, SlitRightSet;
		static int nGuiderFailures;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::Timer^  GuidingTimer;
	private: System::Windows::Forms::ToolStripButton^  ClearMarksButton;
	private: System::Windows::Forms::CheckBox^  LiveCheckBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  MaxPixTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  YTextBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  StarYTextBox;
	private: System::Windows::Forms::Timer^  LiveTimer;

	private: System::Windows::Forms::ToolStripTextBox^  GuidingStateTextBox;
	public: 
		GuideFrameWindow(void)
		{
			InitializeComponent();
			CCDAuto::GuideFrameWindowExists = true;
			FormPtr = this;
			SlitLeftSet = SlitRightSet = false;
			GuidingSlitSettings.Running = false;
			GuidingSlitSettings.Live = false;
			FormPtr->SetGuidingStateTextBox("Off");
			FormPtr->nGuiderFailures = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GuideFrameWindow()
		{
			if (components)
			{
				delete components;
				CCDAuto::GuideFrameWindowExists = false;
			}
		}
	public: System::Drawing::Bitmap ^Bitmap;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  CloseButton;

	private: System::Windows::Forms::ToolStripButton^  SettingsButton;
	private: System::Windows::Forms::ToolStripButton^  OnOffButton;
	private: System::Windows::Forms::ToolStripButton^  ToSlitButton;

	private: System::Windows::Forms::ToolStripButton^  ExposeButton;
	public:  System::Drawing::Bitmap^ GuideFrameBitmap;
	public: System::Windows::Forms::PictureBox^  PictureBox;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  GuideFrameStarPSFGroupBox;
	private: System::Windows::Forms::GroupBox^  GuideFrameCurPixGroupBox;
	private: System::Windows::Forms::GroupBox^  GuideFrameDispParmsGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  XTextBox;




	private: System::Windows::Forms::TextBox^  PixValTextBox;
	private: System::Windows::Forms::TextBox^  MinPixTextBox;



	private: System::Windows::Forms::TextBox^  AvePixTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  StarXTextBox;


	private: System::Windows::Forms::TextBox^  StarMaxTextBox;
	private: System::Windows::Forms::TextBox^  FWHMTextBox;
	private: System::Windows::Forms::TextBox^  StarSumTextBox;

	private: System::Windows::Forms::CheckBox^  PlotCheckBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  BgndTextBox;
	private: System::Windows::Forms::TextBox^  RangeTextBox;
	private: System::Windows::Forms::TextBox^  GammaTextBox;
	private: System::Windows::Forms::TextBox^  XOffsetTextBox;

private: System::Windows::Forms::CheckBox^  LogOffsetsCheckBox;

	private: System::Windows::Forms::Button^  ApplyButton;
private: System::Windows::Forms::TextBox^  YOffsetTextBox;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GuideFrameWindow::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->CloseButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ExposeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->SettingsButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ToSlitButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->OnOffButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ClearMarksButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->GuidingStateTextBox = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->GuideFrameDispParmsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->BgndTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RangeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GammaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->XOffsetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->YOffsetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ApplyButton = (gcnew System::Windows::Forms::Button());
			this->LiveCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LogOffsetsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GuideFrameStarPSFGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->StarXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->FWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->StarSumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PlotCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GuideFrameCurPixGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->XTextBox = (gcnew System::Windows::Forms::TextBox());
			this->YTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->PixValTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->MinPixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->MaxPixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->AvePixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GuidingTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->LiveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->GuideFrameDispParmsGroupBox->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->GuideFrameStarPSFGroupBox->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->GuideFrameCurPixGroupBox->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->toolStrip1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->PictureBox, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.36342F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67.08508F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.66248F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(673, 717);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->CloseButton, this->ExposeButton, 
				this->SettingsButton, this->ToSlitButton, this->OnOffButton, this->ClearMarksButton, this->toolStripSeparator1, this->toolStripLabel1, 
				this->GuidingStateTextBox});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(673, 52);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// CloseButton
			// 
			this->CloseButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->CloseButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CloseButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"CloseButton.Image")));
			this->CloseButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(45, 49);
			this->CloseButton->Text = L"Close";
			this->CloseButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::CloseButton_Click);
			// 
			// ExposeButton
			// 
			this->ExposeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ExposeButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ExposeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ExposeButton.Image")));
			this->ExposeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ExposeButton->Name = L"ExposeButton";
			this->ExposeButton->Size = System::Drawing::Size(56, 49);
			this->ExposeButton->Text = L"Expose";
			this->ExposeButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::ExposeButton_Click);
			// 
			// SettingsButton
			// 
			this->SettingsButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->SettingsButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SettingsButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SettingsButton.Image")));
			this->SettingsButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->SettingsButton->Name = L"SettingsButton";
			this->SettingsButton->Size = System::Drawing::Size(65, 49);
			this->SettingsButton->Text = L"Settings";
			this->SettingsButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::SettingsButton_Click);
			// 
			// ToSlitButton
			// 
			this->ToSlitButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ToSlitButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ToSlitButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ToSlitButton.Image")));
			this->ToSlitButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ToSlitButton->Name = L"ToSlitButton";
			this->ToSlitButton->Size = System::Drawing::Size(58, 49);
			this->ToSlitButton->Text = L"To Slit";
			this->ToSlitButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::ToSlitButton_Click);
			// 
			// OnOffButton
			// 
			this->OnOffButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->OnOffButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OnOffButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"OnOffButton.Image")));
			this->OnOffButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->OnOffButton->Name = L"OnOffButton";
			this->OnOffButton->Size = System::Drawing::Size(61, 49);
			this->OnOffButton->Text = L"On/Off";
			this->OnOffButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::OnOffButton_Click);
			// 
			// ClearMarksButton
			// 
			this->ClearMarksButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ClearMarksButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ClearMarksButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ClearMarksButton.Image")));
			this->ClearMarksButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ClearMarksButton->Name = L"ClearMarksButton";
			this->ClearMarksButton->Size = System::Drawing::Size(88, 49);
			this->ClearMarksButton->Text = L"Clear Marks";
			this->ClearMarksButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::ClearMarksButton_Clicked);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 52);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(102, 49);
			this->toolStripLabel1->Text = L"Guiding State:";
			// 
			// GuidingStateTextBox
			// 
			this->GuidingStateTextBox->Name = L"GuidingStateTextBox";
			this->GuidingStateTextBox->ReadOnly = true;
			this->GuidingStateTextBox->Size = System::Drawing::Size(40, 52);
			// 
			// PictureBox
			// 
			this->PictureBox->BackColor = System::Drawing::Color::White;
			this->PictureBox->Cursor = System::Windows::Forms::Cursors::Cross;
			this->PictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PictureBox->Location = System::Drawing::Point(3, 55);
			this->PictureBox->MaximumSize = System::Drawing::Size(640, 480);
			this->PictureBox->MinimumSize = System::Drawing::Size(256, 256);
			this->PictureBox->Name = L"PictureBox";
			this->PictureBox->Size = System::Drawing::Size(640, 474);
			this->PictureBox->TabIndex = 1;
			this->PictureBox->TabStop = false;
			this->PictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GuideFrameWindow::MouseMoveHandler);
			this->PictureBox->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GuideFrameWindow::MouseDoubleClickHandler);
			this->PictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GuideFrameWindow::MouseClickHandler);
			this->PictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GuideFrameWindow::PaintHandler);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				32.38381F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.13343F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				34.25499F)));
			this->tableLayoutPanel2->Controls->Add(this->GuideFrameDispParmsGroupBox, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->GuideFrameStarPSFGroupBox, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->GuideFrameCurPixGroupBox, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 535);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(667, 179);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// GuideFrameDispParmsGroupBox
			// 
			this->GuideFrameDispParmsGroupBox->Controls->Add(this->tableLayoutPanel5);
			this->GuideFrameDispParmsGroupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GuideFrameDispParmsGroupBox->Location = System::Drawing::Point(440, 3);
			this->GuideFrameDispParmsGroupBox->Name = L"GuideFrameDispParmsGroupBox";
			this->GuideFrameDispParmsGroupBox->Size = System::Drawing::Size(224, 173);
			this->GuideFrameDispParmsGroupBox->TabIndex = 2;
			this->GuideFrameDispParmsGroupBox->TabStop = false;
			this->GuideFrameDispParmsGroupBox->Text = L"Display Parameters";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 4;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				26.6055F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				24.31193F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				25.68807F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				22.93578F)));
			this->tableLayoutPanel5->Controls->Add(this->label13, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label14, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label15, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->BgndTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->RangeTextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->GammaTextBox, 1, 2);
			this->tableLayoutPanel5->Controls->Add(this->label17, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->XOffsetTextBox, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->label7, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->YOffsetTextBox, 3, 1);
			this->tableLayoutPanel5->Controls->Add(this->ApplyButton, 0, 3);
			this->tableLayoutPanel5->Controls->Add(this->LiveCheckBox, 1, 3);
			this->tableLayoutPanel5->Controls->Add(this->LogOffsetsCheckBox, 2, 2);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 4;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99875F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99875F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99875F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00375F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(218, 154);
			this->tableLayoutPanel5->TabIndex = 1;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(20, 12);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(35, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Bgnd:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(13, 50);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 13);
			this->label14->TabIndex = 2;
			this->label14->Text = L"Range:";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(9, 88);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(46, 13);
			this->label15->TabIndex = 3;
			this->label15->Text = L"Gamma:";
			// 
			// BgndTextBox
			// 
			this->BgndTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->BgndTextBox->BackColor = System::Drawing::Color::White;
			this->BgndTextBox->Location = System::Drawing::Point(61, 9);
			this->BgndTextBox->Name = L"BgndTextBox";
			this->BgndTextBox->Size = System::Drawing::Size(37, 20);
			this->BgndTextBox->TabIndex = 7;
			this->BgndTextBox->Text = L"99999";
			this->BgndTextBox->WordWrap = false;
			// 
			// RangeTextBox
			// 
			this->RangeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->RangeTextBox->BackColor = System::Drawing::Color::White;
			this->RangeTextBox->Location = System::Drawing::Point(61, 47);
			this->RangeTextBox->Name = L"RangeTextBox";
			this->RangeTextBox->Size = System::Drawing::Size(37, 20);
			this->RangeTextBox->TabIndex = 8;
			this->RangeTextBox->Text = L"99999";
			this->RangeTextBox->WordWrap = false;
			// 
			// GammaTextBox
			// 
			this->GammaTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GammaTextBox->BackColor = System::Drawing::Color::White;
			this->GammaTextBox->Location = System::Drawing::Point(61, 85);
			this->GammaTextBox->Name = L"GammaTextBox";
			this->GammaTextBox->Size = System::Drawing::Size(43, 20);
			this->GammaTextBox->TabIndex = 9;
			this->GammaTextBox->Text = L"9.9999";
			this->GammaTextBox->WordWrap = false;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(116, 12);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(48, 13);
			this->label17->TabIndex = 5;
			this->label17->Text = L"X Offset:";
			// 
			// XOffsetTextBox
			// 
			this->XOffsetTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->XOffsetTextBox->BackColor = System::Drawing::Color::White;
			this->XOffsetTextBox->Location = System::Drawing::Point(170, 9);
			this->XOffsetTextBox->Name = L"XOffsetTextBox";
			this->XOffsetTextBox->ReadOnly = true;
			this->XOffsetTextBox->Size = System::Drawing::Size(37, 20);
			this->XOffsetTextBox->TabIndex = 11;
			this->XOffsetTextBox->Text = L"99.99";
			this->XOffsetTextBox->WordWrap = false;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(116, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Y Offset:";
			// 
			// YOffsetTextBox
			// 
			this->YOffsetTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->YOffsetTextBox->BackColor = System::Drawing::Color::White;
			this->YOffsetTextBox->Location = System::Drawing::Point(170, 47);
			this->YOffsetTextBox->Name = L"YOffsetTextBox";
			this->YOffsetTextBox->ReadOnly = true;
			this->YOffsetTextBox->Size = System::Drawing::Size(37, 20);
			this->YOffsetTextBox->TabIndex = 15;
			this->YOffsetTextBox->Text = L"99.99";
			this->YOffsetTextBox->WordWrap = false;
			// 
			// ApplyButton
			// 
			this->ApplyButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ApplyButton->Location = System::Drawing::Point(4, 122);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(50, 23);
			this->ApplyButton->TabIndex = 14;
			this->ApplyButton->Text = L"Apply";
			this->ApplyButton->UseVisualStyleBackColor = true;
			this->ApplyButton->Click += gcnew System::EventHandler(this, &GuideFrameWindow::ApplyButton_Click);
			// 
			// LiveCheckBox
			// 
			this->LiveCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->LiveCheckBox->AutoSize = true;
			this->LiveCheckBox->Location = System::Drawing::Point(61, 125);
			this->LiveCheckBox->Name = L"LiveCheckBox";
			this->LiveCheckBox->Size = System::Drawing::Size(46, 17);
			this->LiveCheckBox->TabIndex = 16;
			this->LiveCheckBox->Text = L"Live";
			this->LiveCheckBox->UseVisualStyleBackColor = true;
			this->LiveCheckBox->CheckedChanged += gcnew System::EventHandler(this, &GuideFrameWindow::LiveCheckBox_CheckedChanged);
			// 
			// LogOffsetsCheckBox
			// 
			this->LogOffsetsCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->LogOffsetsCheckBox->AutoSize = true;
			this->LogOffsetsCheckBox->Location = System::Drawing::Point(114, 86);
			this->LogOffsetsCheckBox->Name = L"LogOffsetsCheckBox";
			this->LogOffsetsCheckBox->Size = System::Drawing::Size(50, 17);
			this->LogOffsetsCheckBox->TabIndex = 13;
			this->LogOffsetsCheckBox->Text = L"Log Offsets";
			this->LogOffsetsCheckBox->UseVisualStyleBackColor = true;
			// 
			// GuideFrameStarPSFGroupBox
			// 
			this->GuideFrameStarPSFGroupBox->Controls->Add(this->tableLayoutPanel4);
			this->GuideFrameStarPSFGroupBox->Location = System::Drawing::Point(219, 3);
			this->GuideFrameStarPSFGroupBox->Name = L"GuideFrameStarPSFGroupBox";
			this->GuideFrameStarPSFGroupBox->Size = System::Drawing::Size(215, 122);
			this->GuideFrameStarPSFGroupBox->TabIndex = 1;
			this->GuideFrameStarPSFGroupBox->TabStop = false;
			this->GuideFrameStarPSFGroupBox->Text = L"Star PSF";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				20)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				28.78049F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				24.87805F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				27.31707F)));
			this->tableLayoutPanel4->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->label9, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->StarXTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->StarMaxTextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->StarYTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label10, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->label11, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->FWHMTextBox, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->label12, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->StarSumTextBox, 3, 1);
			this->tableLayoutPanel4->Controls->Add(this->PlotCheckBox, 3, 2);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(209, 103);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 10);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"X:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(21, 44);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Y:";
			// 
			// StarXTextBox
			// 
			this->StarXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarXTextBox->BackColor = System::Drawing::Color::White;
			this->StarXTextBox->Location = System::Drawing::Point(44, 7);
			this->StarXTextBox->Name = L"StarXTextBox";
			this->StarXTextBox->ReadOnly = true;
			this->StarXTextBox->Size = System::Drawing::Size(48, 20);
			this->StarXTextBox->TabIndex = 7;
			this->StarXTextBox->Text = L"9999.99";
			this->StarXTextBox->WordWrap = false;
			// 
			// StarMaxTextBox
			// 
			this->StarMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarMaxTextBox->BackColor = System::Drawing::Color::White;
			this->StarMaxTextBox->Location = System::Drawing::Point(44, 75);
			this->StarMaxTextBox->Name = L"StarMaxTextBox";
			this->StarMaxTextBox->ReadOnly = true;
			this->StarMaxTextBox->Size = System::Drawing::Size(37, 20);
			this->StarMaxTextBox->TabIndex = 9;
			this->StarMaxTextBox->Text = L"99999";
			this->StarMaxTextBox->WordWrap = false;
			// 
			// StarYTextBox
			// 
			this->StarYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarYTextBox->BackColor = System::Drawing::Color::White;
			this->StarYTextBox->Location = System::Drawing::Point(44, 41);
			this->StarYTextBox->Name = L"StarYTextBox";
			this->StarYTextBox->ReadOnly = true;
			this->StarYTextBox->Size = System::Drawing::Size(48, 20);
			this->StarYTextBox->TabIndex = 12;
			this->StarYTextBox->Text = L"9999.99";
			this->StarYTextBox->WordWrap = false;
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(8, 79);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Max:";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(104, 10);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(44, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"FWHM:";
			// 
			// FWHMTextBox
			// 
			this->FWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FWHMTextBox->BackColor = System::Drawing::Color::White;
			this->FWHMTextBox->Location = System::Drawing::Point(154, 7);
			this->FWHMTextBox->Name = L"FWHMTextBox";
			this->FWHMTextBox->ReadOnly = true;
			this->FWHMTextBox->Size = System::Drawing::Size(37, 20);
			this->FWHMTextBox->TabIndex = 10;
			this->FWHMTextBox->Text = L"99.99";
			this->FWHMTextBox->WordWrap = false;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(117, 44);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 13);
			this->label12->TabIndex = 5;
			this->label12->Text = L"Sum:";
			// 
			// StarSumTextBox
			// 
			this->StarSumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarSumTextBox->BackColor = System::Drawing::Color::White;
			this->StarSumTextBox->Location = System::Drawing::Point(154, 41);
			this->StarSumTextBox->Name = L"StarSumTextBox";
			this->StarSumTextBox->ReadOnly = true;
			this->StarSumTextBox->Size = System::Drawing::Size(52, 20);
			this->StarSumTextBox->TabIndex = 11;
			this->StarSumTextBox->Text = L"99999999";
			this->StarSumTextBox->WordWrap = false;
			// 
			// PlotCheckBox
			// 
			this->PlotCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PlotCheckBox->AutoSize = true;
			this->PlotCheckBox->Location = System::Drawing::Point(154, 77);
			this->PlotCheckBox->Name = L"PlotCheckBox";
			this->PlotCheckBox->Size = System::Drawing::Size(52, 17);
			this->PlotCheckBox->TabIndex = 13;
			this->PlotCheckBox->Text = L"Plot PSF";
			this->PlotCheckBox->UseVisualStyleBackColor = true;
			this->PlotCheckBox->CheckedChanged += gcnew System::EventHandler(this, &GuideFrameWindow::PlotButton_CheckedChanged);
			// 
			// GuideFrameCurPixGroupBox
			// 
			this->GuideFrameCurPixGroupBox->Controls->Add(this->tableLayoutPanel3);
			this->GuideFrameCurPixGroupBox->Location = System::Drawing::Point(3, 3);
			this->GuideFrameCurPixGroupBox->Name = L"GuideFrameCurPixGroupBox";
			this->GuideFrameCurPixGroupBox->Size = System::Drawing::Size(210, 122);
			this->GuideFrameCurPixGroupBox->TabIndex = 0;
			this->GuideFrameCurPixGroupBox->TabStop = false;
			this->GuideFrameCurPixGroupBox->Text = L"Current Pixel";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				22)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				23.5F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				26.5F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				28)));
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->XTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->YTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->PixValTextBox, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->MinPixTextBox, 3, 0);
			this->tableLayoutPanel3->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel3->Controls->Add(this->MaxPixTextBox, 3, 1);
			this->tableLayoutPanel3->Controls->Add(this->label6, 2, 2);
			this->tableLayoutPanel3->Controls->Add(this->AvePixTextBox, 3, 2);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(204, 103);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y:";
			// 
			// XTextBox
			// 
			this->XTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->XTextBox->BackColor = System::Drawing::Color::White;
			this->XTextBox->Location = System::Drawing::Point(47, 7);
			this->XTextBox->Name = L"XTextBox";
			this->XTextBox->ReadOnly = true;
			this->XTextBox->Size = System::Drawing::Size(37, 20);
			this->XTextBox->TabIndex = 7;
			this->XTextBox->Text = L"9999";
			this->XTextBox->WordWrap = false;
			// 
			// YTextBox
			// 
			this->YTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->YTextBox->BackColor = System::Drawing::Color::White;
			this->YTextBox->Location = System::Drawing::Point(47, 41);
			this->YTextBox->Name = L"YTextBox";
			this->YTextBox->ReadOnly = true;
			this->YTextBox->Size = System::Drawing::Size(37, 20);
			this->YTextBox->TabIndex = 8;
			this->YTextBox->Text = L"9999";
			this->YTextBox->WordWrap = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Value:";
			// 
			// PixValTextBox
			// 
			this->PixValTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->PixValTextBox->BackColor = System::Drawing::Color::White;
			this->PixValTextBox->Location = System::Drawing::Point(47, 75);
			this->PixValTextBox->Name = L"PixValTextBox";
			this->PixValTextBox->ReadOnly = true;
			this->PixValTextBox->Size = System::Drawing::Size(37, 20);
			this->PixValTextBox->TabIndex = 9;
			this->PixValTextBox->Text = L"99999";
			this->PixValTextBox->WordWrap = false;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(98, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Min Pix:";
			// 
			// MinPixTextBox
			// 
			this->MinPixTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MinPixTextBox->BackColor = System::Drawing::Color::White;
			this->MinPixTextBox->Location = System::Drawing::Point(148, 7);
			this->MinPixTextBox->Name = L"MinPixTextBox";
			this->MinPixTextBox->ReadOnly = true;
			this->MinPixTextBox->Size = System::Drawing::Size(37, 20);
			this->MinPixTextBox->TabIndex = 10;
			this->MinPixTextBox->Text = L"99999";
			this->MinPixTextBox->WordWrap = false;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(95, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Max Pix:";
			// 
			// MaxPixTextBox
			// 
			this->MaxPixTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MaxPixTextBox->BackColor = System::Drawing::Color::White;
			this->MaxPixTextBox->Location = System::Drawing::Point(148, 41);
			this->MaxPixTextBox->Name = L"MaxPixTextBox";
			this->MaxPixTextBox->ReadOnly = true;
			this->MaxPixTextBox->Size = System::Drawing::Size(37, 20);
			this->MaxPixTextBox->TabIndex = 11;
			this->MaxPixTextBox->Text = L"99999";
			this->MaxPixTextBox->WordWrap = false;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(96, 79);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Ave Pix:";
			// 
			// AvePixTextBox
			// 
			this->AvePixTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AvePixTextBox->BackColor = System::Drawing::Color::White;
			this->AvePixTextBox->Location = System::Drawing::Point(148, 75);
			this->AvePixTextBox->Name = L"AvePixTextBox";
			this->AvePixTextBox->ReadOnly = true;
			this->AvePixTextBox->Size = System::Drawing::Size(51, 20);
			this->AvePixTextBox->TabIndex = 12;
			this->AvePixTextBox->Text = L"99999.9";
			this->AvePixTextBox->WordWrap = false;
			// 
			// GuidingTimer
			// 
			this->GuidingTimer->Interval = 1000;
			this->GuidingTimer->Tick += gcnew System::EventHandler(this, &GuideFrameWindow::GuidingTimer_Tick);
			// 
			// LiveTimer
			// 
			this->LiveTimer->Interval = 200;
			this->LiveTimer->Tick += gcnew System::EventHandler(this, &GuideFrameWindow::LiveTimer_Tick);
			// 
			// GuideFrameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(673, 717);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"GuideFrameWindow";
			this->Text = L"GuideFrameWindow";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->GuideFrameDispParmsGroupBox->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->GuideFrameStarPSFGroupBox->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->GuideFrameCurPixGroupBox->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
private: System::Void ClearMarksButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->ClearMarkedStarList();
			 FormPtr->Refresh();
		 }
private: System::Void SettingsButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! SlitGuideSettingsDialogExists) {
				 gcnew SlitGuideSettingsDialog();
			 }

			 SlitGuideSettingsDialog::FormPtr->ShowTheDialog();
		 }
private: System::Void OnOffButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 int answer;
			 
			 // Turn on guiding
			 
			 if (! GuidingSlitSettings.Running) {
				 answer = MessageBox("Sure you want to start auto guiding on current star?", YESNO, true);
				 if (answer != YES)
					 return;
				 GuidingSlitSettings.Running = true;
				 
				 // Get guide star info
				 
				 
				 
				 // Save guiding image settings
				 
				 memcpy(&guideImageSettings_Save, &guideImageSettings, sizeof(SINGLESETTINGS));
				 
				 // Setup so only 60x60 pixel box centered on target is readout
				 
				 //guideImageSettings.x = GuidingSlitSettings.TargetX - 30; 
				 //if (guideImageSettings.x < 0) 
					// guideImageSettings.x = 0; 
				 //if (guideImageSettings.x+60 > guideImageSettings.w) 
					// guideImageSettings.x = guideImageSettings.w - 60; 
				 //guideImageSettings.w = 60; 
				 //guideImageSettings.y = GuidingSlitSettings.TargetY - 30; 
				 //if (guideImageSettings.y < 0) 
					// guideImageSettings.y = 0; 
				 //if (guideImageSettings.y+60 > guideImageSettings.h)
					// guideImageSettings.y = guideImageSettings.h - 60;
				 //guideImageSettings.h = 60;
				 
				 // Start timer to do guiding
				 
				 FormPtr->nGuiderFailures = 0;
				 if (! autoGuider()) {
					 MessageBox("Warning - Error starting autoguider.", OKAY, true);
					 GuidingSlitSettings.Running = false;
					 FormPtr->SetGuidingStateTextBox("Off");
				 } else {
					 FormPtr->SetGuidingStateTextBox("On");
					 FormPtr->GuidingTimer->Interval = (int) (GuidingSlitSettings.interval * 1000.0);
					 FormPtr->GuidingTimer->Enabled = true;
				 }			 
			 } else {
				 
				 // Turn off slit guiding
				 
				 answer = MessageBox("Sure you want to end auto guiding?", YESNO, true);
				 if (answer != YES)
					 return;
				 GuidingSlitSettings.Running = false;
				 FormPtr->GuidingTimer->Enabled = false;
				 FormPtr->SetGuidingStateTextBox("Off");
				 
				 // Restore guiding image settings
				 
				 memcpy(&guideImageSettings, &guideImageSettings_Save, sizeof(SINGLESETTINGS));
			 }
		 }
private: System::Void ToSlitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 char Message[160], buffer[80];
			 float StarX, StarY, StarMax, deltaX, deltaY, diffMax, slitX, slitY;
			 float delX, delY, b, slope;
			 double DeltaRA, DeltaDEC;
			 int xmin, xmax, ymin, ymax, max, nIterations, answer;
			 bool gotFrame, success, Found;
			 FRAME *frame;

			 answer = MessageBox("Sure you want to move the selected object to the slit?", YESNO, true);
			 if (answer != YES)
				 return;

			 frame = &TrackingCCD.Image.light_frame;

			 // Get inital position & max of target star

			 FormPtr->GetStarXTextBox(buffer);
			 sscanf_s(buffer, "%f", &StarX);
			 FormPtr->GetStarYTextBox(buffer);
			 sscanf_s(buffer, "%f", &StarY);
			 FormPtr->GetStarMaxTextBox(buffer);
			 sscanf_s(buffer, "%f", &StarMax);

			 // Compute target position on slit

			 delX = (float) (GuidingSlitSettings.slitX1 - GuidingSlitSettings.slitX0);
			 delY = (float) (GuidingSlitSettings.slitY1 - GuidingSlitSettings.slitY0);
			 b = (float) GuidingSlitSettings.slitY0;
			 slope = delY / delX;
			 slitX = 320;  // 1/2 of full width from left
			 slitY = slope*slitX + b;
		 
			 // Compute window around target position

			 xmin = (int) Math::Round(slitX - 30);
			 if (xmin < frame->x)
				 xmin = frame->x;
			 xmax = (int) Math::Round(slitX + 30);
			 if (xmax > (frame->x+frame->w))
				 xmax = frame->x + frame->w;
			 ymin = (int) Math::Round(slitY - 30);
			 if (ymin < frame->y)
				 ymin = frame->y;
			 ymax = (int) Math::Round(slitY + 30);
			 if (ymax > (frame->y+frame->h))
				 ymax = frame->y + frame->h;
			 
			 // Compute slit - star difference in pixels
			 
			 deltaX = (slitX - StarX);  // Currently X is DEC
			 deltaY = (slitY - StarY);  //  & Y is RA
			 DeltaRA = (deltaY * GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);  // in arcsec
			 DeltaDEC = (deltaX * GuidingSlitSettings.YScale);  // in arcsec

			 SetScopePositionPolling(OFF); // stop polling scope position from osurob because it screws things up
			 nIterations = 0;
			 while (((fabs(DeltaRA)>1.0) || (fabs(DeltaDEC)>1.0)) && (nIterations < 5)) {
				 
				 // Send command to move scope 
				 
				 WriteStatus("*** Info - Bumping telescope\n");
				 success = BumpScope(DeltaRA/3600.0, DeltaDEC/3600.0);
				 if (! success) {
					 MessageBox("*** WARNING - Couldn't move scope, aborting 'to slit'\n", OKAY, true);
					 return;
				 }
				 
				 // Take new image and see how close we got
				 
				 WriteStatus("*** Info - Taking new image to see how close we got.\n");
				 usleep(500000);
				 gotFrame = AcquireGuideFrame(&TrackingCCD, &guideImageSettings);
				 if (! gotFrame) {
					 MessageBox("*** WARNING - Can't acquire new slit image, aborting 'to slit' process\n", OKAY, true);
					 WriteStatus("*** WARNING - Can't acquire new slit image, aborting 'to slit' process\n");
					 return;
				 }
				 max = 0;
				 Found = FindStar(frame, xmin, ymin, xmax, ymax, &StarX, &StarY, &max);
				 diffMax = StarMax - max;
				 diffMax = ((float) fabs(diffMax)/((float) StarMax));
				 //    if ((! Found) || (diffMax > 0.50)) {
				 if (! Found) {
					 sprintf_s(Message, sizeof(Message),
						 "*** WARNING - Lost star, aborting 'to slit' (%f,%d,%f)\n", StarMax, max, diffMax);
					 MessageBox(Message, OKAY, true);
					 WriteStatus(Message);
					 return;
				 }
				 nIterations++;
				 
				 // Compute slit star difference in pixels
				 
				 deltaX = (slitX - StarX);  // Currently X is DEC
				 deltaY = (slitY - StarY);  // & Y is RA
				 DeltaRA = (deltaY*GuidingSlitSettings.XScale)/cos(ScopeDEC*3.14159/180.0);
				 DeltaDEC = (deltaX*GuidingSlitSettings.YScale);
			 }
			 SetScopePositionPolling(ON); // okay can poll scope position from osurob now
			 if (nIterations >= 5) {
				 MessageBox("*** Warning - Couldn't get object onto slit in 5 iterations.", OKAY, true);
				 WriteStatus("*** Warning - Couldn't get object onto slit in 5 iterations.\n");
			 } else {
				 MessageBox("*** Info - Object should be on slit.\n", OKAY, true);
				 WriteStatus("*** Info - Object should be on slit.\n");
			 }
			 
			 return;
		 }
private: System::Void ExposeButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 int gotFrame;

			 guideImageSettings.exposureTime = GuidingSlitSettings.exposure;
			 gotFrame = AcquireGuideFrame(&TrackingCCD, &guideImageSettings);
			 return;
		 }
private: System::Void PlotButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void LiveCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if (FormPtr->LiveCheckBox->Checked) {
				 if (GuidingSlitSettings.Running) {
					 MessageBox("Warning - Can't turn ON 'Live' mode with autoguider running", OKAY, true);
					 FormPtr->LiveCheckBox->Checked = false;
				 } else {
					 WriteStatus("*** Info - Turning ON 'Live' mode for guiding/slit image.\n");
					 GuidingSlitSettings.Live = true;
					 FormPtr->LiveTimer->Interval = 200;
					 FormPtr->LiveTimer->Enabled = true;
				 }
			 } else {
				 WriteStatus("*** Info - Turning OFF 'Live' mode for guiding/slit image.\n");
				 FormPtr->LiveTimer->Enabled = false;
				 GuidingSlitSettings.Live = false;
			 }

		 }
public:  System::Void ShowTheWindow(void) {

			 FormPtr->SlitLeftSet = FormPtr->SlitRightSet = false;
			 FormPtr->Show();
		 }
public: System::Void RefreshImage(void) {

			FormPtr->Refresh();
		}
private: System::Void ApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 UpdateGuideImage();
		 }
public: static void SetGuidingStateTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->GuidingStateTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetGuidingStateTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->GuidingStateTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->XTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->YTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetPixValTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->PixValTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetMinPixTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->MinPixTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetMaxPixTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->MaxPixTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetAvePixTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->AvePixTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetStarXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->StarXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStarXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->StarXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetStarYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->StarYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStarYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->StarYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetStarMaxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->StarMaxTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStarMaxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->StarMaxTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFWHMTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->FWHMTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetStarSumTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->StarSumTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetBgndTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->BgndTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetBgndTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->BgndTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetRangeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->RangeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetRangeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->RangeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetGammaTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->GammaTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetGammaTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->GammaTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetXOffsetTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->XOffsetTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetYOffsetTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		GuideFrameWindow::FormPtr->YOffsetTextBox->Text = buffer;
		delete buffer;
		}
public: static int PlotCheckBoxChecked(void) {
			return GuideFrameWindow::FormPtr->PlotCheckBox->Checked;
		}
private: System::Void MouseClickHandler(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 int xmin, ymin, xmax, ymax;
			 float Magnitude, MagErr, SkyFlux, StarFlux, FWHM, x, y;
			 int max, Found;
			 char buffer[80];
			 CCD *ccd;

			 ccd = &TrackingCCD;

			 if (e->Button == ::MouseButtons::Left) {
				 sprintf_s(buffer, sizeof(buffer), "%f", (float) e->X);
				 FormPtr->SetStarXTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%f", (float) e->Y);
				 FormPtr->SetStarYTextBox(buffer);
			 } else if (e->Button == ::MouseButtons::Right) {
				 xmin = (int) (e->X - photometrySettings.findRadius);
				 if (xmin < 0)
					 xmin = 0;
				 ymin = (int) (e->Y - photometrySettings.findRadius);
				 if (ymin < 0)
					 ymin = 0;
				 xmax = (int) (e->X + photometrySettings.findRadius);
				 if (xmax > ccd->Image.light_frame.w)
					 xmax = ccd->Image.light_frame.w;
				 ymax = (int) (e->Y + photometrySettings.findRadius);
				 if (ymax > ccd->Image.light_frame.h)
					 ymax = ccd->Image.light_frame.h;
				 Found = FindStar(&ccd->Image.light_frame, xmin, ymin, xmax, ymax,
						 &x, &y, &max);
				 if (Found) {
					 sprintf_s(buffer, sizeof(buffer), "%f", x);
					 FormPtr->SetStarXTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%f", y);
					 FormPtr->SetStarYTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%d", max);
					 FormPtr->SetStarMaxTextBox(buffer);
					 doPhotometry(&ccd->Image, GUIDEIMAGEWINDOW, x, y, max, false, &FWHM, &SkyFlux, &StarFlux,
								  &Magnitude, &MagErr);
					 sprintf_s(buffer, sizeof(buffer), "%6.2f", FWHM);
					 FormPtr->SetFWHMTextBox(buffer);
				 }
			 }
			 
		 }
private: System::Void MouseDoubleClickHandler(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 int xmin, ymin, xmax, ymax;
			 float x, y;
			 int max, Found;
			 CCD *ccd;

			 ccd = &TrackingCCD;
			 if (e->Button == ::MouseButtons::Left) {
			 } else if (e->Button == ::MouseButtons::Right) {
				 xmin = (int) (e->X - photometrySettings.findRadius);
				 if (xmin < 0)
					 xmin = 0;
				 ymin = (int) (e->Y - photometrySettings.findRadius);
				 if (ymin < 0)
					 ymin = 0;
				 xmax = (int) (e->X + photometrySettings.findRadius);
				 if (xmax > ccd->Image.light_frame.w)
					 xmax = ccd->Image.light_frame.w;
				 ymax = (int) (e->Y + photometrySettings.findRadius);
				 if (ymax > ccd->Image.light_frame.h)
					 ymax = ccd->Image.light_frame.h;
				 Found = FindStar(&ccd->Image.light_frame, xmin, ymin, xmax, ymax,
						 &x, &y, &max);
				 if (Found) {
					 FormPtr->UnmarkStar(x,y);
				 }
			 }
		 }
private: System::Void MouseMoveHandler(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 char buffer[80];
			 int mouseX = e->X;
			 int mouseY = e->Y;
			 int x = ccd->Image.light_frame.x;
			 int y = ccd->Image.light_frame.y;
			 sprintf_s(buffer,sizeof(buffer),"%d",mouseX);
			 FormPtr->SetXTextBox(buffer);
			 sprintf_s(buffer,sizeof(buffer),"%d",mouseY);
			 FormPtr->SetYTextBox(buffer);
			 if (TrackingCCD.Image.light_frame.frame == NULL)
				 return;
			 if ((mouseX >= TrackingCCD.Image.light_frame.w+x)  || (mouseX < x) ||
				 (mouseY >= TrackingCCD.Image.light_frame.h+y) || (mouseY < y))
				 return;
			 int pixel = TrackingCCD.Image.light_frame.w * (mouseY-y) + (mouseX-x);
			 sprintf_s(buffer, sizeof(buffer), "%d", TrackingCCD.Image.light_frame.frame[pixel]);
			 FormPtr->SetPixValTextBox(buffer);
		 }
public: static void ClearMarkedStarList(void) {

			MARKSTAR *sptr, *next;
			sptr = FormPtr->MarkedStarList;
			while (sptr != NULL) {
				next = sptr->next;
				free(sptr);
				sptr = next;
			}
			FormPtr->MarkedStarList = NULL;
			return;
		}
public: static void MarkStar(float x, float y) {

			MARKSTAR *newptr, *sptr, *prev;

			newptr = (MARKSTAR *) malloc(sizeof(MARKSTAR));
			if (newptr == NULL)
				return;
			newptr->x = x;
			newptr->y = y;
			newptr->next = NULL;
			prev = NULL;
			sptr = FormPtr->MarkedStarList;
			while (sptr != NULL) {
				if ((fabs(newptr->x-sptr->x) < 1.0) &&
					(fabs(newptr->y-sptr->y) < 1.0)) { // star already in list
					free(newptr);
					return;
				}
				prev = sptr;
				sptr = sptr->next;
			}
			if (prev == NULL) {
				FormPtr->MarkedStarList = newptr;
			} else {
				prev->next = newptr;
			}
			FormPtr->FormPtr->Refresh();
			return;
		}
public: static void UnmarkStar(float x, float y) {

			MARKSTAR *sptr, *head, *prev;

			sptr = head = FormPtr->MarkedStarList;
			prev = NULL;
			while (sptr != NULL) {
				if ((fabs(sptr->x-x)<1.0) && (fabs(sptr->y-y)<1.0)) {
					if (prev == NULL)
						FormPtr->MarkedStarList = sptr->next;
					else
						prev->next = sptr->next;
					free(sptr);
					FormPtr->Refresh();
					return;
				} else {
					prev = sptr;
					sptr = sptr->next;
				}
			}
			return;
		}
private: System::Void PaintHandler(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

			 MARKSTAR *sptr;
			 int x1, y1, x2, y2, starX, starY, h, w;
			 float AperRad, SkyInnerRad, SkyOuterRad;

			 AperRad = photometrySettings.aperatureRadius;
			 SkyInnerRad = photometrySettings.skyInnerRadius;
			 SkyOuterRad = photometrySettings.skyOuterRadius;
			 sptr = FormPtr->MarkedStarList;
			 while (sptr != NULL) {
				 starX = (int) Math::Round(sptr->x);
				 starY = (int) Math::Round(sptr->y);
				 x1 = (int) Math::Round(sptr->x - 5.0);
				 y1 = (int) Math::Round(sptr->y - 5.0);
				 x2 = (int) Math::Round(sptr->x + 5.0);
				 y2 = (int) Math::Round(sptr->y + 5.0);
				 e->Graphics->DrawLine(System::Drawing::Pens::Red,starX,y1,starX,y2);
				 e->Graphics->DrawLine(System::Drawing::Pens::Red,x1,starY,x2,starY);
				 x1 = (int) Math::Round(sptr->x-AperRad);
				 y1 = (int) Math::Round(sptr->y-AperRad);
				 h = w = (int) (2.0*AperRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 x1 = (int) Math::Round(sptr->x-SkyInnerRad);
				 y1 = (int) Math::Round(sptr->y-SkyInnerRad);
				 h = w = (int) (2.0*SkyInnerRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 x1 = (int) Math::Round(sptr->x-SkyOuterRad);
				 y1 = (int) Math::Round(sptr->y-SkyOuterRad);
				 h = w = (int) (2.0*SkyOuterRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 sptr = sptr->next;
			 }
			 e->Graphics->DrawLine(System::Drawing::Pens::Red, GuidingSlitSettings.slitX0,GuidingSlitSettings.slitY0,
				 GuidingSlitSettings.slitX1, GuidingSlitSettings.slitY1);
			 return;
		 }

private: System::Void GuidingTimer_Tick(System::Object^  sender, System::EventArgs^  e) {

			 bool success;

			 success = autoGuider();
			 if (! success) {
				 FormPtr->nGuiderFailures++;
				 if (FormPtr->nGuiderFailures >= 5) {
					 GuidingSlitSettings.Running = false;
					 FormPtr->GuidingTimer->Enabled = false;
					 FormPtr->SetGuidingStateTextBox("Off");
					 MessageBox("Had 5 autoguider failures in a row, turning off autoguiding.", OKAY, true);
				 }
			 } else {
				 FormPtr->nGuiderFailures = 0;
			 }
		 }
private: System::Void LiveTimer_Tick(System::Object^  sender, System::EventArgs^  e) {

			 static bool Busy=false;
			 bool gotFrame;

			 if (Busy)
				 return;
			 Busy = true;
			 gotFrame = AcquireGuideFrame(&TrackingCCD, &guideImageSettings);
			 if (! gotFrame) {
				 FormPtr->LiveTimer->Enabled = false;
				 FormPtr->LiveCheckBox->Checked = false;
				 MessageBox("Warning - Couldn't acquire guide/slit image, turned off 'Live'", OKAY, true);
			 }
			 Busy = false;
		 }
};
}
