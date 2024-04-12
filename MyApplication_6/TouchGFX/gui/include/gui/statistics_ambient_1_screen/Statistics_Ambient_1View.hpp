#ifndef STATISTICS_AMBIENT_1VIEW_HPP
#define STATISTICS_AMBIENT_1VIEW_HPP

#include <gui_generated/statistics_ambient_1_screen/Statistics_Ambient_1ViewBase.hpp>
#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1Presenter.hpp>

class Statistics_Ambient_1View : public Statistics_Ambient_1ViewBase
{
public:
    Statistics_Ambient_1View();
    virtual ~Statistics_Ambient_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STATISTICS_AMBIENT_1VIEW_HPP
