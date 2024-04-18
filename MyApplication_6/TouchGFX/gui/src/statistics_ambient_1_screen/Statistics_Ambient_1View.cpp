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
void Statistics_Ambient_1View::set_screen_brightness(int brightness)
{
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}



