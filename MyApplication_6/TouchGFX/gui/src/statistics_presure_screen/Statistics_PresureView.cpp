#include <gui/statistics_presure_screen/Statistics_PresureView.hpp>

Statistics_PresureView::Statistics_PresureView()
{

}

void Statistics_PresureView::setupScreen()
{
    Statistics_PresureViewBase::setupScreen();
}

void Statistics_PresureView::tearDownScreen()
{
    Statistics_PresureViewBase::tearDownScreen();
}

void Statistics_PresureView::set_screen_brightness(int brightness)
{
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}

void Statistics_PresureView::STATISTICS_pressure(int statistics_pressure[24] , int statistics_index)
{

	current_index = statistics_index;

	for(int i = 0 ; i < current_index ; i++)
	{
		Graphic_Presure_Inside.addDataPoint(i , statistics_pressure[i]);
		Graphic_Presure_Inside.invalidate();
	}

}



