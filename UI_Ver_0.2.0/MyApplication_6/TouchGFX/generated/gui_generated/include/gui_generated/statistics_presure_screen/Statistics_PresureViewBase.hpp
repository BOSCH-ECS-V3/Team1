/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STATISTICS_PRESUREVIEWBASE_HPP
#define STATISTICS_PRESUREVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/statistics_presure_screen/Statistics_PresurePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class Statistics_PresureViewBase : public touchgfx::View<Statistics_PresurePresenter>
{
public:
    Statistics_PresureViewBase();
    virtual ~Statistics_PresureViewBase();
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
    touchgfx::TextArea Statistics_text;
    touchgfx::TextArea Presure_sensor_text;
    touchgfx::TextArea Average_Day_val;
    touchgfx::TextArea Average_Week_val;
    touchgfx::TextArea Average_Month_val;
    touchgfx::GraphWrapAndClear<100> Graphic_Presure_Inside;
    touchgfx::GraphElementLine Graphic_Presure_InsideLine1;
    touchgfx::PainterRGB565 Graphic_Presure_InsideLine1Painter;

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 3600;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Statistics_PresureViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // STATISTICS_PRESUREVIEWBASE_HPP
