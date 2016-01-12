#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "doRoutines.h"
#include "Form1.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for UpdateMX916Keywords
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class UpdateMX916Keywords : public System::Windows::Forms::Form
	{
	public:
		static UpdateMX916Keywords^ FormPtr;
		UpdateMX916Keywords(void)
		{
			InitializeComponent();
			FormPtr = this;
			UpdateMX916KeywordsExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateMX916Keywords()
		{
			if (components)
			{
				delete components;
			}
			UpdateMX916KeywordsExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  OBSDateTextBox;
	private: System::Windows::Forms::TextBox^  OBSUTTextBox;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  ObjectNameTextBox;

	private: System::Windows::Forms::TextBox^  ExposureTimeTextBox;
	private: System::Windows::Forms::TextBox^  CCDReadNoiseTextBox;
	private: System::Windows::Forms::TextBox^  CCDGainTextBox;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::TextBox^  ObservatoryTextBox;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  ObserverTextBox;
	private: System::Windows::Forms::TextBox^  ProjectTextBox;

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
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->ExposureTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CCDReadNoiseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CCDGainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->OBSUTTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->OBSDateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->ObservatoryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObserverTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ProjectTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.84615F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				46.15385F)));
			this->tableLayoutPanel1->Controls->Add(this->ProjectTextBox, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->label9, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->ExposureTimeTextBox, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->CCDReadNoiseTextBox, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->CCDGainTextBox, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->ObjectNameTextBox, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->OBSUTTextBox, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->OBSDateTextBox, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->OkayButton, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->CancelButton, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->ObservatoryTextBox, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->ObserverTextBox, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->label8, 0, 7);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 10;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.999625F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.00262F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(247, 286);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(152, 257);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 13;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &UpdateMX916Keywords::CancelButton_Clicked);
			// 
			// ExposureTimeTextBox
			// 
			this->ExposureTimeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ExposureTimeTextBox->Location = System::Drawing::Point(135, 144);
			this->ExposureTimeTextBox->Name = L"ExposureTimeTextBox";
			this->ExposureTimeTextBox->Size = System::Drawing::Size(100, 20);
			this->ExposureTimeTextBox->TabIndex = 11;
			// 
			// CCDReadNoiseTextBox
			// 
			this->CCDReadNoiseTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDReadNoiseTextBox->Location = System::Drawing::Point(135, 116);
			this->CCDReadNoiseTextBox->Name = L"CCDReadNoiseTextBox";
			this->CCDReadNoiseTextBox->Size = System::Drawing::Size(100, 20);
			this->CCDReadNoiseTextBox->TabIndex = 10;
			// 
			// CCDGainTextBox
			// 
			this->CCDGainTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CCDGainTextBox->Location = System::Drawing::Point(135, 88);
			this->CCDGainTextBox->Name = L"CCDGainTextBox";
			this->CCDGainTextBox->Size = System::Drawing::Size(100, 20);
			this->CCDGainTextBox->TabIndex = 9;
			// 
			// ObjectNameTextBox
			// 
			this->ObjectNameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectNameTextBox->Location = System::Drawing::Point(135, 60);
			this->ObjectNameTextBox->Name = L"ObjectNameTextBox";
			this->ObjectNameTextBox->Size = System::Drawing::Size(100, 20);
			this->ObjectNameTextBox->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(57, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Object Name:";
			// 
			// OBSUTTextBox
			// 
			this->OBSUTTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OBSUTTextBox->Location = System::Drawing::Point(135, 32);
			this->OBSUTTextBox->Name = L"OBSUTTextBox";
			this->OBSUTTextBox->Size = System::Drawing::Size(100, 20);
			this->OBSUTTextBox->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Obs. UT (hh:mm:ss):";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Obs. Date (yyyy-mm-dd):";
			// 
			// OBSDateTextBox
			// 
			this->OBSDateTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OBSDateTextBox->Location = System::Drawing::Point(135, 4);
			this->OBSDateTextBox->Name = L"OBSDateTextBox";
			this->OBSDateTextBox->Size = System::Drawing::Size(100, 20);
			this->OBSDateTextBox->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 91);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(98, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"CCD Gain (e-/adc):";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 119);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"CCD Readnoise (e-):";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(35, 147);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Exposure Time (s):";
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(28, 257);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 12;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &UpdateMX916Keywords::OkayButton_Clicked);
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(62, 175);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Observatory:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(76, 203);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Observer:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(86, 231);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Project:";
			// 
			// ObservatoryTextBox
			// 
			this->ObservatoryTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObservatoryTextBox->Location = System::Drawing::Point(135, 172);
			this->ObservatoryTextBox->Name = L"ObservatoryTextBox";
			this->ObservatoryTextBox->Size = System::Drawing::Size(100, 20);
			this->ObservatoryTextBox->TabIndex = 17;
			// 
			// ObserverTextBox
			// 
			this->ObserverTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObserverTextBox->Location = System::Drawing::Point(135, 200);
			this->ObserverTextBox->Name = L"ObserverTextBox";
			this->ObserverTextBox->Size = System::Drawing::Size(100, 20);
			this->ObserverTextBox->TabIndex = 18;
			// 
			// ProjectTextBox
			// 
			this->ProjectTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ProjectTextBox->Location = System::Drawing::Point(135, 228);
			this->ProjectTextBox->Name = L"ProjectTextBox";
			this->ProjectTextBox->Size = System::Drawing::Size(100, 20);
			this->ProjectTextBox->TabIndex = 19;
			// 
			// UpdateMX916Keywords
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(247, 286);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"UpdateMX916Keywords";
			this->Text = L"UpdateMX916Keywords";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 UpdateMX916Keywords::FormPtr->GetCCDGainTextBox(buffer);
			 sscanf_s(buffer, "%f", &ccd->gain);
			 UpdateMX916Keywords::FormPtr->GetCCDReadNoiseTextBox(buffer);
			 sscanf_s(buffer, "%f", &ccd->readNoise);
			 UpdateMX916Keywords::FormPtr->GetExposureTimeTextBox(buffer);
			 sscanf_s(buffer, "%f", &ccd->Image.light_frame.exposure);
			 UpdateMX916Keywords::FormPtr->GetOBSDateTextBox(ccd->Image.light_frame.UTDATE);
			 UpdateMX916Keywords::FormPtr->GetOBSUTTextBox(ccd->Image.light_frame.UT);
			 UpdateMX916Keywords::FormPtr->GetObjectNameTextBox(ccd->Image.ObjectName);
			 UpdateMX916Keywords::FormPtr->GetObservatoryTextBox(ObsSettings.name);
			 UpdateMX916Keywords::FormPtr->GetObserverTextBox(ObsSettings.Observer);
			 UpdateMX916Keywords::FormPtr->GetProjectTextBox(ObsSettings.Project);

			 UpdateMX916Keywords::FormPtr->Hide();
		 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 UpdateMX916Keywords::FormPtr->Hide();
		 }
public: static void ShowTheDialog(void) {
			UpdateMX916Keywords::FormPtr->ShowDialog();
		 }
public: static void SetOBSDateTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->OBSDateTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetOBSDateTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->OBSDateTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetOBSUTTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->OBSUTTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetOBSUTTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->OBSUTTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetObjectNameTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->ObjectNameTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetObjectNameTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->ObjectNameTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetExposureTimeTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->ExposureTimeTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetExposureTimeTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->ExposureTimeTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetCCDReadNoiseTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->CCDReadNoiseTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetCCDReadNoiseTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->CCDReadNoiseTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetCCDGainTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->CCDGainTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetCCDGainTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->CCDGainTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetObservatoryTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->ObservatoryTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetObservatoryTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->ObservatoryTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetObserverTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->ObserverTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetObserverTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->ObserverTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetProjectTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			UpdateMX916Keywords::FormPtr->ProjectTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetProjectTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = UpdateMX916Keywords::FormPtr->ProjectTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
};
}
