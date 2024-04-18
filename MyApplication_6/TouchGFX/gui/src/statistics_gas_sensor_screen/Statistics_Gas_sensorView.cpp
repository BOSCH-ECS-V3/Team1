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
