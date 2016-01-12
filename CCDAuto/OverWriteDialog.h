#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "defines.h"
#include "doRoutines.h"


namespace CCDAuto {

	/// <summary>
	/// Summary for OverWriteDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class OverWriteDialog : public System::Windows::Forms::Form
	{
	public:
		static OverWriteDialog^ FormPtr;
		OverWriteDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			OverWriteDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OverWriteDialog()
		{
			if (components)
			{
				delete components;
			}
			OverWriteDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Button^  NoButton;
	private: System::Windows::Forms::Button^  YesButton;
	private: System::Windows::Forms::Label^  OverWritePrompt;
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
			this->NoButton = (gcnew System::Windows::Forms::Button());
			this->YesButton = (gcnew System::Windows::Forms::Button());
			this->OverWritePrompt = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->OverWritePrompt, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 58.97436F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 41.02564F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(292, 117);
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
			this->tableLayoutPanel2->Controls->Add(this->NoButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->YesButton, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 72);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 42)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(286, 42);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(200, 9);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 5;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &OverWriteDialog::CancelButton_Click);
			// 
			// NoButton
			// 
			this->NoButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->NoButton->Location = System::Drawing::Point(105, 9);
			this->NoButton->Name = L"NoButton";
			this->NoButton->Size = System::Drawing::Size(75, 23);
			this->NoButton->TabIndex = 4;
			this->NoButton->Text = L"No";
			this->NoButton->UseVisualStyleBackColor = true;
			this->NoButton->Click += gcnew System::EventHandler(this, &OverWriteDialog::NoButton_Click);
			// 
			// YesButton
			// 
			this->YesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->YesButton->Location = System::Drawing::Point(10, 9);
			this->YesButton->Name = L"YesButton";
			this->YesButton->Size = System::Drawing::Size(75, 23);
			this->YesButton->TabIndex = 3;
			this->YesButton->Text = L"Yes";
			this->YesButton->UseVisualStyleBackColor = true;
			this->YesButton->Click += gcnew System::EventHandler(this, &OverWriteDialog::YesButton_Click);
			// 
			// OverWritePrompt
			// 
			this->OverWritePrompt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OverWritePrompt->AutoSize = true;
			this->OverWritePrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OverWritePrompt->Location = System::Drawing::Point(7, 24);
			this->OverWritePrompt->Name = L"OverWritePrompt";
			this->OverWritePrompt->Size = System::Drawing::Size(278, 20);
			this->OverWritePrompt->TabIndex = 1;
			this->OverWritePrompt->Text = L"File exists, sure you want to overwrite\?";
			// 
			// OverWriteDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 117);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"OverWriteDialog";
			this->Text = L"OverWrite Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void YesButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 OverWriteDialogAnswer = YES;
			 }
private: System::Void NoButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 OverWriteDialogAnswer = NO;
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 OverWriteDialogAnswer = CANCEL;
		 }
public:  static void ShowTheDialog(char *prompt) {
			String ^buffer;
			buffer = gcnew String(prompt);
			OverWriteDialog::FormPtr->OverWritePrompt->Text = buffer;
			delete buffer;
		 }
};
}
