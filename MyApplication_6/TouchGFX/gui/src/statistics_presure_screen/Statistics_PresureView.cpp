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



