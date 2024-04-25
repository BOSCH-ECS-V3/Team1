#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <data_UI_def.h>
#include "cmsis_os.h"
#include "semphr.h"
#include "cli.h"

/*
 * Define Every month value , used for Date algorithm
 */
#define January 1
#define February 2
#define March 3
#define April 4
#define May 5
#define June 6
#define July 7
#define August 8
#define September 9
#define October 10
#define November 11
#define December 12

extern "C"{
extern xQueueHandle dataQueue;
SensData_t data_from_UI;

}


/*
 * Error Function feedback is used to give back ERROR_ID, which is selected based on
 * Sensors measurements. This ERROR_ID is send to DefaultViewView.cpp -> UI
 */

int Error_feedback(SensData_t data , int GAS_Preheat_FLAG , int SNOOZE_FLAG_TEMPIN , int SNOOZE_FLAG_GAS , int SNOOZE_FLAG_TEMPOUT , int SNOOZE_FLAG_HUMIDITY, int SNOOZE_FLAG_PRESSURE , int SNOOZE_FLAG_AMBIENT)
{
	int Error_ID = 0 ;

	//..Passing sensor values to Default page for presenting on screen
	// [0]->TemperatureIn , [1]-> TemperatureOut , [2]-> Humidity , [3]-> Pressure ,[4]->Ambient light
	// [5]->Gas sensor

	/*  Error List Code

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

	ID with 5xx - > Ambient Light sensor

	Ambient Light Sensor Disconnected ------------> 501

	ID with 6xx - > Gas sensor

	Gas Sensor Disconnected   ------------> 601
	Gas Light Sensor More than 2000ppm ---> 603

	 */

	// Errors Temperature Inside
	if(SNOOZE_FLAG_TEMPIN != 1)
	{
		if(data.tempIN == TEMP_IN_UNPLUGGED)
		{
			Error_ID = 101 ;

		}else if(data.tempIN < TEMP_IN_MIN_VALUE){

			Error_ID = 102;

		}else if(data.tempIN > TEMP_IN_MAX_VALUE){

			Error_ID = 103;
		}
	}

	// Error Template Outside
	if(SNOOZE_FLAG_TEMPOUT != 1)
	{
		if(data.tempOUT == TEMP_OUT_UNPLUGGED)
			{
				Error_ID = 201 ;

			}else if(data.tempOUT < TEMP_OUT_MIN_VALUE){

				Error_ID = 202;

			}else if(data.tempOUT > TEMP_OUT_MAX_VALUE){

				Error_ID = 203;
			}
	}


	// Errors Humidity Sensor
	if(SNOOZE_FLAG_HUMIDITY != 1)
	{
		if(data.humidity == HUMIDITY_UNPLUGGED)
		{
			Error_ID = 301 ;

		}else if(data.humidity < HUMIDITY_MIN_VALUE){

			Error_ID = 302;

		}else if(data.humidity > HUMIDITY_MAX_VALUE){

			Error_ID = 303;
		}
	}


	// Errors Pressure sensor

	if(SNOOZE_FLAG_PRESSURE != 1)
	{
		if(data.pressure == PRESSURE_UNPLUGGED)
			{
				Error_ID = 401 ;
			}
	}


	// Errors Ambient light sensor

	if(SNOOZE_FLAG_AMBIENT != 1)
	{
		if(data.ambientLight == AMBIENT_UNPLUGGED)
		{
			Error_ID = 501 ;
		}
	}


	// Errors Gas sensor

	if(SNOOZE_FLAG_GAS != 1)
	{
		if(data.carbonMonoxide == GAS_UNPLUGGED)
		{
			Error_ID = 601 ;
		}else if((GAS_Preheat_FLAG==1) && (data.carbonMonoxide > GAS_DANGER_VALUES))
		{
			Error_ID = 603 ;
		}
	}



	return Error_ID ;
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

	/*
	 * Read clock and date values from the Command line interface structure
	 */

	if(finished!=0)
	{
		// set clock
		Clock_Values[0] = dateTime.hours;
		Clock_Values[1] = dateTime.minutes;
		Clock_Values[2] = dateTime.seconds;

		// set date
		current_Date_values[0] = dateTime.day;
		current_Date_values[1] = dateTime.month;
		current_Date_values[2] = dateTime.year;

		finished = 0 ;
	}



	/* Get data from UI via Queue*/
	if(uxQueueSpacesAvailable(dataQueue) == 0){

		xQueueReceive(dataQueue, &data_from_UI, 0);
	}

	// ----------------------------- Clock Update to View ---> ----------------------------

	/*
	 * Statistics index is used to indicate where in statistic char to put new value.
	 */
	statistics_index=Clock_Values[0];

	tickCounter++;
	if(tickCounter%60 == 0)
	{
		//  counter ++

		if(statistics_index > 24)
		{
			statistics_index = 0 ;
		}

		/*
		 * Send Clock_Values to dateTime Structure (CLI)
		 */

		//get clock
		dateTime.hours = Clock_Values[0];
		dateTime.minutes = Clock_Values[1];
		dateTime.seconds = Clock_Values[2];

		//get date
		dateTime.day = current_Date_values[0];
		dateTime.month = current_Date_values[1];
		dateTime.year = current_Date_values[2];

		if(++Clock_Values[2]>=60) // If current SECONDS ARE MORE THAN 60 , Change MINUTE , reset SECONDS
		{
			/*
			 *  Code below is executed every MINUTE
			 */
			if(++snoozeCounter == DEFINE_SNOOZE_TIME) // Snozoe time counter
			{
				snoozeCounter = 0;
				SNOOZE_FLAG = 0;
				SNOOZE_FLAG_TEMPIN = 0 ;
				SNOOZE_FLAG_TEMPOUT = 0;
				SNOOZE_FLAG_HUMIDITY = 0;
				SNOOZE_FLAG_PRESSURE = 0;
				SNOOZE_FLAG_AMBIENT = 0 ;
				SNOOZE_FLAG_GAS = 0 ;

			}

			/*
			 * GAS_Preheat_FLAG is used for showing PREHEAT msg for GAS sensor, when we boot our module
			 * for first time
			 */
			if(++GAS_Preheat_time >= 3)
			{
				GAS_Preheat_FLAG = 1 ;
				GAS_Preheat_time = 3 ;
			}

			Clock_Values[2] = 0;
			if(++Clock_Values[1]>=60) // If current MINUTES ARE MORE THAN 60 , Change hour , reset minutes
			{
				/*
				 *  Code below is executed every HOUR
				 */
				/*
				 * hourCounter is used for average calculations.
				 * When hourCounter = 24 , we calculate average sensor values for past 24 hours
				 * and increase dayCounter. When dayCounter is = 7 , we calculate average
				 * week value for past 7 days , and increase weekCounter. When weekCounter = 4
				 * we calculate average month value for every sensor.
				 */
				hourCounter++;

				TempIN_avr[0] = TempIN_avr[0] + data_from_UI.tempIN;
				TempOUT_avr[0] = TempOUT_avr[0] + data_from_UI.tempOUT;
				Humidity_avr[0] = Humidity_avr[0] + data_from_UI.humidity;
				Pressure_avr[0] = Pressure_avr[0] + data_from_UI.pressure;
				Ambient_avr[0] = Ambient_avr[0] + data_from_UI.ambientLight;

				Clock_Values[1] = 0;

				if(++Clock_Values[0]>=24) // If current HOURS ARE MORE THAN 24 , Change day , reset hours
				{
					Clock_Values[0] = 0;

					/*
					 * Code below is used to update current_Date_values based on clock parameters
					 * if the day experince , change date
					 */
					if(current_Date_values[1] ==  January || current_Date_values[1] ==  March ||
							current_Date_values[1] ==  May || current_Date_values[1] ==  July ||
							current_Date_values[1] ==  August || current_Date_values[1] ==  October ||
							current_Date_values[1] ==  December)
					{
						if(++current_Date_values[0]>=31)
						{
							current_Date_values[0] = 1 ;
							current_Date_values[1]++;
						}
					}
					if(current_Date_values[1] ==  April || current_Date_values[1] == June ||
							current_Date_values[1] ==  September || current_Date_values[1] ==  November)
					{
						if(++current_Date_values[0]>=30)
						{
							current_Date_values[0] = 1 ;
							current_Date_values[1]++;
						}
					}
					if(current_Date_values[1] ==  February)
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

	Error_ID = Error_feedback(data_from_UI , GAS_Preheat_FLAG , SNOOZE_FLAG_TEMPIN , SNOOZE_FLAG_GAS , SNOOZE_FLAG_TEMPOUT , SNOOZE_FLAG_HUMIDITY, SNOOZE_FLAG_PRESSURE , SNOOZE_FLAG_AMBIENT);
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

	if(Permission_ALERT_STATE == 1)
	{
		modelListener->SEND_Error_ID(Error_ID , SNOOZE_FLAG_TEMPIN , SNOOZE_FLAG_GAS , SNOOZE_FLAG_TEMPOUT , SNOOZE_FLAG_HUMIDITY, SNOOZE_FLAG_PRESSURE , SNOOZE_FLAG_AMBIENT);
	}

	/*
	 * Calculate screen brightness based on Ambient Light Sensor.
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
	 * hourCounter is used for average calculations.
	 * When hourCounter = 24 , we calculate average sensor values for past 24 hours
	 * and increase dayCounter. When dayCounter is = 7 , we calculate average
	 * week value for past 7 days , and increase weekCounter. When weekCounter = 4
	 * we calculate average month value for every sensor.
	 */

	if(hourCounter == 24)
	{
		avrDayTempIN_res = TempIN_avr[0] / 24 ; // Temp IN
		avrDayTempOUT_res = TempOUT_avr[0] / 24 ; // Temp OUT
		avrDayHumidity_res = Humidity_avr[0] / 24 ; // Humidity
		avrDayPressure_res = Pressure_avr[0] / 24; // Pressure
		avrDayGas_res = Gas_avr[0] / 24 ;
		avrDayAmbient_res = Ambient_avr[0] / 24;

		// reset hours
		hourCounter = 0;
		TempIN_avr[0] = 0; // Temp IN
		TempOUT_avr[0] = 0; // Temp OUT
		Humidity_avr[0] = 0;
		Pressure_avr[0] = 0;
		Gas_avr[0] = 0;
		Ambient_avr[0] = 0;

		dayCounter++;
		TempIN_avr[1] = TempIN_avr[1] + avrDayTempIN_res;
		TempOUT_avr[1] = TempOUT_avr[1] + avrDayTempOUT_res;
		Humidity_avr[1] = Humidity_avr[1] + avrDayHumidity_res;
		Pressure_avr[1] = Pressure_avr[1] + avrDayPressure_res;
		Ambient_avr[1] = Ambient_avr[1] + avrDayAmbient_res;
		Gas_avr[1] = Gas_avr[1] + avrDayGas_res;



		if(dayCounter==7)
		{
			dayCounter = 0;
			avrWeekTempIN_res = TempIN_avr[1] / 7 ;
			avrWeekTempOUT_res = TempOUT_avr[1] / 7 ;
			avrWeekHumidity_res = Humidity_avr[1] / 7 ;
			avrWeekPressure_res = Pressure_avr[1] / 7;
			avrWeekGas_res = Gas_avr[1] / 7 ;
			avrWeekAmbient_res = Ambient_avr[1] / 7;

			TempIN_avr[1] = 0;
			TempOUT_avr[1] = 0;
			Humidity_avr[1] = 0;
			Pressure_avr[1] = 0;
			Gas_avr[1] = 0 ;
			Ambient_avr[1] = 0;

			weekCounter++;

			TempIN_avr[2] = TempIN_avr[2] + avrWeekTempIN_res;
			TempOUT_avr[2] = TempOUT_avr[2] + avrWeekTempOUT_res;
			Humidity_avr[2] = Humidity_avr[2] + avrWeekHumidity_res;
			Pressure_avr[2] = Pressure_avr[2] + avrWeekHumidity_res;
			Gas_avr[2] = Gas_avr[2] + avrWeekGas_res;
			Ambient_avr[2] = Ambient_avr[2] + avrWeekAmbient_res;

			if(weekCounter==4)
			{
				weekCounter = 0 ;
				avrMonthTempIN_res = TempIN_avr[2] / 4 ;
				avrMonthTempOUT_res = TempOUT_avr[2] / 4 ;
				avrMonthHumidity_res = Humidity_avr[2] / 4 ;
				avrMonthPressure_res = Pressure_avr[2] / 4;
				avrMonthGas_res = Gas_avr[2] / 4 ;
				avrMonthAmbient_res = Ambient_avr[2] / 4;

				TempIN_avr[2] = 0;
				TempOUT_avr[2] = 0;
				Humidity_avr[2] = 0;
				Pressure_avr[2] = 0;
				Gas_avr[2] = 0;
				Ambient_avr[2] = 0;
			}
		}

	}


	/*
	 * Send information about average values to presenters
	 */
	modelListener->send_average_TempIN(avrDayTempIN_res , avrWeekTempIN_res , avrMonthTempIN_res);
	modelListener->send_average_TempOUT(avrDayTempOUT_res , avrWeekTempOUT_res , avrMonthTempOUT_res);
	modelListener->send_average_Humidity(avrDayHumidity_res , avrWeekHumidity_res , avrMonthHumidity_res);
	modelListener->send_average_Pressure(avrDayPressure_res , avrWeekPressure_res , avrMonthPressure_res);
	modelListener->send_average_Gas(avrDayGas_res , avrWeekGas_res , avrMonthGas_res);
	modelListener->send_average_Ambient(avrDayAmbient_res , avrWeekAmbient_res , avrMonthAmbient_res);

	/*
	 * Send information about TempIN Statistics page
	 */
	statistics_tempIN[statistics_index] = data_from_UI.tempIN;
	modelListener->STATISTICS_tempIN(statistics_tempIN, statistics_index , 7 );
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
void Model::Snooze_system(int snooze_state, int flag_TempIN , int flag_Gas , int flag_TempOUT , int flag_Humidity, int flag_Pressure , int flag_Ambient)
{

	/* Checking IF SNOOZE button is pressed, if button is pressed , notification and alerts will
	 * stop be shown in view page for 1 minute ! After 1 minute , SNNOZE flag is going off and
	 * alerts will start pop out again.
	 * When snooze button is pressed - snooze flag = 1
	 * When snooze button IS NOT pressed - snooze flag = 0
	 */

	SNOOZE_FLAG = snooze_state;
	SNOOZE_FLAG_TEMPIN = flag_TempIN;
	SNOOZE_FLAG_GAS = flag_Gas;
	SNOOZE_FLAG_TEMPOUT = flag_TempOUT;
	SNOOZE_FLAG_HUMIDITY = flag_Humidity;
	SNOOZE_FLAG_AMBIENT = flag_Ambient;
	SNOOZE_FLAG_PRESSURE = flag_Pressure;

}

