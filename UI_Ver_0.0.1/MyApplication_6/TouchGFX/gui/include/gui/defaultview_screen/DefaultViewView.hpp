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
protected:
};

#endif // DEFAULTVIEWVIEW_HPP
