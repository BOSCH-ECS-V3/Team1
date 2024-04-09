#include <gui/menudropdown_screen/MenuDropdownView.hpp>

MenuDropdownView::MenuDropdownView()
{

}

void MenuDropdownView::setupScreen()
{
    MenuDropdownViewBase::setupScreen();
}

void MenuDropdownView::tearDownScreen()
{
    MenuDropdownViewBase::tearDownScreen();
}
void MenuDropdownView::set_brightness_level(int brightness)
{
	 Screen_Brightness.setAlpha(brightness);
	 Screen_Brightness.invalidate();
}
