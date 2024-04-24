#ifndef AVERAGE_GASVIEW_HPP
#define AVERAGE_GASVIEW_HPP

#include <gui_generated/average_gas_screen/Average_GasViewBase.hpp>
#include <gui/average_gas_screen/Average_GasPresenter.hpp>

class Average_GasView : public Average_GasViewBase
{
public:
    Average_GasView();
    virtual ~Average_GasView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void send_average_Gas(int avrDayGas_res ,int avrWeekGas_res ,int avrMonthGas_res);
protected:
};

#endif // AVERAGE_GASVIEW_HPP
