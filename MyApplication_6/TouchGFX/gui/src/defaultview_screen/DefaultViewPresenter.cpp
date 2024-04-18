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
void DefaultViewPresenter::current_Sensor_values(int current_Sensor_values[5])
{
	view.current_Sensor_values(current_Sensor_values);
};
void DefaultViewPresenter::SEND_Error_ID(int Error_ID)
{
	view.SEND_Error_ID(Error_ID);
};
void DefaultViewPresenter::Snooze_system(int snooze_state)
{
	model->Snooze_system(snooze_state);
}
void DefaultViewPresenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}

