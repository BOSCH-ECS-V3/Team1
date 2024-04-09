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
    virtual void set_brightness_level(int brightness);

protected:
};

#endif // STATISTICS_PRESUREVIEW_HPP
