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
	/// Summary for DefineListDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DefineListDialog : public System::Windows::Forms::Form
	{
	public:
		static DefineListDialog^ FormPtr;
	private: System::Windows::Forms::Button^  ToFileButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::SaveFileDialog^  SaveFileDialog;

	public: 
		static bool StopAutoDefine;
		DefineListDialog(void)
		{
			InitializeComponent();
			FormPtr = this;
			DefineListDialogExists = true;
			StopAutoDefine = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DefineListDialog()
		{
			if (components)
			{
				delete components;
			}
			DefineListDialogExists = false;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  AddStarButton;
	private: System::Windows::Forms::Button^  DeleteStarButton;
	private: System::Windows::Forms::Button^  AutoDefineButton;
	private: System::Windows::Forms::Button^  ClearListButton;
	private: System::Windows::Forms::Button^  FromFileButton;
	private: System::Windows::Forms::OpenFileDialog^  OpenFileDialog;
	private: System::Windows::Forms::Button^  StopAutoButton;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StopAutoButton = (gcnew System::Windows::Forms::Button());
			this->AddStarButton = (gcnew System::Windows::Forms::Button());
			this->DeleteStarButton = (gcnew System::Windows::Forms::Button());
			this->ClearListButton = (gcnew System::Windows::Forms::Button());
			this->FromFileButton = (gcnew System::Windows::Forms::Button());
			this->AutoDefineButton = (gcnew System::Windows::Forms::Button());
			this->ToFileButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.55639F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 59.39849F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.66917F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(248, 252);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Right click on star in image to define star,\r\nthen click add or delete star butto" 
				L"n";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel2->Controls->Add(this->StopAutoButton, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->AddStarButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->DeleteStarButton, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->ClearListButton, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->FromFileButton, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->AutoDefineButton, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->ToFileButton, 1, 3);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 60);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.00062F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.99813F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(242, 144);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// StopAutoButton
			// 
			this->StopAutoButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StopAutoButton->Location = System::Drawing::Point(144, 78);
			this->StopAutoButton->Name = L"StopAutoButton";
			this->StopAutoButton->Size = System::Drawing::Size(75, 23);
			this->StopAutoButton->TabIndex = 8;
			this->StopAutoButton->Text = L"Stop Auto";
			this->StopAutoButton->UseVisualStyleBackColor = true;
			this->StopAutoButton->Click += gcnew System::EventHandler(this, &DefineListDialog::StopAutoButton_Clicked);
			// 
			// AddStarButton
			// 
			this->AddStarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AddStarButton->Location = System::Drawing::Point(23, 6);
			this->AddStarButton->Name = L"AddStarButton";
			this->AddStarButton->Size = System::Drawing::Size(75, 23);
			this->AddStarButton->TabIndex = 3;
			this->AddStarButton->Text = L"Add Star";
			this->AddStarButton->UseVisualStyleBackColor = true;
			this->AddStarButton->Click += gcnew System::EventHandler(this, &DefineListDialog::AddStarButton_Click);
			// 
			// DeleteStarButton
			// 
			this->DeleteStarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DeleteStarButton->Location = System::Drawing::Point(144, 6);
			this->DeleteStarButton->Name = L"DeleteStarButton";
			this->DeleteStarButton->Size = System::Drawing::Size(75, 23);
			this->DeleteStarButton->TabIndex = 4;
			this->DeleteStarButton->Text = L"Delete Star";
			this->DeleteStarButton->UseVisualStyleBackColor = true;
			this->DeleteStarButton->Click += gcnew System::EventHandler(this, &DefineListDialog::DeleteStarButton_Click);
			// 
			// ClearListButton
			// 
			this->ClearListButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ClearListButton->Location = System::Drawing::Point(144, 42);
			this->ClearListButton->Name = L"ClearListButton";
			this->ClearListButton->Size = System::Drawing::Size(75, 23);
			this->ClearListButton->TabIndex = 6;
			this->ClearListButton->Text = L"Clear List";
			this->ClearListButton->UseVisualStyleBackColor = true;
			this->ClearListButton->Click += gcnew System::EventHandler(this, &DefineListDialog::ClearListButton_Click);
			// 
			// FromFileButton
			// 
			this->FromFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FromFileButton->Location = System::Drawing::Point(23, 42);
			this->FromFileButton->Name = L"FromFileButton";
			this->FromFileButton->Size = System::Drawing::Size(75, 23);
			this->FromFileButton->TabIndex = 7;
			this->FromFileButton->Text = L"From File";
			this->FromFileButton->UseVisualStyleBackColor = true;
			this->FromFileButton->Click += gcnew System::EventHandler(this, &DefineListDialog::FromFileButton_Clicked);
			// 
			// AutoDefineButton
			// 
			this->AutoDefineButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AutoDefineButton->Location = System::Drawing::Point(23, 78);
			this->AutoDefineButton->Name = L"AutoDefineButton";
			this->AutoDefineButton->Size = System::Drawing::Size(75, 23);
			this->AutoDefineButton->TabIndex = 5;
			this->AutoDefineButton->Text = L"Auto Define";
			this->AutoDefineButton->UseVisualStyleBackColor = true;
			this->AutoDefineButton->Click += gcnew System::EventHandler(this, &DefineListDialog::AutoDefineButton_Click);
			// 
			// ToFileButton
			// 
			this->ToFileButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ToFileButton->Location = System::Drawing::Point(144, 114);
			this->ToFileButton->Name = L"ToFileButton";
			this->ToFileButton->Size = System::Drawing::Size(75, 23);
			this->ToFileButton->TabIndex = 9;
			this->ToFileButton->Text = L"To File";
			this->ToFileButton->UseVisualStyleBackColor = true;
			this->ToFileButton->Click += gcnew System::EventHandler(this, &DefineListDialog::ToFileButton_Clicked);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel3->Controls->Add(this->CancelButton, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->OkButton, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 210);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(242, 39);
			this->tableLayoutPanel3->TabIndex = 4;
			// 
			// CancelButton
			// 
			this->CancelButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CancelButton->Location = System::Drawing::Point(144, 8);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 3;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &DefineListDialog::CancelButton_Clicked);
			// 
			// OkButton
			// 
			this->OkButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OkButton->Location = System::Drawing::Point(23, 8);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 2;
			this->OkButton->Text = L"Okay";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &DefineListDialog::OkButton_Click);
			// 
			// DefineListDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(248, 252);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"DefineListDialog";
			this->Text = L"Define Star List Dialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 STAR *sptr, *next;
			 char buffer[120];
			 int nStars;

			 // Count number of stars defined

			 sptr = CurrentStarList;
			 nStars = 0;
			 while (sptr != NULL) {
				 nStars++;
				 sptr = sptr->next;
			 }
			 sprintf_s(buffer, sizeof(buffer),
				 "*** INFO - Star list define with %d stars...\n", nStars);
			 Form1::CCDAutoForm->StatusPrint(buffer);

			 // Mark list as defined

			 if (nStars > 0)
				 CurrentStarListDefined = TRUE;

			 // delete "saved old " list

			 sptr = CurrentStarListSave;
			 while (sptr != NULL) {
				 next = sptr->next;
				 free(sptr);
				 sptr = next;
			 }
			 CurrentStarListSave = NULL;

			 DefineListDialog::FormPtr->Hide();
			 return;
		 }
private: System::Void AddStarButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 /* Get Current Star's parameters and add to star list */
			 
			 AddStar();
			 return;
		 }
private: System::Void DeleteStarButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 DeleteStar();
			 return;
		 }
private: System::Void AutoDefineButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 char buffer[80];
			 FRAME *frame;
			 int x0, y0, x, y, starMax, Found, npixels, numStars, findRad;
			 float starX, starY, fwhm, skyFlux, starFlux, Magnitude, MagErr;
			 float rad;
			 BitArray^ DontUse;

			 /* Start with empty star list */

			 clearListStars();
			 StopAutoDefine = false;

			 frame = &ccd->Image.light_frame;
			 npixels = frame->h * frame->w;
			 DontUse = gcnew BitArray(npixels);
			 x0 = frame->x;
			 y0 = frame->y;

			 numStars = 0;
			 rad = photometrySettings.aperatureRadius;
			 findRad = (int) photometrySettings.findRadius;
			 for (y=y0+findRad; y<y0+frame->h-findRad; y+=2*findRad) {
				 usleep(10000);
				 if (StopAutoDefine)
					 break;
				 for (x=x0+findRad; x<x0+frame->w-findRad; x+=2*findRad) {
					 if (x > 0) {
						 Found = FindStar(frame, x-findRad, y-findRad, x+findRad, y+findRad, &starX, &starY, &starMax);
						 sprintf_s(buffer, sizeof(buffer), "%d", starMax);
						 CurrentImageWindow::FormPtr->SetCurrentImageStarMaxTextBox(buffer);
						 if ( (Found) && (starMax >= photometrySettings.minPeak) &&
							 (starMax <= photometrySettings.maxPeak)) {
							doPhotometry(&ccd->Image, CURRENTIMAGEWINDOW, starX, starY, starMax, false, &fwhm, &skyFlux,
								&starFlux, &Magnitude, &MagErr);
							if ((starFlux > 0.0) && (fwhm > photometrySettings.minFWHM) &&
								(fwhm < photometrySettings.maxFWHM) && (starX-rad > 0.0) &&
								(starX+rad < x0+frame->w) && (starY-rad > 0.0) &&
								(starY+rad < y0+frame->h)) {
								if (! AddStar())
									continue;
								numStars++;
							}
						 }
					 }
				 }
			 }
			 return;
		 }
private: System::Void ClearListButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 clearListStars();
			 return;
		 }
public:  static void ShowTheDialog() {
			 DefineListDialog::FormPtr->Show();
		 }
private: System::Void FromFileButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 char fileName[160], Message[240], buffer[160];
			 int i, nItems, idNum, nStars, nobs;
			 double ra, dec, v, verr, bv, bverr, ub, uberr, vr, vrerr, ri, rierr, x, y, ra_err, dec_err;
			 bool LongFormat;
			 FILE *fptr;
			 STAR *sptr;

			 if (ccd->Image.plateSolution.status != 0) {
				 Form1::StatusPrint("*** Warning - can't define star list from file without plate solution\n");
				 return;
			 }

			 this->OpenFileDialog->InitialDirectory = "C:\\Users\\shoup.31\\Documents\\Observatory\\CCDAuto\\PhotometricStandards";
			 this->OpenFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			 this->OpenFileDialog->FilterIndex = 1;
			 this->OpenFileDialog->RestoreDirectory = true;
			 this->OpenFileDialog->FileName = "";
			 System::Windows::Forms::DialogResult res = this->OpenFileDialog->ShowDialog();
			 if ( res != System::Windows::Forms::DialogResult::OK)
				return;
			 String^ file = DefineListDialog::FormPtr->OpenFileDialog->FileName;
			 for (i=0; i<file->Length; i++) fileName[i] = (char) file[i];
			 fileName[i] = '\0';

			 fopen_s(&fptr, fileName, "r");
			 if (fptr == NULL) {
				 sprintf_s(Message, sizeof(Message), "*** Warning - Can't open ref. stars data file: %s\n", fileName);
				 Form1::StatusPrint(Message);
				 return;
			 }

			 fgets(buffer, sizeof(buffer), fptr); // Read in column headings
			 LongFormat = (strstr(buffer,"raerr") != 0);
			 nStars = 0;
			 clearListStars();
			 do {
				 if (fgets(buffer, sizeof(buffer), fptr) == NULL)
					 break;
				 if (! LongFormat) {
					 nItems = sscanf_s(buffer, "%d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
						 &idNum, &ra, &dec, &v, &bv, &ub, &vr, &ri, &verr, &bverr, &uberr, &vrerr, &rierr);
					 if (nItems != 13)
						 break;
				 } else {
					 nItems = sscanf_s(buffer, "%d %lf %lf %lf %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
						 &idNum, &ra, &ra_err, &dec, &dec_err, &nobs, &v, &bv, &ub, &vr, &ri, &verr, &bverr, &uberr,
						 &vrerr, &rierr);
					 if (nItems != 16)
						 break;
				 }
				 ra = ra * 24.0/360.0;  // convert to hours
				 Equatorial2Pixel(ra, dec, &x, &y);
				 if ((x < 0.0) || (x > ccd->Image.light_frame.w) ||
					 (y < 0.0) || (y > ccd->Image.light_frame.h))   // skip this star if outside fov
					 continue;
				 sptr = (STAR *) malloc(sizeof(STAR));
				 if (sptr == NULL) {
					 Form1::StatusPrint("*** Warning - Can't allocate memory for star.\n");
					 return;
				 }
				 sptr->ra = (float) ra;  sptr->dec = (float) dec;
				 sptr->x  = (float) x;   sptr->y   = (float) y;
				 sptr->prev = NULL;
				 sptr->next = NULL;
				 if (CurrentStarList == NULL) {
					 CurrentStarList = sptr;
				 } else {
					 CurrentStarList->prev = sptr;
					 sptr->next = CurrentStarList;
					 CurrentStarList = sptr;
				 }
				 nStars++;
			 } while (! feof(fptr));
			 fclose(fptr);
			 sprintf_s(Message, sizeof(Message), "*** Info - Read in %d stars from file: %s\n", nStars, fileName);
			 Form1::StatusPrint(Message);
			 CurrentStarListDefined = true;

		 }
private: System::Void StopAutoButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 StopAutoDefine = true;
		 }
private: System::Void ToFileButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 int i, nStars;
			 char fileName[256], buffer[160];
			 FILE *fptr;
			 STAR *sptr;
			 
			 // Prompt for file name
			 
			 this->SaveFileDialog->InitialDirectory = "";
			 this->SaveFileDialog->Filter = "list files (*.lst)|*.lst|All files (*.*)|*.*";
			 this->SaveFileDialog->FilterIndex = 1;
			 this->SaveFileDialog->RestoreDirectory = false;
			 do {
				 System::Windows::Forms::DialogResult res = this->SaveFileDialog->ShowDialog();
				 if ( res != System::Windows::Forms::DialogResult::OK)
					 return;
				 String^ file = Form1::CCDAutoForm->SaveFileDialog->FileName;
				 for (i=0; i<file->Length; i++) fileName[i] = (char) file[i];
				 fileName[i] = '\0';
				 fopen_s(&fptr, fileName, "r");
				 				 
				 // If file exist ask if user wants to overwrite

				 if (fptr != NULL) {
					 fclose(fptr);
					 if (! OverWriteDialogExists)
						 gcnew OverWriteDialog();
					 sprintf_s(buffer,sizeof(buffer),"File %s exists, overwrite it?",fileName);
					 OverWriteDialog::ShowTheDialog(buffer);
					 switch (OverWriteDialogAnswer) {
						case NO:  // ask for file again
							continue;
							break;
						case CANCEL:  // do nothing & return
							return;
							break;
						case YES: // delete file & write list out
							_unlink(fileName);
						break;
					 }
				 }

				 // Open file for writing and write list out

				 fopen_s(&fptr, fileName, "w");
				 if (fptr == NULL) {
					 sprintf_s(buffer, sizeof(buffer), "Can't open file: %s for writing star list.\n", fileName);
					 MessageBox(buffer, OKAY, true);
					 return;
				 }
				 sprintf_s(buffer, sizeof(buffer), "ID   RA(J2000)  raerr  DEC(J2000) decerr  nobs    V     B-V"
												   "U-B    V-R    R-I    verr   bverr  uberr  vrerr  rierr");
				 fputs(buffer, fptr);
				 
				 sptr = CurrentStarList;
				 nStars = 0;
				 while (sptr != NULL) {
					 sprintf_s(buffer, sizeof(buffer), "%d %lf %lf %lf %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
						 nStars+1, sptr->ra, 0.0, sptr->dec, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
					 nStars++;
					 sptr = sptr->next;
				 }
				 fclose(fptr);
				 sprintf_s(buffer, sizeof(buffer), "*** Info - Wrote %d stars to file: %s\n", nStars, fileName);
				 Form1::StatusPrint(buffer);
			 } while (true);
		 }
private: System::Void CancelButton_Clicked(System::Object^  sender, System::EventArgs^  e) {

			 clearListStars();

			 CurrentStarList = CurrentStarListSave;
			 FormPtr->Hide();
			 return;
		 }
};
}
