#ifndef AVERAGE_TEMPOUTPRESENTER_HPP
#define AVERAGE_TEMPOUTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Average_TempOUTView;

class Average_TempOUTPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Average_TempOUTPresenter(Average_TempOUTView& v);

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
    virtual void send_average_TempOUT(int avrDayTempOUT_res , int avrWeekTempOUT_res , int avrMonthTempOUT_res);

    virtual ~Average_TempOUTPresenter() {}

private:
    Average_TempOUTPresenter();

    Average_TempOUTView& view;
};

#endif // AVERAGE_TEMPOUTPRESENTER_HPP
