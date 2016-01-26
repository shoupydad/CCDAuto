#pragma once

//#include "string.h"
#include "doRoutines.h"
#include "CameraSettingsDialog.h"
#include "CurrentImageWindow.h"
#include "PhotometryPlotWindow.h"
#include "OverWriteDialog.h"
#include "SingleSettingsDialog.h"
#include "DarkFrameSettingsDialog.h"
#include "FlatFrameSettingsDialog.h"
#include "SeriesSettingsDialog.h"
#include "QueryrDialog.h"
#include "ObservatorySettingsDialog.h"
#include "OpenCalDialog.h"
#include "GuideFrameWindow.h"

namespace CCDAuto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static Form1^ CCDAutoForm;
	public: System::Windows::Forms::SaveFileDialog^  SaveFileDialog;

	private: System::Windows::Forms::Timer^  MainTimer;
	private: System::Windows::Forms::Timer^  DownloadTimer;
	private: System::Windows::Forms::Button^  PauseResumeSeriesButton;
	private: System::Windows::Forms::Button^  StopSeriesButton;


	private: System::Windows::Forms::ToolStripMenuItem^  setBaseFolderToolStripMenuItem;
	public: System::Windows::Forms::FolderBrowserDialog^  FolderBrowserDialog;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	public: 
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  UTTextBox;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  LocalTextBox;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  LSTTextBox;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  JDTextBox;
	private: System::Windows::Forms::GroupBox^  CCDStatusGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::TextBox^  CCDFilterTextBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  CCDCoolingTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  CCDTempTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  CCDStatusTextBox;
	private: System::Windows::Forms::ToolStripMenuItem^  showPhotometryPlotToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openCalibrateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trackiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  TrackingEstablishLinkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  TrackingCloseLinkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  onOffDebugModeToolStripMenuItem;




	public: 
	private: 


	public: 
		static System::Threading::Timer^ stateTimer;
	private: System::Windows::Forms::ToolStripMenuItem^  onOffImageProgressToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  onOffAskSaveImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  BToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  VToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  IToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  HToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  GToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  CToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  updateMX916KeywordsToolStripMenuItem;









	public: 
		static bool DontGetScopePosition;

		Form1(void)
		{
			InitializeComponent();
			CCDAutoForm = this;
			this->FormClosing += gcnew FormClosingEventHandler(this,&Form1::Form1ClosingEventHandler);
			DontUpdate = false;
			DontGetScopePosition = false;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  MenuStrip;
	protected: 

	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  OpenMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  SaveMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  SaveAsMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^  ExitMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  camerasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  imagingCCDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ImagingEstablishLinkMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ImagingCloseLinkStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ImagingTurnOnTempRegMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ImagingTurnOffTempRegMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  spectrographCCDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SpectroEstablishLinkMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SpectroCloseLinkMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  SpectroTurnOnTempRegMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  SpectroTurnOffTempRegMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  filterToolStripMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ObservatoryMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ShowCurrentImageMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  GuidingSlitImageMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  CamerasMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  executeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ExposeSingleFrameMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ExposeDarkFramesMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ExposeFlatFramesMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ExposeSeriesOfFramesMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ExposeStackFramesMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ObjectsMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewEditObjectListToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  HelpMenuItem;
	private: System::Windows::Forms::RichTextBox^  StatusRichTextBox;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::GroupBox^  CurrentImageGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  CurrentImageExposeTextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  CurrentImageBinningTextBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  CurrentImageWhichCCDTextBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  CurrentImageFrameSizeTextBox;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  CurrentImageFileNameTextBox;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  CurrentImageObjectNameTextBox;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  CurrentImageDirectoryTextBox;
	private: System::Windows::Forms::GroupBox^  CurrentSeriesGroupBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
    private: System::Windows::Forms::TextBox^  CurrentSeriesStatusTextBox;
	private: System::Windows::Forms::Label^  label13;
    private: System::Windows::Forms::TextBox^  CurrentSeriesFileNameTextBox;
	private: System::Windows::Forms::Label^  label14;
    private: System::Windows::Forms::TextBox^  ProcessingSeqNumTextBox;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
    private: System::Windows::Forms::TextBox^  ProcessingExpNumTextBox;

    private: System::Windows::Forms::Label^  label18;
    private: System::Windows::Forms::Label^  label17;
    private: System::Windows::Forms::TextBox^  TimeToNextExpTextBox;
    private: System::Windows::Forms::TextBox^  TimeToSeriesEndTextBox;
	public: System::Windows::Forms::OpenFileDialog^  OpenFileDialog;
private: System::ComponentModel::IContainer^  components;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openCalibrateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveAsMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateMX916KeywordsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->camerasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imagingCCDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ImagingEstablishLinkMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ImagingCloseLinkStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ImagingTurnOnTempRegMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ImagingTurnOffTempRegMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->spectrographCCDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SpectroEstablishLinkMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SpectroCloseLinkMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SpectroTurnOnTempRegMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SpectroTurnOffTempRegMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trackiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TrackingEstablishLinkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TrackingCloseLinkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->VToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->IToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ObservatoryMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ShowCurrentImageMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showPhotometryPlotToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GuidingSlitImageMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CamerasMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setBaseFolderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onOffDebugModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onOffImageProgressToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onOffAskSaveImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->executeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExposeSingleFrameMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExposeDarkFramesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExposeFlatFramesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExposeSeriesOfFramesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExposeStackFramesMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ObjectsMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewEditObjectListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StatusRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CurrentSeriesGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StopSeriesButton = (gcnew System::Windows::Forms::Button());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->CurrentSeriesStatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->CurrentSeriesFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->ProcessingSeqNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->ProcessingExpNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->TimeToNextExpTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TimeToSeriesEndTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PauseResumeSeriesButton = (gcnew System::Windows::Forms::Button());
			this->CurrentImageGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageExposeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageBinningTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageWhichCCDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageFrameSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->CurrentImageObjectNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentImageDirectoryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->UTTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->LocalTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->LSTTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->JDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CCDStatusGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CCDFilterTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CCDCoolingTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CCDTempTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->CCDStatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->MainTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->DownloadTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->FolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->MenuStrip->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->CurrentSeriesGroupBox->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->CurrentImageGroupBox->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->CCDStatusGroupBox->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// MenuStrip
			// 
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->fileToolStripMenuItem,
					this->camerasToolStripMenuItem, this->filterToolStripMenuItem, this->settingsToolStripMenuItem, this->executeToolStripMenuItem,
					this->ObjectsMenuItem, this->HelpMenuItem
			});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->Size = System::Drawing::Size(691, 24);
			this->MenuStrip->TabIndex = 0;
			this->MenuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->OpenMenuItem,
					this->openCalibrateToolStripMenuItem, this->SaveMenuItem, this->SaveAsMenuItem, this->updateMX916KeywordsToolStripMenuItem, this->ExitMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// OpenMenuItem
			// 
			this->OpenMenuItem->Name = L"OpenMenuItem";
			this->OpenMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->OpenMenuItem->Size = System::Drawing::Size(186, 22);
			this->OpenMenuItem->Text = L"Open";
			this->OpenMenuItem->Click += gcnew System::EventHandler(this, &Form1::OpenMenuItem_Click);
			// 
			// openCalibrateToolStripMenuItem
			// 
			this->openCalibrateToolStripMenuItem->Name = L"openCalibrateToolStripMenuItem";
			this->openCalibrateToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->openCalibrateToolStripMenuItem->Text = L"Open + Calibrate";
			this->openCalibrateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openCalibrateToolStripMenuItem_Click);
			// 
			// SaveMenuItem
			// 
			this->SaveMenuItem->Name = L"SaveMenuItem";
			this->SaveMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->SaveMenuItem->Size = System::Drawing::Size(186, 22);
			this->SaveMenuItem->Text = L"Save";
			this->SaveMenuItem->Click += gcnew System::EventHandler(this, &Form1::SaveMenuItem_Click);
			// 
			// SaveAsMenuItem
			// 
			this->SaveAsMenuItem->Name = L"SaveAsMenuItem";
			this->SaveAsMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->SaveAsMenuItem->Size = System::Drawing::Size(186, 22);
			this->SaveAsMenuItem->Text = L"Save As";
			this->SaveAsMenuItem->Click += gcnew System::EventHandler(this, &Form1::SaveAsMenuItem_Click);
			// 
			// updateMX916KeywordsToolStripMenuItem
			// 
			this->updateMX916KeywordsToolStripMenuItem->Name = L"updateMX916KeywordsToolStripMenuItem";
			this->updateMX916KeywordsToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->updateMX916KeywordsToolStripMenuItem->Text = L"Update MX916";
			this->updateMX916KeywordsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::updateMX916KeywordsToolStripMenuItem_Click);
			// 
			// ExitMenuItem
			// 
			this->ExitMenuItem->Name = L"ExitMenuItem";
			this->ExitMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->ExitMenuItem->Size = System::Drawing::Size(186, 22);
			this->ExitMenuItem->Text = L"Exit";
			this->ExitMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExitMenuItem_Click);
			// 
			// camerasToolStripMenuItem
			// 
			this->camerasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->imagingCCDToolStripMenuItem,
					this->spectrographCCDToolStripMenuItem, this->trackiToolStripMenuItem
			});
			this->camerasToolStripMenuItem->Name = L"camerasToolStripMenuItem";
			this->camerasToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->camerasToolStripMenuItem->Text = L"Cameras";
			// 
			// imagingCCDToolStripMenuItem
			// 
			this->imagingCCDToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ImagingEstablishLinkMenuItem,
					this->ImagingCloseLinkStripMenuItem, this->ImagingTurnOnTempRegMenuItem, this->ImagingTurnOffTempRegMenuItem
			});
			this->imagingCCDToolStripMenuItem->Name = L"imagingCCDToolStripMenuItem";
			this->imagingCCDToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->imagingCCDToolStripMenuItem->Text = L"Imaging CCD";
			// 
			// ImagingEstablishLinkMenuItem
			// 
			this->ImagingEstablishLinkMenuItem->Name = L"ImagingEstablishLinkMenuItem";
			this->ImagingEstablishLinkMenuItem->Size = System::Drawing::Size(174, 22);
			this->ImagingEstablishLinkMenuItem->Text = L"Establish Link";
			this->ImagingEstablishLinkMenuItem->Click += gcnew System::EventHandler(this, &Form1::ImagingEstablishLinkMenuItem_Click);
			// 
			// ImagingCloseLinkStripMenuItem
			// 
			this->ImagingCloseLinkStripMenuItem->Name = L"ImagingCloseLinkStripMenuItem";
			this->ImagingCloseLinkStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->ImagingCloseLinkStripMenuItem->Text = L"Close Link";
			this->ImagingCloseLinkStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ImagingCloseLinkStripMenuItem_Click);
			// 
			// ImagingTurnOnTempRegMenuItem
			// 
			this->ImagingTurnOnTempRegMenuItem->Name = L"ImagingTurnOnTempRegMenuItem";
			this->ImagingTurnOnTempRegMenuItem->Size = System::Drawing::Size(174, 22);
			this->ImagingTurnOnTempRegMenuItem->Text = L"Turn on temp. reg.";
			this->ImagingTurnOnTempRegMenuItem->Click += gcnew System::EventHandler(this, &Form1::ImagingTurnOnTempRegMenuItem_Click);
			// 
			// ImagingTurnOffTempRegMenuItem
			// 
			this->ImagingTurnOffTempRegMenuItem->Name = L"ImagingTurnOffTempRegMenuItem";
			this->ImagingTurnOffTempRegMenuItem->Size = System::Drawing::Size(174, 22);
			this->ImagingTurnOffTempRegMenuItem->Text = L"Turn off temp. reg.";
			this->ImagingTurnOffTempRegMenuItem->Click += gcnew System::EventHandler(this, &Form1::ImagingTurnOffTempRegMenuItem_Click);
			// 
			// spectrographCCDToolStripMenuItem
			// 
			this->spectrographCCDToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->SpectroEstablishLinkMenuItem,
					this->SpectroCloseLinkMenuItem1, this->SpectroTurnOnTempRegMenuItem1, this->SpectroTurnOffTempRegMenuItem1
			});
			this->spectrographCCDToolStripMenuItem->Name = L"spectrographCCDToolStripMenuItem";
			this->spectrographCCDToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->spectrographCCDToolStripMenuItem->Text = L"Spectrograph CCD";
			// 
			// SpectroEstablishLinkMenuItem
			// 
			this->SpectroEstablishLinkMenuItem->Name = L"SpectroEstablishLinkMenuItem";
			this->SpectroEstablishLinkMenuItem->Size = System::Drawing::Size(174, 22);
			this->SpectroEstablishLinkMenuItem->Text = L"Establish Link";
			this->SpectroEstablishLinkMenuItem->Click += gcnew System::EventHandler(this, &Form1::SpectroEstablishLinkMenuItem_Click);
			// 
			// SpectroCloseLinkMenuItem1
			// 
			this->SpectroCloseLinkMenuItem1->Name = L"SpectroCloseLinkMenuItem1";
			this->SpectroCloseLinkMenuItem1->Size = System::Drawing::Size(174, 22);
			this->SpectroCloseLinkMenuItem1->Text = L"Close Link";
			this->SpectroCloseLinkMenuItem1->Click += gcnew System::EventHandler(this, &Form1::SpectroCloseLinkMenuItem1_Click);
			// 
			// SpectroTurnOnTempRegMenuItem1
			// 
			this->SpectroTurnOnTempRegMenuItem1->Name = L"SpectroTurnOnTempRegMenuItem1";
			this->SpectroTurnOnTempRegMenuItem1->Size = System::Drawing::Size(174, 22);
			this->SpectroTurnOnTempRegMenuItem1->Text = L"Turn on temp. reg.";
			this->SpectroTurnOnTempRegMenuItem1->Click += gcnew System::EventHandler(this, &Form1::SpectroTurnOnTempRegMenuItem1_Click);
			// 
			// SpectroTurnOffTempRegMenuItem1
			// 
			this->SpectroTurnOffTempRegMenuItem1->Name = L"SpectroTurnOffTempRegMenuItem1";
			this->SpectroTurnOffTempRegMenuItem1->Size = System::Drawing::Size(174, 22);
			this->SpectroTurnOffTempRegMenuItem1->Text = L"Turn off temp. reg.";
			this->SpectroTurnOffTempRegMenuItem1->Click += gcnew System::EventHandler(this, &Form1::SpectroTurnOffTempRegMenuItem1_Click);
			// 
			// trackiToolStripMenuItem
			// 
			this->trackiToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->TrackingEstablishLinkToolStripMenuItem,
					this->TrackingCloseLinkToolStripMenuItem
			});
			this->trackiToolStripMenuItem->Name = L"trackiToolStripMenuItem";
			this->trackiToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->trackiToolStripMenuItem->Text = L"Tracking/Slit CCD";
			// 
			// TrackingEstablishLinkToolStripMenuItem
			// 
			this->TrackingEstablishLinkToolStripMenuItem->Name = L"TrackingEstablishLinkToolStripMenuItem";
			this->TrackingEstablishLinkToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->TrackingEstablishLinkToolStripMenuItem->Text = L"Establish Link";
			this->TrackingEstablishLinkToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::TrackingEstablishLinkToolStripMenuItem_Click);
			// 
			// TrackingCloseLinkToolStripMenuItem
			// 
			this->TrackingCloseLinkToolStripMenuItem->Name = L"TrackingCloseLinkToolStripMenuItem";
			this->TrackingCloseLinkToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->TrackingCloseLinkToolStripMenuItem->Text = L"Close Link";
			this->TrackingCloseLinkToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::TrackingCloseLinkToolStripMenuItem_Click);
			// 
			// filterToolStripMenuItem
			// 
			this->filterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->BToolStripMenuItem,
					this->VToolStripMenuItem, this->RToolStripMenuItem, this->IToolStripMenuItem, this->HToolStripMenuItem, this->GToolStripMenuItem,
					this->CToolStripMenuItem
			});
			this->filterToolStripMenuItem->Name = L"filterToolStripMenuItem";
			this->filterToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->filterToolStripMenuItem->Text = L"Filter";
			// 
			// BToolStripMenuItem
			// 
			this->BToolStripMenuItem->Name = L"BToolStripMenuItem";
			this->BToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->BToolStripMenuItem->Text = L"B   (blue)";
			this->BToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::BToolStripMenuItem_Click);
			// 
			// VToolStripMenuItem
			// 
			this->VToolStripMenuItem->Name = L"VToolStripMenuItem";
			this->VToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->VToolStripMenuItem->Text = L"V   (green)";
			this->VToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::VToolStripMenuItem_Click);
			// 
			// RToolStripMenuItem
			// 
			this->RToolStripMenuItem->Name = L"RToolStripMenuItem";
			this->RToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->RToolStripMenuItem->Text = L"R   (red)";
			this->RToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::RToolStripMenuItem_Click);
			// 
			// IToolStripMenuItem
			// 
			this->IToolStripMenuItem->Name = L"IToolStripMenuItem";
			this->IToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->IToolStripMenuItem->Text = L"I   (infrared)";
			this->IToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::IToolStripMenuItem_Click);
			// 
			// HToolStripMenuItem
			// 
			this->HToolStripMenuItem->Name = L"HToolStripMenuItem";
			this->HToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->HToolStripMenuItem->Text = L"H   (H-Alpha)";
			this->HToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::HToolStripMenuItem_Click);
			// 
			// GToolStripMenuItem
			// 
			this->GToolStripMenuItem->Name = L"GToolStripMenuItem";
			this->GToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->GToolStripMenuItem->Text = L"G  (Grating)";
			this->GToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::GToolStripMenuItem_Click);
			// 
			// CToolStripMenuItem
			// 
			this->CToolStripMenuItem->Name = L"CToolStripMenuItem";
			this->CToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->CToolStripMenuItem->Text = L"C   (Empty or Clear)";
			this->CToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::CToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->ObservatoryMenuItem,
					this->ShowCurrentImageMenuItem, this->showPhotometryPlotToolStripMenuItem, this->GuidingSlitImageMenuItem, this->CamerasMenuItem1,
					this->setBaseFolderToolStripMenuItem, this->onOffDebugModeToolStripMenuItem, this->onOffImageProgressToolStripMenuItem, this->onOffAskSaveImageToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// ObservatoryMenuItem
			// 
			this->ObservatoryMenuItem->Name = L"ObservatoryMenuItem";
			this->ObservatoryMenuItem->Size = System::Drawing::Size(197, 22);
			this->ObservatoryMenuItem->Text = L"Observatory";
			this->ObservatoryMenuItem->Click += gcnew System::EventHandler(this, &Form1::ObservatoryMenuItem_Click);
			// 
			// ShowCurrentImageMenuItem
			// 
			this->ShowCurrentImageMenuItem->Name = L"ShowCurrentImageMenuItem";
			this->ShowCurrentImageMenuItem->Size = System::Drawing::Size(197, 22);
			this->ShowCurrentImageMenuItem->Text = L"Show Current Image";
			this->ShowCurrentImageMenuItem->Click += gcnew System::EventHandler(this, &Form1::ShowCurrentImageMenuItem_Click);
			// 
			// showPhotometryPlotToolStripMenuItem
			// 
			this->showPhotometryPlotToolStripMenuItem->Name = L"showPhotometryPlotToolStripMenuItem";
			this->showPhotometryPlotToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->showPhotometryPlotToolStripMenuItem->Text = L"Show Photometry Plot";
			this->showPhotometryPlotToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showPhotometryPlotToolStripMenuItem_Click);
			// 
			// GuidingSlitImageMenuItem
			// 
			this->GuidingSlitImageMenuItem->Name = L"GuidingSlitImageMenuItem";
			this->GuidingSlitImageMenuItem->Size = System::Drawing::Size(197, 22);
			this->GuidingSlitImageMenuItem->Text = L"Guiding/Slit Image";
			this->GuidingSlitImageMenuItem->Click += gcnew System::EventHandler(this, &Form1::GuidingSlitImageMenuItem_Click);
			// 
			// CamerasMenuItem1
			// 
			this->CamerasMenuItem1->Name = L"CamerasMenuItem1";
			this->CamerasMenuItem1->Size = System::Drawing::Size(197, 22);
			this->CamerasMenuItem1->Text = L"Cameras";
			this->CamerasMenuItem1->Click += gcnew System::EventHandler(this, &Form1::CamerasMenuItem1_Click);
			// 
			// setBaseFolderToolStripMenuItem
			// 
			this->setBaseFolderToolStripMenuItem->Name = L"setBaseFolderToolStripMenuItem";
			this->setBaseFolderToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->setBaseFolderToolStripMenuItem->Text = L"Set Base Folder";
			this->setBaseFolderToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::SetBaseFolder_Click);
			// 
			// onOffDebugModeToolStripMenuItem
			// 
			this->onOffDebugModeToolStripMenuItem->Name = L"onOffDebugModeToolStripMenuItem";
			this->onOffDebugModeToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->onOffDebugModeToolStripMenuItem->Text = L"On/Off Debug Mode";
			this->onOffDebugModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::onOffDebugModeToolStripMenuItem_Click);
			// 
			// onOffImageProgressToolStripMenuItem
			// 
			this->onOffImageProgressToolStripMenuItem->Name = L"onOffImageProgressToolStripMenuItem";
			this->onOffImageProgressToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->onOffImageProgressToolStripMenuItem->Text = L"On/Off Image Progress";
			this->onOffImageProgressToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::onOffImageProgressToolStripMenuItem_Click);
			// 
			// onOffAskSaveImageToolStripMenuItem
			// 
			this->onOffAskSaveImageToolStripMenuItem->Name = L"onOffAskSaveImageToolStripMenuItem";
			this->onOffAskSaveImageToolStripMenuItem->Size = System::Drawing::Size(197, 22);
			this->onOffAskSaveImageToolStripMenuItem->Text = L"On/Off Ask Save Image";
			this->onOffAskSaveImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::onOffAskSaveImageToolStripMenuItem_Click);
			// 
			// executeToolStripMenuItem
			// 
			this->executeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->ExposeSingleFrameMenuItem,
					this->ExposeDarkFramesMenuItem, this->ExposeFlatFramesMenuItem, this->ExposeSeriesOfFramesMenuItem, this->ExposeStackFramesMenuItem
			});
			this->executeToolStripMenuItem->Name = L"executeToolStripMenuItem";
			this->executeToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->executeToolStripMenuItem->Text = L"Execute";
			// 
			// ExposeSingleFrameMenuItem
			// 
			this->ExposeSingleFrameMenuItem->Name = L"ExposeSingleFrameMenuItem";
			this->ExposeSingleFrameMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->ExposeSingleFrameMenuItem->Size = System::Drawing::Size(217, 22);
			this->ExposeSingleFrameMenuItem->Text = L"Expose Single Frame";
			this->ExposeSingleFrameMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExposeSingleFrameMenuItem_Click);
			// 
			// ExposeDarkFramesMenuItem
			// 
			this->ExposeDarkFramesMenuItem->Name = L"ExposeDarkFramesMenuItem";
			this->ExposeDarkFramesMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F2;
			this->ExposeDarkFramesMenuItem->Size = System::Drawing::Size(217, 22);
			this->ExposeDarkFramesMenuItem->Text = L"Expose Dark Frames";
			this->ExposeDarkFramesMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExposeDarkFramesMenuItem_Click);
			// 
			// ExposeFlatFramesMenuItem
			// 
			this->ExposeFlatFramesMenuItem->Name = L"ExposeFlatFramesMenuItem";
			this->ExposeFlatFramesMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F3;
			this->ExposeFlatFramesMenuItem->Size = System::Drawing::Size(217, 22);
			this->ExposeFlatFramesMenuItem->Text = L"Expose Flat Frames";
			this->ExposeFlatFramesMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExposeFlatFramesMenuItem_Click);
			// 
			// ExposeSeriesOfFramesMenuItem
			// 
			this->ExposeSeriesOfFramesMenuItem->Name = L"ExposeSeriesOfFramesMenuItem";
			this->ExposeSeriesOfFramesMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F4;
			this->ExposeSeriesOfFramesMenuItem->Size = System::Drawing::Size(217, 22);
			this->ExposeSeriesOfFramesMenuItem->Text = L"Expose Series of Frames";
			this->ExposeSeriesOfFramesMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExposeSeriesOfFramesMenuItem_Click);
			// 
			// ExposeStackFramesMenuItem
			// 
			this->ExposeStackFramesMenuItem->Name = L"ExposeStackFramesMenuItem";
			this->ExposeStackFramesMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->ExposeStackFramesMenuItem->Size = System::Drawing::Size(217, 22);
			this->ExposeStackFramesMenuItem->Text = L"Expose Stack Frames";
			this->ExposeStackFramesMenuItem->Click += gcnew System::EventHandler(this, &Form1::ExposeStackFramesMenuItem_Click);
			// 
			// ObjectsMenuItem
			// 
			this->ObjectsMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->viewEditObjectListToolStripMenuItem });
			this->ObjectsMenuItem->Name = L"ObjectsMenuItem";
			this->ObjectsMenuItem->Size = System::Drawing::Size(59, 20);
			this->ObjectsMenuItem->Text = L"Objects";
			// 
			// viewEditObjectListToolStripMenuItem
			// 
			this->viewEditObjectListToolStripMenuItem->Name = L"viewEditObjectListToolStripMenuItem";
			this->viewEditObjectListToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->viewEditObjectListToolStripMenuItem->Text = L"View/Edit Object List";
			this->viewEditObjectListToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::viewEditObjectListToolStripMenuItem_Click);
			// 
			// HelpMenuItem
			// 
			this->HelpMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->HelpMenuItem->Name = L"HelpMenuItem";
			this->HelpMenuItem->Size = System::Drawing::Size(44, 20);
			this->HelpMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// StatusRichTextBox
			// 
			this->StatusRichTextBox->BackColor = System::Drawing::Color::White;
			this->StatusRichTextBox->Location = System::Drawing::Point(0, 43);
			this->StatusRichTextBox->Name = L"StatusRichTextBox";
			this->StatusRichTextBox->ReadOnly = true;
			this->StatusRichTextBox->Size = System::Drawing::Size(691, 173);
			this->StatusRichTextBox->TabIndex = 1;
			this->StatusRichTextBox->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(269, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"CCDAuto Status Log";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->CurrentSeriesGroupBox, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->CurrentImageGroupBox, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 222);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(691, 245);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// CurrentSeriesGroupBox
			// 
			this->CurrentSeriesGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CurrentSeriesGroupBox->Controls->Add(this->tableLayoutPanel4);
			this->CurrentSeriesGroupBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->CurrentSeriesGroupBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->CurrentSeriesGroupBox->Location = System::Drawing::Point(463, 3);
			this->CurrentSeriesGroupBox->MinimumSize = System::Drawing::Size(200, 150);
			this->CurrentSeriesGroupBox->Name = L"CurrentSeriesGroupBox";
			this->CurrentSeriesGroupBox->Size = System::Drawing::Size(225, 236);
			this->CurrentSeriesGroupBox->TabIndex = 2;
			this->CurrentSeriesGroupBox->TabStop = false;
			this->CurrentSeriesGroupBox->Text = L"Current Series";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->StopSeriesButton, 1, 6);
			this->tableLayoutPanel4->Controls->Add(this->label18, 0, 5);
			this->tableLayoutPanel4->Controls->Add(this->CurrentSeriesStatusTextBox, 1, 3);
			this->tableLayoutPanel4->Controls->Add(this->label13, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->CurrentSeriesFileNameTextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->label14, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->ProcessingSeqNumTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->label15, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->label16, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->ProcessingExpNumTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->label17, 0, 4);
			this->tableLayoutPanel4->Controls->Add(this->TimeToNextExpTextBox, 1, 4);
			this->tableLayoutPanel4->Controls->Add(this->TimeToSeriesEndTextBox, 1, 5);
			this->tableLayoutPanel4->Controls->Add(this->PauseResumeSeriesButton, 0, 6);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 7;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(219, 217);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// StopSeriesButton
			// 
			this->StopSeriesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StopSeriesButton->Location = System::Drawing::Point(126, 187);
			this->StopSeriesButton->Name = L"StopSeriesButton";
			this->StopSeriesButton->Size = System::Drawing::Size(75, 23);
			this->StopSeriesButton->TabIndex = 13;
			this->StopSeriesButton->Text = L"Stop";
			this->StopSeriesButton->UseVisualStyleBackColor = true;
			this->StopSeriesButton->Click += gcnew System::EventHandler(this, &Form1::StopSeriesButton_Clicked);
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 159);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(96, 13);
			this->label18->TabIndex = 11;
			this->label18->Text = L"Time to series end:";
			// 
			// CurrentSeriesStatusTextBox
			// 
			this->CurrentSeriesStatusTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentSeriesStatusTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentSeriesStatusTextBox->Location = System::Drawing::Point(112, 93);
			this->CurrentSeriesStatusTextBox->Name = L"CurrentSeriesStatusTextBox";
			this->CurrentSeriesStatusTextBox->ReadOnly = true;
			this->CurrentSeriesStatusTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentSeriesStatusTextBox->TabIndex = 7;
			this->CurrentSeriesStatusTextBox->WordWrap = false;
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(34, 97);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(40, 13);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Status:";
			// 
			// CurrentSeriesFileNameTextBox
			// 
			this->CurrentSeriesFileNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentSeriesFileNameTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentSeriesFileNameTextBox->Location = System::Drawing::Point(112, 62);
			this->CurrentSeriesFileNameTextBox->Name = L"CurrentSeriesFileNameTextBox";
			this->CurrentSeriesFileNameTextBox->ReadOnly = true;
			this->CurrentSeriesFileNameTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentSeriesFileNameTextBox->TabIndex = 5;
			this->CurrentSeriesFileNameTextBox->WordWrap = false;
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(26, 66);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(57, 13);
			this->label14->TabIndex = 4;
			this->label14->Text = L"File Name:";
			// 
			// ProcessingSeqNumTextBox
			// 
			this->ProcessingSeqNumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ProcessingSeqNumTextBox->BackColor = System::Drawing::Color::White;
			this->ProcessingSeqNumTextBox->Location = System::Drawing::Point(112, 31);
			this->ProcessingSeqNumTextBox->Name = L"ProcessingSeqNumTextBox";
			this->ProcessingSeqNumTextBox->ReadOnly = true;
			this->ProcessingSeqNumTextBox->Size = System::Drawing::Size(100, 20);
			this->ProcessingSeqNumTextBox->TabIndex = 3;
			this->ProcessingSeqNumTextBox->WordWrap = false;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(7, 35);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(94, 13);
			this->label15->TabIndex = 2;
			this->label15->Text = L"Processing Seq #:";
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(8, 6);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(93, 13);
			this->label16->TabIndex = 0;
			this->label16->Text = L"Processing Exp #:";
			// 
			// ProcessingExpNumTextBox
			// 
			this->ProcessingExpNumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ProcessingExpNumTextBox->BackColor = System::Drawing::Color::White;
			this->ProcessingExpNumTextBox->Location = System::Drawing::Point(112, 3);
			this->ProcessingExpNumTextBox->Name = L"ProcessingExpNumTextBox";
			this->ProcessingExpNumTextBox->ReadOnly = true;
			this->ProcessingExpNumTextBox->Size = System::Drawing::Size(100, 20);
			this->ProcessingExpNumTextBox->TabIndex = 1;
			this->ProcessingExpNumTextBox->WordWrap = false;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(10, 128);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(89, 13);
			this->label17->TabIndex = 8;
			this->label17->Text = L"Time to next Exp:";
			// 
			// TimeToNextExpTextBox
			// 
			this->TimeToNextExpTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TimeToNextExpTextBox->BackColor = System::Drawing::Color::White;
			this->TimeToNextExpTextBox->Location = System::Drawing::Point(112, 124);
			this->TimeToNextExpTextBox->Name = L"TimeToNextExpTextBox";
			this->TimeToNextExpTextBox->ReadOnly = true;
			this->TimeToNextExpTextBox->Size = System::Drawing::Size(100, 20);
			this->TimeToNextExpTextBox->TabIndex = 9;
			this->TimeToNextExpTextBox->WordWrap = false;
			// 
			// TimeToSeriesEndTextBox
			// 
			this->TimeToSeriesEndTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->TimeToSeriesEndTextBox->BackColor = System::Drawing::Color::White;
			this->TimeToSeriesEndTextBox->Location = System::Drawing::Point(112, 155);
			this->TimeToSeriesEndTextBox->Name = L"TimeToSeriesEndTextBox";
			this->TimeToSeriesEndTextBox->ReadOnly = true;
			this->TimeToSeriesEndTextBox->Size = System::Drawing::Size(100, 20);
			this->TimeToSeriesEndTextBox->TabIndex = 10;
			this->TimeToSeriesEndTextBox->WordWrap = false;
			// 
			// PauseResumeSeriesButton
			// 
			this->PauseResumeSeriesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PauseResumeSeriesButton->Location = System::Drawing::Point(9, 187);
			this->PauseResumeSeriesButton->Name = L"PauseResumeSeriesButton";
			this->PauseResumeSeriesButton->Size = System::Drawing::Size(90, 23);
			this->PauseResumeSeriesButton->TabIndex = 12;
			this->PauseResumeSeriesButton->Text = L"Pause/Resume";
			this->PauseResumeSeriesButton->UseVisualStyleBackColor = true;
			this->PauseResumeSeriesButton->Click += gcnew System::EventHandler(this, &Form1::PauseResumeSeriesButton_Clicked);
			// 
			// CurrentImageGroupBox
			// 
			this->CurrentImageGroupBox->Controls->Add(this->tableLayoutPanel3);
			this->CurrentImageGroupBox->Location = System::Drawing::Point(233, 3);
			this->CurrentImageGroupBox->Name = L"CurrentImageGroupBox";
			this->CurrentImageGroupBox->Size = System::Drawing::Size(224, 190);
			this->CurrentImageGroupBox->TabIndex = 1;
			this->CurrentImageGroupBox->TabStop = false;
			this->CurrentImageGroupBox->Text = L"Current Image";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->label12, 0, 6);
			this->tableLayoutPanel3->Controls->Add(this->label6, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageExposeTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->label7, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageBinningTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->label8, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageWhichCCDTextBox, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->label9, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageFrameSizeTextBox, 1, 3);
			this->tableLayoutPanel3->Controls->Add(this->label10, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageFileNameTextBox, 1, 4);
			this->tableLayoutPanel3->Controls->Add(this->label11, 0, 5);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageObjectNameTextBox, 1, 5);
			this->tableLayoutPanel3->Controls->Add(this->CurrentImageDirectoryTextBox, 1, 6);
			this->tableLayoutPanel3->Location = System::Drawing::Point(6, 13);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 7;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(218, 171);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(11, 151);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(86, 13);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Object Directory:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(14, 5);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Exposure (sec):";
			// 
			// CurrentImageExposeTextBox
			// 
			this->CurrentImageExposeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageExposeTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageExposeTextBox->Location = System::Drawing::Point(112, 3);
			this->CurrentImageExposeTextBox->Name = L"CurrentImageExposeTextBox";
			this->CurrentImageExposeTextBox->ReadOnly = true;
			this->CurrentImageExposeTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageExposeTextBox->TabIndex = 2;
			this->CurrentImageExposeTextBox->WordWrap = false;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(32, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 13);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Binning:";
			// 
			// CurrentImageBinningTextBox
			// 
			this->CurrentImageBinningTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageBinningTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageBinningTextBox->Location = System::Drawing::Point(112, 27);
			this->CurrentImageBinningTextBox->Name = L"CurrentImageBinningTextBox";
			this->CurrentImageBinningTextBox->ReadOnly = true;
			this->CurrentImageBinningTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageBinningTextBox->TabIndex = 4;
			this->CurrentImageBinningTextBox->WordWrap = false;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 53);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Which CCD:";
			// 
			// CurrentImageWhichCCDTextBox
			// 
			this->CurrentImageWhichCCDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageWhichCCDTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageWhichCCDTextBox->Location = System::Drawing::Point(112, 51);
			this->CurrentImageWhichCCDTextBox->Name = L"CurrentImageWhichCCDTextBox";
			this->CurrentImageWhichCCDTextBox->ReadOnly = true;
			this->CurrentImageWhichCCDTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageWhichCCDTextBox->TabIndex = 6;
			this->CurrentImageWhichCCDTextBox->WordWrap = false;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(23, 77);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(62, 13);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Frame Size:";
			// 
			// CurrentImageFrameSizeTextBox
			// 
			this->CurrentImageFrameSizeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageFrameSizeTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageFrameSizeTextBox->Location = System::Drawing::Point(112, 75);
			this->CurrentImageFrameSizeTextBox->Name = L"CurrentImageFrameSizeTextBox";
			this->CurrentImageFrameSizeTextBox->ReadOnly = true;
			this->CurrentImageFrameSizeTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageFrameSizeTextBox->TabIndex = 8;
			this->CurrentImageFrameSizeTextBox->WordWrap = false;
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(26, 101);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(57, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"File Name:";
			// 
			// CurrentImageFileNameTextBox
			// 
			this->CurrentImageFileNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageFileNameTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageFileNameTextBox->Location = System::Drawing::Point(112, 99);
			this->CurrentImageFileNameTextBox->Name = L"CurrentImageFileNameTextBox";
			this->CurrentImageFileNameTextBox->ReadOnly = true;
			this->CurrentImageFileNameTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageFileNameTextBox->TabIndex = 10;
			this->CurrentImageFileNameTextBox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(18, 125);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(72, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Object Name:";
			// 
			// CurrentImageObjectNameTextBox
			// 
			this->CurrentImageObjectNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageObjectNameTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageObjectNameTextBox->Location = System::Drawing::Point(112, 123);
			this->CurrentImageObjectNameTextBox->Name = L"CurrentImageObjectNameTextBox";
			this->CurrentImageObjectNameTextBox->ReadOnly = true;
			this->CurrentImageObjectNameTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageObjectNameTextBox->TabIndex = 12;
			this->CurrentImageObjectNameTextBox->WordWrap = false;
			// 
			// CurrentImageDirectoryTextBox
			// 
			this->CurrentImageDirectoryTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CurrentImageDirectoryTextBox->BackColor = System::Drawing::Color::White;
			this->CurrentImageDirectoryTextBox->Location = System::Drawing::Point(112, 147);
			this->CurrentImageDirectoryTextBox->Name = L"CurrentImageDirectoryTextBox";
			this->CurrentImageDirectoryTextBox->ReadOnly = true;
			this->CurrentImageDirectoryTextBox->Size = System::Drawing::Size(100, 20);
			this->CurrentImageDirectoryTextBox->TabIndex = 14;
			this->CurrentImageDirectoryTextBox->WordWrap = false;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox6, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->CCDStatusGroupBox, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58.05085F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.94915F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(224, 239);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->tableLayoutPanel6);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox6->Location = System::Drawing::Point(3, 141);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(218, 95);
			this->groupBox6->TabIndex = 11;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Time";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 4;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				17.92453F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				26.88679F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.22642F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.49057F)));
			this->tableLayoutPanel6->Controls->Add(this->label22, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->UTTextBox, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->label21, 2, 0);
			this->tableLayoutPanel6->Controls->Add(this->LocalTextBox, 3, 0);
			this->tableLayoutPanel6->Controls->Add(this->label20, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->LSTTextBox, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->label19, 2, 1);
			this->tableLayoutPanel6->Controls->Add(this->JDTextBox, 3, 1);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(212, 76);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(3, 12);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(25, 13);
			this->label22->TabIndex = 0;
			this->label22->Text = L"UT:";
			// 
			// UTTextBox
			// 
			this->UTTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->UTTextBox->Location = System::Drawing::Point(41, 9);
			this->UTTextBox->Name = L"UTTextBox";
			this->UTTextBox->Size = System::Drawing::Size(50, 20);
			this->UTTextBox->TabIndex = 12;
			this->UTTextBox->Text = L"00:00:00";
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(101, 12);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(36, 13);
			this->label21->TabIndex = 11;
			this->label21->Text = L"Local:";
			// 
			// LocalTextBox
			// 
			this->LocalTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LocalTextBox->Location = System::Drawing::Point(143, 9);
			this->LocalTextBox->Name = L"LocalTextBox";
			this->LocalTextBox->Size = System::Drawing::Size(59, 20);
			this->LocalTextBox->TabIndex = 13;
			this->LocalTextBox->Text = L"00:00:00";
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(3, 50);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(30, 13);
			this->label20->TabIndex = 11;
			this->label20->Text = L"LST:";
			// 
			// LSTTextBox
			// 
			this->LSTTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LSTTextBox->Location = System::Drawing::Point(41, 47);
			this->LSTTextBox->Name = L"LSTTextBox";
			this->LSTTextBox->Size = System::Drawing::Size(50, 20);
			this->LSTTextBox->TabIndex = 14;
			this->LSTTextBox->Text = L"00:00:00";
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(105, 50);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(32, 13);
			this->label19->TabIndex = 15;
			this->label19->Text = L"MJD:";
			// 
			// JDTextBox
			// 
			this->JDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->JDTextBox->Location = System::Drawing::Point(143, 47);
			this->JDTextBox->Name = L"JDTextBox";
			this->JDTextBox->Size = System::Drawing::Size(66, 20);
			this->JDTextBox->TabIndex = 16;
			this->JDTextBox->Text = L"9999.99999";
			// 
			// CCDStatusGroupBox
			// 
			this->CCDStatusGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CCDStatusGroupBox->Controls->Add(this->tableLayoutPanel5);
			this->CCDStatusGroupBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->CCDStatusGroupBox->Location = System::Drawing::Point(3, 3);
			this->CCDStatusGroupBox->MinimumSize = System::Drawing::Size(200, 125);
			this->CCDStatusGroupBox->Name = L"CCDStatusGroupBox";
			this->CCDStatusGroupBox->Size = System::Drawing::Size(218, 130);
			this->CCDStatusGroupBox->TabIndex = 1;
			this->CCDStatusGroupBox->TabStop = false;
			this->CCDStatusGroupBox->Text = L"CCD Status";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->AutoSize = true;
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				38.07107F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				61.92893F)));
			this->tableLayoutPanel5->Controls->Add(this->CCDFilterTextBox, 1, 3);
			this->tableLayoutPanel5->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel5->Controls->Add(this->CCDCoolingTextBox, 1, 2);
			this->tableLayoutPanel5->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->CCDTempTextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->CCDStatusTextBox, 1, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 4;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(218, 113);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// CCDFilterTextBox
			// 
			this->CCDFilterTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDFilterTextBox->BackColor = System::Drawing::Color::White;
			this->CCDFilterTextBox->Location = System::Drawing::Point(85, 88);
			this->CCDFilterTextBox->Name = L"CCDFilterTextBox";
			this->CCDFilterTextBox->ReadOnly = true;
			this->CCDFilterTextBox->Size = System::Drawing::Size(100, 20);
			this->CCDFilterTextBox->TabIndex = 7;
			this->CCDFilterTextBox->WordWrap = false;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"CCD Filter:";
			// 
			// CCDCoolingTextBox
			// 
			this->CCDCoolingTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDCoolingTextBox->BackColor = System::Drawing::Color::White;
			this->CCDCoolingTextBox->Location = System::Drawing::Point(85, 60);
			this->CCDCoolingTextBox->Name = L"CCDCoolingTextBox";
			this->CCDCoolingTextBox->ReadOnly = true;
			this->CCDCoolingTextBox->Size = System::Drawing::Size(100, 20);
			this->CCDCoolingTextBox->TabIndex = 5;
			this->CCDCoolingTextBox->WordWrap = false;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"CCD Cooling:";
			// 
			// CCDTempTextBox
			// 
			this->CCDTempTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDTempTextBox->BackColor = System::Drawing::Color::White;
			this->CCDTempTextBox->Location = System::Drawing::Point(85, 32);
			this->CCDTempTextBox->Name = L"CCDTempTextBox";
			this->CCDTempTextBox->ReadOnly = true;
			this->CCDTempTextBox->Size = System::Drawing::Size(100, 20);
			this->CCDTempTextBox->TabIndex = 3;
			this->CCDTempTextBox->WordWrap = false;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"CCD Temp:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"CCD Status:";
			// 
			// CCDStatusTextBox
			// 
			this->CCDStatusTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDStatusTextBox->BackColor = System::Drawing::Color::White;
			this->CCDStatusTextBox->Location = System::Drawing::Point(85, 4);
			this->CCDStatusTextBox->Name = L"CCDStatusTextBox";
			this->CCDStatusTextBox->ReadOnly = true;
			this->CCDStatusTextBox->Size = System::Drawing::Size(100, 20);
			this->CCDStatusTextBox->TabIndex = 1;
			this->CCDStatusTextBox->WordWrap = false;
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->FileName = L"OpenFileDialog";
			// 
			// MainTimer
			// 
			this->MainTimer->Enabled = true;
			this->MainTimer->Interval = 1000;
			this->MainTimer->Tick += gcnew System::EventHandler(this, &Form1::MainTimerCallback);
			// 
			// DownloadTimer
			// 
			this->DownloadTimer->Interval = 1000;
			this->DownloadTimer->Tick += gcnew System::EventHandler(this, &Form1::DownloadTimerCallback);
			// 
			// FolderBrowserDialog
			// 
			this->FolderBrowserDialog->SelectedPath = L"c:\\Users\\shoup.31\\Documents\\Observatory\\ImageData";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 466);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->StatusRichTextBox);
			this->Controls->Add(this->MenuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->MenuStrip;
			this->Name = L"Form1";
			this->Text = L"CCDAuto";
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->CurrentSeriesGroupBox->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->CurrentImageGroupBox->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->CCDStatusGroupBox->ResumeLayout(false);
			this->CCDStatusGroupBox->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: void Form1ClosingEventHandler(Object^ sender, System::Windows::Forms::FormClosingEventArgs ^e) {
			 if (! ExitMenuItemClicked) {
					StatusPrint("*** Warning - Please exit using File->Exit Menu item (or control-c)...\n");
				   e->Cancel = true;
			 }
		   }

private: System::Void ExitMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int answer;
			 FILE *fptr;
			 char message[240];

			 /* If image active and not saved, ask if save wanted */

			 if (ccd->Image.light_frame.active && (! ccd->Image.saved)) {
				 answer = MessageBox("Current Image not saved, want to save it?", YESNO, true);
				 if (answer == CANCEL)
					 return;
				 if (answer == YES) {
					 SaveImage(false);
				 }
			 }

			 /* If camera linked, ask if unlink wanted */

			 if (ccd->Linked) {
				 answer = MessageBox("Camera still linked, want to unlink it?", YESNO, true);
				 if (answer == CANCEL)
					return;
				 if (answer == YES) {
					 doSetTempOffCamera(ccd);
					 ccd->Linked = false;
					 establish_link(ccd, false);
					 freeImageBuffers(ccd);
				 } else if (answer == NO) {
					 freeImageBuffers(ccd);
				 }
			 }

			 // Save auto focus settings

			 errno_t status = fopen_s(&fptr, DEFAULT_AUTOFOCUS_SETTINGS_FILENAME, "w");
			 if (status != 0) {
				 sprintf_s(message, sizeof(message), "*** Warning - can't write auto focus settings file: %s (ExitMenuItem)", DEFAULT_AUTOFOCUS_SETTINGS_FILENAME);
				 answer = MessageBox(message, OKAY, true);
			 } else {
				 fprintf_s(fptr, "%d  // Calibration run number of frames acquired per point\n", autoFocusSettings.CalNumFramesPerPoint);
				 fprintf_s(fptr, "%d  // Calibration run starting focus position\n", autoFocusSettings.CalStartFocusPosition);
				 fprintf_s(fptr, "%d  // Calibration run ending focus position\n", autoFocusSettings.CalEndFocusPosition);
				 fprintf_s(fptr, "%d  // Calibration run focus step size\n", autoFocusSettings.CalFocusStepSize);
				 fprintf_s(fptr, "%d  // Calibration run field size in pixels\n", autoFocusSettings.CalFieldSize);
				 fprintf_s(fptr, "%d  // Calibration run max star peak in adu\n", autoFocusSettings.CalMaxStarPeak);
				 fprintf_s(fptr, "%d  // Calibration run min star peak in adu\n", autoFocusSettings.CalMinStarPeak);
				 fprintf_s(fptr, "%lf  // Left V Curve Slope\n", autoFocusSettings.LeftVCurveSlope);
				 fprintf_s(fptr, "%lf  // Right V Curve Slope\n", autoFocusSettings.RightVCurveSlope);
				 fprintf_s(fptr, "%d  // Auto focusing frames per point\n", autoFocusSettings.NumFramesPerPoint);
				 fclose(fptr);
			 }


			 ExitMenuItemClicked = true;
			 Application::Exit();
		 }
private: System::Void OpenMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 char fileName[160], Message[160];
			 int i, Success;
			 this->OpenFileDialog->InitialDirectory = "C:Users\\shoup.31\\Documents\\Observatory\\ImageData";
			 this->OpenFileDialog->Filter = "fits files (*.fits)|*.fits|All files (*.*)|*.*";
			 this->OpenFileDialog->FilterIndex = 1;
			 this->OpenFileDialog->RestoreDirectory = true;
			 this->OpenFileDialog->FileName = "";
			 System::Windows::Forms::DialogResult res = this->OpenFileDialog->ShowDialog();
			 if ( res != System::Windows::Forms::DialogResult::OK)
				return;
			 String^ file = Form1::CCDAutoForm->OpenFileDialog->FileName;
			 for (i=0; i<file->Length; i++) fileName[i] = (char) file[i];
			 fileName[i] = '\0';
			 sprintf_s(Message,sizeof(Message),"*** Info - Loading image file %s\n",fileName);
			 StatusPrint(Message);
			 Success = readLight(fileName,&ccd->Image);
			 if (! Success) {
				 StatusPrint("*** Warning - Couldn't open image file...\n");
				 return;
			 }
			 StatusPrint("*** Info - Removing hot pixels...\n");
			 removeHotPixels(&ccd->Image.light_frame);
			 StatusPrint("*** Info - Displaying image...\n");
			 loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
				ccd->Image.light_frame.y, ccd->Image.light_frame.w,
				ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
			 ccd->Image.saved = true;
//			 updateStatusInfo();
		 }
private: System::Void openCalibrateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 char fileName[160], Message[160], DarkDir[MAX_SIZE_PATH_CHARS], FlatDir[MAX_SIZE_PATH_CHARS];
			 int i, Success, DarkOption, FlatOption;
			 String ^ImageDir;

			 // Ask user to update calibration settings, darks, flats, etc.

			 if (! OpenCalDialogExists) {
				 gcnew OpenCalDialog();
			 }
			 OpenCalDialog::ShowTheDialog();

			 if (strlen(singleSettings.ImageDir) > 0)
				 ImageDir = gcnew String(singleSettings.ImageDir);
			 else
				 ImageDir = gcnew String(DEFAULT_IMAGE_DIRECTORY);
			 this->OpenFileDialog->Title = "Open & Calibrate Image file";
			 this->OpenFileDialog->InitialDirectory = ImageDir;
			 delete ImageDir;
			 this->OpenFileDialog->Filter = "fits files (*.fits)|*.fits|All files (*.*)|*.*";
			 this->OpenFileDialog->FilterIndex = 1;
			 this->OpenFileDialog->RestoreDirectory = true;
			 this->OpenFileDialog->FileName = "";
			 System::Windows::Forms::DialogResult res = this->OpenFileDialog->ShowDialog();
			 if ( res != System::Windows::Forms::DialogResult::OK)
				return;
			 String^ file = Form1::CCDAutoForm->OpenFileDialog->FileName;
			 for (i=0; i<file->Length; i++) fileName[i] = (char) file[i];
			 fileName[i] = '\0';
			 sprintf_s(Message,sizeof(Message),"*** Info - Loading image file %s\n",fileName);
			 StatusPrint(Message);
			 Success = readLight(fileName,&ccd->Image);
			 if (! Success) {
				 StatusPrint("*** Warning - Couldn't open image file...\n");
				 return;
			 }
			 ccd->Image.saved = true;

			 // Do required calibrations

			 DarkOption = OpenCalDialog::FormPtr->DarkOption;
			 FlatOption = OpenCalDialog::FormPtr->FlatOption;
			 OpenCalDialog::FormPtr->GetDarkDirTextBox(DarkDir);
			 OpenCalDialog::FormPtr->GetFlatDirTextBox(FlatDir);

			 DoCalibrations(DarkDir, DarkOption, FlatDir, FlatOption, ccd);

			 StatusPrint("*** Info - Displaying image...\n");
			 loadImageImaging(ccd->Image.light_frame.frame, ccd->Image.light_frame.x,
				ccd->Image.light_frame.y, ccd->Image.light_frame.w,
				ccd->Image.light_frame.h, ccd->Image.light_frame.binning);
		 }
private: void SaveImage(bool as) {

 			 FILE *fptr;
			 char fileName[160], Message[160], Prompt[160];
			 int i;

			 if (as) { // Do a save-as save

				 // Prompt for file name

				 if (strlen(singleSettings.ImageDir) > 0) {
					 String^ dir = gcnew String(singleSettings.ImageDir);
					 this->SaveFileDialog->InitialDirectory = dir;
				 } else {
					this->SaveFileDialog->InitialDirectory = "";
				 }
				 this->SaveFileDialog->Filter = "fits files (*.fits)|*.fits|All files (*.*)|*.*";
				 this->SaveFileDialog->FilterIndex = 1;
				 this->SaveFileDialog->RestoreDirectory = false;
				 do {
					System::Windows::Forms::DialogResult res = this->SaveFileDialog->ShowDialog();
					if ( res != System::Windows::Forms::DialogResult::OK)
						return;
					String^ file = Form1::CCDAutoForm->SaveFileDialog->FileName;
					for (i=0; i<file->Length; i++) fileName[i] = (char) file[i];
					fileName[i] = '\0';
					fopen_s(&fptr, fileName, "rb");

					// If file doesn't exist, just save and return

					if (fptr == NULL) { 
						writeFITS(&ccd->Image, 1, fileName, ccd->Image.ObjectName);
						sprintf_s(Message,sizeof(Message),"*** Info - Image file %s saved\n",fileName);
						StatusPrint(Message);
						return;
					}

					// If file does exist ask if user wants to overwrite

					fclose(fptr);
					if (! OverWriteDialogExists)
						gcnew OverWriteDialog();
					sprintf_s(Prompt,sizeof(Prompt),"File %s exists, overwrite it?",fileName);
					OverWriteDialog::ShowTheDialog(Prompt);
					switch (OverWriteDialogAnswer) {
						case CANCEL:  // do nothing & return
							return;
							break;
						case YES: // overwrite file & return
							_unlink(fileName);
							writeFITS(&ccd->Image, 1, fileName, ccd->Image.ObjectName);
							sprintf_s(Message,sizeof(Message),"*** Info - Saving image file %s\n",fileName);
							StatusPrint(Message);
							return;
							break;
						case NO: // display save file dialog again
							break;
					}
				 } while (true);

			 } else {  // Do just a save

				 // If saved already, just overwrite

				 if (strlen(ccd->Image.FileName) != 0) {
					 _unlink(ccd->Image.FileName);
					 writeFITS(&ccd->Image, 1, ccd->Image.FileName, ccd->Image.ObjectName);
					 sprintf_s(Message,sizeof(Message),"*** Info - Image file %s saved\n",
							ccd->Image.FileName);
					 StatusPrint(Message);
					 return;
				 }

				 // If not saved already, prompt for file name

				 if (strlen(singleSettings.ImageDir) > 0) {
					 String^ dir = gcnew String(singleSettings.ImageDir);
					 this->SaveFileDialog->InitialDirectory = dir;
				 } else {
					this->SaveFileDialog->InitialDirectory = "";
				 }
				 this->SaveFileDialog->Filter = "fit files (*.fits)|*.fits|All files (*.*)|*.*";
				 this->SaveFileDialog->FilterIndex = 1;
				 this->SaveFileDialog->RestoreDirectory = true;
				 do {
					 System::Windows::Forms::DialogResult res = this->SaveFileDialog->ShowDialog();
					 if ( res != System::Windows::Forms::DialogResult::OK)
						return;
					 String^ file = Form1::CCDAutoForm->SaveFileDialog->FileName;
					 for (i=0; i<file->Length; i++) fileName[i] = (char) file[i];
					 fileName[i] = '\0';
					 fopen_s(&fptr, fileName, "rb");

					 // If file doesn't exist, just save and return

					 if (fptr == NULL) {
						 writeFITS(&ccd->Image, 1, fileName, ccd->Image.ObjectName);
						 sprintf_s(Message,sizeof(Message),"*** Info - Image file %s saved\n",fileName);
						 StatusPrint(Message);
						 return;
					 }

					 // If file does exist ask if user wants to overwrite

					 fclose(fptr);
					 if (! OverWriteDialogExists)
						gcnew OverWriteDialog();
					 sprintf_s(Prompt,sizeof(Prompt),"File %s exists, overwrite it?",fileName);
					 OverWriteDialog::ShowTheDialog(Prompt);
					 switch (OverWriteDialogAnswer) {
						case CANCEL:  // do nothing & return
							return;
							break;
						case YES: // overwrite file & return
							_unlink(fileName);
							writeFITS(&ccd->Image, 1, fileName, ccd->Image.ObjectName);
							sprintf_s(Message,sizeof(Message),"*** Info - Saving image file %s\n",fileName);
							StatusPrint(Message);
							return;
							break;
						case NO: // display save file dialog again
							break;
					 }
				 } while (true);
			 }
		 }
private: System::Void SaveMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveImage(false);
		 }
private: System::Void SaveAsMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveImage(true);
		 }
private: System::Void ImagingEstablishLinkMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int i, Linked, status;

			 if (ImagingCCD.Linked) {
				 StatusPrint("*** INFO - Already Linked to imaging ccd\n");
				 return;
			 } else if (SpectroCCD.Linked) {
				 StatusPrint("*** WARNING - Already Linked to Spectro CCD, can only "
					 "hand one CCD at a time...\n");
				 return;
			 }

			 /* Link to camera, try at most 4 times */

			 ccd = &ImagingCCD;
			 strcpy_s(ccd->name, sizeof(ccd->name), ccdSettings.ImagingType);
			 strcpy_s(ccd->port, sizeof(ccd->port), ccdSettings.ImagingPort);

			 Linked = false;
			 for (i=0; i<4; i++) {
				 Linked = establish_link(ccd, true);
				 if (Linked)
					 break;
				 usleep(100000);
			 }
			 if (! Linked) {
				 StatusPrint("*** WARNING - Can't open camera, giving up...\n");
				 return;
			 }

			 ccd->Linked = true;

			 /* Get CCD info */
			 
			 ccd->Linked = get_ccd_info(ccd);
			 GetCCDFrameSettings(ccd,&singleSettings.x,&singleSettings.y,
				        	      &singleSettings.w,&singleSettings.h,
								  &singleSettings.binning);
			 GetCCDFrameSettings(ccd,&seriesSettings.x,&seriesSettings.y,
				    		      &seriesSettings.w,&seriesSettings.h,
								  &seriesSettings.binning);
			 GetCCDFrameSettings(ccd,&darkFrameSettings.x,&darkFrameSettings.y,
				    		      &darkFrameSettings.w,&darkFrameSettings.h,
								  &darkFrameSettings.binning);
			 GetCCDFrameSettings(ccd,&flatFrameSettings.x,&flatFrameSettings.y,
				    		      &flatFrameSettings.w,&flatFrameSettings.h,
								  &flatFrameSettings.binning);
			 GetCCDFrameSettings(ccd,&stackSettings.x,&stackSettings.y,
				     		      &stackSettings.w,&stackSettings.h,
								  &stackSettings.binning);

			 /* Inquire filter wheel position */

			 GetOrionFWPosition(&ccd->filterPosition);

			 /* Also show current status */

			 doShowStatus(ccd, &status);

			 return;
		 }
private: System::Void ImagingCloseLinkStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! ImagingCCD.Linked) {
				 Form1::CCDAutoForm->StatusPrint("*** WARNING - Imaging CCD not linked...\n");
				 return;
			 }
			 doSetTempOffCamera(&ImagingCCD);
			 ImagingCCD.Linked = false;
			 establish_link(&ImagingCCD, false);
			 freeImageBuffers(&ImagingCCD);
			 return;
		 }
private: System::Void ImagingTurnOnTempRegMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 bool okay, Success;
			 float setpoint;

			 if (! ImagingCCD.Linked) {
				 StatusPrint("*** WARNING - Can't turn temp. regulation on, link to ccd first...\n");
				 return;
			 }
			 
			 /* Ask user for temp set point */

			 okay = Queryr("Enter temperature setpoint:", &setpoint);
			 if (! okay)
				 return;

			 Success = doSetTempOnCamera(&ImagingCCD, (double) setpoint);
			 return; 
		 }
private: System::Void ImagingTurnOffTempRegMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 doSetTempOffCamera(&ImagingCCD);
		 }
private: System::Void SpectroEstablishLinkMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int i, Linked, status;

			 if (SpectroCCD.Linked) {
				 StatusPrint("*** INFO - Already Linked to spectro ccd\n");
				 return;
			 } else if (ImagingCCD.Linked) {
				 StatusPrint("*** WARNING - Already Linked to Imaging CCD, can only "
					 "hand one CCD at a time...\n");
				 return;
			 }

			 /* Link to camera, try at most 4 times */

			 ccd = &SpectroCCD;
			 strcpy_s(ccd->name, sizeof(ccd->name), ccdSettings.SpectroType);
			 strcpy_s(ccd->port, sizeof(ccd->port), ccdSettings.SpectroPort);

			 Linked = false;
			 for (i=0; i<4; i++) {
				 Linked = establish_link(ccd, true);
				 if (Linked)
					 break;
				 usleep(100000);
			 }
			 if (! Linked) {
				 StatusPrint("*** WARNING - Can't open camera, giving up...\n");
				 return;
			 }

			 ccd->Linked = true;

			 /* Get CCD info */
			 
			 ccd->Linked = get_ccd_info(ccd);
			 GetCCDFrameSettings(ccd,&singleSettings.x,&singleSettings.y,
				        	      &singleSettings.w,&singleSettings.h,
								  &singleSettings.binning);
			 GetCCDFrameSettings(ccd,&seriesSettings.x,&seriesSettings.y,
				    		      &seriesSettings.w,&seriesSettings.h,
								  &seriesSettings.binning);
			 GetCCDFrameSettings(ccd,&darkFrameSettings.x,&darkFrameSettings.y,
				    		      &darkFrameSettings.w,&darkFrameSettings.h,
								  &darkFrameSettings.binning);
			 GetCCDFrameSettings(ccd,&flatFrameSettings.x,&flatFrameSettings.y,
				    		      &flatFrameSettings.w,&flatFrameSettings.h,
								  &flatFrameSettings.binning);
			 GetCCDFrameSettings(ccd,&stackSettings.x,&stackSettings.y,
				     		      &stackSettings.w,&stackSettings.h,
								  &stackSettings.binning);

			 /* Also show current status */

			 doShowStatus(ccd, &status);

			 return;
		 }
private: System::Void SpectroCloseLinkMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! SpectroCCD.Linked) {
				 Form1::CCDAutoForm->StatusPrint("*** WARNING - Spectro CCD not linked...\n");
				 return;
			 }
			 doSetTempOffCamera(&SpectroCCD);
			 SpectroCCD.Linked = false;
			 establish_link(&SpectroCCD, false);
			 freeImageBuffers(&SpectroCCD);
			 return;
		 }
private: System::Void SpectroTurnOnTempRegMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

			 bool okay, Success;
			 float setpoint;

			 if (! SpectroCCD.Linked) {
				 StatusPrint("*** WARNING - Can't turn temp. regulation on, link to ccd first...\n");
				 return;
			 }
			 
			 /* Ask user for temp set point */

			 okay = Queryr("Enter temperature setpoint:", &setpoint);
			 if (! okay)
				 return;

			 Success = doSetTempOnCamera(&SpectroCCD, setpoint);
			 return; 
		 }
private: System::Void SpectroTurnOffTempRegMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 doSetTempOffCamera(&SpectroCCD);
		 }
private: System::Void BToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 1);
		 }
private: System::Void VToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 2);
		 }
private: System::Void RToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 3);
		 }
private: System::Void IToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 4);
		 }
private: System::Void HToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 6);
		 }
private: System::Void GToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 5);
		 }
private: System::Void CToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int status;
			 doFilterWheel(ccd, &status, 7);
		 }
private: System::Void ObservatoryMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 ObservatorySettingsDialog::FormPtr->ShowTheDialog();
		 }
private: System::Void ShowCurrentImageMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (CurrentImageWindowExists)
				 CurrentImageWindow::FormPtr->Show();
			 else
				 Form1::CCDAutoForm->StatusPrint("*** WARNING - Current Image Window not active, you must open or take an image first.");
		 }
private: System::Void GuidingSlitImageMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! GuideFrameWindowExists)
				 gcnew GuideFrameWindow();

			 GuideFrameWindow::FormPtr->ShowTheWindow();
		 }
private: System::Void CamerasMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (! CameraSettingsDialogExists) {
				 gcnew CameraSettingsDialog();
			 }
			 CameraSettingsDialog::FormPtr->ShowTheDialog();
		 }
private: System::Void ExposeSingleFrameMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 /* Save current settings in case "cancel" button hit */
			 
			 memcpy(&singleSettings_Save,&singleSettings, sizeof(singleSettings));
			 
			 /* Create the dialog if not already done */
			 
			 if (! SingleSettingsDialogExists)
				 gcnew SingleSettingsDialog();

			 /* Update the dialog values */
			 
			 SingleSettingsDialog::FormPtr->SetSingleSettings();

			/* show the dialog */

			SingleSettingsDialog::FormPtr->ShowTheDialog();

			 return;
		 }
private: System::Void ExposeDarkFramesMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Save current settings in case "cancel" button hit */
			 
			 memcpy(&darkFrameSettings_Save,&darkFrameSettings, sizeof(darkFrameSettings));
			 
			 /* Create the dialog if not already done */
			 
			 if (! DarkFrameSettingsDialogExists)
				 gcnew DarkFrameSettingsDialog();

			 /* Update the dialog values */
			 
			 DarkFrameSettingsDialog::FormPtr->SetDarkFrameSettings();

			/* show the dialog */

			DarkFrameSettingsDialog::FormPtr->ShowTheDialog();

			 return;
		 }
private: System::Void ExposeFlatFramesMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Save current settings in case "cancel" button hit */
			 
			 memcpy(&flatFrameSettings_Save,&flatFrameSettings, sizeof(flatFrameSettings));
			 
			 /* Create the dialog if not already done */
			 
			 if (! FlatFrameSettingsDialogExists)
				 gcnew FlatFrameSettingsDialog();

			 /* Update the dialog values */
			 
			 FlatFrameSettingsDialog::FormPtr->SetFlatFrameSettings();

			/* show the dialog */

			FlatFrameSettingsDialog::FormPtr->ShowTheDialog();

			return;
		 }
private: System::Void ExposeSeriesOfFramesMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Save current settings in case "cancel" button hit */
			 
			 memcpy(&seriesSettings_Save,&seriesSettings, sizeof(seriesSettings));
			 
			 /* Create the dialog if not already done */
			 
			 if (! SeriesSettingsDialogExists)
				 gcnew SeriesSettingsDialog();

			 /* Update the dialog values */
			 
			 SeriesSettingsDialog::FormPtr->SetSeriesSettings();

			/* show the dialog */

			SeriesSettingsDialog::FormPtr->ShowTheDialog();

			 return;
		 }
private: System::Void ExposeStackFramesMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void viewEditObjectListToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Create & show the dialog */

			 ShowObjectListDialog();

		 }
public: static void StatusPrint(char *Message) {
		String ^buffer;
		buffer = gcnew String(Message);
		if ((strstr(Message,"Warning") != NULL) ||
			(strstr(Message,"WARNING") != NULL))
			Form1::CCDAutoForm->StatusRichTextBox->ForeColor = System::Drawing::Color::Red;
		else
			Form1::CCDAutoForm->StatusRichTextBox->ForeColor = System::Drawing::Color::Black;
//		Form1::CCDAutoForm->StatusRichTextBox->Text = buffer;
		Form1::CCDAutoForm->StatusRichTextBox->AppendText(buffer);
		Form1::CCDAutoForm->StatusRichTextBox->ScrollToCaret();
		delete buffer;
		 }
public: static void SetCCDStatusTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CCDStatusTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCCDTempTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CCDTempTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCCDCoolingTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CCDCoolingTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCCDFilterTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CCDFilterTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageExposeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageExposeTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageBinningTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageBinningTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageWhichCCDTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageWhichCCDTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageFrameSizeTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageFrameSizeTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageFileNameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageFileNameTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageObjectNameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageObjectNameTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentImageDirectoryTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentImageDirectoryTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetProcessingExpNumTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->ProcessingExpNumTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetProcessingSeqNumTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->ProcessingSeqNumTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentSeriesFileNameTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentSeriesFileNameTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetCurrentSeriesStatusTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->CurrentSeriesStatusTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetTimeToNextExpTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->TimeToNextExpTextBox->Text = buffer;
		delete buffer;
		}
public: static void SetTimeToSeriesEndTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->TimeToSeriesEndTextBox->Text = buffer;
		delete buffer;
		}
public: void OpenFileDialog_FileOk( Object^ sender, System::ComponentModel::CancelEventArgs^ e ) {
		return;
		}
public: void MainTimerCallback(Object^ sender, System::EventArgs^ e) {

			static int TimeToGetScopePos=10;
			static bool Busy=false;
			//int stat;

			if (Busy)
				return;
			Busy = true;
			Form1::CCDAutoForm->Refresh();
			if (CurrentImageWindowExists)
				RefreshCurrentImageWindow();
			if (PhotometryPlotWindowExists)
				RefreshPhotometryPlotWindow();
			updateStatusInfo();
			//stat = altaCam_ReadStatus();
			//switch (stat) {
			//	case ALTA_STATUS_IDLE:
			//		Form1::StatusPrint("*** Debug - Alta Camera is idle.\n");
			//		break;
			//	case ALTA_STATUS_EXPOSING:
			//		Form1::StatusPrint("*** Debug - Alta Camera is exposing.\n");
			//		break;
			//	case ALTA_STATUS_IMAGINGACTIVE:
			//		Form1::StatusPrint("*** Debug - Alta Camera is idle.\n");
			//		break;
			//	case ALTA_STATUS_IMAGEREADY:
			//		Form1::StatusPrint("*** Debug - Alta Camera is idle.\n");
			//		break;
			//	case ALTA_STATUS_FLUSHING:
			//		Form1::StatusPrint("*** Debug - Alta Camera is idle.\n");
			//		break;
			//	case ALTA_STATUS_WAITINGONTRIGGER:
			//		Form1::StatusPrint("*** Debug - Alta Camera is idle.\n");
			//		break;
			//	default:
			//		Form1::StatusPrint("*** Debug - Unknown Alta Camera state.\n");
			//		break;
			//}


			if (PleaseStartSeries) {
				PleaseStartSeries = false;
				ExposeSeriesFrames();
			}
			if (! DontGetScopePosition) {
				if (TimeToGetScopePos == 0) {
					GetScopePosition(&ScopeRA, &ScopeDEC);
					TimeToGetScopePos = 10;
				} else {
					TimeToGetScopePos--;
				}
			}
			Busy = false;

		}
public: void SetDownloadTimerState(bool On) {

			Form1::DownloadTimer->Enabled = On;
		}

private: System::Void DownloadTimerCallback(System::Object^  sender, System::EventArgs^  e) {

			 Form1::StatusPrint("*** DEBUG - Heartbeat...\n");
			 RunMainIteration(0.1);
		 }


private: System::Void SetBaseFolder_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->FolderBrowserDialog->Description = "Select Base Folder";
			 System::Windows::Forms::DialogResult res = this->FolderBrowserDialog->ShowDialog();
			 if ( res != System::Windows::Forms::DialogResult::OK)
				return;
			 String^ path = this->FolderBrowserDialog->SelectedPath;
			 Directory::SetCurrentDirectory(path);
			 return;
		 }
private: System::Void PauseResumeSeriesButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 PauseSeries = (! PauseSeries);
		 }
private: System::Void StopSeriesButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 StopSeries = true;
		 }
public: static void SetUTTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->UTTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetLocalTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->LocalTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetLSTTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->LSTTextBox->Text = buffer;
		delete buffer;
		}

public: static void SetJDTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		Form1::CCDAutoForm->JDTextBox->Text = buffer;
		delete buffer;
		}

private: System::Void showPhotometryPlotToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! PhotometryPlotWindowExists) {
				 gcnew PhotometryPlotWindow();
			 }
			 PhotometryPlotWindow::FormPtr->ShowTheDialog();
			 return;
		 }
private: System::Void TrackingEstablishLinkToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 int i, Linked;

			 if (TrackingCCD.Linked) {
				 StatusPrint("*** INFO - Already Linked to tracking ccd\n");
				 return;
			 }

			 /* Link to camera, try at most 4 times */

			 strcpy_s(TrackingCCD.name, sizeof(TrackingCCD.name), ccdSettings.TrackingType);
			 strcpy_s(TrackingCCD.port, sizeof(TrackingCCD.port), ccdSettings.TrackingPort);

			 Linked = false;
			 for (i=0; i<4; i++) {
				 Linked = establish_link(&TrackingCCD, true);
				 if (Linked)
					 break;
				 usleep(100000);
			 }
			 if (! Linked) {
				 StatusPrint("*** WARNING - Can't open camera, giving up...\n");
				 return;
			 }

			 TrackingCCD.Linked = true;

			 /* Get CCD info */

			 TrackingCCD.Linked = get_ccd_info(&TrackingCCD);

			 return;
		 }
private: System::Void TrackingCloseLinkToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (! TrackingCCD.Linked) {
				 Form1::CCDAutoForm->StatusPrint("*** WARNING - Tracking CCD not linked...\n");
				 return;
			 }
			 TrackingCCD.Linked = false;
			 establish_link(&TrackingCCD, false);
			 freeImageBuffers(&TrackingCCD);
			 return;
		 }
private: System::Void onOffDebugModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (GlobalDebug) {
				 Form1::StatusPrint("*** Info - Turning OFF debug mode.\n");
				 GlobalDebug = false;
			 } else {
				 Form1::StatusPrint("*** Info - Turning ON debug mode.\n");
				 GlobalDebug = true;
			 }
		 }
private: System::Void onOffImageProgressToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (DontShowImageProgress) {
				 Form1::StatusPrint("*** Info - Turning ON Image Progress Dialog Box.\n");
				 DontShowImageProgress = false;
			 } else {
				 Form1::StatusPrint("*** Info - Turning OFF Image Progress Dialog Box.\n");
				 DontShowImageProgress = true;
			 }

		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 char message[160];

			 sprintf_s(message, sizeof(message), "This is the OSU-Lima Student Observatory CCD control program, Version %3.1f",
				 RELEASE_VERSION);
			 MessageBox(message, OKAY, true);
		 }
private: System::Void onOffAskSaveImageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (DontAskSaveImage) {
				 StatusPrint("*** Info - Turning on Asking of saving unsaved images.\n");
				 DontAskSaveImage = false;
			 } else {
				 StatusPrint("*** Info - Turning off Asking of saving unsaved images.\n");
				 DontAskSaveImage = true;
			 }
			 return;
		 }
private: System::Void updateMX916KeywordsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 ShowUpdateMX916Keywords();
		 }
};
};

