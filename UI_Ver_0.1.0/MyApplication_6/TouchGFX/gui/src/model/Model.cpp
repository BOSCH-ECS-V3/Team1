#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



Model::Model() : modelListener(0)
{

}

void Model::tick()
{


	// Test sending info to View

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

	if(current_Date_values[1] >= 13)
	{
		current_Date_values[1] = 1 ;
		current_Date_values[2]++;
	}

	modelListener->current_Clock(Clock_Values);

	modelListener->current_Date_value(current_Date_values);
	//modelListener->update_sensor_values(SensorValues);
}

void Model::update_Clock(int updated_Clock_Values[3])
{
	Clock_Values[0] = updated_Clock_Values[0];
	Clock_Values[1] = updated_Clock_Values[1];
	Clock_Values[2] = updated_Clock_Values[2];
}
void Model::update_Date(int updated_Date_Values[3])
{
	current_Date_values[0] = updated_Date_Values[0];
	current_Date_values[1] = updated_Date_Values[1];
	current_Date_values[2] = updated_Date_Values[2];
}
