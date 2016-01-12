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
	/// Summary for YesNoDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class YesNoDialog : public System::Windows::Forms::Form
	{
	public:
		static YesNoDialog^ FormPtr;
		YesNoDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			YesNoDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~YesNoDialog()
		{
			if (components)
			{
				delete components;
			}
			YesNoDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  NoButton;
	private: System::Windows::Forms::Button^  YesButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Label^  Message;

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
			this->NoButton = (gcnew System::Windows::Forms::Button());
			this->YesButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->Message = (gcnew System::Windows::Forms::Label());
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
			this->tableLayoutPanel1->Controls->Add(this->Message, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 65.46763F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.53238F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(292, 120);
			this->tableLayoutPanel1->TabIndex = 1;
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
			this->tableLayoutPanel2->Controls->Add(this->NoButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->YesButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 81);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(286, 36);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// NoButton
			// 
			this->NoButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->NoButton->Location = System::Drawing::Point(105, 6);
			this->NoButton->Name = L"NoButton";
			this->NoButton->Size = System::Drawing::Size(75, 23);
			this->NoButton->TabIndex = 7;
			this->NoButton->Text = L"No";
			this->NoButton->UseVisualStyleBackColor = true;
			this->NoButton->Click += gcnew System::EventHandler(this, &YesNoDialog::NoButton_Click);
			// 
			// YesButton
			// 
			this->YesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->YesButton->Location = System::Drawing::Point(10, 6);
			this->YesButton->Name = L"YesButton";
			this->YesButton->Size = System::Drawing::Size(75, 23);
			this->YesButton->TabIndex = 2;
			this->YesButton->Text = L"Yes";
			this->YesButton->UseVisualStyleBackColor = true;
			this->YesButton->Click += gcnew System::EventHandler(this, &YesNoDialog::YesButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(200, 6);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 6;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &YesNoDialog::CancelButton_Click);
			// 
			// Message
			// 
			this->Message->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Message->AutoSize = true;
			this->Message->Location = System::Drawing::Point(121, 32);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(50, 13);
			this->Message->TabIndex = 1;
			this->Message->Text = L"Message";
			// 
			// YesNoDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 120);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"YesNoDialog";
			this->Text = L"Yes/No Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void YesButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBoxAnswer = YES;
			 YesNoDialog::FormPtr->Hide();
		 }
private: System::Void NoButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBoxAnswer = NO;
			 YesNoDialog::FormPtr->Hide();
		 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBoxAnswer = CANCEL;
			 YesNoDialog::FormPtr->Hide();
		 }
public: static void SetMessage(char *text) {
			String ^buffer;
		    buffer = gcnew String(text);
		    YesNoDialog::FormPtr->Message->Text = buffer;
		    delete buffer;
		}
public: static void ShowTheDialog(bool Modal) {
			if (Modal)
				YesNoDialog::FormPtr->ShowDialog();
			else
				YesNoDialog::FormPtr->Show();
		}
public: static void HideTheDialog(void) {
			YesNoDialog::FormPtr->Hide();
		}
};
}
