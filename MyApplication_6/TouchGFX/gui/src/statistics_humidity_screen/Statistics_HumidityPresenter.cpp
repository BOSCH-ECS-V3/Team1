#include <gui/statistics_humidity_screen/Statistics_HumidityView.hpp>
#include <gui/statistics_humidity_screen/Statistics_HumidityPresenter.hpp>

Statistics_HumidityPresenter::Statistics_HumidityPresenter(Statistics_HumidityView& v)
    : view(v)
{

}

void Statistics_HumidityPresenter::activate()
{

}

void Statistics_HumidityPresenter::deactivate()
{

}

void Statistics_HumidityPresenter::set_screen_brightness(int brightness)
{
 view.set_screen_brightness(brightness);
}

void Statistics_HumidityPresenter::STATISTICS_humidity(int statistics_humidity[24], int statistics_index)
{
	view.STATISTICS_humidity(statistics_humidity, statistics_index);
}
