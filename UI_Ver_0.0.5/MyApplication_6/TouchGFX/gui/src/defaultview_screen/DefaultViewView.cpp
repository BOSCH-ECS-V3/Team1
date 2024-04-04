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
}

