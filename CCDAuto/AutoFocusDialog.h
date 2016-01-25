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
	private: System::Windows::Forms::TextBox^  FocusStartPosTextBox;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  FocusStepSizeTextBox;
	private: System::Windows::Forms::TextBox^  FocusEndPosTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  MaxPeakTextBox;
	private: System::Windows::Forms::TextBox^  MinPeakTextBox;
	private: System::Windows::Forms::TextBox^  FieldSizeTextBox;
	private: System::Windows::Forms::TextBox^  CalNumFramesPerPointTextBox;

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
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  NumFramesPerPointTextBox;
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
			Mitov::PlotLab::ScopeDataView^  scopeDataView10 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground46 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings46 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen46 = (gcnew Vcl::VclPen());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AutoFocusDialog::typeid));
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting10 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting19 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting20 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting55 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting56 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting57 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting58 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting59 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint10 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel10 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting60 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList19 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView10 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground47 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings10 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup73 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel73 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup74 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel74 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup75 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel75 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup76 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel76 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup77 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel77 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup78 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel78 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup79 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel79 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize37 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup80 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel80 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle10 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground48 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize38 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar10 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons10 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton199 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage199 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton200 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage200 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton201 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage201 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton202 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage202 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton203 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage203 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton204 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage204 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton205 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage205 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize28 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton206 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage206 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton207 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage207 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton208 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage208 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton209 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage209 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton210 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage210 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton211 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage211 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton212 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage212 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition10 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails10 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis10 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel19 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground49 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings19 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings19 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings19 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings47 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen47 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings48 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen48 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat19 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks19 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart19 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue19 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange55 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue109 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue110 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue37 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample10 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue19 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange56 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue111 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue112 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue38 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks19 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar19 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons19 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize29 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton213 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage213 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton214 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage214 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton215 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage215 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton216 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage216 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale10 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize39 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom19 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange57 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue113 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue114 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin19 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList20 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis10 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling10 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace19 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace20 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel20 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground50 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings20 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings20 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings20 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings49 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen49 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings50 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen50 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat20 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks20 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart20 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue20 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange58 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue115 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue116 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue39 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue20 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange59 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue117 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue118 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue40 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks20 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar20 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons20 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize30 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton217 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage217 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton218 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage218 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton219 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage219 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton220 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage220 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize40 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom20 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange60 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue119 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue120 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin20 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom10 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView11 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground51 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings51 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen51 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting11 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting21 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting22 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting61 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting62 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting63 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting64 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting65 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint11 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel11 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting66 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList21 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView11 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground52 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings11 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup81 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel81 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup82 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel82 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup83 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel83 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup84 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel84 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup85 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel85 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup86 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel86 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup87 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel87 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize41 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup88 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel88 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle11 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground53 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize42 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar11 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons11 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton221 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage221 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton222 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage222 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton223 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage223 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton224 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage224 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton225 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage225 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton226 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage226 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton227 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage227 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize31 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton228 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage228 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton229 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage229 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton230 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage230 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton231 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage231 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton232 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage232 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton233 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage233 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton234 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage234 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition11 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails11 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis11 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel21 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground54 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings21 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings21 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings21 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings52 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen52 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings53 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen53 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat21 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks21 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart21 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue21 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange61 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue121 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue122 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue41 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample11 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue21 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange62 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue123 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue124 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue42 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks21 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar21 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons21 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize32 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton235 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage235 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton236 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage236 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton237 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage237 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton238 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage238 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale11 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize43 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom21 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange63 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue125 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue126 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin21 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList22 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis11 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling11 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace21 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace22 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel22 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground55 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings22 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings22 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings22 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings54 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen54 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings55 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen55 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat22 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks22 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart22 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue22 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange64 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue127 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue128 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue43 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue22 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange65 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue129 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue130 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue44 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks22 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar22 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons22 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize33 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton239 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage239 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton240 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage240 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton241 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage241 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton242 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage242 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize44 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom22 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange66 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue131 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue132 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin22 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom11 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView12 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground56 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings56 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen56 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataChartHighlighting^  dataChartHighlighting12 = (gcnew Mitov::PlotLab::DataChartHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting23 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting24 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting67 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting68 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting69 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting70 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting71 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint12 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::BasicLab::OptionalLabel^  optionalLabel12 = (gcnew Mitov::BasicLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting72 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList23 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView12 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground57 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings12 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup89 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel89 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup90 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel90 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup91 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel91 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup92 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel92 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup93 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel93 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup94 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel94 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup95 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel95 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize45 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup96 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel96 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle12 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground58 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize46 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar12 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons12 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton243 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage243 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton244 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage244 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton245 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage245 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton246 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage246 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton247 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage247 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton248 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage248 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton249 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage249 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize34 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton250 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage250 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton251 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage251 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton252 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage252 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton253 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage253 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton254 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage254 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton255 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage255 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton256 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage256 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition12 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails12 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis12 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel23 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground59 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings23 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings23 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings23 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings57 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen57 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings58 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen58 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat23 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks23 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart23 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue23 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange67 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue133 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue134 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue45 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample12 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue23 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange68 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue135 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue136 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue46 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks23 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar23 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons23 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize35 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton257 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage257 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton258 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage258 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton259 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage259 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton260 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage260 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale12 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize47 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom23 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange69 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue137 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue138 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin23 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList24 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis12 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling12 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace23 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace24 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel24 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground60 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings24 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings24 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings24 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings59 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen59 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings60 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen60 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat24 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks24 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart24 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue24 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange70 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue139 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue140 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue47 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue24 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange71 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue141 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue142 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue48 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks24 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar24 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons24 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::ToolBarButtonSize^  toolBarButtonSize36 = (gcnew Mitov::PlotLab::ToolBarButtonSize());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton261 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage261 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton262 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage262 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton263 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage263 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton264 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButtonImage^  displayToolBarButtonImage264 = (gcnew Mitov::PlotLab::DisplayToolBarButtonImage());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize48 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom24 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange72 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue143 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue144 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin24 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom12 = (gcnew Mitov::PlotLab::DisplayZoom());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->VCurveScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->XTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalFocusFramePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->CalStarProfileScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalNumFramesPerPointTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->MaxPeakTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->FocusStepSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FocusStartPosTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->FocusEndPosTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->MinPeakTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FieldSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->YTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HFDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->NumPointsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LeftSlopeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RightSlopeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VertexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StarProfileScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->FocusFramePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->NumFramesPerPointTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->CalFocuserPositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->StarXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarMaxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->StarHFDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->FocuserPositionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->FrameNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->CalFrameNumTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCurveScope))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFocusFramePictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStarProfileScope))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StarProfileScope))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FocusFramePictureBox))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->tableLayoutPanel12->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 94.61539F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5.384615F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(633, 650);
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
			this->tabControl->Size = System::Drawing::Size(627, 609);
			this->tabControl->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox5);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(619, 583);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Auto Focus";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tableLayoutPanel3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(619, 583);
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
			this->tableLayoutPanel3->Size = System::Drawing::Size(613, 577);
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
			this->tableLayoutPanel4->Size = System::Drawing::Size(607, 472);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// VCurveScope
			// 
			this->VCurveScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground46->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView10->Background = displayViewBackground46;
			vclPen46->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen46->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen46.InternalData")));
			displayGridLineSettings46->Pen = vclPen46;
			scopeDataView10->Border = displayGridLineSettings46;
			this->VCurveScope->DataView = scopeDataView10;
			this->VCurveScope->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting19->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->ChannelLinks = channelItemHighlighting19;
			channelItemHighlighting20->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->Channels = channelItemHighlighting20;
			displayItemHighlighting55->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->CursorLinks = displayItemHighlighting55;
			displayItemHighlighting56->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->Cursors = displayItemHighlighting56;
			displayItemHighlighting57->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->Ellipses = displayItemHighlighting57;
			displayItemHighlighting58->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->Labels = displayItemHighlighting58;
			displayItemHighlighting59->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->Markers = displayItemHighlighting59;
			channelMouseHitPoint10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint10->PointLabel = optionalLabel10;
			dataChartHighlighting10->MouseHitPoint = channelMouseHitPoint10;
			displayItemHighlighting60->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting10->Zones = displayItemHighlighting60;
			this->VCurveScope->Highlighting = dataChartHighlighting10;
			this->VCurveScope->InputPins = pinList19;
			this->VCurveScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"VCurveScope.InternalData")));
			displayViewBackground47->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView10->Background = displayViewBackground47;
			legendViewButtonSettings10->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings10->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings10->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView10->Buttons = legendViewButtonSettings10;
			displayLabel73->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup73->Caption = displayLabel73;
			legendGroup73->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->ChannelLinks = legendGroup73;
			displayLabel74->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup74->Caption = displayLabel74;
			legendGroup74->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->Channels = legendGroup74;
			displayLabel75->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup75->Caption = displayLabel75;
			legendGroup75->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->CursorLinks = legendGroup75;
			displayLabel76->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup76->Caption = displayLabel76;
			legendGroup76->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->Cursors = legendGroup76;
			displayLabel77->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup77->Caption = displayLabel77;
			legendGroup77->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->Ellipses = legendGroup77;
			scopeLegendView10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView10.InternalData")));
			displayLabel78->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup78->Caption = displayLabel78;
			legendGroup78->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->Labels = legendGroup78;
			displayLabel79->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup79->Caption = displayLabel79;
			legendGroup79->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->MarkerGroups = legendGroup79;
			displayViewSize37->Size = static_cast<System::UInt32>(100);
			scopeLegendView10->ViewSize = displayViewSize37;
			displayLabel80->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup80->Caption = displayLabel80;
			legendGroup80->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView10->Zones = legendGroup80;
			this->VCurveScope->Legend = scopeLegendView10;
			this->VCurveScope->Location = System::Drawing::Point(306, 3);
			this->VCurveScope->Name = L"VCurveScope";
			this->VCurveScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->VCurveScope->Size = System::Drawing::Size(298, 360);
			this->VCurveScope->SizeLimit = static_cast<System::UInt32>(0);
			this->VCurveScope->TabIndex = 0;
			this->VCurveScope->Text = L"V Curve";
			displayViewBackground48->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle10->Background = displayViewBackground48;
			displayTitle10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 13, 1));
			displayTitle10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle10.InternalData")));
			displayTitle10->Text = L"V Curve";
			displayViewSize38->Size = static_cast<System::UInt32>(100);
			displayTitle10->ViewSize = displayViewSize38;
			this->VCurveScope->Title = displayTitle10;
			displayToolBar10->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar10->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton199->Image = displayToolBarButtonImage199;
			displayToolBarButtons10->Copy = displayToolBarButton199;
			displayToolBarButton200->Image = displayToolBarButtonImage200;
			displayToolBarButtons10->Hold = displayToolBarButton200;
			displayToolBarButton201->Image = displayToolBarButtonImage201;
			displayToolBarButtons10->PanMode = displayToolBarButton201;
			displayToolBarButton202->Image = displayToolBarButtonImage202;
			displayToolBarButtons10->Print = displayToolBarButton202;
			displayToolBarButton203->Image = displayToolBarButtonImage203;
			displayToolBarButtons10->Run = displayToolBarButton203;
			displayToolBarButton204->Image = displayToolBarButtonImage204;
			displayToolBarButtons10->Save = displayToolBarButton204;
			displayToolBarButton205->Image = displayToolBarButtonImage205;
			displayToolBarButtons10->Setup = displayToolBarButton205;
			displayToolBarButtons10->Size = toolBarButtonSize28;
			displayToolBarButton206->Image = displayToolBarButtonImage206;
			displayToolBarButtons10->XYZoomOn = displayToolBarButton206;
			displayToolBarButton207->Image = displayToolBarButtonImage207;
			displayToolBarButtons10->ZoomIn = displayToolBarButton207;
			displayToolBarButton208->Image = displayToolBarButtonImage208;
			displayToolBarButtons10->ZoomMode = displayToolBarButton208;
			displayToolBarButton209->Image = displayToolBarButtonImage209;
			displayToolBarButtons10->ZoomNext = displayToolBarButton209;
			displayToolBarButton210->Image = displayToolBarButtonImage210;
			displayToolBarButtons10->ZoomOff = displayToolBarButton210;
			displayToolBarButton211->Image = displayToolBarButtonImage211;
			displayToolBarButtons10->ZoomOut = displayToolBarButton211;
			displayToolBarButton212->Image = displayToolBarButtonImage212;
			displayToolBarButtons10->ZoomPrevious = displayToolBarButton212;
			displayToolBar10->Buttons = displayToolBarButtons10;
			displayToolBar10->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar10->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar10->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar10->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar10->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar10->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar10->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition10.InternalData")));
			displayToolBar10->Position = toolBarPosition10;
			this->VCurveScope->ToolBar = displayToolBar10;
			displayTrails10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->VCurveScope->Trails = displayTrails10;
			displayTitleLabel19->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel19->Text = L"Focus Position";
			scopeXAxis10->AxisLabel = displayTitleLabel19;
			displayViewBackground49->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis10->Background = displayViewBackground49;
			viewButtonSettings19->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings19->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings19->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings19->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings19->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis10->Button = viewButtonSettings19;
			scopeXAxis10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis10->CursorSettings = displayAxisCursorSettings19;
			vclPen47->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen47->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen47.InternalData")));
			displayGridLineSettings47->Pen = vclPen47;
			displayGridDirectionalLinesSettings19->Lines = displayGridLineSettings47;
			vclPen48->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen48->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen48.InternalData")));
			displayGridLineSettings48->Pen = vclPen48;
			displayGridDirectionalLinesSettings19->ZeroLine = displayGridLineSettings48;
			scopeXAxis10->DataView = displayGridDirectionalLinesSettings19;
			scopeXAxis10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat19->Precision = 3;
			scopeXAxis10->Format = axisFormat19;
			scopeXAxis10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis10.InternalData")));
			ticksStart19->StartFrom = 0;
			majorTicks19->StartFrom = ticksStart19;
			majorTicks19->Step = 10;
			scopeXAxis10->MajorTicks = majorTicks19;
			maxAxisValue19->DataValue = 1024;
			displayOptionalValue109->Enabled = false;
			displayOptionalValue109->Value = 1000;
			displayValueRange55->High = displayOptionalValue109;
			displayOptionalValue110->Enabled = false;
			displayOptionalValue110->Value = -1000;
			displayValueRange55->Low = displayOptionalValue110;
			maxAxisValue19->Range = displayValueRange55;
			basicAxisValue37->Value = 1024;
			maxAxisValue19->Tick = basicAxisValue37;
			maxAxisValue19->Value = 1024;
			scopeXAxis10->Max = maxAxisValue19;
			scopeMaxSample10->Value = static_cast<System::UInt32>(1024);
			scopeXAxis10->MaxSample = scopeMaxSample10;
			axisValue19->DataValue = 0;
			displayOptionalValue111->Enabled = false;
			displayOptionalValue111->Value = 1000;
			displayValueRange56->High = displayOptionalValue111;
			displayOptionalValue112->Enabled = false;
			displayOptionalValue112->Value = -1000;
			displayValueRange56->Low = displayOptionalValue112;
			axisValue19->Range = displayValueRange56;
			basicAxisValue38->Value = 0;
			axisValue19->Tick = basicAxisValue38;
			axisValue19->Value = 0;
			scopeXAxis10->Min = axisValue19;
			scopeXAxis10->MinorTicks = minorTicks19;
			axisToolBar19->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar19->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons19->Size = toolBarButtonSize29;
			displayToolBarButton213->Image = displayToolBarButtonImage213;
			axisToolBarButtons19->ZoomIn = displayToolBarButton213;
			displayToolBarButton214->Image = displayToolBarButtonImage214;
			axisToolBarButtons19->ZoomOff = displayToolBarButton214;
			displayToolBarButton215->Image = displayToolBarButtonImage215;
			axisToolBarButtons19->ZoomOneDir = displayToolBarButton215;
			displayToolBarButton216->Image = displayToolBarButtonImage216;
			axisToolBarButtons19->ZoomOut = displayToolBarButton216;
			axisToolBar19->Buttons = axisToolBarButtons19;
			axisToolBar19->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar19->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar19->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar19->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar19->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar19->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar19->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis10->ToolBar = axisToolBar19;
			scopeXAxis10->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis10->UnitScale = scopeXAxisUnitScale10;
			displayViewSize39->Size = static_cast<System::UInt32>(100);
			scopeXAxis10->ViewSize = displayViewSize39;
			displayOptionalValue113->Enabled = false;
			displayOptionalValue113->Value = 100000000;
			displayValueRange57->High = displayOptionalValue113;
			displayOptionalValue114->Enabled = true;
			displayOptionalValue114->Value = 1E-07;
			displayValueRange57->Low = displayOptionalValue114;
			displayAxisZoom19->Range = displayValueRange57;
			scopeXAxis10->Zooming = displayAxisZoom19;
			scopeXAxis10->ZoomPin = statePin19;
			this->VCurveScope->XAxis = scopeXAxis10;
			this->VCurveScope->XInputPins = pinList20;
			scopeAutoScaling10->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace19->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace19->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling10->SpaceAbove = scopeAutoScalingSpace19;
			scopeAutoScalingSpace20->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace20->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling10->SpaceBelow = scopeAutoScalingSpace20;
			scopeYAxis10->AutoScaling = scopeAutoScaling10;
			displayTitleLabel20->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel20->Text = L"Half Flux Diameter (Pixels)";
			scopeYAxis10->AxisLabel = displayTitleLabel20;
			displayViewBackground50->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis10->Background = displayViewBackground50;
			viewButtonSettings20->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings20->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings20->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings20->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings20->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis10->Button = viewButtonSettings20;
			scopeYAxis10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis10->CursorSettings = displayAxisCursorSettings20;
			vclPen49->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen49->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen49.InternalData")));
			displayGridLineSettings49->Pen = vclPen49;
			displayGridDirectionalLinesSettings20->Lines = displayGridLineSettings49;
			vclPen50->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen50->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen50.InternalData")));
			displayGridLineSettings50->Pen = vclPen50;
			displayGridDirectionalLinesSettings20->ZeroLine = displayGridLineSettings50;
			scopeYAxis10->DataView = displayGridDirectionalLinesSettings20;
			scopeYAxis10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat20->Precision = 3;
			scopeYAxis10->Format = axisFormat20;
			scopeYAxis10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis10.InternalData")));
			ticksStart20->StartFrom = 0;
			majorTicks20->StartFrom = ticksStart20;
			majorTicks20->Step = 10;
			scopeYAxis10->MajorTicks = majorTicks20;
			maxAxisValue20->DataValue = 1000;
			displayOptionalValue115->Enabled = false;
			displayOptionalValue115->Value = 1000;
			displayValueRange58->High = displayOptionalValue115;
			displayOptionalValue116->Enabled = false;
			displayOptionalValue116->Value = -1000;
			displayValueRange58->Low = displayOptionalValue116;
			maxAxisValue20->Range = displayValueRange58;
			basicAxisValue39->Value = 0;
			maxAxisValue20->Tick = basicAxisValue39;
			maxAxisValue20->Value = 1000;
			scopeYAxis10->Max = maxAxisValue20;
			axisValue20->DataValue = -1000;
			displayOptionalValue117->Enabled = false;
			displayOptionalValue117->Value = 1000;
			displayValueRange59->High = displayOptionalValue117;
			displayOptionalValue118->Enabled = false;
			displayOptionalValue118->Value = -1000;
			displayValueRange59->Low = displayOptionalValue118;
			axisValue20->Range = displayValueRange59;
			basicAxisValue40->Value = 0;
			axisValue20->Tick = basicAxisValue40;
			axisValue20->Value = -1000;
			scopeYAxis10->Min = axisValue20;
			scopeYAxis10->MinorTicks = minorTicks20;
			axisToolBar20->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar20->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons20->Size = toolBarButtonSize30;
			displayToolBarButton217->Image = displayToolBarButtonImage217;
			axisToolBarButtons20->ZoomIn = displayToolBarButton217;
			displayToolBarButton218->Image = displayToolBarButtonImage218;
			axisToolBarButtons20->ZoomOff = displayToolBarButton218;
			displayToolBarButton219->Image = displayToolBarButtonImage219;
			axisToolBarButtons20->ZoomOneDir = displayToolBarButton219;
			displayToolBarButton220->Image = displayToolBarButtonImage220;
			axisToolBarButtons20->ZoomOut = displayToolBarButton220;
			axisToolBar20->Buttons = axisToolBarButtons20;
			axisToolBar20->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar20->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar20->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar20->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar20->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar20->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar20->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis10->ToolBar = axisToolBar20;
			scopeYAxis10->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize40->Size = static_cast<System::UInt32>(100);
			scopeYAxis10->ViewSize = displayViewSize40;
			displayOptionalValue119->Enabled = false;
			displayOptionalValue119->Value = 100000000;
			displayValueRange60->High = displayOptionalValue119;
			displayOptionalValue120->Enabled = true;
			displayOptionalValue120->Value = 1E-07;
			displayValueRange60->Low = displayOptionalValue120;
			displayAxisZoom20->Range = displayValueRange60;
			scopeYAxis10->Zooming = displayAxisZoom20;
			scopeYAxis10->ZoomPin = statePin20;
			this->VCurveScope->YAxis = scopeYAxis10;
			displayZoom10->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->VCurveScope->Zooming = displayZoom10;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::SkyBlue;
			this->groupBox2->Controls->Add(this->tableLayoutPanel7);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(3, 369);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(297, 100);
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
			this->tableLayoutPanel7->Size = System::Drawing::Size(291, 81);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(37, 32);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(37, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Star y:";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(37, 6);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Star x:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(162, 6);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Star Max:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(163, 32);
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
			this->XTextBox->Size = System::Drawing::Size(56, 20);
			this->XTextBox->TabIndex = 5;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::Khaki;
			this->groupBox3->Controls->Add(this->tableLayoutPanel8);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(306, 369);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(298, 100);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Results";
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
			this->tableLayoutPanel6->Size = System::Drawing::Size(297, 360);
			this->tableLayoutPanel6->TabIndex = 4;
			// 
			// CalFocusFramePictureBox
			// 
			this->CalFocusFramePictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CalFocusFramePictureBox->Location = System::Drawing::Point(3, 16);
			this->CalFocusFramePictureBox->Name = L"CalFocusFramePictureBox";
			this->CalFocusFramePictureBox->Size = System::Drawing::Size(285, 135);
			this->CalFocusFramePictureBox->TabIndex = 0;
			this->CalFocusFramePictureBox->TabStop = false;
			// 
			// CalStarProfileScope
			// 
			this->CalStarProfileScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground51->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView11->Background = displayViewBackground51;
			vclPen51->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen51->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen51.InternalData")));
			displayGridLineSettings51->Pen = vclPen51;
			scopeDataView11->Border = displayGridLineSettings51;
			this->CalStarProfileScope->DataView = scopeDataView11;
			channelItemHighlighting21->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->ChannelLinks = channelItemHighlighting21;
			channelItemHighlighting22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->Channels = channelItemHighlighting22;
			displayItemHighlighting61->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->CursorLinks = displayItemHighlighting61;
			displayItemHighlighting62->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->Cursors = displayItemHighlighting62;
			displayItemHighlighting63->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->Ellipses = displayItemHighlighting63;
			displayItemHighlighting64->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->Labels = displayItemHighlighting64;
			displayItemHighlighting65->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->Markers = displayItemHighlighting65;
			channelMouseHitPoint11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint11->PointLabel = optionalLabel11;
			dataChartHighlighting11->MouseHitPoint = channelMouseHitPoint11;
			displayItemHighlighting66->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting11->Zones = displayItemHighlighting66;
			this->CalStarProfileScope->Highlighting = dataChartHighlighting11;
			this->CalStarProfileScope->InputPins = pinList21;
			this->CalStarProfileScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"CalStarProfileScope.InternalData")));
			displayViewBackground52->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView11->Background = displayViewBackground52;
			legendViewButtonSettings11->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings11->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings11->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView11->Buttons = legendViewButtonSettings11;
			displayLabel81->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup81->Caption = displayLabel81;
			legendGroup81->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->ChannelLinks = legendGroup81;
			displayLabel82->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup82->Caption = displayLabel82;
			legendGroup82->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->Channels = legendGroup82;
			displayLabel83->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup83->Caption = displayLabel83;
			legendGroup83->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->CursorLinks = legendGroup83;
			displayLabel84->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup84->Caption = displayLabel84;
			legendGroup84->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->Cursors = legendGroup84;
			displayLabel85->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup85->Caption = displayLabel85;
			legendGroup85->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->Ellipses = legendGroup85;
			scopeLegendView11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView11.InternalData")));
			displayLabel86->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup86->Caption = displayLabel86;
			legendGroup86->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->Labels = legendGroup86;
			displayLabel87->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup87->Caption = displayLabel87;
			legendGroup87->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->MarkerGroups = legendGroup87;
			displayViewSize41->Size = static_cast<System::UInt32>(100);
			scopeLegendView11->ViewSize = displayViewSize41;
			displayLabel88->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup88->Caption = displayLabel88;
			legendGroup88->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView11->Zones = legendGroup88;
			this->CalStarProfileScope->Legend = scopeLegendView11;
			this->CalStarProfileScope->Location = System::Drawing::Point(3, 163);
			this->CalStarProfileScope->Name = L"CalStarProfileScope";
			this->CalStarProfileScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->CalStarProfileScope->Size = System::Drawing::Size(291, 191);
			this->CalStarProfileScope->SizeLimit = static_cast<System::UInt32>(0);
			this->CalStarProfileScope->TabIndex = 1;
			this->CalStarProfileScope->Text = L"scope1";
			displayViewBackground53->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle11->Background = displayViewBackground53;
			displayTitle11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 13, 1));
			displayTitle11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle11.InternalData")));
			displayTitle11->Text = L"Star Profile";
			displayViewSize42->Size = static_cast<System::UInt32>(100);
			displayTitle11->ViewSize = displayViewSize42;
			this->CalStarProfileScope->Title = displayTitle11;
			displayToolBar11->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar11->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton221->Image = displayToolBarButtonImage221;
			displayToolBarButtons11->Copy = displayToolBarButton221;
			displayToolBarButton222->Image = displayToolBarButtonImage222;
			displayToolBarButtons11->Hold = displayToolBarButton222;
			displayToolBarButton223->Image = displayToolBarButtonImage223;
			displayToolBarButtons11->PanMode = displayToolBarButton223;
			displayToolBarButton224->Image = displayToolBarButtonImage224;
			displayToolBarButtons11->Print = displayToolBarButton224;
			displayToolBarButton225->Image = displayToolBarButtonImage225;
			displayToolBarButtons11->Run = displayToolBarButton225;
			displayToolBarButton226->Image = displayToolBarButtonImage226;
			displayToolBarButtons11->Save = displayToolBarButton226;
			displayToolBarButton227->Image = displayToolBarButtonImage227;
			displayToolBarButtons11->Setup = displayToolBarButton227;
			displayToolBarButtons11->Size = toolBarButtonSize31;
			displayToolBarButton228->Image = displayToolBarButtonImage228;
			displayToolBarButtons11->XYZoomOn = displayToolBarButton228;
			displayToolBarButton229->Image = displayToolBarButtonImage229;
			displayToolBarButtons11->ZoomIn = displayToolBarButton229;
			displayToolBarButton230->Image = displayToolBarButtonImage230;
			displayToolBarButtons11->ZoomMode = displayToolBarButton230;
			displayToolBarButton231->Image = displayToolBarButtonImage231;
			displayToolBarButtons11->ZoomNext = displayToolBarButton231;
			displayToolBarButton232->Image = displayToolBarButtonImage232;
			displayToolBarButtons11->ZoomOff = displayToolBarButton232;
			displayToolBarButton233->Image = displayToolBarButtonImage233;
			displayToolBarButtons11->ZoomOut = displayToolBarButton233;
			displayToolBarButton234->Image = displayToolBarButtonImage234;
			displayToolBarButtons11->ZoomPrevious = displayToolBarButton234;
			displayToolBar11->Buttons = displayToolBarButtons11;
			displayToolBar11->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar11->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar11->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar11->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar11->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar11->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar11->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition11.InternalData")));
			displayToolBar11->Position = toolBarPosition11;
			this->CalStarProfileScope->ToolBar = displayToolBar11;
			displayTrails11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->CalStarProfileScope->Trails = displayTrails11;
			displayTitleLabel21->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel21->Text = L"Crossection (pixels)";
			scopeXAxis11->AxisLabel = displayTitleLabel21;
			displayViewBackground54->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis11->Background = displayViewBackground54;
			viewButtonSettings21->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings21->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings21->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings21->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings21->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis11->Button = viewButtonSettings21;
			scopeXAxis11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis11->CursorSettings = displayAxisCursorSettings21;
			vclPen52->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen52->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen52.InternalData")));
			displayGridLineSettings52->Pen = vclPen52;
			displayGridDirectionalLinesSettings21->Lines = displayGridLineSettings52;
			vclPen53->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen53->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen53.InternalData")));
			displayGridLineSettings53->Pen = vclPen53;
			displayGridDirectionalLinesSettings21->ZeroLine = displayGridLineSettings53;
			scopeXAxis11->DataView = displayGridDirectionalLinesSettings21;
			scopeXAxis11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat21->Precision = 3;
			scopeXAxis11->Format = axisFormat21;
			scopeXAxis11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis11.InternalData")));
			ticksStart21->StartFrom = 0;
			majorTicks21->StartFrom = ticksStart21;
			majorTicks21->Step = 10;
			scopeXAxis11->MajorTicks = majorTicks21;
			maxAxisValue21->DataValue = 1024;
			displayOptionalValue121->Enabled = false;
			displayOptionalValue121->Value = 1000;
			displayValueRange61->High = displayOptionalValue121;
			displayOptionalValue122->Enabled = false;
			displayOptionalValue122->Value = -1000;
			displayValueRange61->Low = displayOptionalValue122;
			maxAxisValue21->Range = displayValueRange61;
			basicAxisValue41->Value = 1024;
			maxAxisValue21->Tick = basicAxisValue41;
			maxAxisValue21->Value = 1024;
			scopeXAxis11->Max = maxAxisValue21;
			scopeMaxSample11->Value = static_cast<System::UInt32>(1024);
			scopeXAxis11->MaxSample = scopeMaxSample11;
			axisValue21->DataValue = 0;
			displayOptionalValue123->Enabled = false;
			displayOptionalValue123->Value = 1000;
			displayValueRange62->High = displayOptionalValue123;
			displayOptionalValue124->Enabled = false;
			displayOptionalValue124->Value = -1000;
			displayValueRange62->Low = displayOptionalValue124;
			axisValue21->Range = displayValueRange62;
			basicAxisValue42->Value = 0;
			axisValue21->Tick = basicAxisValue42;
			axisValue21->Value = 0;
			scopeXAxis11->Min = axisValue21;
			scopeXAxis11->MinorTicks = minorTicks21;
			axisToolBar21->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar21->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons21->Size = toolBarButtonSize32;
			displayToolBarButton235->Image = displayToolBarButtonImage235;
			axisToolBarButtons21->ZoomIn = displayToolBarButton235;
			displayToolBarButton236->Image = displayToolBarButtonImage236;
			axisToolBarButtons21->ZoomOff = displayToolBarButton236;
			displayToolBarButton237->Image = displayToolBarButtonImage237;
			axisToolBarButtons21->ZoomOneDir = displayToolBarButton237;
			displayToolBarButton238->Image = displayToolBarButtonImage238;
			axisToolBarButtons21->ZoomOut = displayToolBarButton238;
			axisToolBar21->Buttons = axisToolBarButtons21;
			axisToolBar21->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar21->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar21->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar21->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar21->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar21->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar21->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis11->ToolBar = axisToolBar21;
			scopeXAxis11->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis11->UnitScale = scopeXAxisUnitScale11;
			displayViewSize43->Size = static_cast<System::UInt32>(100);
			scopeXAxis11->ViewSize = displayViewSize43;
			displayOptionalValue125->Enabled = false;
			displayOptionalValue125->Value = 100000000;
			displayValueRange63->High = displayOptionalValue125;
			displayOptionalValue126->Enabled = true;
			displayOptionalValue126->Value = 1E-07;
			displayValueRange63->Low = displayOptionalValue126;
			displayAxisZoom21->Range = displayValueRange63;
			scopeXAxis11->Zooming = displayAxisZoom21;
			scopeXAxis11->ZoomPin = statePin21;
			this->CalStarProfileScope->XAxis = scopeXAxis11;
			this->CalStarProfileScope->XInputPins = pinList22;
			scopeAutoScaling11->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace21->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace21->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling11->SpaceAbove = scopeAutoScalingSpace21;
			scopeAutoScalingSpace22->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace22->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling11->SpaceBelow = scopeAutoScalingSpace22;
			scopeYAxis11->AutoScaling = scopeAutoScaling11;
			displayTitleLabel22->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel22->Text = L"Pixel Value (ADU)";
			scopeYAxis11->AxisLabel = displayTitleLabel22;
			displayViewBackground55->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis11->Background = displayViewBackground55;
			viewButtonSettings22->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings22->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings22->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings22->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings22->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis11->Button = viewButtonSettings22;
			scopeYAxis11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis11->CursorSettings = displayAxisCursorSettings22;
			vclPen54->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen54->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen54.InternalData")));
			displayGridLineSettings54->Pen = vclPen54;
			displayGridDirectionalLinesSettings22->Lines = displayGridLineSettings54;
			vclPen55->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen55->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen55.InternalData")));
			displayGridLineSettings55->Pen = vclPen55;
			displayGridDirectionalLinesSettings22->ZeroLine = displayGridLineSettings55;
			scopeYAxis11->DataView = displayGridDirectionalLinesSettings22;
			scopeYAxis11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat22->Precision = 3;
			scopeYAxis11->Format = axisFormat22;
			scopeYAxis11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis11.InternalData")));
			ticksStart22->StartFrom = 0;
			majorTicks22->StartFrom = ticksStart22;
			majorTicks22->Step = 10;
			scopeYAxis11->MajorTicks = majorTicks22;
			maxAxisValue22->DataValue = 1000;
			displayOptionalValue127->Enabled = false;
			displayOptionalValue127->Value = 1000;
			displayValueRange64->High = displayOptionalValue127;
			displayOptionalValue128->Enabled = false;
			displayOptionalValue128->Value = -1000;
			displayValueRange64->Low = displayOptionalValue128;
			maxAxisValue22->Range = displayValueRange64;
			basicAxisValue43->Value = 0;
			maxAxisValue22->Tick = basicAxisValue43;
			maxAxisValue22->Value = 1000;
			scopeYAxis11->Max = maxAxisValue22;
			axisValue22->DataValue = -1000;
			displayOptionalValue129->Enabled = false;
			displayOptionalValue129->Value = 1000;
			displayValueRange65->High = displayOptionalValue129;
			displayOptionalValue130->Enabled = false;
			displayOptionalValue130->Value = -1000;
			displayValueRange65->Low = displayOptionalValue130;
			axisValue22->Range = displayValueRange65;
			basicAxisValue44->Value = 0;
			axisValue22->Tick = basicAxisValue44;
			axisValue22->Value = -1000;
			scopeYAxis11->Min = axisValue22;
			scopeYAxis11->MinorTicks = minorTicks22;
			axisToolBar22->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar22->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons22->Size = toolBarButtonSize33;
			displayToolBarButton239->Image = displayToolBarButtonImage239;
			axisToolBarButtons22->ZoomIn = displayToolBarButton239;
			displayToolBarButton240->Image = displayToolBarButtonImage240;
			axisToolBarButtons22->ZoomOff = displayToolBarButton240;
			displayToolBarButton241->Image = displayToolBarButtonImage241;
			axisToolBarButtons22->ZoomOneDir = displayToolBarButton241;
			displayToolBarButton242->Image = displayToolBarButtonImage242;
			axisToolBarButtons22->ZoomOut = displayToolBarButton242;
			axisToolBar22->Buttons = axisToolBarButtons22;
			axisToolBar22->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar22->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar22->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar22->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar22->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar22->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar22->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis11->ToolBar = axisToolBar22;
			scopeYAxis11->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize44->Size = static_cast<System::UInt32>(100);
			scopeYAxis11->ViewSize = displayViewSize44;
			displayOptionalValue131->Enabled = false;
			displayOptionalValue131->Value = 100000000;
			displayValueRange66->High = displayOptionalValue131;
			displayOptionalValue132->Enabled = true;
			displayOptionalValue132->Value = 1E-07;
			displayValueRange66->Low = displayOptionalValue132;
			displayAxisZoom22->Range = displayValueRange66;
			scopeYAxis11->Zooming = displayAxisZoom22;
			scopeYAxis11->ZoomPin = statePin22;
			this->CalStarProfileScope->YAxis = scopeYAxis11;
			displayZoom11->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->CalStarProfileScope->Zooming = displayZoom11;
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
			this->tableLayoutPanel5->Controls->Add(this->CalNumFramesPerPointTextBox, 5, 0);
			this->tableLayoutPanel5->Controls->Add(this->label7, 4, 0);
			this->tableLayoutPanel5->Controls->Add(this->MaxPeakTextBox, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->label4, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->FocusStepSizeTextBox, 1, 2);
			this->tableLayoutPanel5->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->FocusStartPosTextBox, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->FocusEndPosTextBox, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->label5, 2, 1);
			this->tableLayoutPanel5->Controls->Add(this->label6, 2, 2);
			this->tableLayoutPanel5->Controls->Add(this->MinPeakTextBox, 3, 1);
			this->tableLayoutPanel5->Controls->Add(this->FieldSizeTextBox, 3, 2);
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
			// CalNumFramesPerPointTextBox
			// 
			this->CalNumFramesPerPointTextBox->Location = System::Drawing::Point(336, 3);
			this->CalNumFramesPerPointTextBox->Name = L"CalNumFramesPerPointTextBox";
			this->CalNumFramesPerPointTextBox->Size = System::Drawing::Size(56, 20);
			this->CalNumFramesPerPointTextBox->TabIndex = 12;
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
			// MaxPeakTextBox
			// 
			this->MaxPeakTextBox->Location = System::Drawing::Point(186, 3);
			this->MaxPeakTextBox->Name = L"MaxPeakTextBox";
			this->MaxPeakTextBox->Size = System::Drawing::Size(56, 20);
			this->MaxPeakTextBox->TabIndex = 8;
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
			// FocusStepSizeTextBox
			// 
			this->FocusStepSizeTextBox->Location = System::Drawing::Point(49, 51);
			this->FocusStepSizeTextBox->Name = L"FocusStepSizeTextBox";
			this->FocusStepSizeTextBox->Size = System::Drawing::Size(56, 20);
			this->FocusStepSizeTextBox->TabIndex = 4;
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
			// FocusStartPosTextBox
			// 
			this->FocusStartPosTextBox->Location = System::Drawing::Point(49, 3);
			this->FocusStartPosTextBox->Name = L"FocusStartPosTextBox";
			this->FocusStartPosTextBox->Size = System::Drawing::Size(56, 20);
			this->FocusStartPosTextBox->TabIndex = 1;
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
			// FocusEndPosTextBox
			// 
			this->FocusEndPosTextBox->Location = System::Drawing::Point(49, 27);
			this->FocusEndPosTextBox->Name = L"FocusEndPosTextBox";
			this->FocusEndPosTextBox->Size = System::Drawing::Size(56, 20);
			this->FocusEndPosTextBox->TabIndex = 3;
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
			// MinPeakTextBox
			// 
			this->MinPeakTextBox->Location = System::Drawing::Point(186, 27);
			this->MinPeakTextBox->Name = L"MinPeakTextBox";
			this->MinPeakTextBox->Size = System::Drawing::Size(56, 20);
			this->MinPeakTextBox->TabIndex = 9;
			// 
			// FieldSizeTextBox
			// 
			this->FieldSizeTextBox->Location = System::Drawing::Point(186, 51);
			this->FieldSizeTextBox->Name = L"FieldSizeTextBox";
			this->FieldSizeTextBox->Size = System::Drawing::Size(56, 20);
			this->FieldSizeTextBox->TabIndex = 10;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(619, 583);
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
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 618);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(627, 29);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CloseButton->Location = System::Drawing::Point(119, 3);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 0;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &AutoFocusDialog::CloseButton_Click);
			// 
			// YTextBox
			// 
			this->YTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->YTextBox->Location = System::Drawing::Point(80, 29);
			this->YTextBox->Name = L"YTextBox";
			this->YTextBox->Size = System::Drawing::Size(56, 20);
			this->YTextBox->TabIndex = 6;
			// 
			// MaxTextBox
			// 
			this->MaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->MaxTextBox->Location = System::Drawing::Point(220, 3);
			this->MaxTextBox->Name = L"MaxTextBox";
			this->MaxTextBox->Size = System::Drawing::Size(56, 20);
			this->MaxTextBox->TabIndex = 7;
			// 
			// HFDTextBox
			// 
			this->HFDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->HFDTextBox->Location = System::Drawing::Point(220, 29);
			this->HFDTextBox->Name = L"HFDTextBox";
			this->HFDTextBox->Size = System::Drawing::Size(56, 20);
			this->HFDTextBox->TabIndex = 8;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->CalFocusFramePictureBox);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(3, 3);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(291, 154);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Current Focus Frame";
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
			this->tableLayoutPanel8->Size = System::Drawing::Size(292, 81);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 54);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(58, 13);
			this->label12->TabIndex = 4;
			this->label12->Text = L"Left Slope:";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(9, 13);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"# of Points:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(151, 13);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(65, 13);
			this->label14->TabIndex = 2;
			this->label14->Text = L"Right Slope:";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(176, 54);
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
			this->NumPointsTextBox->Size = System::Drawing::Size(56, 20);
			this->NumPointsTextBox->TabIndex = 5;
			// 
			// LeftSlopeTextBox
			// 
			this->LeftSlopeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LeftSlopeTextBox->Location = System::Drawing::Point(76, 50);
			this->LeftSlopeTextBox->Name = L"LeftSlopeTextBox";
			this->LeftSlopeTextBox->Size = System::Drawing::Size(56, 20);
			this->LeftSlopeTextBox->TabIndex = 6;
			// 
			// RightSlopeTextBox
			// 
			this->RightSlopeTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->RightSlopeTextBox->Location = System::Drawing::Point(222, 10);
			this->RightSlopeTextBox->Name = L"RightSlopeTextBox";
			this->RightSlopeTextBox->Size = System::Drawing::Size(56, 20);
			this->RightSlopeTextBox->TabIndex = 7;
			// 
			// VertexTextBox
			// 
			this->VertexTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->VertexTextBox->Location = System::Drawing::Point(222, 50);
			this->VertexTextBox->Name = L"VertexTextBox";
			this->VertexTextBox->Size = System::Drawing::Size(56, 20);
			this->VertexTextBox->TabIndex = 8;
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
			this->tableLayoutPanel9->Controls->Add(this->tableLayoutPanel11, 0, 3);
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
			displayViewBackground56->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView12->Background = displayViewBackground56;
			vclPen56->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen56->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen56.InternalData")));
			displayGridLineSettings56->Pen = vclPen56;
			scopeDataView12->Border = displayGridLineSettings56;
			this->StarProfileScope->DataView = scopeDataView12;
			channelItemHighlighting23->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->ChannelLinks = channelItemHighlighting23;
			channelItemHighlighting24->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->Channels = channelItemHighlighting24;
			displayItemHighlighting67->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->CursorLinks = displayItemHighlighting67;
			displayItemHighlighting68->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->Cursors = displayItemHighlighting68;
			displayItemHighlighting69->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->Ellipses = displayItemHighlighting69;
			displayItemHighlighting70->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->Labels = displayItemHighlighting70;
			displayItemHighlighting71->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->Markers = displayItemHighlighting71;
			channelMouseHitPoint12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			channelMouseHitPoint12->PointLabel = optionalLabel12;
			dataChartHighlighting12->MouseHitPoint = channelMouseHitPoint12;
			displayItemHighlighting72->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataChartHighlighting12->Zones = displayItemHighlighting72;
			this->StarProfileScope->Highlighting = dataChartHighlighting12;
			this->StarProfileScope->InputPins = pinList23;
			this->StarProfileScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"StarProfileScope.InternalData")));
			displayViewBackground57->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView12->Background = displayViewBackground57;
			legendViewButtonSettings12->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings12->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings12->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView12->Buttons = legendViewButtonSettings12;
			displayLabel89->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup89->Caption = displayLabel89;
			legendGroup89->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->ChannelLinks = legendGroup89;
			displayLabel90->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup90->Caption = displayLabel90;
			legendGroup90->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->Channels = legendGroup90;
			displayLabel91->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup91->Caption = displayLabel91;
			legendGroup91->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->CursorLinks = legendGroup91;
			displayLabel92->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup92->Caption = displayLabel92;
			legendGroup92->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->Cursors = legendGroup92;
			displayLabel93->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup93->Caption = displayLabel93;
			legendGroup93->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->Ellipses = legendGroup93;
			scopeLegendView12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			scopeLegendView12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeLegendView12.InternalData")));
			displayLabel94->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup94->Caption = displayLabel94;
			legendGroup94->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->Labels = legendGroup94;
			displayLabel95->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup95->Caption = displayLabel95;
			legendGroup95->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->MarkerGroups = legendGroup95;
			displayViewSize45->Size = static_cast<System::UInt32>(100);
			scopeLegendView12->ViewSize = displayViewSize45;
			displayLabel96->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 13, 1));
			legendGroup96->Caption = displayLabel96;
			legendGroup96->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView12->Zones = legendGroup96;
			this->StarProfileScope->Legend = scopeLegendView12;
			this->StarProfileScope->Location = System::Drawing::Point(303, 3);
			this->StarProfileScope->Name = L"StarProfileScope";
			this->StarProfileScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->StarProfileScope->Size = System::Drawing::Size(295, 194);
			this->StarProfileScope->SizeLimit = static_cast<System::UInt32>(0);
			this->StarProfileScope->TabIndex = 0;
			this->StarProfileScope->Text = L"scope2";
			displayViewBackground58->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle12->Background = displayViewBackground58;
			displayTitle12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 16, 1));
			displayTitle12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"displayTitle12.InternalData")));
			displayTitle12->Text = L"Star Profile";
			displayViewSize46->Size = static_cast<System::UInt32>(100);
			displayTitle12->ViewSize = displayViewSize46;
			this->StarProfileScope->Title = displayTitle12;
			displayToolBar12->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar12->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButton243->Image = displayToolBarButtonImage243;
			displayToolBarButtons12->Copy = displayToolBarButton243;
			displayToolBarButton244->Image = displayToolBarButtonImage244;
			displayToolBarButtons12->Hold = displayToolBarButton244;
			displayToolBarButton245->Image = displayToolBarButtonImage245;
			displayToolBarButtons12->PanMode = displayToolBarButton245;
			displayToolBarButton246->Image = displayToolBarButtonImage246;
			displayToolBarButtons12->Print = displayToolBarButton246;
			displayToolBarButton247->Image = displayToolBarButtonImage247;
			displayToolBarButtons12->Run = displayToolBarButton247;
			displayToolBarButton248->Image = displayToolBarButtonImage248;
			displayToolBarButtons12->Save = displayToolBarButton248;
			displayToolBarButton249->Image = displayToolBarButtonImage249;
			displayToolBarButtons12->Setup = displayToolBarButton249;
			displayToolBarButtons12->Size = toolBarButtonSize34;
			displayToolBarButton250->Image = displayToolBarButtonImage250;
			displayToolBarButtons12->XYZoomOn = displayToolBarButton250;
			displayToolBarButton251->Image = displayToolBarButtonImage251;
			displayToolBarButtons12->ZoomIn = displayToolBarButton251;
			displayToolBarButton252->Image = displayToolBarButtonImage252;
			displayToolBarButtons12->ZoomMode = displayToolBarButton252;
			displayToolBarButton253->Image = displayToolBarButtonImage253;
			displayToolBarButtons12->ZoomNext = displayToolBarButton253;
			displayToolBarButton254->Image = displayToolBarButtonImage254;
			displayToolBarButtons12->ZoomOff = displayToolBarButton254;
			displayToolBarButton255->Image = displayToolBarButtonImage255;
			displayToolBarButtons12->ZoomOut = displayToolBarButton255;
			displayToolBarButton256->Image = displayToolBarButtonImage256;
			displayToolBarButtons12->ZoomPrevious = displayToolBarButton256;
			displayToolBar12->Buttons = displayToolBarButtons12;
			displayToolBar12->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar12->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar12->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar12->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar12->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar12->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar12->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"toolBarPosition12.InternalData")));
			displayToolBar12->Position = toolBarPosition12;
			this->StarProfileScope->ToolBar = displayToolBar12;
			displayTrails12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->StarProfileScope->Trails = displayTrails12;
			displayTitleLabel23->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel23->Text = L"Cross Section (pixels)";
			scopeXAxis12->AxisLabel = displayTitleLabel23;
			displayViewBackground59->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis12->Background = displayViewBackground59;
			viewButtonSettings23->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings23->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings23->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings23->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings23->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis12->Button = viewButtonSettings23;
			scopeXAxis12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis12->CursorSettings = displayAxisCursorSettings23;
			vclPen57->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen57->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen57.InternalData")));
			displayGridLineSettings57->Pen = vclPen57;
			displayGridDirectionalLinesSettings23->Lines = displayGridLineSettings57;
			vclPen58->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen58->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen58.InternalData")));
			displayGridLineSettings58->Pen = vclPen58;
			displayGridDirectionalLinesSettings23->ZeroLine = displayGridLineSettings58;
			scopeXAxis12->DataView = displayGridDirectionalLinesSettings23;
			scopeXAxis12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat23->Precision = 3;
			scopeXAxis12->Format = axisFormat23;
			scopeXAxis12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeXAxis12.InternalData")));
			ticksStart23->StartFrom = 0;
			majorTicks23->StartFrom = ticksStart23;
			majorTicks23->Step = 10;
			scopeXAxis12->MajorTicks = majorTicks23;
			maxAxisValue23->DataValue = 1024;
			displayOptionalValue133->Enabled = false;
			displayOptionalValue133->Value = 1000;
			displayValueRange67->High = displayOptionalValue133;
			displayOptionalValue134->Enabled = false;
			displayOptionalValue134->Value = -1000;
			displayValueRange67->Low = displayOptionalValue134;
			maxAxisValue23->Range = displayValueRange67;
			basicAxisValue45->Value = 1024;
			maxAxisValue23->Tick = basicAxisValue45;
			maxAxisValue23->Value = 1024;
			scopeXAxis12->Max = maxAxisValue23;
			scopeMaxSample12->Value = static_cast<System::UInt32>(1024);
			scopeXAxis12->MaxSample = scopeMaxSample12;
			axisValue23->DataValue = 0;
			displayOptionalValue135->Enabled = false;
			displayOptionalValue135->Value = 1000;
			displayValueRange68->High = displayOptionalValue135;
			displayOptionalValue136->Enabled = false;
			displayOptionalValue136->Value = -1000;
			displayValueRange68->Low = displayOptionalValue136;
			axisValue23->Range = displayValueRange68;
			basicAxisValue46->Value = 0;
			axisValue23->Tick = basicAxisValue46;
			axisValue23->Value = 0;
			scopeXAxis12->Min = axisValue23;
			scopeXAxis12->MinorTicks = minorTicks23;
			axisToolBar23->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar23->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons23->Size = toolBarButtonSize35;
			displayToolBarButton257->Image = displayToolBarButtonImage257;
			axisToolBarButtons23->ZoomIn = displayToolBarButton257;
			displayToolBarButton258->Image = displayToolBarButtonImage258;
			axisToolBarButtons23->ZoomOff = displayToolBarButton258;
			displayToolBarButton259->Image = displayToolBarButtonImage259;
			axisToolBarButtons23->ZoomOneDir = displayToolBarButton259;
			displayToolBarButton260->Image = displayToolBarButtonImage260;
			axisToolBarButtons23->ZoomOut = displayToolBarButton260;
			axisToolBar23->Buttons = axisToolBarButtons23;
			axisToolBar23->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar23->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar23->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar23->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar23->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar23->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar23->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis12->ToolBar = axisToolBar23;
			scopeXAxis12->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis12->UnitScale = scopeXAxisUnitScale12;
			displayViewSize47->Size = static_cast<System::UInt32>(100);
			scopeXAxis12->ViewSize = displayViewSize47;
			displayOptionalValue137->Enabled = false;
			displayOptionalValue137->Value = 100000000;
			displayValueRange69->High = displayOptionalValue137;
			displayOptionalValue138->Enabled = true;
			displayOptionalValue138->Value = 1E-07;
			displayValueRange69->Low = displayOptionalValue138;
			displayAxisZoom23->Range = displayValueRange69;
			scopeXAxis12->Zooming = displayAxisZoom23;
			scopeXAxis12->ZoomPin = statePin23;
			this->StarProfileScope->XAxis = scopeXAxis12;
			this->StarProfileScope->XInputPins = pinList24;
			scopeAutoScaling12->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace23->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace23->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling12->SpaceAbove = scopeAutoScalingSpace23;
			scopeAutoScalingSpace24->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace24->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling12->SpaceBelow = scopeAutoScalingSpace24;
			scopeYAxis12->AutoScaling = scopeAutoScaling12;
			displayTitleLabel24->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
			displayTitleLabel24->Text = L"Pixel Value (ADU)";
			scopeYAxis12->AxisLabel = displayTitleLabel24;
			displayViewBackground60->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis12->Background = displayViewBackground60;
			viewButtonSettings24->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings24->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings24->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings24->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings24->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis12->Button = viewButtonSettings24;
			scopeYAxis12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis12->CursorSettings = displayAxisCursorSettings24;
			vclPen59->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen59->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen59.InternalData")));
			displayGridLineSettings59->Pen = vclPen59;
			displayGridDirectionalLinesSettings24->Lines = displayGridLineSettings59;
			vclPen60->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen60->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen60.InternalData")));
			displayGridLineSettings60->Pen = vclPen60;
			displayGridDirectionalLinesSettings24->ZeroLine = displayGridLineSettings60;
			scopeYAxis12->DataView = displayGridDirectionalLinesSettings24;
			scopeYAxis12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			axisFormat24->Precision = 3;
			scopeYAxis12->Format = axisFormat24;
			scopeYAxis12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scopeYAxis12.InternalData")));
			ticksStart24->StartFrom = 0;
			majorTicks24->StartFrom = ticksStart24;
			majorTicks24->Step = 10;
			scopeYAxis12->MajorTicks = majorTicks24;
			maxAxisValue24->DataValue = 1000;
			displayOptionalValue139->Enabled = false;
			displayOptionalValue139->Value = 1000;
			displayValueRange70->High = displayOptionalValue139;
			displayOptionalValue140->Enabled = false;
			displayOptionalValue140->Value = -1000;
			displayValueRange70->Low = displayOptionalValue140;
			maxAxisValue24->Range = displayValueRange70;
			basicAxisValue47->Value = 0;
			maxAxisValue24->Tick = basicAxisValue47;
			maxAxisValue24->Value = 1000;
			scopeYAxis12->Max = maxAxisValue24;
			axisValue24->DataValue = -1000;
			displayOptionalValue141->Enabled = false;
			displayOptionalValue141->Value = 1000;
			displayValueRange71->High = displayOptionalValue141;
			displayOptionalValue142->Enabled = false;
			displayOptionalValue142->Value = -1000;
			displayValueRange71->Low = displayOptionalValue142;
			axisValue24->Range = displayValueRange71;
			basicAxisValue48->Value = 0;
			axisValue24->Tick = basicAxisValue48;
			axisValue24->Value = -1000;
			scopeYAxis12->Min = axisValue24;
			scopeYAxis12->MinorTicks = minorTicks24;
			axisToolBar24->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar24->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons24->Size = toolBarButtonSize36;
			displayToolBarButton261->Image = displayToolBarButtonImage261;
			axisToolBarButtons24->ZoomIn = displayToolBarButton261;
			displayToolBarButton262->Image = displayToolBarButtonImage262;
			axisToolBarButtons24->ZoomOff = displayToolBarButton262;
			displayToolBarButton263->Image = displayToolBarButtonImage263;
			axisToolBarButtons24->ZoomOneDir = displayToolBarButton263;
			displayToolBarButton264->Image = displayToolBarButtonImage264;
			axisToolBarButtons24->ZoomOut = displayToolBarButton264;
			axisToolBar24->Buttons = axisToolBarButtons24;
			axisToolBar24->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar24->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar24->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar24->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar24->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar24->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar24->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis12->ToolBar = axisToolBar24;
			scopeYAxis12->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize48->Size = static_cast<System::UInt32>(100);
			scopeYAxis12->ViewSize = displayViewSize48;
			displayOptionalValue143->Enabled = false;
			displayOptionalValue143->Value = 100000000;
			displayValueRange72->High = displayOptionalValue143;
			displayOptionalValue144->Enabled = true;
			displayOptionalValue144->Value = 1E-07;
			displayValueRange72->Low = displayOptionalValue144;
			displayAxisZoom24->Range = displayValueRange72;
			scopeYAxis12->Zooming = displayAxisZoom24;
			scopeYAxis12->ZoomPin = statePin24;
			this->StarProfileScope->YAxis = scopeYAxis12;
			displayZoom12->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->StarProfileScope->Zooming = displayZoom12;
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
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 3;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47.84946F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				52.15054F)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				91)));
			this->tableLayoutPanel11->Controls->Add(this->button3, 2, 0);
			this->tableLayoutPanel11->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel11->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel11->Location = System::Drawing::Point(3, 413);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 1;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(278, 33);
			this->tableLayoutPanel11->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::ForestGreen;
			this->button1->Location = System::Drawing::Point(7, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(100, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Pause";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->Location = System::Drawing::Point(194, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// tableLayoutPanel12
			// 
			this->tableLayoutPanel12->ColumnCount = 3;
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.27322F)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.72678F)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				127)));
			this->tableLayoutPanel12->Controls->Add(this->radioButton1, 2, 0);
			this->tableLayoutPanel12->Controls->Add(this->radioButton2, 2, 1);
			this->tableLayoutPanel12->Controls->Add(this->radioButton3, 2, 2);
			this->tableLayoutPanel12->Controls->Add(this->label16, 0, 0);
			this->tableLayoutPanel12->Controls->Add(this->NumFramesPerPointTextBox, 1, 0);
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
			this->radioButton1->Location = System::Drawing::Point(186, 3);
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
			this->radioButton2->Location = System::Drawing::Point(186, 28);
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
			this->radioButton3->Location = System::Drawing::Point(186, 53);
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
			this->label16->Location = System::Drawing::Point(16, 6);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(73, 13);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Frames/Point:";
			// 
			// NumFramesPerPointTextBox
			// 
			this->NumFramesPerPointTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->NumFramesPerPointTextBox->Location = System::Drawing::Point(95, 3);
			this->NumFramesPerPointTextBox->Name = L"NumFramesPerPointTextBox";
			this->NumFramesPerPointTextBox->Size = System::Drawing::Size(38, 20);
			this->NumFramesPerPointTextBox->TabIndex = 4;
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(5, 60);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(69, 13);
			this->label17->TabIndex = 9;
			this->label17->Text = L"Focuser Pos:";
			// 
			// CalFocuserPositionTextBox
			// 
			this->CalFocuserPositionTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CalFocuserPositionTextBox->Location = System::Drawing::Point(80, 56);
			this->CalFocuserPositionTextBox->Name = L"CalFocuserPositionTextBox";
			this->CalFocuserPositionTextBox->Size = System::Drawing::Size(56, 20);
			this->CalFocuserPositionTextBox->TabIndex = 10;
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
				90)));
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
			this->StarXTextBox->Size = System::Drawing::Size(38, 20);
			this->StarXTextBox->TabIndex = 8;
			// 
			// StarYTextBox
			// 
			this->StarYTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarYTextBox->Location = System::Drawing::Point(58, 47);
			this->StarYTextBox->Name = L"StarYTextBox";
			this->StarYTextBox->Size = System::Drawing::Size(38, 20);
			this->StarYTextBox->TabIndex = 9;
			// 
			// StarMaxTextBox
			// 
			this->StarMaxTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarMaxTextBox->Location = System::Drawing::Point(178, 9);
			this->StarMaxTextBox->Name = L"StarMaxTextBox";
			this->StarMaxTextBox->Size = System::Drawing::Size(38, 20);
			this->StarMaxTextBox->TabIndex = 10;
			// 
			// StarHFDTextBox
			// 
			this->StarHFDTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StarHFDTextBox->Location = System::Drawing::Point(178, 47);
			this->StarHFDTextBox->Name = L"StarHFDTextBox";
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
			this->FrameNumTextBox->Size = System::Drawing::Size(38, 20);
			this->FrameNumTextBox->TabIndex = 15;
			// 
			// label24
			// 
			this->label24->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(165, 60);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(49, 13);
			this->label24->TabIndex = 11;
			this->label24->Text = L"Frame #:";
			// 
			// CalFrameNumTextBox
			// 
			this->CalFrameNumTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->CalFrameNumTextBox->Location = System::Drawing::Point(220, 56);
			this->CalFrameNumTextBox->Name = L"CalFrameNumTextBox";
			this->CalFrameNumTextBox->Size = System::Drawing::Size(56, 20);
			this->CalFrameNumTextBox->TabIndex = 12;
			// 
			// AutoFocusDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 650);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AutoFocusDialog";
			this->Text = L"AutoFocusDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tabControl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCurveScope))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalFocusFramePictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CalStarProfileScope))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StarProfileScope))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FocusFramePictureBox))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->tableLayoutPanel11->ResumeLayout(false);
			this->tableLayoutPanel12->ResumeLayout(false);
			this->tableLayoutPanel12->PerformLayout();
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: static System::Void ShowTheDialog() {

		// Finally, show the dialog

		AutoFocusDialog::FormPtr->ShowDialog();

	}

	private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
	}
};
}
