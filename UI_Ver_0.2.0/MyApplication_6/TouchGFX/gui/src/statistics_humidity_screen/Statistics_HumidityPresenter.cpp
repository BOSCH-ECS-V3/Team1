#include <gui/statistics_humidity_screen/Statistics_HumidityView.hpp>
#include <gui/statistics_humidity_screen/Statistics_HumidityPresenter.hpp>

Statistics_HumidityPresenter::Statistics_HumidityPresenter(Statistics_HumidityView& v)
    : view(v)
{

}

void Statistics_HumidityPresenter::activate()
{

}

void Statistics_HumidityPresenter::deactivate()
{

}

void Statistics_HumidityPresenter::set_brightness_level(int brightness)
{
	view.set_brightness_level(brightness);
}
