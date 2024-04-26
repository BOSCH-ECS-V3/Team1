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
	/*
	 * Set brightness level of the screen
	 */
 view.set_screen_brightness(brightness);
}

void Statistics_HumidityPresenter::STATISTICS_humidity(int statistics_humidity[24], int statistics_index)
{
	/*
	 * This function is used to pass statistics values to humidity statistics char
	 * statistics_humidity array are pasts 24 hour values and statistics index is current hour to place
	 * value
	 */
	view.STATISTICS_humidity(statistics_humidity, statistics_index);
}
