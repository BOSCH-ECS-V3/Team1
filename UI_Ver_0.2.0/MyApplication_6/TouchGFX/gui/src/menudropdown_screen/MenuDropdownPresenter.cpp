#include <gui/menudropdown_screen/MenuDropdownView.hpp>
#include <gui/menudropdown_screen/MenuDropdownPresenter.hpp>

MenuDropdownPresenter::MenuDropdownPresenter(MenuDropdownView& v)
    : view(v)
{

}

void MenuDropdownPresenter::activate()
{

}

void MenuDropdownPresenter::deactivate()
{

}

void MenuDropdownPresenter::set_brightness_level(int brightness)
{
	view.set_brightness_level(brightness);
}
