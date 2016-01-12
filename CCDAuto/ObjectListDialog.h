#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "doRoutines.h"
#include "Form1.h"

namespace CCDAuto {

	/// <summary>
	/// Summary for ObjectListDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ObjectListDialog : public System::Windows::Forms::Form
	{
	public:
		static ObjectListDialog^ FormPtr;
		ObjectListDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			ObjectListDialogExists = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ObjectListDialog()
		{
			if (components)
			{
				delete components;
			}
			ObjectListDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;






	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  ObjectListComboBox;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  UTextBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  BTextBox;
	private: System::Windows::Forms::TextBox^  VTextBox;
	private: System::Windows::Forms::TextBox^  RTextBox;
	private: System::Windows::Forms::TextBox^  ITextBox;




	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  NameTextBox;
	private: System::Windows::Forms::TextBox^  ObjectTypeTextBox;
	private: System::Windows::Forms::TextBox^  VarTypeTextBox;
	private: System::Windows::Forms::TextBox^  SpectralTypeTextBox;

	private: System::Windows::Forms::TextBox^  RATextBox;
	private: System::Windows::Forms::TextBox^  DECTextBox;






	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  OkButton;
	private: System::Windows::Forms::ToolStripButton^  NewButton;
	private: System::Windows::Forms::ToolStripButton^  ApplyButton;
	private: System::Windows::Forms::ToolStripButton^  SelectButton;




	private: System::Windows::Forms::ToolStripButton^  DeleteButton;

	private: System::Windows::Forms::CheckBox^  EditCheckBox;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ObjectListDialog::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ObjectListComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->UTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->BTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ITextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ObjectTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VarTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SpectralTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RATextBox = (gcnew System::Windows::Forms::TextBox());
			this->DECTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->OkButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->NewButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->ApplyButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->SelectButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->DeleteButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->EditCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->toolStrip1->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80.93645F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 19.06355F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(421, 299);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				32.14286F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				27.10084F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				40.96638F)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->groupBox3, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 235)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(415, 235);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ObjectListComboBox);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(127, 229);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Object List";
			// 
			// ObjectListComboBox
			// 
			this->ObjectListComboBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ObjectListComboBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ObjectListComboBox->FormattingEnabled = true;
			this->ObjectListComboBox->Location = System::Drawing::Point(3, 16);
			this->ObjectListComboBox->Name = L"ObjectListComboBox";
			this->ObjectListComboBox->Size = System::Drawing::Size(121, 26);
			this->ObjectListComboBox->TabIndex = 0;
			this->ObjectListComboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &ObjectListDialog::ComboBox_SelectionChangeCommitted);
			this->ObjectListComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ObjectListDialog::ObjectListDialogComboBox_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tableLayoutPanel3);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(136, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(106, 229);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Magnitudes";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				30.8642F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				69.1358F)));
			this->tableLayoutPanel3->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->UTextBox, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->BTextBox, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->VTextBox, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->RTextBox, 1, 3);
			this->tableLayoutPanel3->Controls->Add(this->ITextBox, 1, 4);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 5;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(100, 210);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 182);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"I:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"U:";
			// 
			// UTextBox
			// 
			this->UTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->UTextBox->BackColor = System::Drawing::Color::White;
			this->UTextBox->Location = System::Drawing::Point(33, 11);
			this->UTextBox->Name = L"UTextBox";
			this->UTextBox->ReadOnly = true;
			this->UTextBox->Size = System::Drawing::Size(46, 20);
			this->UTextBox->TabIndex = 8;
			this->UTextBox->Text = L"99.999";
			this->UTextBox->WordWrap = false;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"B:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"V:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 140);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"R:";
			// 
			// BTextBox
			// 
			this->BTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->BTextBox->BackColor = System::Drawing::Color::White;
			this->BTextBox->Location = System::Drawing::Point(33, 53);
			this->BTextBox->Name = L"BTextBox";
			this->BTextBox->ReadOnly = true;
			this->BTextBox->Size = System::Drawing::Size(46, 20);
			this->BTextBox->TabIndex = 13;
			this->BTextBox->Text = L"99.999";
			this->BTextBox->WordWrap = false;
			// 
			// VTextBox
			// 
			this->VTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->VTextBox->BackColor = System::Drawing::Color::White;
			this->VTextBox->Location = System::Drawing::Point(33, 95);
			this->VTextBox->Name = L"VTextBox";
			this->VTextBox->ReadOnly = true;
			this->VTextBox->Size = System::Drawing::Size(46, 20);
			this->VTextBox->TabIndex = 14;
			this->VTextBox->Text = L"99.999";
			this->VTextBox->WordWrap = false;
			// 
			// RTextBox
			// 
			this->RTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->RTextBox->BackColor = System::Drawing::Color::White;
			this->RTextBox->Location = System::Drawing::Point(33, 137);
			this->RTextBox->Name = L"RTextBox";
			this->RTextBox->ReadOnly = true;
			this->RTextBox->Size = System::Drawing::Size(46, 20);
			this->RTextBox->TabIndex = 15;
			this->RTextBox->Text = L"99.999";
			this->RTextBox->WordWrap = false;
			// 
			// ITextBox
			// 
			this->ITextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ITextBox->BackColor = System::Drawing::Color::White;
			this->ITextBox->Location = System::Drawing::Point(33, 179);
			this->ITextBox->Name = L"ITextBox";
			this->ITextBox->ReadOnly = true;
			this->ITextBox->Size = System::Drawing::Size(46, 20);
			this->ITextBox->TabIndex = 16;
			this->ITextBox->Text = L"99.999";
			this->ITextBox->WordWrap = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tableLayoutPanel4);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(248, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(164, 229);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Object Parameters";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				34.43983F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				65.56017F)));
			this->tableLayoutPanel4->Controls->Add(this->label11, 0, 5);
			this->tableLayoutPanel4->Controls->Add(this->label6, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->label7, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->label8, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->label9, 0, 3);
			this->tableLayoutPanel4->Controls->Add(this->label10, 0, 4);
			this->tableLayoutPanel4->Controls->Add(this->NameTextBox, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->ObjectTypeTextBox, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->VarTypeTextBox, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->SpectralTypeTextBox, 1, 3);
			this->tableLayoutPanel4->Controls->Add(this->RATextBox, 1, 4);
			this->tableLayoutPanel4->Controls->Add(this->DECTextBox, 1, 5);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 6;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(158, 210);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(19, 183);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(32, 13);
			this->label11->TabIndex = 8;
			this->label11->Text = L"DEC:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 10);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Name:";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 38);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 26);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Object Type:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 72);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 26);
			this->label8->TabIndex = 5;
			this->label8->Text = L"Variable Type:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(5, 106);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 26);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Spectral Type:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(26, 146);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(25, 13);
			this->label10->TabIndex = 7;
			this->label10->Text = L"RA:";
			// 
			// NameTextBox
			// 
			this->NameTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NameTextBox->BackColor = System::Drawing::Color::White;
			this->NameTextBox->Location = System::Drawing::Point(57, 7);
			this->NameTextBox->MaxLength = 10;
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->ReadOnly = true;
			this->NameTextBox->Size = System::Drawing::Size(75, 20);
			this->NameTextBox->TabIndex = 9;
			this->NameTextBox->WordWrap = false;
			// 
			// ObjectTypeTextBox
			// 
			this->ObjectTypeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ObjectTypeTextBox->BackColor = System::Drawing::Color::White;
			this->ObjectTypeTextBox->Location = System::Drawing::Point(57, 41);
			this->ObjectTypeTextBox->MaxLength = 10;
			this->ObjectTypeTextBox->Name = L"ObjectTypeTextBox";
			this->ObjectTypeTextBox->ReadOnly = true;
			this->ObjectTypeTextBox->Size = System::Drawing::Size(75, 20);
			this->ObjectTypeTextBox->TabIndex = 10;
			this->ObjectTypeTextBox->WordWrap = false;
			// 
			// VarTypeTextBox
			// 
			this->VarTypeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->VarTypeTextBox->BackColor = System::Drawing::Color::White;
			this->VarTypeTextBox->Location = System::Drawing::Point(57, 75);
			this->VarTypeTextBox->MaxLength = 10;
			this->VarTypeTextBox->Name = L"VarTypeTextBox";
			this->VarTypeTextBox->ReadOnly = true;
			this->VarTypeTextBox->Size = System::Drawing::Size(75, 20);
			this->VarTypeTextBox->TabIndex = 11;
			this->VarTypeTextBox->WordWrap = false;
			// 
			// SpectralTypeTextBox
			// 
			this->SpectralTypeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->SpectralTypeTextBox->BackColor = System::Drawing::Color::White;
			this->SpectralTypeTextBox->Location = System::Drawing::Point(57, 109);
			this->SpectralTypeTextBox->MaxLength = 10;
			this->SpectralTypeTextBox->Name = L"SpectralTypeTextBox";
			this->SpectralTypeTextBox->ReadOnly = true;
			this->SpectralTypeTextBox->Size = System::Drawing::Size(75, 20);
			this->SpectralTypeTextBox->TabIndex = 12;
			this->SpectralTypeTextBox->WordWrap = false;
			// 
			// RATextBox
			// 
			this->RATextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->RATextBox->BackColor = System::Drawing::Color::White;
			this->RATextBox->Location = System::Drawing::Point(57, 143);
			this->RATextBox->MaxLength = 11;
			this->RATextBox->Name = L"RATextBox";
			this->RATextBox->ReadOnly = true;
			this->RATextBox->Size = System::Drawing::Size(71, 20);
			this->RATextBox->TabIndex = 13;
			this->RATextBox->Text = L"00:00:00.00";
			this->RATextBox->WordWrap = false;
			// 
			// DECTextBox
			// 
			this->DECTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DECTextBox->BackColor = System::Drawing::Color::White;
			this->DECTextBox->Location = System::Drawing::Point(57, 180);
			this->DECTextBox->MaxLength = 11;
			this->DECTextBox->Name = L"DECTextBox";
			this->DECTextBox->ReadOnly = true;
			this->DECTextBox->Size = System::Drawing::Size(71, 20);
			this->DECTextBox->TabIndex = 14;
			this->DECTextBox->Text = L"+00:00:00.0";
			this->DECTextBox->WordWrap = false;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				81.5126F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				18.48739F)));
			this->tableLayoutPanel5->Controls->Add(this->toolStrip1, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->EditCheckBox, 1, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 244);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(415, 52);
			this->tableLayoutPanel5->TabIndex = 1;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->OkButton, this->NewButton, 
				this->ApplyButton, this->SelectButton, this->DeleteButton});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(338, 52);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// OkButton
			// 
			this->OkButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OkButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"OkButton.Image")));
			this->OkButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(46, 49);
			this->OkButton->Text = L"Ok";
			this->OkButton->Click += gcnew System::EventHandler(this, &ObjectListDialog::OkButton_Click);
			// 
			// NewButton
			// 
			this->NewButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NewButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"NewButton.Image")));
			this->NewButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->NewButton->Name = L"NewButton";
			this->NewButton->Size = System::Drawing::Size(56, 49);
			this->NewButton->Text = L"New";
			this->NewButton->Click += gcnew System::EventHandler(this, &ObjectListDialog::NewButton_Click);
			// 
			// ApplyButton
			// 
			this->ApplyButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ApplyButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ApplyButton.Image")));
			this->ApplyButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ApplyButton->Name = L"ApplyButton";
			this->ApplyButton->Size = System::Drawing::Size(64, 49);
			this->ApplyButton->Text = L"Apply";
			this->ApplyButton->Click += gcnew System::EventHandler(this, &ObjectListDialog::ApplyButton_Click);
			// 
			// SelectButton
			// 
			this->SelectButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->SelectButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SelectButton.Image")));
			this->SelectButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->SelectButton->Name = L"SelectButton";
			this->SelectButton->Size = System::Drawing::Size(69, 49);
			this->SelectButton->Text = L"Select";
			this->SelectButton->Click += gcnew System::EventHandler(this, &ObjectListDialog::SelectButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DeleteButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"DeleteButton.Image")));
			this->DeleteButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(69, 49);
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->Click += gcnew System::EventHandler(this, &ObjectListDialog::DeleteButton_Click);
			// 
			// EditCheckBox
			// 
			this->EditCheckBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EditCheckBox->AutoSize = true;
			this->EditCheckBox->Location = System::Drawing::Point(341, 17);
			this->EditCheckBox->Name = L"EditCheckBox";
			this->EditCheckBox->Size = System::Drawing::Size(71, 17);
			this->EditCheckBox->TabIndex = 3;
			this->EditCheckBox->Text = L"Edit Mode";
			this->EditCheckBox->UseVisualStyleBackColor = true;
			this->EditCheckBox->CheckedChanged += gcnew System::EventHandler(this, &ObjectListDialog::EditCheckBox_CheckedChanged);
			// 
			// ObjectListDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 299);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"ObjectListDialog";
			this->Text = L"Object List Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ObjectListDialog::FormPtr->Hide();
		 }
private: System::Void NewButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 // Set all Text boxes to read/write & clear them

			 ObjectListDialog::FormPtr->SetEditCheckBox(true);
			 ObjectListDialog::FormPtr->SetNameTextBox("");
			 ObjectListDialog::FormPtr->SetObjectTypeTextBox("");
			 ObjectListDialog::FormPtr->SetVarTypeTextBox("");
			 ObjectListDialog::FormPtr->SetSpectralTypeTextBox("");
			 ObjectListDialog::FormPtr->SetRATextBox("00:00:00");
			 ObjectListDialog::FormPtr->SetDECTextBox("+00:00:00");
			 ObjectListDialog::FormPtr->SetUTextBox("00.000");
			 ObjectListDialog::FormPtr->SetBTextBox("00.000");
			 ObjectListDialog::FormPtr->SetVTextBox("00.000");
			 ObjectListDialog::FormPtr->SetRTextBox("00.000");
			 ObjectListDialog::FormPtr->SetITextBox("00.000");
			 return;
		 }
private: System::Void ApplyButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 int nItems, hr, min, isec;
			 float sec;
			 char buffer[80], Message[160];
			 OBJECT obj, dummy;

			 if (ObjectListEditable) {
				 ObjectListDialog::FormPtr->GetNameTextBox(obj.name);
				 ObjectListDialog::FormPtr->GetObjectTypeTextBox(obj.objectType);
				 ObjectListDialog::FormPtr->GetVarTypeTextBox(obj.varType);
				 ObjectListDialog::FormPtr->GetSpectralTypeTextBox(obj.specType);
				 ObjectListDialog::FormPtr->GetRATextBox(obj.ra);
				 nItems = sscanf_s(obj.ra, "%2d:%2d:%f", &hr, &min, &sec);
				 if (nItems != 3) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's RA field not in"
						 " hh:mm:ss.s format: %s object not updated\n", obj.ra);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 ObjectListDialog::FormPtr->GetDECTextBox(obj.dec);
				 nItems = sscanf_s(obj.dec, "%3d:%2d:%2d", &hr, &min, &isec);
				 sec = ((float) isec);
				 if (nItems != 3) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's DEC field not in"
						 " +dd:mm:ss format: %s object not updated\n", obj.dec);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 ObjectListDialog::FormPtr->GetUTextBox(buffer);
				 nItems = sscanf_s(buffer, "%f", &obj.Mags[0]);
				 if (nItems != 1) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's U field not in"
						 " real number format: %s object not updated\n", buffer);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 ObjectListDialog::FormPtr->GetBTextBox(buffer);
				 nItems = sscanf_s(buffer, "%f", &obj.Mags[1]);
				 if (nItems != 1) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's B field not in"
						 " real number format: %s object not updated\n", buffer);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 ObjectListDialog::FormPtr->GetVTextBox(buffer);
				 nItems = sscanf_s(buffer, "%f", &obj.Mags[2]);
				 if (nItems != 1) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's V field not in"
						 " real number format: %s object not updated\n", buffer);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 ObjectListDialog::FormPtr->GetRTextBox(buffer);
				 nItems = sscanf_s(buffer, "%f", &obj.Mags[3]);
				 if (nItems != 1) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's R field not in"
						 " real number format: %s object not updated\n", buffer);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 ObjectListDialog::FormPtr->GetITextBox(buffer);
				 nItems = sscanf_s(buffer, "%f", &obj.Mags[4]);
				 if (nItems != 1) {
					 sprintf_s(Message, sizeof(Message), "*** Warning - Object's I field not in"
						 " real number format: %s object not updated\n", buffer);
					 Form1::CCDAutoForm->StatusPrint(Message);
					 return;
				 }
				 if (GetObjectInfo(obj.name,&dummy)) {
					 SetObjectInfo(obj.name, &obj);
					 sprintf_s(buffer, sizeof(buffer), "*** INFO - Updated existing object %s\n",
						 obj.name);
					 Form1::CCDAutoForm->StatusPrint(buffer);
				 } else {
					 AddObject(&obj);
					 sprintf_s(buffer, sizeof(buffer), "*** INFO - Added new object %s\n", obj.name);
					 Form1::CCDAutoForm->StatusPrint(buffer);
				 }
				 WriteObjectList();
			 }

		 }
private: System::Void SelectButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 int i;
			 OBJECT obj;
			 char name[80], buffer[80];
			 String^ string;

			 string = (String ^) ObjectListDialog::FormPtr->ObjectListComboBox->SelectedItem;
			 for (i=0; i<string->Length; i++) name[i] = (char) string[i];
			 name[i] = 0;
			 if (GetObjectInfo(name, &obj)) {
				 ObjectListDialog::FormPtr->SetNameTextBox(obj.name);
				 ObjectListDialog::FormPtr->SetObjectTypeTextBox(obj.objectType);
				 ObjectListDialog::FormPtr->SetSpectralTypeTextBox(obj.specType);
				 ObjectListDialog::FormPtr->SetVarTypeTextBox(obj.varType);
				 ObjectListDialog::FormPtr->SetRATextBox(obj.ra);
				 ObjectListDialog::FormPtr->SetDECTextBox(obj.dec);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[0]);
				 ObjectListDialog::FormPtr->SetUTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[1]);
				 ObjectListDialog::FormPtr->SetBTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[2]);
				 ObjectListDialog::FormPtr->SetVTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[3]);
				 ObjectListDialog::FormPtr->SetRTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[4]);
				 ObjectListDialog::FormPtr->SetITextBox(buffer);
			 }
			 ObjectListDialog::FormPtr->Refresh();

			 strcpy_s(singleSettings.ObjectName, sizeof(singleSettings.ObjectName), obj.name);
			 strcpy_s(seriesSettings.objectName, sizeof(seriesSettings.objectName), obj.name);
			 strcpy_s(stackSettings.ObjectName, sizeof(stackSettings.ObjectName), obj.name);
			 sprintf_s(buffer, sizeof(buffer), "*** Info - Object %s selected for single, series and stack exposures\n",
				 obj.name);
			 Form1::CCDAutoForm->StatusPrint(buffer);
		 }
private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 int i;
			 char name[80], buffer[80];
			 String^ string;

			 string = (String ^) ObjectListDialog::FormPtr->ObjectListComboBox->SelectedItem;
			 for (i=0; i<string->Length; i++) name[i] = (char) string[i];
			 name[i] = 0;
			 if (DeleteObject(name)) {
				 sprintf_s(buffer, sizeof(buffer), "*** INFO - Object %s was delete\n", name);
				 Form1::CCDAutoForm->StatusPrint(buffer);
				 WriteObjectList();
			 } else {
				 sprintf_s(buffer, sizeof(buffer), "*** Warning - Couldn't find object %s to delete\n", name);
				 Form1::CCDAutoForm->StatusPrint(buffer);
			 }
		 }
private: System::Void ObjectListDialogComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 int i;
			 OBJECT obj;
			 char name[80], buffer[80];
			 String^ string;

			 string = (String ^) ObjectListDialog::FormPtr->ObjectListComboBox->SelectedItem;
			 for (i=0; i<string->Length; i++) name[i] = (char) string[i];
			 name[i] = 0;
			 if (GetObjectInfo(name, &obj)) {
				 ObjectListDialog::FormPtr->SetNameTextBox(obj.name);
				 ObjectListDialog::FormPtr->SetObjectTypeTextBox(obj.objectType);
				 ObjectListDialog::FormPtr->SetSpectralTypeTextBox(obj.specType);
				 ObjectListDialog::FormPtr->SetVarTypeTextBox(obj.varType);
				 ObjectListDialog::FormPtr->SetRATextBox(obj.ra);
				 ObjectListDialog::FormPtr->SetDECTextBox(obj.dec);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[0]);
				 ObjectListDialog::FormPtr->SetUTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[1]);
				 ObjectListDialog::FormPtr->SetBTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[2]);
				 ObjectListDialog::FormPtr->SetVTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[3]);
				 ObjectListDialog::FormPtr->SetRTextBox(buffer);
				 sprintf_s(buffer, sizeof(buffer), "%6.3f", obj.Mags[4]);
				 ObjectListDialog::FormPtr->SetITextBox(buffer);
			 }
			 ObjectListDialog::FormPtr->Refresh();
			 return;
		 }
public:  static void ShowTheDialog(void) {
			 ObjectListDialog::FormPtr->ShowDialog();
		 }
public:  static void AddObjectNameToList(char *name) {
			 String^ buffer = gcnew String(name);
			 ObjectListDialog::FormPtr->ObjectListComboBox->Items->Add(buffer);
			 delete buffer;
		 }
public:  static void SetEditCheckBox(bool state) {
			 ObjectListDialog::FormPtr->EditCheckBox->Checked = state;
		 }
public:  static void SetComboBoxSelectedIndex(int index) {
			 ObjectListDialog::FormPtr->ObjectListComboBox->SelectedIndex = index;
		 }
public:  static void SetComboBoxSelectedText(char *text) {

			 String^ buffer = gcnew String(text);
			 ObjectListDialog::FormPtr->ObjectListComboBox->SelectedText = buffer;
			 delete buffer;
		 }
public: static void GetComboBoxSelectedText(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->ObjectListComboBox->SelectedText;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetNameTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->NameTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetNameTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->NameTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetObjectTypeTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->ObjectTypeTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetObjectTypeTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->ObjectTypeTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetVarTypeTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->VarTypeTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetVarTypeTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->VarTypeTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetSpectralTypeTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->SpectralTypeTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetSpectralTypeTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->SpectralTypeTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetRATextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->RATextBox->Text = buffer;
			delete buffer;
		}
public: static void GetRATextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->RATextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetDECTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->DECTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetDECTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->DECTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetUTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->UTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetUTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->UTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetBTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->BTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetBTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->BTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetVTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->VTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetVTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->VTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetRTextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->RTextBox->Text = buffer;
			delete buffer;
		}
public: static void GetRTextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->RTextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
public: static void SetITextBox(char *text) {
			String ^buffer;
			buffer = gcnew String(text);
			ObjectListDialog::FormPtr->ITextBox->Text = buffer;
			delete buffer;
		}
public: static void GetITextBox(char *text) {
			int i;
			String ^buffer = gcnew String("");
			buffer = ObjectListDialog::FormPtr->ITextBox->Text;
			for (i=0; i<buffer->Length; i++) text[i] = (char) buffer[i];
			text[i] = 0;
			delete buffer;
		}
private: System::Void ComboBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void EditCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if (ObjectListDialog::FormPtr->EditCheckBox->Checked)
				 ObjectListEditable = true;
			 else
				 ObjectListEditable = false;

			 ObjectListDialog::FormPtr->NameTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->ObjectTypeTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->VarTypeTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->SpectralTypeTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->RATextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->DECTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->UTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->BTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->VTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->RTextBox->ReadOnly = ! ObjectListEditable;
			 ObjectListDialog::FormPtr->ITextBox->ReadOnly = ! ObjectListEditable;
		 }
};
}
