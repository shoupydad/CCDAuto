#pragma once

#include "doRoutines.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CCDAuto {

	/// <summary>
	/// Summary for GuideSlitSettingsDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class GuideSlitSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		static GuideSlitSettingsDialog ^FormPtr;
		GuideSlitSettingsDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			GuideSlitSettingsDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GuideSlitSettingsDialog()
		{
			if (components)
			{
				delete components;
				GuideSlitSettingsDialogExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  IntervalTextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  ExposureTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TextBox^  SlitRightYTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  SlitRightXTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  SlitLeftYTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  SlitLeftXTextBox;
	private: System::Windows::Forms::TextBox^  ScaleYTextBox;
	private: System::Windows::Forms::TextBox^  ScaleXTextBox;

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->splitContainer1, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 82.33083F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.66917F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(292, 266);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(286, 212);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 221);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->OkayButton);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->CancelButton);
			this->splitContainer1->Size = System::Drawing::Size(286, 42);
			this->splitContainer1->SplitterDistance = 141;
			this->splitContainer1->TabIndex = 1;
			// 
			// OkayButton
			// 
			this->OkayButton->Location = System::Drawing::Point(30, 10);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 0;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &GuideSlitSettingsDialog::OkayButton_Clicked);
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(33, 10);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &GuideSlitSettingsDialog::CancelButton_Clicked);
			// 
			// GuideSlitSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"GuideSlitSettingsDialog";
			this->Text = L"GuideSlitSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 FormPtr->GetExposureTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.exposure);
			 FormPtr->GetIntervalTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.interval);
			 FormPtr->GetScaleXTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.XScale);
			 FormPtr->GetScaleYTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.YScale);
			 FormPtr->GetSlitLeftXTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.slitX0);
			 FormPtr->GetSlitLeftYTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.slitY0);
			 FormPtr->GetSlitRightXTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.slitX1);
			 FormPtr->GetSlitRightYTextBox(buffer);
			 sscanf_s(buffer, "%f", &GuidingSlitSettings.slitY1);
			 FormPtr->Hide();

			 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
public: static void ShowTheDialog(void) {

			char buffer[80];

			sprintf_s(buffer, sizeof(buffer), "%7.3f", GuidingSlitSettings.exposure);
			FormPtr->SetExposureTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%7.3f", GuidingSlitSettings.interval);
			FormPtr->SetIntervalTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%6.3f", GuidingSlitSettings.XScale);
			FormPtr->SetScaleXTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%6.3f", GuidingSlitSettings.YScale);
			FormPtr->SetScaleYTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%5.1f", GuidingSlitSettings.slitX0);
			FormPtr->SetSlitLeftXTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%5.1f", GuidingSlitSettings.slitY0);
			FormPtr->SetSlitLeftYTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%5.1f", GuidingSlitSettings.slitX1);
			FormPtr->SetSlitRightXTextBox(buffer);
			sprintf_s(buffer, sizeof(buffer), "%5.1f", GuidingSlitSettings.slitY1);
			FormPtr->SetSlitRightYTextBox(buffer);

			FormPtr->ShowDialog();
		}
public: static void SetExposureTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->ExposureTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetExposureTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->ExposureTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetIntervalTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->IntervalTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetIntervalTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->IntervalTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetScaleXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->ScaleXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetScaleXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->ScaleXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetScaleYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->ScaleYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetScaleYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->ScaleYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitLeftXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->ScaleXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitLeftXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitLeftXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitLeftYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitLeftYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitLeftYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitLeftYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitRightXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitRightXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitRightXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitRightXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetSlitRightYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->SlitRightYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetSlitRightYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->SlitRightYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
};
}
