#include <gui/about_screen/AboutView.hpp>

AboutView::AboutView()
{

}

void AboutView::setupScreen()
{
    AboutViewBase::setupScreen();
}

void AboutView::tearDownScreen()
{
    AboutViewBase::tearDownScreen();
}

void AboutView::set_screen_brightness(int brightness)
{
	/*
	 * Set brightness level
	 */
	 Brightness_level.setAlpha(brightness);
	 Brightness_level.invalidate();
}
