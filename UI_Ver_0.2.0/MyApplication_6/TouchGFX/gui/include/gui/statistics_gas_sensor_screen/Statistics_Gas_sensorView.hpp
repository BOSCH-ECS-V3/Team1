#ifndef STATISTICS_GAS_SENSORVIEW_HPP
#define STATISTICS_GAS_SENSORVIEW_HPP

#include <gui_generated/statistics_gas_sensor_screen/Statistics_Gas_sensorViewBase.hpp>
#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorPresenter.hpp>

class Statistics_Gas_sensorView : public Statistics_Gas_sensorViewBase
{
public:
    Statistics_Gas_sensorView();
    virtual ~Statistics_Gas_sensorView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void set_brightness_level(int brightness);
protected:
};

#endif // STATISTICS_GAS_SENSORVIEW_HPP
