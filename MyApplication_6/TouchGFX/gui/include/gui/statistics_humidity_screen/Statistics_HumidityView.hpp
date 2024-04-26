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
    virtual void STATISTICS_humidity(int statistics_humidity[24], int statistics_index);


protected:
    int humidity_val[24] ;
    int current_index = 0 ;

};

#endif // STATISTICS_HUMIDITYVIEW_HPP
