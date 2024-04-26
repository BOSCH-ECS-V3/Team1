#ifndef STATISTICS_PRESUREVIEW_HPP
#define STATISTICS_PRESUREVIEW_HPP

#include <gui_generated/statistics_presure_screen/Statistics_PresureViewBase.hpp>
#include <gui/statistics_presure_screen/Statistics_PresurePresenter.hpp>

class Statistics_PresureView : public Statistics_PresureViewBase
{
public:
    Statistics_PresureView();
    virtual ~Statistics_PresureView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void set_screen_brightness(int brightness);
    virtual void STATISTICS_pressure(int statistics_pressure[24] , int statistics_index);


protected:

    int pressure_val[24];
    int current_index = 0 ;
};

#endif // STATISTICS_PRESUREVIEW_HPP
