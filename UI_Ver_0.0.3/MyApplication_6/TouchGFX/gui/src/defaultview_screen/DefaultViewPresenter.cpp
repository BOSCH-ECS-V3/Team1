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

void DefaultViewPresenter::updateValue(int state)
{
	view.updateValue(state);
}


/*
void DefaultViewPresenter::update_sensor_values(struct values)
{
    view.update_sensor_values(values);
}
*/

