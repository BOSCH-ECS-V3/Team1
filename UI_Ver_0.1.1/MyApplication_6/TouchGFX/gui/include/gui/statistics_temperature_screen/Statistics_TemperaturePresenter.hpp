#ifndef STATISTICS_TEMPERATUREPRESENTER_HPP
#define STATISTICS_TEMPERATUREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_TemperatureView;

class Statistics_TemperaturePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_TemperaturePresenter(Statistics_TemperatureView& v);

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

    virtual ~Statistics_TemperaturePresenter() {}

private:
    Statistics_TemperaturePresenter();

    Statistics_TemperatureView& view;
};

#endif // STATISTICS_TEMPERATUREPRESENTER_HPP
