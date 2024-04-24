#ifndef AVERAGE_AMBIENTLIGHTVIEW_HPP
#define AVERAGE_AMBIENTLIGHTVIEW_HPP

#include <gui_generated/average_ambientlight_screen/Average_AmbientLightViewBase.hpp>
#include <gui/average_ambientlight_screen/Average_AmbientLightPresenter.hpp>

class Average_AmbientLightView : public Average_AmbientLightViewBase
{
public:
    Average_AmbientLightView();
    virtual ~Average_AmbientLightView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void send_average_Ambient(int avrDayAmbient_res , int avrWeekAmbient_res , int avrMonthAmbient_res);
protected:
};

#endif // AVERAGE_AMBIENTLIGHTVIEW_HPP
