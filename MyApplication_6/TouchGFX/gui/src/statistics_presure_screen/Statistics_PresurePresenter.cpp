#include <gui/statistics_presure_screen/Statistics_PresureView.hpp>
#include <gui/statistics_presure_screen/Statistics_PresurePresenter.hpp>

Statistics_PresurePresenter::Statistics_PresurePresenter(Statistics_PresureView& v)
    : view(v)
{

}

void Statistics_PresurePresenter::activate()
{

}

void Statistics_PresurePresenter::deactivate()
{

}

void Statistics_PresurePresenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}

void Statistics_PresurePresenter::STATISTICS_pressure(int statistics_pressure[24] , int statistics_index)
{
	/*
	 * This function is used to pass statistics values to pressure statistics char
	 * statistics_pressure array are pasts 24 hour values and statistics index is current hour to place
	 * value
	 */
	view.STATISTICS_pressure(statistics_pressure , statistics_index);
}
