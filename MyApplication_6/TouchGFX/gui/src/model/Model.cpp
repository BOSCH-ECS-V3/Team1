#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <data_UI_def.h>
#include "cmsis_os.h"
#include "semphr.h"
#include "cli.h"


extern "C"{
extern xQueueHandle dataQueue;
SensData_t data_from_UI;

}

int Error_feedback(SensData_t data)
{
	int Error_ID = 0 ;

	//..Passing sensor values to Default page for presenting on screen
	// [0]->TemperatureIn , [1]-> TemperatureOut , [2]-> Humidity , [3]-> Pressure ,[4]->Ambient light
	// [5]->Gas sensor

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

	// Errors Temperature Outside

	if(data.tempIN == TEMP_IN_UNPLUGGED)
	{
		Error_ID = 201 ;

	}else if(data.tempIN < TEMP_IN_MIN_VALUE){

		Error_ID = 202;

	}else if(data.tempIN > TEMP_IN_MAX_VALUE){

		Error_ID = 203;
	}

	// Errors Humidity Sensor

	if(data.humidity == HUMIDITY_UNPLUGGED)
	{
		Error_ID = 301 ;

	}else if(data.humidity < HUMIDITY_MIN_VALUE){

		Error_ID = 302;

	}else if(data.humidity > HUMIDITY_MAX_VALUE){

		Error_ID = 303;
	}

	// Errors Pressure sensor

	if(data.pressure == PRESSURE_UNPLUGGED)
	{
		Error_ID = 401 ;
	}

	// Errors Ambient light sensor

	if(data.ambientLight == AMBIENT_UNPLUGGED)
	{
		Error_ID = 501 ;
	}

	// Errors Gas sensor

	if(data.carbonMonoxide == GAS_UNPLUGGED)
	{
		Error_ID = 601 ;
	}else if(data.carbonMonoxide > GAS_DANGER_VALUES)
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

	/*
	//get clock
	dateTime.hours = Clock_Values[0];
	dateTime.minutes = Clock_Values[1];
	dateTime.seconds = Clock_Values[2];

	//get date
	dateTime.day = current_Date_values[0];
	dateTime.month = current_Date_values[1];
	dateTime.year = current_Date_values[2];

	if (finished != 0) {
//		// set clock
//		Clock_Values[0] = dateTime.hours;
//		Clock_Values[1] = dateTime.minutes;
//		Clock_Values[2] = dateTime.seconds;
//		modelListener->updated_Clock(Clock_Values);
////		// set date
////		current_Date_values[0] = dateTime.day;
////		current_Date_values[1] = dateTime.month;
////		current_Date_values[2] = dateTime.year;
////		modelListener->updateValue(state)(current_Date_values);
	}
	*/
	/* Get data from UI via Queue*/
	if(uxQueueSpacesAvailable(dataQueue) == 0){

		xQueueReceive(dataQueue, &data_from_UI, 0);
	}

	// ----------------------------- Clock Update to View ---> ----------------------------

	/*
	 * Update char every minute. Need to change to Clock_Values[0] to update every hour
	 */
	statistics_index=Clock_Values[1];

	tickCounter++;
	if(tickCounter%60 == 0)
	{
		if(++Clock_Values[2]>=60)
		{
			if(++snoozeCounter == DEFINE_SNOOZE_TIME) // Snoze time counter
			{
				snoozeCounter = 0;
				SNOOZE_FLAG = 0;
			}
			if(++GAS_Preheat_time >= 3)
			{
				GAS_Preheat_FLAG = 1 ;
				GAS_Preheat_time = 3 ;
			}
			/*
			 *  Add new value to the statistics char every MINUTE
			 */

			if(statistics_index == 24)
			{
				statistics_index = 0 ;
			}

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


	/*
	 * We update current Clock & Date values view modelListener->Presenter->View
	 * Clock_Values[] -> current clock values from the system
	 * current_Date_values[] -> current date values from the system
	 */
	modelListener->current_Clock(Clock_Values);
	modelListener->current_Date_value(current_Date_values);

	//..Passing sensor values to Default page for presenting on screen
	// [0]->TemperatureOut , [1]-> TemperatureIn , [2]-> Humidity , [3]-> Pressure ,[4]->Ambient light
	// [5]->Gas sensor

	current_Sensor_values[0] = data_from_UI.tempOUT ;
	current_Sensor_values[1] = data_from_UI.tempIN ;
	current_Sensor_values[2] = data_from_UI.humidity ;
	current_Sensor_values[3] = data_from_UI.pressure ;
	current_Sensor_values[4] = data_from_UI.ambientLight ;
	current_Sensor_values[5] = data_from_UI.carbonMonoxide ;

	modelListener->current_Sensor_values(current_Sensor_values , GAS_Preheat_FLAG);

	/*
	 * By default we set ALERT Permission to TRUE.
	 * This means we will receive notification after starting the device
	 */
	modelListener->RECEIVE_Permission(Permission_ALERT_STATE);

	/*
	 *  <Error_feedback> function return ID of ERROR. For more information about ID meaning, you can
	 *  check inside Error_feedback()
	 *
	 *  We are checking for error and store it in Error_ID. If there is no errors , Error_feedback
	 *  will give us value of 0, otherwise we will get ID number XXX from func.
	 *
	 *  We use Error_ID for passing it to view page;
	 *
	 */

	Error_ID = Error_feedback(data_from_UI);
	/*
	 * If Permission_Alert_STATE = 0 , we will not receive alerts for strange sensor values until
	 * we turn ON this option from the page "ALARM".
	 *
	 * Checking IF SNOOZE button is pressed, if button is pressed , notification and alerts will
	 * stop be shown in view page for 1 minute ! After 1 minute , SNNOZE flag is going off and
	 * alerts will start pop out again.
	 *
	 * If both states are TRUE we can send Error_ID to the view.
	 */

	if(Permission_ALERT_STATE == 1 && SNOOZE_FLAG == 0)
	{
		modelListener->SEND_Error_ID(Error_ID);
	}

	/*
	 * Screen brightness
	 */
	if(current_Sensor_values[4] < 100 )
	{
		brightness = 0 ;
		if(current_Sensor_values[4] < 80)
		{
			brightness = 25 ;
			if(current_Sensor_values[4] < 60)
			{
				brightness = 50 ;
				if(current_Sensor_values[4] < 40)
				{
					brightness = 75 ;
					if(current_Sensor_values[4] < 20)
					{
						brightness = 100 ;
					}
				}

			}
		}
	}
	modelListener->set_screen_brightness(brightness);

	/*
	 * Send information about tempIN Statistics page
	 *
	 *
	 */

	statistics_tempIN[statistics_index] = data_from_UI.tempIN;
	modelListener->STATISTICS_tempIN(statistics_tempIN, statistics_index);


	/*
	 * Send information about TempOut Statistics page
	 */
	statistics_tempOUT[statistics_index] = data_from_UI.tempOUT;
	modelListener->STATISTICS_tempOUT(statistics_tempOUT, statistics_index);

	/*
	 * Send information about Humidity Statistics page
	 */
	statistics_humidity[statistics_index] = data_from_UI.humidity;
	modelListener->STATISTICS_humidity(statistics_humidity, statistics_index);

	/*
	 * Send information about Gas Sensor
	 */
	statistics_gas[statistics_index] = data_from_UI.carbonMonoxide;
	modelListener->STATISTICS_gas(statistics_gas, statistics_index);

	/*
	 * Send information about Pressure
	 */

	statistics_pressure[statistics_index] = data_from_UI.pressure;
	modelListener->STATISTICS_pressure(statistics_pressure , statistics_index);

	/*
	 * Send information about Ambient light values
	 */

	statistics_ambient[statistics_index] = data_from_UI.ambientLight ;
	modelListener->STATISTICS_ambient(statistics_ambient , statistics_index);

}

void Model::update_Clock(int updated_Clock_Values[3])
{

	/* Receive data from Clock View
	 * Clock settings can be changed through "Time" page from the dropdown menu.
	 * When user change Time manually , we receive this change from the view through Presenter.
	 * Values which we receive are updated_Clock_Values[i], where :
	 *
	 * ->  updated_Clock_Values[0] - Hour
	 * ->  updated_Clock_Values[1] - Minute
	 * ->  updated_Clock_values[2] - Seconds
	 *
	 * In our program , for ticking current clock values we use
	 * 	Clock_Values[i] where :
	 * 	Clock_Values[0]= current Hour
	 *	Clock_Values[1] = current Minutes
	 *  Clock_Values[2] = current Seconds
	 *
	 *  When USER submit new Clock setting from UI , we get information from updated_Clock_Values and put
	 *  it in Clock_Values[i]
	 */
	Clock_Values[0] = updated_Clock_Values[0]; // Hours
	Clock_Values[1] = updated_Clock_Values[1]; // Minutes
	Clock_Values[2] = updated_Clock_Values[2]; // Seconds

}
void Model::update_Date(int updated_Date_Values[3])
{

	/* Receive data from Data View
	 * Date settings can be changed through "DATE" page from the dropdown menu.
	 * When user change DATE manually , we receive this change from the view through Presenter.
	 * Values which we receive are updated_Date_value[i]
	 * ->  updated_Date_Values[0] - Day
	 * ->  updated_Date_Values[1] - Month
	 * ->  updated_Date_values[2] - Year
	 *
	 * In our program , for changing date based on clock setting , we use
	 * current_Date_values[i] where :
	 * 	current_Date_values[0] = current Days
	 *	current_Date_values[1] = current Month
	 *  current_Date_values[2] = current Year
	 *
	 *  When USER submit new DATE from UI , we get information from updated_Date_Values and put
	 *  it in current_Date_values
	 */

	current_Date_values[0] = updated_Date_Values[0]; // Days
	current_Date_values[1] = updated_Date_Values[1]; // Month
	current_Date_values[2] = updated_Date_Values[2]; // Year
}
void Model::SEND_Permission(int Permission_STATE)
{

	/*
	 * By default , permission for alerts in set to 1.
	 * This means that we will get alerts
	 * about strange sensor values. This setting can be changed through "ALARM" page from the
	 * dropdown menu of UI.
	 * If Permission_Alert_STATE = 0 , we will not receive alerts for strange sensor values until
	 * we turn ON this option from the page "ALARM".
	 */
	Permission_ALERT_STATE = Permission_STATE;

}
void Model::Snooze_system(int snooze_state)
{

	/* Checking IF SNOOZE button is pressed, if button is pressed , notification and alerts will
	 * stop be shown in view page for 1 minute ! After 1 minute , SNNOZE flag is going off and
	 * alerts will start pop out again.
	 * When snooze button is pressed - snooze flag = 1
	 * When snooze button IS NOT pressed - snooze flag = 0
	 */

	SNOOZE_FLAG = snooze_state;

}

