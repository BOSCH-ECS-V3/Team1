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
}

void DefaultViewView::current_Sensor_values(int current_Sensor_values[])
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
    Gas_Sensor_value = current_Sensor_values[5] ;

    // updating values to view

    Unicode::snprintf(TempOut_ValBuffer, TEMPOUT_VAL_SIZE, "%d", Temperature_Sensor_INSIDE_values);
    Unicode::snprintf(TempIn_ValBuffer, TEMPIN_VAL_SIZE, "%d", Temperature_Sensor_OUTSIDE_value);
    Unicode::snprintf(Humidity_ValBuffer, HUMIDITY_VAL_SIZE, "%d", Humidity_Sensor_value);
    Unicode::snprintf(Presure_ValBuffer, PRESURE_VAL_SIZE, "%d", Pressure_Sensor_value);
    Unicode::snprintf(Ambient_ValBuffer, AMBIENT_VAL_SIZE, "%d", Ambient_Light_Sensor_value);
    Unicode::snprintf(Carbon_ValBuffer, CARBON_VAL_SIZE, "%d", Gas_Sensor_value );
};
void DefaultViewView::set_brightness_level(int brightness)
{
	// Setting screen brightness level

	Screen_Brightness.setAlpha(brightness);
	Screen_Brightness.invalidate();

}
