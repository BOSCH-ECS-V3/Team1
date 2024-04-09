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
void Statistics_HumidityView::set_brightness_level(int brightness)
{
	Screen_Brightness.setAlpha(brightness);
	Screen_Brightness.invalidate();
}
