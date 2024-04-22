#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsideView.hpp>

Statistics_Temperature_OutsideView::Statistics_Temperature_OutsideView()
{

}

void Statistics_Temperature_OutsideView::setupScreen()
{
    Statistics_Temperature_OutsideViewBase::setupScreen();
}

void Statistics_Temperature_OutsideView::tearDownScreen()
{
    Statistics_Temperature_OutsideViewBase::tearDownScreen();
}

void Statistics_Temperature_OutsideView::set_screen_brightness(int brightness)
{
	  Brightness_level.setAlpha(brightness);
	  Brightness_level.invalidate();
}

void Statistics_Temperature_OutsideView::STATISTICS_tempOUT(int statistics_tempOUT[24], int statistics_index)
{
	current_index = statistics_index ;

	for(int i = 0 ; i < current_index ; i++)
	{
		tempOUT_val[i] = statistics_tempOUT[i];
		Graphic_Temperature_Outside.addDataPoint(i , statistics_tempOUT[i]);
		Graphic_Temperature_Outside.invalidate();

	}

}
