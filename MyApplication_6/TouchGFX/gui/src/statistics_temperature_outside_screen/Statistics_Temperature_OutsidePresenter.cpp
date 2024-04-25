#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsideView.hpp>
#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsidePresenter.hpp>

Statistics_Temperature_OutsidePresenter::Statistics_Temperature_OutsidePresenter(Statistics_Temperature_OutsideView& v)
: view(v)
{

}

void Statistics_Temperature_OutsidePresenter::activate()
{

}

void Statistics_Temperature_OutsidePresenter::deactivate()
{

}

void Statistics_Temperature_OutsidePresenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}

void Statistics_Temperature_OutsidePresenter::STATISTICS_tempOUT(int statistics_tempOUT[24], int statistics_index)
{
	/*
	 * This function is used to pass statistics values to tempOUT statistics char
	 * statistics_tempOUT array are pasts 24 hour values and statistics index is current hour to place
	 * value
	 */
	view.STATISTICS_tempOUT(statistics_tempOUT, statistics_index);
}
