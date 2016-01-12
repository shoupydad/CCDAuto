#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include <malloc.h>
#include "doRoutines.h"


namespace CCDAuto {

	/// <summary>
	/// Summary for OpenCalDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class OpenCalDialog : public System::Windows::Forms::Form
	{
	public:
		static OpenCalDialog ^FormPtr;
		static char *DarkDir;
		static char *FlatDir;
		static int  DarkOption;
		static int  FlatOption;
		OpenCalDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			OpenCalDialogExists = true;
			DarkDir = (char *) malloc(161);
			FlatDir = (char *) malloc(161);
			strcpy_s(DarkDir, 161, "");
			strcpy_s(FlatDir, 161, "");
			DarkOption = 3;
			FlatOption = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OpenCalDialog()
		{
			if (components)
			{
				delete components;
				OpenCalDialogExists = false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::ComboBox^  DarkFrameOptionComboBox;
	private: System::Windows::Forms::TextBox^  DarkDirTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::Button^  PickDarkFolderButton;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::ComboBox^  FlatFrameOptionComboBox;
	private: System::Windows::Forms::TextBox^  FlatDirTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::Button^  PickFlatFolderButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  CancelButton;
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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FlatFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FlatDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickFlatFolderButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->DarkFrameOptionComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DarkDirTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PickDarkFolderButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 76.38191F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 23.61809F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(292, 199);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox5, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox3, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(286, 146);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel10);
			this->groupBox5->Location = System::Drawing::Point(146, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(129, 129);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Flat Frame Options";
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 1;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel10->Controls->Add(this->FlatFrameOptionComboBox, 0, 0);
			this->tableLayoutPanel10->Controls->Add(this->FlatDirTextBox, 0, 2);
			this->tableLayoutPanel10->Controls->Add(this->tableLayoutPanel11, 0, 1);
			this->tableLayoutPanel10->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 3;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.4486F)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30.84112F)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(127, 107);
			this->tableLayoutPanel10->TabIndex = 1;
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
			// 
			// FlatDirTextBox
			// 
			this->FlatDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FlatDirTextBox->Location = System::Drawing::Point(16, 80);
			this->FlatDirTextBox->Name = L"FlatDirTextBox";
			this->FlatDirTextBox->Size = System::Drawing::Size(95, 20);
			this->FlatDirTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 2;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				46.79803F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.20197F)));
			this->tableLayoutPanel11->Controls->Add(this->PickFlatFolderButton, 0, 0);
			this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel11->Location = System::Drawing::Point(3, 38);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				32)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(121, 32);
			this->tableLayoutPanel11->TabIndex = 1;
			// 
			// PickFlatFolderButton
			// 
			this->PickFlatFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel11->SetColumnSpan(this->PickFlatFolderButton, 2);
			this->PickFlatFolderButton->Location = System::Drawing::Point(14, 5);
			this->PickFlatFolderButton->Name = L"PickFlatFolderButton";
			this->PickFlatFolderButton->Size = System::Drawing::Size(93, 21);
			this->PickFlatFolderButton->TabIndex = 11;
			this->PickFlatFolderButton->Text = L"Pick Flat Folder";
			this->PickFlatFolderButton->UseVisualStyleBackColor = true;
			this->PickFlatFolderButton->Click += gcnew System::EventHandler(this, &OpenCalDialog::PickFlatFolderButton_Clicked);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel7);
			this->groupBox3->Location = System::Drawing::Point(3, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(129, 129);
			this->groupBox3->TabIndex = 4;
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
			this->tableLayoutPanel7->Controls->Add(this->DarkDirTextBox, 0, 2);
			this->tableLayoutPanel7->Controls->Add(this->tableLayoutPanel8, 0, 1);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.09091F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.36364F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.54546F)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(123, 110);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// DarkFrameOptionComboBox
			// 
			this->DarkFrameOptionComboBox->FormattingEnabled = true;
			this->DarkFrameOptionComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Automatic dark frame", L"Force new dark frame", 
				L"Use dark frame from file", L"Don\'t use dark frame"});
			this->DarkFrameOptionComboBox->Location = System::Drawing::Point(3, 3);
			this->DarkFrameOptionComboBox->Name = L"DarkFrameOptionComboBox";
			this->DarkFrameOptionComboBox->Size = System::Drawing::Size(117, 21);
			this->DarkFrameOptionComboBox->TabIndex = 0;
			// 
			// DarkDirTextBox
			// 
			this->DarkDirTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DarkDirTextBox->Location = System::Drawing::Point(14, 80);
			this->DarkDirTextBox->Name = L"DarkDirTextBox";
			this->DarkDirTextBox->Size = System::Drawing::Size(95, 20);
			this->DarkDirTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 2;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				53.33333F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				46.66667F)));
			this->tableLayoutPanel8->Controls->Add(this->PickDarkFolderButton, 0, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 34);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(117, 33);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// PickDarkFolderButton
			// 
			this->PickDarkFolderButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel8->SetColumnSpan(this->PickDarkFolderButton, 2);
			this->PickDarkFolderButton->Location = System::Drawing::Point(7, 6);
			this->PickDarkFolderButton->Name = L"PickDarkFolderButton";
			this->PickDarkFolderButton->Size = System::Drawing::Size(103, 21);
			this->PickDarkFolderButton->TabIndex = 3;
			this->PickDarkFolderButton->Text = L"Pick Dark Folder";
			this->PickDarkFolderButton->UseVisualStyleBackColor = true;
			this->PickDarkFolderButton->Click += gcnew System::EventHandler(this, &OpenCalDialog::PickDarkFolderButton_Clicked);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->CancelButton, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 155);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(286, 41);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(34, 9);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 4;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &OpenCalDialog::OkButton_Clicked);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(177, 9);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 5;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &OpenCalDialog::CancelButton_Clicked);
			// 
			// OpenCalDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 199);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"OpenCalDialog";
			this->Text = L"OpenCalDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->tableLayoutPanel11->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
public: static void SetDarkDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->DarkDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetDarkDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->DarkDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFlatDirTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		FormPtr->FlatDirTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFlatDirTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = FormPtr->FlatDirTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void ShowTheDialog(void) {

			FormPtr->ShowDialog();
		}
private: System::Void PickDarkFolderButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Pick Dark Frame Folder", path);
			 strcpy_s(this->FormPtr->DarkDir, 161, path);
			 this->FormPtr->SetDarkDirTextBox(this->FormPtr->DarkDir);
			 return;
			 }
private: System::Void PickFlatFolderButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char path[180];

			 GetAFolder("Pick Flat Frame Folder", path);
			 strcpy_s(this->FormPtr->FlatDir, 161, path);
			 this->FormPtr->SetFlatDirTextBox(this->FormPtr->FlatDir);
			 return;
		 }
private: System::Void OkButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->GetDarkDirTextBox(FormPtr->DarkDir);
			 FormPtr->GetFlatDirTextBox(FormPtr->FlatDir);
			 FormPtr->DarkOption = FormPtr->DarkFrameOptionComboBox->SelectedIndex;
			 FormPtr->FlatOption = FormPtr->FlatFrameOptionComboBox->SelectedIndex;
			 FormPtr->Hide();
		 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 FormPtr->Hide();
		 }
};
}
