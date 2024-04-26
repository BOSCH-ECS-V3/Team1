#ifndef AVERAGE_PRESSUREVIEW_HPP
#define AVERAGE_PRESSUREVIEW_HPP

#include <gui_generated/average_pressure_screen/Average_PressureViewBase.hpp>
#include <gui/average_pressure_screen/Average_PressurePresenter.hpp>

class Average_PressureView : public Average_PressureViewBase
{
public:
    Average_PressureView();
    virtual ~Average_PressureView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void send_average_Pressure(int avrDayPressure_res , int avrWeekPressure_res , int avrMonthPressure_res);
protected:
};

#endif // AVERAGE_PRESSUREVIEW_HPP
