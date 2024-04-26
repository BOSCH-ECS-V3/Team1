#ifndef DEFAULTVIEWPRESENTER_HPP
#define DEFAULTVIEWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DefaultViewView;

class DefaultViewPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DefaultViewPresenter(DefaultViewView& v);

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

    virtual ~DefaultViewPresenter() {}

    virtual void update_Clock(int Clock_Values[]);

    virtual void current_Sensor_values(int current_Sensor_values[], int GAS_Preheat_FLAG );

    virtual void SEND_Error_ID(int Error_ID, int SNOOZE_FLAG_TEMPIN ,int SNOOZE_FLAG_GAS , int SNOOZE_FLAG_TEMPOUT , int SNOOZE_FLAG_HUMIDITY, int SNOOZE_FLAG_PRESSURE , int SNOOZE_FLAG_AMBIENT);

    virtual void Snooze_system(int snooze_state, int flag_TempIN , int flag_Gas , int flag_TempOUT , int flag_Humidity, int flag_Pressure , int flag_Ambient);

    virtual void set_screen_brightness(int brightness);


private:
    DefaultViewPresenter();

    DefaultViewView& view;
};

#endif // DEFAULTVIEWPRESENTER_HPP
