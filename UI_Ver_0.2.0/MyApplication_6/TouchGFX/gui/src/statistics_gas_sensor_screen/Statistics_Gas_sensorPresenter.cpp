#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorView.hpp>
#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorPresenter.hpp>

Statistics_Gas_sensorPresenter::Statistics_Gas_sensorPresenter(Statistics_Gas_sensorView& v)
    : view(v)
{

}

void Statistics_Gas_sensorPresenter::activate()
{

}

void Statistics_Gas_sensorPresenter::deactivate()
{

}
void Statistics_Gas_sensorPresenter::set_brightness_level(int brightness)
{
	// passing value to view

	view.set_brightness_level(brightness);
}
