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

	int Statistics_Flag = 0 ;
	int STATISTICS_Temperature_INSIDE[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int STATISTICS_Array_Index = 5;

	int STATISCITS_INIT=1;

};

#endif // MODEL_HPP
