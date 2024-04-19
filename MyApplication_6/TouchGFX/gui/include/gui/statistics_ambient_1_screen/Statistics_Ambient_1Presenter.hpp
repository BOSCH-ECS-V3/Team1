#ifndef STATISTICS_AMBIENT_1PRESENTER_HPP
#define STATISTICS_AMBIENT_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_Ambient_1View;

class Statistics_Ambient_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_Ambient_1Presenter(Statistics_Ambient_1View& v);

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
    virtual void set_screen_brightness(int brightness);

    virtual ~Statistics_Ambient_1Presenter() {}

private:
    Statistics_Ambient_1Presenter();

    Statistics_Ambient_1View& view;
};

#endif // STATISTICS_AMBIENT_1PRESENTER_HPP
