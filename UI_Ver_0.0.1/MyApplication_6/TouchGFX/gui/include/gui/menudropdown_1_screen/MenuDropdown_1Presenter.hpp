#ifndef MENUDROPDOWN_1PRESENTER_HPP
#define MENUDROPDOWN_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MenuDropdown_1View;

class MenuDropdown_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    MenuDropdown_1Presenter(MenuDropdown_1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MenuDropdown_1Presenter() {}

private:
    MenuDropdown_1Presenter();

    MenuDropdown_1View& view;
};

#endif // MENUDROPDOWN_1PRESENTER_HPP
