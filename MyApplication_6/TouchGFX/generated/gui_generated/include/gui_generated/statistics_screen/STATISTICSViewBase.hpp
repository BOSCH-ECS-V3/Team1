/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STATISTICSVIEWBASE_HPP
#define STATISTICSVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/statistics_screen/STATISTICSPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class STATISTICSViewBase : public touchgfx::View<STATISTICSPresenter>
{
public:
    STATISTICSViewBase();
    virtual ~STATISTICSViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box backround;
    touchgfx::Box Header_backround;
    touchgfx::ButtonWithLabel Menu_Button;
    touchgfx::TextArea Header_Text;
    touchgfx::TextArea Header_Text_1;
    touchgfx::ButtonWithLabel Temperature_INSIDE;
    touchgfx::ButtonWithLabel Temperature_OUTSIDE;
    touchgfx::ButtonWithLabel Humidity;
    touchgfx::ButtonWithLabel Ambient_light;
    touchgfx::ButtonWithLabel Gas_sensor;
    touchgfx::ButtonWithLabel Pressure;
    touchgfx::Box Brightness_level;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<STATISTICSViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // STATISTICSVIEWBASE_HPP
