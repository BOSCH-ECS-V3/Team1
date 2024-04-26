#include <gui/time_settings_screen/Time_SettingsView.hpp>
#include <gui/time_settings_screen/Time_SettingsPresenter.hpp>

Time_SettingsPresenter::Time_SettingsPresenter(Time_SettingsView& v)
    : view(v)
{

}

void Time_SettingsPresenter::activate()
{

}

void Time_SettingsPresenter::deactivate()
{

}

void Time_SettingsPresenter::current_Clock(int Clock_Value[3])
{
	/*
	 * Send current clock values to view page
	 */
	view.current_Clock(Clock_Value);
}
void Time_SettingsPresenter::update_Clock(int Clock_Value[3])
{
	/*
	 * Receive new Clock values for UI , if used changed manually Time parameters.
	 */
	model->update_Clock(Clock_Value);
}

void Time_SettingsPresenter::set_screen_brightness(int brightness)
{
	/*
	 * Set screen brightness
	 */
	view.set_screen_brightness(brightness);
}
