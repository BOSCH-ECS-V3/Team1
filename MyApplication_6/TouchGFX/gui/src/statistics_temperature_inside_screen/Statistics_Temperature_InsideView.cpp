#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsideView.hpp>

Statistics_Temperature_InsideView::Statistics_Temperature_InsideView()
{

}

void Statistics_Temperature_InsideView::setupScreen()
{
    Statistics_Temperature_InsideViewBase::setupScreen();
}

void Statistics_Temperature_InsideView::tearDownScreen()
{
    Statistics_Temperature_InsideViewBase::tearDownScreen();
}
void Statistics_Temperature_InsideView::SEND_STATISTICS_INFORMATION_TEMPERATURE_INSIDE(int STATISTICS_Temperature_INSIDE[], int STATISTICS_Array_Index)
{
  // Receive Statistics information from model and push it to char via addPoint();

	for(int i = 0 ; i <= 24 ; i++)
	{
		temperatureIN_values[i] = STATISTICS_Temperature_INSIDE[i];

	}

   array_index = STATISTICS_Array_Index ;

}
void Statistics_Temperature_InsideView::UpdateData()
{
		for(int i = 0 ; i < 24 ; i++)
		{

			   Graphic_Temperature_Inside.addDataPoint(i, temperatureIN_values[i]);
			   Graphic_Temperature_Inside.invalidate();
		}


}
