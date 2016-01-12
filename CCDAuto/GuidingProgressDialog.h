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
	/// Summary for GuidingProgressDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class GuidingProgressDialog : public System::Windows::Forms::Form
	{
	public:
		static GuidingProgressDialog^ FormPtr;
		GuidingProgressDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			CCDAuto::GuidingProgressDialogExists = TRUE;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GuidingProgressDialog()
		{
			if (components)
			{
				delete components;
			}
			CCDAuto::GuidingProgressDialogExists = TRUE;

		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ProgressBar^  GuidingProgressDialogBar;
	protected: 

	private: System::Windows::Forms::Label^  GuidingProgressDialogLabel;


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
			this->GuidingProgressDialogBar = (gcnew System::Windows::Forms::ProgressBar());
			this->GuidingProgressDialogLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->GuidingProgressDialogBar, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->GuidingProgressDialogLabel, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 35.29412F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 64.70588F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(202, 78);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// GuidingProgressDialogBar
			// 
			this->GuidingProgressDialogBar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GuidingProgressDialogBar->Location = System::Drawing::Point(18, 37);
			this->GuidingProgressDialogBar->Name = L"GuidingProgressDialogBar";
			this->GuidingProgressDialogBar->Size = System::Drawing::Size(166, 31);
			this->GuidingProgressDialogBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->GuidingProgressDialogBar->TabIndex = 1;
			// 
			// GuidingProgressDialogLabel
			// 
			this->GuidingProgressDialogLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GuidingProgressDialogLabel->AutoSize = true;
			this->GuidingProgressDialogLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GuidingProgressDialogLabel->Location = System::Drawing::Point(70, 4);
			this->GuidingProgressDialogLabel->Name = L"GuidingProgressDialogLabel";
			this->GuidingProgressDialogLabel->Size = System::Drawing::Size(61, 19);
			this->GuidingProgressDialogLabel->TabIndex = 2;
			this->GuidingProgressDialogLabel->Text = L"Progress";
			// 
			// GuidingProgressDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(202, 78);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"GuidingProgressDialog";
			this->Text = L"Guiding Progress";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
public: static void SetGuidingProgressDialogLabel(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			GuidingProgressDialog::FormPtr->GuidingProgressDialogLabel->Text = buffer;
			delete buffer;
		}
public: static void SetGuidingProgressDialogBar(int value) {
			GuidingProgressDialog::FormPtr->GuidingProgressDialogBar->Value = value;
		}
public: static void ShowGuidingProgressDialog() {
			GuidingProgressDialog::FormPtr->ShowDialog();
		}
public: static void HideGuidingProgressDialog() {
			GuidingProgressDialog::FormPtr->Hide();
		}

#pragma endregion
	};
}
