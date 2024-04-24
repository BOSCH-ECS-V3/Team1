#ifndef AVERAGE_AMBIENTLIGHTPRESENTER_HPP
#define AVERAGE_AMBIENTLIGHTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Average_AmbientLightView;

class Average_AmbientLightPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Average_AmbientLightPresenter(Average_AmbientLightView& v);

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
    virtual void send_average_Ambient(int avrDayAmbient_res , int avrWeekAmbient_res , int avrMonthAmbient_res);

    virtual ~Average_AmbientLightPresenter() {}

private:
    Average_AmbientLightPresenter();

    Average_AmbientLightView& view;
};

#endif // AVERAGE_AMBIENTLIGHTPRESENTER_HPP
