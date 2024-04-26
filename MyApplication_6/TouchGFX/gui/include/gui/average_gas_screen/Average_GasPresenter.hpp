#ifndef AVERAGE_GASPRESENTER_HPP
#define AVERAGE_GASPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Average_GasView;

class Average_GasPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Average_GasPresenter(Average_GasView& v);

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
    virtual void send_average_Gas(int avrDayGas_res ,int avrWeekGas_res ,int avrMonthGas_res);

    virtual ~Average_GasPresenter() {}

private:
    Average_GasPresenter();

    Average_GasView& view;
};

#endif // AVERAGE_GASPRESENTER_HPP
