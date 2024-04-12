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
	Permission_STATE = Permission_ALERT_STATE;


		Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", Permission_STATE);
		textArea1.invalidate();

}


void Alarm_SettingsView::btn_Permission_ON()
{
	Permission_STATE = 1 ;
	presenter->SEND_Permission(Permission_STATE);

}

void Alarm_SettingsView::btn_Permission_OFF()
{
	Permission_STATE = 0 ;
	presenter->SEND_Permission(Permission_STATE);
}

void SEND_Permission(int Permission_State)
{

}

