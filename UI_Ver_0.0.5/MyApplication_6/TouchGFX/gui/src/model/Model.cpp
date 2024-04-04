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

				}
			}
		}
	}

	modelListener->current_Clock(Clock_Values);
	//modelListener->update_sensor_values(SensorValues);
}

void Model::update_Clock(int updated_Clock_Values[3])
{
	Clock_Values[0] = updated_Clock_Values[0];
	Clock_Values[1] = updated_Clock_Values[1];
	Clock_Values[2] = updated_Clock_Values[2];
}
