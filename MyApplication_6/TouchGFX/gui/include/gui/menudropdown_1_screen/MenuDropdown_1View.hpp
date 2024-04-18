#ifndef MENUDROPDOWN_1VIEW_HPP
#define MENUDROPDOWN_1VIEW_HPP

#include <gui_generated/menudropdown_1_screen/MenuDropdown_1ViewBase.hpp>
#include <gui/menudropdown_1_screen/MenuDropdown_1Presenter.hpp>

class MenuDropdown_1View : public MenuDropdown_1ViewBase
{
public:
    MenuDropdown_1View();
    virtual ~MenuDropdown_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void set_screen_brightness(int brightness);
protected:
};

#endif // MENUDROPDOWN_1VIEW_HPP
