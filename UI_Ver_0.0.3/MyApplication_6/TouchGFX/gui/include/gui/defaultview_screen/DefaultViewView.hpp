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
    virtual void updateValue(int state);
    // virtual void clock_setup(int Hours , int Minutes , int Seconds);
  //  virtual void update_sensor_values(struct values);
protected:
};

#endif // DEFAULTVIEWVIEW_HPP
