#ifndef AVERAGE_TEMPINVIEW_HPP
#define AVERAGE_TEMPINVIEW_HPP

#include <gui_generated/average_tempin_screen/Average_TempINViewBase.hpp>
#include <gui/average_tempin_screen/Average_TempINPresenter.hpp>

class Average_TempINView : public Average_TempINViewBase
{
public:
    Average_TempINView();
    virtual ~Average_TempINView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void send_average_TempIN(int average_day , int average_week ,  int average_month);

protected:
};

#endif // AVERAGE_TEMPINVIEW_HPP
