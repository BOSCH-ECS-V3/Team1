#ifndef STATISTICS_HUMIDITYVIEW_HPP
#define STATISTICS_HUMIDITYVIEW_HPP

#include <gui_generated/statistics_humidity_screen/Statistics_HumidityViewBase.hpp>
#include <gui/statistics_humidity_screen/Statistics_HumidityPresenter.hpp>

class Statistics_HumidityView : public Statistics_HumidityViewBase
{
public:
    Statistics_HumidityView();
    virtual ~Statistics_HumidityView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void set_screen_brightness(int brightness);
protected:
};

#endif // STATISTICS_HUMIDITYVIEW_HPP
