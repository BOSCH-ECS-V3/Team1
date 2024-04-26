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
	/*
	 * Set brightness level of the screen
	 */
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}

void Statistics_HumidityView::STATISTICS_humidity(int statistics_humidity[24], int statistics_index)
{
	/*
	 * Update humidity char
	 */
	current_index = statistics_index ;

	for(int i = 0 ; i < current_index ; i++)
	{
		humidity_val[i] = statistics_humidity[i];
		Graphic_Humidity_Inside.addDataPoint(i , statistics_humidity[i]);
		Graphic_Humidity_Inside.invalidate();
	}
}

