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
		System::Windows::Forms::PictureBox^  RefStarPictureBox;
		System::Windows::Forms::PictureBox^  ImagePictureBox;
		System::Drawing::Bitmap^ ImageBitmap;
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
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  ObjectXTextBox;
	private: System::Windows::Forms::TextBox^  ObjectYTextBox;
	private: System::Windows::Forms::TextBox^  ObjectMaxTextBox;
	private: System::Windows::Forms::TextBox^  ObjectFWHMTextBox;
	private: System::Windows::Forms::TextBox^  ObjectMagTextBox;
	private: System::Windows::Forms::TextBox^  ObjectRATextBox;
	private: System::Windows::Forms::TextBox^  ObjectDECTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
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
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  SolutionStatusTextBox;
	private: System::Windows::Forms::TextBox^  NumStarsTextBox;
	private: System::Windows::Forms::TextBox^  ScaleTextBox;
	private: System::Windows::Forms::TextBox^  AtextBox;
	private: System::Windows::Forms::TextBox^  BTextBox;
	private: System::Windows::Forms::TextBox^  CTextBox;
	private: System::Windows::Forms::TextBox^  DTextBox;
	private: System::Windows::Forms::TextBox^  ETextBox;
	private: System::Windows::Forms::TextBox^  FTextBox;
	private: System::Windows::Forms::TextBox^  CenterRATextBox;
	private: System::Windows::Forms::TextBox^  CenterDECTextBox;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  ComputeSolutionButton;
	private: System::Windows::Forms::ToolStripButton^  ResetStarsButton;
	private: System::Windows::Forms::ToolStripButton^  CloseButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::ToolStripButton^  InitializeButton;

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
			this->RefStarPictureBox = (gcnew System::Windows::Forms::PictureBox());
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->SolutionStatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumStarsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ScaleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AtextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->ObjectXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectFWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->CloseButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ComputeSolutionButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ResetStarsButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->InitializeButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RefStarPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ImagePictureBox))->BeginInit();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->toolStrip1->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->toolStrip1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.494382F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 73.99679F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.66934F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(896, 623);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->RefStarPictureBox, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->ImagePictureBox, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 30);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 454)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(890, 454);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// RefStarPictureBox
			// 
			this->RefStarPictureBox->BackColor = System::Drawing::Color::White;
			this->RefStarPictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->RefStarPictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->RefStarPictureBox->Location = System::Drawing::Point(3, 3);
			this->RefStarPictureBox->MaximumSize = System::Drawing::Size(1024, 1024);
			this->RefStarPictureBox->MinimumSize = System::Drawing::Size(256, 256);
			this->RefStarPictureBox->Name = L"RefStarPictureBox";
			this->RefStarPictureBox->Size = System::Drawing::Size(512, 512);
			this->RefStarPictureBox->TabIndex = 3;
			this->RefStarPictureBox->TabStop = false;
			// 
			// ImagePictureBox
			// 
			this->ImagePictureBox->BackColor = System::Drawing::Color::White;
			this->ImagePictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ImagePictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ImagePictureBox->Location = System::Drawing::Point(448, 3);
			this->ImagePictureBox->MaximumSize = System::Drawing::Size(1024, 1024);
			this->ImagePictureBox->MinimumSize = System::Drawing::Size(256, 256);
			this->ImagePictureBox->Name = L"ImagePictureBox";
			this->ImagePictureBox->Size = System::Drawing::Size(512, 512);
			this->ImagePictureBox->TabIndex = 2;
			this->ImagePictureBox->TabStop = false;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				24.60674F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				44.04494F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				31.46067F)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 490);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 130)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(890, 130);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel4);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Selected Star";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
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
			this->tableLayoutPanel4->Size = System::Drawing::Size(194, 81);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// SelectedStarMagTextBox
			// 
			this->SelectedStarMagTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SelectedStarMagTextBox->BackColor = System::Drawing::Color::White;
			this->SelectedStarMagTextBox->Location = System::Drawing::Point(100, 57);
			this->SelectedStarMagTextBox->Name = L"SelectedStarMagTextBox";
			this->SelectedStarMagTextBox->ReadOnly = true;
			this->SelectedStarMagTextBox->Size = System::Drawing::Size(65, 20);
			this->SelectedStarMagTextBox->TabIndex = 21;
			this->SelectedStarMagTextBox->Text = L"99.999";
			this->SelectedStarMagTextBox->WordWrap = false;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(63, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Mag:";
			// 
			// SelectedStarDECTextBox
			// 
			this->SelectedStarDECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SelectedStarDECTextBox->BackColor = System::Drawing::Color::White;
			this->SelectedStarDECTextBox->Location = System::Drawing::Point(100, 30);
			this->SelectedStarDECTextBox->Name = L"SelectedStarDECTextBox";
			this->SelectedStarDECTextBox->ReadOnly = true;
			this->SelectedStarDECTextBox->Size = System::Drawing::Size(65, 20);
			this->SelectedStarDECTextBox->TabIndex = 19;
			this->SelectedStarDECTextBox->Text = L" 00:00:00.0";
			this->SelectedStarDECTextBox->WordWrap = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(62, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"DEC:";
			// 
			// SelectedStarRATextBox
			// 
			this->SelectedStarRATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SelectedStarRATextBox->BackColor = System::Drawing::Color::White;
			this->SelectedStarRATextBox->Location = System::Drawing::Point(100, 3);
			this->SelectedStarRATextBox->Name = L"SelectedStarRATextBox";
			this->SelectedStarRATextBox->ReadOnly = true;
			this->SelectedStarRATextBox->Size = System::Drawing::Size(65, 20);
			this->SelectedStarRATextBox->TabIndex = 17;
			this->SelectedStarRATextBox->Text = L" 00:00:00.0";
			this->SelectedStarRATextBox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(69, 7);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 13);
			this->label11->TabIndex = 15;
			this->label11->Text = L"RA:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel5);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(221, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(385, 124);
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
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->label5, 4, 0);
			this->tableLayoutPanel5->Controls->Add(this->label6, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label7, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->label8, 4, 1);
			this->tableLayoutPanel5->Controls->Add(this->label9, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label10, 2, 2);
			this->tableLayoutPanel5->Controls->Add(this->label12, 4, 2);
			this->tableLayoutPanel5->Controls->Add(this->label13, 1, 3);
			this->tableLayoutPanel5->Controls->Add(this->label14, 2, 3);
			this->tableLayoutPanel5->Controls->Add(this->label15, 4, 3);
			this->tableLayoutPanel5->Controls->Add(this->SolutionStatusTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->NumStarsTextBox, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->ScaleTextBox, 5, 0);
			this->tableLayoutPanel5->Controls->Add(this->AtextBox, 1, 1);
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(379, 105);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Status:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(126, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"# Stars:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(253, 6);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Scale:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(29, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"A:";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(153, 32);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"B:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(273, 32);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"C:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(28, 58);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(18, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"D:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(153, 58);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"E:";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(274, 58);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(16, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"F:";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(78, 85);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 13);
			this->label13->TabIndex = 25;
			this->label13->Text = L"Center:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(145, 85);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(25, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"RA:";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(258, 85);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 13);
			this->label15->TabIndex = 27;
			this->label15->Text = L"DEC:";
			// 
			// SolutionStatusTextBox
			// 
			this->SolutionStatusTextBox->BackColor = System::Drawing::Color::White;
			this->SolutionStatusTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SolutionStatusTextBox->Location = System::Drawing::Point(52, 3);
			this->SolutionStatusTextBox->Name = L"SolutionStatusTextBox";
			this->SolutionStatusTextBox->ReadOnly = true;
			this->SolutionStatusTextBox->Size = System::Drawing::Size(67, 20);
			this->SolutionStatusTextBox->TabIndex = 28;
			this->SolutionStatusTextBox->Text = L"None";
			this->SolutionStatusTextBox->WordWrap = false;
			// 
			// NumStarsTextBox
			// 
			this->NumStarsTextBox->BackColor = System::Drawing::Color::White;
			this->NumStarsTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NumStarsTextBox->Location = System::Drawing::Point(176, 3);
			this->NumStarsTextBox->Name = L"NumStarsTextBox";
			this->NumStarsTextBox->ReadOnly = true;
			this->NumStarsTextBox->Size = System::Drawing::Size(69, 20);
			this->NumStarsTextBox->TabIndex = 29;
			this->NumStarsTextBox->Text = L"000";
			this->NumStarsTextBox->WordWrap = false;
			// 
			// ScaleTextBox
			// 
			this->ScaleTextBox->BackColor = System::Drawing::Color::White;
			this->ScaleTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ScaleTextBox->Location = System::Drawing::Point(296, 3);
			this->ScaleTextBox->Name = L"ScaleTextBox";
			this->ScaleTextBox->ReadOnly = true;
			this->ScaleTextBox->Size = System::Drawing::Size(80, 20);
			this->ScaleTextBox->TabIndex = 30;
			this->ScaleTextBox->Text = L"0.000 \"/pixel";
			this->ScaleTextBox->WordWrap = false;
			// 
			// AtextBox
			// 
			this->AtextBox->BackColor = System::Drawing::Color::White;
			this->AtextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->AtextBox->Location = System::Drawing::Point(52, 29);
			this->AtextBox->Name = L"AtextBox";
			this->AtextBox->ReadOnly = true;
			this->AtextBox->Size = System::Drawing::Size(67, 20);
			this->AtextBox->TabIndex = 31;
			this->AtextBox->Text = L"+000.0000";
			this->AtextBox->WordWrap = false;
			// 
			// BTextBox
			// 
			this->BTextBox->BackColor = System::Drawing::Color::White;
			this->BTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->BTextBox->Location = System::Drawing::Point(176, 29);
			this->BTextBox->Name = L"BTextBox";
			this->BTextBox->ReadOnly = true;
			this->BTextBox->Size = System::Drawing::Size(69, 20);
			this->BTextBox->TabIndex = 32;
			this->BTextBox->Text = L"+000.0000";
			this->BTextBox->WordWrap = false;
			// 
			// CTextBox
			// 
			this->CTextBox->BackColor = System::Drawing::Color::White;
			this->CTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CTextBox->Location = System::Drawing::Point(296, 29);
			this->CTextBox->Name = L"CTextBox";
			this->CTextBox->ReadOnly = true;
			this->CTextBox->Size = System::Drawing::Size(80, 20);
			this->CTextBox->TabIndex = 33;
			this->CTextBox->Text = L"+000.0000";
			this->CTextBox->WordWrap = false;
			// 
			// DTextBox
			// 
			this->DTextBox->BackColor = System::Drawing::Color::White;
			this->DTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DTextBox->Location = System::Drawing::Point(52, 55);
			this->DTextBox->Name = L"DTextBox";
			this->DTextBox->ReadOnly = true;
			this->DTextBox->Size = System::Drawing::Size(67, 20);
			this->DTextBox->TabIndex = 34;
			this->DTextBox->Text = L"+000.0000";
			this->DTextBox->WordWrap = false;
			// 
			// ETextBox
			// 
			this->ETextBox->BackColor = System::Drawing::Color::White;
			this->ETextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ETextBox->Location = System::Drawing::Point(176, 55);
			this->ETextBox->Name = L"ETextBox";
			this->ETextBox->ReadOnly = true;
			this->ETextBox->Size = System::Drawing::Size(69, 20);
			this->ETextBox->TabIndex = 35;
			this->ETextBox->Text = L"+000.0000";
			this->ETextBox->WordWrap = false;
			// 
			// FTextBox
			// 
			this->FTextBox->BackColor = System::Drawing::Color::White;
			this->FTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FTextBox->Location = System::Drawing::Point(296, 55);
			this->FTextBox->Name = L"FTextBox";
			this->FTextBox->ReadOnly = true;
			this->FTextBox->Size = System::Drawing::Size(80, 20);
			this->FTextBox->TabIndex = 36;
			this->FTextBox->Text = L"+000.0000";
			this->FTextBox->WordWrap = false;
			// 
			// CenterRATextBox
			// 
			this->CenterRATextBox->BackColor = System::Drawing::Color::White;
			this->CenterRATextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterRATextBox->Location = System::Drawing::Point(176, 81);
			this->CenterRATextBox->Name = L"CenterRATextBox";
			this->CenterRATextBox->ReadOnly = true;
			this->CenterRATextBox->Size = System::Drawing::Size(69, 20);
			this->CenterRATextBox->TabIndex = 37;
			this->CenterRATextBox->Text = L" 00:00:00.0";
			this->CenterRATextBox->WordWrap = false;
			// 
			// CenterDECTextBox
			// 
			this->CenterDECTextBox->BackColor = System::Drawing::Color::White;
			this->CenterDECTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterDECTextBox->Location = System::Drawing::Point(296, 81);
			this->CenterDECTextBox->Name = L"CenterDECTextBox";
			this->CenterDECTextBox->ReadOnly = true;
			this->CenterDECTextBox->Size = System::Drawing::Size(80, 20);
			this->CenterDECTextBox->TabIndex = 38;
			this->CenterDECTextBox->Text = L" 00:00:00.0";
			this->CenterDECTextBox->WordWrap = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel6);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(612, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(275, 124);
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
			this->tableLayoutPanel6->Controls->Add(this->label18, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->label19, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->label20, 2, 1);
			this->tableLayoutPanel6->Controls->Add(this->label21, 2, 2);
			this->tableLayoutPanel6->Controls->Add(this->label22, 2, 3);
			this->tableLayoutPanel6->Controls->Add(this->ObjectXTextBox, 3, 0);
			this->tableLayoutPanel6->Controls->Add(this->ObjectYTextBox, 3, 1);
			this->tableLayoutPanel6->Controls->Add(this->ObjectMaxTextBox, 3, 2);
			this->tableLayoutPanel6->Controls->Add(this->ObjectFWHMTextBox, 3, 3);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 4;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(269, 105);
			this->tableLayoutPanel6->TabIndex = 1;
			// 
			// ObjectMagTextBox
			// 
			this->ObjectMagTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectMagTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectMagTextBox->Location = System::Drawing::Point(50, 55);
			this->ObjectMagTextBox->Name = L"ObjectMagTextBox";
			this->ObjectMagTextBox->ReadOnly = true;
			this->ObjectMagTextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectMagTextBox->TabIndex = 21;
			this->ObjectMagTextBox->Text = L"99.999";
			this->ObjectMagTextBox->WordWrap = false;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(13, 58);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 13);
			this->label16->TabIndex = 20;
			this->label16->Text = L"Mag:";
			// 
			// ObjectDECTextBox
			// 
			this->ObjectDECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectDECTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectDECTextBox->Location = System::Drawing::Point(50, 29);
			this->ObjectDECTextBox->Name = L"ObjectDECTextBox";
			this->ObjectDECTextBox->ReadOnly = true;
			this->ObjectDECTextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectDECTextBox->TabIndex = 19;
			this->ObjectDECTextBox->Text = L" 00:00:00.0";
			this->ObjectDECTextBox->WordWrap = false;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(12, 32);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(32, 13);
			this->label17->TabIndex = 18;
			this->label17->Text = L"DEC:";
			// 
			// ObjectRATextBox
			// 
			this->ObjectRATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectRATextBox->BackColor = System::Drawing::Color::White;
			this->ObjectRATextBox->Location = System::Drawing::Point(50, 3);
			this->ObjectRATextBox->Name = L"ObjectRATextBox";
			this->ObjectRATextBox->ReadOnly = true;
			this->ObjectRATextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectRATextBox->TabIndex = 17;
			this->ObjectRATextBox->Text = L" 00:00:00.0";
			this->ObjectRATextBox->WordWrap = false;
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(19, 6);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(25, 13);
			this->label18->TabIndex = 15;
			this->label18->Text = L"RA:";
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(165, 6);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(17, 13);
			this->label19->TabIndex = 22;
			this->label19->Text = L"X:";
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(165, 32);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(17, 13);
			this->label20->TabIndex = 23;
			this->label20->Text = L"Y:";
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(152, 58);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(30, 13);
			this->label21->TabIndex = 24;
			this->label21->Text = L"Max:";
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(138, 85);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(44, 13);
			this->label22->TabIndex = 25;
			this->label22->Text = L"FWHM:";
			// 
			// ObjectXTextBox
			// 
			this->ObjectXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectXTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectXTextBox->Location = System::Drawing::Point(188, 3);
			this->ObjectXTextBox->Name = L"ObjectXTextBox";
			this->ObjectXTextBox->ReadOnly = true;
			this->ObjectXTextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectXTextBox->TabIndex = 26;
			this->ObjectXTextBox->Text = L" 0000.00";
			this->ObjectXTextBox->WordWrap = false;
			// 
			// ObjectYTextBox
			// 
			this->ObjectYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectYTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectYTextBox->Location = System::Drawing::Point(188, 29);
			this->ObjectYTextBox->Name = L"ObjectYTextBox";
			this->ObjectYTextBox->ReadOnly = true;
			this->ObjectYTextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectYTextBox->TabIndex = 27;
			this->ObjectYTextBox->Text = L" 0000.00";
			this->ObjectYTextBox->WordWrap = false;
			// 
			// ObjectMaxTextBox
			// 
			this->ObjectMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectMaxTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectMaxTextBox->Location = System::Drawing::Point(188, 55);
			this->ObjectMaxTextBox->Name = L"ObjectMaxTextBox";
			this->ObjectMaxTextBox->ReadOnly = true;
			this->ObjectMaxTextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectMaxTextBox->TabIndex = 28;
			this->ObjectMaxTextBox->Text = L"0000000";
			this->ObjectMaxTextBox->WordWrap = false;
			// 
			// ObjectFWHMTextBox
			// 
			this->ObjectFWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectFWHMTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectFWHMTextBox->Location = System::Drawing::Point(188, 81);
			this->ObjectFWHMTextBox->Name = L"ObjectFWHMTextBox";
			this->ObjectFWHMTextBox->ReadOnly = true;
			this->ObjectFWHMTextBox->Size = System::Drawing::Size(65, 20);
			this->ObjectFWHMTextBox->TabIndex = 29;
			this->ObjectFWHMTextBox->Text = L"00.000";
			this->ObjectFWHMTextBox->WordWrap = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->CloseButton, this->ComputeSolutionButton, 
				this->ResetStarsButton, this->InitializeButton});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(896, 27);
			this->toolStrip1->TabIndex = 3;
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
			this->CloseButton->Size = System::Drawing::Size(45, 24);
			this->CloseButton->Text = L"Close";
			this->CloseButton->Click += gcnew System::EventHandler(this, &AstrometryWindow::CloseButton_Clicked);
			// 
			// ComputeSolutionButton
			// 
			this->ComputeSolutionButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ComputeSolutionButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ComputeSolutionButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ComputeSolutionButton.Image")));
			this->ComputeSolutionButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ComputeSolutionButton->Name = L"ComputeSolutionButton";
			this->ComputeSolutionButton->Size = System::Drawing::Size(140, 24);
			this->ComputeSolutionButton->Text = L"   Compute Solution";
			// 
			// ResetStarsButton
			// 
			this->ResetStarsButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ResetStarsButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ResetStarsButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ResetStarsButton.Image")));
			this->ResetStarsButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ResetStarsButton->Name = L"ResetStarsButton";
			this->ResetStarsButton->Size = System::Drawing::Size(105, 24);
			this->ResetStarsButton->Text = L"   Reset Stars";
			// 
			// InitializeButton
			// 
			this->InitializeButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->InitializeButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->InitializeButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"InitializeButton.Image")));
			this->InitializeButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->InitializeButton->Name = L"InitializeButton";
			this->InitializeButton->Size = System::Drawing::Size(146, 24);
			this->InitializeButton->Text = L"   Initialize Settings";
			this->InitializeButton->Click += gcnew System::EventHandler(this, &AstrometryWindow::InitializeButton_Clicked);
			// 
			// AstrometryWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(896, 623);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AstrometryWindow";
			this->Text = L"AstrometryWindow";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RefStarPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ImagePictureBox))->EndInit();
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
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
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

			 int xmin, ymin, xmax, ymax;
			 float Magnitude, MagErr, SkyFlux, StarFlux, FWHM, x, y;
			 int max, Found;
			 char buffer[80];

			 if (e->Button == ::MouseButtons::Left) {
/*				 if (! PickAlignStarDialogExists)
					 return;
				 sprintf_s(buffer, sizeof(buffer), "%d", e->X);
				 PickAlignStarDialog::SetObjectXTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%d", e->Y);
				 PickAlignStarDialog::SetObjectYTextBox(buffer); */
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
					 AstrometryWindow::SetObjectXTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%f", y);
					 AstrometryWindow::SetObjectYTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%d", max);
					 AstrometryWindow::SetObjectMaxTextBox(buffer);
					 doPhotometry(&ccd->Image, x, y, max, &FWHM, &SkyFlux, &StarFlux,
								  &Magnitude, &MagErr);
					 sprintf_s(buffer, sizeof(buffer), "%6.2f", FWHM);
					 AstrometryWindow::SetObjectFWHMTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%6.3f+/-%5.3f", Magnitude, MagErr);
					 AstrometryWindow::SetObjectMagTextBox(buffer);
				 }
			 }
		 }
private: System::Void MouseDoubleClickHandler(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int xmin, ymin, xmax, ymax;
			 float x, y;
			 int max, Found;

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
					 AstrometryWindow::UnmarkStar(x,y);
				 }
			 }
		 }
private: System::Void MouseMoveHandler(Object^ sender,System::Windows::Forms::MouseEventArgs^ e ) {

/*	     char buffer[80];
         int mouseX = e->X;
         int mouseY = e->Y;
		 int x = ccd->Image.light_frame.x;
		 int y = ccd->Image.light_frame.y;
		 sprintf_s(buffer,sizeof(buffer),"%d",mouseX);
		 String^ str = gcnew String(buffer);
		 CurrentImageWindow::FormPtr->CurrentImageXTextBox->Text = str;
		 delete str;
		 sprintf_s(buffer,sizeof(buffer),"%d",mouseY);
		 str = gcnew String(buffer);
		 CurrentImageWindow::FormPtr->CurrentImageYTextBox->Text = str;
		 delete str;
		 if (ccd->Image.light_frame.frame == NULL)
            return;
         if ((mouseX >= ccd->Image.light_frame.w+x)  || (mouseX < x) ||
			 (mouseY >= ccd->Image.light_frame.h+y) || (mouseY < y))
            return;
         int pixel = ccd->Image.light_frame.w * (mouseY-y) + (mouseX-x);
		 sprintf_s(buffer,sizeof(buffer),"%d", ccd->Image.light_frame.frame[pixel]);
		 str = gcnew String(buffer);
		 CurrentImageWindow::FormPtr->CurrentImagePixValTextBox->Text = str;
		 delete str; */
      }
public: static void ClearMarkedStarList(void) {

			MARKSTAR *sptr, *next;
			sptr = AstrometryWindow::MarkedStarList;
			while (sptr != NULL) {
				next = sptr->next;
				free(sptr);
				sptr = next;
			}
			AstrometryWindow::MarkedStarList = NULL;
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
			 int x1, y1, x2, y2, starX, starY, h, w;
			 float AperRad, SkyInnerRad, SkyOuterRad;

			 AperRad = photometrySettings.aperatureRadius;
			 SkyInnerRad = photometrySettings.skyInnerRadius;
			 SkyOuterRad = photometrySettings.skyOuterRadius;
			 sptr = AstrometryWindow::MarkedStarList;
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
			 return;
		 }

public: void ShowTheWindow(void) {

			AstrometryWindow::Show();
		}
private: System::Void CloseButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 AstrometryWindow::Hide();
		 }
private: System::Void InitializeButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ShowInitializeAstrometryDialog();
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

public: static void SetObjectYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AstrometryWindow::FormPtr->ObjectYTextBox->Text = buffer;
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

private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
