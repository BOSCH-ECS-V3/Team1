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
