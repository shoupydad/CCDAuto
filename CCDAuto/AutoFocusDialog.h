#pragma once

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
			AutoFocusDialgoExists = true;
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
			AutoFocusDialgoExists = false;
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
	private: System::Windows::Forms::TextBox^  NumFramesPerPointTextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::PictureBox^  FocusFramePictureBox;
	private: Mitov::PlotLab::Scope^  scope1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			Mitov::PlotLab::ScopeDataView^  scopeDataView5 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground21 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings21 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen21 = (gcnew Vcl::VclPen());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AutoFocusDialog::typeid));
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->VCurveScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FocusFramePictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->scope1 = (gcnew Mitov::PlotLab::Scope(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->NumFramesPerPointTextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCurveScope))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FocusFramePictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scope1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 92.42175F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.578254F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(633, 607);
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
			this->tabControl->Size = System::Drawing::Size(627, 554);
			this->tabControl->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(619, 528);
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
			this->tabPage2->Size = System::Drawing::Size(619, 528);
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
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 19.34866F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80.65134F)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(613, 522);
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
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 104);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.59036F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.40964F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(607, 415);
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
			this->VCurveScope->Size = System::Drawing::Size(298, 316);
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
			displayTitleLabel10->Text = L"Half Flux Diameter";
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
			this->groupBox2->Location = System::Drawing::Point(3, 325);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(297, 87);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Results";
			// 
			// groupBox3
			// 
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(306, 325);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(298, 87);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Results";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->FocusFramePictureBox, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->scope1, 0, 1);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 37.65823F)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 62.34177F)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(297, 316);
			this->tableLayoutPanel6->TabIndex = 4;
			// 
			// FocusFramePictureBox
			// 
			this->FocusFramePictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->FocusFramePictureBox->Location = System::Drawing::Point(3, 3);
			this->FocusFramePictureBox->Name = L"FocusFramePictureBox";
			this->FocusFramePictureBox->Size = System::Drawing::Size(291, 113);
			this->FocusFramePictureBox->TabIndex = 0;
			this->FocusFramePictureBox->TabStop = false;
			// 
			// scope1
			// 
			this->scope1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView6->Background = displayViewBackground26;
			vclPen26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen26->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"vclPen26.InternalData")));
			displayGridLineSettings26->Pen = vclPen26;
			scopeDataView6->Border = displayGridLineSettings26;
			this->scope1->DataView = scopeDataView6;
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
			this->scope1->Highlighting = dataChartHighlighting6;
			this->scope1->InputPins = pinList11;
			this->scope1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^>(resources->GetObject(L"scope1.InternalData")));
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
			this->scope1->Legend = scopeLegendView6;
			this->scope1->Location = System::Drawing::Point(3, 122);
			this->scope1->Name = L"scope1";
			this->scope1->RefreshInterval = static_cast<System::UInt32>(100);
			this->scope1->Size = System::Drawing::Size(291, 191);
			this->scope1->SizeLimit = static_cast<System::UInt32>(0);
			this->scope1->TabIndex = 1;
			this->scope1->Text = L"scope1";
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
			this->scope1->Title = displayTitle6;
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
			this->scope1->ToolBar = displayToolBar6;
			displayTrails6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial",
				1, 0, true, 11, 0));
			this->scope1->Trails = displayTrails6;
			displayTitleLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Comic Sans MS",
				1, 0, true, 12, 1));
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
			this->scope1->XAxis = scopeXAxis6;
			this->scope1->XInputPins = pinList12;
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
			displayTitleLabel12->Text = L"Y Axis";
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
			this->scope1->YAxis = scopeYAxis6;
			displayZoom6->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->scope1->Zooming = displayZoom6;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->BackColor = System::Drawing::Color::Plum;
			this->groupBox1->Controls->Add(this->tableLayoutPanel5);
			this->groupBox1->Location = System::Drawing::Point(94, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(425, 95);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parameters";
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
			this->tableLayoutPanel5->Controls->Add(this->NumFramesPerPointTextBox, 5, 0);
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(419, 76);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// NumFramesPerPointTextBox
			// 
			this->NumFramesPerPointTextBox->Location = System::Drawing::Point(336, 3);
			this->NumFramesPerPointTextBox->Name = L"NumFramesPerPointTextBox";
			this->NumFramesPerPointTextBox->Size = System::Drawing::Size(56, 20);
			this->NumFramesPerPointTextBox->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(257, 6);
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
			this->label4->Location = System::Drawing::Point(125, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"MaxPeak:";
			// 
			// FocusStepSizeTextBox
			// 
			this->FocusStepSizeTextBox->Location = System::Drawing::Point(49, 53);
			this->FocusStepSizeTextBox->Name = L"FocusStepSizeTextBox";
			this->FocusStepSizeTextBox->Size = System::Drawing::Size(56, 20);
			this->FocusStepSizeTextBox->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 6);
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
			this->label2->Location = System::Drawing::Point(14, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"End:";
			// 
			// FocusEndPosTextBox
			// 
			this->FocusEndPosTextBox->Location = System::Drawing::Point(49, 28);
			this->FocusEndPosTextBox->Name = L"FocusEndPosTextBox";
			this->FocusEndPosTextBox->Size = System::Drawing::Size(56, 20);
			this->FocusEndPosTextBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Step:";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(128, 31);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"MinPeak:";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(125, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Field Size:";
			// 
			// MinPeakTextBox
			// 
			this->MinPeakTextBox->Location = System::Drawing::Point(186, 28);
			this->MinPeakTextBox->Name = L"MinPeakTextBox";
			this->MinPeakTextBox->Size = System::Drawing::Size(56, 20);
			this->MinPeakTextBox->TabIndex = 9;
			// 
			// FieldSizeTextBox
			// 
			this->FieldSizeTextBox->Location = System::Drawing::Point(186, 53);
			this->FieldSizeTextBox->Name = L"FieldSizeTextBox";
			this->FieldSizeTextBox->Size = System::Drawing::Size(56, 20);
			this->FieldSizeTextBox->TabIndex = 10;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(619, 528);
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 563);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(627, 41);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseButton->Location = System::Drawing::Point(119, 9);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 0;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 4;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel7->Controls->Add(this->label11, 0, 1);
			this->tableLayoutPanel7->Controls->Add(this->label8, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->label9, 2, 0);
			this->tableLayoutPanel7->Controls->Add(this->label10, 2, 1);
			this->tableLayoutPanel7->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(291, 68);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(37, 10);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Start:";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(181, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Start:";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(181, 44);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(32, 13);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Start:";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(37, 44);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(32, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Start:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(75, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(56, 20);
			this->textBox1->TabIndex = 5;
			// 
			// AutoFocusDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 607);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AutoFocusDialog";
			this->Text = L"AutoFocusDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tabControl->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCurveScope))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FocusFramePictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scope1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: static System::Void ShowTheDialog() {

		// Finally, show the dialog

		AutoFocusDialog::FormPtr->ShowDialog();

	}

	};
}
