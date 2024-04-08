/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/statistics_ambient_1_screen/Statistics_Ambient_1ViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Statistics_Ambient_1ViewBase::Statistics_Ambient_1ViewBase() :
    buttonCallback(this, &Statistics_Ambient_1ViewBase::buttonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backround.setPosition(0, 0, 240, 320);
    backround.setColor(touchgfx::Color::getColorFromRGB(43, 43, 43));
    add(backround);

    Header_backround.setPosition(0, 0, 240, 52);
    Header_backround.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    Header_backround.setAlpha(17);
    add(Header_backround);

    Menu_Button.setXY(197, 7);
    Menu_Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_PRESSED_ID));
    Menu_Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_IBFV));
    Menu_Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setAction(buttonCallback);
    add(Menu_Button);

    Header_Text.setXY(27, 13);
    Header_Text.setColor(touchgfx::Color::getColorFromRGB(153, 153, 153));
    Header_Text.setLinespacing(0);
    Header_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XG0O));
    add(Header_Text);

    Statistics_text.setXY(22, 63);
    Statistics_text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Statistics_text.setLinespacing(0);
    Statistics_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BRAW));
    add(Statistics_text);

    Ambient_sensor_text.setXY(58, 104);
    Ambient_sensor_text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Ambient_sensor_text.setLinespacing(0);
    Ambient_sensor_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VA8A));
    add(Ambient_sensor_text);

    Average_Day_val.setXY(6, 236);
    Average_Day_val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Average_Day_val.setLinespacing(0);
    Average_Day_val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FR08));
    add(Average_Day_val);

    Average_Week_val.setXY(6, 260);
    Average_Week_val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Average_Week_val.setLinespacing(0);
    Average_Week_val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7QC5));
    add(Average_Week_val);

    Average_Month_val.setXY(6, 284);
    Average_Month_val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Average_Month_val.setLinespacing(0);
    Average_Month_val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B4VT));
    add(Average_Month_val);

    Graphic_Ambient_Inside.setPosition(23, 137, 200, 76);
    Graphic_Ambient_Inside.setScale(1);
    Graphic_Ambient_Inside.setGraphAreaMargin(0, 0, 0, 0);
    Graphic_Ambient_Inside.setGraphAreaPadding(0, 0, 0, 0);
    Graphic_Ambient_Inside.setGraphRangeY(0, 100);
    Graphic_Ambient_InsideLine1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Ambient_InsideLine1.setPainter(Graphic_Ambient_InsideLine1Painter);
    Graphic_Ambient_InsideLine1.setLineWidth(2);
    Graphic_Ambient_Inside.addGraphElement(Graphic_Ambient_InsideLine1);


    Graphic_Ambient_Inside.addDataPoint(45.17348f);
    Graphic_Ambient_Inside.addDataPoint(55.6366f);
    Graphic_Ambient_Inside.addDataPoint(61.11546f);
    Graphic_Ambient_Inside.addDataPoint(61.06411f);
    Graphic_Ambient_Inside.addDataPoint(56.40259f);
    Graphic_Ambient_Inside.addDataPoint(49.25543f);
    Graphic_Ambient_Inside.addDataPoint(42.39238f);
    Graphic_Ambient_Inside.addDataPoint(38.50953f);
    Graphic_Ambient_Inside.addDataPoint(39.52877f);
    Graphic_Ambient_Inside.addDataPoint(46.08852f);
    Graphic_Ambient_Inside.addDataPoint(57.35202f);
    Graphic_Ambient_Inside.addDataPoint(71.1815f);
    Graphic_Ambient_Inside.addDataPoint(84.63692f);
    Graphic_Ambient_Inside.addDataPoint(94.67795f);
    Graphic_Ambient_Inside.addDataPoint(98.8983f);
    Graphic_Ambient_Inside.addDataPoint(96.11272f);
    Graphic_Ambient_Inside.addDataPoint(86.65327f);
    Graphic_Ambient_Inside.addDataPoint(72.30199f);
    Graphic_Ambient_Inside.addDataPoint(55.87587f);
    Graphic_Ambient_Inside.addDataPoint(40.56491f);
    Graphic_Ambient_Inside.addDataPoint(29.18428f);
    Graphic_Ambient_Inside.addDataPoint(23.52227f);
    Graphic_Ambient_Inside.addDataPoint(23.94224f);
    Graphic_Ambient_Inside.addDataPoint(29.33445f);
    Graphic_Ambient_Inside.addDataPoint(37.42791f);
    Graphic_Ambient_Inside.addDataPoint(45.38426f);
    Graphic_Ambient_Inside.addDataPoint(50.52693f);
    Graphic_Ambient_Inside.addDataPoint(51.02543f);
    Graphic_Ambient_Inside.addDataPoint(46.36635f);
    Graphic_Ambient_Inside.addDataPoint(37.49462f);
    Graphic_Ambient_Inside.addDataPoint(26.59002f);
    Graphic_Ambient_Inside.addDataPoint(16.53312f);
    Graphic_Ambient_Inside.addDataPoint(10.19167f);
    Graphic_Ambient_Inside.addDataPoint(9.70228f);
    Graphic_Ambient_Inside.addDataPoint(15.92403f);
    Graphic_Ambient_Inside.addDataPoint(28.19867f);
    Graphic_Ambient_Inside.addDataPoint(44.47728f);
    Graphic_Ambient_Inside.addDataPoint(61.78381f);
    Graphic_Ambient_Inside.addDataPoint(76.90346f);
    Graphic_Ambient_Inside.addDataPoint(87.12903f);
    Graphic_Ambient_Inside.addDataPoint(90.88405f);
    Graphic_Ambient_Inside.addDataPoint(88.07185f);
    Graphic_Ambient_Inside.addDataPoint(80.06637f);
    Graphic_Ambient_Inside.addDataPoint(69.34849f);
    Graphic_Ambient_Inside.addDataPoint(58.87784f);
    Graphic_Ambient_Inside.addDataPoint(51.3548f);
    Graphic_Ambient_Inside.addDataPoint(48.55392f);
    Graphic_Ambient_Inside.addDataPoint(50.89211f);
    Graphic_Ambient_Inside.addDataPoint(57.33728f);
    Graphic_Ambient_Inside.addDataPoint(65.67939f);
    Graphic_Ambient_Inside.addDataPoint(73.09672f);
    Graphic_Ambient_Inside.addDataPoint(76.87777f);
    Graphic_Ambient_Inside.addDataPoint(75.12087f);
    Graphic_Ambient_Inside.addDataPoint(67.23867f);
    Graphic_Ambient_Inside.addDataPoint(54.14249f);
    Graphic_Ambient_Inside.addDataPoint(38.05983f);
    Graphic_Ambient_Inside.addDataPoint(22.02799f);
    Graphic_Ambient_Inside.addDataPoint(9.18638f);
    Graphic_Ambient_Inside.addDataPoint(2.03914f);
    Graphic_Ambient_Inside.addDataPoint(1.86762f);
    Graphic_Ambient_Inside.addDataPoint(8.43527f);
    Graphic_Ambient_Inside.addDataPoint(20.05673f);
    Graphic_Ambient_Inside.addDataPoint(34.0135f);
    Graphic_Ambient_Inside.addDataPoint(47.21449f);
    Graphic_Ambient_Inside.addDataPoint(56.93981f);
    Graphic_Ambient_Inside.addDataPoint(61.4863f);
    Graphic_Ambient_Inside.addDataPoint(60.55749f);
    Graphic_Ambient_Inside.addDataPoint(55.3036f);
    Graphic_Ambient_Inside.addDataPoint(48.00318f);
    Graphic_Ambient_Inside.addDataPoint(41.46565f);
    Graphic_Ambient_Inside.addDataPoint(38.30273f);
    Graphic_Ambient_Inside.addDataPoint(40.24868f);
    Graphic_Ambient_Inside.addDataPoint(47.69744f);
    Graphic_Ambient_Inside.addDataPoint(59.57146f);
    Graphic_Ambient_Inside.addDataPoint(73.5558f);
    Graphic_Ambient_Inside.addDataPoint(86.64126f);
    Graphic_Ambient_Inside.addDataPoint(95.84465f);
    Graphic_Ambient_Inside.addDataPoint(98.93036f);
    Graphic_Ambient_Inside.addDataPoint(94.95701f);
    Graphic_Ambient_Inside.addDataPoint(84.51535f);
    Graphic_Ambient_Inside.addDataPoint(69.59885f);
    Graphic_Ambient_Inside.addDataPoint(53.13807f);
    Graphic_Ambient_Inside.addDataPoint(38.31196f);
    Graphic_Ambient_Inside.addDataPoint(27.80341f);
    Graphic_Ambient_Inside.addDataPoint(23.18019f);
    Graphic_Ambient_Inside.addDataPoint(24.55117f);
    Graphic_Ambient_Inside.addDataPoint(30.58044f);
    Graphic_Ambient_Inside.addDataPoint(38.85427f);
    Graphic_Ambient_Inside.addDataPoint(46.50943f);
    Graphic_Ambient_Inside.addDataPoint(50.96765f);
    Graphic_Ambient_Inside.addDataPoint(50.59489f);
    Graphic_Ambient_Inside.addDataPoint(45.12304f);
    Graphic_Ambient_Inside.addDataPoint(35.72993f);
    Graphic_Ambient_Inside.addDataPoint(24.75735f);
    Graphic_Ambient_Inside.addDataPoint(15.13609f);
    Graphic_Ambient_Inside.addDataPoint(9.65858f);
    Graphic_Ambient_Inside.addDataPoint(10.27783f);
    Graphic_Ambient_Inside.addDataPoint(17.60484f);
    Graphic_Ambient_Inside.addDataPoint(30.72865f);
    Graphic_Ambient_Inside.addDataPoint(47.4041f);
    add(Graphic_Ambient_Inside);
}

Statistics_Ambient_1ViewBase::~Statistics_Ambient_1ViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void Statistics_Ambient_1ViewBase::setupScreen()
{

}

void Statistics_Ambient_1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Menu_Button)
    {
        //MenuDropdown
        //When Menu_Button clicked change screen to MenuDropdown_1
        //Go to MenuDropdown_1 with no screen transition
        application().gotoMenuDropdown_1ScreenNoTransition();
    }
}
