/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/statistics_temperature_outside_screen/Statistics_Temperature_OutsideViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Statistics_Temperature_OutsideViewBase::Statistics_Temperature_OutsideViewBase() :
    buttonCallback(this, &Statistics_Temperature_OutsideViewBase::buttonCallbackHandler)
{
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
    Menu_Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_PXJX));
    Menu_Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setAction(buttonCallback);
    add(Menu_Button);

    Header_Text.setXY(27, 13);
    Header_Text.setColor(touchgfx::Color::getColorFromRGB(153, 153, 153));
    Header_Text.setLinespacing(0);
    Header_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PIO1));
    add(Header_Text);

    Temperature_sensor_outside_text.setXY(9, 61);
    Temperature_sensor_outside_text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Temperature_sensor_outside_text.setLinespacing(0);
    Temperature_sensor_outside_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XZWT));
    add(Temperature_sensor_outside_text);

    Average_Day_val.setXY(6, 236);
    Average_Day_val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Average_Day_val.setLinespacing(0);
    Average_Day_val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9E53));
    add(Average_Day_val);

    Average_Week_val.setXY(6, 260);
    Average_Week_val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Average_Week_val.setLinespacing(0);
    Average_Week_val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GLAO));
    add(Average_Week_val);

    Average_Month_val.setXY(6, 284);
    Average_Month_val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Average_Month_val.setLinespacing(0);
    Average_Month_val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8J5E));
    add(Average_Month_val);

    Graphic_Temperature_Outside.setPosition(0, 94, 238, 132);
    Graphic_Temperature_Outside.setScaleX(1);
    Graphic_Temperature_Outside.setScaleY(1);
    Graphic_Temperature_Outside.setGraphAreaMargin(0, 15, 0, 16);
    Graphic_Temperature_Outside.setGraphAreaPadding(0, 9, 12, 2);
    Graphic_Temperature_Outside.setGraphRangeX(0, 24);
    Graphic_Temperature_Outside.setGraphRangeY(0, 45);
    Graphic_Temperature_OutsideMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_OutsideMajorYAxisGrid.setInterval(4);
    Graphic_Temperature_OutsideMajorYAxisGrid.setLineWidth(1);
    Graphic_Temperature_OutsideMajorYAxisGrid.setScale(1);
    Graphic_Temperature_Outside.addGraphElement(Graphic_Temperature_OutsideMajorYAxisGrid);

    Graphic_Temperature_OutsideMajorXAxisLabel.setInterval(3);
    Graphic_Temperature_OutsideMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_3GTH));
    Graphic_Temperature_OutsideMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_OutsideMajorXAxisLabel.setScale(1);
    Graphic_Temperature_Outside.addBottomElement(Graphic_Temperature_OutsideMajorXAxisLabel);

    Graphic_Temperature_OutsideMajorYAxisLabel.setInterval(10);
    Graphic_Temperature_OutsideMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_O4FJ));
    Graphic_Temperature_OutsideMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_OutsideMajorYAxisLabel.setScale(1);
    Graphic_Temperature_Outside.addLeftElement(Graphic_Temperature_OutsideMajorYAxisLabel);

    Graphic_Temperature_OutsideHistogram1.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_OutsideHistogram1.setBarWidth(4);
    Graphic_Temperature_OutsideHistogram1.setBaseline(0);
    Graphic_Temperature_Outside.addGraphElement(Graphic_Temperature_OutsideHistogram1);


    add(Graphic_Temperature_Outside);

    Brightness_level.setPosition(0, 0, 240, 320);
    Brightness_level.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Brightness_level.setAlpha(0);
    add(Brightness_level);
}

Statistics_Temperature_OutsideViewBase::~Statistics_Temperature_OutsideViewBase()
{

}

void Statistics_Temperature_OutsideViewBase::setupScreen()
{

}

void Statistics_Temperature_OutsideViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Menu_Button)
    {
        //MenuDropdown
        //When Menu_Button clicked change screen to STATISTICS
        //Go to STATISTICS with no screen transition
        application().gotoSTATISTICSScreenNoTransition();
    }
}
