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

void AboutView::set_brightness_level(int brightness)
{
	Screen_Brightness.setAlpha(brightness);
	Screen_Brightness.invalidate();
}
