#include <gui/average_ambientlight_screen/Average_AmbientLightView.hpp>

Average_AmbientLightView::Average_AmbientLightView()
{

}

void Average_AmbientLightView::setupScreen()
{
    Average_AmbientLightViewBase::setupScreen();
}

void Average_AmbientLightView::tearDownScreen()
{
    Average_AmbientLightViewBase::tearDownScreen();
}

void Average_AmbientLightView::send_average_Ambient(int avrDayAmbient_res , int avrWeekAmbient_res , int avrMonthAmbient_res)
{
	 Unicode::snprintf(Average_day_valBuffer, AVERAGE_DAY_VAL_SIZE, "%d", avrDayAmbient_res);
	 Unicode::snprintf(Average_week_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrWeekAmbient_res);
	 Unicode::snprintf(Average_month_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", avrMonthAmbient_res);
	 Average_day_val.invalidate();
	 Average_week_val.invalidate();
	 Average_month_val.invalidate();
}
