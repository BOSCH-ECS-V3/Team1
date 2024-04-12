#ifndef DEFAULTVIEWVIEW_HPP
#define DEFAULTVIEWVIEW_HPP

#include <gui_generated/defaultview_screen/DefaultViewViewBase.hpp>
#include <gui/defaultview_screen/DefaultViewPresenter.hpp>

class DefaultViewView : public DefaultViewViewBase
{
public:
    DefaultViewView();
    virtual ~DefaultViewView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void update_Clock(int Clock_Values[]);
    virtual void handleTickEvent();
    virtual void current_Sensor_values(int current_Sensor_values[5]);
    virtual void SEND_Error_ID(int Error_ID);


    // Variables for storing sensor information

    int Temperature_Sensor_INSIDE_values ;
    int Temperature_Sensor_OUTSIDE_value ;
    int Humidity_Sensor_value ;
    int Pressure_Sensor_value ;
    int Ambient_Light_Sensor_value ;
    int Gas_Sensor_value ;

    // Variables for clock settings

    int analogHours ;
    int analogMinutes ;
    int analogSeconds ;

    // Variables for Alert msg

    int current_ERROR_ID;

protected:
};

#endif // DEFAULTVIEWVIEW_HPP
