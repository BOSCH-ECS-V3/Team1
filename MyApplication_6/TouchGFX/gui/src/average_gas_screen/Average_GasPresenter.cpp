#include <gui/average_gas_screen/Average_GasView.hpp>
#include <gui/average_gas_screen/Average_GasPresenter.hpp>

Average_GasPresenter::Average_GasPresenter(Average_GasView& v)
    : view(v)
{

}

void Average_GasPresenter::activate()
{

}

void Average_GasPresenter::deactivate()
{

}
void Average_GasPresenter::send_average_Gas(int avrDayGas_res ,int avrWeekGas_res ,int avrMonthGas_res)
{
	/*
	 * This function is used for sending average day/week/month values to the VIEW page.
	 */
	view.send_average_Gas( avrDayGas_res , avrWeekGas_res , avrMonthGas_res);
}
