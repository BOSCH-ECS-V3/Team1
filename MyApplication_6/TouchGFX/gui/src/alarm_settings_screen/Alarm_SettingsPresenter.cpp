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
	model->SEND_Permission(Permission_STATE);
}
void Alarm_SettingsPresenter::RECEIVE_Permission(int Permission_STATE)
{
	view.RECEIVE_Permission(Permission_STATE);
}
