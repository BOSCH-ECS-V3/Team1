#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsideView.hpp>
#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsidePresenter.hpp>

Statistics_Temperature_InsidePresenter::Statistics_Temperature_InsidePresenter(Statistics_Temperature_InsideView& v)
    : view(v)
{

}

void Statistics_Temperature_InsidePresenter::activate()
{

}

void Statistics_Temperature_InsidePresenter::deactivate()
{

}
void Statistics_Temperature_InsidePresenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}

void Statistics_Temperature_InsidePresenter::STATISTICS_tempIN(int statistics_tempIN[24], int tempIN_index , int average_day)
{
	/*
	 * This function is used to pass statistics values to tempIN statistics char
	 * statistics_tempIN array are pasts 24 hour values and statistics index is current hour to place
	 * value
	 */
	view.STATISTICS_tempIN(statistics_tempIN, tempIN_index , average_day);
}
