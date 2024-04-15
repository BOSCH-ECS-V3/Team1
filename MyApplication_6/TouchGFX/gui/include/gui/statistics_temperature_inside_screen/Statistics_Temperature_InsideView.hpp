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
    virtual void SEND_STATISTICS_INFORMATION_TEMPERATURE_INSIDE(int STATISTICS_Temperature_INSIDE[], int STATISTICS_Array_Index);
    virtual void   UpdateData();

    int y_POINT_TEMPERATURE_IN = 0 ;
    int temperatureIN_values[24];
    int array_index = 0;
protected:
};

#endif // STATISTICS_TEMPERATURE_INSIDEVIEW_HPP
