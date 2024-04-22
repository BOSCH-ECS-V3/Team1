#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorView.hpp>

Statistics_Gas_sensorView::Statistics_Gas_sensorView()
{

}

void Statistics_Gas_sensorView::setupScreen()
{
    Statistics_Gas_sensorViewBase::setupScreen();
}

void Statistics_Gas_sensorView::tearDownScreen()
{
    Statistics_Gas_sensorViewBase::tearDownScreen();
}

void Statistics_Gas_sensorView::set_screen_brightness(int brightness)
{
	  Brightness_level.setAlpha(brightness);
	  Brightness_level.invalidate();
}

void Statistics_Gas_sensorView::STATISTICS_gas(int statistics_gas[24], int statistics_index)
{
	current_index = statistics_index ;
	for(int i = 0 ; i < current_index ; i++)
	{
		gas_val[i] = statistics_gas[i];
		Graphic_Gas_sensor.addDataPoint(i , statistics_gas[i]);
		Graphic_Gas_sensor.invalidate();
	}
}
