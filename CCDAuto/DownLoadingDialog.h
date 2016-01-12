#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CCDAuto {

	/// <summary>
	/// Summary for DownLoadingDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DownLoadingDialog : public System::Windows::Forms::Form
	{
	public:
		DownLoadingDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DownLoadingDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::ProgressBar^  DownLoadingProgressBar;
	private: System::Windows::Forms::Label^  DownloadingLabel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  DownLoadingCancelButton;

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->DownloadingLabel = (gcnew System::Windows::Forms::Label());
			this->DownLoadingProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DownLoadingCancelButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->DownLoadingCancelButton, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 64.95727F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 35.04274F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(260, 117);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				20)));
			this->tableLayoutPanel2->Controls->Add(this->splitContainer1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->DownloadingLabel, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(254, 70);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 38);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->DownLoadingProgressBar);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->label1);
			this->splitContainer1->Size = System::Drawing::Size(248, 29);
			this->splitContainer1->SplitterDistance = 212;
			this->splitContainer1->TabIndex = 0;
			// 
			// DownloadingLabel
			// 
			this->DownloadingLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DownloadingLabel->AutoSize = true;
			this->DownloadingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DownloadingLabel->Location = System::Drawing::Point(35, 7);
			this->DownloadingLabel->Name = L"DownloadingLabel";
			this->DownloadingLabel->Size = System::Drawing::Size(183, 20);
			this->DownloadingLabel->TabIndex = 1;
			this->DownloadingLabel->Text = L"Downloading Frame...";
			// 
			// DownLoadingProgressBar
			// 
			this->DownLoadingProgressBar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DownLoadingProgressBar->Location = System::Drawing::Point(1, 6);
			this->DownLoadingProgressBar->Name = L"DownLoadingProgressBar";
			this->DownLoadingProgressBar->Size = System::Drawing::Size(209, 23);
			this->DownLoadingProgressBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->DownLoadingProgressBar->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"%";
			// 
			// DownLoadingCancelButton
			// 
			this->DownLoadingCancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DownLoadingCancelButton->Location = System::Drawing::Point(92, 85);
			this->DownLoadingCancelButton->Name = L"DownLoadingCancelButton";
			this->DownLoadingCancelButton->Size = System::Drawing::Size(75, 23);
			this->DownLoadingCancelButton->TabIndex = 1;
			this->DownLoadingCancelButton->Text = L"Cancel";
			this->DownLoadingCancelButton->UseVisualStyleBackColor = true;
			this->DownLoadingCancelButton->Click += gcnew System::EventHandler(this, &DownLoadingDialog::DownLoadingCancelButton_Click);
			// 
			// DownLoadingDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 117);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"DownLoadingDialog";
			this->Text = L"DownLoading Progress";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DownLoadingCancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
