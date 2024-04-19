#ifndef STATISTICS_PRESUREPRESENTER_HPP
#define STATISTICS_PRESUREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Statistics_PresureView;

class Statistics_PresurePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Statistics_PresurePresenter(Statistics_PresureView& v);

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
    virtual void set_screen_brightness(int brightness);

    virtual ~Statistics_PresurePresenter() {}

private:
    Statistics_PresurePresenter();

    Statistics_PresureView& view;
};

#endif // STATISTICS_PRESUREPRESENTER_HPP
