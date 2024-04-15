/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STATISTICS_TEMPERATURE_OUTSIDEVIEWBASE_HPP
#define STATISTICS_TEMPERATURE_OUTSIDEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsidePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>

class Statistics_Temperature_OutsideViewBase : public touchgfx::View<Statistics_Temperature_OutsidePresenter>
{
public:
    Statistics_Temperature_OutsideViewBase();
    virtual ~Statistics_Temperature_OutsideViewBase();
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
    touchgfx::TextArea Temperature_sensor_outside_text;
    touchgfx::TextArea Average_Day_val;
    touchgfx::TextArea Average_Week_val;
    touchgfx::TextArea Average_Month_val;
    touchgfx::GraphWrapAndClear<24> Graphic_Temperature_Outside;
    touchgfx::GraphElementGridY Graphic_Temperature_OutsideMajorYAxisGrid;
    touchgfx::GraphLabelsX Graphic_Temperature_OutsideMinorXAxisLabel;
    touchgfx::GraphLabelsY Graphic_Temperature_OutsideMinorYAxisLabel;
    touchgfx::GraphLabelsX Graphic_Temperature_OutsideMajorXAxisLabel;
    touchgfx::GraphLabelsY Graphic_Temperature_OutsideMajorYAxisLabel;
    touchgfx::GraphElementHistogram Graphic_Temperature_OutsideHistogram1;
    touchgfx::Box Brightness_level;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Statistics_Temperature_OutsideViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // STATISTICS_TEMPERATURE_OUTSIDEVIEWBASE_HPP
