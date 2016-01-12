#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//#include "Form1.h"
#include "doRoutines.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for PickAlignStarDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PickAlignStarDialog : public System::Windows::Forms::Form
	{
	public:
		static PickAlignStarDialog^ FormPtr;
		PickAlignStarDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			PickAlignStarDialogExists = TRUE;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PickAlignStarDialog()
		{
			if (components)
			{
				delete components;
			}
			PickAlignStarDialogExists = FALSE;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  ApplyButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::GroupBox^  groupbox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  X1TextBox;
	private: System::Windows::Forms::TextBox^  Y1TextBox;
	private: System::Windows::Forms::TextBox^  X2TextBox;
	private: System::Windows::Forms::TextBox^  Y2TextBox;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  StarXTextBox;
	private: System::Windows::Forms::TextBox^  StarYTextBox;
	private: System::Windows::Forms::TextBox^  StarMaxTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
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
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->ApplyButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->StarXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupbox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->X1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Y1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->X2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Y2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->groupbox1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(265, 194);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				33.33333F)));
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->ApplyButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 148);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(259, 43);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(178, 10);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 4;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &PickAlignStarDialog::CancelButton_Click);
			// 
			// ApplyButton
			// 
			this->ApplyButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ApplyButton->Location = System::Drawing::Point(91, 10);
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(75, 23);
			this->ApplyButton->TabIndex = 3;
			this->ApplyButton->Text = L"Apply";
			this->ApplyButton->UseVisualStyleBackColor = true;
			this->ApplyButton->Click += gcnew System::EventHandler(this, &PickAlignStarDialog::ApplyButton_Click);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(5, 10);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 1;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &PickAlignStarDialog::OkButton_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupbox1, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 139)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(259, 139);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel6);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(132, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(124, 133);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Star";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel6->Controls->Add(this->label9, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->label10, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->label11, 0, 2);
			this->tableLayoutPanel6->Controls->Add(this->StarXTextBox, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->StarYTextBox, 1, 1);
			this->tableLayoutPanel6->Controls->Add(this->StarMaxTextBox, 1, 2);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 3;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(118, 114);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(41, 12);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(15, 13);
			this->label9->TabIndex = 5;
			this->label9->Text = L"x:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(41, 50);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(15, 13);
			this->label10->TabIndex = 6;
			this->label10->Text = L"y:";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(26, 88);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(30, 13);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Max:";
			// 
			// StarXTextBox
			// 
			this->StarXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarXTextBox->Location = System::Drawing::Point(62, 9);
			this->StarXTextBox->Name = L"StarXTextBox";
			this->StarXTextBox->Size = System::Drawing::Size(53, 20);
			this->StarXTextBox->TabIndex = 9;
			// 
			// StarYTextBox
			// 
			this->StarYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarYTextBox->Location = System::Drawing::Point(62, 47);
			this->StarYTextBox->Name = L"StarYTextBox";
			this->StarYTextBox->Size = System::Drawing::Size(53, 20);
			this->StarYTextBox->TabIndex = 10;
			// 
			// StarMaxTextBox
			// 
			this->StarMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarMaxTextBox->Location = System::Drawing::Point(62, 85);
			this->StarMaxTextBox->Name = L"StarMaxTextBox";
			this->StarMaxTextBox->Size = System::Drawing::Size(53, 20);
			this->StarMaxTextBox->TabIndex = 11;
			// 
			// groupbox1
			// 
			this->groupbox1->Controls->Add(this->tableLayoutPanel4);
			this->groupbox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupbox1->Location = System::Drawing::Point(3, 3);
			this->groupbox1->Name = L"groupbox1";
			this->groupbox1->Size = System::Drawing::Size(123, 133);
			this->groupbox1->TabIndex = 0;
			this->groupbox1->TabStop = false;
			this->groupbox1->Text = L"Box";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel4->Controls->Add(this->label3, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->label4, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->X1TextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->Y1TextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->X2TextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->Y2TextBox, 1, 3);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 4;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(117, 114);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"y2:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(34, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"x1:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"y1:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"x2:";
			// 
			// X1TextBox
			// 
			this->X1TextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->X1TextBox->Location = System::Drawing::Point(61, 4);
			this->X1TextBox->Name = L"X1TextBox";
			this->X1TextBox->Size = System::Drawing::Size(53, 20);
			this->X1TextBox->TabIndex = 9;
			// 
			// Y1TextBox
			// 
			this->Y1TextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Y1TextBox->Location = System::Drawing::Point(61, 32);
			this->Y1TextBox->Name = L"Y1TextBox";
			this->Y1TextBox->Size = System::Drawing::Size(53, 20);
			this->Y1TextBox->TabIndex = 10;
			// 
			// X2TextBox
			// 
			this->X2TextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->X2TextBox->Location = System::Drawing::Point(61, 60);
			this->X2TextBox->Name = L"X2TextBox";
			this->X2TextBox->Size = System::Drawing::Size(53, 20);
			this->X2TextBox->TabIndex = 11;
			// 
			// Y2TextBox
			// 
			this->Y2TextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Y2TextBox->Location = System::Drawing::Point(61, 89);
			this->Y2TextBox->Name = L"Y2TextBox";
			this->Y2TextBox->Size = System::Drawing::Size(53, 20);
			this->Y2TextBox->TabIndex = 12;
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 100);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel5->Controls->Add(this->label5, 0, 3);
			this->tableLayoutPanel5->Controls->Add(this->label6, 0, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 4;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(200, 100);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(76, 73);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"y2:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(76, 3);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"x1:";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(38, 58);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"y1:";
			// 
			// PickAlignStarDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(265, 194);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"PickAlignStarDialog";
			this->Text = L"PickAlignStarDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->groupbox1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void ApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
public: static void ShowPickAlignStarDialog() {
			PickAlignStarDialog::FormPtr->ShowDialog();
		}
public: static void HidePickAlignStarDialog() {
			PickAlignStarDialog::FormPtr->Hide();
		}
public: static void SetStarXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		PickAlignStarDialog::FormPtr->StarXTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStarXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = PickAlignStarDialog::FormPtr->StarXTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetStarYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		PickAlignStarDialog::FormPtr->StarYTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStarYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = PickAlignStarDialog::FormPtr->StarYTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
public: static void SetStarMaxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		PickAlignStarDialog::FormPtr->StarMaxTextBox->Text = buffer;
		delete buffer;
		}
public: static void GetStarMaxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = PickAlignStarDialog::FormPtr->StarMaxTextBox->Text;
		for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
		text[i] = 0;
		delete buffer;
		}
};
}
