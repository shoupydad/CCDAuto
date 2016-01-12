#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "doRoutines.h"
#include "PickAlignStarDialog.h"
#include "HistogramWindow.h"


namespace CCDAuto {

	/// <summary>
	/// Summary for CurrentImageWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class CurrentImageWindow : public System::Windows::Forms::Form
	{
	public:
		static CurrentImageWindow^ FormPtr;
	//private: System::Windows::Forms::ToolStripButton^  ClearMarkedStarsButton;

	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::PictureBox^  CurrentImagePictureBox;
	//private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	//private: System::Windows::Forms::ToolStripButton^  CenterButton;
	private: System::Windows::Forms::Button^  HistogramButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exposeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  defineListToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  measureListToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  photometrySettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  astrometryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  centerToolStripMenuItem;
	private: System::Windows::Forms::Button^  ApplyButton;
	private: System::Windows::Forms::CheckBox^  AutoScaleCheckBox;
	private: System::Windows::Forms::CheckBox^  FlipVerticalCheckBox;
	private: System::Windows::Forms::CheckBox^  FlipHorizontalCheckBox;






	public: 
	private: 

	private: 
	public: 

	public: 
		static MARKSTAR *MarkedStarList;
		CurrentImageWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			FormPtr = this;
			this->FormClosing += gcnew FormClosingEventHandler(this,&CurrentImageWindow::ClosingEventHandler);
			CCDAuto::CurrentImageWindowExists = true;
			this->CurrentImagePictureBox->MouseMove +=
				gcnew System::Windows::Forms::MouseEventHandler(this, &CurrentImageWindow::MouseMoveHandler);
			this->CurrentImagePictureBox->Paint +=
				gcnew System::Windows::Forms::PaintEventHandler(this, &CurrentImageWindow::PaintHandler);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CurrentImageWindow()
		{
			if (components)
			{
				delete components;
				CCDAuto::CurrentImageWindowExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

	public:  System::Drawing::Bitmap^ CurrentImageBitmap;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  CurrentImagePixelGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  CurrentImageXTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageYTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImagePixValTextBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  CurrentImageAvePixTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageMaxPixTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageMinPixTextBox;
	private: System::Windows::Forms::GroupBox^  CurrentImageStellarPSFGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  CurrentImageStarXTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageStarYTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageStarMaxTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageFWHMTextBox;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  CurrentImageRATextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageDECTextBox;
	private: System::Windows::Forms::CheckBox^  CurrentImagePlotCheckBox;
	private: System::Windows::Forms::GroupBox^  CurrentImagePhotometryGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  CurrentImageStarFluxTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageSkyFluxTextBox;
	private: System::Windows::Forms::TextBox^  CurrentImageMagTextBox;
	private: System::Windows::Forms::GroupBox^  CurrentImageDisplayParametersGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  CurrentImageBgndTextBox;

	private: System::Windows::Forms::TextBox^  CurrentImageRangeTextBox;

	private: System::Windows::Forms::TextBox^  CurrentImageGammaTextBox;
	protected: 

	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CurrentImageWindow::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CurrentImagePixelGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CurrentImageAvePixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageMaxPixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageMinPixTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImagePixValTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageStellarPSFGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageStarXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageStarYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageStarMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageFWHMTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageRATextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageDECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImagePlotCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CurrentImagePhotometryGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageStarFluxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageSkyFluxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageMagTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageDisplayParametersGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageBgndTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageRangeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageGammaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ApplyButton = (gcnew System::Windows::Forms::Button());
			this->HistogramButton = (gcnew System::Windows::Forms::Button());
			this->AutoScaleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FlipVerticalCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FlipHorizontalCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->CurrentImagePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exposeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->defineListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->measureListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->photometrySettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearMarksToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->astrometryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->CurrentImagePixelGroupBox->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->CurrentImageStellarPSFGroupBox->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->CurrentImagePhotometryGroupBox->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->CurrentImageDisplayParametersGroupBox->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentImagePictureBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->menuStrip1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 6.114398F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 74.05405F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 19.86486F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(787, 740);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				24.16107F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				27.38853F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				22.92994F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.73248F)));
			this->tableLayoutPanel2->Controls->Add(this->CurrentImagePixelGroupBox, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->CurrentImageStellarPSFGroupBox, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->CurrentImagePhotometryGroupBox, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->CurrentImageDisplayParametersGroupBox, 3, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 595);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 142)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(781, 142);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// CurrentImagePixelGroupBox
			// 
			this->CurrentImagePixelGroupBox->Controls->Add(this->tableLayoutPanel3);
			this->CurrentImagePixelGroupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CurrentImagePixelGroupBox->Location = System::Drawing::Point(3, 3);
			this->CurrentImagePixelGroupBox->Name = L"CurrentImagePixelGroupBox";
			this->CurrentImagePixelGroupBox->Size = System::Drawing::Size(182, 136);
			this->CurrentImagePixelGroupBox->TabIndex = 0;
			this->CurrentImagePixelGroupBox->TabStop = false;
			this->CurrentImagePixelGroupBox->Text = L"Current Pixel/Image";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				26.19048F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.59524F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				22.02381F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageAvePixTextBox, 3, 2);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageMaxPixTextBox, 3, 1);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageMinPixTextBox, 3, 0);
			this->tableLayoutPanel3->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageXTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageYTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImagePixValTextBox, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel3->Controls->Add(this->label6, 2, 2);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(176, 117);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// CurrentImageAvePixTextBox
			// 
			this->CurrentImageAvePixTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageAvePixTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageAvePixTextBox->Location = System::Drawing::Point(133, 87);
			this->CurrentImageAvePixTextBox->Name = L"CurrentImageAvePixTextBox";
			this->CurrentImageAvePixTextBox->ReadOnly = true;
			this->CurrentImageAvePixTextBox->Size = System::Drawing::Size(37, 20);
			this->CurrentImageAvePixTextBox->TabIndex = 11;
			this->CurrentImageAvePixTextBox->Text = L"0";
			this->CurrentImageAvePixTextBox->WordWrap = false;
			// 
			// CurrentImageMaxPixTextBox
			// 
			this->CurrentImageMaxPixTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageMaxPixTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageMaxPixTextBox->Location = System::Drawing::Point(133, 48);
			this->CurrentImageMaxPixTextBox->Name = L"CurrentImageMaxPixTextBox";
			this->CurrentImageMaxPixTextBox->ReadOnly = true;
			this->CurrentImageMaxPixTextBox->Size = System::Drawing::Size(37, 20);
			this->CurrentImageMaxPixTextBox->TabIndex = 10;
			this->CurrentImageMaxPixTextBox->Text = L"0";
			this->CurrentImageMaxPixTextBox->WordWrap = false;
			// 
			// CurrentImageMinPixTextBox
			// 
			this->CurrentImageMinPixTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageMinPixTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageMinPixTextBox->Location = System::Drawing::Point(133, 9);
			this->CurrentImageMinPixTextBox->Name = L"CurrentImageMinPixTextBox";
			this->CurrentImageMinPixTextBox->ReadOnly = true;
			this->CurrentImageMinPixTextBox->Size = System::Drawing::Size(37, 20);
			this->CurrentImageMinPixTextBox->TabIndex = 9;
			this->CurrentImageMinPixTextBox->Text = L"0";
			this->CurrentImageMinPixTextBox->WordWrap = false;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(100, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Min:";
			// 
			// CurrentImageXTextBox
			// 
			this->CurrentImageXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageXTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageXTextBox->Location = System::Drawing::Point(49, 9);
			this->CurrentImageXTextBox->Name = L"CurrentImageXTextBox";
			this->CurrentImageXTextBox->ReadOnly = true;
			this->CurrentImageXTextBox->Size = System::Drawing::Size(36, 20);
			this->CurrentImageXTextBox->TabIndex = 3;
			this->CurrentImageXTextBox->Text = L"0";
			this->CurrentImageXTextBox->WordWrap = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Y:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Value:";
			// 
			// CurrentImageYTextBox
			// 
			this->CurrentImageYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageYTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageYTextBox->Location = System::Drawing::Point(49, 48);
			this->CurrentImageYTextBox->Name = L"CurrentImageYTextBox";
			this->CurrentImageYTextBox->ReadOnly = true;
			this->CurrentImageYTextBox->Size = System::Drawing::Size(36, 20);
			this->CurrentImageYTextBox->TabIndex = 4;
			this->CurrentImageYTextBox->Text = L"0";
			this->CurrentImageYTextBox->WordWrap = false;
			this->CurrentImageYTextBox->TextChanged += gcnew System::EventHandler(this, &CurrentImageWindow::CurrentImageYTextBox_TextChanged);
			// 
			// CurrentImagePixValTextBox
			// 
			this->CurrentImagePixValTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImagePixValTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImagePixValTextBox->Location = System::Drawing::Point(49, 87);
			this->CurrentImagePixValTextBox->Name = L"CurrentImagePixValTextBox";
			this->CurrentImagePixValTextBox->ReadOnly = true;
			this->CurrentImagePixValTextBox->Size = System::Drawing::Size(36, 20);
			this->CurrentImagePixValTextBox->TabIndex = 5;
			this->CurrentImagePixValTextBox->Text = L"0";
			this->CurrentImagePixValTextBox->WordWrap = false;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(97, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Max:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(98, 91);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Ave:";
			// 
			// CurrentImageStellarPSFGroupBox
			// 
			this->CurrentImageStellarPSFGroupBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CurrentImageStellarPSFGroupBox->Controls->Add(this->tableLayoutPanel4);
			this->CurrentImageStellarPSFGroupBox->Location = System::Drawing::Point(192, 14);
			this->CurrentImageStellarPSFGroupBox->Name = L"CurrentImageStellarPSFGroupBox";
			this->CurrentImageStellarPSFGroupBox->Size = System::Drawing::Size(205, 114);
			this->CurrentImageStellarPSFGroupBox->TabIndex = 1;
			this->CurrentImageStellarPSFGroupBox->TabStop = false;
			this->CurrentImageStellarPSFGroupBox->Text = L"Stellar PSF";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				24)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.5F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.98058F)));
			this->tableLayoutPanel4->Controls->Add(this->label10, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->label7, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->label8, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->label9, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImageStarXTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImageStarYTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImageStarMaxTextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImageFWHMTextBox, 1, 3);
			this->tableLayoutPanel4->Controls->Add(this->label11, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->label12, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImageRATextBox, 3, 0);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImageDECTextBox, 3, 1);
			this->tableLayoutPanel4->Controls->Add(this->CurrentImagePlotCheckBox, 3, 2);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 4;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(199, 95);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(4, 75);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"fwhm:";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 5);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"X:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(22, 28);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Y:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 51);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Max:";
			// 
			// CurrentImageStarXTextBox
			// 
			this->CurrentImageStarXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageStarXTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageStarXTextBox->Location = System::Drawing::Point(45, 3);
			this->CurrentImageStarXTextBox->Name = L"CurrentImageStarXTextBox";
			this->CurrentImageStarXTextBox->ReadOnly = true;
			this->CurrentImageStarXTextBox->Size = System::Drawing::Size(42, 20);
			this->CurrentImageStarXTextBox->TabIndex = 10;
			this->CurrentImageStarXTextBox->Text = L"9999";
			this->CurrentImageStarXTextBox->WordWrap = false;
			// 
			// CurrentImageStarYTextBox
			// 
			this->CurrentImageStarYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageStarYTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageStarYTextBox->Location = System::Drawing::Point(45, 26);
			this->CurrentImageStarYTextBox->Name = L"CurrentImageStarYTextBox";
			this->CurrentImageStarYTextBox->ReadOnly = true;
			this->CurrentImageStarYTextBox->Size = System::Drawing::Size(42, 20);
			this->CurrentImageStarYTextBox->TabIndex = 11;
			this->CurrentImageStarYTextBox->Text = L"9999";
			this->CurrentImageStarYTextBox->WordWrap = false;
			// 
			// CurrentImageStarMaxTextBox
			// 
			this->CurrentImageStarMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageStarMaxTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageStarMaxTextBox->Location = System::Drawing::Point(45, 49);
			this->CurrentImageStarMaxTextBox->Name = L"CurrentImageStarMaxTextBox";
			this->CurrentImageStarMaxTextBox->ReadOnly = true;
			this->CurrentImageStarMaxTextBox->Size = System::Drawing::Size(42, 20);
			this->CurrentImageStarMaxTextBox->TabIndex = 12;
			this->CurrentImageStarMaxTextBox->Text = L"99999";
			this->CurrentImageStarMaxTextBox->WordWrap = false;
			// 
			// CurrentImageFWHMTextBox
			// 
			this->CurrentImageFWHMTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageFWHMTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageFWHMTextBox->Location = System::Drawing::Point(45, 72);
			this->CurrentImageFWHMTextBox->Name = L"CurrentImageFWHMTextBox";
			this->CurrentImageFWHMTextBox->ReadOnly = true;
			this->CurrentImageFWHMTextBox->Size = System::Drawing::Size(35, 20);
			this->CurrentImageFWHMTextBox->TabIndex = 13;
			this->CurrentImageFWHMTextBox->Text = L"99.99";
			this->CurrentImageFWHMTextBox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(101, 5);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"RA:";
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(94, 28);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(32, 13);
			this->label12->TabIndex = 15;
			this->label12->Text = L"DEC:";
			// 
			// CurrentImageRATextBox
			// 
			this->CurrentImageRATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageRATextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageRATextBox->Location = System::Drawing::Point(132, 3);
			this->CurrentImageRATextBox->Name = L"CurrentImageRATextBox";
			this->CurrentImageRATextBox->ReadOnly = true;
			this->CurrentImageRATextBox->Size = System::Drawing::Size(64, 20);
			this->CurrentImageRATextBox->TabIndex = 16;
			this->CurrentImageRATextBox->Text = L" 00:00:00.0";
			this->CurrentImageRATextBox->WordWrap = false;
			// 
			// CurrentImageDECTextBox
			// 
			this->CurrentImageDECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageDECTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageDECTextBox->Location = System::Drawing::Point(132, 26);
			this->CurrentImageDECTextBox->Name = L"CurrentImageDECTextBox";
			this->CurrentImageDECTextBox->ReadOnly = true;
			this->CurrentImageDECTextBox->Size = System::Drawing::Size(64, 20);
			this->CurrentImageDECTextBox->TabIndex = 17;
			this->CurrentImageDECTextBox->Text = L"+00:00:00.0";
			this->CurrentImageDECTextBox->WordWrap = false;
			// 
			// CurrentImagePlotCheckBox
			// 
			this->CurrentImagePlotCheckBox->AutoSize = true;
			this->CurrentImagePlotCheckBox->BackColor = System::Drawing::SystemColors::Control;
			this->CurrentImagePlotCheckBox->Location = System::Drawing::Point(132, 49);
			this->CurrentImagePlotCheckBox->Name = L"CurrentImagePlotCheckBox";
			this->CurrentImagePlotCheckBox->Size = System::Drawing::Size(50, 17);
			this->CurrentImagePlotCheckBox->TabIndex = 18;
			this->CurrentImagePlotCheckBox->Text = L"Plot\?";
			this->CurrentImagePlotCheckBox->UseVisualStyleBackColor = false;
			// 
			// CurrentImagePhotometryGroupBox
			// 
			this->CurrentImagePhotometryGroupBox->Controls->Add(this->tableLayoutPanel5);
			this->CurrentImagePhotometryGroupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CurrentImagePhotometryGroupBox->Location = System::Drawing::Point(404, 3);
			this->CurrentImagePhotometryGroupBox->Name = L"CurrentImagePhotometryGroupBox";
			this->CurrentImagePhotometryGroupBox->Size = System::Drawing::Size(172, 136);
			this->CurrentImagePhotometryGroupBox->TabIndex = 2;
			this->CurrentImagePhotometryGroupBox->TabStop = false;
			this->CurrentImagePhotometryGroupBox->Text = L"Photometry";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				37.01299F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				62.98701F)));
			this->tableLayoutPanel5->Controls->Add(this->label15, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label13, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label14, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->CurrentImageStarFluxTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->CurrentImageSkyFluxTextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->CurrentImageMagTextBox, 1, 2);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(166, 117);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(27, 91);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 13);
			this->label15->TabIndex = 4;
			this->label15->Text = L"Mag:";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(10, 13);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(48, 13);
			this->label13->TabIndex = 2;
			this->label13->Text = L"StarFlux:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(11, 52);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(47, 13);
			this->label14->TabIndex = 3;
			this->label14->Text = L"SkyFlux:";
			// 
			// CurrentImageStarFluxTextBox
			// 
			this->CurrentImageStarFluxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageStarFluxTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageStarFluxTextBox->Location = System::Drawing::Point(64, 9);
			this->CurrentImageStarFluxTextBox->Name = L"CurrentImageStarFluxTextBox";
			this->CurrentImageStarFluxTextBox->ReadOnly = true;
			this->CurrentImageStarFluxTextBox->Size = System::Drawing::Size(77, 20);
			this->CurrentImageStarFluxTextBox->TabIndex = 19;
			this->CurrentImageStarFluxTextBox->Text = L"0";
			this->CurrentImageStarFluxTextBox->WordWrap = false;
			// 
			// CurrentImageSkyFluxTextBox
			// 
			this->CurrentImageSkyFluxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageSkyFluxTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageSkyFluxTextBox->Location = System::Drawing::Point(64, 48);
			this->CurrentImageSkyFluxTextBox->Name = L"CurrentImageSkyFluxTextBox";
			this->CurrentImageSkyFluxTextBox->ReadOnly = true;
			this->CurrentImageSkyFluxTextBox->Size = System::Drawing::Size(77, 20);
			this->CurrentImageSkyFluxTextBox->TabIndex = 20;
			this->CurrentImageSkyFluxTextBox->Text = L"0";
			this->CurrentImageSkyFluxTextBox->WordWrap = false;
			// 
			// CurrentImageMagTextBox
			// 
			this->CurrentImageMagTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageMagTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageMagTextBox->Location = System::Drawing::Point(64, 87);
			this->CurrentImageMagTextBox->Name = L"CurrentImageMagTextBox";
			this->CurrentImageMagTextBox->ReadOnly = true;
			this->CurrentImageMagTextBox->Size = System::Drawing::Size(91, 20);
			this->CurrentImageMagTextBox->TabIndex = 21;
			this->CurrentImageMagTextBox->Text = L"99.999 +/-9.999";
			this->CurrentImageMagTextBox->WordWrap = false;
			// 
			// CurrentImageDisplayParametersGroupBox
			// 
			this->CurrentImageDisplayParametersGroupBox->Controls->Add(this->tableLayoutPanel6);
			this->CurrentImageDisplayParametersGroupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CurrentImageDisplayParametersGroupBox->Location = System::Drawing::Point(582, 3);
			this->CurrentImageDisplayParametersGroupBox->Name = L"CurrentImageDisplayParametersGroupBox";
			this->CurrentImageDisplayParametersGroupBox->Size = System::Drawing::Size(196, 136);
			this->CurrentImageDisplayParametersGroupBox->TabIndex = 3;
			this->CurrentImageDisplayParametersGroupBox->TabStop = false;
			this->CurrentImageDisplayParametersGroupBox->Text = L"Display Parameters";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 3;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				27.36842F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.05263F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.57895F)));
			this->tableLayoutPanel6->Controls->Add(this->label16, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->label17, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->label18, 0, 2);
			this->tableLayoutPanel6->Controls->Add(this->CurrentImageBgndTextBox, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->CurrentImageRangeTextBox, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->CurrentImageGammaTextBox, 1, 2);
			this->tableLayoutPanel6->Controls->Add(this->ApplyButton, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->HistogramButton, 0, 3);
			this->tableLayoutPanel6->Controls->Add(this->AutoScaleCheckBox, 2, 1);
			this->tableLayoutPanel6->Controls->Add(this->FlipVerticalCheckBox, 2, 2);
			this->tableLayoutPanel6->Controls->Add(this->FlipHorizontalCheckBox, 2, 3);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 4;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(190, 117);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(13, 8);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(35, 13);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Bgnd:";
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 37);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(42, 13);
			this->label17->TabIndex = 4;
			this->label17->Text = L"Range:";
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(5, 59);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(43, 26);
			this->label18->TabIndex = 5;
			this->label18->Text = L"Gamma:";
			// 
			// CurrentImageBgndTextBox
			// 
			this->CurrentImageBgndTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageBgndTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageBgndTextBox->Location = System::Drawing::Point(54, 4);
			this->CurrentImageBgndTextBox->Name = L"CurrentImageBgndTextBox";
			this->CurrentImageBgndTextBox->Size = System::Drawing::Size(33, 20);
			this->CurrentImageBgndTextBox->TabIndex = 10;
			this->CurrentImageBgndTextBox->Text = L"0";
			this->CurrentImageBgndTextBox->WordWrap = false;
			// 
			// CurrentImageRangeTextBox
			// 
			this->CurrentImageRangeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageRangeTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageRangeTextBox->Location = System::Drawing::Point(54, 33);
			this->CurrentImageRangeTextBox->Name = L"CurrentImageRangeTextBox";
			this->CurrentImageRangeTextBox->Size = System::Drawing::Size(33, 20);
			this->CurrentImageRangeTextBox->TabIndex = 11;
			this->CurrentImageRangeTextBox->Text = L"0";
			this->CurrentImageRangeTextBox->WordWrap = false;
			// 
			// CurrentImageGammaTextBox
			// 
			this->CurrentImageGammaTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageGammaTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageGammaTextBox->Location = System::Drawing::Point(54, 62);
			this->CurrentImageGammaTextBox->Name = L"CurrentImageGammaTextBox";
			this->CurrentImageGammaTextBox->Size = System::Drawing::Size(33, 20);
			this->CurrentImageGammaTextBox->TabIndex = 12;
			this->CurrentImageGammaTextBox->Text = L"1.000";
			this->CurrentImageGammaTextBox->WordWrap = false;
			// 
			// ApplyButton
			// 
			this->ApplyButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ApplyButton->Location = System::Drawing::Point(114, 4);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(52, 21);
			this->ApplyButton->TabIndex = 13;
			this->ApplyButton->Text = L"Apply";
			this->ApplyButton->UseVisualStyleBackColor = true;
			this->ApplyButton->Click += gcnew System::EventHandler(this, &CurrentImageWindow::ApplyButton_Click);
			// 
			// HistogramButton
			// 
			this->HistogramButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HistogramButton->Location = System::Drawing::Point(3, 91);
			this->HistogramButton->Name = L"HistogramButton";
			this->HistogramButton->Size = System::Drawing::Size(45, 21);
			this->HistogramButton->TabIndex = 14;
			this->HistogramButton->Text = L"Hist";
			this->HistogramButton->UseVisualStyleBackColor = true;
			this->HistogramButton->Click += gcnew System::EventHandler(this, &CurrentImageWindow::HistogramButton_Clicked);
			// 
			// AutoScaleCheckBox
			// 
			this->AutoScaleCheckBox->AutoSize = true;
			this->AutoScaleCheckBox->Location = System::Drawing::Point(93, 32);
			this->AutoScaleCheckBox->Name = L"AutoScaleCheckBox";
			this->AutoScaleCheckBox->Size = System::Drawing::Size(75, 17);
			this->AutoScaleCheckBox->TabIndex = 15;
			this->AutoScaleCheckBox->Text = L"AutoScale";
			this->AutoScaleCheckBox->UseVisualStyleBackColor = true;
			this->AutoScaleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CurrentImageWindow::AutoScaleCheckBox_CheckedChanged);
			// 
			// FlipVerticalCheckBox
			// 
			this->FlipVerticalCheckBox->AutoSize = true;
			this->FlipVerticalCheckBox->Location = System::Drawing::Point(93, 61);
			this->FlipVerticalCheckBox->Name = L"FlipVerticalCheckBox";
			this->FlipVerticalCheckBox->Size = System::Drawing::Size(80, 17);
			this->FlipVerticalCheckBox->TabIndex = 16;
			this->FlipVerticalCheckBox->Text = L"Flip Vertical";
			this->FlipVerticalCheckBox->UseVisualStyleBackColor = true;
			this->FlipVerticalCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CurrentImageWindow::FlipVerticalCheckBox_CheckChanged);
			// 
			// FlipHorizontalCheckBox
			// 
			this->FlipHorizontalCheckBox->AutoSize = true;
			this->FlipHorizontalCheckBox->Location = System::Drawing::Point(93, 90);
			this->FlipHorizontalCheckBox->Name = L"FlipHorizontalCheckBox";
			this->FlipHorizontalCheckBox->Size = System::Drawing::Size(92, 17);
			this->FlipHorizontalCheckBox->TabIndex = 17;
			this->FlipHorizontalCheckBox->Text = L"Flip Horizontal";
			this->FlipHorizontalCheckBox->UseVisualStyleBackColor = true;
			this->FlipHorizontalCheckBox->CheckedChanged += gcnew System::EventHandler(this, &CurrentImageWindow::FlipHorizontalCheckBox_CheckChanged);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->CurrentImagePictureBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 48);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(781, 541);
			this->panel1->TabIndex = 3;
			// 
			// CurrentImagePictureBox
			// 
			this->CurrentImagePictureBox->BackColor = System::Drawing::Color::White;
			this->CurrentImagePictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->CurrentImagePictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CurrentImagePictureBox->Location = System::Drawing::Point(0, 0);
			this->CurrentImagePictureBox->MaximumSize = System::Drawing::Size(3326, 2504);
			this->CurrentImagePictureBox->MinimumSize = System::Drawing::Size(256, 256);
			this->CurrentImagePictureBox->Name = L"CurrentImagePictureBox";
			this->CurrentImagePictureBox->Size = System::Drawing::Size(760, 541);
			this->CurrentImagePictureBox->TabIndex = 1;
			this->CurrentImagePictureBox->TabStop = false;
			this->CurrentImagePictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CurrentImageWindow::MouseClickHandler);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->closeToolStripMenuItem,
					this->exposeToolStripMenuItem, this->defineListToolStripMenuItem, this->measureListToolStripMenuItem, this->photometrySettingsToolStripMenuItem,
					this->clearMarksToolStripMenuItem, this->astrometryToolStripMenuItem, this->centerToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(0, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(787, 27);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::CloseMenuItem_Clicked);
			// 
			// exposeToolStripMenuItem
			// 
			this->exposeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exposeToolStripMenuItem->Name = L"exposeToolStripMenuItem";
			this->exposeToolStripMenuItem->Size = System::Drawing::Size(67, 23);
			this->exposeToolStripMenuItem->Text = L"Expose";
			this->exposeToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::ExposeMenuItem_Clicked);
			// 
			// defineListToolStripMenuItem
			// 
			this->defineListToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->defineListToolStripMenuItem->Name = L"defineListToolStripMenuItem";
			this->defineListToolStripMenuItem->Size = System::Drawing::Size(97, 23);
			this->defineListToolStripMenuItem->Text = L"Define List";
			this->defineListToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::DefineListMenuItem_Clicked);
			// 
			// measureListToolStripMenuItem
			// 
			this->measureListToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->measureListToolStripMenuItem->Name = L"measureListToolStripMenuItem";
			this->measureListToolStripMenuItem->Size = System::Drawing::Size(110, 23);
			this->measureListToolStripMenuItem->Text = L"Measure List";
			this->measureListToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::MeasureListMenuItem_Clicked);
			// 
			// photometrySettingsToolStripMenuItem
			// 
			this->photometrySettingsToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->photometrySettingsToolStripMenuItem->Name = L"photometrySettingsToolStripMenuItem";
			this->photometrySettingsToolStripMenuItem->Size = System::Drawing::Size(161, 23);
			this->photometrySettingsToolStripMenuItem->Text = L"Photometry Settings";
			this->photometrySettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::PhotometrySettingsMenuItem_Clicked);
			// 
			// clearMarksToolStripMenuItem
			// 
			this->clearMarksToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearMarksToolStripMenuItem->Name = L"clearMarksToolStripMenuItem";
			this->clearMarksToolStripMenuItem->Size = System::Drawing::Size(105, 23);
			this->clearMarksToolStripMenuItem->Text = L"Clear Marks";
			this->clearMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::ClearMarksMenuItem_Clicked);
			// 
			// astrometryToolStripMenuItem
			// 
			this->astrometryToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->astrometryToolStripMenuItem->Name = L"astrometryToolStripMenuItem";
			this->astrometryToolStripMenuItem->Size = System::Drawing::Size(100, 23);
			this->astrometryToolStripMenuItem->Text = L"Astrometry";
			this->astrometryToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::AstrometryMenuItem_Clicked);
			// 
			// centerToolStripMenuItem
			// 
			this->centerToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->centerToolStripMenuItem->Name = L"centerToolStripMenuItem";
			this->centerToolStripMenuItem->Size = System::Drawing::Size(67, 23);
			this->centerToolStripMenuItem->Text = L"Center";
			this->centerToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrentImageWindow::CenterMenuItem_Clicked);
			// 
			// CurrentImageWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 740);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CurrentImageWindow";
			this->Text = L"Current Image Window";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->CurrentImagePixelGroupBox->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->CurrentImageStellarPSFGroupBox->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->CurrentImagePhotometryGroupBox->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->CurrentImageDisplayParametersGroupBox->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CurrentImagePictureBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: void ClosingEventHandler(Object^ sender, System::Windows::Forms::FormClosingEventArgs ^e) {

			 MARKSTAR *sptr, *next;

			 if (! CurrentImageWindowCloseButtonClicked) {
				   e->Cancel = true;
				   return;
			 }
			 sptr = CurrentImageWindow::FormPtr->MarkedStarList;
			 while (sptr != NULL) {
				next = sptr->next;
				free(sptr);
				sptr = next;
			 }
		   }

public: static void ShowThisDialog(void) {
			CurrentImageWindow::FormPtr->Show();
		}
public: static void SetCurrentImageXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageXTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageYTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImagePixValTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImagePixValTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageMinPixTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageMinPixTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageMaxPixTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageMaxPixTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageAvePixTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageAvePixTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageStarXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageStarXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageStarXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageStarXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void GetCurrentImageStarYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageStarYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageStarYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageStarYTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageStarMaxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageStarMaxTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageStarMaxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageStarMaxTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageFWHMTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageFWHMTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageFWHMTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageFWHMTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageRATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageRATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageDECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageDECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageStarFluxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageStarFluxTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageStarFluxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageStarFluxTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageSkyFluxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageSkyFluxTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageSkyFluxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageSkyFluxTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageMagTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageMagTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageMagTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageMagTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageBgndTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageBgndTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageBgndTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageBgndTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageRangeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageRangeTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageRangeTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageRangeTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetCurrentImageGammaTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		CurrentImageWindow::FormPtr->CurrentImageGammaTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetCurrentImageGammaTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = CurrentImageWindow::FormPtr->CurrentImageGammaTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

#pragma endregion
private: System::Void CloseMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 CurrentImageWindowCloseButtonClicked = true;
			 CurrentImageWindow::FormPtr->Hide();
		 }
private: System::Void ExposeMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ExposeSingleFrame();
		 }
private: System::Void DefineListMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 ShowDefineListDialog();
		 }
private: System::Void MeasureListMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 bool success;

			 CurrentImageWindow::FormPtr->ClearMarkedStarList();
			 success = updateListStars(&ccd->Image, CurrentStarList);
			 if (! success) return;
			 measureListStars(&ccd->Image, CurrentStarList);
		 }
private: System::Void PhotometrySettingsMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 ShowPhotometrySettingsDialog();
		 }
public: static void CurrentImageXTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void CurrentImageYTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void MouseClickHandler(Object^ sender,System::Windows::Forms::MouseEventArgs^ e ) {

			 int xmin, ymin, xmax, ymax;
			 float Magnitude, MagErr, SkyFlux, StarFlux, FWHM, x, y;
			 int max, Found, frameX, frameY;
			 char buffer[80];
			 FRAME *light;

			 light = &ccd->Image.light_frame;
			 PictureToFrame(e->X, e->Y, &frameX, &frameY, light);
			 if (e->Button == ::MouseButtons::Left) {
				 if (! PickAlignStarDialogExists)
					 return;
				 sprintf_s(buffer, sizeof(buffer), "%d", frameX);
				 PickAlignStarDialog::SetStarXTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%d", frameY);
				 PickAlignStarDialog::SetStarYTextBox(buffer);
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
					 CurrentImageWindow::SetCurrentImageStarXTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%f", y);
					 CurrentImageWindow::SetCurrentImageStarYTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%d", max);
					 CurrentImageWindow::SetCurrentImageStarMaxTextBox(buffer);
					 doPhotometry(&ccd->Image, CURRENTIMAGEWINDOW, x, y, max, false, &FWHM, &SkyFlux, &StarFlux,
								  &Magnitude, &MagErr);
					 sprintf_s(buffer, sizeof(buffer), "%6.2f", FWHM);
					 CurrentImageWindow::SetCurrentImageFWHMTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%6.3f+/-%5.3f", Magnitude, MagErr);
					 CurrentImageWindow::SetCurrentImageMagTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%8.0f", SkyFlux);
					 CurrentImageWindow::SetCurrentImageSkyFluxTextBox(buffer);
					 sprintf_s(buffer, sizeof(buffer), "%8.0f", StarFlux);
					 CurrentImageWindow::SetCurrentImageStarFluxTextBox(buffer);
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

			 light = &ccd->Image.light_frame;
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
				 if (xmax > ccd->Image.light_frame.w)
					 xmax = ccd->Image.light_frame.w;
				 ymax = (int) (frameY + photometrySettings.findRadius);
				 if (ymax > ccd->Image.light_frame.h)
					 ymax = ccd->Image.light_frame.h;
				 Found = FindStar(&ccd->Image.light_frame, xmin, ymin, xmax, ymax,
						 &x, &y, &max);
				 if (Found) {
					 CurrentImageWindow::UnmarkStar(x,y);
				 }
			 }
		 }
private: System::Void MouseMoveHandler(Object^ sender,System::Windows::Forms::MouseEventArgs^ e ) {
	     char buffer[80];
		 int x, y, frameX, frameY, ipix;
		 FRAME *light;
		 String^ str;

		 light = &ccd->Image.light_frame;
		 x = light->x;
		 y = light->y;
		 PictureToFrame(e->X, e->Y, &frameX, &frameY, light);
		 sprintf_s(buffer,sizeof(buffer),"%d",frameX);
		 str = gcnew String(buffer);
		 CurrentImageWindow::FormPtr->CurrentImageXTextBox->Text = str;
		 delete str;
		 sprintf_s(buffer,sizeof(buffer),"%d",frameY);
		 str = gcnew String(buffer);
		 CurrentImageWindow::FormPtr->CurrentImageYTextBox->Text = str;
		 delete str;
		 if (light->frame == NULL)
            return;
         if ((frameX >= light->w+x) || (frameX < x) || (frameY >= light->h+y) || (frameY < y))
            return;
         //int ipix = ccd->Image.light_frame.w * (mouseY-y) + (mouseX-x);
		 ipix = XYtoPixel(light,frameX,frameY); // Changed to macro (doRoutines.h) ALS - 04-03-09
		 sprintf_s(buffer,sizeof(buffer),"%d", light->frame[ipix]);
		 str = gcnew String(buffer);
		 CurrentImageWindow::FormPtr->CurrentImagePixValTextBox->Text = str;
		 delete str;
      }
public: static int PlotCheckBoxChecked(void) {

			int state;

			state = CurrentImageWindow::FormPtr->CurrentImagePlotCheckBox->Checked;
			return state;
		 }
public: static void ClearMarkedStarList(void) {

			MARKSTAR *sptr, *next;
			sptr = CurrentImageWindow::MarkedStarList;
			while (sptr != NULL) {
				next = sptr->next;
				free(sptr);
				sptr = next;
			}
			CurrentImageWindow::MarkedStarList = NULL;
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
			sptr = CurrentImageWindow::MarkedStarList;
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
				CurrentImageWindow::MarkedStarList = newptr;
			} else {
				prev->next = newptr;
			}
			CurrentImageWindow::FormPtr->Refresh();
			return;
		}
public: static void UnmarkStar(float x, float y) {

			MARKSTAR *sptr, *head, *prev;

			sptr = head = CurrentImageWindow::MarkedStarList;
			prev = NULL;
			while (sptr != NULL) {
				if ((fabs(sptr->x-x)<1.0) && (fabs(sptr->y-y)<1.0)) {
					if (prev == NULL)
						CurrentImageWindow::MarkedStarList = sptr->next;
					else
						prev->next = sptr->next;
					free(sptr);
					CurrentImageWindow::FormPtr->Refresh();
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
			 int x1, y1, x2, y2, starX, starY, h, w, starNum;
			 float AperRad, SkyInnerRad, SkyOuterRad;
			 char text[10];
			 FRAME *light;

			 light = &ccd->Image.light_frame;
			 AperRad = photometrySettings.aperatureRadius;
			 SkyInnerRad = photometrySettings.skyInnerRadius;
			 SkyOuterRad = photometrySettings.skyOuterRadius;
			 sptr = CurrentImageWindow::MarkedStarList;
			 starNum = 0;
			 while (sptr != NULL) {
				 FrameToPicture((int)Math::Round(sptr->x), (int)Math::Round(sptr->y), &starX, &starY, light);
				 FrameToPicture((int)Math::Round(sptr->x-5.0), (int)Math::Round(sptr->y-5.0), &x1, &y1, light);
				 FrameToPicture((int)Math::Round(sptr->x+5.0), (int)Math::Round(sptr->y+5.0), &x2, &y2, light);
				 e->Graphics->DrawLine(System::Drawing::Pens::Red,starX,y1,starX,y2);
				 e->Graphics->DrawLine(System::Drawing::Pens::Red,x1,starY,x2,starY);
				 FrameToPicture((int)sptr->x, (int)sptr->y, &x1, &y1, light);
				 x1 = (int)Math::Round(x1 - AperRad);
				 y1 = (int)Math::Round(y1 - AperRad);
				 h = w = (int) (2.0*AperRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 FrameToPicture((int)sptr->x, (int)sptr->y, &x1, &y1, light);
				 x1 = (int)Math::Round(x1 - SkyInnerRad);
				 y1 = (int)Math::Round(y1 - SkyInnerRad);
				 h = w = (int) (2.0*SkyInnerRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 FrameToPicture((int)sptr->x, (int)sptr->y, &x1, &y1, light);
				 x1 = (int)Math::Round(x1 - SkyOuterRad);
				 y1 = (int)Math::Round(y1 - SkyOuterRad);
				 h = w = (int) (2.0*SkyOuterRad);
				 e->Graphics->DrawEllipse(System::Drawing::Pens::Red,x1,y1,h,w);
				 sprintf_s(text, sizeof(text), "%d", starNum);
				 String ^buffer;
				 buffer = gcnew String(text);
				 e->Graphics->DrawString(buffer, this->Font, System::Drawing::Brushes::Red,
					 ((float) (starX+5)), ((float) (starY+5)));
				 delete buffer;
				 sptr = sptr->next;
				 starNum++;
			 }
			 return;
		 }
private: System::Void ClearMarksMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 CurrentImageWindow::FormPtr->ClearMarkedStarList();
			 CurrentImageWindow::FormPtr->Refresh();
		 }
private: System::Void ApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 UpdateImage();
		 }
private: System::Void CurrentImagePictureBox_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void AstrometryMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 ShowAstrometryWindow();

		 }
private: System::Void CenterMenuItem_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 double x, y, delra, deldec;
			 char buffer[80];

			 // Get current object's position in pixels

			 CurrentImageWindow::FormPtr->GetCurrentImageStarXTextBox(buffer);
			 sscanf_s(buffer, "%lf", &x);
			 CurrentImageWindow::FormPtr->GetCurrentImageStarYTextBox(buffer);
			 sscanf_s(buffer, "%lf", &y);

			 // Compute offset from center and convert to delta ra and delta dec

			 delra = - (ccd->Image.light_frame.w/2.0 - x)*plateSolution.PixelScale/3600.0;  // in degrees
			 deldec = (ccd->Image.light_frame.h/2.0 - y)*plateSolution.PixelScale/3600.0; // in degrees

			 // Tell OSUrob to move scope

			 BumpScope(delra, deldec);
		 }

private: System::Void HistogramButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 if (! HistogramWindowExists) {
				 gcnew HistogramWindow();
			 }
			 HistogramWindow::FormPtr->ccd = ccd;
			 HistogramWindow::FormPtr->ShowTheWindow();
		 }
private: System::Void AutoScaleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void FlipVerticalCheckBox_CheckChanged(System::Object^  sender, System::EventArgs^  e) {

			this->FormPtr->CurrentImagePictureBox->Image->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipY);
			this->Refresh();
		}

private: System::Void FlipHorizontalCheckBox_CheckChanged(System::Object^  sender, System::EventArgs^  e) {

			this->FormPtr->CurrentImagePictureBox->Image->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipX);
			this->Refresh();
		}

public: static System::Void FlipImageIfRequested() {

		if (CurrentImageWindow::FormPtr->FlipVerticalCheckBox->Checked)
			CurrentImageWindow::FormPtr->CurrentImagePictureBox->Image->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipY);
		if (CurrentImageWindow::FormPtr->FlipHorizontalCheckBox->Checked)
			CurrentImageWindow::FormPtr->CurrentImagePictureBox->Image->RotateFlip(System::Drawing::RotateFlipType::RotateNoneFlipX);
}
};
}
