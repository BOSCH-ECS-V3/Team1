#include <gui/alarm_settings_screen/Alarm_SettingsView.hpp>

Alarm_SettingsView::Alarm_SettingsView()
{

}

void Alarm_SettingsView::setupScreen()
{
	Alarm_SettingsViewBase::setupScreen();
}

void Alarm_SettingsView::tearDownScreen()
{
	Alarm_SettingsViewBase::tearDownScreen();
}

void Alarm_SettingsView::RECEIVE_Permission(int Permission_ALERT_STATE)
{
	/*
	 * Read current Permission state from Model and send display it in label
	 */
	Permission_STATE = Permission_ALERT_STATE;


		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", Permission_STATE);
		textArea1.invalidate();

}


void Alarm_SettingsView::btn_Permission_ON()
{
	/*
	 * If Permission_ON btn is pressed , change permission state
	 * and send it to model
	 */
	Permission_STATE = 1 ;
	presenter->SEND_Permission(Permission_STATE);

}

void Alarm_SettingsView::btn_Permission_OFF()
{
	/*
	 * If Permission_OFF btn is pressed , change permission state
	 * and send it to model
	 */
	Permission_STATE = 0 ;
	presenter->SEND_Permission(Permission_STATE);
}

void SEND_Permission(int Permission_State)
{
	// empty for now
}
void Alarm_SettingsView::set_screen_brightness(int brightness)
{

	/*
	 * This func is used for automatic screen brightness adjustment
	 */
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}

