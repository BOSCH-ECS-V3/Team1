#include <gui/average_tempout_screen/Average_TempOUTView.hpp>

Average_TempOUTView::Average_TempOUTView()
{

}

void Average_TempOUTView::setupScreen()
{
    Average_TempOUTViewBase::setupScreen();
}

void Average_TempOUTView::tearDownScreen()
{
    Average_TempOUTViewBase::tearDownScreen();
}

void Average_TempOUTView::send_average_TempOUT(int avrDayTempOUT_res , int avrWeekTempOUT_res , int avrMonthTempOUT_res)
{
	 Unicode::snprintf(Average_day_valBuffer, AVERAGE_DAY_VAL_SIZE, "%d", avrDayTempOUT_res);
	 Unicode::snprintf(Average_week_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrWeekTempOUT_res);
	 Unicode::snprintf(Average_month_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrMonthTempOUT_res);
	 Average_day_val.invalidate();
	 Average_week_val.invalidate();
	 Average_month_val.invalidate();
}
