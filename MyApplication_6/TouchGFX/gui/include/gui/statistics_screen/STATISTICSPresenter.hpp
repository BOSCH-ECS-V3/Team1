#ifndef STATISTICSPRESENTER_HPP
#define STATISTICSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class STATISTICSView;

class STATISTICSPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    STATISTICSPresenter(STATISTICSView& v);

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

    virtual ~STATISTICSPresenter() {}

private:
    STATISTICSPresenter();

    STATISTICSView& view;
};

#endif // STATISTICSPRESENTER_HPP
