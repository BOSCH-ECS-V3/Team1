#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1View.hpp>

Statistics_Ambient_1View::Statistics_Ambient_1View()
{

}

void Statistics_Ambient_1View::setupScreen()
{
    Statistics_Ambient_1ViewBase::setupScreen();
}

void Statistics_Ambient_1View::tearDownScreen()
{
    Statistics_Ambient_1ViewBase::tearDownScreen();
}

void Statistics_Ambient_1View::set_brightness_level(int brightness)
{
	// Sending screen brightness to view
	Screen_Brightness.setAlpha(brightness);
	Screen_Brightness.invalidate();
}
