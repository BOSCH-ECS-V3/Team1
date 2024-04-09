#ifndef MENUDROPDOWNPRESENTER_HPP
#define MENUDROPDOWNPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MenuDropdownView;

class MenuDropdownPresenter : public touchgfx::Presenter, public ModelListener
{
public:
	MenuDropdownPresenter(MenuDropdownView& v);

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

	virtual void set_brightness_level(int brightness);


	virtual ~MenuDropdownPresenter() {}

private:
	MenuDropdownPresenter();

	MenuDropdownView& view;
};

#endif // MENUDROPDOWNPRESENTER_HPP
