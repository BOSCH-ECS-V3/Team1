#ifndef AVERAGE_PRESSUREPRESENTER_HPP
#define AVERAGE_PRESSUREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Average_PressureView;

class Average_PressurePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Average_PressurePresenter(Average_PressureView& v);

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
    virtual void send_average_Pressure(int avrDayPressure_res , int avrWeekPressure_res , int avrMonthPressure_res);


    virtual ~Average_PressurePresenter() {}

private:
    Average_PressurePresenter();

    Average_PressureView& view;
};

#endif // AVERAGE_PRESSUREPRESENTER_HPP
