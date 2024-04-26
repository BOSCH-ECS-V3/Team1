#ifndef ALARM_SETTINGSPRESENTER_HPP
#define ALARM_SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Alarm_SettingsView;

class Alarm_SettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Alarm_SettingsPresenter(Alarm_SettingsView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();
    virtual void SEND_Permission(int Permission_STATE);
    virtual void RECEIVE_Permission(int Permission_ALERT_STATE);
    virtual void set_screen_brightness(int brightness);
    virtual ~Alarm_SettingsPresenter() {}

private:
    Alarm_SettingsPresenter();

    Alarm_SettingsView& view;
};

#endif // ALARM_SETTINGSPRESENTER_HPP
