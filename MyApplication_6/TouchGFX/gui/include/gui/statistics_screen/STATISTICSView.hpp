#ifndef STATISTICSVIEW_HPP
#define STATISTICSVIEW_HPP

#include <gui_generated/statistics_screen/STATISTICSViewBase.hpp>
#include <gui/statistics_screen/STATISTICSPresenter.hpp>

class STATISTICSView : public STATISTICSViewBase
{
public:
    STATISTICSView();
    virtual ~STATISTICSView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STATISTICSVIEW_HPP
