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
	/// Summary for InitializeAstrometryDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class InitializeAstrometryDialog : public System::Windows::Forms::Form
	{
	public:
		static InitializeAstrometryDialog ^FormPtr;
		static bool InitializeCancelled;
		InitializeAstrometryDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			FormPtr = this;
			InitializeAstrometryDialogExists=true;
			InitializeCancelled = false;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InitializeAstrometryDialog()
		{
			if (components)
			{
				delete components;
				InitializeAstrometryDialogExists=false;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  FieldCenterRATextBox;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  FieldCenterDECTextBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TextBox^  PixelScaleTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  OkButton;
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->PixelScaleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FieldCenterRATextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->FieldCenterDECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.08602F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.49462F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 27.95699F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(206, 186);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel3);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 84);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 46);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Misc.";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->Controls->Add(this->PixelScaleTextBox, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(194, 27);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// PixelScaleTextBox
			// 
			this->PixelScaleTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->PixelScaleTextBox->BackColor = System::Drawing::Color::White;
			this->PixelScaleTextBox->Location = System::Drawing::Point(100, 3);
			this->PixelScaleTextBox->Name = L"PixelScaleTextBox";
			this->PixelScaleTextBox->Size = System::Drawing::Size(79, 20);
			this->PixelScaleTextBox->TabIndex = 22;
			this->PixelScaleTextBox->Text = L"00.000 ";
			this->PixelScaleTextBox->WordWrap = false;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Scale (\"/pixel):";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 75);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Field Center";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->FieldCenterRATextBox, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->label11, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->FieldCenterDECTextBox, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(194, 56);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(62, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"DEC:";
			// 
			// FieldCenterRATextBox
			// 
			this->FieldCenterRATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FieldCenterRATextBox->BackColor = System::Drawing::Color::White;
			this->FieldCenterRATextBox->Location = System::Drawing::Point(100, 4);
			this->FieldCenterRATextBox->Name = L"FieldCenterRATextBox";
			this->FieldCenterRATextBox->Size = System::Drawing::Size(65, 20);
			this->FieldCenterRATextBox->TabIndex = 19;
			this->FieldCenterRATextBox->Text = L" 00:00:00.0";
			this->FieldCenterRATextBox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(69, 7);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"RA:";
			// 
			// FieldCenterDECTextBox
			// 
			this->FieldCenterDECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FieldCenterDECTextBox->BackColor = System::Drawing::Color::White;
			this->FieldCenterDECTextBox->Location = System::Drawing::Point(100, 32);
			this->FieldCenterDECTextBox->Name = L"FieldCenterDECTextBox";
			this->FieldCenterDECTextBox->Size = System::Drawing::Size(65, 20);
			this->FieldCenterDECTextBox->TabIndex = 21;
			this->FieldCenterDECTextBox->Text = L" 00:00:00.0";
			this->FieldCenterDECTextBox->WordWrap = false;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->Controls->Add(this->CancelButton, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 136);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(200, 47);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(112, 12);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &InitializeAstrometryDialog::CancelButton_Clicked);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(12, 12);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 2;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &InitializeAstrometryDialog::OkayButton_Clicked);
			// 
			// InitializeAstrometryDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(206, 186);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"InitializeAstrometryDialog";
			this->Text = L"Init Astrometry";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

public:  void ShowTheDialog(void) {

			 InitializeAstrometryDialog::FormPtr->ShowDialog();
		 }

private: System::Void OkayButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];

			 InitializeAstrometryDialog::FormPtr->GetFieldCenterRATextBox(buffer);
			 sscanf_s(buffer, "%lf", &ccd->Image.plateSolution.InitFieldCenterRA);
			 InitializeAstrometryDialog::FormPtr->GetFieldCenterDECTextBox(buffer);
			 sscanf_s(buffer, "%lf", &ccd->Image.plateSolution.InitFieldCenterDEC);
			 InitializeAstrometryDialog::FormPtr->GetPixelScaleTextBox(buffer);
			 sscanf_s(buffer, "%lf", &ccd->Image.plateSolution.PixelScale);

			 InitializeAstrometryDialog::FormPtr->Hide();
			 InitializeCancelled = false;
			 }

private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 InitializeAstrometryDialog::FormPtr->Hide();
			 InitializeCancelled = true;
		 }

public: static void SetFieldCenterRATextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		InitializeAstrometryDialog::FormPtr->FieldCenterRATextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFieldCenterRATextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = InitializeAstrometryDialog::FormPtr->FieldCenterRATextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetFieldCenterDECTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		InitializeAstrometryDialog::FormPtr->FieldCenterDECTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetFieldCenterDECTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = InitializeAstrometryDialog::FormPtr->FieldCenterDECTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}

public: static void SetPixelScaleTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		InitializeAstrometryDialog::FormPtr->PixelScaleTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetPixelScaleTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = InitializeAstrometryDialog::FormPtr->PixelScaleTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}


};
}
