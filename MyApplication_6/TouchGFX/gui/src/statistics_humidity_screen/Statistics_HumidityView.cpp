#include <gui/statistics_humidity_screen/Statistics_HumidityView.hpp>

Statistics_HumidityView::Statistics_HumidityView()
{

}

void Statistics_HumidityView::setupScreen()
{
    Statistics_HumidityViewBase::setupScreen();
}

void Statistics_HumidityView::tearDownScreen()
{
    Statistics_HumidityViewBase::tearDownScreen();
}

void Statistics_HumidityView::set_screen_brightness(int brightness)
{
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}


