#include <gui/average_humidity_screen/Average_HumidityView.hpp>
#include <gui/average_humidity_screen/Average_HumidityPresenter.hpp>

Average_HumidityPresenter::Average_HumidityPresenter(Average_HumidityView& v)
    : view(v)
{

}

void Average_HumidityPresenter::activate()
{

}

void Average_HumidityPresenter::deactivate()
{

}
void Average_HumidityPresenter::send_average_Humidity(int avrDayHumidity_res , int avrWeekHumidity_res , int avrMonthHumidity_res)
{
	view.send_average_Humidity(avrDayHumidity_res , avrWeekHumidity_res , avrMonthHumidity_res);
}
