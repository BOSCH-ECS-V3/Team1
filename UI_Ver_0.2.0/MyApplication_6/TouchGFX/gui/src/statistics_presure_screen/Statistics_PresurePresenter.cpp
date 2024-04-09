#include <gui/statistics_presure_screen/Statistics_PresureView.hpp>
#include <gui/statistics_presure_screen/Statistics_PresurePresenter.hpp>

Statistics_PresurePresenter::Statistics_PresurePresenter(Statistics_PresureView& v)
    : view(v)
{

}

void Statistics_PresurePresenter::activate()
{

}

void Statistics_PresurePresenter::deactivate()
{

}
void Statistics_PresurePresenter::set_brightness_level(int brightness)
{
	view.set_brightness_level(brightness);
}
