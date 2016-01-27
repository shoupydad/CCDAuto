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
		static bool PauseRequested;
		static bool AbortRequested;
		AutoFocusDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			FormPtr = this;
			AutoFocusDialogExists = true;
			this->FocusImageBitmap = gcnew System::Drawing::Bitmap(MIN_FOCUS_FIELD_SIZE, MIN_FOCUS_FIELD_SIZE);
			this->PauseRequested = false;
			this->AbortRequested = false;
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
	private: System::Windows::Forms::Button^  AbortButton;


	private: System::Windows::Forms::Button^  PauseButton;


	private: System::Windows::Forms::Button^  StartButton;



	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
private: System::Windows::Forms::RadioButton^  OnVCurveLeftRadioButton;
private: System::Windows::Forms::RadioButton^  OnVCurveRightRadioButton;
private: System::Windows::Forms::RadioButton^  UnknownRadioButton;



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
			Mitov::PlotLab::ScopeDataView^  scopeDataView4 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground16 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings16 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen16 = (gcnew Vcl::VclPen());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AutoFocusDialog::typeid));
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting4 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting7 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting8 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting19 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting20 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting21 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting22 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting23 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint4 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel4 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting24 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList7 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView4 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground17 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings4 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup25 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel25 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup26 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel26 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup27 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel27 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup28 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel28 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup29 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel29 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup30 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel30 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup31 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel31 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize13 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup32 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel32 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle4 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground18 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize14 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar4 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons4 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton67 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage67 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton68 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage68 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton69 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage69 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton70 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage70 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton71 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage71 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton72 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage72 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton73 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage73 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize10 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton74 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage74 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton75 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage75 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton76 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage76 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton77 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage77 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton78 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage78 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton79 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage79 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton80 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage80 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition4 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails4 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis4 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel7 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground19 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings7 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings7 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings7 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings17 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen17 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings18 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen18 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat7 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks7 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart7 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue7 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange19 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue37 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue38 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue13 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample4 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue7 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange20 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue39 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue40 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue14 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks7 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar7 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons7 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize11 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton81 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage81 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton82 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage82 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton83 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage83 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton84 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage84 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale4 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize15 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom7 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange21 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue41 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue42 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin7 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList8 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis4 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling4 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace7 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace8 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel8 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground20 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings8 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings8 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings8 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings19 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen19 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings20 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen20 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat8 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks8 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart8 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue8 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange22 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue43 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue44 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue15 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue8 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange23 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue45 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue46 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue16 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks8 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar8 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons8 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize12 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton85 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage85 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton86 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage86 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton87 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage87 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton88 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage88 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize16 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom8 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange24 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue47 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue48 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin8 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom4 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView5 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground21 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings21 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen21 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting5 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting9 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting10 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting25 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting26 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting27 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting28 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting29 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint5 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel5 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting30 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList9 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView5 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground22 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings5 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup33 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel33 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup34 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel34 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup35 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel35 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup36 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel36 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup37 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel37 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup38 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel38 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup39 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel39 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize17 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup40 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel40 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle5 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground23 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize18 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar5 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons5 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton89 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage89 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton90 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage90 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton91 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage91 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton92 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage92 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton93 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage93 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton94 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage94 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton95 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage95 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize13 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton96 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage96 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton97 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage97 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton98 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage98 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton99 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage99 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton100 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage100 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton101 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage101 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton102 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage102 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition5 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails5 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis5 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel9 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground24 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings9 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings9 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings9 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings22 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen22 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings23 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen23 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat9 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks9 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart9 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue9 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange25 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue49 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue50 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue17 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample5 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue9 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange26 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue51 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue52 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue18 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks9 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar9 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons9 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize14 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton103 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage103 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton104 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage104 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton105 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage105 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton106 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage106 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale5 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize19 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom9 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange27 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue53 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue54 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin9 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList10 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis5 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling5 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace9 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace10 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel10 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground25 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings10 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings10 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings10 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings24 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen24 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings25 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen25 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat10 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks10 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart10 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue10 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange28 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue55 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue56 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue19 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue10 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange29 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue57 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue58 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue20 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks10 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar10 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons10 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize15 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton107 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage107 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton108 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage108 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton109 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage109 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton110 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage110 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize20 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom10 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange30 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue59 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue60 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin10 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom5 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView6 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground26 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings26 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen26 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting6 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting11 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting12 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting31 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting32 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting33 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting34 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting35 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint6 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel6 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting36 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList11 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView6 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground27 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings6 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup41 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel41 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup42 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel42 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup43 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel43 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup44 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel44 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup45 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel45 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup46 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel46 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup47 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel47 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize21 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup48 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel48 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle6 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground28 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize22 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar6 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons6 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton111 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage111 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton112 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage112 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton113 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage113 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton114 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage114 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton115 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage115 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton116 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage116 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton117 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage117 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize16 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton118 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage118 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton119 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage119 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton120 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage120 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton121 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage121 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton122 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage122 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton123 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage123 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton124 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage124 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition6 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails6 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis6 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel11 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground29 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings11 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings11 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings11 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings27 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen27 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings28 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen28 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat11 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks11 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart11 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue11 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange31 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue61 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue62 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue21 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample6 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue11 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange32 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue63 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue64 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue22 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks11 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar11 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons11 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize17 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton125 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage125 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton126 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage126 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton127 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage127 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton128 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage128 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale6 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize23 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom11 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange33 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue65 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue66 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin11 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList12 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis6 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling6 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace11 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace12 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel12 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground30 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings12 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings12 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings12 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings29 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen29 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings30 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen30 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat12 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks12 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart12 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue12 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange34 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue67 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue68 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue23 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue12 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange35 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue69 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue70 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue24 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks12 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar12 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons12 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize18 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton129 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage129 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton130 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage130 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton131 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage131 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton132 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage132 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize24 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom12 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange36 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue71 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue72 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin12 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom6 = (gcnew Mitov::PlotLab::DisplayZoom());
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
			this->OnVCurveLeftRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->OnVCurveRightRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->UnknownRadioButton = (gcnew System::Windows::Forms::RadioButton());
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
			this->AbortButton = (gcnew System::Windows::Forms::Button());
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
			displayViewBackground16->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView4->Background = displayViewBackground16;
			vclPen16->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen16->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen16.InternalData")));
			displayGridLineSettings16->Pen = vclPen16;
			scopeDataView4->Border = displayGridLineSettings16;
			this->StarProfileScope->DataView = scopeDataView4;
			channelItemHighlighting7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->ChannelLinks = channelItemHighlighting7;
			channelItemHighlighting8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->Channels = channelItemHighlighting8;
			displayItemHighlighting19->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->CursorLinks = displayItemHighlighting19;
			displayItemHighlighting20->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->Cursors = displayItemHighlighting20;
			displayItemHighlighting21->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->Ellipses = displayItemHighlighting21;
			displayItemHighlighting22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->Labels = displayItemHighlighting22;
			displayItemHighlighting23->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->Markers = displayItemHighlighting23;
			channelMouseHitPoint4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint4->PointLabel = optionalLabel4;
			dataChartHighlighting4->MouseHitPoint = channelMouseHitPoint4;
			displayItemHighlighting24->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting4->Zones = displayItemHighlighting24;
			this->StarProfileScope->Highlighting = dataChartHighlighting4;
			this->StarProfileScope->InputPins = pinList7;
			this->StarProfileScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"StarProfileScope.InternalData")));
			displayViewBackground17->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView4->Background = displayViewBackground17;
			legendViewButtonSettings4->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings4->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings4->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView4->Buttons = legendViewButtonSettings4;
			displayLabel25->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup25->Caption = displayLabel25;
			legendGroup25->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->ChannelLinks = legendGroup25;
			displayLabel26->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup26->Caption = displayLabel26;
			legendGroup26->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->Channels = legendGroup26;
			displayLabel27->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup27->Caption = displayLabel27;
			legendGroup27->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->CursorLinks = legendGroup27;
			displayLabel28->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup28->Caption = displayLabel28;
			legendGroup28->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->Cursors = legendGroup28;
			displayLabel29->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup29->Caption = displayLabel29;
			legendGroup29->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->Ellipses = legendGroup29;
			scopeLegendView4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView4.InternalData")));
			displayLabel30->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup30->Caption = displayLabel30;
			legendGroup30->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->Labels = legendGroup30;
			displayLabel31->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup31->Caption = displayLabel31;
			legendGroup31->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->MarkerGroups = legendGroup31;
			displayViewSize13->Size = static_cast<System::UInt32>(100);
			scopeLegendView4->ViewSize = displayViewSize13;
			displayLabel32->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup32->Caption = displayLabel32;
			legendGroup32->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView4->Zones = legendGroup32;
			this->StarProfileScope->Legend = scopeLegendView4;
			this->StarProfileScope->Location = System::Drawing::Point(303, 3);
			this->StarProfileScope->Name = L"StarProfileScope";
			this->StarProfileScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->StarProfileScope->Size = System::Drawing::Size(295, 194);
			this->StarProfileScope->SizeLimit = static_cast<System::UInt32>(0);
			this->StarProfileScope->TabIndex = 0;
			this->StarProfileScope->Text = L"scope2";
			displayViewBackground18->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle4->Background = displayViewBackground18;
			displayTitle4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 16, 1));
			displayTitle4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle4.InternalData")));
			displayTitle4->Text = L"Star Profile";
			displayViewSize14->Size = static_cast<System::UInt32>(100);
			displayTitle4->ViewSize = displayViewSize14;
			this->StarProfileScope->Title = displayTitle4;
			displayToolBar4->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar4->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton67->Image = displayToolBarButtonImage67;
			displayToolBarButtons4->Copy = displayToolBarButton67;
			displayToolBarButton68->Image = displayToolBarButtonImage68;
			displayToolBarButtons4->Hold = displayToolBarButton68;
			displayToolBarButton69->Image = displayToolBarButtonImage69;
			displayToolBarButtons4->PanMode = displayToolBarButton69;
			displayToolBarButton70->Image = displayToolBarButtonImage70;
			displayToolBarButtons4->Print = displayToolBarButton70;
			displayToolBarButton71->Image = displayToolBarButtonImage71;
			displayToolBarButtons4->Run = displayToolBarButton71;
			displayToolBarButton72->Image = displayToolBarButtonImage72;
			displayToolBarButtons4->Save = displayToolBarButton72;
			displayToolBarButton73->Image = displayToolBarButtonImage73;
			displayToolBarButtons4->Setup = displayToolBarButton73;
			displayToolBarButtons4->Size = toolBarButtonSize10;
			displayToolBarButton74->Image = displayToolBarButtonImage74;
			displayToolBarButtons4->XYZoomOn = displayToolBarButton74;
			displayToolBarButton75->Image = displayToolBarButtonImage75;
			displayToolBarButtons4->ZoomIn = displayToolBarButton75;
			displayToolBarButton76->Image = displayToolBarButtonImage76;
			displayToolBarButtons4->ZoomMode = displayToolBarButton76;
			displayToolBarButton77->Image = displayToolBarButtonImage77;
			displayToolBarButtons4->ZoomNext = displayToolBarButton77;
			displayToolBarButton78->Image = displayToolBarButtonImage78;
			displayToolBarButtons4->ZoomOff = displayToolBarButton78;
			displayToolBarButton79->Image = displayToolBarButtonImage79;
			displayToolBarButtons4->ZoomOut = displayToolBarButton79;
			displayToolBarButton80->Image = displayToolBarButtonImage80;
			displayToolBarButtons4->ZoomPrevious = displayToolBarButton80;
			displayToolBar4->Buttons = displayToolBarButtons4;
			displayToolBar4->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar4->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar4->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar4->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar4->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition4.InternalData")));
			displayToolBar4->Position = toolBarPosition4;
			this->StarProfileScope->ToolBar = displayToolBar4;
			displayTrails4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->StarProfileScope->Trails = displayTrails4;
			displayTitleLabel7->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel7->Text = L"Cross Section (pixels)";
			scopeXAxis4->AxisLabel = displayTitleLabel7;
			displayViewBackground19->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis4->Background = displayViewBackground19;
			viewButtonSettings7->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings7->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings7->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings7->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings7->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis4->Button = viewButtonSettings7;
			scopeXAxis4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis4->CursorSettings = displayAxisCursorSettings7;
			vclPen17->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen17->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen17.InternalData")));
			displayGridLineSettings17->Pen = vclPen17;
			displayGridDirectionalLinesSettings7->Lines = displayGridLineSettings17;
			vclPen18->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen18->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen18.InternalData")));
			displayGridLineSettings18->Pen = vclPen18;
			displayGridDirectionalLinesSettings7->ZeroLine = displayGridLineSettings18;
			scopeXAxis4->DataView = displayGridDirectionalLinesSettings7;
			scopeXAxis4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat7->Precision = 3;
			scopeXAxis4->Format = axisFormat7;
			scopeXAxis4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis4.InternalData")));
			ticksStart7->StartFrom = 0;
			majorTicks7->StartFrom = ticksStart7;
			majorTicks7->Step = 10;
			scopeXAxis4->MajorTicks = majorTicks7;
			maxAxisValue7->DataValue = 1024;
			displayOptionalValue37->Enabled = false;
			displayOptionalValue37->Value = 1000;
			displayValueRange19->High = displayOptionalValue37;
			displayOptionalValue38->Enabled = false;
			displayOptionalValue38->Value = -1000;
			displayValueRange19->Low = displayOptionalValue38;
			maxAxisValue7->Range = displayValueRange19;
			basicAxisValue13->Value = 1024;
			maxAxisValue7->Tick = basicAxisValue13;
			maxAxisValue7->Value = 1024;
			scopeXAxis4->Max = maxAxisValue7;
			scopeMaxSample4->Value = static_cast<System::UInt32>(1024);
			scopeXAxis4->MaxSample = scopeMaxSample4;
			axisValue7->DataValue = 0;
			displayOptionalValue39->Enabled = false;
			displayOptionalValue39->Value = 1000;
			displayValueRange20->High = displayOptionalValue39;
			displayOptionalValue40->Enabled = false;
			displayOptionalValue40->Value = -1000;
			displayValueRange20->Low = displayOptionalValue40;
			axisValue7->Range = displayValueRange20;
			basicAxisValue14->Value = 0;
			axisValue7->Tick = basicAxisValue14;
			axisValue7->Value = 0;
			scopeXAxis4->Min = axisValue7;
			scopeXAxis4->MinorTicks = minorTicks7;
			axisToolBar7->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar7->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons7->Size = toolBarButtonSize11;
			displayToolBarButton81->Image = displayToolBarButtonImage81;
			axisToolBarButtons7->ZoomIn = displayToolBarButton81;
			displayToolBarButton82->Image = displayToolBarButtonImage82;
			axisToolBarButtons7->ZoomOff = displayToolBarButton82;
			displayToolBarButton83->Image = displayToolBarButtonImage83;
			axisToolBarButtons7->ZoomOneDir = displayToolBarButton83;
			displayToolBarButton84->Image = displayToolBarButtonImage84;
			axisToolBarButtons7->ZoomOut = displayToolBarButton84;
			axisToolBar7->Buttons = axisToolBarButtons7;
			axisToolBar7->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar7->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar7->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar7->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar7->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar7->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar7->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis4->ToolBar = axisToolBar7;
			scopeXAxis4->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis4->UnitScale = scopeXAxisUnitScale4;
			displayViewSize15->Size = static_cast<System::UInt32>(100);
			scopeXAxis4->ViewSize = displayViewSize15;
			displayOptionalValue41->Enabled = false;
			displayOptionalValue41->Value = 100000000;
			displayValueRange21->High = displayOptionalValue41;
			displayOptionalValue42->Enabled = true;
			displayOptionalValue42->Value = 1E-07;
			displayValueRange21->Low = displayOptionalValue42;
			displayAxisZoom7->Range = displayValueRange21;
			scopeXAxis4->Zooming = displayAxisZoom7;
			scopeXAxis4->ZoomPin = statePin7;
			this->StarProfileScope->XAxis = scopeXAxis4;
			this->StarProfileScope->XInputPins = pinList8;
			scopeAutoScaling4->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace7->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace7->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling4->SpaceAbove = scopeAutoScalingSpace7;
			scopeAutoScalingSpace8->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace8->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling4->SpaceBelow = scopeAutoScalingSpace8;
			scopeYAxis4->AutoScaling = scopeAutoScaling4;
			displayTitleLabel8->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel8->Text = L"Pixel Value (ADU)";
			scopeYAxis4->AxisLabel = displayTitleLabel8;
			displayViewBackground20->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis4->Background = displayViewBackground20;
			viewButtonSettings8->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings8->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings8->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings8->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings8->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis4->Button = viewButtonSettings8;
			scopeYAxis4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis4->CursorSettings = displayAxisCursorSettings8;
			vclPen19->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen19->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen19.InternalData")));
			displayGridLineSettings19->Pen = vclPen19;
			displayGridDirectionalLinesSettings8->Lines = displayGridLineSettings19;
			vclPen20->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen20->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen20.InternalData")));
			displayGridLineSettings20->Pen = vclPen20;
			displayGridDirectionalLinesSettings8->ZeroLine = displayGridLineSettings20;
			scopeYAxis4->DataView = displayGridDirectionalLinesSettings8;
			scopeYAxis4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat8->Precision = 3;
			scopeYAxis4->Format = axisFormat8;
			scopeYAxis4->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis4.InternalData")));
			ticksStart8->StartFrom = 0;
			majorTicks8->StartFrom = ticksStart8;
			majorTicks8->Step = 10;
			scopeYAxis4->MajorTicks = majorTicks8;
			maxAxisValue8->DataValue = 1000;
			displayOptionalValue43->Enabled = false;
			displayOptionalValue43->Value = 1000;
			displayValueRange22->High = displayOptionalValue43;
			displayOptionalValue44->Enabled = false;
			displayOptionalValue44->Value = -1000;
			displayValueRange22->Low = displayOptionalValue44;
			maxAxisValue8->Range = displayValueRange22;
			basicAxisValue15->Value = 0;
			maxAxisValue8->Tick = basicAxisValue15;
			maxAxisValue8->Value = 1000;
			scopeYAxis4->Max = maxAxisValue8;
			axisValue8->DataValue = -1000;
			displayOptionalValue45->Enabled = false;
			displayOptionalValue45->Value = 1000;
			displayValueRange23->High = displayOptionalValue45;
			displayOptionalValue46->Enabled = false;
			displayOptionalValue46->Value = -1000;
			displayValueRange23->Low = displayOptionalValue46;
			axisValue8->Range = displayValueRange23;
			basicAxisValue16->Value = 0;
			axisValue8->Tick = basicAxisValue16;
			axisValue8->Value = -1000;
			scopeYAxis4->Min = axisValue8;
			scopeYAxis4->MinorTicks = minorTicks8;
			axisToolBar8->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar8->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons8->Size = toolBarButtonSize12;
			displayToolBarButton85->Image = displayToolBarButtonImage85;
			axisToolBarButtons8->ZoomIn = displayToolBarButton85;
			displayToolBarButton86->Image = displayToolBarButtonImage86;
			axisToolBarButtons8->ZoomOff = displayToolBarButton86;
			displayToolBarButton87->Image = displayToolBarButtonImage87;
			axisToolBarButtons8->ZoomOneDir = displayToolBarButton87;
			displayToolBarButton88->Image = displayToolBarButtonImage88;
			axisToolBarButtons8->ZoomOut = displayToolBarButton88;
			axisToolBar8->Buttons = axisToolBarButtons8;
			axisToolBar8->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar8->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar8->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar8->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar8->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar8->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar8->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis4->ToolBar = axisToolBar8;
			scopeYAxis4->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize16->Size = static_cast<System::UInt32>(100);
			scopeYAxis4->ViewSize = displayViewSize16;
			displayOptionalValue47->Enabled = false;
			displayOptionalValue47->Value = 100000000;
			displayValueRange24->High = displayOptionalValue47;
			displayOptionalValue48->Enabled = true;
			displayOptionalValue48->Value = 1E-07;
			displayValueRange24->Low = displayOptionalValue48;
			displayAxisZoom8->Range = displayValueRange24;
			scopeYAxis4->Zooming = displayAxisZoom8;
			scopeYAxis4->ZoomPin = statePin8;
			this->StarProfileScope->YAxis = scopeYAxis4;
			displayZoom4->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->StarProfileScope->Zooming = displayZoom4;
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
				145)));
			this->tableLayoutPanel12->Controls->Add(this->OnVCurveLeftRadioButton, 2, 0);
			this->tableLayoutPanel12->Controls->Add(this->OnVCurveRightRadioButton, 2, 1);
			this->tableLayoutPanel12->Controls->Add(this->UnknownRadioButton, 2, 2);
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
			// OnVCurveLeftRadioButton
			// 
			this->OnVCurveLeftRadioButton->AutoSize = true;
			this->OnVCurveLeftRadioButton->Location = System::Drawing::Point(168, 3);
			this->OnVCurveLeftRadioButton->Name = L"OnVCurveLeftRadioButton";
			this->OnVCurveLeftRadioButton->Size = System::Drawing::Size(98, 17);
			this->OnVCurveLeftRadioButton->TabIndex = 0;
			this->OnVCurveLeftRadioButton->TabStop = true;
			this->OnVCurveLeftRadioButton->Text = L"On VCurve Left";
			this->OnVCurveLeftRadioButton->UseVisualStyleBackColor = true;
			// 
			// OnVCurveRightRadioButton
			// 
			this->OnVCurveRightRadioButton->AutoSize = true;
			this->OnVCurveRightRadioButton->Location = System::Drawing::Point(168, 28);
			this->OnVCurveRightRadioButton->Name = L"OnVCurveRightRadioButton";
			this->OnVCurveRightRadioButton->Size = System::Drawing::Size(105, 17);
			this->OnVCurveRightRadioButton->TabIndex = 1;
			this->OnVCurveRightRadioButton->TabStop = true;
			this->OnVCurveRightRadioButton->Text = L"On VCurve Right";
			this->OnVCurveRightRadioButton->UseVisualStyleBackColor = true;
			// 
			// UnknownRadioButton
			// 
			this->UnknownRadioButton->AutoSize = true;
			this->UnknownRadioButton->Location = System::Drawing::Point(168, 53);
			this->UnknownRadioButton->Name = L"UnknownRadioButton";
			this->UnknownRadioButton->Size = System::Drawing::Size(71, 17);
			this->UnknownRadioButton->TabIndex = 2;
			this->UnknownRadioButton->TabStop = true;
			this->UnknownRadioButton->Text = L"Unknown";
			this->UnknownRadioButton->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(7, 6);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(73, 13);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Frames/Point:";
			// 
			// FramesPerPointNumericUpDown
			// 
			this->FramesPerPointNumericUpDown->Location = System::Drawing::Point(86, 3);
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
			displayViewBackground21->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView5->Background = displayViewBackground21;
			vclPen21->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen21->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen21.InternalData")));
			displayGridLineSettings21->Pen = vclPen21;
			scopeDataView5->Border = displayGridLineSettings21;
			this->VCurveScope->DataView = scopeDataView5;
			this->VCurveScope->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->ChannelLinks = channelItemHighlighting9;
			channelItemHighlighting10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->Channels = channelItemHighlighting10;
			displayItemHighlighting25->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->CursorLinks = displayItemHighlighting25;
			displayItemHighlighting26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->Cursors = displayItemHighlighting26;
			displayItemHighlighting27->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->Ellipses = displayItemHighlighting27;
			displayItemHighlighting28->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->Labels = displayItemHighlighting28;
			displayItemHighlighting29->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->Markers = displayItemHighlighting29;
			channelMouseHitPoint5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint5->PointLabel = optionalLabel5;
			dataChartHighlighting5->MouseHitPoint = channelMouseHitPoint5;
			displayItemHighlighting30->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting5->Zones = displayItemHighlighting30;
			this->VCurveScope->Highlighting = dataChartHighlighting5;
			this->VCurveScope->InputPins = pinList9;
			this->VCurveScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"VCurveScope.InternalData")));
			displayViewBackground22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView5->Background = displayViewBackground22;
			legendViewButtonSettings5->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings5->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView5->Buttons = legendViewButtonSettings5;
			displayLabel33->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup33->Caption = displayLabel33;
			legendGroup33->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->ChannelLinks = legendGroup33;
			displayLabel34->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup34->Caption = displayLabel34;
			legendGroup34->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->Channels = legendGroup34;
			displayLabel35->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup35->Caption = displayLabel35;
			legendGroup35->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->CursorLinks = legendGroup35;
			displayLabel36->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup36->Caption = displayLabel36;
			legendGroup36->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->Cursors = legendGroup36;
			displayLabel37->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup37->Caption = displayLabel37;
			legendGroup37->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->Ellipses = legendGroup37;
			scopeLegendView5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView5.InternalData")));
			displayLabel38->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup38->Caption = displayLabel38;
			legendGroup38->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->Labels = legendGroup38;
			displayLabel39->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup39->Caption = displayLabel39;
			legendGroup39->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->MarkerGroups = legendGroup39;
			displayViewSize17->Size = static_cast<System::UInt32>(100);
			scopeLegendView5->ViewSize = displayViewSize17;
			displayLabel40->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup40->Caption = displayLabel40;
			legendGroup40->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView5->Zones = legendGroup40;
			this->VCurveScope->Legend = scopeLegendView5;
			this->VCurveScope->Location = System::Drawing::Point(306, 3);
			this->VCurveScope->Name = L"VCurveScope";
			this->VCurveScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->VCurveScope->Size = System::Drawing::Size(298, 363);
			this->VCurveScope->SizeLimit = static_cast<System::UInt32>(0);
			this->VCurveScope->TabIndex = 0;
			this->VCurveScope->Text = L"V Curve";
			displayViewBackground23->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle5->Background = displayViewBackground23;
			displayTitle5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 13, 1));
			displayTitle5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle5.InternalData")));
			displayTitle5->Text = L"V Curve";
			displayViewSize18->Size = static_cast<System::UInt32>(100);
			displayTitle5->ViewSize = displayViewSize18;
			this->VCurveScope->Title = displayTitle5;
			displayToolBar5->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton89->Image = displayToolBarButtonImage89;
			displayToolBarButtons5->Copy = displayToolBarButton89;
			displayToolBarButton90->Image = displayToolBarButtonImage90;
			displayToolBarButtons5->Hold = displayToolBarButton90;
			displayToolBarButton91->Image = displayToolBarButtonImage91;
			displayToolBarButtons5->PanMode = displayToolBarButton91;
			displayToolBarButton92->Image = displayToolBarButtonImage92;
			displayToolBarButtons5->Print = displayToolBarButton92;
			displayToolBarButton93->Image = displayToolBarButtonImage93;
			displayToolBarButtons5->Run = displayToolBarButton93;
			displayToolBarButton94->Image = displayToolBarButtonImage94;
			displayToolBarButtons5->Save = displayToolBarButton94;
			displayToolBarButton95->Image = displayToolBarButtonImage95;
			displayToolBarButtons5->Setup = displayToolBarButton95;
			displayToolBarButtons5->Size = toolBarButtonSize13;
			displayToolBarButton96->Image = displayToolBarButtonImage96;
			displayToolBarButtons5->XYZoomOn = displayToolBarButton96;
			displayToolBarButton97->Image = displayToolBarButtonImage97;
			displayToolBarButtons5->ZoomIn = displayToolBarButton97;
			displayToolBarButton98->Image = displayToolBarButtonImage98;
			displayToolBarButtons5->ZoomMode = displayToolBarButton98;
			displayToolBarButton99->Image = displayToolBarButtonImage99;
			displayToolBarButtons5->ZoomNext = displayToolBarButton99;
			displayToolBarButton100->Image = displayToolBarButtonImage100;
			displayToolBarButtons5->ZoomOff = displayToolBarButton100;
			displayToolBarButton101->Image = displayToolBarButtonImage101;
			displayToolBarButtons5->ZoomOut = displayToolBarButton101;
			displayToolBarButton102->Image = displayToolBarButtonImage102;
			displayToolBarButtons5->ZoomPrevious = displayToolBarButton102;
			displayToolBar5->Buttons = displayToolBarButtons5;
			displayToolBar5->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar5->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition5.InternalData")));
			displayToolBar5->Position = toolBarPosition5;
			this->VCurveScope->ToolBar = displayToolBar5;
			displayTrails5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->VCurveScope->Trails = displayTrails5;
			displayTitleLabel9->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel9->Text = L"Focus Position";
			scopeXAxis5->AxisLabel = displayTitleLabel9;
			displayViewBackground24->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis5->Background = displayViewBackground24;
			viewButtonSettings9->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings9->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings9->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings9->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings9->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis5->Button = viewButtonSettings9;
			scopeXAxis5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis5->CursorSettings = displayAxisCursorSettings9;
			vclPen22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen22->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen22.InternalData")));
			displayGridLineSettings22->Pen = vclPen22;
			displayGridDirectionalLinesSettings9->Lines = displayGridLineSettings22;
			vclPen23->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen23->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen23.InternalData")));
			displayGridLineSettings23->Pen = vclPen23;
			displayGridDirectionalLinesSettings9->ZeroLine = displayGridLineSettings23;
			scopeXAxis5->DataView = displayGridDirectionalLinesSettings9;
			scopeXAxis5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat9->Precision = 3;
			scopeXAxis5->Format = axisFormat9;
			scopeXAxis5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis5.InternalData")));
			ticksStart9->StartFrom = 0;
			majorTicks9->StartFrom = ticksStart9;
			majorTicks9->Step = 10;
			scopeXAxis5->MajorTicks = majorTicks9;
			maxAxisValue9->DataValue = 1024;
			displayOptionalValue49->Enabled = false;
			displayOptionalValue49->Value = 1000;
			displayValueRange25->High = displayOptionalValue49;
			displayOptionalValue50->Enabled = false;
			displayOptionalValue50->Value = -1000;
			displayValueRange25->Low = displayOptionalValue50;
			maxAxisValue9->Range = displayValueRange25;
			basicAxisValue17->Value = 1024;
			maxAxisValue9->Tick = basicAxisValue17;
			maxAxisValue9->Value = 1024;
			scopeXAxis5->Max = maxAxisValue9;
			scopeMaxSample5->Value = static_cast<System::UInt32>(1024);
			scopeXAxis5->MaxSample = scopeMaxSample5;
			axisValue9->DataValue = 0;
			displayOptionalValue51->Enabled = false;
			displayOptionalValue51->Value = 1000;
			displayValueRange26->High = displayOptionalValue51;
			displayOptionalValue52->Enabled = false;
			displayOptionalValue52->Value = -1000;
			displayValueRange26->Low = displayOptionalValue52;
			axisValue9->Range = displayValueRange26;
			basicAxisValue18->Value = 0;
			axisValue9->Tick = basicAxisValue18;
			axisValue9->Value = 0;
			scopeXAxis5->Min = axisValue9;
			scopeXAxis5->MinorTicks = minorTicks9;
			axisToolBar9->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons9->Size = toolBarButtonSize14;
			displayToolBarButton103->Image = displayToolBarButtonImage103;
			axisToolBarButtons9->ZoomIn = displayToolBarButton103;
			displayToolBarButton104->Image = displayToolBarButtonImage104;
			axisToolBarButtons9->ZoomOff = displayToolBarButton104;
			displayToolBarButton105->Image = displayToolBarButtonImage105;
			axisToolBarButtons9->ZoomOneDir = displayToolBarButton105;
			displayToolBarButton106->Image = displayToolBarButtonImage106;
			axisToolBarButtons9->ZoomOut = displayToolBarButton106;
			axisToolBar9->Buttons = axisToolBarButtons9;
			axisToolBar9->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar9->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis5->ToolBar = axisToolBar9;
			scopeXAxis5->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis5->UnitScale = scopeXAxisUnitScale5;
			displayViewSize19->Size = static_cast<System::UInt32>(100);
			scopeXAxis5->ViewSize = displayViewSize19;
			displayOptionalValue53->Enabled = false;
			displayOptionalValue53->Value = 100000000;
			displayValueRange27->High = displayOptionalValue53;
			displayOptionalValue54->Enabled = true;
			displayOptionalValue54->Value = 1E-07;
			displayValueRange27->Low = displayOptionalValue54;
			displayAxisZoom9->Range = displayValueRange27;
			scopeXAxis5->Zooming = displayAxisZoom9;
			scopeXAxis5->ZoomPin = statePin9;
			this->VCurveScope->XAxis = scopeXAxis5;
			this->VCurveScope->XInputPins = pinList10;
			scopeAutoScaling5->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace9->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace9->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling5->SpaceAbove = scopeAutoScalingSpace9;
			scopeAutoScalingSpace10->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace10->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling5->SpaceBelow = scopeAutoScalingSpace10;
			scopeYAxis5->AutoScaling = scopeAutoScaling5;
			displayTitleLabel10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel10->Text = L"Half Flux Diameter (Pixels)";
			scopeYAxis5->AxisLabel = displayTitleLabel10;
			displayViewBackground25->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis5->Background = displayViewBackground25;
			viewButtonSettings10->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings10->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings10->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings10->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings10->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis5->Button = viewButtonSettings10;
			scopeYAxis5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis5->CursorSettings = displayAxisCursorSettings10;
			vclPen24->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen24->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen24.InternalData")));
			displayGridLineSettings24->Pen = vclPen24;
			displayGridDirectionalLinesSettings10->Lines = displayGridLineSettings24;
			vclPen25->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen25->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen25.InternalData")));
			displayGridLineSettings25->Pen = vclPen25;
			displayGridDirectionalLinesSettings10->ZeroLine = displayGridLineSettings25;
			scopeYAxis5->DataView = displayGridDirectionalLinesSettings10;
			scopeYAxis5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat10->Precision = 3;
			scopeYAxis5->Format = axisFormat10;
			scopeYAxis5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis5.InternalData")));
			ticksStart10->StartFrom = 0;
			majorTicks10->StartFrom = ticksStart10;
			majorTicks10->Step = 10;
			scopeYAxis5->MajorTicks = majorTicks10;
			maxAxisValue10->DataValue = 1000;
			displayOptionalValue55->Enabled = false;
			displayOptionalValue55->Value = 1000;
			displayValueRange28->High = displayOptionalValue55;
			displayOptionalValue56->Enabled = false;
			displayOptionalValue56->Value = -1000;
			displayValueRange28->Low = displayOptionalValue56;
			maxAxisValue10->Range = displayValueRange28;
			basicAxisValue19->Value = 0;
			maxAxisValue10->Tick = basicAxisValue19;
			maxAxisValue10->Value = 1000;
			scopeYAxis5->Max = maxAxisValue10;
			axisValue10->DataValue = -1000;
			displayOptionalValue57->Enabled = false;
			displayOptionalValue57->Value = 1000;
			displayValueRange29->High = displayOptionalValue57;
			displayOptionalValue58->Enabled = false;
			displayOptionalValue58->Value = -1000;
			displayValueRange29->Low = displayOptionalValue58;
			axisValue10->Range = displayValueRange29;
			basicAxisValue20->Value = 0;
			axisValue10->Tick = basicAxisValue20;
			axisValue10->Value = -1000;
			scopeYAxis5->Min = axisValue10;
			scopeYAxis5->MinorTicks = minorTicks10;
			axisToolBar10->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons10->Size = toolBarButtonSize15;
			displayToolBarButton107->Image = displayToolBarButtonImage107;
			axisToolBarButtons10->ZoomIn = displayToolBarButton107;
			displayToolBarButton108->Image = displayToolBarButtonImage108;
			axisToolBarButtons10->ZoomOff = displayToolBarButton108;
			displayToolBarButton109->Image = displayToolBarButtonImage109;
			axisToolBarButtons10->ZoomOneDir = displayToolBarButton109;
			displayToolBarButton110->Image = displayToolBarButtonImage110;
			axisToolBarButtons10->ZoomOut = displayToolBarButton110;
			axisToolBar10->Buttons = axisToolBarButtons10;
			axisToolBar10->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar10->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis5->ToolBar = axisToolBar10;
			scopeYAxis5->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize20->Size = static_cast<System::UInt32>(100);
			scopeYAxis5->ViewSize = displayViewSize20;
			displayOptionalValue59->Enabled = false;
			displayOptionalValue59->Value = 100000000;
			displayValueRange30->High = displayOptionalValue59;
			displayOptionalValue60->Enabled = true;
			displayOptionalValue60->Value = 1E-07;
			displayValueRange30->Low = displayOptionalValue60;
			displayAxisZoom10->Range = displayValueRange30;
			scopeYAxis5->Zooming = displayAxisZoom10;
			scopeYAxis5->ZoomPin = statePin10;
			this->VCurveScope->YAxis = scopeYAxis5;
			displayZoom5->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->VCurveScope->Zooming = displayZoom5;
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
			displayViewBackground26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView6->Background = displayViewBackground26;
			vclPen26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen26->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen26.InternalData")));
			displayGridLineSettings26->Pen = vclPen26;
			scopeDataView6->Border = displayGridLineSettings26;
			this->CalStarProfileScope->DataView = scopeDataView6;
			channelItemHighlighting11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->ChannelLinks = channelItemHighlighting11;
			channelItemHighlighting12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->Channels = channelItemHighlighting12;
			displayItemHighlighting31->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->CursorLinks = displayItemHighlighting31;
			displayItemHighlighting32->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->Cursors = displayItemHighlighting32;
			displayItemHighlighting33->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->Ellipses = displayItemHighlighting33;
			displayItemHighlighting34->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->Labels = displayItemHighlighting34;
			displayItemHighlighting35->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->Markers = displayItemHighlighting35;
			channelMouseHitPoint6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint6->PointLabel = optionalLabel6;
			dataChartHighlighting6->MouseHitPoint = channelMouseHitPoint6;
			displayItemHighlighting36->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting6->Zones = displayItemHighlighting36;
			this->CalStarProfileScope->Highlighting = dataChartHighlighting6;
			this->CalStarProfileScope->InputPins = pinList11;
			this->CalStarProfileScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"CalStarProfileScope.InternalData")));
			displayViewBackground27->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView6->Background = displayViewBackground27;
			legendViewButtonSettings6->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings6->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView6->Buttons = legendViewButtonSettings6;
			displayLabel41->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup41->Caption = displayLabel41;
			legendGroup41->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->ChannelLinks = legendGroup41;
			displayLabel42->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup42->Caption = displayLabel42;
			legendGroup42->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->Channels = legendGroup42;
			displayLabel43->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup43->Caption = displayLabel43;
			legendGroup43->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->CursorLinks = legendGroup43;
			displayLabel44->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup44->Caption = displayLabel44;
			legendGroup44->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->Cursors = legendGroup44;
			displayLabel45->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup45->Caption = displayLabel45;
			legendGroup45->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->Ellipses = legendGroup45;
			scopeLegendView6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView6.InternalData")));
			displayLabel46->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup46->Caption = displayLabel46;
			legendGroup46->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->Labels = legendGroup46;
			displayLabel47->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup47->Caption = displayLabel47;
			legendGroup47->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->MarkerGroups = legendGroup47;
			displayViewSize21->Size = static_cast<System::UInt32>(100);
			scopeLegendView6->ViewSize = displayViewSize21;
			displayLabel48->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup48->Caption = displayLabel48;
			legendGroup48->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView6->Zones = legendGroup48;
			this->CalStarProfileScope->Legend = scopeLegendView6;
			this->CalStarProfileScope->Location = System::Drawing::Point(3, 165);
			this->CalStarProfileScope->Name = L"CalStarProfileScope";
			this->CalStarProfileScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->CalStarProfileScope->Size = System::Drawing::Size(291, 191);
			this->CalStarProfileScope->SizeLimit = static_cast<System::UInt32>(0);
			this->CalStarProfileScope->TabIndex = 1;
			this->CalStarProfileScope->Text = L"scope1";
			displayViewBackground28->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle6->Background = displayViewBackground28;
			displayTitle6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 13, 1));
			displayTitle6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle6.InternalData")));
			displayTitle6->Text = L"Star Profile";
			displayViewSize22->Size = static_cast<System::UInt32>(100);
			displayTitle6->ViewSize = displayViewSize22;
			this->CalStarProfileScope->Title = displayTitle6;
			displayToolBar6->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton111->Image = displayToolBarButtonImage111;
			displayToolBarButtons6->Copy = displayToolBarButton111;
			displayToolBarButton112->Image = displayToolBarButtonImage112;
			displayToolBarButtons6->Hold = displayToolBarButton112;
			displayToolBarButton113->Image = displayToolBarButtonImage113;
			displayToolBarButtons6->PanMode = displayToolBarButton113;
			displayToolBarButton114->Image = displayToolBarButtonImage114;
			displayToolBarButtons6->Print = displayToolBarButton114;
			displayToolBarButton115->Image = displayToolBarButtonImage115;
			displayToolBarButtons6->Run = displayToolBarButton115;
			displayToolBarButton116->Image = displayToolBarButtonImage116;
			displayToolBarButtons6->Save = displayToolBarButton116;
			displayToolBarButton117->Image = displayToolBarButtonImage117;
			displayToolBarButtons6->Setup = displayToolBarButton117;
			displayToolBarButtons6->Size = toolBarButtonSize16;
			displayToolBarButton118->Image = displayToolBarButtonImage118;
			displayToolBarButtons6->XYZoomOn = displayToolBarButton118;
			displayToolBarButton119->Image = displayToolBarButtonImage119;
			displayToolBarButtons6->ZoomIn = displayToolBarButton119;
			displayToolBarButton120->Image = displayToolBarButtonImage120;
			displayToolBarButtons6->ZoomMode = displayToolBarButton120;
			displayToolBarButton121->Image = displayToolBarButtonImage121;
			displayToolBarButtons6->ZoomNext = displayToolBarButton121;
			displayToolBarButton122->Image = displayToolBarButtonImage122;
			displayToolBarButtons6->ZoomOff = displayToolBarButton122;
			displayToolBarButton123->Image = displayToolBarButtonImage123;
			displayToolBarButtons6->ZoomOut = displayToolBarButton123;
			displayToolBarButton124->Image = displayToolBarButtonImage124;
			displayToolBarButtons6->ZoomPrevious = displayToolBarButton124;
			displayToolBar6->Buttons = displayToolBarButtons6;
			displayToolBar6->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar6->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition6.InternalData")));
			displayToolBar6->Position = toolBarPosition6;
			this->CalStarProfileScope->ToolBar = displayToolBar6;
			displayTrails6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->CalStarProfileScope->Trails = displayTrails6;
			displayTitleLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel11->Text = L"Crossection (pixels)";
			scopeXAxis6->AxisLabel = displayTitleLabel11;
			displayViewBackground29->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis6->Background = displayViewBackground29;
			viewButtonSettings11->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings11->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings11->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings11->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings11->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis6->Button = viewButtonSettings11;
			scopeXAxis6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis6->CursorSettings = displayAxisCursorSettings11;
			vclPen27->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen27->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen27.InternalData")));
			displayGridLineSettings27->Pen = vclPen27;
			displayGridDirectionalLinesSettings11->Lines = displayGridLineSettings27;
			vclPen28->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen28->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen28.InternalData")));
			displayGridLineSettings28->Pen = vclPen28;
			displayGridDirectionalLinesSettings11->ZeroLine = displayGridLineSettings28;
			scopeXAxis6->DataView = displayGridDirectionalLinesSettings11;
			scopeXAxis6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat11->Precision = 3;
			scopeXAxis6->Format = axisFormat11;
			scopeXAxis6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis6.InternalData")));
			ticksStart11->StartFrom = 0;
			majorTicks11->StartFrom = ticksStart11;
			majorTicks11->Step = 10;
			scopeXAxis6->MajorTicks = majorTicks11;
			maxAxisValue11->DataValue = 1024;
			displayOptionalValue61->Enabled = false;
			displayOptionalValue61->Value = 1000;
			displayValueRange31->High = displayOptionalValue61;
			displayOptionalValue62->Enabled = false;
			displayOptionalValue62->Value = -1000;
			displayValueRange31->Low = displayOptionalValue62;
			maxAxisValue11->Range = displayValueRange31;
			basicAxisValue21->Value = 1024;
			maxAxisValue11->Tick = basicAxisValue21;
			maxAxisValue11->Value = 1024;
			scopeXAxis6->Max = maxAxisValue11;
			scopeMaxSample6->Value = static_cast<System::UInt32>(1024);
			scopeXAxis6->MaxSample = scopeMaxSample6;
			axisValue11->DataValue = 0;
			displayOptionalValue63->Enabled = false;
			displayOptionalValue63->Value = 1000;
			displayValueRange32->High = displayOptionalValue63;
			displayOptionalValue64->Enabled = false;
			displayOptionalValue64->Value = -1000;
			displayValueRange32->Low = displayOptionalValue64;
			axisValue11->Range = displayValueRange32;
			basicAxisValue22->Value = 0;
			axisValue11->Tick = basicAxisValue22;
			axisValue11->Value = 0;
			scopeXAxis6->Min = axisValue11;
			scopeXAxis6->MinorTicks = minorTicks11;
			axisToolBar11->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons11->Size = toolBarButtonSize17;
			displayToolBarButton125->Image = displayToolBarButtonImage125;
			axisToolBarButtons11->ZoomIn = displayToolBarButton125;
			displayToolBarButton126->Image = displayToolBarButtonImage126;
			axisToolBarButtons11->ZoomOff = displayToolBarButton126;
			displayToolBarButton127->Image = displayToolBarButtonImage127;
			axisToolBarButtons11->ZoomOneDir = displayToolBarButton127;
			displayToolBarButton128->Image = displayToolBarButtonImage128;
			axisToolBarButtons11->ZoomOut = displayToolBarButton128;
			axisToolBar11->Buttons = axisToolBarButtons11;
			axisToolBar11->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar11->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis6->ToolBar = axisToolBar11;
			scopeXAxis6->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis6->UnitScale = scopeXAxisUnitScale6;
			displayViewSize23->Size = static_cast<System::UInt32>(100);
			scopeXAxis6->ViewSize = displayViewSize23;
			displayOptionalValue65->Enabled = false;
			displayOptionalValue65->Value = 100000000;
			displayValueRange33->High = displayOptionalValue65;
			displayOptionalValue66->Enabled = true;
			displayOptionalValue66->Value = 1E-07;
			displayValueRange33->Low = displayOptionalValue66;
			displayAxisZoom11->Range = displayValueRange33;
			scopeXAxis6->Zooming = displayAxisZoom11;
			scopeXAxis6->ZoomPin = statePin11;
			this->CalStarProfileScope->XAxis = scopeXAxis6;
			this->CalStarProfileScope->XInputPins = pinList12;
			scopeAutoScaling6->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace11->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace11->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling6->SpaceAbove = scopeAutoScalingSpace11;
			scopeAutoScalingSpace12->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace12->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling6->SpaceBelow = scopeAutoScalingSpace12;
			scopeYAxis6->AutoScaling = scopeAutoScaling6;
			displayTitleLabel12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel12->Text = L"Pixel Value (ADU)";
			scopeYAxis6->AxisLabel = displayTitleLabel12;
			displayViewBackground30->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis6->Background = displayViewBackground30;
			viewButtonSettings12->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings12->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings12->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings12->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings12->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis6->Button = viewButtonSettings12;
			scopeYAxis6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis6->CursorSettings = displayAxisCursorSettings12;
			vclPen29->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen29->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen29.InternalData")));
			displayGridLineSettings29->Pen = vclPen29;
			displayGridDirectionalLinesSettings12->Lines = displayGridLineSettings29;
			vclPen30->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen30->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen30.InternalData")));
			displayGridLineSettings30->Pen = vclPen30;
			displayGridDirectionalLinesSettings12->ZeroLine = displayGridLineSettings30;
			scopeYAxis6->DataView = displayGridDirectionalLinesSettings12;
			scopeYAxis6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat12->Precision = 3;
			scopeYAxis6->Format = axisFormat12;
			scopeYAxis6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis6.InternalData")));
			ticksStart12->StartFrom = 0;
			majorTicks12->StartFrom = ticksStart12;
			majorTicks12->Step = 10;
			scopeYAxis6->MajorTicks = majorTicks12;
			maxAxisValue12->DataValue = 1000;
			displayOptionalValue67->Enabled = false;
			displayOptionalValue67->Value = 1000;
			displayValueRange34->High = displayOptionalValue67;
			displayOptionalValue68->Enabled = false;
			displayOptionalValue68->Value = -1000;
			displayValueRange34->Low = displayOptionalValue68;
			maxAxisValue12->Range = displayValueRange34;
			basicAxisValue23->Value = 0;
			maxAxisValue12->Tick = basicAxisValue23;
			maxAxisValue12->Value = 1000;
			scopeYAxis6->Max = maxAxisValue12;
			axisValue12->DataValue = -1000;
			displayOptionalValue69->Enabled = false;
			displayOptionalValue69->Value = 1000;
			displayValueRange35->High = displayOptionalValue69;
			displayOptionalValue70->Enabled = false;
			displayOptionalValue70->Value = -1000;
			displayValueRange35->Low = displayOptionalValue70;
			axisValue12->Range = displayValueRange35;
			basicAxisValue24->Value = 0;
			axisValue12->Tick = basicAxisValue24;
			axisValue12->Value = -1000;
			scopeYAxis6->Min = axisValue12;
			scopeYAxis6->MinorTicks = minorTicks12;
			axisToolBar12->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons12->Size = toolBarButtonSize18;
			displayToolBarButton129->Image = displayToolBarButtonImage129;
			axisToolBarButtons12->ZoomIn = displayToolBarButton129;
			displayToolBarButton130->Image = displayToolBarButtonImage130;
			axisToolBarButtons12->ZoomOff = displayToolBarButton130;
			displayToolBarButton131->Image = displayToolBarButtonImage131;
			axisToolBarButtons12->ZoomOneDir = displayToolBarButton131;
			displayToolBarButton132->Image = displayToolBarButtonImage132;
			axisToolBarButtons12->ZoomOut = displayToolBarButton132;
			axisToolBar12->Buttons = axisToolBarButtons12;
			axisToolBar12->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar12->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis6->ToolBar = axisToolBar12;
			scopeYAxis6->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize24->Size = static_cast<System::UInt32>(100);
			scopeYAxis6->ViewSize = displayViewSize24;
			displayOptionalValue71->Enabled = false;
			displayOptionalValue71->Value = 100000000;
			displayValueRange36->High = displayOptionalValue71;
			displayOptionalValue72->Enabled = true;
			displayOptionalValue72->Value = 1E-07;
			displayValueRange36->Low = displayOptionalValue72;
			displayAxisZoom12->Range = displayValueRange36;
			scopeYAxis6->Zooming = displayAxisZoom12;
			scopeYAxis6->ZoomPin = statePin12;
			this->CalStarProfileScope->YAxis = scopeYAxis6;
			displayZoom6->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->CalStarProfileScope->Zooming = displayZoom6;
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
			this->tableLayoutPanel11->Controls->Add(this->AbortButton, 2, 0);
			this->tableLayoutPanel11->Controls->Add(this->PauseButton, 1, 0);
			this->tableLayoutPanel11->Controls->Add(this->StartButton, 0, 0);
			this->tableLayoutPanel11->Location = System::Drawing::Point(316, 3);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(278, 31);
			this->tableLayoutPanel11->TabIndex = 3;
			// 
			// AbortButton
			// 
			this->AbortButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AbortButton->BackColor = System::Drawing::Color::Red;
			this->AbortButton->Location = System::Drawing::Point(194, 4);
			this->AbortButton->Name = L"AbortButton";
			this->AbortButton->Size = System::Drawing::Size(75, 23);
			this->AbortButton->TabIndex = 2;
			this->AbortButton->Text = L"Abort";
			this->AbortButton->UseVisualStyleBackColor = false;
			this->AbortButton->Click += gcnew System::EventHandler(this, &AutoFocusDialog::AbortButton_Click);
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
		if (AutoFocusDialog::FormPtr->OnVCurveLeftRadioButton->Checked)
			autoFocusSettings.StartingVCurveSide = -1;
		else if (AutoFocusDialog::FormPtr->OnVCurveRightRadioButton->Checked)
			autoFocusSettings.StartingVCurveSide = 1;
		else
			autoFocusSettings.StartingVCurveSide = 0;

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

	public: static void SetFocusPositionTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->FocuserPositionTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetFocusPositionTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->FocuserPositionTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetStarXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->StarXTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetStarXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->StarXTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetStarYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->StarYTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetStarYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->StarYTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetStarMaxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->StarMaxTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetStarMaxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->StarMaxTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetStarHFDTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->StarHFDTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetStarHFDTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->StarHFDTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetXTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->XTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetXTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->XTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetYTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->YTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetYTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->YTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetMaxTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->MaxTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetMaxTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->MaxTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
	}


	public: static void SetHFDTextBox(char *text) {
		String ^buffer;
		buffer = gcnew String(text);
		AutoFocusDialog::FormPtr->HFDTextBox->Text = buffer;
		delete buffer;
	}


	public: static void GetHFDTextBox(char *text) {
		int i;
		String ^buffer;
		buffer = gcnew String("");
		buffer = AutoFocusDialog::FormPtr->HFDTextBox->Text;
		for (i = 0; i<buffer->Length; i++) text[i] = (char)buffer[i];
		text[i] = 0;
		delete buffer;
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

		this->PauseRequested = !this->PauseRequested;
	}


	public: static System::Void PlotStarPSF(PIXCELL *pixList) {

		PIXCELL *pptr;

		if (AutoFocusDialog::FormPtr->StarProfileScope->Channels->Count == 0) {
			AutoFocusDialog::FormPtr->StarProfileScope->XAxis->AxisLabel->Text = "Pixel Distance (pixels)";
			AutoFocusDialog::FormPtr->StarProfileScope->YAxis->AxisLabel->Text = "Pixel Value (adu)";
			AutoFocusDialog::FormPtr->StarProfileScope->Title->Text = "Current Star Profile";
			AutoFocusDialog::FormPtr->StarProfileScope->Channels->Add(1);
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Name = "Star Profile";
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Color = System::Drawing::Color::DarkMagenta;
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Points->Shape = Mitov::PlotLab::ScopePointsShape::Cross;
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Points->Visible = true;
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->ChannelMode = Mitov::PlotLab::ScopeChannelMode::Point;
		}

		AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Data->Clear();

		pptr = pixList;
		while (pptr != NULL) {
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Data->AddXYPoint(pptr->r, pptr->val);
			pptr = pptr->next;
		}

		AutoFocusDialog::FormPtr->Refresh();

	}

	public: static System::Void PlotCalStarPSF(PIXCELL *pixList) {

		PIXCELL *pptr;

		if (AutoFocusDialog::FormPtr->CalStarProfileScope->Channels->Count == 0) {
			AutoFocusDialog::FormPtr->CalStarProfileScope->XAxis->AxisLabel->Text = "Pixel Distance (pixels)";
			AutoFocusDialog::FormPtr->CalStarProfileScope->YAxis->AxisLabel->Text = "Pixel Value (adu)";
			AutoFocusDialog::FormPtr->CalStarProfileScope->Title->Text = "Current Star Profile";
			AutoFocusDialog::FormPtr->CalStarProfileScope->Channels->Add(1);
			AutoFocusDialog::FormPtr->CalStarProfileScope->Channels[0]->Name = "Star Profile";
			AutoFocusDialog::FormPtr->CalStarProfileScope->Channels[0]->Color = System::Drawing::Color::DarkMagenta;
			AutoFocusDialog::FormPtr->CalStarProfileScope->Channels[0]->Points->Shape = Mitov::PlotLab::ScopePointsShape::Cross;
			AutoFocusDialog::FormPtr->CalStarProfileScope->Channels[0]->Points->Visible = true;
			AutoFocusDialog::FormPtr->CalStarProfileScope->Channels[0]->ChannelMode = Mitov::PlotLab::ScopeChannelMode::Point;
		}

		AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Data->Clear();

		pptr = pixList;
		while (pptr != NULL) {
			AutoFocusDialog::FormPtr->StarProfileScope->Channels[0]->Data->AddXYPoint(pptr->r, pptr->val);
			pptr = pptr->next;
		}

		AutoFocusDialog::FormPtr->Refresh();

	}


	public: static System::Void AddPointVCurve(double focuserPosition, double halfFluxDiameter) {


		if (AutoFocusDialog::FormPtr->VCurveScope->Channels->Count == 0) {
			AutoFocusDialog::FormPtr->VCurveScope->XAxis->AxisLabel->Text = "Focuser Position (steps)";
			AutoFocusDialog::FormPtr->VCurveScope->YAxis->AxisLabel->Text = "Half Flux Diameter (pixels)";
			AutoFocusDialog::FormPtr->VCurveScope->Title->Text = "Calibration V Curve";
			AutoFocusDialog::FormPtr->VCurveScope->Channels->Add(1);
			AutoFocusDialog::FormPtr->VCurveScope->Channels[0]->Name = "V Curve Data";
			AutoFocusDialog::FormPtr->VCurveScope->Channels[0]->Color = System::Drawing::Color::DarkViolet;
			AutoFocusDialog::FormPtr->VCurveScope->Channels[0]->Points->Shape = Mitov::PlotLab::ScopePointsShape::Circle;
			AutoFocusDialog::FormPtr->VCurveScope->Channels[0]->Points->Visible = true;
			AutoFocusDialog::FormPtr->VCurveScope->Channels[0]->ChannelMode = Mitov::PlotLab::ScopeChannelMode::Point;
		}

		AutoFocusDialog::FormPtr->VCurveScope->Channels[0]->Data->AddXYPoint(focuserPosition, halfFluxDiameter);

		AutoFocusDialog::FormPtr->Refresh();

	}

	private: System::Void AbortButton_Click(System::Object^  sender, System::EventArgs^  e) {

		this->AbortRequested = true;
	}

};
}
