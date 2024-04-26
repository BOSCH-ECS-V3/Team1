#ifndef AVERAGE_TEMPOUTVIEW_HPP
#define AVERAGE_TEMPOUTVIEW_HPP

#include <gui_generated/average_tempout_screen/Average_TempOUTViewBase.hpp>
#include <gui/average_tempout_screen/Average_TempOUTPresenter.hpp>

class Average_TempOUTView : public Average_TempOUTViewBase
{
public:
    Average_TempOUTView();
    virtual ~Average_TempOUTView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void send_average_TempOUT(int avrDayTempOUT_res , int avrWeekTempOUT_res , int avrMonthTempOUT_res);
protected:
};

#endif // AVERAGE_TEMPOUTVIEW_HPP
