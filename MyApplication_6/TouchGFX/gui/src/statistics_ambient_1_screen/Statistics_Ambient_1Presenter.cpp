#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1View.hpp>
#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1Presenter.hpp>

Statistics_Ambient_1Presenter::Statistics_Ambient_1Presenter(Statistics_Ambient_1View& v)
    : view(v)
{

}

void Statistics_Ambient_1Presenter::activate()
{

}

void Statistics_Ambient_1Presenter::deactivate()
{

}

void Statistics_Ambient_1Presenter::set_screen_brightness(int brightness)
{
	view.set_screen_brightness(brightness);
}
void Statistics_Ambient_1Presenter::STATISTICS_ambient(int statistics_ambient[24] , int statistics_index)
{
	/*
	 * This function is used to pass statistics values to ambient statistics char
	 * statistics_ambient array are pasts 24 hour values and statistics index is current hour to place
	 * value
	 */
	view.STATISTICS_ambient(statistics_ambient , statistics_index);
}
