#include <gui/average_pressure_screen/Average_PressureView.hpp>

Average_PressureView::Average_PressureView()
{

}

void Average_PressureView::setupScreen()
{
    Average_PressureViewBase::setupScreen();
}

void Average_PressureView::tearDownScreen()
{
    Average_PressureViewBase::tearDownScreen();
}

void Average_PressureView::send_average_Pressure(int avrDayPressure_res , int avrWeekPressure_res , int avrMonthPressure_res)
{
	 Unicode::snprintf(Average_day_valBuffer, AVERAGE_DAY_VAL_SIZE, "%d", avrDayPressure_res);
	 Unicode::snprintf(Average_week_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrWeekPressure_res);
	 Unicode::snprintf(Average_month_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrMonthPressure_res);
	 Average_day_val.invalidate();
	 Average_week_val.invalidate();
	 Average_month_val.invalidate();
}
