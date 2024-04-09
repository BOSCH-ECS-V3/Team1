#ifndef STATISTICS_GAS_SENSORPRESENTER_HPP
#define STATISTICS_GAS_SENSORPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_Gas_sensorView;

class Statistics_Gas_sensorPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_Gas_sensorPresenter(Statistics_Gas_sensorView& v);

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

    virtual ~Statistics_Gas_sensorPresenter() {}

private:
    Statistics_Gas_sensorPresenter();

    Statistics_Gas_sensorView& view;
};

#endif // STATISTICS_GAS_SENSORPRESENTER_HPP
