#ifndef STATISTICS_TEMPERATURE_INSIDEVIEW_HPP
#define STATISTICS_TEMPERATURE_INSIDEVIEW_HPP

#include <gui_generated/statistics_temperature_inside_screen/Statistics_Temperature_InsideViewBase.hpp>
#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsidePresenter.hpp>

class Statistics_Temperature_InsideView : public Statistics_Temperature_InsideViewBase
{
public:
    Statistics_Temperature_InsideView();
    virtual ~Statistics_Temperature_InsideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void set_screen_brightness(int brightness);
    virtual void STATISTICS_tempIN(int statistics_tempIN[24], int tempIN_index);

protected:

    int current_index = 0;
    int tempIN_val[24];
};

#endif // STATISTICS_TEMPERATURE_INSIDEVIEW_HPP
