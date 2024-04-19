#include <gui/menudropdown_1_screen/MenuDropdown_1View.hpp>
#include <gui/menudropdown_1_screen/MenuDropdown_1Presenter.hpp>

MenuDropdown_1Presenter::MenuDropdown_1Presenter(MenuDropdown_1View& v)
    : view(v)
{

}

void MenuDropdown_1Presenter::activate()
{

}

void MenuDropdown_1Presenter::deactivate()
{

}

void MenuDropdown_1Presenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}
