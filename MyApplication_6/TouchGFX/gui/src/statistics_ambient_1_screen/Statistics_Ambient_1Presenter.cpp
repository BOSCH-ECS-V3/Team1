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
