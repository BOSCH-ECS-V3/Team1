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
void Statistics_Temperature_InsideView::STATISTICS_tempIN(int statistics_tempIN[24], int tempIN_index)
{
	// Add new data point to view
	current_index = tempIN_index ;

	for(int i = 0 ; i < current_index ; i++)
	{
		tempIN_val[i] = statistics_tempIN[i];
		Graphic_Temperature_Inside.addDataPoint( i , statistics_tempIN[i]);
		Graphic_Temperature_Inside.invalidate();
	}


}
