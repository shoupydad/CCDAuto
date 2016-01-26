#pragma once

#include "doRoutines.h"

namespace CCDAuto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AutoFocusDialog
	/// </summary>
	public ref class AutoFocusDialog : public System::Windows::Forms::Form
	{
	public:
		static AutoFocusDialog ^FormPtr;
		AutoFocusDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			FormPtr = this;
			AutoFocusDialogExists = true;
			this->FocusImageBitmap = gcnew System::Drawing::Bitmap(MIN_FOCUS_FIELD_SIZE, MIN_FOCUS_FIELD_SIZE);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AutoFocusDialog()
		{
			if (components)
			{
				delete components;
			}
			AutoFocusDialogExists = false;
		}
	public:  System::Drawing::Bitmap^ FocusImageBitmap;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: Mitov::PlotLab::Scope^  VCurveScope;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;





	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::PictureBox^  CalFocusFramePictureBox;
	private: Mitov::PlotLab::Scope^  CalStarProfileScope;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  XTextBox;
	private: System::Windows::Forms::TextBox^  YTextBox;
	private: System::Windows::Forms::TextBox^  MaxTextBox;
	private: System::Windows::Forms::TextBox^  HFDTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  NumPointsTextBox;
	private: System::Windows::Forms::TextBox^  LeftSlopeTextBox;
	private: System::Windows::Forms::TextBox^  RightSlopeTextBox;
	private: System::Windows::Forms::TextBox^  VertexTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: Mitov::PlotLab::Scope^  StarProfileScope;


	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::PictureBox^  FocusFramePictureBox;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::Button^  StopButton;

	private: System::Windows::Forms::Button^  PauseButton;


	private: System::Windows::Forms::Button^  StartButton;



	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Label^  label16;

private: System::Windows::Forms::TextBox^  CalFocuserPositionTextBox;

private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::TextBox^  StarXTextBox;
private: System::Windows::Forms::TextBox^  StarYTextBox;
private: System::Windows::Forms::TextBox^  StarMaxTextBox;
private: System::Windows::Forms::TextBox^  StarHFDTextBox;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::TextBox^  FocuserPositionTextBox;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::TextBox^  FrameNumTextBox;
private: System::Windows::Forms::TextBox^  CalFrameNumTextBox;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::NumericUpDown^  CalFramesPerPointNumericUpDown;
private: System::Windows::Forms::NumericUpDown^  CalFieldSizeNumericUpDown;
private: System::Windows::Forms::NumericUpDown^  MaxStarPeakNumericUpDown;
private: System::Windows::Forms::NumericUpDown^  MinStarPeakNumericUpDown;


private: System::Windows::Forms::NumericUpDown^  CalEndFocusPositionNumericUpDown;

private: System::Windows::Forms::NumericUpDown^  CalStartFocusPositionNumericUpDown;
private: System::Windows::Forms::NumericUpDown^  CalStepSizeNumericUpDown;
private: System::Windows::Forms::NumericUpDown^  FramesPerPointNumericUpDown;












	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			Mitov::PlotLab::ScopeDataView^  scopeDataView1 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground1 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings1 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen1 = (gcnew Vcl::VclPen());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AutoFocusDialog::typeid));
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting1 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting1 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting2 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting1 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting2 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting3 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting4 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting5 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint1 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel1 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting6 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList1 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView1 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground2 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings1 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup1 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel1 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup2 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel2 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup3 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel3 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup4 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel4 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup5 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel5 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup6 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel6 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup7 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel7 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize1 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup8 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel8 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle1 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground3 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize2 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar1 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons1 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton1 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage1 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton2 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage2 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton3 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage3 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton4 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage4 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton5 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage5 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton6 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage6 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton7 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage7 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize1 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton8 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage8 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton9 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage9 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton10 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage10 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton11 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage11 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton12 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage12 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton13 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage13 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton14 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage14 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition1 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails1 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis1 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel1 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground4 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings1 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings1 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings1 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings2 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen2 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings3 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen3 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat1 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks1 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart1 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue1 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange1 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue1 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue2 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue1 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample1 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue1 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange2 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue3 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue4 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue2 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks1 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar1 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons1 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize2 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton15 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage15 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton16 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage16 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton17 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage17 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton18 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage18 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale1 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize3 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom1 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange3 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue5 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue6 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin1 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList2 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis1 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling1 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace1 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace2 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel2 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground5 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings2 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings2 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings2 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings4 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen4 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings5 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen5 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat2 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks2 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart2 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue2 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange4 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue7 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue8 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue3 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue2 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange5 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue9 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue10 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue4 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks2 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar2 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons2 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize3 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton19 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage19 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton20 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage20 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton21 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage21 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton22 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage22 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize4 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom2 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange6 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue11 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue12 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin2 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom1 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView2 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground6 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings6 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen6 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting2 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting3 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting4 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting7 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting8 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting9 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting10 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting11 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint2 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel2 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting12 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList3 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView2 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground7 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings2 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup9 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel9 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup10 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel10 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup11 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel11 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup12 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel12 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup13 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel13 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup14 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel14 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup15 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel15 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize5 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup16 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel16 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle2 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground8 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize6 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar2 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons2 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton23 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage23 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton24 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage24 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton25 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage25 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton26 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage26 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton27 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage27 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton28 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage28 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton29 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage29 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize4 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton30 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage30 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton31 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage31 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton32 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage32 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton33 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage33 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton34 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage34 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton35 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage35 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton36 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage36 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition2 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails2 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis2 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel3 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground9 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings3 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings3 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings3 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings7 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen7 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings8 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen8 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat3 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks3 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart3 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue3 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange7 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue13 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue14 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue5 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample2 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue3 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange8 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue15 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue16 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue6 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks3 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar3 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons3 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize5 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton37 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage37 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton38 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage38 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton39 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage39 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton40 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage40 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale2 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize7 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom3 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange9 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue17 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue18 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin3 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList4 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis2 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling2 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace3 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace4 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel4 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground10 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings4 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings4 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings4 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings9 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen9 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings10 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen10 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat4 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks4 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart4 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue4 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange10 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue19 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue20 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue7 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue4 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange11 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue21 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue22 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue8 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks4 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar4 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons4 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize6 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton41 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage41 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton42 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage42 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton43 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage43 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton44 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage44 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize8 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom4 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange12 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue23 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue24 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin4 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom2 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView3 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground11 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings11 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen11 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting3 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting5 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting6 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting13 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting14 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting15 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting16 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting17 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint3 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel3 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting18 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList5 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView3 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground12 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings3 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup17 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel17 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup18 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel18 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup19 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel19 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup20 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel20 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup21 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel21 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup22 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel22 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup23 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel23 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize9 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup24 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel24 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle3 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground13 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize10 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar3 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons3 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton45 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage45 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton46 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage46 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton47 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage47 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton48 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage48 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton49 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage49 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton50 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage50 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton51 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage51 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize7 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton52 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage52 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton53 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage53 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton54 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage54 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton55 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage55 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton56 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage56 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton57 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage57 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton58 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage58 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition3 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails3 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis3 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel5 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground14 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings5 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings5 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings5 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings12 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen12 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings13 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen13 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat5 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks5 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart5 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue5 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange13 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue25 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue26 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue9 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample3 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue5 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange14 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue27 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue28 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue10 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks5 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar5 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons5 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize8 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton59 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage59 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton60 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage60 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton61 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage61 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton62 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage62 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale3 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize11 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom5 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange15 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue29 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue30 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin5 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList6 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis3 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling3 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace5 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace6 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel6 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground15 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings6 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings6 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings6 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings14 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen14 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings15 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen15 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat6 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks6 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart6 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue6 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange16 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue31 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue32 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue11 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue6 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange17 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue33 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue34 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue12 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks6 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar6 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons6 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize9 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton63 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage63 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton64 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage64 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton65 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage65 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton66 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage66 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize12 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom6 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange18 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue35 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue36 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin6 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom3 = (gcnew Mitov::PlotLab::DisplayZoom());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StarProfileScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->FocusFramePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->FramesPerPointNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->StarXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarHFDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->FocuserPositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->FrameNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->VCurveScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalFrameNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->CalFocuserPositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->XTextBox = (gcnew System::Windows::Forms::TextBox());
			this->YTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HFDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->NumPointsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LeftSlopeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RightSlopeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VertexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalStarProfileScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->CalFocusFramePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalEndFocusPositionNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->CalStartFocusPositionNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->MinStarPeakNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CalFramesPerPointNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->CalFieldSizeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->MaxStarPeakNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->CalStepSizeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StopButton = (gcnew System::Windows::Forms::Button());
			this->PauseButton = (gcnew System::Windows::Forms::Button());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StarProfileScope))->BeginInit();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FocusFramePictureBox))->BeginInit();
			this->groupBox7->SuspendLayout();
			this->tableLayoutPanel12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FramesPerPointNumericUpDown))->BeginInit();
			this->groupBox8->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCurveScope))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStarProfileScope))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFocusFramePictureBox))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalEndFocusPositionNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStartFocusPositionNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MinStarPeakNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFramesPerPointNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFieldSizeNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxStarPeakNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStepSizeNumericUpDown))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tabControl, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 93.50453F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 6.495468F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(633, 662);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPage1);
			this->tabControl->Controls->Add(this->tabPage2);
			this->tabControl->Controls->Add(this->tabPage3);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(3, 3);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(627, 613);
			this->tabControl->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(619, 587);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Auto Focus";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tableLayoutPanel9);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox5->Location = System::Drawing::Point(3, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(613, 468);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Auto Focus";
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 1;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel9->Controls->Add(this->tableLayoutPanel10, 0, 1);
			this->tableLayoutPanel9->Controls->Add(this->groupBox7, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->groupBox8, 0, 2);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 4;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 23.16258F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.10245F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.71715F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.463252F)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(607, 449);
			this->tableLayoutPanel9->TabIndex = 0;
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 2;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel10->Controls->Add(this->StarProfileScope, 1, 0);
			this->tableLayoutPanel10->Controls->Add(this->groupBox6, 0, 0);
			this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel10->Location = System::Drawing::Point(3, 106);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 1;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(601, 200);
			this->tableLayoutPanel10->TabIndex = 0;
			// 
			// StarProfileScope
			// 
			this->StarProfileScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView1->Background = displayViewBackground1;
			vclPen1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen1.InternalData")));
			displayGridLineSettings1->Pen = vclPen1;
			scopeDataView1->Border = displayGridLineSettings1;
			this->StarProfileScope->DataView = scopeDataView1;
			channelItemHighlighting1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->ChannelLinks = channelItemHighlighting1;
			channelItemHighlighting2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->Channels = channelItemHighlighting2;
			displayItemHighlighting1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->CursorLinks = displayItemHighlighting1;
			displayItemHighlighting2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->Cursors = displayItemHighlighting2;
			displayItemHighlighting3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->Ellipses = displayItemHighlighting3;
			displayItemHighlighting4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->Labels = displayItemHighlighting4;
			displayItemHighlighting5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->Markers = displayItemHighlighting5;
			channelMouseHitPoint1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint1->PointLabel = optionalLabel1;
			dataChartHighlighting1->MouseHitPoint = channelMouseHitPoint1;
			displayItemHighlighting6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting1->Zones = displayItemHighlighting6;
			this->StarProfileScope->Highlighting = dataChartHighlighting1;
			this->StarProfileScope->InputPins = pinList1;
			this->StarProfileScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"StarProfileScope.InternalData")));
			displayViewBackground2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView1->Background = displayViewBackground2;
			legendViewButtonSettings1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings1->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings1->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView1->Buttons = legendViewButtonSettings1;
			displayLabel1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup1->Caption = displayLabel1;
			legendGroup1->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->ChannelLinks = legendGroup1;
			displayLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup2->Caption = displayLabel2;
			legendGroup2->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->Channels = legendGroup2;
			displayLabel3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup3->Caption = displayLabel3;
			legendGroup3->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->CursorLinks = legendGroup3;
			displayLabel4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup4->Caption = displayLabel4;
			legendGroup4->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->Cursors = legendGroup4;
			displayLabel5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup5->Caption = displayLabel5;
			legendGroup5->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->Ellipses = legendGroup5;
			scopeLegendView1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView1.InternalData")));
			displayLabel6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup6->Caption = displayLabel6;
			legendGroup6->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->Labels = legendGroup6;
			displayLabel7->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup7->Caption = displayLabel7;
			legendGroup7->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->MarkerGroups = legendGroup7;
			displayViewSize1->Size = static_cast<System::UInt32>(100);
			scopeLegendView1->ViewSize = displayViewSize1;
			displayLabel8->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup8->Caption = displayLabel8;
			legendGroup8->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView1->Zones = legendGroup8;
			this->StarProfileScope->Legend = scopeLegendView1;
			this->StarProfileScope->Location = System::Drawing::Point(303, 3);
			this->StarProfileScope->Name = L"StarProfileScope";
			this->StarProfileScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->StarProfileScope->Size = System::Drawing::Size(295, 194);
			this->StarProfileScope->SizeLimit = static_cast<System::UInt32>(0);
			this->StarProfileScope->TabIndex = 0;
			this->StarProfileScope->Text = L"scope2";
			displayViewBackground3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle1->Background = displayViewBackground3;
			displayTitle1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 16, 1));
			displayTitle1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle1.InternalData")));
			displayTitle1->Text = L"Star Profile";
			displayViewSize2->Size = static_cast<System::UInt32>(100);
			displayTitle1->ViewSize = displayViewSize2;
			this->StarProfileScope->Title = displayTitle1;
			displayToolBar1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton1->Image = displayToolBarButtonImage1;
			displayToolBarButtons1->Copy = displayToolBarButton1;
			displayToolBarButton2->Image = displayToolBarButtonImage2;
			displayToolBarButtons1->Hold = displayToolBarButton2;
			displayToolBarButton3->Image = displayToolBarButtonImage3;
			displayToolBarButtons1->PanMode = displayToolBarButton3;
			displayToolBarButton4->Image = displayToolBarButtonImage4;
			displayToolBarButtons1->Print = displayToolBarButton4;
			displayToolBarButton5->Image = displayToolBarButtonImage5;
			displayToolBarButtons1->Run = displayToolBarButton5;
			displayToolBarButton6->Image = displayToolBarButtonImage6;
			displayToolBarButtons1->Save = displayToolBarButton6;
			displayToolBarButton7->Image = displayToolBarButtonImage7;
			displayToolBarButtons1->Setup = displayToolBarButton7;
			displayToolBarButtons1->Size = toolBarButtonSize1;
			displayToolBarButton8->Image = displayToolBarButtonImage8;
			displayToolBarButtons1->XYZoomOn = displayToolBarButton8;
			displayToolBarButton9->Image = displayToolBarButtonImage9;
			displayToolBarButtons1->ZoomIn = displayToolBarButton9;
			displayToolBarButton10->Image = displayToolBarButtonImage10;
			displayToolBarButtons1->ZoomMode = displayToolBarButton10;
			displayToolBarButton11->Image = displayToolBarButtonImage11;
			displayToolBarButtons1->ZoomNext = displayToolBarButton11;
			displayToolBarButton12->Image = displayToolBarButtonImage12;
			displayToolBarButtons1->ZoomOff = displayToolBarButton12;
			displayToolBarButton13->Image = displayToolBarButtonImage13;
			displayToolBarButtons1->ZoomOut = displayToolBarButton13;
			displayToolBarButton14->Image = displayToolBarButtonImage14;
			displayToolBarButtons1->ZoomPrevious = displayToolBarButton14;
			displayToolBar1->Buttons = displayToolBarButtons1;
			displayToolBar1->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar1->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar1->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition1.InternalData")));
			displayToolBar1->Position = toolBarPosition1;
			this->StarProfileScope->ToolBar = displayToolBar1;
			displayTrails1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->StarProfileScope->Trails = displayTrails1;
			displayTitleLabel1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel1->Text = L"Cross Section (pixels)";
			scopeXAxis1->AxisLabel = displayTitleLabel1;
			displayViewBackground4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->Background = displayViewBackground4;
			viewButtonSettings1->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings1->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings1->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->Button = viewButtonSettings1;
			scopeXAxis1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis1->CursorSettings = displayAxisCursorSettings1;
			vclPen2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen2.InternalData")));
			displayGridLineSettings2->Pen = vclPen2;
			displayGridDirectionalLinesSettings1->Lines = displayGridLineSettings2;
			vclPen3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen3.InternalData")));
			displayGridLineSettings3->Pen = vclPen3;
			displayGridDirectionalLinesSettings1->ZeroLine = displayGridLineSettings3;
			scopeXAxis1->DataView = displayGridDirectionalLinesSettings1;
			scopeXAxis1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat1->Precision = 3;
			scopeXAxis1->Format = axisFormat1;
			scopeXAxis1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis1.InternalData")));
			ticksStart1->StartFrom = 0;
			majorTicks1->StartFrom = ticksStart1;
			majorTicks1->Step = 10;
			scopeXAxis1->MajorTicks = majorTicks1;
			maxAxisValue1->DataValue = 1024;
			displayOptionalValue1->Enabled = false;
			displayOptionalValue1->Value = 1000;
			displayValueRange1->High = displayOptionalValue1;
			displayOptionalValue2->Enabled = false;
			displayOptionalValue2->Value = -1000;
			displayValueRange1->Low = displayOptionalValue2;
			maxAxisValue1->Range = displayValueRange1;
			basicAxisValue1->Value = 1024;
			maxAxisValue1->Tick = basicAxisValue1;
			maxAxisValue1->Value = 1024;
			scopeXAxis1->Max = maxAxisValue1;
			scopeMaxSample1->Value = static_cast<System::UInt32>(1024);
			scopeXAxis1->MaxSample = scopeMaxSample1;
			axisValue1->DataValue = 0;
			displayOptionalValue3->Enabled = false;
			displayOptionalValue3->Value = 1000;
			displayValueRange2->High = displayOptionalValue3;
			displayOptionalValue4->Enabled = false;
			displayOptionalValue4->Value = -1000;
			displayValueRange2->Low = displayOptionalValue4;
			axisValue1->Range = displayValueRange2;
			basicAxisValue2->Value = 0;
			axisValue1->Tick = basicAxisValue2;
			axisValue1->Value = 0;
			scopeXAxis1->Min = axisValue1;
			scopeXAxis1->MinorTicks = minorTicks1;
			axisToolBar1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons1->Size = toolBarButtonSize2;
			displayToolBarButton15->Image = displayToolBarButtonImage15;
			axisToolBarButtons1->ZoomIn = displayToolBarButton15;
			displayToolBarButton16->Image = displayToolBarButtonImage16;
			axisToolBarButtons1->ZoomOff = displayToolBarButton16;
			displayToolBarButton17->Image = displayToolBarButtonImage17;
			axisToolBarButtons1->ZoomOneDir = displayToolBarButton17;
			displayToolBarButton18->Image = displayToolBarButtonImage18;
			axisToolBarButtons1->ZoomOut = displayToolBarButton18;
			axisToolBar1->Buttons = axisToolBarButtons1;
			axisToolBar1->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar1->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar1->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->ToolBar = axisToolBar1;
			scopeXAxis1->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis1->UnitScale = scopeXAxisUnitScale1;
			displayViewSize3->Size = static_cast<System::UInt32>(100);
			scopeXAxis1->ViewSize = displayViewSize3;
			displayOptionalValue5->Enabled = false;
			displayOptionalValue5->Value = 100000000;
			displayValueRange3->High = displayOptionalValue5;
			displayOptionalValue6->Enabled = true;
			displayOptionalValue6->Value = 1E-07;
			displayValueRange3->Low = displayOptionalValue6;
			displayAxisZoom1->Range = displayValueRange3;
			scopeXAxis1->Zooming = displayAxisZoom1;
			scopeXAxis1->ZoomPin = statePin1;
			this->StarProfileScope->XAxis = scopeXAxis1;
			this->StarProfileScope->XInputPins = pinList2;
			scopeAutoScaling1->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace1->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace1->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling1->SpaceAbove = scopeAutoScalingSpace1;
			scopeAutoScalingSpace2->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace2->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling1->SpaceBelow = scopeAutoScalingSpace2;
			scopeYAxis1->AutoScaling = scopeAutoScaling1;
			displayTitleLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel2->Text = L"Pixel Value (ADU)";
			scopeYAxis1->AxisLabel = displayTitleLabel2;
			displayViewBackground5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis1->Background = displayViewBackground5;
			viewButtonSettings2->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings2->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings2->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis1->Button = viewButtonSettings2;
			scopeYAxis1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis1->CursorSettings = displayAxisCursorSettings2;
			vclPen4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen4.InternalData")));
			displayGridLineSettings4->Pen = vclPen4;
			displayGridDirectionalLinesSettings2->Lines = displayGridLineSettings4;
			vclPen5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen5.InternalData")));
			displayGridLineSettings5->Pen = vclPen5;
			displayGridDirectionalLinesSettings2->ZeroLine = displayGridLineSettings5;
			scopeYAxis1->DataView = displayGridDirectionalLinesSettings2;
			scopeYAxis1->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat2->Precision = 3;
			scopeYAxis1->Format = axisFormat2;
			scopeYAxis1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis1.InternalData")));
			ticksStart2->StartFrom = 0;
			majorTicks2->StartFrom = ticksStart2;
			majorTicks2->Step = 10;
			scopeYAxis1->MajorTicks = majorTicks2;
			maxAxisValue2->DataValue = 1000;
			displayOptionalValue7->Enabled = false;
			displayOptionalValue7->Value = 1000;
			displayValueRange4->High = displayOptionalValue7;
			displayOptionalValue8->Enabled = false;
			displayOptionalValue8->Value = -1000;
			displayValueRange4->Low = displayOptionalValue8;
			maxAxisValue2->Range = displayValueRange4;
			basicAxisValue3->Value = 0;
			maxAxisValue2->Tick = basicAxisValue3;
			maxAxisValue2->Value = 1000;
			scopeYAxis1->Max = maxAxisValue2;
			axisValue2->DataValue = -1000;
			displayOptionalValue9->Enabled = false;
			displayOptionalValue9->Value = 1000;
			displayValueRange5->High = displayOptionalValue9;
			displayOptionalValue10->Enabled = false;
			displayOptionalValue10->Value = -1000;
			displayValueRange5->Low = displayOptionalValue10;
			axisValue2->Range = displayValueRange5;
			basicAxisValue4->Value = 0;
			axisValue2->Tick = basicAxisValue4;
			axisValue2->Value = -1000;
			scopeYAxis1->Min = axisValue2;
			scopeYAxis1->MinorTicks = minorTicks2;
			axisToolBar2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons2->Size = toolBarButtonSize3;
			displayToolBarButton19->Image = displayToolBarButtonImage19;
			axisToolBarButtons2->ZoomIn = displayToolBarButton19;
			displayToolBarButton20->Image = displayToolBarButtonImage20;
			axisToolBarButtons2->ZoomOff = displayToolBarButton20;
			displayToolBarButton21->Image = displayToolBarButtonImage21;
			axisToolBarButtons2->ZoomOneDir = displayToolBarButton21;
			displayToolBarButton22->Image = displayToolBarButtonImage22;
			axisToolBarButtons2->ZoomOut = displayToolBarButton22;
			axisToolBar2->Buttons = axisToolBarButtons2;
			axisToolBar2->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar2->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis1->ToolBar = axisToolBar2;
			scopeYAxis1->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize4->Size = static_cast<System::UInt32>(100);
			scopeYAxis1->ViewSize = displayViewSize4;
			displayOptionalValue11->Enabled = false;
			displayOptionalValue11->Value = 100000000;
			displayValueRange6->High = displayOptionalValue11;
			displayOptionalValue12->Enabled = true;
			displayOptionalValue12->Value = 1E-07;
			displayValueRange6->Low = displayOptionalValue12;
			displayAxisZoom2->Range = displayValueRange6;
			scopeYAxis1->Zooming = displayAxisZoom2;
			scopeYAxis1->ZoomPin = statePin2;
			this->StarProfileScope->YAxis = scopeYAxis1;
			displayZoom1->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->StarProfileScope->Zooming = displayZoom1;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->FocusFramePictureBox);
			this->groupBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox6->Location = System::Drawing::Point(3, 3);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(294, 194);
			this->groupBox6->TabIndex = 1;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Current Focus Frame";
			// 
			// FocusFramePictureBox
			// 
			this->FocusFramePictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FocusFramePictureBox->Location = System::Drawing::Point(3, 16);
			this->FocusFramePictureBox->Name = L"FocusFramePictureBox";
			this->FocusFramePictureBox->Size = System::Drawing::Size(288, 175);
			this->FocusFramePictureBox->TabIndex = 1;
			this->FocusFramePictureBox->TabStop = false;
			// 
			// groupBox7
			// 
			this->groupBox7->BackColor = System::Drawing::Color::Plum;
			this->groupBox7->Controls->Add(this->tableLayoutPanel12);
			this->groupBox7->Location = System::Drawing::Point(3, 3);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(317, 97);
			this->groupBox7->TabIndex = 1;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Auto Focus Parameters";
			// 
			// tableLayoutPanel12
			// 
			this->tableLayoutPanel12->ColumnCount = 3;
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.27322F)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.72678F)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel12->Controls->Add(this->radioButton1, 2, 0);
			this->tableLayoutPanel12->Controls->Add(this->radioButton2, 2, 1);
			this->tableLayoutPanel12->Controls->Add(this->radioButton3, 2, 2);
			this->tableLayoutPanel12->Controls->Add(this->label16, 0, 0);
			this->tableLayoutPanel12->Controls->Add(this->FramesPerPointNumericUpDown, 1, 0);
			this->tableLayoutPanel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel12->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
			this->tableLayoutPanel12->RowCount = 3;
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				27)));
			this->tableLayoutPanel12->Size = System::Drawing::Size(311, 78);
			this->tableLayoutPanel12->TabIndex = 0;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(178, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(98, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"On VCurve Left";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(178, 28);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(105, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"On VCurve Right";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(178, 53);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(71, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Unknown";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(12, 6);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(73, 13);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Frames/Point:";
			// 
			// FramesPerPointNumericUpDown
			// 
			this->FramesPerPointNumericUpDown->Location = System::Drawing::Point(91, 3);
			this->FramesPerPointNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->FramesPerPointNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FramesPerPointNumericUpDown->Name = L"FramesPerPointNumericUpDown";
			this->FramesPerPointNumericUpDown->Size = System::Drawing::Size(45, 20);
			this->FramesPerPointNumericUpDown->TabIndex = 4;
			this->FramesPerPointNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// groupBox8
			// 
			this->groupBox8->BackColor = System::Drawing::Color::SkyBlue;
			this->groupBox8->Controls->Add(this->tableLayoutPanel13);
			this->groupBox8->Location = System::Drawing::Point(3, 312);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(408, 95);
			this->groupBox8->TabIndex = 2;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Auto Focus Results";
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->ColumnCount = 6;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				65)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				54)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				82)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				91)));
			this->tableLayoutPanel13->Controls->Add(this->label20, 0, 1);
			this->tableLayoutPanel13->Controls->Add(this->label18, 0, 0);
			this->tableLayoutPanel13->Controls->Add(this->label19, 2, 0);
			this->tableLayoutPanel13->Controls->Add(this->label21, 2, 1);
			this->tableLayoutPanel13->Controls->Add(this->StarXTextBox, 1, 0);
			this->tableLayoutPanel13->Controls->Add(this->StarYTextBox, 1, 1);
			this->tableLayoutPanel13->Controls->Add(this->StarMaxTextBox, 3, 0);
			this->tableLayoutPanel13->Controls->Add(this->StarHFDTextBox, 3, 1);
			this->tableLayoutPanel13->Controls->Add(this->label22, 4, 0);
			this->tableLayoutPanel13->Controls->Add(this->FocuserPositionTextBox, 5, 0);
			this->tableLayoutPanel13->Controls->Add(this->label23, 4, 1);
			this->tableLayoutPanel13->Controls->Add(this->FrameNumTextBox, 5, 1);
			this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel13->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 2;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel13->Size = System::Drawing::Size(402, 76);
			this->tableLayoutPanel13->TabIndex = 0;
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(13, 50);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(39, 13);
			this->label20->TabIndex = 6;
			this->label20->Text = L"Star X:";
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(13, 12);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(39, 13);
			this->label18->TabIndex = 4;
			this->label18->Text = L"Star X:";
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(120, 12);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(52, 13);
			this->label19->TabIndex = 5;
			this->label19->Text = L"Star Max:";
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(118, 50);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(54, 13);
			this->label21->TabIndex = 7;
			this->label21->Text = L"Star HFD:";
			// 
			// StarXTextBox
			// 
			this->StarXTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarXTextBox->Location = System::Drawing::Point(58, 9);
			this->StarXTextBox->Name = L"StarXTextBox";
			this->StarXTextBox->ReadOnly = true;
			this->StarXTextBox->Size = System::Drawing::Size(38, 20);
			this->StarXTextBox->TabIndex = 8;
			// 
			// StarYTextBox
			// 
			this->StarYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarYTextBox->Location = System::Drawing::Point(58, 47);
			this->StarYTextBox->Name = L"StarYTextBox";
			this->StarYTextBox->ReadOnly = true;
			this->StarYTextBox->Size = System::Drawing::Size(38, 20);
			this->StarYTextBox->TabIndex = 9;
			// 
			// StarMaxTextBox
			// 
			this->StarMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarMaxTextBox->Location = System::Drawing::Point(178, 9);
			this->StarMaxTextBox->Name = L"StarMaxTextBox";
			this->StarMaxTextBox->ReadOnly = true;
			this->StarMaxTextBox->Size = System::Drawing::Size(38, 20);
			this->StarMaxTextBox->TabIndex = 10;
			// 
			// StarHFDTextBox
			// 
			this->StarHFDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarHFDTextBox->Location = System::Drawing::Point(178, 47);
			this->StarHFDTextBox->Name = L"StarHFDTextBox";
			this->StarHFDTextBox->ReadOnly = true;
			this->StarHFDTextBox->Size = System::Drawing::Size(38, 20);
			this->StarHFDTextBox->TabIndex = 11;
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(239, 12);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(69, 13);
			this->label22->TabIndex = 12;
			this->label22->Text = L"Focuser Pos:";
			// 
			// FocuserPositionTextBox
			// 
			this->FocuserPositionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FocuserPositionTextBox->Location = System::Drawing::Point(314, 9);
			this->FocuserPositionTextBox->Name = L"FocuserPositionTextBox";
			this->FocuserPositionTextBox->ReadOnly = true;
			this->FocuserPositionTextBox->Size = System::Drawing::Size(38, 20);
			this->FocuserPositionTextBox->TabIndex = 13;
			// 
			// label23
			// 
			this->label23->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(259, 50);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(49, 13);
			this->label23->TabIndex = 14;
			this->label23->Text = L"Frame #:";
			// 
			// FrameNumTextBox
			// 
			this->FrameNumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->FrameNumTextBox->Location = System::Drawing::Point(314, 47);
			this->FrameNumTextBox->Name = L"FrameNumTextBox";
			this->FrameNumTextBox->ReadOnly = true;
			this->FrameNumTextBox->Size = System::Drawing::Size(38, 20);
			this->FrameNumTextBox->TabIndex = 15;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tableLayoutPanel3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(619, 587);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Calibrate";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.15771F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 82.84229F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(613, 581);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->VCurveScope, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox2, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->groupBox3, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel6, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 102);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.59036F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.40964F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(607, 476);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// VCurveScope
			// 
			this->VCurveScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView2->Background = displayViewBackground6;
			vclPen6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen6.InternalData")));
			displayGridLineSettings6->Pen = vclPen6;
			scopeDataView2->Border = displayGridLineSettings6;
			this->VCurveScope->DataView = scopeDataView2;
			this->VCurveScope->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->ChannelLinks = channelItemHighlighting3;
			channelItemHighlighting4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->Channels = channelItemHighlighting4;
			displayItemHighlighting7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->CursorLinks = displayItemHighlighting7;
			displayItemHighlighting8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->Cursors = displayItemHighlighting8;
			displayItemHighlighting9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->Ellipses = displayItemHighlighting9;
			displayItemHighlighting10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->Labels = displayItemHighlighting10;
			displayItemHighlighting11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->Markers = displayItemHighlighting11;
			channelMouseHitPoint2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint2->PointLabel = optionalLabel2;
			dataChartHighlighting2->MouseHitPoint = channelMouseHitPoint2;
			displayItemHighlighting12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting2->Zones = displayItemHighlighting12;
			this->VCurveScope->Highlighting = dataChartHighlighting2;
			this->VCurveScope->InputPins = pinList3;
			this->VCurveScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"VCurveScope.InternalData")));
			displayViewBackground7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView2->Background = displayViewBackground7;
			legendViewButtonSettings2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView2->Buttons = legendViewButtonSettings2;
			displayLabel9->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup9->Caption = displayLabel9;
			legendGroup9->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->ChannelLinks = legendGroup9;
			displayLabel10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup10->Caption = displayLabel10;
			legendGroup10->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Channels = legendGroup10;
			displayLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup11->Caption = displayLabel11;
			legendGroup11->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->CursorLinks = legendGroup11;
			displayLabel12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup12->Caption = displayLabel12;
			legendGroup12->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Cursors = legendGroup12;
			displayLabel13->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup13->Caption = displayLabel13;
			legendGroup13->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Ellipses = legendGroup13;
			scopeLegendView2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView2.InternalData")));
			displayLabel14->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup14->Caption = displayLabel14;
			legendGroup14->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Labels = legendGroup14;
			displayLabel15->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup15->Caption = displayLabel15;
			legendGroup15->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->MarkerGroups = legendGroup15;
			displayViewSize5->Size = static_cast<System::UInt32>(100);
			scopeLegendView2->ViewSize = displayViewSize5;
			displayLabel16->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup16->Caption = displayLabel16;
			legendGroup16->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Zones = legendGroup16;
			this->VCurveScope->Legend = scopeLegendView2;
			this->VCurveScope->Location = System::Drawing::Point(306, 3);
			this->VCurveScope->Name = L"VCurveScope";
			this->VCurveScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->VCurveScope->Size = System::Drawing::Size(298, 363);
			this->VCurveScope->SizeLimit = static_cast<System::UInt32>(0);
			this->VCurveScope->TabIndex = 0;
			this->VCurveScope->Text = L"V Curve";
			displayViewBackground8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle2->Background = displayViewBackground8;
			displayTitle2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 13, 1));
			displayTitle2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle2.InternalData")));
			displayTitle2->Text = L"V Curve";
			displayViewSize6->Size = static_cast<System::UInt32>(100);
			displayTitle2->ViewSize = displayViewSize6;
			this->VCurveScope->Title = displayTitle2;
			displayToolBar2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton23->Image = displayToolBarButtonImage23;
			displayToolBarButtons2->Copy = displayToolBarButton23;
			displayToolBarButton24->Image = displayToolBarButtonImage24;
			displayToolBarButtons2->Hold = displayToolBarButton24;
			displayToolBarButton25->Image = displayToolBarButtonImage25;
			displayToolBarButtons2->PanMode = displayToolBarButton25;
			displayToolBarButton26->Image = displayToolBarButtonImage26;
			displayToolBarButtons2->Print = displayToolBarButton26;
			displayToolBarButton27->Image = displayToolBarButtonImage27;
			displayToolBarButtons2->Run = displayToolBarButton27;
			displayToolBarButton28->Image = displayToolBarButtonImage28;
			displayToolBarButtons2->Save = displayToolBarButton28;
			displayToolBarButton29->Image = displayToolBarButtonImage29;
			displayToolBarButtons2->Setup = displayToolBarButton29;
			displayToolBarButtons2->Size = toolBarButtonSize4;
			displayToolBarButton30->Image = displayToolBarButtonImage30;
			displayToolBarButtons2->XYZoomOn = displayToolBarButton30;
			displayToolBarButton31->Image = displayToolBarButtonImage31;
			displayToolBarButtons2->ZoomIn = displayToolBarButton31;
			displayToolBarButton32->Image = displayToolBarButtonImage32;
			displayToolBarButtons2->ZoomMode = displayToolBarButton32;
			displayToolBarButton33->Image = displayToolBarButtonImage33;
			displayToolBarButtons2->ZoomNext = displayToolBarButton33;
			displayToolBarButton34->Image = displayToolBarButtonImage34;
			displayToolBarButtons2->ZoomOff = displayToolBarButton34;
			displayToolBarButton35->Image = displayToolBarButtonImage35;
			displayToolBarButtons2->ZoomOut = displayToolBarButton35;
			displayToolBarButton36->Image = displayToolBarButtonImage36;
			displayToolBarButtons2->ZoomPrevious = displayToolBarButton36;
			displayToolBar2->Buttons = displayToolBarButtons2;
			displayToolBar2->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition2.InternalData")));
			displayToolBar2->Position = toolBarPosition2;
			this->VCurveScope->ToolBar = displayToolBar2;
			displayTrails2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->VCurveScope->Trails = displayTrails2;
			displayTitleLabel3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel3->Text = L"Focus Position";
			scopeXAxis2->AxisLabel = displayTitleLabel3;
			displayViewBackground9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->Background = displayViewBackground9;
			viewButtonSettings3->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->Button = viewButtonSettings3;
			scopeXAxis2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis2->CursorSettings = displayAxisCursorSettings3;
			vclPen7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen7->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen7.InternalData")));
			displayGridLineSettings7->Pen = vclPen7;
			displayGridDirectionalLinesSettings3->Lines = displayGridLineSettings7;
			vclPen8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen8->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen8.InternalData")));
			displayGridLineSettings8->Pen = vclPen8;
			displayGridDirectionalLinesSettings3->ZeroLine = displayGridLineSettings8;
			scopeXAxis2->DataView = displayGridDirectionalLinesSettings3;
			scopeXAxis2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat3->Precision = 3;
			scopeXAxis2->Format = axisFormat3;
			scopeXAxis2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis2.InternalData")));
			ticksStart3->StartFrom = 0;
			majorTicks3->StartFrom = ticksStart3;
			majorTicks3->Step = 10;
			scopeXAxis2->MajorTicks = majorTicks3;
			maxAxisValue3->DataValue = 1024;
			displayOptionalValue13->Enabled = false;
			displayOptionalValue13->Value = 1000;
			displayValueRange7->High = displayOptionalValue13;
			displayOptionalValue14->Enabled = false;
			displayOptionalValue14->Value = -1000;
			displayValueRange7->Low = displayOptionalValue14;
			maxAxisValue3->Range = displayValueRange7;
			basicAxisValue5->Value = 1024;
			maxAxisValue3->Tick = basicAxisValue5;
			maxAxisValue3->Value = 1024;
			scopeXAxis2->Max = maxAxisValue3;
			scopeMaxSample2->Value = static_cast<System::UInt32>(1024);
			scopeXAxis2->MaxSample = scopeMaxSample2;
			axisValue3->DataValue = 0;
			displayOptionalValue15->Enabled = false;
			displayOptionalValue15->Value = 1000;
			displayValueRange8->High = displayOptionalValue15;
			displayOptionalValue16->Enabled = false;
			displayOptionalValue16->Value = -1000;
			displayValueRange8->Low = displayOptionalValue16;
			axisValue3->Range = displayValueRange8;
			basicAxisValue6->Value = 0;
			axisValue3->Tick = basicAxisValue6;
			axisValue3->Value = 0;
			scopeXAxis2->Min = axisValue3;
			scopeXAxis2->MinorTicks = minorTicks3;
			axisToolBar3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons3->Size = toolBarButtonSize5;
			displayToolBarButton37->Image = displayToolBarButtonImage37;
			axisToolBarButtons3->ZoomIn = displayToolBarButton37;
			displayToolBarButton38->Image = displayToolBarButtonImage38;
			axisToolBarButtons3->ZoomOff = displayToolBarButton38;
			displayToolBarButton39->Image = displayToolBarButtonImage39;
			axisToolBarButtons3->ZoomOneDir = displayToolBarButton39;
			displayToolBarButton40->Image = displayToolBarButtonImage40;
			axisToolBarButtons3->ZoomOut = displayToolBarButton40;
			axisToolBar3->Buttons = axisToolBarButtons3;
			axisToolBar3->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar3->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->ToolBar = axisToolBar3;
			scopeXAxis2->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->UnitScale = scopeXAxisUnitScale2;
			displayViewSize7->Size = static_cast<System::UInt32>(100);
			scopeXAxis2->ViewSize = displayViewSize7;
			displayOptionalValue17->Enabled = false;
			displayOptionalValue17->Value = 100000000;
			displayValueRange9->High = displayOptionalValue17;
			displayOptionalValue18->Enabled = true;
			displayOptionalValue18->Value = 1E-07;
			displayValueRange9->Low = displayOptionalValue18;
			displayAxisZoom3->Range = displayValueRange9;
			scopeXAxis2->Zooming = displayAxisZoom3;
			scopeXAxis2->ZoomPin = statePin3;
			this->VCurveScope->XAxis = scopeXAxis2;
			this->VCurveScope->XInputPins = pinList4;
			scopeAutoScaling2->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace3->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace3->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling2->SpaceAbove = scopeAutoScalingSpace3;
			scopeAutoScalingSpace4->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace4->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling2->SpaceBelow = scopeAutoScalingSpace4;
			scopeYAxis2->AutoScaling = scopeAutoScaling2;
			displayTitleLabel4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel4->Text = L"Half Flux Diameter (Pixels)";
			scopeYAxis2->AxisLabel = displayTitleLabel4;
			displayViewBackground10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->Background = displayViewBackground10;
			viewButtonSettings4->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->Button = viewButtonSettings4;
			scopeYAxis2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis2->CursorSettings = displayAxisCursorSettings4;
			vclPen9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen9->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen9.InternalData")));
			displayGridLineSettings9->Pen = vclPen9;
			displayGridDirectionalLinesSettings4->Lines = displayGridLineSettings9;
			vclPen10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen10.InternalData")));
			displayGridLineSettings10->Pen = vclPen10;
			displayGridDirectionalLinesSettings4->ZeroLine = displayGridLineSettings10;
			scopeYAxis2->DataView = displayGridDirectionalLinesSettings4;
			scopeYAxis2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat4->Precision = 3;
			scopeYAxis2->Format = axisFormat4;
			scopeYAxis2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis2.InternalData")));
			ticksStart4->StartFrom = 0;
			majorTicks4->StartFrom = ticksStart4;
			majorTicks4->Step = 10;
			scopeYAxis2->MajorTicks = majorTicks4;
			maxAxisValue4->DataValue = 1000;
			displayOptionalValue19->Enabled = false;
			displayOptionalValue19->Value = 1000;
			displayValueRange10->High = displayOptionalValue19;
			displayOptionalValue20->Enabled = false;
			displayOptionalValue20->Value = -1000;
			displayValueRange10->Low = displayOptionalValue20;
			maxAxisValue4->Range = displayValueRange10;
			basicAxisValue7->Value = 0;
			maxAxisValue4->Tick = basicAxisValue7;
			maxAxisValue4->Value = 1000;
			scopeYAxis2->Max = maxAxisValue4;
			axisValue4->DataValue = -1000;
			displayOptionalValue21->Enabled = false;
			displayOptionalValue21->Value = 1000;
			displayValueRange11->High = displayOptionalValue21;
			displayOptionalValue22->Enabled = false;
			displayOptionalValue22->Value = -1000;
			displayValueRange11->Low = displayOptionalValue22;
			axisValue4->Range = displayValueRange11;
			basicAxisValue8->Value = 0;
			axisValue4->Tick = basicAxisValue8;
			axisValue4->Value = -1000;
			scopeYAxis2->Min = axisValue4;
			scopeYAxis2->MinorTicks = minorTicks4;
			axisToolBar4->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons4->Size = toolBarButtonSize6;
			displayToolBarButton41->Image = displayToolBarButtonImage41;
			axisToolBarButtons4->ZoomIn = displayToolBarButton41;
			displayToolBarButton42->Image = displayToolBarButtonImage42;
			axisToolBarButtons4->ZoomOff = displayToolBarButton42;
			displayToolBarButton43->Image = displayToolBarButtonImage43;
			axisToolBarButtons4->ZoomOneDir = displayToolBarButton43;
			displayToolBarButton44->Image = displayToolBarButtonImage44;
			axisToolBarButtons4->ZoomOut = displayToolBarButton44;
			axisToolBar4->Buttons = axisToolBarButtons4;
			axisToolBar4->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar4->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->ToolBar = axisToolBar4;
			scopeYAxis2->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize8->Size = static_cast<System::UInt32>(100);
			scopeYAxis2->ViewSize = displayViewSize8;
			displayOptionalValue23->Enabled = false;
			displayOptionalValue23->Value = 100000000;
			displayValueRange12->High = displayOptionalValue23;
			displayOptionalValue24->Enabled = true;
			displayOptionalValue24->Value = 1E-07;
			displayValueRange12->Low = displayOptionalValue24;
			displayAxisZoom4->Range = displayValueRange12;
			scopeYAxis2->Zooming = displayAxisZoom4;
			scopeYAxis2->ZoomPin = statePin4;
			this->VCurveScope->YAxis = scopeYAxis2;
			displayZoom2->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->VCurveScope->Zooming = displayZoom2;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::SkyBlue;
			this->groupBox2->Controls->Add(this->tableLayoutPanel7);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 372);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(297, 101);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Results";
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 4;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				26.46048F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.08591F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				23.02406F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel7->Controls->Add(this->CalFrameNumTextBox, 3, 2);
			this->tableLayoutPanel7->Controls->Add(this->label24, 2, 2);
			this->tableLayoutPanel7->Controls->Add(this->CalFocuserPositionTextBox, 1, 2);
			this->tableLayoutPanel7->Controls->Add(this->label11, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->label9, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->label10, 2, 1);
			this->tableLayoutPanel7->Controls->Add(this->XTextBox, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->YTextBox, 1, 1);
			this->tableLayoutPanel7->Controls->Add(this->MaxTextBox, 3, 0);
			this->tableLayoutPanel7->Controls->Add(this->HFDTextBox, 3, 1);
			this->tableLayoutPanel7->Controls->Add(this->label17, 0, 2);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 3;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50.90909F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 49.09091F)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(291, 82);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// CalFrameNumTextBox
			// 
			this->CalFrameNumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CalFrameNumTextBox->Location = System::Drawing::Point(220, 57);
			this->CalFrameNumTextBox->Name = L"CalFrameNumTextBox";
			this->CalFrameNumTextBox->ReadOnly = true;
			this->CalFrameNumTextBox->Size = System::Drawing::Size(56, 20);
			this->CalFrameNumTextBox->TabIndex = 12;
			// 
			// label24
			// 
			this->label24->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(165, 61);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(49, 13);
			this->label24->TabIndex = 11;
			this->label24->Text = L"Frame #:";
			// 
			// CalFocuserPositionTextBox
			// 
			this->CalFocuserPositionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CalFocuserPositionTextBox->Location = System::Drawing::Point(80, 57);
			this->CalFocuserPositionTextBox->Name = L"CalFocuserPositionTextBox";
			this->CalFocuserPositionTextBox->ReadOnly = true;
			this->CalFocuserPositionTextBox->Size = System::Drawing::Size(56, 20);
			this->CalFocuserPositionTextBox->TabIndex = 10;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(37, 33);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(37, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Star y:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(37, 7);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Star x:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(162, 7);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Star Max:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(163, 33);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(51, 13);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Star HFD";
			// 
			// XTextBox
			// 
			this->XTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->XTextBox->Location = System::Drawing::Point(80, 3);
			this->XTextBox->Name = L"XTextBox";
			this->XTextBox->ReadOnly = true;
			this->XTextBox->Size = System::Drawing::Size(56, 20);
			this->XTextBox->TabIndex = 5;
			// 
			// YTextBox
			// 
			this->YTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->YTextBox->Location = System::Drawing::Point(80, 30);
			this->YTextBox->Name = L"YTextBox";
			this->YTextBox->ReadOnly = true;
			this->YTextBox->Size = System::Drawing::Size(56, 20);
			this->YTextBox->TabIndex = 6;
			// 
			// MaxTextBox
			// 
			this->MaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MaxTextBox->Location = System::Drawing::Point(220, 3);
			this->MaxTextBox->Name = L"MaxTextBox";
			this->MaxTextBox->ReadOnly = true;
			this->MaxTextBox->Size = System::Drawing::Size(56, 20);
			this->MaxTextBox->TabIndex = 7;
			// 
			// HFDTextBox
			// 
			this->HFDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HFDTextBox->Location = System::Drawing::Point(220, 30);
			this->HFDTextBox->Name = L"HFDTextBox";
			this->HFDTextBox->ReadOnly = true;
			this->HFDTextBox->Size = System::Drawing::Size(56, 20);
			this->HFDTextBox->TabIndex = 8;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(5, 61);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(69, 13);
			this->label17->TabIndex = 9;
			this->label17->Text = L"Focuser Pos:";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::Khaki;
			this->groupBox3->Controls->Add(this->tableLayoutPanel8);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(306, 372);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(298, 101);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Results";
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 4;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel8->Controls->Add(this->label12, 0, 1);
			this->tableLayoutPanel8->Controls->Add(this->label13, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->label14, 2, 0);
			this->tableLayoutPanel8->Controls->Add(this->label15, 2, 1);
			this->tableLayoutPanel8->Controls->Add(this->NumPointsTextBox, 1, 0);
			this->tableLayoutPanel8->Controls->Add(this->LeftSlopeTextBox, 1, 1);
			this->tableLayoutPanel8->Controls->Add(this->RightSlopeTextBox, 3, 0);
			this->tableLayoutPanel8->Controls->Add(this->VertexTextBox, 3, 1);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 2;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(292, 82);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 55);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(58, 13);
			this->label12->TabIndex = 4;
			this->label12->Text = L"Left Slope:";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(9, 14);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"# of Points:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(151, 14);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(65, 13);
			this->label14->TabIndex = 2;
			this->label14->Text = L"Right Slope:";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(176, 55);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(40, 13);
			this->label15->TabIndex = 3;
			this->label15->Text = L"Vertex:";
			// 
			// NumPointsTextBox
			// 
			this->NumPointsTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NumPointsTextBox->Location = System::Drawing::Point(76, 10);
			this->NumPointsTextBox->Name = L"NumPointsTextBox";
			this->NumPointsTextBox->ReadOnly = true;
			this->NumPointsTextBox->Size = System::Drawing::Size(56, 20);
			this->NumPointsTextBox->TabIndex = 5;
			// 
			// LeftSlopeTextBox
			// 
			this->LeftSlopeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LeftSlopeTextBox->Location = System::Drawing::Point(76, 51);
			this->LeftSlopeTextBox->Name = L"LeftSlopeTextBox";
			this->LeftSlopeTextBox->ReadOnly = true;
			this->LeftSlopeTextBox->Size = System::Drawing::Size(56, 20);
			this->LeftSlopeTextBox->TabIndex = 6;
			// 
			// RightSlopeTextBox
			// 
			this->RightSlopeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->RightSlopeTextBox->Location = System::Drawing::Point(222, 10);
			this->RightSlopeTextBox->Name = L"RightSlopeTextBox";
			this->RightSlopeTextBox->ReadOnly = true;
			this->RightSlopeTextBox->Size = System::Drawing::Size(56, 20);
			this->RightSlopeTextBox->TabIndex = 7;
			// 
			// VertexTextBox
			// 
			this->VertexTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->VertexTextBox->Location = System::Drawing::Point(222, 51);
			this->VertexTextBox->Name = L"VertexTextBox";
			this->VertexTextBox->ReadOnly = true;
			this->VertexTextBox->Size = System::Drawing::Size(56, 20);
			this->VertexTextBox->TabIndex = 8;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->CalStarProfileScope, 0, 1);
			this->tableLayoutPanel6->Controls->Add(this->groupBox4, 0, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.72222F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.27778F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(297, 363);
			this->tableLayoutPanel6->TabIndex = 4;
			// 
			// CalStarProfileScope
			// 
			this->CalStarProfileScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView3->Background = displayViewBackground11;
			vclPen11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen11.InternalData")));
			displayGridLineSettings11->Pen = vclPen11;
			scopeDataView3->Border = displayGridLineSettings11;
			this->CalStarProfileScope->DataView = scopeDataView3;
			channelItemHighlighting5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->ChannelLinks = channelItemHighlighting5;
			channelItemHighlighting6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->Channels = channelItemHighlighting6;
			displayItemHighlighting13->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->CursorLinks = displayItemHighlighting13;
			displayItemHighlighting14->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->Cursors = displayItemHighlighting14;
			displayItemHighlighting15->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->Ellipses = displayItemHighlighting15;
			displayItemHighlighting16->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->Labels = displayItemHighlighting16;
			displayItemHighlighting17->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->Markers = displayItemHighlighting17;
			channelMouseHitPoint3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint3->PointLabel = optionalLabel3;
			dataChartHighlighting3->MouseHitPoint = channelMouseHitPoint3;
			displayItemHighlighting18->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting3->Zones = displayItemHighlighting18;
			this->CalStarProfileScope->Highlighting = dataChartHighlighting3;
			this->CalStarProfileScope->InputPins = pinList5;
			this->CalStarProfileScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"CalStarProfileScope.InternalData")));
			displayViewBackground12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView3->Background = displayViewBackground12;
			legendViewButtonSettings3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings3->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings3->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView3->Buttons = legendViewButtonSettings3;
			displayLabel17->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup17->Caption = displayLabel17;
			legendGroup17->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->ChannelLinks = legendGroup17;
			displayLabel18->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup18->Caption = displayLabel18;
			legendGroup18->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->Channels = legendGroup18;
			displayLabel19->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup19->Caption = displayLabel19;
			legendGroup19->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->CursorLinks = legendGroup19;
			displayLabel20->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup20->Caption = displayLabel20;
			legendGroup20->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->Cursors = legendGroup20;
			displayLabel21->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup21->Caption = displayLabel21;
			legendGroup21->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->Ellipses = legendGroup21;
			scopeLegendView3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView3.InternalData")));
			displayLabel22->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup22->Caption = displayLabel22;
			legendGroup22->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->Labels = legendGroup22;
			displayLabel23->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup23->Caption = displayLabel23;
			legendGroup23->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->MarkerGroups = legendGroup23;
			displayViewSize9->Size = static_cast<System::UInt32>(100);
			scopeLegendView3->ViewSize = displayViewSize9;
			displayLabel24->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup24->Caption = displayLabel24;
			legendGroup24->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView3->Zones = legendGroup24;
			this->CalStarProfileScope->Legend = scopeLegendView3;
			this->CalStarProfileScope->Location = System::Drawing::Point(3, 165);
			this->CalStarProfileScope->Name = L"CalStarProfileScope";
			this->CalStarProfileScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->CalStarProfileScope->Size = System::Drawing::Size(291, 191);
			this->CalStarProfileScope->SizeLimit = static_cast<System::UInt32>(0);
			this->CalStarProfileScope->TabIndex = 1;
			this->CalStarProfileScope->Text = L"scope1";
			displayViewBackground13->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle3->Background = displayViewBackground13;
			displayTitle3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 13, 1));
			displayTitle3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle3.InternalData")));
			displayTitle3->Text = L"Star Profile";
			displayViewSize10->Size = static_cast<System::UInt32>(100);
			displayTitle3->ViewSize = displayViewSize10;
			this->CalStarProfileScope->Title = displayTitle3;
			displayToolBar3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar3->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton45->Image = displayToolBarButtonImage45;
			displayToolBarButtons3->Copy = displayToolBarButton45;
			displayToolBarButton46->Image = displayToolBarButtonImage46;
			displayToolBarButtons3->Hold = displayToolBarButton46;
			displayToolBarButton47->Image = displayToolBarButtonImage47;
			displayToolBarButtons3->PanMode = displayToolBarButton47;
			displayToolBarButton48->Image = displayToolBarButtonImage48;
			displayToolBarButtons3->Print = displayToolBarButton48;
			displayToolBarButton49->Image = displayToolBarButtonImage49;
			displayToolBarButtons3->Run = displayToolBarButton49;
			displayToolBarButton50->Image = displayToolBarButtonImage50;
			displayToolBarButtons3->Save = displayToolBarButton50;
			displayToolBarButton51->Image = displayToolBarButtonImage51;
			displayToolBarButtons3->Setup = displayToolBarButton51;
			displayToolBarButtons3->Size = toolBarButtonSize7;
			displayToolBarButton52->Image = displayToolBarButtonImage52;
			displayToolBarButtons3->XYZoomOn = displayToolBarButton52;
			displayToolBarButton53->Image = displayToolBarButtonImage53;
			displayToolBarButtons3->ZoomIn = displayToolBarButton53;
			displayToolBarButton54->Image = displayToolBarButtonImage54;
			displayToolBarButtons3->ZoomMode = displayToolBarButton54;
			displayToolBarButton55->Image = displayToolBarButtonImage55;
			displayToolBarButtons3->ZoomNext = displayToolBarButton55;
			displayToolBarButton56->Image = displayToolBarButtonImage56;
			displayToolBarButtons3->ZoomOff = displayToolBarButton56;
			displayToolBarButton57->Image = displayToolBarButtonImage57;
			displayToolBarButtons3->ZoomOut = displayToolBarButton57;
			displayToolBarButton58->Image = displayToolBarButtonImage58;
			displayToolBarButtons3->ZoomPrevious = displayToolBarButton58;
			displayToolBar3->Buttons = displayToolBarButtons3;
			displayToolBar3->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar3->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar3->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar3->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar3->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition3.InternalData")));
			displayToolBar3->Position = toolBarPosition3;
			this->CalStarProfileScope->ToolBar = displayToolBar3;
			displayTrails3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->CalStarProfileScope->Trails = displayTrails3;
			displayTitleLabel5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel5->Text = L"Crossection (pixels)";
			scopeXAxis3->AxisLabel = displayTitleLabel5;
			displayViewBackground14->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis3->Background = displayViewBackground14;
			viewButtonSettings5->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings5->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings5->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings5->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings5->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis3->Button = viewButtonSettings5;
			scopeXAxis3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis3->CursorSettings = displayAxisCursorSettings5;
			vclPen12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen12.InternalData")));
			displayGridLineSettings12->Pen = vclPen12;
			displayGridDirectionalLinesSettings5->Lines = displayGridLineSettings12;
			vclPen13->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen13->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen13.InternalData")));
			displayGridLineSettings13->Pen = vclPen13;
			displayGridDirectionalLinesSettings5->ZeroLine = displayGridLineSettings13;
			scopeXAxis3->DataView = displayGridDirectionalLinesSettings5;
			scopeXAxis3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat5->Precision = 3;
			scopeXAxis3->Format = axisFormat5;
			scopeXAxis3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis3.InternalData")));
			ticksStart5->StartFrom = 0;
			majorTicks5->StartFrom = ticksStart5;
			majorTicks5->Step = 10;
			scopeXAxis3->MajorTicks = majorTicks5;
			maxAxisValue5->DataValue = 1024;
			displayOptionalValue25->Enabled = false;
			displayOptionalValue25->Value = 1000;
			displayValueRange13->High = displayOptionalValue25;
			displayOptionalValue26->Enabled = false;
			displayOptionalValue26->Value = -1000;
			displayValueRange13->Low = displayOptionalValue26;
			maxAxisValue5->Range = displayValueRange13;
			basicAxisValue9->Value = 1024;
			maxAxisValue5->Tick = basicAxisValue9;
			maxAxisValue5->Value = 1024;
			scopeXAxis3->Max = maxAxisValue5;
			scopeMaxSample3->Value = static_cast<System::UInt32>(1024);
			scopeXAxis3->MaxSample = scopeMaxSample3;
			axisValue5->DataValue = 0;
			displayOptionalValue27->Enabled = false;
			displayOptionalValue27->Value = 1000;
			displayValueRange14->High = displayOptionalValue27;
			displayOptionalValue28->Enabled = false;
			displayOptionalValue28->Value = -1000;
			displayValueRange14->Low = displayOptionalValue28;
			axisValue5->Range = displayValueRange14;
			basicAxisValue10->Value = 0;
			axisValue5->Tick = basicAxisValue10;
			axisValue5->Value = 0;
			scopeXAxis3->Min = axisValue5;
			scopeXAxis3->MinorTicks = minorTicks5;
			axisToolBar5->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar5->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons5->Size = toolBarButtonSize8;
			displayToolBarButton59->Image = displayToolBarButtonImage59;
			axisToolBarButtons5->ZoomIn = displayToolBarButton59;
			displayToolBarButton60->Image = displayToolBarButtonImage60;
			axisToolBarButtons5->ZoomOff = displayToolBarButton60;
			displayToolBarButton61->Image = displayToolBarButtonImage61;
			axisToolBarButtons5->ZoomOneDir = displayToolBarButton61;
			displayToolBarButton62->Image = displayToolBarButtonImage62;
			axisToolBarButtons5->ZoomOut = displayToolBarButton62;
			axisToolBar5->Buttons = axisToolBarButtons5;
			axisToolBar5->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar5->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar5->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar5->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar5->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar5->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar5->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis3->ToolBar = axisToolBar5;
			scopeXAxis3->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis3->UnitScale = scopeXAxisUnitScale3;
			displayViewSize11->Size = static_cast<System::UInt32>(100);
			scopeXAxis3->ViewSize = displayViewSize11;
			displayOptionalValue29->Enabled = false;
			displayOptionalValue29->Value = 100000000;
			displayValueRange15->High = displayOptionalValue29;
			displayOptionalValue30->Enabled = true;
			displayOptionalValue30->Value = 1E-07;
			displayValueRange15->Low = displayOptionalValue30;
			displayAxisZoom5->Range = displayValueRange15;
			scopeXAxis3->Zooming = displayAxisZoom5;
			scopeXAxis3->ZoomPin = statePin5;
			this->CalStarProfileScope->XAxis = scopeXAxis3;
			this->CalStarProfileScope->XInputPins = pinList6;
			scopeAutoScaling3->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace5->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace5->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling3->SpaceAbove = scopeAutoScalingSpace5;
			scopeAutoScalingSpace6->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace6->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling3->SpaceBelow = scopeAutoScalingSpace6;
			scopeYAxis3->AutoScaling = scopeAutoScaling3;
			displayTitleLabel6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel6->Text = L"Pixel Value (ADU)";
			scopeYAxis3->AxisLabel = displayTitleLabel6;
			displayViewBackground15->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis3->Background = displayViewBackground15;
			viewButtonSettings6->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings6->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings6->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings6->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings6->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis3->Button = viewButtonSettings6;
			scopeYAxis3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis3->CursorSettings = displayAxisCursorSettings6;
			vclPen14->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen14->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen14.InternalData")));
			displayGridLineSettings14->Pen = vclPen14;
			displayGridDirectionalLinesSettings6->Lines = displayGridLineSettings14;
			vclPen15->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen15->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen15.InternalData")));
			displayGridLineSettings15->Pen = vclPen15;
			displayGridDirectionalLinesSettings6->ZeroLine = displayGridLineSettings15;
			scopeYAxis3->DataView = displayGridDirectionalLinesSettings6;
			scopeYAxis3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat6->Precision = 3;
			scopeYAxis3->Format = axisFormat6;
			scopeYAxis3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis3.InternalData")));
			ticksStart6->StartFrom = 0;
			majorTicks6->StartFrom = ticksStart6;
			majorTicks6->Step = 10;
			scopeYAxis3->MajorTicks = majorTicks6;
			maxAxisValue6->DataValue = 1000;
			displayOptionalValue31->Enabled = false;
			displayOptionalValue31->Value = 1000;
			displayValueRange16->High = displayOptionalValue31;
			displayOptionalValue32->Enabled = false;
			displayOptionalValue32->Value = -1000;
			displayValueRange16->Low = displayOptionalValue32;
			maxAxisValue6->Range = displayValueRange16;
			basicAxisValue11->Value = 0;
			maxAxisValue6->Tick = basicAxisValue11;
			maxAxisValue6->Value = 1000;
			scopeYAxis3->Max = maxAxisValue6;
			axisValue6->DataValue = -1000;
			displayOptionalValue33->Enabled = false;
			displayOptionalValue33->Value = 1000;
			displayValueRange17->High = displayOptionalValue33;
			displayOptionalValue34->Enabled = false;
			displayOptionalValue34->Value = -1000;
			displayValueRange17->Low = displayOptionalValue34;
			axisValue6->Range = displayValueRange17;
			basicAxisValue12->Value = 0;
			axisValue6->Tick = basicAxisValue12;
			axisValue6->Value = -1000;
			scopeYAxis3->Min = axisValue6;
			scopeYAxis3->MinorTicks = minorTicks6;
			axisToolBar6->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar6->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons6->Size = toolBarButtonSize9;
			displayToolBarButton63->Image = displayToolBarButtonImage63;
			axisToolBarButtons6->ZoomIn = displayToolBarButton63;
			displayToolBarButton64->Image = displayToolBarButtonImage64;
			axisToolBarButtons6->ZoomOff = displayToolBarButton64;
			displayToolBarButton65->Image = displayToolBarButtonImage65;
			axisToolBarButtons6->ZoomOneDir = displayToolBarButton65;
			displayToolBarButton66->Image = displayToolBarButtonImage66;
			axisToolBarButtons6->ZoomOut = displayToolBarButton66;
			axisToolBar6->Buttons = axisToolBarButtons6;
			axisToolBar6->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar6->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar6->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar6->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar6->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar6->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar6->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis3->ToolBar = axisToolBar6;
			scopeYAxis3->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize12->Size = static_cast<System::UInt32>(100);
			scopeYAxis3->ViewSize = displayViewSize12;
			displayOptionalValue35->Enabled = false;
			displayOptionalValue35->Value = 100000000;
			displayValueRange18->High = displayOptionalValue35;
			displayOptionalValue36->Enabled = true;
			displayOptionalValue36->Value = 1E-07;
			displayValueRange18->Low = displayOptionalValue36;
			displayAxisZoom6->Range = displayValueRange18;
			scopeYAxis3->Zooming = displayAxisZoom6;
			scopeYAxis3->ZoomPin = statePin6;
			this->CalStarProfileScope->YAxis = scopeYAxis3;
			displayZoom3->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->CalStarProfileScope->Zooming = displayZoom3;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->CalFocusFramePictureBox);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(291, 156);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Current Focus Frame";
			// 
			// CalFocusFramePictureBox
			// 
			this->CalFocusFramePictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CalFocusFramePictureBox->Location = System::Drawing::Point(3, 16);
			this->CalFocusFramePictureBox->Name = L"CalFocusFramePictureBox";
			this->CalFocusFramePictureBox->Size = System::Drawing::Size(285, 137);
			this->CalFocusFramePictureBox->TabIndex = 0;
			this->CalFocusFramePictureBox->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->BackColor = System::Drawing::Color::Plum;
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Location = System::Drawing::Point(94, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(425, 93);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Calibration Run Parameters";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel5->ColumnCount = 6;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.97852F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				18.13842F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				14.51303F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15.30612F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20.66327F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel5->Controls->Add(this->CalEndFocusPositionNumericUpDown, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->CalStartFocusPositionNumericUpDown, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->MinStarPeakNumericUpDown, 3, 1);
			this->tableLayoutPanel5->Controls->Add(this->label7, 4, 0);
			this->tableLayoutPanel5->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->label6, 2, 2);
			this->tableLayoutPanel5->Controls->Add(this->CalFramesPerPointNumericUpDown, 5, 0);
			this->tableLayoutPanel5->Controls->Add(this->CalFieldSizeNumericUpDown, 3, 2);
			this->tableLayoutPanel5->Controls->Add(this->MaxStarPeakNumericUpDown, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->CalStepSizeNumericUpDown, 1, 2);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(419, 74);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// CalEndFocusPositionNumericUpDown
			// 
			this->CalEndFocusPositionNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->CalEndFocusPositionNumericUpDown->Location = System::Drawing::Point(49, 27);
			this->CalEndFocusPositionNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->CalEndFocusPositionNumericUpDown->Name = L"CalEndFocusPositionNumericUpDown";
			this->CalEndFocusPositionNumericUpDown->Size = System::Drawing::Size(58, 20);
			this->CalEndFocusPositionNumericUpDown->TabIndex = 19;
			this->CalEndFocusPositionNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// CalStartFocusPositionNumericUpDown
			// 
			this->CalStartFocusPositionNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->CalStartFocusPositionNumericUpDown->Location = System::Drawing::Point(49, 3);
			this->CalStartFocusPositionNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->CalStartFocusPositionNumericUpDown->Name = L"CalStartFocusPositionNumericUpDown";
			this->CalStartFocusPositionNumericUpDown->Size = System::Drawing::Size(58, 20);
			this->CalStartFocusPositionNumericUpDown->TabIndex = 16;
			// 
			// MinStarPeakNumericUpDown
			// 
			this->MinStarPeakNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->MinStarPeakNumericUpDown->Location = System::Drawing::Point(186, 27);
			this->MinStarPeakNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60000, 0, 0, 0 });
			this->MinStarPeakNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->MinStarPeakNumericUpDown->Name = L"MinStarPeakNumericUpDown";
			this->MinStarPeakNumericUpDown->Size = System::Drawing::Size(58, 20);
			this->MinStarPeakNumericUpDown->TabIndex = 15;
			this->MinStarPeakNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(257, 5);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Frames/Point:";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(125, 5);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"MaxPeak:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Start:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"End:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Step:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(128, 29);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"MinPeak:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(125, 54);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Field Size:";
			// 
			// CalFramesPerPointNumericUpDown
			// 
			this->CalFramesPerPointNumericUpDown->Location = System::Drawing::Point(336, 3);
			this->CalFramesPerPointNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->CalFramesPerPointNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->CalFramesPerPointNumericUpDown->Name = L"CalFramesPerPointNumericUpDown";
			this->CalFramesPerPointNumericUpDown->Size = System::Drawing::Size(45, 20);
			this->CalFramesPerPointNumericUpDown->TabIndex = 12;
			this->CalFramesPerPointNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// CalFieldSizeNumericUpDown
			// 
			this->CalFieldSizeNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->CalFieldSizeNumericUpDown->Location = System::Drawing::Point(186, 51);
			this->CalFieldSizeNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->CalFieldSizeNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->CalFieldSizeNumericUpDown->Name = L"CalFieldSizeNumericUpDown";
			this->CalFieldSizeNumericUpDown->Size = System::Drawing::Size(58, 20);
			this->CalFieldSizeNumericUpDown->TabIndex = 13;
			this->CalFieldSizeNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// MaxStarPeakNumericUpDown
			// 
			this->MaxStarPeakNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->MaxStarPeakNumericUpDown->Location = System::Drawing::Point(186, 3);
			this->MaxStarPeakNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60000, 0, 0, 0 });
			this->MaxStarPeakNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->MaxStarPeakNumericUpDown->Name = L"MaxStarPeakNumericUpDown";
			this->MaxStarPeakNumericUpDown->Size = System::Drawing::Size(58, 20);
			this->MaxStarPeakNumericUpDown->TabIndex = 14;
			this->MaxStarPeakNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// CalStepSizeNumericUpDown
			// 
			this->CalStepSizeNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->CalStepSizeNumericUpDown->Location = System::Drawing::Point(49, 51);
			this->CalStepSizeNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->CalStepSizeNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->CalStepSizeNumericUpDown->Name = L"CalStepSizeNumericUpDown";
			this->CalStepSizeNumericUpDown->Size = System::Drawing::Size(58, 20);
			this->CalStepSizeNumericUpDown->TabIndex = 18;
			this->CalStepSizeNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(619, 587);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Calibration Parameters";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->CloseButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel11, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 622);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(627, 37);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CloseButton->Location = System::Drawing::Point(119, 7);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 0;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &AutoFocusDialog::CloseButton_Click);
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 3;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.84946F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.15054F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				92)));
			this->tableLayoutPanel11->Controls->Add(this->StopButton, 2, 0);
			this->tableLayoutPanel11->Controls->Add(this->PauseButton, 1, 0);
			this->tableLayoutPanel11->Controls->Add(this->StartButton, 0, 0);
			this->tableLayoutPanel11->Location = System::Drawing::Point(316, 3);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(278, 31);
			this->tableLayoutPanel11->TabIndex = 3;
			// 
			// StopButton
			// 
			this->StopButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StopButton->BackColor = System::Drawing::Color::Red;
			this->StopButton->Location = System::Drawing::Point(194, 4);
			this->StopButton->Name = L"StopButton";
			this->StopButton->Size = System::Drawing::Size(75, 23);
			this->StopButton->TabIndex = 2;
			this->StopButton->Text = L"Stop";
			this->StopButton->UseVisualStyleBackColor = false;
			this->StopButton->Click += gcnew System::EventHandler(this, &AutoFocusDialog::StopButton_Click);
			// 
			// PauseButton
			// 
			this->PauseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PauseButton->BackColor = System::Drawing::Color::Yellow;
			this->PauseButton->Location = System::Drawing::Point(99, 4);
			this->PauseButton->Name = L"PauseButton";
			this->PauseButton->Size = System::Drawing::Size(75, 23);
			this->PauseButton->TabIndex = 1;
			this->PauseButton->Text = L"Pause";
			this->PauseButton->UseVisualStyleBackColor = false;
			this->PauseButton->Click += gcnew System::EventHandler(this, &AutoFocusDialog::PauseButton_Click);
			// 
			// StartButton
			// 
			this->StartButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StartButton->BackColor = System::Drawing::Color::ForestGreen;
			this->StartButton->Location = System::Drawing::Point(6, 4);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(75, 23);
			this->StartButton->TabIndex = 0;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &AutoFocusDialog::StartButton_Click);
			// 
			// AutoFocusDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 662);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AutoFocusDialog";
			this->Text = L"AutoFocusDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tabControl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StarProfileScope))->EndInit();
			this->groupBox6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FocusFramePictureBox))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->tableLayoutPanel12->ResumeLayout(false);
			this->tableLayoutPanel12->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FramesPerPointNumericUpDown))->EndInit();
			this->groupBox8->ResumeLayout(false);
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCurveScope))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStarProfileScope))->EndInit();
			this->groupBox4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFocusFramePictureBox))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalEndFocusPositionNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStartFocusPositionNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MinStarPeakNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFramesPerPointNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFieldSizeNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxStarPeakNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStepSizeNumericUpDown))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel11->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	public: static System::Void ShowTheDialog(int x1, int y1, int x2, int y2) {

		// Set all current values for dialog controls

		AutoFocusDialog::FormPtr->SetAllDialogValues();
		autoFocusSettings.FrameX1 = x1;
		autoFocusSettings.FrameY1 = y1;
		autoFocusSettings.FrameX2 = x2;
		autoFocusSettings.FrameY2 = y2;

		// Finally, show the dialog

		AutoFocusDialog::FormPtr->Show();

	}

	private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {

		// Get all values from dialog controls

		this->GetAllDialogValues();
		this->Hide();
	}

	private: System::Void SetAllDialogValues() {

		AutoFocusDialog::FormPtr->SetCalNumFramesPerPoint(autoFocusSettings.CalNumFramesPerPoint);
		AutoFocusDialog::FormPtr->SetCalStartFocusPosition(autoFocusSettings.CalStartFocusPosition);
		AutoFocusDialog::FormPtr->SetCalEndFocusPosition(autoFocusSettings.CalEndFocusPosition);
		AutoFocusDialog::FormPtr->SetCalFieldSize(autoFocusSettings.CalFieldSize);
		AutoFocusDialog::FormPtr->SetCalStepSize(autoFocusSettings.CalFocusStepSize);
		AutoFocusDialog::FormPtr->SetMaxStarPeak(autoFocusSettings.CalMaxStarPeak);
		AutoFocusDialog::FormPtr->SetMinStarPeak(autoFocusSettings.CalMinStarPeak);
		AutoFocusDialog::FormPtr->SetFramesPerPoint(autoFocusSettings.NumFramesPerPoint);
	}

	private:  System::Void GetAllDialogValues() {

		AutoFocusDialog::FormPtr->GetCalNumFramesPerPoint(&autoFocusSettings.CalNumFramesPerPoint);
		AutoFocusDialog::FormPtr->GetCalStartFocusPosition(&autoFocusSettings.CalStartFocusPosition);
		AutoFocusDialog::FormPtr->GetCalEndFocusPosition(&autoFocusSettings.CalEndFocusPosition);
		AutoFocusDialog::FormPtr->GetCalFieldSize(&autoFocusSettings.CalFieldSize);
		AutoFocusDialog::FormPtr->GetCalStepSize(&autoFocusSettings.CalFocusStepSize);
		AutoFocusDialog::FormPtr->GetMaxStarPeak(&autoFocusSettings.CalMaxStarPeak);
		AutoFocusDialog::FormPtr->GetMinStarPeak(&autoFocusSettings.CalMinStarPeak);
		AutoFocusDialog::FormPtr->GetFramesPerPoint(&autoFocusSettings.NumFramesPerPoint);

	}

	public: static void GetCalNumFramesPerPoint(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->CalFramesPerPointNumericUpDown->Value);
	}


	public: static void SetCalNumFramesPerPoint(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->CalFramesPerPointNumericUpDown->Value = Value;
	}


	public: static void GetCalStartFocusPosition(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->CalStartFocusPositionNumericUpDown->Value);
	}


	public: static void SetCalStartFocusPosition(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->CalStartFocusPositionNumericUpDown->Value = Value;
	}


	public: static void GetCalEndFocusPosition(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->CalEndFocusPositionNumericUpDown->Value);
	}


	public: static void SetCalEndFocusPosition(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->CalEndFocusPositionNumericUpDown->Value = Value;
	}


	public: static void GetCalStepSize(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->CalStepSizeNumericUpDown->Value);
	}


	public: static void SetCalStepSize(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->CalStepSizeNumericUpDown->Value = Value;
	}


	public: static void GetMaxStarPeak(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->MaxStarPeakNumericUpDown->Value);
	}


	public: static void SetMaxStarPeak(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->MaxStarPeakNumericUpDown->Value = Value;
	}


	public: static void GetMinStarPeak(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->MinStarPeakNumericUpDown->Value);
	}


	public: static void SetMinStarPeak(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->MinStarPeakNumericUpDown->Value = Value;
	}


	public: static void GetCalFieldSize(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->CalFieldSizeNumericUpDown->Value);
	}


	public: static void SetCalFieldSize(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->CalFieldSizeNumericUpDown->Value = Value;
	}


	public: static void GetFramesPerPoint(int *value) {

		*value = System::Decimal::ToInt32(AutoFocusDialog::FormPtr->FramesPerPointNumericUpDown->Value);
	}


	public: static void SetFramesPerPoint(int value) {

		System::Decimal Value;

		Value = System::Decimal(value);
		AutoFocusDialog::FormPtr->FramesPerPointNumericUpDown->Value = Value;
	}



	private: System::Void StartButton_Click(System::Object^  sender, System::EventArgs^  e) {

		// First figure out if start of calibration run or auto focusing

		this->GetAllDialogValues();

		switch (this->tabControl->SelectedIndex) {

			case 0: // Autofocusing
				this->FocusFramePictureBox->Image = this->FocusImageBitmap;
				this->FocusFramePictureBox->Width = (autoFocusSettings.FrameX2 - autoFocusSettings.FrameX1);
				this->FocusFramePictureBox->Height = (autoFocusSettings.FrameY2 - autoFocusSettings.FrameY1);
				doAutoFocusing(&autoFocusSettings);
				break;
			case 1: // Calibration run
				this->CalFocusFramePictureBox->Image = this->FocusImageBitmap;
				this->CalFocusFramePictureBox->Width = (autoFocusSettings.FrameX2 - autoFocusSettings.FrameX1);
				this->CalFocusFramePictureBox->Height = (autoFocusSettings.FrameY2 - autoFocusSettings.FrameY1);
				doAutoFocusingCalibrationRun(&autoFocusSettings);
				break;
			case 2: // just viewing calibration parameters
				break;
		}
	}


	private: System::Void PauseButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void StopButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}

};
}
