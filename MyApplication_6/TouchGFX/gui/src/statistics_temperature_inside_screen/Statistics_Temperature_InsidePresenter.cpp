#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsideView.hpp>
#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsidePresenter.hpp>

Statistics_Temperature_InsidePresenter::Statistics_Temperature_InsidePresenter(Statistics_Temperature_InsideView& v)
    : view(v)
{

}

void Statistics_Temperature_InsidePresenter::activate()
{

}

void Statistics_Temperature_InsidePresenter::deactivate()
{

}
void Statistics_Temperature_InsidePresenter::SEND_STATISTICS_INFORMATION_TEMPERATURE_INSIDE(int STATISTICS_Temperature_INSIDE[], int STATISTICS_Array_Index)
{
	view.SEND_STATISTICS_INFORMATION_TEMPERATURE_INSIDE(STATISTICS_Temperature_INSIDE, STATISTICS_Array_Index);
}
