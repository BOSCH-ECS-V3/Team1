#include <gui/average_ambientlight_screen/Average_AmbientLightView.hpp>
#include <gui/average_ambientlight_screen/Average_AmbientLightPresenter.hpp>

Average_AmbientLightPresenter::Average_AmbientLightPresenter(Average_AmbientLightView& v)
    : view(v)
{

}

void Average_AmbientLightPresenter::activate()
{

}

void Average_AmbientLightPresenter::deactivate()
{

}

void Average_AmbientLightPresenter::send_average_Ambient(int avrDayAmbient_res , int avrWeekAmbient_res , int avrMonthAmbient_res)
{
	view.send_average_Ambient(avrDayAmbient_res , avrWeekAmbient_res , avrMonthAmbient_res);
}
