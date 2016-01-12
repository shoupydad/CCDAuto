#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Form1.h"
#include "InitializeAstrometryDialog.h"


namespace CCDAuto {

	/// <summary>
	/// Summary for AstrometryWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AstrometryWindow : public System::Windows::Forms::Form
	{
	public:
		static AstrometryWindow ^FormPtr;
		static MARKSTAR *MarkedStarList;
		System::Drawing::Bitmap^ ImageBitmap;
		IMAGE *imagePtr;












//	private: System::Windows::Forms::Panel^  panel78;
//	private: System::Windows::Forms::Panel^  panel80;
//	private: System::Windows::Forms::Panel^  panel1;
//	private: System::Windows::Forms::Panel^  panel2;
//	private: System::Windows::Forms::Panel^  panel1;
//	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  EstErrorTextBox;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  initializeSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  computeSolutionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  matchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  unMatchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resetStarsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearMarkedStarsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  assignPreviousToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::TextBox^  ObjectMagTextBox;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  ObjectDECTextBox;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  ObjectRATextBox;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  ObjectXTextBox;
	private: System::Windows::Forms::TextBox^  ObjectYTextBox;
	private: System::Windows::Forms::TextBox^  ObjectMaxTextBox;
	private: System::Windows::Forms::TextBox^  ObjectFWHMTextBox;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  CurrentRATextBox;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  CurrentDECTextBox;
	private: System::Windows::Forms::CheckBox^  FlipVerticalCheckBox;
	private: System::Windows::Forms::CheckBox^  FlipHorizontalCheckBox;


	public: 
		System::Drawing::Bitmap^ ChartBitmap;
		AstrometryWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			FormPtr = this;
			this->FormClosing += gcnew FormClosingEventHandler(this,&AstrometryWindow::ClosingEventHandler);
			this->ImagePictureBox->MouseMove +=
				gcnew System::Windows::Forms::MouseEventHandler(this, &AstrometryWindow::MouseMoveHandler);
			this->ImagePictureBox->Paint +=
				gcnew System::Windows::Forms::PaintEventHandler(this, &AstrometryWindow::PaintHandler);
			this->ChartPictureBox->Paint +=
				gcnew System::Windows::Forms::PaintEventHandler(this, &AstrometryWindow::ChartPaintHandler);
			AstrometryWindowExists = true;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AstrometryWindow()
		{
			if (components)
			{
				delete components;
				AstrometryWindowExists = false;
			}
		}
	protected: 

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;











	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  SelectedStarMagTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  SelectedStarDECTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  SelectedStarRATextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label12;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  SolutionStatusTextBox;
	private: System::Windows::Forms::TextBox^  NumStarsTextBox;
	private: System::Windows::Forms::TextBox^  ScaleTextBox;
	private: System::Windows::Forms::TextBox^  ATextBox;
	private: System::Windows::Forms::TextBox^  BTextBox;
	private: System::Windows::Forms::TextBox^  CTextBox;
	private: System::Windows::Forms::TextBox^  DTextBox;
	private: System::Windows::Forms::TextBox^  ETextBox;
	private: System::Windows::Forms::TextBox^  FTextBox;
	private: System::Windows::Forms::TextBox^  CenterRATextBox;
	private: System::Windows::Forms::TextBox^  CenterDECTextBox;









	public: System::Windows::Forms::PictureBox^  ChartPictureBox;
	public: System::Windows::Forms::PictureBox^  ImagePictureBox;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AstrometryWindow::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ChartPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->ImagePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SelectedStarMagTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SelectedStarDECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SelectedStarRATextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->EstErrorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->SolutionStatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumStarsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ScaleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ATextBox = (gcnew System::Windows::Forms::TextBox());
			this->BTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ETextBox = (gcnew System::Windows::Forms::TextBox());
			this->FTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CenterRATextBox = (gcnew System::Windows::Forms::TextBox());
			this->CenterDECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ObjectMagTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->ObjectDECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->ObjectRATextBox = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->ObjectXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectFWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->CurrentRATextBox = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->CurrentDECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FlipVerticalCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FlipHorizontalCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initializeSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->computeSolutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->matchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unMatchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetStarsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearMarkedStarsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->assignPreviousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChartPictureBox))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImagePictureBox))->BeginInit();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->menuStrip1->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->menuStrip1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.494382F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.99679F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.66934F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1028, 708);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->AutoScroll = true;
			this->tableLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 34);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 517)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1022, 517);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->ChartPictureBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(505, 511);
			this->panel1->TabIndex = 4;
			// 
			// ChartPictureBox
			// 
			this->ChartPictureBox->BackColor = System::Drawing::Color::White;
			this->ChartPictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ChartPictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ChartPictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ChartPictureBox->Location = System::Drawing::Point(0, 0);
			this->ChartPictureBox->MaximumSize = System::Drawing::Size(1024, 1024);
			this->ChartPictureBox->MinimumSize = System::Drawing::Size(256, 256);
			this->ChartPictureBox->Name = L"ChartPictureBox";
			this->ChartPictureBox->Size = System::Drawing::Size(505, 511);
			this->ChartPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->ChartPictureBox->TabIndex = 3;
			this->ChartPictureBox->TabStop = false;
			this->ChartPictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AstrometryWindow::ChartMouseClickHandler);
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->Controls->Add(this->ImagePictureBox);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(514, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(505, 511);
			this->panel2->TabIndex = 5;
			// 
			// ImagePictureBox
			// 
			this->ImagePictureBox->BackColor = System::Drawing::Color::White;
			this->ImagePictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ImagePictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ImagePictureBox->Location = System::Drawing::Point(0, 0);
			this->ImagePictureBox->MaximumSize = System::Drawing::Size(1024, 1024);
			this->ImagePictureBox->MinimumSize = System::Drawing::Size(256, 256);
			this->ImagePictureBox->Name = L"ImagePictureBox";
			this->ImagePictureBox->Size = System::Drawing::Size(505, 497);
			this->ImagePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->ImagePictureBox->TabIndex = 2;
			this->ImagePictureBox->TabStop = false;
			this->ImagePictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AstrometryWindow::MouseClickHandler);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.91585F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.93346F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.09002F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				28.86497F)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 3, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel8, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 557);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1022, 148);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel4);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(126, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Selected Star";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40.83333F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				59.16667F)));
			this->tableLayoutPanel4->Controls->Add(this->SelectedStarMagTextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->SelectedStarDECTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->SelectedStarRATextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->label11, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(120, 81);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// SelectedStarMagTextBox
			// 
			this->SelectedStarMagTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SelectedStarMagTextBox->BackColor = System::Drawing::Color::White;
			this->SelectedStarMagTextBox->Location = System::Drawing::Point(51, 57);
			this->SelectedStarMagTextBox->Name = L"SelectedStarMagTextBox";
			this->SelectedStarMagTextBox->ReadOnly = true;
			this->SelectedStarMagTextBox->Size = System::Drawing::Size(48, 20);
			this->SelectedStarMagTextBox->TabIndex = 21;
			this->SelectedStarMagTextBox->Text = L"99.999";
			this->SelectedStarMagTextBox->WordWrap = false;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Mag:";
			// 
			// SelectedStarDECTextBox
			// 
			this->SelectedStarDECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SelectedStarDECTextBox->BackColor = System::Drawing::Color::White;
			this->SelectedStarDECTextBox->Location = System::Drawing::Point(51, 30);
			this->SelectedStarDECTextBox->Name = L"SelectedStarDECTextBox";
			this->SelectedStarDECTextBox->ReadOnly = true;
			this->SelectedStarDECTextBox->Size = System::Drawing::Size(66, 20);
			this->SelectedStarDECTextBox->TabIndex = 19;
			this->SelectedStarDECTextBox->Text = L" 00:00:00.0";
			this->SelectedStarDECTextBox->WordWrap = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"DEC:";
			// 
			// SelectedStarRATextBox
			// 
			this->SelectedStarRATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SelectedStarRATextBox->BackColor = System::Drawing::Color::White;
			this->SelectedStarRATextBox->Location = System::Drawing::Point(51, 3);
			this->SelectedStarRATextBox->Name = L"SelectedStarRATextBox";
			this->SelectedStarRATextBox->ReadOnly = true;
			this->SelectedStarRATextBox->Size = System::Drawing::Size(66, 20);
			this->SelectedStarRATextBox->TabIndex = 17;
			this->SelectedStarRATextBox->Text = L" 00:00:00.0";
			this->SelectedStarRATextBox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(20, 7);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 13);
			this->label11->TabIndex = 15;
			this->label11->Text = L"RA:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel5);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(135, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(443, 142);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Current Solution";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 6;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				13.19261F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.52507F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				13.72032F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20.05277F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.1372F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				22.42744F)));
			this->tableLayoutPanel5->Controls->Add(this->label13, 0, 3);
			this->tableLayoutPanel5->Controls->Add(this->EstErrorTextBox, 1, 3);
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->label5, 4, 0);
			this->tableLayoutPanel5->Controls->Add(this->label6, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label7, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->label8, 4, 1);
			this->tableLayoutPanel5->Controls->Add(this->label9, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label10, 2, 2);
			this->tableLayoutPanel5->Controls->Add(this->label12, 4, 2);
			this->tableLayoutPanel5->Controls->Add(this->label14, 2, 3);
			this->tableLayoutPanel5->Controls->Add(this->label15, 4, 3);
			this->tableLayoutPanel5->Controls->Add(this->SolutionStatusTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->NumStarsTextBox, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->ScaleTextBox, 5, 0);
			this->tableLayoutPanel5->Controls->Add(this->ATextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->BTextBox, 3, 1);
			this->tableLayoutPanel5->Controls->Add(this->CTextBox, 5, 1);
			this->tableLayoutPanel5->Controls->Add(this->DTextBox, 1, 2);
			this->tableLayoutPanel5->Controls->Add(this->ETextBox, 3, 2);
			this->tableLayoutPanel5->Controls->Add(this->FTextBox, 5, 2);
			this->tableLayoutPanel5->Controls->Add(this->CenterRATextBox, 3, 3);
			this->tableLayoutPanel5->Controls->Add(this->CenterDECTextBox, 5, 3);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 4;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(437, 123);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(4, 100);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(50, 13);
			this->label13->TabIndex = 30;
			this->label13->Text = L"Error Est:";
			// 
			// EstErrorTextBox
			// 
			this->EstErrorTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->EstErrorTextBox->BackColor = System::Drawing::Color::White;
			this->EstErrorTextBox->Location = System::Drawing::Point(60, 96);
			this->EstErrorTextBox->Name = L"EstErrorTextBox";
			this->EstErrorTextBox->ReadOnly = true;
			this->EstErrorTextBox->Size = System::Drawing::Size(51, 20);
			this->EstErrorTextBox->TabIndex = 40;
			this->EstErrorTextBox->Text = L"+000.0000";
			this->EstErrorTextBox->WordWrap = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Status:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(153, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"# Stars:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(298, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Scale:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(37, 38);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"A:";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(180, 38);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"B:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(318, 38);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"C:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(36, 68);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(18, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"D:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(180, 68);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"E:";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(319, 68);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(16, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"F:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(172, 100);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(25, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"RA:";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(303, 100);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 13);
			this->label15->TabIndex = 27;
			this->label15->Text = L"DEC:";
			// 
			// SolutionStatusTextBox
			// 
			this->SolutionStatusTextBox->BackColor = System::Drawing::Color::White;
			this->SolutionStatusTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SolutionStatusTextBox->Location = System::Drawing::Point(60, 3);
			this->SolutionStatusTextBox->Name = L"SolutionStatusTextBox";
			this->SolutionStatusTextBox->ReadOnly = true;
			this->SolutionStatusTextBox->Size = System::Drawing::Size(78, 20);
			this->SolutionStatusTextBox->TabIndex = 28;
			this->SolutionStatusTextBox->Text = L"None";
			this->SolutionStatusTextBox->WordWrap = false;
			// 
			// NumStarsTextBox
			// 
			this->NumStarsTextBox->BackColor = System::Drawing::Color::White;
			this->NumStarsTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NumStarsTextBox->Location = System::Drawing::Point(203, 3);
			this->NumStarsTextBox->Name = L"NumStarsTextBox";
			this->NumStarsTextBox->ReadOnly = true;
			this->NumStarsTextBox->Size = System::Drawing::Size(80, 20);
			this->NumStarsTextBox->TabIndex = 29;
			this->NumStarsTextBox->Text = L"000";
			this->NumStarsTextBox->WordWrap = false;
			// 
			// ScaleTextBox
			// 
			this->ScaleTextBox->BackColor = System::Drawing::Color::White;
			this->ScaleTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ScaleTextBox->Location = System::Drawing::Point(341, 3);
			this->ScaleTextBox->Name = L"ScaleTextBox";
			this->ScaleTextBox->ReadOnly = true;
			this->ScaleTextBox->Size = System::Drawing::Size(93, 20);
			this->ScaleTextBox->TabIndex = 30;
			this->ScaleTextBox->Text = L"0.000 \"/pixel";
			this->ScaleTextBox->WordWrap = false;
			// 
			// ATextBox
			// 
			this->ATextBox->BackColor = System::Drawing::Color::White;
			this->ATextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ATextBox->Location = System::Drawing::Point(60, 33);
			this->ATextBox->Name = L"ATextBox";
			this->ATextBox->ReadOnly = true;
			this->ATextBox->Size = System::Drawing::Size(78, 20);
			this->ATextBox->TabIndex = 31;
			this->ATextBox->Text = L"+000.0000";
			this->ATextBox->WordWrap = false;
			// 
			// BTextBox
			// 
			this->BTextBox->BackColor = System::Drawing::Color::White;
			this->BTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->BTextBox->Location = System::Drawing::Point(203, 33);
			this->BTextBox->Name = L"BTextBox";
			this->BTextBox->ReadOnly = true;
			this->BTextBox->Size = System::Drawing::Size(80, 20);
			this->BTextBox->TabIndex = 32;
			this->BTextBox->Text = L"+000.0000";
			this->BTextBox->WordWrap = false;
			// 
			// CTextBox
			// 
			this->CTextBox->BackColor = System::Drawing::Color::White;
			this->CTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CTextBox->Location = System::Drawing::Point(341, 33);
			this->CTextBox->Name = L"CTextBox";
			this->CTextBox->ReadOnly = true;
			this->CTextBox->Size = System::Drawing::Size(93, 20);
			this->CTextBox->TabIndex = 33;
			this->CTextBox->Text = L"+000.0000";
			this->CTextBox->WordWrap = false;
			// 
			// DTextBox
			// 
			this->DTextBox->BackColor = System::Drawing::Color::White;
			this->DTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DTextBox->Location = System::Drawing::Point(60, 63);
			this->DTextBox->Name = L"DTextBox";
			this->DTextBox->ReadOnly = true;
			this->DTextBox->Size = System::Drawing::Size(78, 20);
			this->DTextBox->TabIndex = 34;
			this->DTextBox->Text = L"+000.0000";
			this->DTextBox->WordWrap = false;
			// 
			// ETextBox
			// 
			this->ETextBox->BackColor = System::Drawing::Color::White;
			this->ETextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ETextBox->Location = System::Drawing::Point(203, 63);
			this->ETextBox->Name = L"ETextBox";
			this->ETextBox->ReadOnly = true;
			this->ETextBox->Size = System::Drawing::Size(80, 20);
			this->ETextBox->TabIndex = 35;
			this->ETextBox->Text = L"+000.0000";
			this->ETextBox->WordWrap = false;
			// 
			// FTextBox
			// 
			this->FTextBox->BackColor = System::Drawing::Color::White;
			this->FTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FTextBox->Location = System::Drawing::Point(341, 63);
			this->FTextBox->Name = L"FTextBox";
			this->FTextBox->ReadOnly = true;
			this->FTextBox->Size = System::Drawing::Size(93, 20);
			this->FTextBox->TabIndex = 36;
			this->FTextBox->Text = L"+000.0000";
			this->FTextBox->WordWrap = false;
			// 
			// CenterRATextBox
			// 
			this->CenterRATextBox->BackColor = System::Drawing::Color::White;
			this->CenterRATextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterRATextBox->Location = System::Drawing::Point(203, 93);
			this->CenterRATextBox->Name = L"CenterRATextBox";
			this->CenterRATextBox->ReadOnly = true;
			this->CenterRATextBox->Size = System::Drawing::Size(80, 20);
			this->CenterRATextBox->TabIndex = 37;
			this->CenterRATextBox->Text = L" 00:00:00.0";
			this->CenterRATextBox->WordWrap = false;
			// 
			// CenterDECTextBox
			// 
			this->CenterDECTextBox->BackColor = System::Drawing::Color::White;
			this->CenterDECTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterDECTextBox->Location = System::Drawing::Point(341, 93);
			this->CenterDECTextBox->Name = L"CenterDECTextBox";
			this->CenterDECTextBox->ReadOnly = true;
			this->CenterDECTextBox->Size = System::Drawing::Size(93, 20);
			this->CenterDECTextBox->TabIndex = 38;
			this->CenterDECTextBox->Text = L" 00:00:00.0";
			this->CenterDECTextBox->WordWrap = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel6);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(728, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(291, 142);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Selected Object";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 4;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				17.66917F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				31.95489F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.92481F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				31.20301F)));
			this->tableLayoutPanel6->Controls->Add(this->ObjectMagTextBox, 1, 2);
			this->tableLayoutPanel6->Controls->Add(this->label16, 0, 2);
			this->tableLayoutPanel6->Controls->Add(this->ObjectDECTextBox, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->label17, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->ObjectRATextBox, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->label19, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->label20, 2, 1);
			this->tableLayoutPanel6->Controls->Add(this->label21, 2, 2);
			this->tableLayoutPanel6->Controls->Add(this->label22, 2, 3);
			this->tableLayoutPanel6->Controls->Add(this->ObjectXTextBox, 3, 0);
			this->tableLayoutPanel6->Controls->Add(this->ObjectYTextBox, 3, 1);
			this->tableLayoutPanel6->Controls->Add(this->ObjectMaxTextBox, 3, 2);
			this->tableLayoutPanel6->Controls->Add(this->ObjectFWHMTextBox, 3, 3);
			this->tableLayoutPanel6->Controls->Add(this->label18, 0, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 4;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(285, 123);
			this->tableLayoutPanel6->TabIndex = 1;
			// 
			// ObjectMagTextBox
			// 
			this->ObjectMagTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectMagTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectMagTextBox->Location = System::Drawing::Point(52, 65);
			this->ObjectMagTextBox->Name = L"ObjectMagTextBox";
			this->ObjectMagTextBox->ReadOnly = true;
			this->ObjectMagTextBox->Size = System::Drawing::Size(35, 20);
			this->ObjectMagTextBox->TabIndex = 21;
			this->ObjectMagTextBox->Text = L"99.999+/-9.999";
			this->ObjectMagTextBox->WordWrap = false;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(15, 68);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 13);
			this->label16->TabIndex = 20;
			this->label16->Text = L"Mag:";
			// 
			// ObjectDECTextBox
			// 
			this->ObjectDECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectDECTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectDECTextBox->Location = System::Drawing::Point(52, 35);
			this->ObjectDECTextBox->Name = L"ObjectDECTextBox";
			this->ObjectDECTextBox->ReadOnly = true;
			this->ObjectDECTextBox->Size = System::Drawing::Size(35, 20);
			this->ObjectDECTextBox->TabIndex = 19;
			this->ObjectDECTextBox->Text = L" 00:00:00.0";
			this->ObjectDECTextBox->WordWrap = false;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(14, 38);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(32, 13);
			this->label17->TabIndex = 18;
			this->label17->Text = L"DEC:";
			// 
			// ObjectRATextBox
			// 
			this->ObjectRATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectRATextBox->BackColor = System::Drawing::Color::White;
			this->ObjectRATextBox->Location = System::Drawing::Point(52, 5);
			this->ObjectRATextBox->Name = L"ObjectRATextBox";
			this->ObjectRATextBox->ReadOnly = true;
			this->ObjectRATextBox->Size = System::Drawing::Size(35, 20);
			this->ObjectRATextBox->TabIndex = 17;
			this->ObjectRATextBox->Text = L" 00:00:00.0";
			this->ObjectRATextBox->WordWrap = false;
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(175, 8);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(17, 13);
			this->label19->TabIndex = 22;
			this->label19->Text = L"X:";
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(175, 38);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(17, 13);
			this->label20->TabIndex = 23;
			this->label20->Text = L"Y:";
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(162, 68);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(30, 13);
			this->label21->TabIndex = 24;
			this->label21->Text = L"Max:";
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(148, 100);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(44, 13);
			this->label22->TabIndex = 25;
			this->label22->Text = L"FWHM:";
			// 
			// ObjectXTextBox
			// 
			this->ObjectXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectXTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectXTextBox->Location = System::Drawing::Point(198, 5);
			this->ObjectXTextBox->Name = L"ObjectXTextBox";
			this->ObjectXTextBox->ReadOnly = true;
			this->ObjectXTextBox->Size = System::Drawing::Size(36, 20);
			this->ObjectXTextBox->TabIndex = 26;
			this->ObjectXTextBox->Text = L" 0000.00";
			this->ObjectXTextBox->WordWrap = false;
			// 
			// ObjectYTextBox
			// 
			this->ObjectYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectYTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectYTextBox->Location = System::Drawing::Point(198, 35);
			this->ObjectYTextBox->Name = L"ObjectYTextBox";
			this->ObjectYTextBox->ReadOnly = true;
			this->ObjectYTextBox->Size = System::Drawing::Size(36, 20);
			this->ObjectYTextBox->TabIndex = 27;
			this->ObjectYTextBox->Text = L" 0000.00";
			this->ObjectYTextBox->WordWrap = false;
			// 
			// ObjectMaxTextBox
			// 
			this->ObjectMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectMaxTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectMaxTextBox->Location = System::Drawing::Point(198, 65);
			this->ObjectMaxTextBox->Name = L"ObjectMaxTextBox";
			this->ObjectMaxTextBox->ReadOnly = true;
			this->ObjectMaxTextBox->Size = System::Drawing::Size(36, 20);
			this->ObjectMaxTextBox->TabIndex = 28;
			this->ObjectMaxTextBox->Text = L"0000000";
			this->ObjectMaxTextBox->WordWrap = false;
			// 
			// ObjectFWHMTextBox
			// 
			this->ObjectFWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectFWHMTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectFWHMTextBox->Location = System::Drawing::Point(198, 96);
			this->ObjectFWHMTextBox->Name = L"ObjectFWHMTextBox";
			this->ObjectFWHMTextBox->ReadOnly = true;
			this->ObjectFWHMTextBox->Size = System::Drawing::Size(36, 20);
			this->ObjectFWHMTextBox->TabIndex = 29;
			this->ObjectFWHMTextBox->Text = L"00.000";
			this->ObjectFWHMTextBox->WordWrap = false;
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(21, 8);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(25, 13);
			this->label18->TabIndex = 15;
			this->label18->Text = L"RA:";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 1;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->Controls->Add(this->groupBox4, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->FlipVerticalCheckBox, 0, 1);
			this->tableLayoutPanel8->Controls->Add(this->FlipHorizontalCheckBox, 0, 2);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(584, 3);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 3;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 66.32653F)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.67347F)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(138, 142);
			this->tableLayoutPanel8->TabIndex = 3;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->tableLayoutPanel7);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(132, 64);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Current Position";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.42424F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.57576F)));
			this->tableLayoutPanel7->Controls->Add(this->label24, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->CurrentRATextBox, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->label23, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->CurrentDECTextBox, 1, 1);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(126, 45);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// label24
			// 
			this->label24->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(18, 27);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(32, 13);
			this->label24->TabIndex = 21;
			this->label24->Text = L"DEC:";
			// 
			// CurrentRATextBox
			// 
			this->CurrentRATextBox->BackColor = System::Drawing::Color::White;
			this->CurrentRATextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CurrentRATextBox->Location = System::Drawing::Point(56, 3);
			this->CurrentRATextBox->Name = L"CurrentRATextBox";
			this->CurrentRATextBox->ReadOnly = true;
			this->CurrentRATextBox->Size = System::Drawing::Size(67, 20);
			this->CurrentRATextBox->TabIndex = 18;
			this->CurrentRATextBox->Text = L" 00:00:00.0";
			this->CurrentRATextBox->WordWrap = false;
			// 
			// label23
			// 
			this->label23->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(25, 4);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(25, 13);
			this->label23->TabIndex = 19;
			this->label23->Text = L"RA:";
			// 
			// CurrentDECTextBox
			// 
			this->CurrentDECTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentDECTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CurrentDECTextBox->Location = System::Drawing::Point(56, 25);
			this->CurrentDECTextBox->Name = L"CurrentDECTextBox";
			this->CurrentDECTextBox->ReadOnly = true;
			this->CurrentDECTextBox->Size = System::Drawing::Size(67, 20);
			this->CurrentDECTextBox->TabIndex = 20;
			this->CurrentDECTextBox->Text = L" 00:00:00.0";
			this->CurrentDECTextBox->WordWrap = false;
			// 
			// FlipVerticalCheckBox
			// 
			this->FlipVerticalCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FlipVerticalCheckBox->AutoSize = true;
			this->FlipVerticalCheckBox->Location = System::Drawing::Point(29, 79);
			this->FlipVerticalCheckBox->Name = L"FlipVerticalCheckBox";
			this->FlipVerticalCheckBox->Size = System::Drawing::Size(80, 17);
			this->FlipVerticalCheckBox->TabIndex = 4;
			this->FlipVerticalCheckBox->Text = L"Flip Vertical";
			this->FlipVerticalCheckBox->UseVisualStyleBackColor = true;
			this->FlipVerticalCheckBox->CheckedChanged += gcnew System::EventHandler(this, &AstrometryWindow::FlipVerticalCheckBox_Changed);
			// 
			// FlipHorizontalCheckBox
			// 
			this->FlipHorizontalCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FlipHorizontalCheckBox->AutoSize = true;
			this->FlipHorizontalCheckBox->Location = System::Drawing::Point(23, 115);
			this->FlipHorizontalCheckBox->Name = L"FlipHorizontalCheckBox";
			this->FlipHorizontalCheckBox->Size = System::Drawing::Size(92, 17);
			this->FlipHorizontalCheckBox->TabIndex = 5;
			this->FlipHorizontalCheckBox->Text = L"Flip Horizontal";
			this->FlipHorizontalCheckBox->UseVisualStyleBackColor = true;
			this->FlipHorizontalCheckBox->CheckedChanged += gcnew System::EventHandler(this, &AstrometryWindow::FlipHorizontalCheckBox_Changed);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->closeToolStripMenuItem,
					this->initializeSettingsToolStripMenuItem, this->computeSolutionToolStripMenuItem, this->matchToolStripMenuItem, this->unMatchToolStripMenuItem,
					this->resetStarsToolStripMenuItem, this->clearMarkedStarsToolStripMenuItem, this->assignPreviousToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1028, 27);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::CloseMenuItem_Clicked);
			// 
			// initializeSettingsToolStripMenuItem
			// 
			this->initializeSettingsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->initializeSettingsToolStripMenuItem->Name = L"initializeSettingsToolStripMenuItem";
			this->initializeSettingsToolStripMenuItem->Size = System::Drawing::Size(146, 23);
			this->initializeSettingsToolStripMenuItem->Text = L"Initialize Settings";
			this->initializeSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::InitializeSettingsMenuItem_Clicked);
			// 
			// computeSolutionToolStripMenuItem
			// 
			this->computeSolutionToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->computeSolutionToolStripMenuItem->Name = L"computeSolutionToolStripMenuItem";
			this->computeSolutionToolStripMenuItem->Size = System::Drawing::Size(136, 23);
			this->computeSolutionToolStripMenuItem->Text = L"Compute Solution";
			this->computeSolutionToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::ComputeSolutionMenuItem_Clicked);
			// 
			// matchToolStripMenuItem
			// 
			this->matchToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->matchToolStripMenuItem->Name = L"matchToolStripMenuItem";
			this->matchToolStripMenuItem->Size = System::Drawing::Size(63, 23);
			this->matchToolStripMenuItem->Text = L"Match";
			this->matchToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::MatchMenuItem_Clicked);
			// 
			// unMatchToolStripMenuItem
			// 
			this->unMatchToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->unMatchToolStripMenuItem->Name = L"unMatchToolStripMenuItem";
			this->unMatchToolStripMenuItem->Size = System::Drawing::Size(80, 23);
			this->unMatchToolStripMenuItem->Text = L"UnMatch";
			this->unMatchToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::UnMatchMenuItem_Clicked);
			// 
			// resetStarsToolStripMenuItem
			// 
			this->resetStarsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resetStarsToolStripMenuItem->Name = L"resetStarsToolStripMenuItem";
			this->resetStarsToolStripMenuItem->Size = System::Drawing::Size(105, 23);
			this->resetStarsToolStripMenuItem->Text = L"Reset Stars";
			this->resetStarsToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::ResetStarsMenuItem_Clicked);
			// 
			// clearMarkedStarsToolStripMenuItem
			// 
			this->clearMarkedStarsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->clearMarkedStarsToolStripMenuItem->Name = L"clearMarkedStarsToolStripMenuItem";
			this->clearMarkedStarsToolStripMenuItem->Size = System::Drawing::Size(159, 23);
			this->clearMarkedStarsToolStripMenuItem->Text = L"Clear Marked Stars";
			this->clearMarkedStarsToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::ClearMarkedStarsMenuItem_Clicked);
			// 
			// assignPreviousToolStripMenuItem
			// 
			this->assignPreviousToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->assignPreviousToolStripMenuItem->Name = L"assignPreviousToolStripMenuItem";
			this->assignPreviousToolStripMenuItem->Size = System::Drawing::Size(123, 23);
			this->assignPreviousToolStripMenuItem->Text = L"Assign Previous";
			this->assignPreviousToolStripMenuItem->Click += gcnew System::EventHandler(this, &AstrometryWindow::AssignPreviousMenuItem_Clicked);
			// 
			// AstrometryWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 708);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AstrometryWindow";
			this->Text = L"AstrometryWindow";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChartPictureBox))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImagePictureBox))->EndInit();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: void ClosingEventHandler(Object^ sender, System::Windows::Forms::FormClosingEventArgs ^e) {

			 MARKSTAR *sptr, *next;

			 if (! AstrometryWindowCloseButtonClicked) {
				   e->Cancel = true;
				   return;
			 }
			 sptr = AstrometryWindow::FormPtr->MarkedStarList;
			 while (sptr != NULL) {
				next = sptr->next;
				free(sptr);
				sptr = next;
			 }
		   }
private: System::Void MouseClickHandler(Object^ sender,System::Windows::Forms::MouseEventArgs^ e ) {

			 int xmin, ymin, xmax, ymax, hours, degs, mins;
			 float Magnitude, MagErr, SkyFlux, StarFlux, FWHM, x, y, secs;
			 double ra, dec;
			 int max, Found, frameX, frameY;
			 char buffer[80];
			 FRAME *light;

			 light = &this->imagePtr->light_frame;
			 PictureToFrame(e->X, e->Y, &frameX, &frameY, light);
			 if (e->Button == ::MouseButtons::Left) {
			 } else if (e->Button == ::MouseButtons::Right) {
				 xmin = (int) (frameX - photometrySettings.findRadius);
				 if (xmin < 0)
					 xmin = 0;
				 ymin = (int) (frameY - photometrySettings.findRadius);
				 if (ymin < 0)
					 ymin = 0;
				 xmax = (int) (frameX + photometrySettings.findRadius);
				 if (xmax > light->w)
					 xmax = light->w;
				 ymax = (int) (frameY + photometrySettings.findRadius);
				 if (ymax > light->h)
					 ymax = light->h;
				 Found = FindStar(light, xmin, ymin, xmax, ymax, &x, &y, &max);
				 if (Found) {
					 sprintf_s(buffer, sizeof(buffer), "%f", x);
					 AstrometryWindow::SetObjectXTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%f", y);
					 AstrometryWindow::SetObjectYTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%d", max);
					 AstrometryWindow::SetObjectMaxTextBox(buffer);
					 doPhotometry(this->imagePtr, ASTROMETRYWINDOW, x, y, max, false, &FWHM, &SkyFlux, &StarFlux,
								  &Magnitude, &MagErr);
				 }
				 if (plateSolution.status == 0) {
					 Pixel2Equatorial((double) x, (double) y, &ra, &dec);
					 ConvertRAtoHMS(ra, &hours, &mins, &secs);
					 sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.2f", hours, mins, secs);
					 AstrometryWindow::FormPtr->SetObjectRATextBox(buffer);
					 ConvertDECtoDMS(dec, &degs, &mins, &secs);
					 sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.2f", degs, mins, secs);
					 AstrometryWindow::FormPtr->SetObjectDECTextBox(buffer);
				 }
			 }
		 }

private: System::Void PictureToFrame(int pictX, int pictY, int *frameX, int *frameY, FRAME *light) {

			if (this->FlipVerticalCheckBox->Checked)
				*frameY = pictY;
			else
				*frameY = light->h - pictY;
			
			if (this->FlipHorizontalCheckBox->Checked)
				*frameX = light->w - pictX;
			else
				*frameX = pictX;
}

private: System::Void FrameToPicture(int frameX, int frameY, int *pictX, int *pictY, FRAME *light) {

	if (this->FlipVerticalCheckBox->Checked)
		*pictY = frameY;
	else
		*pictY = light->h - frameY;

	if (this->FlipHorizontalCheckBox->Checked)
		*pictX = light->w - frameX;
	else
		*pictX = frameX;

}

private: System::Void MouseDoubleClickHandler(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int xmin, ymin, xmax, ymax;
			 float x, y;
			 int max, Found, frameX, frameY;
			 FRAME *light;

			 light = &this->imagePtr->light_frame;
			 PictureToFrame(e->X, e->Y, &frameX, &frameY, light);

			 if (e->Button == ::MouseButtons::Left) {
			 } else if (e->Button == ::MouseButtons::Right) {
				 xmin = (int) (frameX - photometrySettings.findRadius);
				 if (xmin < 0)
					 xmin = 0;
				 ymin = (int) (frameY - photometrySettings.findRadius);
				 if (ymin < 0)
					 ymin = 0;
				 xmax = (int) (frameX + photometrySettings.findRadius);
				 if (xmax > light->w)
					 xmax = light->w;
				 ymax = (int) (frameY + photometrySettings.findRadius);
				 if (ymax > light->h)
					 ymax = light->h;
				 Found = FindStar(light, xmin, ymin, xmax, ymax, &x, &y, &max);
				 if (Found) {
					 AstrometryWindow::UnmarkStar(x,y);
				 }
			 }
		 }
private: System::Void MouseMoveHandler(Object^ sender,System::Windows::Forms::MouseEventArgs^ e ) {

	     char buffer[80];
		 int hours, degs, mins, frameX, frameY;
		 double ra, dec;
		 float secs;
		 FRAME *light;
		 
		 light = &this->imagePtr->light_frame;
		 PictureToFrame(e->X, e->Y, &frameX, &frameY, light);

		 if (plateSolution.status == 0) {
			 Pixel2Equatorial((double) frameX, (double) frameY, &ra, &dec);
			 ConvertRAtoHMS(ra, &hours, &mins, &secs);
			 sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.2f", hours, mins, secs);
			 AstrometryWindow::FormPtr->SetCurrentRATextBox(buffer);
			 ConvertDECtoDMS(dec, &degs, &mins, &secs);
			 sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.2f", degs, mins, secs);
			 AstrometryWindow::FormPtr->SetCurrentDECTextBox(buffer);
		 }
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
			sptr = AstrometryWindow::MarkedStarList;
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
				AstrometryWindow::MarkedStarList = newptr;
			} else {
				prev->next = newptr;
			}
			AstrometryWindow::FormPtr->Refresh();
			return;
		}
public: static void UnmarkStar(float x, float y) {

			MARKSTAR *sptr, *head, *prev;

			sptr = head = AstrometryWindow::MarkedStarList;
			prev = NULL;
			while (sptr != NULL) {
				if ((fabs(sptr->x-x)<1.0) && (fabs(sptr->y-y)<1.0)) {
					if (prev == NULL)
						AstrometryWindow::MarkedStarList = sptr->next;
					else
						prev->next = sptr->next;
					free(sptr);
					AstrometryWindow::FormPtr->Refresh();
					return;
				} else {
					prev = sptr;
					sptr = sptr->next;
				}
			}
			return;
		}
private: void PaintHandler( Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

			 MARKSTAR *sptr;
			 int x1, y1, x2, y2, starX, starY, h, w, i, starNum;
			 float AperRad, SkyInnerRad, SkyOuterRad;
			 char text[80];
			 FRAME *light;

			 light = &this->imagePtr->light_frame;
			 AperRad = photometrySettings.aperatureRadius;
			 SkyInnerRad = photometrySettings.skyInnerRadius;
			 SkyOuterRad = photometrySettings.skyOuterRadius;
			 sptr = AstrometryWindow::MarkedStarList;
			 starNum = 0;
			 while (sptr != NULL) {
				 FrameToPicture((int)Math::Round(sptr->x), (int)Math::Round(sptr->y), &starX, &starY, light);
				 FrameToPicture((int)Math::Round(sptr->x-5.0), (int)Math::Round(sptr->y-5.0), &x1, &y1, light);
				 FrameToPicture((int)Math::Round(sptr->x+5.0), (int)Math::Round(sptr->y+5.0), &x2, &y2, light);
				 e->Graphics->DrawLine(System::Drawing::Pens::Red,starX,y1,starX,y2);
				 e->Graphics->DrawLine(System::Drawing::Pens::Red,x1,starY,x2,starY);
				 FrameToPicture((int) sptr->x, (int) sptr->y, &x1, &y1, light);
				 x1 = (int) Math::Round(x1-AperRad);
				 y1 = (int) Math::Round(y1-AperRad);
				 h = w = (int) (2.0*AperRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 FrameToPicture((int) sptr->x, (int) sptr->y, &x1, &y1, light);
				 x1 = (int)Math::Round(x1 - SkyInnerRad);
				 y1 = (int)Math::Round(y1 - SkyInnerRad);
				 h = w = (int) (2.0*SkyInnerRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 FrameToPicture((int) sptr->x, (int) sptr->y, &x1, &y1, light);
				 x1 = (int)Math::Round(x1 - SkyOuterRad);
				 y1 = (int)Math::Round(y1 - SkyOuterRad);
				 h = w = (int) (2.0*SkyOuterRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 //sprintf_s(text, sizeof(text), "%d", starNum);
				 //String ^buffer;
				 //buffer = gcnew String(text);
				 //e->Graphics->DrawString(buffer, this->Font, System::Drawing::Brushes::Red,
					// ((float) (starX+5)), ((float) (starY+5)));
				 //delete buffer;
				 sptr = sptr->next;
				 starNum++;
			 }
			 for (i=0; i<plateStars.numStars; i++) {
				 starX = ((int) (plateStars.pixelX[i]));
				 starY = ((int) ( plateStars.pixelY[i]));
				 FrameToPicture((int)plateStars.pixelX[i], (int)plateStars.pixelY[i], &starX, &starY, light);
				 sprintf_s(text, sizeof(text), "%d", i+1);
				 String ^buffer;
				 buffer = gcnew String(text);
				 e->Graphics->DrawString(buffer, this->Font, System::Drawing::Brushes::Red,
					 ((float) (starX+5)), ((float) (starY+5)));
				 delete buffer;
			 }
			 return;
		 }

public: void ShowTheWindow(void) {

			AstrometryWindow::Show();
		}
private: System::Void CloseMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 
			 AstrometryWindowCloseButtonClicked = true;
			 AstrometryWindow::Hide();
		 }
private: System::Void InitializeSettingsMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int i;

			 ShowInitializeAstrometryDialog();
			 if (InitializeAstrometryDialog::FormPtr->InitializeCancelled)
				 return;
			 plateSolution.status = -1;
			 for (i=0; i<6; i++) plateSolution.coeffs[i] = 0.0;
			 AstrometryWindow::FormPtr->SetSolutionStatusTextBox("Inited");
			 AstrometryWindow::FormPtr->SetATextBox("unknown");
			 AstrometryWindow::FormPtr->SetBTextBox("unknown");
			 AstrometryWindow::FormPtr->SetCTextBox("unknown");
			 AstrometryWindow::FormPtr->SetDTextBox("unknown");
			 AstrometryWindow::FormPtr->SetETextBox("unknown");
			 AstrometryWindow::FormPtr->SetFTextBox("unknown");
			 AstrometryWindow::FormPtr->SetEstErrorTextBox("unknown");
			 AstrometryWindow::FormPtr->SetCenterRATextBox("unknown");
			 AstrometryWindow::FormPtr->SetCenterDECTextBox("unknown");
			 plateStars.numStars = 0;
			 refStars.numStars = 0;
			 loadRefChartAstrometry(this->imagePtr);
		 }

public: static void SetObjectMaxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectMaxTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetObjectXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetObjectXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->ObjectXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetObjectYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetObjectYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->ObjectYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetObjectRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectRATextBox->Text = buffer;
		delete buffer;
		}

public: static void SetObjectDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectDECTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetObjectFWHMTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectFWHMTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetObjectMagTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectMagTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetObjectMagTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->ObjectMagTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetSelectedStarRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->SelectedStarRATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSelectedStarRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->SelectedStarRATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetSelectedStarDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->SelectedStarDECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSelectedStarDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->SelectedStarDECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetSelectedStarMagTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->SelectedStarMagTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSelectedStarMagTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->SelectedStarMagTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetNumStarsTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->NumStarsTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetNumStarsTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->NumStarsTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetSolutionStatusTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->SolutionStatusTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSolutionStatusTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->SolutionStatusTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetScaleTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ScaleTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetScaleTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->ScaleTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->ATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetBTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->BTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetBTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->BTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->CTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->CTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetDTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->DTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->DTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetETextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ETextBox->Text = buffer;
		delete buffer;
		}
public: static void GetETextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->ETextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->FTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->FTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCenterRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->CenterRATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCenterRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->CenterRATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCenterDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->CenterDECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCenterDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->CenterDECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->CurrentRATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->CurrentRATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->CurrentDECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->CurrentDECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetEstErrorTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->EstErrorTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetEstErrorTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AstrometryWindow::FormPtr->EstErrorTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
private: System::Void ChartMouseClickHandler(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 char buffer[80];
			 double delx, dely, dist;
			 int i, hours, degs, mins;
			 float secs;

			 // If left button clicked, do nothing

			 if (e->Button == ::MouseButtons::Left) {

			 // If right button clicked, mark reference star

			 } else if (e->Button == ::MouseButtons::Right) {
				 for (i=0; i<refStars.numStars; i++) {
					delx = e->X - refStars.x[i];
					dely = e->Y - refStars.y[i];
					dist = delx*delx + dely*dely;
					if (dist > 0.0) dist = Math::Sqrt(dist);
					if (dist < 5.0)
						break;
				 }
				 if (dist < 5.0) {
					 ConvertRAtoHMS(refStars.RA[i], &hours, &mins, &secs);
					 sprintf_s(buffer, sizeof(buffer), "%02d:%02d:%04.2f", hours, mins, secs);
					 AstrometryWindow::SetSelectedStarRATextBox(buffer);
					 ConvertDECtoDMS(refStars.DEC[i], &degs, &mins, &secs);
					 sprintf_s(buffer, sizeof(buffer), "%03d:%02d:%04.2f", degs, mins, secs);
					 AstrometryWindow::SetSelectedStarDECTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%f", refStars.Mag[i]);
					 AstrometryWindow::SetSelectedStarMagTextBox(buffer);
					 refStars.Marked[i] = true;
				 }
			 }
			 AstrometryWindow::FormPtr->Refresh();
		 }

private: void ChartPaintHandler( Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

			 int x1, y1, x2, y2, starX, starY, h, w, i, r, delYear, imageYear;
			 double minMag, maxMag;
			 double magScale, mag, ra, dec;
			 char text[80];
			 double CenterRA, CenterDEC, PixelScale;
			 double MinRA, MaxRA, MinDEC, MaxDEC, FieldWidthHours, FieldHeightDegs;
			 int fullw, fullh, pictboxfullw, pictboxfullh;

			 // Get "rough" RA & DEC of image center

			 if (plateSolution.status != 0) {
				 CenterRA = this->imagePtr->plateSolution.InitFieldCenterRA;
				 CenterDEC = this->imagePtr->plateSolution.InitFieldCenterDEC;
				 PixelScale = this->imagePtr->plateSolution.PixelScale;
			 }
			 else {
				 CenterRA = this->imagePtr->plateSolution.FieldCenterRA;
				 CenterDEC = this->imagePtr->plateSolution.FieldCenterDEC;
				 PixelScale = this->imagePtr->plateSolution.PixelScale;
			 }
			 fullw = this->imagePtr->light_frame.w;
			 fullh = this->imagePtr->light_frame.h;
			 FieldWidthHours = PixelScale*fullw / 3600.0 / 15.0 / Math::Cos(CenterDEC*DEG2RAD);
			 FieldHeightDegs = PixelScale*fullh / 3600.0;
			 MinRA = CenterRA - FieldWidthHours / 2.0;
			 if (MinRA < 0.0) MinRA += 24.0;
			 if (MinRA > 24.0) MinRA -= 24.0;
			 MaxRA = MinRA + FieldWidthHours;
			 if (MaxRA > 24.0) MaxRA -= 24.0;
			 MinDEC = CenterDEC - FieldHeightDegs / 2.0;
			 if (MinDEC < -90.0) MinDEC = -90.0;
			 if (MinDEC > 90.0) MinDEC = 90.0;
			 MaxDEC = MinDEC + FieldHeightDegs;
			 if (MaxDEC > 90.0) MaxDEC = 90.0;
			 if (MinDEC >= MaxDEC) MinDEC = MaxDEC - FieldHeightDegs;

			 // Update reference stars chart positions

			 pictboxfullw = AstrometryWindow::FormPtr->ChartPictureBox->Size.Width;
			 pictboxfullh = AstrometryWindow::FormPtr->ChartPictureBox->Size.Height;
			 refStars.ChartXScale = FieldWidthHours / pictboxfullw;
			 refStars.ChartYScale = FieldHeightDegs / pictboxfullh;
			 refStars.ChartMinRA = MinRA;
			 refStars.ChartMinDEC = MinDEC;
			 sscanf_s(this->imagePtr->light_frame.UTDATE, "%4d", &imageYear);
			 delYear = imageYear - 2000;
			 for (i = 0; i < refStars.numStars; i++) {
				 ra = refStars.RA[i] + (refStars.ProperMotionRA[i] * delYear) / 3600.0 * 24.0 / 360.0;
				 dec = refStars.DEC[i] + (refStars.ProperMotionDEC[i] * delYear) / 3600.0;
				 refStars.x[i] = pictboxfullw - ((int)((ra - refStars.ChartMinRA) / refStars.ChartXScale));
				 refStars.y[i] = pictboxfullh - ((int)((dec - refStars.ChartMinDEC) / refStars.ChartYScale));
			 }

			 // Find range of magnitudes

			 minMag = 999.0;
			 maxMag = -999.0;
			 for (i = 0; i < refStars.numStars; i++) {
				 if (refStars.Mag[i] < minMag)
					 minMag = refStars.Mag[i];
				 if (refStars.Mag[i] > maxMag)
					 maxMag = refStars.Mag[i];
			 }
			 magScale = 10.0 / (maxMag - minMag);

			 // Plot stars and indicate if they are marked

			 for (i=0; i<refStars.numStars; i++) {
				 starX = refStars.x[i];
				 starY = refStars.y[i];
				 h = w = (int) (magScale*(maxMag - refStars.Mag[i])) + 1;
				 if (h < 1) h = w = 1;
				 if (h > 10) h = w = 10;
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Black,starX-w/2,starY-h/2,h,w);
				 if (refStars.Marked[i]) {
					 x1 = (int) Math::Round(starX - 5.0);
					 y1 = (int) Math::Round(starY - 5.0);
					 x2 = (int) Math::Round(starX + 5.0);
					 y2 = (int) Math::Round(starY + 5.0);
					 e->Graphics->DrawLine(System::Drawing::Pens::Red,starX,y1,starX,y2);
					 e->Graphics->DrawLine(System::Drawing::Pens::Red,x1,starY,x2,starY);
				 }
			 }

			 // Draw legend of star magnitudes

			 x1 = (int) (AstrometryWindow::FormPtr->ChartPictureBox->Size.Width*0.8);
			 y1 = (int) (AstrometryWindow::FormPtr->ChartPictureBox->Size.Height*0.925);
			 h = (int) (AstrometryWindow::FormPtr->ChartPictureBox->Size.Height*0.075);
			 w = (int) (AstrometryWindow::FormPtr->ChartPictureBox->Size.Width*0.2);
			 e->Graphics->DrawRectangle(System::Drawing::Pens::Green, x1, y1, w, h);

			 for (i = 1; i <= 5; i++) {
				 starX = (int) (x1 + 0.2*i*w - 0.1*w);
				 starY = (int) (y1 + 0.25*h);
				 mag = maxMag - 0.2*(i-1)*(maxMag-minMag);
				 r = (int)(magScale*(maxMag - mag)) + 1;
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Green, starX-r/2, starY-r/2, r, r);
				 sprintf_s(text, sizeof(text), "%5.1f", mag);
				 String ^buffer;
				 buffer = gcnew String(text);
				 e->Graphics->DrawString(buffer, this->Font, System::Drawing::Brushes::Green,
					 ((float)(starX-0.1*w)),
					 ((float)(starY + 0.1*h)));
				 delete buffer;
			 }

			 // Indicate which stars used in plate solution

			 for (i=0; i<plateStars.numStars; i++) {
				 starX = AstrometryWindow::FormPtr->ChartPictureBox->Size.Width -
					 ((int) ((plateStars.RA[i] - (refStars.ChartMinRA-0.001))/refStars.ChartXScale));
				 starY = AstrometryWindow::FormPtr->ChartPictureBox->Size.Height -
					 ((int)((plateStars.DEC[i] - refStars.ChartMinDEC) / refStars.ChartYScale));
				 sprintf_s(text, sizeof(text), "%d", i+1);
				 String ^buffer;
				 buffer = gcnew String(text);
				 e->Graphics->DrawString(buffer, this->Font, System::Drawing::Brushes::Red,
					 ((float) (starX+5)), ((float) (starY+5)));
				 delete buffer;
			 }
			 return;
		 }

private: System::Void MatchMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int i, hours, degs, mins;
			 char buffer[80];
			 MARKSTAR *sptr;
			 double ra, dec, x, y, mag;
			 float secs;
			 FRAME *light;

			 light = &this->imagePtr->light_frame;
			 AstrometryWindow::FormPtr->GetSelectedStarRATextBox(buffer);
			 sscanf_s(buffer, "%d:%d:%f", &hours, &mins, &secs);
			 ConvertHMStoRA(hours, mins, secs, &ra);
			 AstrometryWindow::FormPtr->GetSelectedStarDECTextBox(buffer);
			 sscanf_s(buffer, "%d:%d:%f", &degs, &mins, &secs);
			 ConvertDMStoDEC(degs, mins, secs, &dec);
			 AstrometryWindow::FormPtr->GetObjectXTextBox(buffer);
			 sscanf_s(buffer, "%lf", &x);
			 AstrometryWindow::FormPtr->GetObjectYTextBox(buffer);
			 sscanf_s(buffer, "%lf", &y);
			 AstrometryWindow::FormPtr->GetSelectedStarMagTextBox(buffer);
			 sscanf_s(buffer, "%lf", &mag);
			 for (i=0; i<refStars.numStars; i++) {
				 if ((ra == refStars.RA[i]) && (dec == refStars.DEC[i])) {
					 MessageBox("Reference star already used, pick another star", OKAY, true);
					 return;
				 }
			 }
			 sptr = AstrometryWindow::MarkedStarList;
			 while (sptr != NULL) {
				 if ((sptr->x == x) || (sptr->y == y)) {
					 MessageBox("Marked Object already used, pick another object", OKAY, true);
					 return;
				 }
				 sptr = sptr->next;
			 }
			 i = plateStars.numStars;
			 plateStars.pixelX[i] = x;
			 plateStars.pixelY[i] = y;
			 plateStars.RA[i] = ra;
			 plateStars.DEC[i] = dec;
			 plateStars.Mag[i] = mag;
			 plateStars.numStars++;
			 sprintf_s(buffer, sizeof(buffer), "%d", plateStars.numStars);
			 AstrometryWindow::FormPtr->SetNumStarsTextBox(buffer);
			 AstrometryWindow::FormPtr->Refresh();
		 }
private: System::Void UnMatchMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 double ra, dec;
			 int i, j, nStars;
			 char buffer[80];

			 AstrometryWindow::GetSelectedStarRATextBox(buffer);
			 sscanf_s(buffer, "%lf", &ra);
			 AstrometryWindow::GetSelectedStarDECTextBox(buffer);
			 sscanf_s(buffer, "%lf", &dec);
			 nStars = plateStars.numStars;
			 for (i=0; i<nStars; i++) {
				 if ((ra == plateStars.RA[i]) && (dec == plateStars.DEC[i])) {
					 for (j=i+1; j<plateStars.numStars; j++) {
						 plateStars.RA[j-1] = plateStars.RA[j];
						 plateStars.DEC[j-1] = plateStars.DEC[j];
						 plateStars.Mag[j-1] = plateStars.Mag[j];
						 plateStars.pixelX[j-1] = plateStars.pixelX[j];
						 plateStars.pixelY[j-1] = plateStars.pixelY[j];
					 }
					 plateStars.numStars--;
				 }
			 }
			 AstrometryWindow::FormPtr->Refresh();
		 }
private: System::Void ComputeSolutionMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ComputePlateSolution(&plateSolution);
		 }
private: System::Void ResetStarsMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int answer;

			 answer = MessageBox("Sure you want to clear matched star list?", YESNO, true);
			 if (answer != YES)
				 return;

			 plateStars.numStars = 0;
			 AstrometryWindow::FormPtr->SetNumStarsTextBox("0");
		 }
private: System::Void ClearMarkedStarsMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 AstrometryWindow::FormPtr->ClearMarkedStarList();
			 AstrometryWindow::FormPtr->Refresh();
		 }
public: static void ClearMarkedStarList(void) {

			int i;
			MARKSTAR *sptr, *next;

			sptr = AstrometryWindow::MarkedStarList;
			while (sptr != NULL) {
				next = sptr->next;
				free(sptr);
				sptr = next;
			}
			AstrometryWindow::MarkedStarList = NULL;

			for (i=0; i<refStars.numStars; i++)
				refStars.Marked[i] = false;

			return;
		}

private: System::Void AssignPreviousMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int i, numUpdated, xmin, xmax, ymin, ymax, max;
			 float x, y, starX, starY, findRad;
			 bool Found;
			 char buffer[160];

			 if (plateSolution.status == 0) {
				 if (refStars.numStars > 0) {
					 if (plateStars.numStars > 0) {
						 numUpdated = 0;
						 findRad = photometrySettings.findRadius;
						 for (i=0; i<plateStars.numStars; i++) {
							 starX = (float) plateStars.pixelX[i];
							 starY = (float) plateStars.pixelY[i];
							 xmin = (int) Math::Round(starX - findRad);
							 xmax = (int) Math::Round(starX + findRad);
							 ymin = (int) Math::Round(starY - findRad);
							 ymax = (int) Math::Round(starY + findRad);
							 Found = FindStar(&this->imagePtr->light_frame, xmin, ymin, xmax, ymax, &x, &y, &max);
							 if (! Found) {
								 sprintf_s(buffer, sizeof(buffer), "*** WARNING - Can't find star #%d at (%7.2f,%7.2f)\n",
									 i, starX, starY);
								 Form1::StatusPrint(buffer);
							 } else if ((fabs(starX-x) > findRad) || (fabs(starY-y) > findRad)) {
								 sprintf_s(buffer, sizeof(buffer), "*** WARNING - Star #%d at (%7.2f,%7.2f) shifted by: "
									 " (%5.1f,%5.1f)\n",
									 i, starX, starY, (starX-x), (starY-y));
								 Form1::StatusPrint(buffer);
							 } else {
								 sprintf_s(buffer, sizeof(buffer),
									 "*** INFO - Updated position for star #%d is: (%7.2f,%7.2f)\n",
									 i, x, y);
								 Form1::StatusPrint(buffer);
								 plateStars.pixelX[i] = x;
								 plateStars.pixelY[i] = y;
								 numUpdated++;
							 }
						 }
						 if (numUpdated < 1) {
							 MessageBox("*** Warning - can't find at least 1 star to compute shifts.\n"
								 "              Plate Solution taken AS IS!\n", OKAY, true);
						 } else {
							 ComputePlateSolution(&plateSolution);
						 }
					 }
				 }
			 } else {
				 MessageBox("Don't have a solution to assign.", OKAY, true);
			 }
		 }

private: System::Void FlipVerticalCheckBox_Changed(System::Object^  sender, System::EventArgs^  e) {

		this->ImagePictureBox->Image->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipY);
		this->ImagePictureBox->Refresh();
}


private: System::Void FlipHorizontalCheckBox_Changed(System::Object^  sender, System::EventArgs^  e) {

	this->ImagePictureBox->Image->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipX);
	this->ImagePictureBox->Refresh();
}

public: static System::Void ClearFlippedCheckBoxes() {

	AstrometryWindow::FormPtr->FlipVerticalCheckBox->Checked = false;
	AstrometryWindow::FormPtr->FlipHorizontalCheckBox->Checked = false;
}


};
}
