#ifndef ALARM_SETTINGSVIEW_HPP
#define ALARM_SETTINGSVIEW_HPP

#include <gui_generated/alarm_settings_screen/Alarm_SettingsViewBase.hpp>
#include <gui/alarm_settings_screen/Alarm_SettingsPresenter.hpp>

class Alarm_SettingsView : public Alarm_SettingsViewBase
{
public:
    Alarm_SettingsView();
    virtual ~Alarm_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void btn_Permission_OFF();
    virtual void btn_Permission_ON();
    virtual void RECEIVE_Permission(int Permission_ALERT_STATE);
    virtual void set_screen_brightness(int brightness);

    int Permission_STATE ;

protected:
};

#endif // ALARM_SETTINGSVIEW_HPP
