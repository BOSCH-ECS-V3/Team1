#ifndef MENUDROPDOWNVIEW_HPP
#define MENUDROPDOWNVIEW_HPP

#include <gui_generated/menudropdown_screen/MenuDropdownViewBase.hpp>
#include <gui/menudropdown_screen/MenuDropdownPresenter.hpp>

class MenuDropdownView : public MenuDropdownViewBase
{
public:
    MenuDropdownView();
    virtual ~MenuDropdownView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MENUDROPDOWNVIEW_HPP
