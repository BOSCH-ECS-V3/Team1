#include <gui/time_settings_screen/Time_SettingsView.hpp>

Time_SettingsView::Time_SettingsView()
{

}
void Time_SettingsView::setupScreen()
{
	Time_SettingsViewBase::setupScreen();
	analogHours = digitalClock_RealTime.getCurrentHour();
	analogMinutes = digitalClock_RealTime.getCurrentMinute();
	analogSeconds = digitalClock_RealTime.getCurrentSecond();
}
void Time_SettingsView::tearDownScreen()
{
	Time_SettingsViewBase::tearDownScreen();
}

void Time_SettingsView::current_Clock(int Clock_Values[])
{
	analogHours = Clock_Values[0];
	analogMinutes = Clock_Values[1];
	analogSeconds = Clock_Values[2];
}
void update_Clock(int Clock_Values[])
{

}

void Time_SettingsView::Set_Current_Time()
{


	digitalClock_RealTime.setTime24Hour(update_Hours, update_Minutes, update_Seconds);

	analogHours = update_Hours ;
	analogMinutes = update_Minutes;
	analogSeconds = update_Seconds;

	int updated_values[3]={update_Hours, update_Minutes, update_Seconds};
	presenter->update_Clock(updated_values);
}
void Time_SettingsView::handleTickEvent()
{
	digitalClock_RealTime.setTime24Hour(analogHours, analogMinutes, analogSeconds);
}
void Time_SettingsView::Hours_Up()
{

	update_Hours++;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Hours_Down()
{

	update_Hours--;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Minutes_Up()
{

	update_Minutes++;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Minutes_Down()
{

	update_Minutes--;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Seconds_Up()
{

	update_Seconds++;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();
}
void Time_SettingsView::Seconds_Down()
{

	update_Seconds--;

	digitalClock1.setTime24Hour(update_Hours, update_Minutes, update_Seconds);
	digitalClock1.invalidate();

}





