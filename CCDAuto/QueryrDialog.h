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
	/// Summary for QueryrDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class QueryrDialog : public System::Windows::Forms::Form
	{
	public:
		static QueryrDialog^ FormPtr;
		static float value;
		static bool okay;
		QueryrDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			QueryrDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QueryrDialog()
		{
			if (components)
			{
				delete components;
			}
			QueryrDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  Prompt;
	private: System::Windows::Forms::TextBox^  AnswerTextBox;
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
			this->Prompt = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->AnswerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(292, 126);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// Prompt
			// 
			this->Prompt->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->Prompt->AutoSize = true;
			this->Prompt->Location = System::Drawing::Point(102, 23);
			this->Prompt->Name = L"Prompt";
			this->Prompt->Size = System::Drawing::Size(43, 13);
			this->Prompt->TabIndex = 0;
			this->Prompt->Text = L"Prompt:";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				52.0979F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				47.9021F)));
			this->tableLayoutPanel2->Controls->Add(this->OkButton, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->Prompt, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->AnswerTextBox, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(286, 120);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// AnswerTextBox
			// 
			this->AnswerTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->AnswerTextBox->Location = System::Drawing::Point(151, 20);
			this->AnswerTextBox->Name = L"AnswerTextBox";
			this->AnswerTextBox->Size = System::Drawing::Size(70, 20);
			this->AnswerTextBox->TabIndex = 1;
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(36, 78);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 3;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &QueryrDialog::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(179, 78);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 6;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &QueryrDialog::CancelButton_Click);
			// 
			// QueryrDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 126);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"QueryrDialog";
			this->Text = L"QueryrDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 QueryrDialog::FormPtr->okay = true;
			 QueryrDialog::Hide();
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 QueryrDialog::FormPtr->okay = false;
			 QueryrDialog::FormPtr->Hide();
		 }
public:  static bool ShowTheDialog(char *prompt, float *answer) {

			 int i;
			 char text[80];
			 String ^buffer;
			 buffer = gcnew String(prompt);

			 QueryrDialog::FormPtr->Prompt->Text = buffer;
			 delete buffer;
			 QueryrDialog::FormPtr->value = *answer;
			 QueryrDialog::FormPtr->okay = true;
			 QueryrDialog::FormPtr->ShowDialog();
			 if (! QueryrDialog::FormPtr->okay)
				 return false;

			 buffer = gcnew String("");
			 buffer = QueryrDialog::FormPtr->AnswerTextBox->Text;
			 for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			 text[i] = 0;
			 sscanf_s(text, "%f", answer);
			 delete buffer;
			 return true;
		 }
};
}
