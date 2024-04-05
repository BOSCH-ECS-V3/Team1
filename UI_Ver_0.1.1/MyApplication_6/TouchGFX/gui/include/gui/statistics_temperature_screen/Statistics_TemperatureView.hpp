#ifndef STATISTICS_TEMPERATUREVIEW_HPP
#define STATISTICS_TEMPERATUREVIEW_HPP

#include <gui_generated/statistics_temperature_screen/Statistics_TemperatureViewBase.hpp>
#include <gui/statistics_temperature_screen/Statistics_TemperaturePresenter.hpp>

class Statistics_TemperatureView : public Statistics_TemperatureViewBase
{
public:
    Statistics_TemperatureView();
    virtual ~Statistics_TemperatureView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STATISTICS_TEMPERATUREVIEW_HPP
