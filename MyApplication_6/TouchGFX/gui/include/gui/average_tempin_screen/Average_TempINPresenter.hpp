#ifndef AVERAGE_TEMPINPRESENTER_HPP
#define AVERAGE_TEMPINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Average_TempINView;

class Average_TempINPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Average_TempINPresenter(Average_TempINView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();
    virtual void send_average_TempIN(int average_day , int average_week ,  int average_month);

    virtual ~Average_TempINPresenter() {}

private:
    Average_TempINPresenter();

    Average_TempINView& view;
};

#endif // AVERAGE_TEMPINPRESENTER_HPP
