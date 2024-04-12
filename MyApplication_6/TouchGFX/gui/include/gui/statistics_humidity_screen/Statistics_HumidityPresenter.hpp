#ifndef STATISTICS_HUMIDITYPRESENTER_HPP
#define STATISTICS_HUMIDITYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_HumidityView;

class Statistics_HumidityPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_HumidityPresenter(Statistics_HumidityView& v);

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

    virtual ~Statistics_HumidityPresenter() {}

private:
    Statistics_HumidityPresenter();

    Statistics_HumidityView& view;
};

#endif // STATISTICS_HUMIDITYPRESENTER_HPP
