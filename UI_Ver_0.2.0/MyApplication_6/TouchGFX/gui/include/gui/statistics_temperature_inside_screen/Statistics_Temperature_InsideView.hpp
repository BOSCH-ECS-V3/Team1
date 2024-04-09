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
    virtual void set_brightness_level(int brightness);
protected:
};

#endif // STATISTICS_TEMPERATURE_INSIDEVIEW_HPP
