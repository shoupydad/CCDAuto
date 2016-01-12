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
	/// Summary for AAVSOPhotoDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AAVSOPhotoDialog : public System::Windows::Forms::Form
	{
	public:
		static AAVSOPhotoDialog ^ FormPtr;

	public: 


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  VarStarIDTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  CompStarIDTextBox;

	public: 



	public:
	static bool Cancelled;
	AAVSOPhotoDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			AAVSOPhotoDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AAVSOPhotoDialog()
		{
			if (components)
			{
				delete components;
			}
			AAVSOPhotoDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  CheckStarIDTextBox;




	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  ChartDateTextBox;


	private: System::Windows::Forms::Button^  OkayButton;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
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
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ChartDateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->CheckStarIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->OkayButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->VarStarIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CompStarIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67.69231F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 32.30769F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(363, 159);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel6, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(357, 101);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				48.78049F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				51.21951F)));
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->ChartDateTextBox, 1, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(181, 53);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(173, 45);
			this->tableLayoutPanel5->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 26);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Chart Date:\r\n(yy/mm/dd)";
			// 
			// ChartDateTextBox
			// 
			this->ChartDateTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ChartDateTextBox->Location = System::Drawing::Point(87, 12);
			this->ChartDateTextBox->Name = L"ChartDateTextBox";
			this->ChartDateTextBox->Size = System::Drawing::Size(79, 20);
			this->ChartDateTextBox->TabIndex = 4;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				48.78049F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				51.21951F)));
			this->tableLayoutPanel4->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->CheckStarIDTextBox, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 53);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(172, 45);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Check Star ID:";
			// 
			// CheckStarIDTextBox
			// 
			this->CheckStarIDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CheckStarIDTextBox->Location = System::Drawing::Point(86, 12);
			this->CheckStarIDTextBox->Name = L"CheckStarIDTextBox";
			this->CheckStarIDTextBox->Size = System::Drawing::Size(79, 20);
			this->CheckStarIDTextBox->TabIndex = 3;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 110);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->OkayButton);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->CancelButton);
			this->splitContainer1->Size = System::Drawing::Size(357, 46);
			this->splitContainer1->SplitterDistance = 173;
			this->splitContainer1->TabIndex = 1;
			// 
			// OkayButton
			// 
			this->OkayButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkayButton->Location = System::Drawing::Point(45, 14);
			this->OkayButton->Name = L"OkayButton";
			this->OkayButton->Size = System::Drawing::Size(75, 23);
			this->OkayButton->TabIndex = 1;
			this->OkayButton->Text = L"Okay";
			this->OkayButton->UseVisualStyleBackColor = true;
			this->OkayButton->Click += gcnew System::EventHandler(this, &AAVSOPhotoDialog::OkayButton_Clicked);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(53, 12);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 2;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &AAVSOPhotoDialog::CancelButton_Clicked);
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				48.78049F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				51.21951F)));
			this->tableLayoutPanel6->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->VarStarIDTextBox, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(172, 44);
			this->tableLayoutPanel6->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 15);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Var Star ID:";
			// 
			// VarStarIDTextBox
			// 
			this->VarStarIDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->VarStarIDTextBox->Location = System::Drawing::Point(86, 12);
			this->VarStarIDTextBox->Name = L"VarStarIDTextBox";
			this->VarStarIDTextBox->Size = System::Drawing::Size(79, 20);
			this->VarStarIDTextBox->TabIndex = 1;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				48.78049F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				51.21951F)));
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->CompStarIDTextBox, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(181, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(173, 44);
			this->tableLayoutPanel3->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Comp Star ID:";
			// 
			// CompStarIDTextBox
			// 
			this->CompStarIDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CompStarIDTextBox->Location = System::Drawing::Point(87, 12);
			this->CompStarIDTextBox->Name = L"CompStarIDTextBox";
			this->CompStarIDTextBox->Size = System::Drawing::Size(83, 20);
			this->CompStarIDTextBox->TabIndex = 2;
			// 
			// AAVSOPhotoDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(363, 159);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AAVSOPhotoDialog";
			this->Text = L"AAVSO Photometry Params Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 AAVSOPhotoDialog::FormPtr->GetCompStarIDTextBox(photometrySettings.AAVSOCompStarID);
			 AAVSOPhotoDialog::FormPtr->GetCheckStarIDTextBox(photometrySettings.AAVSOCheckStarID);
			 AAVSOPhotoDialog::FormPtr->GetVarStarIDTextBox(photometrySettings.AAVSOVarStarID);
			 AAVSOPhotoDialog::FormPtr->GetChartDateTextBox(photometrySettings.AAVSOChartDate);
			 AAVSOPhotoDialog::FormPtr->Hide();
			 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 AAVSOPhotoDialog::FormPtr->Hide();
			 AAVSOPhotoDialog::FormPtr->Cancelled = true;
		 }
public:  static bool ShowTheDialog(void) {

			 AAVSOPhotoDialog::FormPtr->Cancelled = false;
			 AAVSOPhotoDialog::FormPtr->SetCompStarIDTextBox(photometrySettings.AAVSOCompStarID);
			 AAVSOPhotoDialog::FormPtr->SetCheckStarIDTextBox(photometrySettings.AAVSOCheckStarID);
			 AAVSOPhotoDialog::FormPtr->SetVarStarIDTextBox(photometrySettings.AAVSOVarStarID);
			 AAVSOPhotoDialog::FormPtr->SetChartDateTextBox(photometrySettings.AAVSOChartDate);
			 AAVSOPhotoDialog::FormPtr->ShowDialog();
			 return AAVSOPhotoDialog::FormPtr->Cancelled;
		 }
public:  static void SetCompStarIDTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 AAVSOPhotoDialog::FormPtr->CompStarIDTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetCompStarIDTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = AAVSOPhotoDialog::FormPtr->CompStarIDTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetCheckStarIDTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 AAVSOPhotoDialog::FormPtr->CheckStarIDTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetCheckStarIDTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = AAVSOPhotoDialog::FormPtr->CheckStarIDTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetVarStarIDTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 AAVSOPhotoDialog::FormPtr->VarStarIDTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetVarStarIDTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = AAVSOPhotoDialog::FormPtr->VarStarIDTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }
public:  static void SetChartDateTextBox(char *text) {
			 String ^buffer;
			 buffer = gcnew String(text);
			 AAVSOPhotoDialog::FormPtr->ChartDateTextBox->Text = buffer;
			 delete buffer;
		 }
public:  static void GetChartDateTextBox(char *text) {
			 int i;
			 String ^buffer;
			 buffer = gcnew String("");
			 buffer = AAVSOPhotoDialog::FormPtr->ChartDateTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 delete buffer;
		 }

};
}
