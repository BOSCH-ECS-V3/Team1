#include <gui/average_tempin_screen/Average_TempINView.hpp>
#include <gui/average_tempin_screen/Average_TempINPresenter.hpp>

Average_TempINPresenter::Average_TempINPresenter(Average_TempINView& v)
    : view(v)
{

}

void Average_TempINPresenter::activate()
{

}

void Average_TempINPresenter::deactivate()
{

}

void Average_TempINPresenter::send_average_TempIN(int average_day , int average_week ,  int average_month)
{
	/*
	 * This function is used for sending average day/week/month values to the VIEW page.
	 */
	view.send_average_TempIN(average_day , average_week ,  average_month);
}
