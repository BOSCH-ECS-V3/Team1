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
protected:
};

#endif // TIME_SETTINGSVIEW_HPP
