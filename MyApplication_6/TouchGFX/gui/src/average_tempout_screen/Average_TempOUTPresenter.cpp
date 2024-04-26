#include <gui/average_tempout_screen/Average_TempOUTView.hpp>
#include <gui/average_tempout_screen/Average_TempOUTPresenter.hpp>

Average_TempOUTPresenter::Average_TempOUTPresenter(Average_TempOUTView& v)
    : view(v)
{

}

void Average_TempOUTPresenter::activate()
{

}

void Average_TempOUTPresenter::deactivate()
{

}

void Average_TempOUTPresenter::send_average_TempOUT(int avrDayTempOUT_res , int avrWeekTempOUT_res , int avrMonthTempOUT_res)
{
	/*
	 * This function is used for sending average day/week/month values to the VIEW page.
	 */
	view.send_average_TempOUT(avrDayTempOUT_res , avrWeekTempOUT_res , avrMonthTempOUT_res);
}
