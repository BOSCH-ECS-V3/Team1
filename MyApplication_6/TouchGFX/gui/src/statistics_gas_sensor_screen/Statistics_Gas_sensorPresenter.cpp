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

void Statistics_Gas_sensorPresenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}

void Statistics_Gas_sensorPresenter::STATISTICS_gas(int statistics_gas[24], int statistics_index)
{
	view.STATISTICS_gas(statistics_gas, statistics_index);
}
