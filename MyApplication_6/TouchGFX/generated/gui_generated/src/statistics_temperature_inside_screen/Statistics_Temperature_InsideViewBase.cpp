/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/statistics_temperature_inside_screen/Statistics_Temperature_InsideViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Statistics_Temperature_InsideViewBase::Statistics_Temperature_InsideViewBase() :
    buttonCallback(this, &Statistics_Temperature_InsideViewBase::buttonCallbackHandler)
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
    Menu_Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_UUWM));
    Menu_Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setAction(buttonCallback);
    add(Menu_Button);

    Header_Text.setXY(27, 13);
    Header_Text.setColor(touchgfx::Color::getColorFromRGB(153, 153, 153));
    Header_Text.setLinespacing(0);
    Header_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_26T7));
    add(Header_Text);

    Temperature_sensor_text.setXY(16, 67);
    Temperature_sensor_text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Temperature_sensor_text.setLinespacing(0);
    Temperature_sensor_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YSM9));
    add(Temperature_sensor_text);

    Graphic_Temperature_Inside.setPosition(1, 106, 239, 180);
    Graphic_Temperature_Inside.setScaleX(1);
    Graphic_Temperature_Inside.setScaleY(1);
    Graphic_Temperature_Inside.setGraphAreaMargin(0, 15, 0, 16);
    Graphic_Temperature_Inside.setGraphAreaPadding(0, 9, 12, 2);
    Graphic_Temperature_Inside.setGraphRangeX(0, 24);
    Graphic_Temperature_Inside.setGraphRangeY(0, 45);
    Graphic_Temperature_InsideMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_InsideMajorYAxisGrid.setInterval(4);
    Graphic_Temperature_InsideMajorYAxisGrid.setLineWidth(1);
    Graphic_Temperature_InsideMajorYAxisGrid.setScale(1);
    Graphic_Temperature_Inside.addGraphElement(Graphic_Temperature_InsideMajorYAxisGrid);

    Graphic_Temperature_InsideMajorXAxisLabel.setInterval(3);
    Graphic_Temperature_InsideMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_M8Z7));
    Graphic_Temperature_InsideMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_InsideMajorXAxisLabel.setScale(1);
    Graphic_Temperature_Inside.addBottomElement(Graphic_Temperature_InsideMajorXAxisLabel);

    Graphic_Temperature_InsideMajorYAxisLabel.setInterval(10);
    Graphic_Temperature_InsideMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_XT9W));
    Graphic_Temperature_InsideMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_InsideMajorYAxisLabel.setScale(1);
    Graphic_Temperature_Inside.addLeftElement(Graphic_Temperature_InsideMajorYAxisLabel);

    Graphic_Temperature_InsideHistogram1.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    Graphic_Temperature_InsideHistogram1.setBarWidth(4);
    Graphic_Temperature_InsideHistogram1.setBaseline(0);
    Graphic_Temperature_Inside.addGraphElement(Graphic_Temperature_InsideHistogram1);


    add(Graphic_Temperature_Inside);

    Brightness_level.setPosition(0, 0, 240, 320);
    Brightness_level.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Brightness_level.setAlpha(0);
    add(Brightness_level);
}

Statistics_Temperature_InsideViewBase::~Statistics_Temperature_InsideViewBase()
{

}

void Statistics_Temperature_InsideViewBase::setupScreen()
{

}

void Statistics_Temperature_InsideViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Menu_Button)
    {
        //MenuDropdown
        //When Menu_Button clicked change screen to STATISTICS
        //Go to STATISTICS with no screen transition
        application().gotoSTATISTICSScreenNoTransition();
    }
}
