/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STATISTICS_GAS_SENSORVIEWBASE_HPP
#define STATISTICS_GAS_SENSORVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/graph/Graph.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>

class Statistics_Gas_sensorViewBase : public touchgfx::View<Statistics_Gas_sensorPresenter>
{
public:
    Statistics_Gas_sensorViewBase();
    virtual ~Statistics_Gas_sensorViewBase();
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
    touchgfx::TextArea Gas_sensor_text;
    touchgfx::TextArea Average_Day_val;
    touchgfx::TextArea Average_Week_val;
    touchgfx::TextArea Average_Month_val;
    touchgfx::Graph<24> Graphic_Gas_sensor;
    touchgfx::GraphElementGridY Graphic_Gas_sensorMajorYAxisGrid;
    touchgfx::GraphLabelsX Graphic_Gas_sensorMajorXAxisLabel;
    touchgfx::GraphLabelsY Graphic_Gas_sensorMajorYAxisLabel;
    touchgfx::GraphElementHistogram Graphic_Gas_sensorHistogram1;
    touchgfx::Box Brightness_level;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Statistics_Gas_sensorViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // STATISTICS_GAS_SENSORVIEWBASE_HPP
