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
	/*
	 * Set brightness of the screen
	 */
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}
void Statistics_Ambient_1View::STATISTICS_ambient(int statistics_ambient[24] , int statistics_index)
{

	/*
	 * Update statistics char
	 */
	current_index = statistics_index;

	for(int i = 0 ; i < current_index ; i++)
	{
		Graphic_Ambient_Inside.addDataPoint(i , statistics_ambient[i]);
		Graphic_Ambient_Inside.invalidate();
	}
}


