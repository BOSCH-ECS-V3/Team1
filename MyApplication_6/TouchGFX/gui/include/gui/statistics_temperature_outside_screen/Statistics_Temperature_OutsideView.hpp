#ifndef STATISTICS_TEMPERATURE_OUTSIDEVIEW_HPP
#define STATISTICS_TEMPERATURE_OUTSIDEVIEW_HPP

#include <gui_generated/statistics_temperature_outside_screen/Statistics_Temperature_OutsideViewBase.hpp>
#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsidePresenter.hpp>

class Statistics_Temperature_OutsideView : public Statistics_Temperature_OutsideViewBase
{
public:
    Statistics_Temperature_OutsideView();
    virtual ~Statistics_Temperature_OutsideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void set_screen_brightness(int brightness);
    virtual void STATISTICS_tempOUT(int statistics_tempOUT[24], int statistics_index);

protected:

    int tempOUT_val[24];
    int current_index = 0 ;

};

#endif // STATISTICS_TEMPERATURE_OUTSIDEVIEW_HPP
