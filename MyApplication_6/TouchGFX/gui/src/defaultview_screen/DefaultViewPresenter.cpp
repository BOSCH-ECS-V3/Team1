#include <gui/defaultview_screen/DefaultViewView.hpp>
#include <gui/defaultview_screen/DefaultViewPresenter.hpp>

DefaultViewPresenter::DefaultViewPresenter(DefaultViewView& v)
    : view(v)
{

}

void DefaultViewPresenter::activate()
{

}

void DefaultViewPresenter::deactivate()
{

}

void DefaultViewPresenter::update_Clock(int Clock_Value[3])
{
	view.update_Clock(Clock_Value);
}
void DefaultViewPresenter::current_Sensor_values(int current_Sensor_values[5], int GAS_Preheat_FLAG)
{
	/*
	 * This function is used for sending current Sensor Values to the DefaultViewView page
	 * Values for every sensor is stored in current_Sensor_values array.
	 * Gas_Prehead_FLAG is used for showing preheat msg.
	 */
	view.current_Sensor_values(current_Sensor_values, GAS_Preheat_FLAG);
};
void DefaultViewPresenter::SEND_Error_ID(int Error_ID, int SNOOZE_FLAG_TEMPIN , int SNOOZE_FLAG_GAS , int SNOOZE_FLAG_TEMPOUT , int SNOOZE_FLAG_HUMIDITY, int SNOOZE_FLAG_PRESSURE , int SNOOZE_FLAG_AMBIENT)
{
	/*
	 * This function is used for sending Error_ID to the DefaultViewView page.
	 * If we have error_ID != 0 , we will receive pop up alert on screen , if notification
	 * option is not turen OFF.
	 */
	view.SEND_Error_ID(Error_ID,SNOOZE_FLAG_TEMPIN , SNOOZE_FLAG_GAS , SNOOZE_FLAG_TEMPOUT , SNOOZE_FLAG_HUMIDITY, SNOOZE_FLAG_PRESSURE , SNOOZE_FLAG_AMBIENT);
};
void DefaultViewPresenter::Snooze_system(int snooze_state, int flag_TempIN , int flag_Gas , int flag_TempOUT , int flag_Humidity, int flag_Pressure , int flag_Ambient)
{
	/*
	 * This function is used for snoozing alarms. If this function is turen on , we will not
	 * receive notification for period of time.
	 */
	model->Snooze_system(snooze_state, flag_TempIN , flag_Gas , flag_TempOUT , flag_Humidity, flag_Pressure , flag_Ambient);
}
void DefaultViewPresenter::set_screen_brightness(int brightness)
{
	/*
	 * This function is used for adjustment screen brightness
	 */
	view.set_screen_brightness(brightness);
}

