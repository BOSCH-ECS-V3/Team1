#ifndef STATISTICS_TEMPERATURE_INSIDEPRESENTER_HPP
#define STATISTICS_TEMPERATURE_INSIDEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_Temperature_InsideView;

class Statistics_Temperature_InsidePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_Temperature_InsidePresenter(Statistics_Temperature_InsideView& v);

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
    virtual void STATISTICS_tempIN(int statistics_tempIN[24], int tempIN_index , int average_day);

    virtual ~Statistics_Temperature_InsidePresenter() {}

private:
    Statistics_Temperature_InsidePresenter();

    Statistics_Temperature_InsideView& view;
};

#endif // STATISTICS_TEMPERATURE_INSIDEPRESENTER_HPP
