/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef AVERAGE_AMBIENTLIGHTVIEWBASE_HPP
#define AVERAGE_AMBIENTLIGHTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/average_ambientlight_screen/Average_AmbientLightPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Average_AmbientLightViewBase : public touchgfx::View<Average_AmbientLightPresenter>
{
public:
    Average_AmbientLightViewBase();
    virtual ~Average_AmbientLightViewBase();
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
    touchgfx::TextAreaWithOneWildcard Average_day_val;
    touchgfx::TextAreaWithOneWildcard Average_week_val;
    touchgfx::TextAreaWithOneWildcard Average_month_val;
    touchgfx::TextArea Average_day_text;
    touchgfx::TextArea Average_week_text;
    touchgfx::TextArea Average_month_text;

    /*
     * Wildcard Buffers
     */
    static const uint16_t AVERAGE_DAY_VAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar Average_day_valBuffer[AVERAGE_DAY_VAL_SIZE];
    static const uint16_t AVERAGE_WEEK_VAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar Average_week_valBuffer[AVERAGE_WEEK_VAL_SIZE];
    static const uint16_t AVERAGE_MONTH_VAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar Average_month_valBuffer[AVERAGE_MONTH_VAL_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Average_AmbientLightViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // AVERAGE_AMBIENTLIGHTVIEWBASE_HPP
