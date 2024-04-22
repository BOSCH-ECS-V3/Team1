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
	void Snooze_system(int snooze_state);
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

	typedef struct
	{
	    int average_day;
	    int average_week;
	    int average_month;
	}Average_val;


};

#endif // MODEL_HPP
