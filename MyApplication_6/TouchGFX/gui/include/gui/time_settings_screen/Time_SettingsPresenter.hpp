#ifndef TIME_SETTINGSPRESENTER_HPP
#define TIME_SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Time_SettingsView;

class Time_SettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Time_SettingsPresenter(Time_SettingsView& v);

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

    virtual ~Time_SettingsPresenter() {}

    virtual void current_Clock(int Clock_Values[]);
    virtual void update_Clock(int Clock_Values[]);
    virtual void set_screen_brightness(int brightness);
private:
    Time_SettingsPresenter();

    Time_SettingsView& view;
};

#endif // TIME_SETTINGSPRESENTER_HPP
