#include <gui/date_settings_screen/Date_SettingsView.hpp>
#include <gui/date_settings_screen/Date_SettingsPresenter.hpp>

Date_SettingsPresenter::Date_SettingsPresenter(Date_SettingsView& v)
    : view(v)
{

}

void Date_SettingsPresenter::activate()
{

}

void Date_SettingsPresenter::deactivate()
{

}
void Date_SettingsPresenter::current_Date_value(int current_Date_value[3])
{
	// sending current information to view.date ->
	view.current_Date_value(current_Date_value);
}
void Date_SettingsPresenter::update_Date(int Date_Value[3])
{
	// updating date values based on user adjustment in view
	model->update_Date(Date_Value); // passing values to model
}
void Date_SettingsPresenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}
