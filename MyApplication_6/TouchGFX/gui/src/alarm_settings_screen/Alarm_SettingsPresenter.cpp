#include <gui/alarm_settings_screen/Alarm_SettingsView.hpp>
#include <gui/alarm_settings_screen/Alarm_SettingsPresenter.hpp>

Alarm_SettingsPresenter::Alarm_SettingsPresenter(Alarm_SettingsView& v)
: view(v)
{

}

void Alarm_SettingsPresenter::activate()
{

}

void Alarm_SettingsPresenter::deactivate()
{

}
void Alarm_SettingsPresenter::SEND_Permission(int Permission_STATE)
{
	/*
	 * This function is used for sending Permission state from VIEW to model , if user manually
	 * turn ON/OFF Notification option.
	 */
	model->SEND_Permission(Permission_STATE);
}
void Alarm_SettingsPresenter::RECEIVE_Permission(int Permission_STATE)
{
	/*
	 * This function is used for sending Permission state from model to VIEW , storing current Permission
	 * state.
	 */
	view.RECEIVE_Permission(Permission_STATE);
}

void Alarm_SettingsPresenter::set_screen_brightness(int brightness)
{
	/*
	 * This function is used for adjustment screen brightness
	 */
	view.set_screen_brightness(brightness);
}
