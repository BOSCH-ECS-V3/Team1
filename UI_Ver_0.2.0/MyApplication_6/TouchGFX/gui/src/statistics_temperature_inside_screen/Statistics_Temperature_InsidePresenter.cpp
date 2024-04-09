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

void Statistics_Temperature_InsidePresenter::set_brightness_level(int brightness)
{
	view.set_brightness_level(brightness);
}
