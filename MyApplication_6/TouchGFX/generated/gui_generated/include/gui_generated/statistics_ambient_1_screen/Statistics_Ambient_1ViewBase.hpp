/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STATISTICS_AMBIENT_1VIEWBASE_HPP
#define STATISTICS_AMBIENT_1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/graph/Graph.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>

class Statistics_Ambient_1ViewBase : public touchgfx::View<Statistics_Ambient_1Presenter>
{
public:
    Statistics_Ambient_1ViewBase();
    virtual ~Statistics_Ambient_1ViewBase();
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
    touchgfx::TextArea Ambient_sensor_text;
    touchgfx::Graph<24> Graphic_Ambient_Inside;
    touchgfx::GraphElementGridY Graphic_Ambient_InsideMajorYAxisGrid;
    touchgfx::GraphLabelsX Graphic_Ambient_InsideMajorXAxisLabel;
    touchgfx::GraphLabelsY Graphic_Ambient_InsideMajorYAxisLabel;
    touchgfx::GraphElementHistogram Graphic_Ambient_InsideHistogram1;
    touchgfx::Box Brightness_level;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Statistics_Ambient_1ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // STATISTICS_AMBIENT_1VIEWBASE_HPP
