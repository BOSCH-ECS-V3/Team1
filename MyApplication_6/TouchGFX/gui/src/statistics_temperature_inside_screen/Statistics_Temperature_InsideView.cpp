#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsideView.hpp>

Statistics_Temperature_InsideView::Statistics_Temperature_InsideView()
{

}

void Statistics_Temperature_InsideView::setupScreen()
{
    Statistics_Temperature_InsideViewBase::setupScreen();
}

void Statistics_Temperature_InsideView::tearDownScreen()
{
    Statistics_Temperature_InsideViewBase::tearDownScreen();
}
void Statistics_Temperature_InsideView::set_screen_brightness(int brightness)
{
	  Brightness_level.setAlpha(brightness);
		  Brightness_level.invalidate();
}
