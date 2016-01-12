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
	/// Summary for ProgressDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ProgressDialog : public System::Windows::Forms::Form
	{
	public:
		static ProgressDialog^ FormPtr;
		ProgressDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			CCDAuto::ProgressDialogExists = TRUE;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProgressDialog()
		{
			if (components)
			{
				delete components;
			}
			CCDAuto::ProgressDialogExists = FALSE;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 

	private: System::Windows::Forms::Label^  ProgressDialogLabel;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::ProgressBar^  ProgressDialogBar;
	private: System::Windows::Forms::Button^  CancelButton;

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
			this->ProgressDialogLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ProgressDialogBar = (gcnew System::Windows::Forms::ProgressBar());
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
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->ProgressDialogLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.28986F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 79.71014F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(201, 138);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// ProgressDialogLabel
			// 
			this->ProgressDialogLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ProgressDialogLabel->AutoSize = true;
			this->ProgressDialogLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ProgressDialogLabel->Location = System::Drawing::Point(70, 4);
			this->ProgressDialogLabel->Name = L"ProgressDialogLabel";
			this->ProgressDialogLabel->Size = System::Drawing::Size(61, 19);
			this->ProgressDialogLabel->TabIndex = 2;
			this->ProgressDialogLabel->Text = L"Progress";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->ProgressDialogBar, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->CancelButton, 0, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 31);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(195, 100);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// ProgressDialogBar
			// 
			this->ProgressDialogBar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ProgressDialogBar->Location = System::Drawing::Point(14, 9);
			this->ProgressDialogBar->Name = L"ProgressDialogBar";
			this->ProgressDialogBar->Size = System::Drawing::Size(166, 31);
			this->ProgressDialogBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->ProgressDialogBar->TabIndex = 2;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(60, 63);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &ProgressDialog::CancelButton_Clicked);
			// 
			// ProgressDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(201, 138);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"ProgressDialog";
			this->Text = L"Image Progress";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
public: static void SetProgressDialogLabel(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ProgressDialog::FormPtr->ProgressDialogLabel->Text = buffer;
			delete buffer;
		}
public: static void SetProgressDialogBar(int value) {
			ProgressDialog::FormPtr->ProgressDialogBar->Value = value;
		}
public: static void ShowProgressDialog() {
			ProgressDialog::FormPtr->Show();
		}
public: static void HideProgressDialog() {
			ProgressDialog::FormPtr->Hide();
		}

#pragma endregion

private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
			CancelCurrentAcquire = true;
		 }
};
}
