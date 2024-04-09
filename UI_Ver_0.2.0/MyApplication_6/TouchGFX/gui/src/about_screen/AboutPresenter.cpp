#include <gui/about_screen/AboutView.hpp>
#include <gui/about_screen/AboutPresenter.hpp>

AboutPresenter::AboutPresenter(AboutView& v)
    : view(v)
{

}

void AboutPresenter::activate()
{

}

void AboutPresenter::deactivate()
{

}

void AboutPresenter::set_brightness_level(int brightness)
{
	view.set_brightness_level(brightness);
}
