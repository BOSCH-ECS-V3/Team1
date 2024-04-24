#ifndef AVERAGE_HUMIDITYPRESENTER_HPP
#define AVERAGE_HUMIDITYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Average_HumidityView;

class Average_HumidityPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Average_HumidityPresenter(Average_HumidityView& v);

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
    virtual void send_average_Humidity(int avrDayHumidity_res , int avrWeekHumidity_res , int avrMonthHumidity_res);

    virtual ~Average_HumidityPresenter() {}

private:
    Average_HumidityPresenter();

    Average_HumidityView& view;
};

#endif // AVERAGE_HUMIDITYPRESENTER_HPP
