#ifndef DEFAULTVIEWPRESENTER_HPP
#define DEFAULTVIEWPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DefaultViewView;

class DefaultViewPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DefaultViewPresenter(DefaultViewView& v);

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

    virtual ~DefaultViewPresenter() {}

    virtual void update_Clock(int Clock_Values[]);

    virtual void current_Sensor_values(int current_Sensor_values[]);

private:
    DefaultViewPresenter();

    DefaultViewView& view;
};

#endif // DEFAULTVIEWPRESENTER_HPP
