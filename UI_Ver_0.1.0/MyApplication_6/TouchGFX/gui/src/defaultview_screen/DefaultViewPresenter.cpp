#include <gui/defaultview_screen/DefaultViewView.hpp>
#include <gui/defaultview_screen/DefaultViewPresenter.hpp>

DefaultViewPresenter::DefaultViewPresenter(DefaultViewView& v)
    : view(v)
{

}

void DefaultViewPresenter::activate()
{

}

void DefaultViewPresenter::deactivate()
{

}

void DefaultViewPresenter::update_Clock(int Clock_Value[3])
{
	view.update_Clock(Clock_Value);
}


