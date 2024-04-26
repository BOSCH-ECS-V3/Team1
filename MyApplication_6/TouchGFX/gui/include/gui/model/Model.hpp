#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
	Model();

	void bind(ModelListener* listener)
	{
		modelListener = listener;
	}

	void tick();
	void update_Clock(int Clock_Valued[3]);
	void update_Date(int updated_Date_Values[3]);
	void SEND_Permission(int Permission_STATE);
	void Snooze_system(int snooze_state , int flag_TempIN , int flag_Gas , int flag_TempOUT , int flag_Humidity, int flag_Pressure ,int  flag_ambient);
	void set_screen_brightness(int brightness);


protected:
	ModelListener* modelListener;

	// !!! All variables in model.cpp should be declared here to pass them to the presentor->view
	//int Button_state = 100 ;

	int tickCounter = 0;
	int Clock_Values[3]={0,0,0};
	int current_Date_values[3]={4,4,2024};
	int current_Sensor_values[6]={0,0,0,0,0,0};
	int Error_ID = 0 ;

	int Permission_ALERT_STATE = 1 ;
	int snoozeCounter = 0;
	int DEFINE_SNOOZE_TIME = 1 ;
	int SNOOZE_FLAG = 0 ;
	int SNOOZE_FLAG_GAS = 0;
	int SNOOZE_FLAG_TEMPIN = 0 ;
	int SNOOZE_FLAG_TEMPOUT = 0 ;
	int SNOOZE_FLAG_HUMIDITY = 0 ;
	int SNOOZE_FLAG_AMBIENT = 0 ;
	int SNOOZE_FLAG_PRESSURE = 0 ;


	int brightness = 255 ;

	/*
	 * Arrays to store information for statistics
	 */

	int statistics_tempIN[24] ;
	int statistics_tempOUT[24];
	int statistics_humidity[24];
	int statistics_gas[24];
	int statistics_ambient[24];
	int statistics_pressure[24];

	int statistics_index = 0 ;

	int GAS_Preheat_time = 3 ;
	int GAS_Preheat_FLAG = 0 ;

	/*
	 * Average vars for tempIN
	 */
	int TempIN_avr[3] ={0,0,0};
	int avrDayTempIN_res = 0 ; // result for storying average val of the day
	int avrWeekTempIN_res = 0 ; // result for storying average val of the day
	int avrMonthTempIN_res = 0 ; // result for storying average val of the day

	/*
	 * Average vars for tempOUT
	 */
	int TempOUT_avr[3] ={0,0,0};
	int avrDayTempOUT_res = 0 ; // result for storying average val of the day
	int avrWeekTempOUT_res = 0 ; // result for storying average val of the day
	int avrMonthTempOUT_res = 0 ; // result for storying average val of the day


	/*
	 * Average vars for Humidity
	 */
	int Humidity_avr[3] ={0,0,0};
	int avrDayHumidity_res = 0 ; // result for storying average val of the day
	int avrWeekHumidity_res = 0 ; // result for storying average val of the day
	int avrMonthHumidity_res = 0 ; // result for storying average val of the day

	/*
	 * Average vars for Pressure
	 */

	int Pressure_avr[3] ={0,0,0};
	int avrDayPressure_res = 0 ; // result for storying average val of the day
	int avrWeekPressure_res = 0 ; // result for storying average val of the day
	int avrMonthPressure_res = 0 ; // result for storying average val of the day

	/*
	 * Average vars for Gas
	 */

	int Gas_avr[3] ={0,0,0};
	int avrDayGas_res = 0 ; // result for storying average val of the day
	int avrWeekGas_res = 0 ; // result for storying average val of the day
	int avrMonthGas_res = 0 ; // result for storying average val of the day

	/*
	 * Average vars for Gas
	 */

	int Ambient_avr[3] ={0,0,0};
	int avrDayAmbient_res = 0 ; // result for storying average val of the day
	int avrWeekAmbient_res = 0 ; // result for storying average val of the day
	int avrMonthAmbient_res = 0 ; // result for storying average val of the day

	int hourCounter = 0 ; // counter for every hour which passes
	int dayCounter = 0 ; // counter for every day which passes
	int weekCounter = 0 ; // counter for every week which passes



};

#endif // MODEL_HPP
