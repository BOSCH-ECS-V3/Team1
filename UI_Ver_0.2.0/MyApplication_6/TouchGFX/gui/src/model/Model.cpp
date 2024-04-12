#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <data_UI_def.h>

extern "C"{
extern SensData_t data_UI;
}
int Error_feedback(int current_Sensor_values[5])
{
	int Error_ID = 999 ;

	//..Passing sensor values to Default page for presenting on screen
	// [0]->TemperatureIn , [1]-> TemperatureOut , [2]-> Humidity , [3]-> Pressure ,[4]->Ambient light
	// [5]->Gas sensor

	int tempIN_val = current_Sensor_values[0]  ;
	int tempOUT_val = current_Sensor_values[1] ;
	int humidity_val = current_Sensor_values[2]  ;
	int pressure_val = current_Sensor_values[3] ;
	int ambientLight_val = current_Sensor_values[4] ;
	int carbonMonoxide_val = current_Sensor_values[5] ;

	// Define error values for TempIN sensor
	int tempIN_MAX_VALUE = 300;
	int tempIN_MIN_VALUE = -10;
	int tempIN_DISCONNECTED_VALUE = 201 ;
	// Define error values for TempOUT sensor
	int tempOUT_MAX_VALUE = 300;
	int tempOUT_MIN_VALUE = -10;
	int tempOUT_DISCONNECTED_VALUE = 201 ;
	// Define error values for Humidity sensor
	int humidity_MAX_VALUE = 65;
	int humidity_MIN_VALUE = 25;
	int humidity_DISCONNECTED_VALUE = 201;
	// Define error values for Pressure sensor
	int pressure_MAX_VALUE = 1000 ;
	int pressure_MIN_VALUE = 100;
	int pressure_DISCONNECTED_VALUE = 2000;
	// Define error values for Ambient light sensor
	int ambientLight_MAX_VALUE = 100 ;
	int ambientLight_MIN_VALUE = 0;
	int ambientLight_DISCONNECTED_VALUE = 201 ;
	// Define error values for carbonMonoxide sensor
	int carbonMonoxide_MAX_VALUE = 30000;
	int carbonMonoxide_MIN_VALUE = 1;
	int carbonMonoxide_DISCONNECTED_VALUE = 0 ;

	/*  Error List Code

 	ID with 9xx - > General Errors

 	General Error -

 	ID with 1xx - > tempIN sensor

	TemperatureInside Sensor Disconnected ------------> 101
	TemperatureInside Sensor Below tempIN_MIN_VALUE degrees ---> 102
	TemperatureInside Sensor More than tempIN_MAX_VALUE degrees ---> 103

	ID with 2xx - > tempOUT sensor

	TemperatureOutside Sensor Disconnected ------------> 201
	TemperatureOutside Sensor Below 0 degrees ---> 202
	TemperatureOutside Sensor More than 40 degrees ---> 203

	ID with 3xx - > Humidity sensor

	Humidity Sensor Disconnected ------------> 301
	Humidity Sensor Below 30  ---> 302
	Humidity Sensor More than 65 degrees ---> 303

	ID with 4xx - > Pressure sensor

	Pressure Sensor Disconnected ------------> 401
	Pressure Sensor Below 100  ---> 402
	Pressure Sensor More than 900 ---> 403

	ID with 5xx - > Ambient Light sensor

	Ambient Light Sensor Disconnected ------------> 501
	Ambient Light Sensor Below 100     ---> 502
	Ambient Light Sensor More than 900 ---> 503

	ID with 6xx - > Gas sensor

	Gas Sensor Disconnected   ------------> 601
	Gas Light Sensor Below 100ppm      ---> 602
	Gas Light Sensor More than 2000ppm ---> 603

	 */


	// Errors Temperature Inside

	if(tempIN_val == tempIN_DISCONNECTED_VALUE)
	{
		Error_ID = 101 ;
	}
	if(tempIN_val < tempIN_MIN_VALUE )
	{
		Error_ID = 102 ;
	}
	if(tempIN_val > tempIN_MAX_VALUE )
	{
		Error_ID = 103 ;
	}

	// Errors Temperature Outside

	if(tempOUT_val == tempOUT_DISCONNECTED_VALUE)
	{
		Error_ID = 201 ;
	}
	if(tempOUT_val < tempOUT_MIN_VALUE)
	{
		Error_ID = 202 ;
	}
	if(tempOUT_val > tempOUT_MAX_VALUE)
	{
		Error_ID = 203 ;
	}

	// Errors Humidity Sensor

	if(humidity_val == humidity_DISCONNECTED_VALUE)
	{
		Error_ID = 301 ;
	}
	if(humidity_val < humidity_MIN_VALUE)
	{
		Error_ID = 302 ;
	}
	if(humidity_val > humidity_MAX_VALUE)
	{
		Error_ID = 303 ;
	}

	// Errors Pressure sensor

	if(pressure_val == pressure_DISCONNECTED_VALUE)
	{
		Error_ID = 401 ;
	}
	if(pressure_val < pressure_MIN_VALUE)
	{
		Error_ID = 402 ;
	}
	if(pressure_val > pressure_MAX_VALUE)
	{
		Error_ID = 403 ;
	}

	// Errors Ambient light sensor

	if(ambientLight_val == ambientLight_DISCONNECTED_VALUE)
	{
		Error_ID = 501 ;
	}
	if(ambientLight_val < ambientLight_MIN_VALUE)
	{
		Error_ID = 502 ;
	}
	if(ambientLight_val > ambientLight_MAX_VALUE)
	{
		Error_ID = 503 ;
	}

	// Errors Gas sensor

	if(carbonMonoxide_val == carbonMonoxide_DISCONNECTED_VALUE)
	{
		Error_ID = 601 ;
	}
	if(carbonMonoxide_val < carbonMonoxide_MIN_VALUE)
	{
		Error_ID = 602 ;
	}
	if(carbonMonoxide_val > carbonMonoxide_MAX_VALUE)
	{
		Error_ID = 603 ;
	}


	return Error_ID ;
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

	// ----------------------------- Clock Update to View ---> ----------------------------
	tickCounter++;
	if(tickCounter%60 == 0)
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

	current_Sensor_values[0] = data_UI.tempIN ;
	current_Sensor_values[1] = data_UI.tempOUT ;
	current_Sensor_values[2] = data_UI.humidity ;
	current_Sensor_values[3] = data_UI.pressure ;
	current_Sensor_values[4] = data_UI.ambientLight ;
	current_Sensor_values[5] = data_UI.carbonMonoxide ;

	modelListener->current_Sensor_values(current_Sensor_values);

	// sending information about permission_alert_state to view page of alert
	modelListener->RECEIVE_Permission(Permission_ALERT_STATE);

	// Checking for Errors

	Error_ID = Error_feedback(current_Sensor_values);


	if(Permission_ALERT_STATE == 1)
	{
		modelListener->SEND_Error_ID(Error_ID);
	}

	// if Snooze option is not pressed and alerts are on
	// modelListener->display_error(Error_msg);

	// If Snooze option is pressed , set Alert_PERMISION = FALSE
	// wait 2 min and then reset Alert_PERMISION = TRUE ;

}

void Model::update_Clock(int updated_Clock_Values[3])
{
	// Receive data from Clock View
	Clock_Values[0] = updated_Clock_Values[0]; // Hours
	Clock_Values[1] = updated_Clock_Values[1]; // Minutes
	Clock_Values[2] = updated_Clock_Values[2]; // Seconds
}
void Model::update_Date(int updated_Date_Values[3])
{
	// Receive data from Data View
	current_Date_values[0] = updated_Date_Values[0]; // Days
	current_Date_values[1] = updated_Date_Values[1]; // Month
	current_Date_values[2] = updated_Date_Values[2]; // Year
}
void Model::SEND_Permission(int Permission_STATE)
{
	Permission_ALERT_STATE = Permission_STATE;
}

