#include <gui/defaultview_screen/DefaultViewView.hpp>

DefaultViewView::DefaultViewView()
{

}

void DefaultViewView::setupScreen()
{
	DefaultViewViewBase::setupScreen();
	analogHours = digitalClock1.getCurrentHour();
	analogMinutes = digitalClock1.getCurrentMinute();
	analogSeconds = digitalClock1.getCurrentSecond();
}

void DefaultViewView::tearDownScreen()
{
	DefaultViewViewBase::tearDownScreen();
}


void DefaultViewView::update_Clock(int Clock_Values[])
{

	analogHours = Clock_Values[0];
	analogMinutes = Clock_Values[1];
	analogSeconds = Clock_Values[2];

}

void DefaultViewView::handleTickEvent()
{
	digitalClock1.setTime24Hour(analogHours, analogMinutes, analogSeconds);
	digitalClock1.invalidate();

	Carbon_Val.invalidate();
	TempOut_Val.invalidate();
	TempIn_Val.invalidate();
	Humidity_Val.invalidate();
	Presure_Val.invalidate();
	Ambient_Val.invalidate();
}

void DefaultViewView::SEND_Error_ID(int Error_ID , int SNOOZE_FLAG_TEMPIN , int SNOOZE_FLAG_GAS , int SNOOZE_FLAG_TEMPOUT , int SNOOZE_FLAG_HUMIDITY, int SNOOZE_FLAG_PRESSURE , int SNOOZE_FLAG_AMBIENT)
{
	current_ERROR_ID = Error_ID ;


	if(current_ERROR_ID != 0) // If there is error , update UI
	{
		Alert_cover.setVisible(true);
		Unicode::snprintf(Error_codeBuffer, ERROR_CODE_SIZE, "%d", current_ERROR_ID);

		if(SNOOZE_FLAG_TEMPIN == 0)
		{
			switch(current_ERROR_ID) {
			//------------------------TempIN-----------------------------------
			case 101:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Temperature Inside Sensor \ndisconnected!");
				break;
			case 102:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Temperature Inside \nEXTREMELY LOW");
				break;
			case 103:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Temperature Inside \nEXTREMELY HIGH");
				break;
			}
		}
		//--------------------------TEMPOUT---------------------------------

		if(SNOOZE_FLAG_TEMPOUT == 0)
		{
			switch(current_ERROR_ID)
					{
					case 201:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Temperature Outside Sensor \ndisconnected!");
						break;
					case 202:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Temperature Outside \nEXTREMELY LOW");
						break;
					case 203:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Temperature Outside \nEXTREMELY HIGH");
						break;
					}
		}


		//------------------------Humidity-----------------------------------
		if(SNOOZE_FLAG_HUMIDITY == 0)
		{
			switch(current_ERROR_ID)
					{
					case 301:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Humidity Sensor \ndisconnected!");
						break;
					case 302:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Humidity \nEXTREMELY LOW");
						break;
					case 303:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Humidity \nEXTREMELY HIGH");
						break;
					}
		}

		//--------------------------Pressure---------------------------------
		if(SNOOZE_FLAG_PRESSURE == 0)
		{
			switch(current_ERROR_ID)
					{
					case 401:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Pressure Sensor \ndisconnected!");
						break;
					case 402:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Pressure \nEXTREMELY LOW");
						break;
					case 403:
						Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Pressure \nEXTREMELY HIGH");
						break;
					}
		}


		//------------------------Ambient-----------------------------------
		if(SNOOZE_FLAG_AMBIENT == 0)
		{
			switch(current_ERROR_ID)
			{
			case 501:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Ambient Sensor \ndisconnected!");
				break;
			case 502:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Ambient \nEXTREMELY LOW");
				break;
			case 503:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Ambient \nEXTREMELY HIGH");
				break;
			}

		}

		//--------------------------Gas---------------------------------
		if(SNOOZE_FLAG_GAS == 0)
		{
			switch(current_ERROR_ID)
			{
			case 601:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Gas Sensor \ndisconnected!");
				break;
			case 602:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Gas \nEXTREMELY LOW");
				break;
			case 603:
				Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "Gas \nEXTREMELY HIGH");
				break;
			}
		}
	}


	Alert_cover.invalidate();
	Error_code.invalidate();
	Error_text.invalidate();

}

void DefaultViewView::current_Sensor_values(int current_Sensor_values[] , int GAS_Preheat_FLAG)
{
	// Receiving sensor values from model and store them in var
	//..Passing sensor values to Default page for presenting on screen
	// [0]->TemperatureIn , [1]-> TemperatureOut , [2]-> Humidity , [3]-> Pressure ,[4]->Ambient light
	// [5]->Gas sensor
	Temperature_Sensor_INSIDE_values = current_Sensor_values[0];
	Temperature_Sensor_OUTSIDE_value = current_Sensor_values[1];
	Humidity_Sensor_value = current_Sensor_values[2];
	Pressure_Sensor_value = current_Sensor_values[3];
	Ambient_Light_Sensor_value = current_Sensor_values[4];
	if(GAS_Preheat_FLAG == 1)
	{
		Preheat_msg.setVisible(false);
		Preheat_msg.invalidate();
		Gas_Sensor_value = current_Sensor_values[5] ;
	}


	// updating values to view

	Unicode::snprintf(TempOut_ValBuffer, TEMPOUT_VAL_SIZE, "%d", Temperature_Sensor_INSIDE_values);

	Unicode::snprintf(TempIn_ValBuffer, TEMPIN_VAL_SIZE, "%d", Temperature_Sensor_OUTSIDE_value);

	Unicode::snprintf(Humidity_ValBuffer, HUMIDITY_VAL_SIZE, "%d", Humidity_Sensor_value);

	Unicode::snprintf(Presure_ValBuffer, PRESURE_VAL_SIZE, "%d", Pressure_Sensor_value);

	Unicode::snprintf(Ambient_ValBuffer, AMBIENT_VAL_SIZE, "%d", Ambient_Light_Sensor_value);

	Unicode::snprintf(Carbon_ValBuffer, CARBON_VAL_SIZE, "%d",  Gas_Sensor_value );

};

void DefaultViewView::Snooze_btn_pressed()
{
	snooze_state = 1 ;

	if(current_ERROR_ID == 101 || current_ERROR_ID == 102 || current_ERROR_ID == 103)
	{
		flag_TempIN = 1;
	}
	if(current_ERROR_ID == 601 || current_ERROR_ID == 602 || current_ERROR_ID == 603)
	{
		flag_Gas = 1;
	}
	if(current_ERROR_ID == 201 || current_ERROR_ID == 202 || current_ERROR_ID == 203)
	{
		flag_TempOUT = 1;
	}
	if(current_ERROR_ID == 301 || current_ERROR_ID == 302 || current_ERROR_ID == 303)
	{
		flag_Humidity = 1;
	}
	if(current_ERROR_ID == 401 || current_ERROR_ID == 402 || current_ERROR_ID == 403)
	{
		flag_Pressure = 1;
	}
	if(current_ERROR_ID == 501 || current_ERROR_ID == 502 || current_ERROR_ID == 503)
	{
		flag_ambient = 1;
	}


	presenter->Snooze_system(snooze_state , flag_TempIN , flag_Gas , flag_TempOUT , flag_Humidity, flag_Pressure , flag_ambient);
	snooze_state = 0 ;
}

void DefaultViewView::set_screen_brightness(int brightness)
{
	Brightness_level.setAlpha(brightness);
	Brightness_level.invalidate();
}
