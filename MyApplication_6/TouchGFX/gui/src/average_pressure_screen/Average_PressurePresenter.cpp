#include <gui/average_pressure_screen/Average_PressureView.hpp>
#include <gui/average_pressure_screen/Average_PressurePresenter.hpp>

Average_PressurePresenter::Average_PressurePresenter(Average_PressureView& v)
    : view(v)
{

}

void Average_PressurePresenter::activate()
{

}

void Average_PressurePresenter::deactivate()
{

}

void Average_PressurePresenter::send_average_Pressure(int avrDayPressure_res , int avrWeekPressure_res , int avrMonthPressure_res)
{
	/*
	 * This function is used for sending average day/week/month values to the VIEW page.
	 */
	view.send_average_Pressure(avrDayPressure_res , avrWeekPressure_res , avrMonthPressure_res);
}
