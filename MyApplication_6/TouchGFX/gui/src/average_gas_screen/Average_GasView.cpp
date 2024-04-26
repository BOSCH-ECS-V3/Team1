#include <gui/average_gas_screen/Average_GasView.hpp>

Average_GasView::Average_GasView()
{

}

void Average_GasView::setupScreen()
{
    Average_GasViewBase::setupScreen();
}

void Average_GasView::tearDownScreen()
{
    Average_GasViewBase::tearDownScreen();
}

void Average_GasView::send_average_Gas(int avrDayGas_res ,int avrWeekGas_res ,int avrMonthGas_res)
{
	/*
	 * Update average values to the screen
	 */
	 Unicode::snprintf(Average_day_valBuffer, AVERAGE_DAY_VAL_SIZE, "%d", avrDayGas_res);
	 Unicode::snprintf(Average_week_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrWeekGas_res);
	 Unicode::snprintf(Average_month_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrMonthGas_res);
	 Average_day_val.invalidate();
	 Average_week_val.invalidate();
	 Average_month_val.invalidate();
}

