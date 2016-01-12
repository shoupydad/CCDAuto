#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "doRoutines.h"


namespace CCDAuto {

	/// <summary>
	/// Summary for PhotometryPlotWindow2
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class PhotometryPlotWindow2 : public System::Windows::Forms::Form
	{
	public:
		static PhotometryPlotWindow2 ^FormPtr;
		static bool VersusUT;
		PhotometryPlotWindow2(void)
		{
			InitializeComponent();
			FormPtr = this;
			VersusUT = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PhotometryPlotWindow2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: Mitov::PlotLab::Scope^  VCPlotScope;
	private: Mitov::PlotLab::Scope^  scope1;
	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::Button^  ClearButton;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PhotometryPlotWindow2::typeid));
			Mitov::PlotLab::DisplayHighlighting^  displayHighlighting5 = (gcnew Mitov::PlotLab::DisplayHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting9 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting10 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting21 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting22 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting23 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting24 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint5 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::SignalLab::OptionalLabel^  optionalLabel5 = (gcnew Mitov::SignalLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting25 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList9 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView5 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground22 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings5 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup29 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel29 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup30 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel30 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup31 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel31 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup32 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel32 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup33 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel33 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup34 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel34 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize17 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup35 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel35 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle5 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground23 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize18 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar5 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons5 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton81 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton82 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton83 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton84 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton85 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton86 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton87 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton88 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton89 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton90 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton91 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton92 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition5 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails5 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis5 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel9 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground24 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings9 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings9 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings9 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings22 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings23 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat9 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks9 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart9 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxScopeAxisValue^  maxScopeAxisValue5 = (gcnew Mitov::PlotLab::MaxScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange25 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue49 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue50 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue9 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample5 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::ScopeAxisValue^  scopeAxisValue5 = (gcnew Mitov::PlotLab::ScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange26 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue51 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue52 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue10 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks9 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar9 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons9 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton93 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton94 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton95 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton96 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale5 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize19 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom9 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange27 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue53 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue54 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
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
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings25 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat10 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks10 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart10 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue9 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange28 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue55 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue56 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue10 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange29 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue57 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue58 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::MinorTicks^  minorTicks10 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar10 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons10 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton97 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton98 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton99 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton100 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize20 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom10 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange30 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue59 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue60 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayZoom^  displayZoom5 = (gcnew Mitov::PlotLab::DisplayZoom());
			Mitov::PlotLab::ScopeDataView^  scopeDataView6 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground26 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings26 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayHighlighting^  displayHighlighting6 = (gcnew Mitov::PlotLab::DisplayHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting11 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting12 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting26 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting27 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting28 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting29 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint6 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::SignalLab::OptionalLabel^  optionalLabel6 = (gcnew Mitov::SignalLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting30 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList11 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView6 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground27 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings6 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup36 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel36 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup37 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel37 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup38 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel38 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup39 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel39 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup40 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel40 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup41 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel41 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize21 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup42 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel42 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle6 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground28 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize22 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar6 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons6 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton101 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton102 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton103 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton104 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton105 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton106 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton107 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton108 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton109 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton110 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton111 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton112 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition6 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails6 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis6 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel11 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground29 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings11 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings11 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings11 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings27 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings28 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat11 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks11 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart11 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxScopeAxisValue^  maxScopeAxisValue6 = (gcnew Mitov::PlotLab::MaxScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange31 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue61 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue62 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue11 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample6 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::ScopeAxisValue^  scopeAxisValue6 = (gcnew Mitov::PlotLab::ScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange32 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue63 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue64 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue12 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks11 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar11 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons11 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton113 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton114 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton115 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton116 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale6 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize23 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom11 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange33 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue65 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue66 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
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
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings30 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Mitov::PlotLab::AxisFormat^  axisFormat12 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks12 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart12 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue11 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange34 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue67 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue68 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicScopeAxisValue^  basicScopeAxisValue12 = (gcnew Mitov::PlotLab::BasicScopeAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange35 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue69 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue70 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::MinorTicks^  minorTicks12 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar12 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons12 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton117 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton118 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton119 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton120 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize24 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom12 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange36 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue71 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue72 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayZoom^  displayZoom6 = (gcnew Mitov::PlotLab::DisplayZoom());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->VCPlotScope = (gcnew Mitov::PlotLab::Scope(this->components));
			this->scope1 = (gcnew Mitov::PlotLab::Scope(this->components));
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VCPlotScope))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scope1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->VCPlotScope, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->scope1, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(705, 613);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				49.0991F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50.9009F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				276)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				200)));
			this->tableLayoutPanel2->Controls->Add(this->ClearButton, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->CloseButton, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 571);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(699, 39);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// VCPlotScope
			// 
			this->VCPlotScope->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground21->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView5->Background = displayViewBackground21;
			displayGridLineSettings21->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			scopeDataView5->Border = displayGridLineSettings21;
			scopeDataView5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeDataView5.InternalData")));
			this->VCPlotScope->DataView = scopeDataView5;
			this->VCPlotScope->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->ChannelLinks = channelItemHighlighting9;
			channelItemHighlighting10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->Channels = channelItemHighlighting10;
			displayItemHighlighting21->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->CursorLinks = displayItemHighlighting21;
			displayItemHighlighting22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->Cursors = displayItemHighlighting22;
			displayItemHighlighting23->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->Ellipses = displayItemHighlighting23;
			displayItemHighlighting24->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->Markers = displayItemHighlighting24;
			channelMouseHitPoint5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			optionalLabel5->Text = L"";
			channelMouseHitPoint5->PointLabel = optionalLabel5;
			displayHighlighting5->MouseHitPoint = channelMouseHitPoint5;
			displayItemHighlighting25->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting5->Zones = displayItemHighlighting25;
			this->VCPlotScope->Highlighting = displayHighlighting5;
			pinList9->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList9.ConnectionData")));
			this->VCPlotScope->InputPins = pinList9;
			this->VCPlotScope->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"VCPlotScope.InternalData")));
			scopeLegendView5->Align = Mitov::PlotLab::ViewAlign::Right;
			displayViewBackground22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView5->Background = displayViewBackground22;
			legendViewButtonSettings5->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings5->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
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
			displayLabel29->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel29->Text = L"";
			legendGroup29->Caption = displayLabel29;
			scopeLegendView5->ChannelLinks = legendGroup29;
			displayLabel30->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel30->Text = L"";
			legendGroup30->Caption = displayLabel30;
			scopeLegendView5->Channels = legendGroup30;
			displayLabel31->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel31->Text = L"";
			legendGroup31->Caption = displayLabel31;
			scopeLegendView5->CursorLinks = legendGroup31;
			displayLabel32->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel32->Text = L"";
			legendGroup32->Caption = displayLabel32;
			scopeLegendView5->Cursors = legendGroup32;
			displayLabel33->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel33->Text = L"";
			legendGroup33->Caption = displayLabel33;
			scopeLegendView5->Ellipses = legendGroup33;
			scopeLegendView5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			scopeLegendView5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeLegendView5.InternalData")));
			displayLabel34->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel34->Text = L"";
			legendGroup34->Caption = displayLabel34;
			scopeLegendView5->MarkerGroups = legendGroup34;
			displayViewSize17->Size = static_cast<System::UInt32>(100);
			scopeLegendView5->ViewSize = displayViewSize17;
			displayLabel35->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel35->Text = L"";
			legendGroup35->Caption = displayLabel35;
			scopeLegendView5->Zones = legendGroup35;
			this->VCPlotScope->Legend = scopeLegendView5;
			this->VCPlotScope->Location = System::Drawing::Point(3, 3);
			this->VCPlotScope->Name = L"VCPlotScope";
			this->VCPlotScope->RefreshInterval = static_cast<System::UInt32>(100);
			this->VCPlotScope->Size = System::Drawing::Size(699, 278);
			this->VCPlotScope->SizeLimit = static_cast<System::UInt32>(0);
			this->VCPlotScope->TabIndex = 1;
			this->VCPlotScope->Text = L"V-C Plot";
			displayViewBackground23->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle5->Background = displayViewBackground23;
			displayTitle5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 21, (gcnew Vcl::FontStyles(1))));
			displayTitle5->Text = L"V-C Plot";
			displayViewSize18->Size = static_cast<System::UInt32>(100);
			displayTitle5->ViewSize = displayViewSize18;
			this->VCPlotScope->Title = displayTitle5;
			displayToolBar5->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar5->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButtons5->Copy = displayToolBarButton81;
			displayToolBarButtons5->Hold = displayToolBarButton82;
			displayToolBarButtons5->Print = displayToolBarButton83;
			displayToolBarButtons5->Save = displayToolBarButton84;
			displayToolBarButtons5->Setup = displayToolBarButton85;
			displayToolBarButtons5->XYZoomOn = displayToolBarButton86;
			displayToolBarButtons5->ZoomIn = displayToolBarButton87;
			displayToolBarButtons5->ZoomMode = displayToolBarButton88;
			displayToolBarButtons5->ZoomNext = displayToolBarButton89;
			displayToolBarButtons5->ZoomOff = displayToolBarButton90;
			displayToolBarButtons5->ZoomOut = displayToolBarButton91;
			displayToolBarButtons5->ZoomPrevious = displayToolBarButton92;
			displayToolBar5->Buttons = displayToolBarButtons5;
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
			displayToolBar5->Position = toolBarPosition5;
			this->VCPlotScope->ToolBar = displayToolBar5;
			displayTrails5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			this->VCPlotScope->Trails = displayTrails5;
			this->VCPlotScope->Visible = true;
			scopeXAxis5->Align = Mitov::PlotLab::ViewAlign::Bottom;
			displayTitleLabel9->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(1))));
			displayTitleLabel9->Text = L"Universal Time (Hours)";
			scopeXAxis5->AxisLabel = displayTitleLabel9;
			displayViewBackground24->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis5->Background = displayViewBackground24;
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
			displayGridLineSettings22->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings9->Lines = displayGridLineSettings22;
			displayGridLineSettings23->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings9->ZeroLine = displayGridLineSettings23;
			scopeXAxis5->DataView = displayGridDirectionalLinesSettings9;
			scopeXAxis5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			scopeXAxis5->Format = axisFormat9;
			scopeXAxis5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeXAxis5.InternalData")));
			ticksStart9->StartFrom = 0;
			majorTicks9->StartFrom = ticksStart9;
			majorTicks9->Step = 10;
			scopeXAxis5->MajorTicks = majorTicks9;
			maxScopeAxisValue5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"maxScopeAxisValue5.InternalData")));
			displayOptionalValue49->Enabled = false;
			displayOptionalValue49->Value = 1000;
			displayValueRange25->High = displayOptionalValue49;
			displayOptionalValue50->Enabled = false;
			displayOptionalValue50->Value = -1000;
			displayValueRange25->Low = displayOptionalValue50;
			maxScopeAxisValue5->Range = displayValueRange25;
			basicAxisValue9->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue9.InternalData")));
			basicAxisValue9->Value = 1024;
			maxScopeAxisValue5->Tick = basicAxisValue9;
			maxScopeAxisValue5->Value = 1024;
			scopeXAxis5->Max = maxScopeAxisValue5;
			scopeMaxSample5->Value = static_cast<System::UInt32>(1024);
			scopeXAxis5->MaxSample = scopeMaxSample5;
			scopeAxisValue5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeAxisValue5.InternalData")));
			displayOptionalValue51->Enabled = false;
			displayOptionalValue51->Value = 1000;
			displayValueRange26->High = displayOptionalValue51;
			displayOptionalValue52->Enabled = false;
			displayOptionalValue52->Value = -1000;
			displayValueRange26->Low = displayOptionalValue52;
			scopeAxisValue5->Range = displayValueRange26;
			basicAxisValue10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue10.InternalData")));
			basicAxisValue10->Value = 0;
			scopeAxisValue5->Tick = basicAxisValue10;
			scopeAxisValue5->Value = 0;
			scopeXAxis5->Min = scopeAxisValue5;
			minorTicks9->Count = static_cast<System::UInt32>(0);
			scopeXAxis5->MinorTicks = minorTicks9;
			axisToolBar9->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar9->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons9->ZoomIn = displayToolBarButton93;
			axisToolBarButtons9->ZoomOff = displayToolBarButton94;
			axisToolBarButtons9->ZoomOneDir = displayToolBarButton95;
			axisToolBarButtons9->ZoomOut = displayToolBarButton96;
			axisToolBar9->Buttons = axisToolBarButtons9;
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
			scopeXAxisUnitScale5->Exponent = 0;
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
			this->VCPlotScope->XAxis = scopeXAxis5;
			pinList10->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList10.ConnectionData")));
			this->VCPlotScope->XInputPins = pinList10;
			scopeYAxis5->Align = Mitov::PlotLab::ViewAlign::Left;
			scopeAutoScaling5->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace9->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace9->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling5->SpaceAbove = scopeAutoScalingSpace9;
			scopeAutoScalingSpace10->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace10->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling5->SpaceBelow = scopeAutoScalingSpace10;
			scopeYAxis5->AutoScaling = scopeAutoScaling5;
			displayTitleLabel10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(1))));
			displayTitleLabel10->Text = L"V-C (m)";
			scopeYAxis5->AxisLabel = displayTitleLabel10;
			displayViewBackground25->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis5->Background = displayViewBackground25;
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
			displayGridLineSettings24->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings10->Lines = displayGridLineSettings24;
			displayGridLineSettings25->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings10->ZeroLine = displayGridLineSettings25;
			scopeYAxis5->DataView = displayGridDirectionalLinesSettings10;
			scopeYAxis5->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			scopeYAxis5->Format = axisFormat10;
			scopeYAxis5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeYAxis5.InternalData")));
			ticksStart10->StartFrom = 0;
			majorTicks10->StartFrom = ticksStart10;
			majorTicks10->Step = 10;
			scopeYAxis5->MajorTicks = majorTicks10;
			basicScopeAxisValue9->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue9.InternalData")));
			displayOptionalValue55->Enabled = false;
			displayOptionalValue55->Value = 1000;
			displayValueRange28->High = displayOptionalValue55;
			displayOptionalValue56->Enabled = false;
			displayOptionalValue56->Value = -1000;
			displayValueRange28->Low = displayOptionalValue56;
			basicScopeAxisValue9->Range = displayValueRange28;
			basicScopeAxisValue9->Value = 1000;
			scopeYAxis5->Max = basicScopeAxisValue9;
			basicScopeAxisValue10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue10.InternalData")));
			displayOptionalValue57->Enabled = false;
			displayOptionalValue57->Value = 1000;
			displayValueRange29->High = displayOptionalValue57;
			displayOptionalValue58->Enabled = false;
			displayOptionalValue58->Value = -1000;
			displayValueRange29->Low = displayOptionalValue58;
			basicScopeAxisValue10->Range = displayValueRange29;
			basicScopeAxisValue10->Value = -1000;
			scopeYAxis5->Min = basicScopeAxisValue10;
			minorTicks10->Count = static_cast<System::UInt32>(0);
			scopeYAxis5->MinorTicks = minorTicks10;
			axisToolBar10->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar10->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons10->ZoomIn = displayToolBarButton97;
			axisToolBarButtons10->ZoomOff = displayToolBarButton98;
			axisToolBarButtons10->ZoomOneDir = displayToolBarButton99;
			axisToolBarButtons10->ZoomOut = displayToolBarButton100;
			axisToolBar10->Buttons = axisToolBarButtons10;
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
			this->VCPlotScope->YAxis = scopeYAxis5;
			displayZoom5->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->VCPlotScope->Zooming = displayZoom5;
			// 
			// scope1
			// 
			this->scope1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewBackground26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView6->Background = displayViewBackground26;
			displayGridLineSettings26->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			scopeDataView6->Border = displayGridLineSettings26;
			scopeDataView6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeDataView6.InternalData")));
			this->scope1->DataView = scopeDataView6;
			this->scope1->Dock = System::Windows::Forms::DockStyle::Fill;
			channelItemHighlighting11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->ChannelLinks = channelItemHighlighting11;
			channelItemHighlighting12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->Channels = channelItemHighlighting12;
			displayItemHighlighting26->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->CursorLinks = displayItemHighlighting26;
			displayItemHighlighting27->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->Cursors = displayItemHighlighting27;
			displayItemHighlighting28->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->Ellipses = displayItemHighlighting28;
			displayItemHighlighting29->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->Markers = displayItemHighlighting29;
			channelMouseHitPoint6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			optionalLabel6->Text = L"";
			channelMouseHitPoint6->PointLabel = optionalLabel6;
			displayHighlighting6->MouseHitPoint = channelMouseHitPoint6;
			displayItemHighlighting30->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayHighlighting6->Zones = displayItemHighlighting30;
			this->scope1->Highlighting = displayHighlighting6;
			pinList11->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList11.ConnectionData")));
			this->scope1->InputPins = pinList11;
			this->scope1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scope1.InternalData")));
			scopeLegendView6->Align = Mitov::PlotLab::ViewAlign::Right;
			displayViewBackground27->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView6->Background = displayViewBackground27;
			legendViewButtonSettings6->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings6->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
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
			displayLabel36->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel36->Text = L"";
			legendGroup36->Caption = displayLabel36;
			scopeLegendView6->ChannelLinks = legendGroup36;
			displayLabel37->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel37->Text = L"";
			legendGroup37->Caption = displayLabel37;
			scopeLegendView6->Channels = legendGroup37;
			displayLabel38->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel38->Text = L"";
			legendGroup38->Caption = displayLabel38;
			scopeLegendView6->CursorLinks = legendGroup38;
			displayLabel39->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel39->Text = L"";
			legendGroup39->Caption = displayLabel39;
			scopeLegendView6->Cursors = legendGroup39;
			displayLabel40->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel40->Text = L"";
			legendGroup40->Caption = displayLabel40;
			scopeLegendView6->Ellipses = legendGroup40;
			scopeLegendView6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			scopeLegendView6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeLegendView6.InternalData")));
			displayLabel41->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel41->Text = L"";
			legendGroup41->Caption = displayLabel41;
			scopeLegendView6->MarkerGroups = legendGroup41;
			displayViewSize21->Size = static_cast<System::UInt32>(100);
			scopeLegendView6->ViewSize = displayViewSize21;
			displayLabel42->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(0))));
			displayLabel42->Text = L"";
			legendGroup42->Caption = displayLabel42;
			scopeLegendView6->Zones = legendGroup42;
			this->scope1->Legend = scopeLegendView6;
			this->scope1->Location = System::Drawing::Point(3, 287);
			this->scope1->Name = L"scope1";
			this->scope1->RefreshInterval = static_cast<System::UInt32>(100);
			this->scope1->Size = System::Drawing::Size(699, 278);
			this->scope1->SizeLimit = static_cast<System::UInt32>(0);
			this->scope1->TabIndex = 2;
			this->scope1->Text = L"scope1";
			displayViewBackground28->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle6->Background = displayViewBackground28;
			displayTitle6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 21, (gcnew Vcl::FontStyles(1))));
			displayTitle6->Text = L"K-C Plot";
			displayViewSize22->Size = static_cast<System::UInt32>(100);
			displayTitle6->ViewSize = displayViewSize22;
			this->scope1->Title = displayTitle6;
			displayToolBar6->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar6->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButtons6->Copy = displayToolBarButton101;
			displayToolBarButtons6->Hold = displayToolBarButton102;
			displayToolBarButtons6->Print = displayToolBarButton103;
			displayToolBarButtons6->Save = displayToolBarButton104;
			displayToolBarButtons6->Setup = displayToolBarButton105;
			displayToolBarButtons6->XYZoomOn = displayToolBarButton106;
			displayToolBarButtons6->ZoomIn = displayToolBarButton107;
			displayToolBarButtons6->ZoomMode = displayToolBarButton108;
			displayToolBarButtons6->ZoomNext = displayToolBarButton109;
			displayToolBarButtons6->ZoomOff = displayToolBarButton110;
			displayToolBarButtons6->ZoomOut = displayToolBarButton111;
			displayToolBarButtons6->ZoomPrevious = displayToolBarButton112;
			displayToolBar6->Buttons = displayToolBarButtons6;
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
			displayToolBar6->Position = toolBarPosition6;
			this->scope1->ToolBar = displayToolBar6;
			displayTrails6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			this->scope1->Trails = displayTrails6;
			this->scope1->Visible = true;
			scopeXAxis6->Align = Mitov::PlotLab::ViewAlign::Bottom;
			displayTitleLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(1))));
			displayTitleLabel11->Text = L"Universal Time (Hours)";
			scopeXAxis6->AxisLabel = displayTitleLabel11;
			displayViewBackground29->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis6->Background = displayViewBackground29;
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
			displayGridLineSettings27->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings11->Lines = displayGridLineSettings27;
			displayGridLineSettings28->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings11->ZeroLine = displayGridLineSettings28;
			scopeXAxis6->DataView = displayGridDirectionalLinesSettings11;
			scopeXAxis6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			scopeXAxis6->Format = axisFormat11;
			scopeXAxis6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeXAxis6.InternalData")));
			ticksStart11->StartFrom = 0;
			majorTicks11->StartFrom = ticksStart11;
			majorTicks11->Step = 10;
			scopeXAxis6->MajorTicks = majorTicks11;
			maxScopeAxisValue6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"maxScopeAxisValue6.InternalData")));
			displayOptionalValue61->Enabled = false;
			displayOptionalValue61->Value = 1000;
			displayValueRange31->High = displayOptionalValue61;
			displayOptionalValue62->Enabled = false;
			displayOptionalValue62->Value = -1000;
			displayValueRange31->Low = displayOptionalValue62;
			maxScopeAxisValue6->Range = displayValueRange31;
			basicAxisValue11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue11.InternalData")));
			basicAxisValue11->Value = 1024;
			maxScopeAxisValue6->Tick = basicAxisValue11;
			maxScopeAxisValue6->Value = 1024;
			scopeXAxis6->Max = maxScopeAxisValue6;
			scopeMaxSample6->Value = static_cast<System::UInt32>(1024);
			scopeXAxis6->MaxSample = scopeMaxSample6;
			scopeAxisValue6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeAxisValue6.InternalData")));
			displayOptionalValue63->Enabled = false;
			displayOptionalValue63->Value = 1000;
			displayValueRange32->High = displayOptionalValue63;
			displayOptionalValue64->Enabled = false;
			displayOptionalValue64->Value = -1000;
			displayValueRange32->Low = displayOptionalValue64;
			scopeAxisValue6->Range = displayValueRange32;
			basicAxisValue12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicAxisValue12.InternalData")));
			basicAxisValue12->Value = 0;
			scopeAxisValue6->Tick = basicAxisValue12;
			scopeAxisValue6->Value = 0;
			scopeXAxis6->Min = scopeAxisValue6;
			minorTicks11->Count = static_cast<System::UInt32>(0);
			scopeXAxis6->MinorTicks = minorTicks11;
			axisToolBar11->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar11->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons11->ZoomIn = displayToolBarButton113;
			axisToolBarButtons11->ZoomOff = displayToolBarButton114;
			axisToolBarButtons11->ZoomOneDir = displayToolBarButton115;
			axisToolBarButtons11->ZoomOut = displayToolBarButton116;
			axisToolBar11->Buttons = axisToolBarButtons11;
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
			scopeXAxisUnitScale6->Exponent = 0;
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
			this->scope1->XAxis = scopeXAxis6;
			pinList12->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList12.ConnectionData")));
			this->scope1->XInputPins = pinList12;
			scopeYAxis6->Align = Mitov::PlotLab::ViewAlign::Left;
			scopeAutoScaling6->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace11->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace11->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling6->SpaceAbove = scopeAutoScalingSpace11;
			scopeAutoScalingSpace12->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace12->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling6->SpaceBelow = scopeAutoScalingSpace12;
			scopeYAxis6->AutoScaling = scopeAutoScaling6;
			displayTitleLabel12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 13, (gcnew Vcl::FontStyles(1))));
			displayTitleLabel12->Text = L"K-C (m)";
			scopeYAxis6->AxisLabel = displayTitleLabel12;
			displayViewBackground30->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis6->Background = displayViewBackground30;
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
			displayGridLineSettings29->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings12->Lines = displayGridLineSettings29;
			displayGridLineSettings30->Pen = (gcnew Vcl::VclPen(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), Vcl::PenMode::Copy, 
				Vcl::PenStyle::Solid, 1));
			displayGridDirectionalLinesSettings12->ZeroLine = displayGridLineSettings30;
			scopeYAxis6->DataView = displayGridDirectionalLinesSettings12;
			scopeYAxis6->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				Vcl::FontCharset::Default, Vcl::FontPitch::Default, true, 11, (gcnew Vcl::FontStyles(0))));
			scopeYAxis6->Format = axisFormat12;
			scopeYAxis6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeYAxis6.InternalData")));
			ticksStart12->StartFrom = 0;
			majorTicks12->StartFrom = ticksStart12;
			majorTicks12->Step = 10;
			scopeYAxis6->MajorTicks = majorTicks12;
			basicScopeAxisValue11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue11.InternalData")));
			displayOptionalValue67->Enabled = false;
			displayOptionalValue67->Value = 1000;
			displayValueRange34->High = displayOptionalValue67;
			displayOptionalValue68->Enabled = false;
			displayOptionalValue68->Value = -1000;
			displayValueRange34->Low = displayOptionalValue68;
			basicScopeAxisValue11->Range = displayValueRange34;
			basicScopeAxisValue11->Value = 1000;
			scopeYAxis6->Max = basicScopeAxisValue11;
			basicScopeAxisValue12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"basicScopeAxisValue12.InternalData")));
			displayOptionalValue69->Enabled = false;
			displayOptionalValue69->Value = 1000;
			displayValueRange35->High = displayOptionalValue69;
			displayOptionalValue70->Enabled = false;
			displayOptionalValue70->Value = -1000;
			displayValueRange35->Low = displayOptionalValue70;
			basicScopeAxisValue12->Range = displayValueRange35;
			basicScopeAxisValue12->Value = -1000;
			scopeYAxis6->Min = basicScopeAxisValue12;
			minorTicks12->Count = static_cast<System::UInt32>(0);
			scopeYAxis6->MinorTicks = minorTicks12;
			axisToolBar12->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar12->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons12->ZoomIn = displayToolBarButton117;
			axisToolBarButtons12->ZoomOff = displayToolBarButton118;
			axisToolBarButtons12->ZoomOneDir = displayToolBarButton119;
			axisToolBarButtons12->ZoomOut = displayToolBarButton120;
			axisToolBar12->Buttons = axisToolBarButtons12;
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
			this->scope1->YAxis = scopeYAxis6;
			displayZoom6->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->scope1->Zooming = displayZoom6;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CloseButton->Location = System::Drawing::Point(17, 8);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 0;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &PhotometryPlotWindow2::CloseButton_Clicked);
			// 
			// ClearButton
			// 
			this->ClearButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ClearButton->Location = System::Drawing::Point(128, 8);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 23);
			this->ClearButton->TabIndex = 1;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &PhotometryPlotWindow2::ClearButton_Clicked);
			// 
			// PhotometryPlotWindow2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 613);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"PhotometryPlotWindow2";
			this->Text = L"Photometry Plot Window";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->VCPlotScope))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scope1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void CloseButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
			 PhotometryPlotWindow2::Hide();
			 }
private: System::Void ClearButton_Clicked(System::Object^  sender, System::EventArgs^  e) {
		 }
public:  System::Void HideTheDialog(void) {
			 PhotometryPlotWindow2::FormPtr->Hide();
		 }
public:  System::Void ShowTheDialog(void) {
			 PhotometryPlotWindow2::FormPtr->Show();
		 }
public:  System::Void AddGraphPoint(DIFFPHOT *dptr) {

			 int graphNum;
			 float diff, diffErr, x;
			 static bool First=true;

			 if (First || (pptr == NULL)) {
				 PhotometryPlotWindow2::FormPtr->VCPlotScope->Channels->Add(4);
				 PhotometryPlotWindow2::FormPtr->VCPlotScope->Channels[0].Name = "B";
				 PhotometryPlotWindow2::FormPtr->VCPlotScope->Channels[1].Name = "V";
				 PhotometryPlotWindow2::FormPtr->VCPlotScope->Channels[2].Name = "R";
				 PhotometryPlotWindow2::FormPtr->VCPlotScope->Channels[3].Name = "I";
				 PhotometryPlotWindow2::FormPtr->scope1->Channels->Add(4);
				 PhotometryPlotWindow2::FormPtr->scope1->Channels[0].Name = "B";
				 PhotometryPlotWindow2::FormPtr->scope1->Channels[1].Name = "V";
				 PhotometryPlotWindow2::FormPtr->scope1->Channels[2].Name = "R";
				 PhotometryPlotWindow2::FormPtr->scope1->Channels[3].Name = "I";
			 }

			 switch(pptr->Filter) {
				 case 'B':
					 graphNum = 0;
					 break;
				 case 'V':
					 graphNum = 1;
					 break;
				 case 'R':
					 graphNum = 2;
					 break;
				 case 'I':
					 graphNum = 3;
			 }
			 if (PhotometryPlotWindow2::FormPtr->VersusUT) {
				 x = pptr->UT;
			 } else {
				 x = ((float) (pptr->HJD - 2450000.5));
			 }
			 diff = -(pptr->VarMag - pptr->CmpMag);
			 diffErr = sqrt(pptr->VarMagErr*pptr->VarMagErr + 
				            pptr->CmpMagErr*pptr->CmpMagErr);
			 PhotometryPlotWindow2::FormPtr->VCPlotScope->Channels[0]->Data->AddXYPoint(x, diff);
			 diff = -(pptr->ChkMag - pptr->CmpMag);
			 diffErr = sqrt(pptr->ChkMagErr*pptr->ChkMagErr + 
				            pptr->CmpMagErr*pptr->CmpMagErr);
			 PhotometryPlotWindow2::FormPtr->scope1->Channels[0]->Data->AddXYPoint(x, diff);
			 PhotometryPlotWindow2::FormPtr->Refresh();
			 usleep(100000);
		 }
};
}
