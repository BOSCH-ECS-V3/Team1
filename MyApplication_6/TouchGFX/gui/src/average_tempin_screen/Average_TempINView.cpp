#include <gui/average_tempin_screen/Average_TempINView.hpp>

Average_TempINView::Average_TempINView()
{

}

void Average_TempINView::setupScreen()
{
    Average_TempINViewBase::setupScreen();
}

void Average_TempINView::tearDownScreen()
{
    Average_TempINViewBase::tearDownScreen();
}

void Average_TempINView::send_average_TempIN(int average_day , int average_week ,  int average_month)
{
	 Unicode::snprintf(Average_day_valBuffer, AVERAGE_DAY_VAL_SIZE, "%d", average_day);
	 Unicode::snprintf(Average_week_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", average_week);
	 Unicode::snprintf(Average_month_valBuffer, AVERAGE_WEEK_VAL_SIZE, "%d", average_month);
	 Average_day_val.invalidate();
	 Average_week_val.invalidate();
	 Average_month_val.invalidate();
}
