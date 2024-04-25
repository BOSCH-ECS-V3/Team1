#include <gui/time_settings_screen/Time_SettingsView.hpp>

Time_SettingsView::Time_SettingsView()
{

}
void Time_SettingsView::setupScreen()
{
	Time_SettingsViewBase::setupScreen();
}
void Time_SettingsView::tearDownScreen()
{
	Time_SettingsViewBase::tearDownScreen();
}

void Time_SettingsView::current_Clock(int Clock_Values[])
{
	/*
	 * Receive clock values from model and update view page
	 */
	analogHours = Clock_Values[0];
	analogMinutes = Clock_Values[1];
	analogSeconds = Clock_Values[2];
}
void update_Clock(int Clock_Values[])
{

}

void Time_SettingsView::Set_Current_Time()
{

	/*
	 * if submit btn from view page is presset , pass new parameters to the model page
	 */
	digitalClock_RealTime.setTime24Hour(update_Hours, update_Minutes, update_Seconds);

	analogHours = update_Hours ;
	analogMinutes = update_Minutes;
	analogSeconds = update_Seconds;


	// pass updated values to the module
	int updated_values[3]={update_Hours, update_Minutes, update_Seconds};
	presenter->update_Clock(updated_values);

}
void Time_SettingsView::handleTickEvent()
{
	/*
	 * Update screen values on every tick
	 */
	digitalClock_RealTime.setTime24Hour(analogHours, analogMinutes, analogSeconds);
}
void Time_SettingsView::Hours_Up()
{

	/*
	 * If hours btn up is pressed , increase hours label val
	 */
	update_Hours++;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Hours_Down()
{
	/*
	 * If hours btn down is pressed , decrease hours label val
	 */
	update_Hours--;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Minutes_Up()
{

	/*
	 * If minutes btn up is pressed , increase minutes label val
	 */
	update_Minutes++;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Minutes_Down()
{
	/*
	 * If minutes btn down is pressed , decrease minutes label val
	 */
	update_Minutes--;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Seconds_Up()
{
	/*
	 * If seconds btn up is pressed , increase seconds label val
	 */

	update_Seconds++;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Seconds_Down()
{
	/*
	 * If seconds btn up is pressed , decrease seconds label val
	 */

	update_Seconds--;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();

}
void Time_SettingsView::set_screen_brightness(int brightness)
{
	/*
	 * Set brightness level of the screen
	 */
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}





