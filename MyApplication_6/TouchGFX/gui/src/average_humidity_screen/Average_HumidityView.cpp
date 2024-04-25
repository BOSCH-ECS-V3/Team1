#include <gui/average_humidity_screen/Average_HumidityView.hpp>

Average_HumidityView::Average_HumidityView()
{

}

void Average_HumidityView::setupScreen()
{
    Average_HumidityViewBase::setupScreen();
}

void Average_HumidityView::tearDownScreen()
{
    Average_HumidityViewBase::tearDownScreen();
}

void Average_HumidityView::send_average_Humidity(int avrDayHumidity_res , int avrWeekHumidity_res , int avrMonthHumidity_res)
{
	/*
	 * Update average values to the screen
	 */
		 Unicode::snprintf(Average_day_valBuffer, AVERAGE_DAY_VAL_SIZE, "%d", avrDayHumidity_res);
		 Unicode::snprintf(Average_week_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrWeekHumidity_res);
		 Unicode::snprintf(Average_month_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrMonthHumidity_res);
		 Average_day_val.invalidate();
		 Average_week_val.invalidate();
		 Average_month_val.invalidate();
}
