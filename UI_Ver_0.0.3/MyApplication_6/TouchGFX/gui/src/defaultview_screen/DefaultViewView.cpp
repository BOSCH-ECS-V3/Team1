#include <gui/defaultview_screen/DefaultViewView.hpp>

DefaultViewView::DefaultViewView()
{

}

void DefaultViewView::setupScreen()
{
    DefaultViewViewBase::setupScreen();
}

void DefaultViewView::tearDownScreen()
{
    DefaultViewViewBase::tearDownScreen();
}


void DefaultViewView::updateValue(int state)
{
	 CarbonCirc_Val.setValue(state);
}

/*
void DefaultViewView::update_sensor_values(struct values)
{

}
*/


