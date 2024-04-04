#ifndef DEFAULTVIEWVIEW_HPP
#define DEFAULTVIEWVIEW_HPP

#include <gui_generated/defaultview_screen/DefaultViewViewBase.hpp>
#include <gui/defaultview_screen/DefaultViewPresenter.hpp>

class DefaultViewView : public DefaultViewViewBase
{
public:
    DefaultViewView();
    virtual ~DefaultViewView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void update_Clock(int Clock_Values[]);
    virtual void handleTickEvent();

    int analogHours ;
    int analogMinutes ;
    int analogSeconds ;
protected:
};

#endif // DEFAULTVIEWVIEW_HPP
