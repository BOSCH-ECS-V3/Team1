#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



Model::Model() : modelListener(0)
{

}

void Model::tick()
{

	// ----------------------------- Clock Update to View ---> ----------------------------
	tickCounter++;
	if(tickCounter%60 ==0)
	{
		if(++Clock_Values[2]>=60)
		{
			Clock_Values[2] = 0;
			if(++Clock_Values[1]>=60)
			{
				Clock_Values[1] = 0;
				if(++Clock_Values[0]>=24)
				{
					Clock_Values[0] = 0;
					if(current_Date_values[1] ==  1 || current_Date_values[1] ==  3 ||
							current_Date_values[1] ==  5 || current_Date_values[1] ==  7 ||
							current_Date_values[1] ==  8 || current_Date_values[1] ==  10 ||
							current_Date_values[1] ==  12)
					{
						if(++current_Date_values[0]>=31)
						{
							current_Date_values[0] = 1 ;
							current_Date_values[1]++;
						}
					}
					if(current_Date_values[1] ==  4 || current_Date_values[1] == 6 ||
							current_Date_values[1] ==  9 || current_Date_values[1] ==  11)
					{
						if(++current_Date_values[0]>=30)
						{
							current_Date_values[0] = 1 ;
							current_Date_values[1]++;
						}
					}
					if(current_Date_values[1] ==  2)
					{
						if(++current_Date_values[0]>=28)
						{
							current_Date_values[0] = 1 ;
							current_Date_values[1]++;
						}
					}

				}
			}
		}
	}
	// Returning months to 1 , after 12
	if(current_Date_values[1] >= 13)
	{
		current_Date_values[1] = 1 ;
		current_Date_values[2]++;
	}
	// ----------------------------- Clock Update to View  END ---> ----------------------------

	// Passing values to clock View
	modelListener->current_Clock(Clock_Values);

	//Passing values to date View
	modelListener->current_Date_value(current_Date_values);

	//..Passing sensor values to Default page for presenting on screen
	// [0]->TemperatureIn , [1]-> TemperatureOut , [2]-> Humidity , [3]-> Pressure ,[4]->Ambient light
	// [5]->Gas sensor

	current_Sensor_values[0] = 27 ;
	current_Sensor_values[1] = 22 ;
	current_Sensor_values[2] = 45 ;
	current_Sensor_values[3] = 20 ;
	current_Sensor_values[4] = 78 ;
	current_Sensor_values[5] = 80 ;

	modelListener->current_Sensor_values(current_Sensor_values);

	// -------------------------------- Passing backround intensity to view pages

	/*
	 *
	 * Import algorithm for calculating brightness based on ASL value
	 *
	 *
	 */

	modelListener->set_brightness_level(brightness);
}

void Model::update_Clock(int updated_Clock_Values[3])
{
	// Receive data from Clock View
	// Element[0] - hours , element[1] - minutes , element[2] - seconds
	Clock_Values[0] = updated_Clock_Values[0];
	Clock_Values[1] = updated_Clock_Values[1];
	Clock_Values[2] = updated_Clock_Values[2];
}
void Model::update_Date(int updated_Date_Values[3])
{
	// Receive data from Data View
	// element[0] - Days , element[1] - months , element[2] - year
	current_Date_values[0] = updated_Date_Values[0];
	current_Date_values[1] = updated_Date_Values[1];
	current_Date_values[2] = updated_Date_Values[2];
}
