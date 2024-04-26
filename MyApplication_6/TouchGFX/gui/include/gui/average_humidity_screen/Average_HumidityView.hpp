#ifndef AVERAGE_HUMIDITYVIEW_HPP
#define AVERAGE_HUMIDITYVIEW_HPP

#include <gui_generated/average_humidity_screen/Average_HumidityViewBase.hpp>
#include <gui/average_humidity_screen/Average_HumidityPresenter.hpp>

class Average_HumidityView : public Average_HumidityViewBase
{
public:
    Average_HumidityView();
    virtual ~Average_HumidityView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void send_average_Humidity(int avrDayHumidity_res , int avrWeekHumidity_res , int avrMonthHumidity_res);
protected:
};

#endif // AVERAGE_HUMIDITYVIEW_HPP
