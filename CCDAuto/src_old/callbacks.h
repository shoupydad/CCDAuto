#include <gnome.h>

void
on_open1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_save1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_save_as1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_exit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_link1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_unlink1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_temp_on1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_temp_off1_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_u1_activate                         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_b1_activate                         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_v1_activate                         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_r1_activate                         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_i1_activate                         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_c1_activate                         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_exposure1_activate                  (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_readout1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_series1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_unlink_yes_click                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_unlink_on_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_unlink_cancel_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_unlink_no_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit_save_yes_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit_save_no_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit_save_cancel_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit_save_yes_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MessageBoxOkay_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void StatusPrint(char *Message);

void
on_expose_single_frame_activate        (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_start_series_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_queryr_dialog_ok_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_queryr_dialog_ok_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ForceDarkFrameButton_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ExposureSettingOkay_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettings_activate             (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_SeriesSettings_activate             (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_SingleSettingsForceDarkCheck_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettingsCCDBinning1x1Button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsCCDBinning2x2Button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsCCDBinning3x3Button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsOkay_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsCancel_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsWhichCCDButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettingsCCDBinning1x1Button_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettingsCCDBinning2x2Button_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettingsCCDBinning3x3Button_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsWhichCCDImageButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettings1x1BinningButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettings2x2BinningButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettings3x3BinningButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsUButton_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsBButton_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsVButoon_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsRButton_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsIButton_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsOkay_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsForceDarkCheck_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsVButton_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_CurrentImagePixMap_expose_event     (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_edit_an_object_activate             (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_ObjectListOkButton_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListSelectButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListClearButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListCancelButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
viewEdit_object_list_activate          (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_ObjectListEditButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListCancelButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_DownLoadingCancelButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);
int updateStatusInfo(gpointer data);

void
on_ObjectListNewButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsStartASAPButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MainSeriesPauseButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_MainSeriesResumeButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_MainSeriesPauseButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_MainSeriesCancel_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_MainSeriesResumeButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_SaveCurrentImageOkButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_SaveCurrentImageCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_expose_dark_frames_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_expose_flat_frames_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_DarkFrameSettingsOkay_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_DarkFrameSettingsCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_DarkFrameSettingsExecButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_DarkFrameSettingsImagingButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettings1x1Button_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettings2x2Button_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettings3x3Button_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsMedian_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsUButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsBButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsVButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsRButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsIButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsImagingButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettings1x1Button_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettings2x2Button_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettings3x3Button_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsMedian_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsUButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsBButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsVButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsRButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsIButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsOkay_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_FlatFrameSettingsCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_FlatFrameSettingsExecButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsSaveDarkButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettingsDarkSaveButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_DarkFrameSettingsSaveDarkButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsSaveFlatButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsSaveDarkButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_OpenFileOkayButton_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_OpenFileCancelButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsCancelButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListEditButton_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ObjectListCancelButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListApplyButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_observatory_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_ObsSettingsOKButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObsSettingsApplyButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObsSettingsCancelButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_OverWriteYesButton_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_OverWriteNoButton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_OverWriteCancelButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_track___accumulate1_activate        (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_StackSettingsSaveDarkButton_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsSaveLightButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsOkButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsCancelButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsExecButton_enter       (GtkButton       *button,
                                        gpointer         user_data);

void
on_expose_stack_frames1_activate       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_StackSettingsOkay_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsCancel_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsOkayButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsCancelButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackeSettingsExecButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsExecButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_CurrentImageViewport_button_press_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageViewport_button_release_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageViewport_configure_event
                                        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageViewport_expose_event   (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageViewport_motion_notify_event
                                        (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

void
on_CurrentWindowCloseButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowPhotoButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentImageAstroButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_CurrentImageDrawingArea_button_press_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageDrawingArea_button_release_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageDrawingArea_configure_event
                                        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageDrawingArea_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_CurrentImageDrawingArea_motion_notify_event
                                        (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

void
on_CurrentImageDrawingArea_drag_begin  (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        gpointer         user_data);

void
on_CurrentImageDrawingArea_drag_end    (GtkWidget       *widget,
                                        GdkDragContext  *drag_context,
                                        gpointer         user_data);

void
on_PickAlignStarOkButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_PickAlignStarApplyButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_PickAlignStarCancelButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentImageApplyButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentImageBackSpin_changed        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_CurrentImageRangeSpin_changed       (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_CurrentImageGammaSpin_changed       (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_CurrentImageRangeSpin_changed       (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_StackSettingsSaveLightButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsWhichCCDButton_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsCCDBinning2x2Button_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsSaveDarkButton_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsCCDBinning1x1Button_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettingsCCDBinning3x3Button_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ObjectListComboEntry_changed        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_ObjectListCancelButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_show_current_image_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_open1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_start_autofocus_activate            (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_SingleSettingsExecute_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsExecute_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_expose_series_frames_activate       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_CurrentWindowAutoFocus_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_SingleSettingsApply_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowExposeButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_YesNoDialogYesButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_YesNoDialogNoButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_YesNoDialogCancelButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_OkayDialogOKButton_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_OkayDialogCancelButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsApplyButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_DarkFrameSettingsApplyButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_FlatFrameSettingsApplyButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_StackSettingsApplyButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_link_to_imaging_ccd_activate        (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_turn_on_imaging_temp_activate       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_turn_off_imaging_temp_activate      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_link_to_spectro_ccd_activate        (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_turn_on_spectro_temp_activate       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_turn_off_spectro_temp_activate      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_unlink_imaging_ccd_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_unlink_spectro_ccd_activate         (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_ProgressDialogCancelButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_ObjectListSelectButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettings2x2BinningButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MainSeriesStopButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_PhotometrySettingsAutoFindButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_PhotometrySettingsOffsetSkyButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_PhotometrySettingsLogResultsButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_PhotometrySettingsOKButton_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_PhotometrySettingsApplyButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_PhotometrySettingsCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowFindListButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowMeasureListButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowPhotoButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_PhotometrySettingsPlotButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_CurrentWindowDefineListButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_DefineListAddButton_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_DefineListDeleteButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_DefineListOkayButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_DefineListCancelButton_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_DefineListClearButton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_PhotometrySettingsBatchButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_PhotometrySettingsStopButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowApplyButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_DefineListAutoButton_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWndowAstrometryButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_AstrometryDialogOKButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_AstrometryDialogSolveButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_AstrometryDialogCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CoordinateDialogOKButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_CoordinateDialogCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CoordinateDialogAddButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_CoordinatesDialogRemoveButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowSlitButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowGuideButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_spectrograph_slit_activate          (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_SlitGuidingOnCheckButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SpectroSettingsOKButton_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_SpectroSettingsCancelButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsAutoBumpButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_guiding_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_show_guiding_window_activate        (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_CurrentWindowCalibrateSlitButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuidingSlitSettingsDialogOkButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuidingSlitSettingsDialogCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuideFrameWindowCloseButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuideFrameWindowSelectButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuideFrameWindowSettingsButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuidingFrameWindowOnOffButton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GuidingFrameWindowToSlit_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuidingFrameWindowCalSlitButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GuideFrameWindowApplyButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowCloseButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowExposeButton_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowDefineListButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowMeasureListButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CurrentWindowPhotoButton_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuideFrameWindowLogButton_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GuidingSlitSettingsDialogAcquireButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuideFrameWindowExoseButton_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuideFrameWindowExposeButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_guiding_slit_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

gboolean
on_GuideFrameWindowDrawingArea_button_press_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_GuideFrameWindowDrawingArea_button_release_event
                                        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_GuideFrameWindowDrawingArea_configure_event
                                        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_GuideFrameWindowDrawingArea_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_GuideFrameWindowDrawingArea_motion_notify_event
                                        (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

void
on_GuidingProgressDialogCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_GuidingProgressDialogCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_cameras_settings_activate           (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_CameraSettingsDialogOKButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_CameraSettingsDialogCancelButton_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_SeriesSettingsCButton_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FlatFrameSettingsCButton_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettings1x1Button_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettings2x2Button_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SingleSettings3x3Button_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettings1x1Button_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettings3x3Button_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SeriesSettings2x2Button_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettings1x1Button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettings2x2Button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_StackSettings3x3Button_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
