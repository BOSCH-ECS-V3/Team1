#ifndef TIME_SETTINGSVIEW_HPP
#define TIME_SETTINGSVIEW_HPP

#include <gui_generated/time_settings_screen/Time_SettingsViewBase.hpp>
#include <gui/time_settings_screen/Time_SettingsPresenter.hpp>

class Time_SettingsView : public Time_SettingsViewBase
{
public:
    Time_SettingsView();
    virtual ~Time_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void Hours_Up();
    virtual void Hours_Down();
    virtual void Minutes_Up();
    virtual void Minutes_Down();
    virtual void Seconds_Up();
    virtual void Seconds_Down();

    virtual void handleTickEvent();
    virtual void Set_Current_Time();
    virtual void current_Clock(int Clock_Values[]); // This is functuon to update clock from model
    virtual void set_brightness_level(int brightness);


    int update_Hours = 0;
    int update_Minutes = 0;
    int update_Seconds = 0;

    int tickCounter;
    int analogHours;
    int analogMinutes;
    int analogSeconds;


protected:
};

#endif // TIME_SETTINGSVIEW_HPP
