#ifndef STATISTICS_TEMPERATURE_OUTSIDEPRESENTER_HPP
#define STATISTICS_TEMPERATURE_OUTSIDEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_Temperature_OutsideView;

class Statistics_Temperature_OutsidePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_Temperature_OutsidePresenter(Statistics_Temperature_OutsideView& v);

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
    virtual void STATISTICS_tempOUT(int statistics_tempOUT[24], int statistics_index);

    virtual ~Statistics_Temperature_OutsidePresenter() {}

private:
    Statistics_Temperature_OutsidePresenter();

    Statistics_Temperature_OutsideView& view;
};

#endif // STATISTICS_TEMPERATURE_OUTSIDEPRESENTER_HPP
