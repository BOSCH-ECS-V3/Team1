#ifndef DATE_SETTINGSPRESENTER_HPP
#define DATE_SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Date_SettingsView;

class Date_SettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Date_SettingsPresenter(Date_SettingsView& v);

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

    virtual ~Date_SettingsPresenter() {}
    virtual void current_Date_value(int current_Date_value[]);
    virtual void update_Date(int Date_Values[]); // func for passsing view values to model

private:
    Date_SettingsPresenter();

    Date_SettingsView& view;
};

#endif // DATE_SETTINGSPRESENTER_HPP
