#include <gui/menudropdown_1_screen/MenuDropdown_1View.hpp>

MenuDropdown_1View::MenuDropdown_1View()
{

}

void MenuDropdown_1View::setupScreen()
{
    MenuDropdown_1ViewBase::setupScreen();
}

void MenuDropdown_1View::tearDownScreen()
{
    MenuDropdown_1ViewBase::tearDownScreen();
}
void MenuDropdown_1View::set_screen_brightness(int brightness)
{
	/*
	 * Set brightness of the screen
	 */
	  Brightness_level.setAlpha(brightness);
	  Brightness_level.invalidate();
}
