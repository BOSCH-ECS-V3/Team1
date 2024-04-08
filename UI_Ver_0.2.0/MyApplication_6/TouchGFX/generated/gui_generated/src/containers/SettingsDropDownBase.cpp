/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/SettingsDropDownBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SettingsDropDownBase::SettingsDropDownBase() :
    buttonCallback(this, &SettingsDropDownBase::buttonCallbackHandler)
{
    setWidth(245);
    setHeight(430);
    box1.setPosition(-3, 0, 248, 434);
    box1.setColor(touchgfx::Color::getColorFromRGB(43, 43, 43));
    add(box1);

    Home.setXY(50, 11);
    Home.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_ACTIVE_ID));
    Home.setLabelText(touchgfx::TypedText(T___SINGLEUSE_BWPU));
    Home.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Home.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Home.setAction(buttonCallback);
    add(Home);

    Alarm.setXY(50, 93);
    Alarm.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_ACTIVE_ID));
    Alarm.setLabelText(touchgfx::TypedText(T___SINGLEUSE_YUNA));
    Alarm.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Alarm.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(Alarm);

    DateSettings.setXY(49, 266);
    DateSettings.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_ACTIVE_ID));
    DateSettings.setLabelText(touchgfx::TypedText(T___SINGLEUSE_86OG));
    DateSettings.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    DateSettings.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    DateSettings.setAction(buttonCallback);
    add(DateSettings);

    TimeSettings.setXY(49, 185);
    TimeSettings.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_ACTIVE_ID));
    TimeSettings.setLabelText(touchgfx::TypedText(T___SINGLEUSE_FTBM));
    TimeSettings.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    TimeSettings.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    TimeSettings.setAction(buttonCallback);
    add(TimeSettings);

    About.setXY(49, 353);
    About.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUND_ACTIVE_ID));
    About.setLabelText(touchgfx::TypedText(T___SINGLEUSE_OC5C));
    About.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    About.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    About.setAction(buttonCallback);
    add(About);
}

SettingsDropDownBase::~SettingsDropDownBase()
{

}

void SettingsDropDownBase::initialize()
{

}

void SettingsDropDownBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Home)
    {
        //HomePageNav
        //When Home clicked change screen to DefaultView
        //Go to DefaultView with no screen transition
        application().gotoDefaultViewScreenNoTransition();
    }
    if (&src == &About)
    {
        //About
        //When About clicked change screen to About
        //Go to About with no screen transition
        application().gotoAboutScreenNoTransition();
    }
    if (&src == &TimeSettings)
    {
        //ClockPageNav
        //When TimeSettings clicked change screen to Time_Settings
        //Go to Time_Settings with no screen transition
        application().gotoTime_SettingsScreenNoTransition();
    }
    if (&src == &DateSettings)
    {
        //DatePageNav
        //When DateSettings clicked change screen to Date_Settings
        //Go to Date_Settings with no screen transition
        application().gotoDate_SettingsScreenNoTransition();
    }
}
