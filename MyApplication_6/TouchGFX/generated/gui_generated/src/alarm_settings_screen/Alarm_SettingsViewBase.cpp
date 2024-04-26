/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/alarm_settings_screen/Alarm_SettingsViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Alarm_SettingsViewBase::Alarm_SettingsViewBase() :
    buttonCallback(this, &Alarm_SettingsViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backround.setPosition(0, 0, 240, 320);
    backround.setColor(touchgfx::Color::getColorFromRGB(43, 43, 43));
    add(backround);

    Footer.setPosition(-1, 292, 241, 32);
    Footer.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    Footer.setAlpha(17);
    add(Footer);

    Header_backround.setPosition(0, 0, 240, 52);
    Header_backround.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    Header_backround.setAlpha(17);
    add(Header_backround);

    Menu_Button.setXY(197, 7);
    Menu_Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_PRESSED_ID));
    Menu_Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_BMQY));
    Menu_Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setAction(buttonCallback);
    add(Menu_Button);

    Header_Text.setXY(27, 13);
    Header_Text.setColor(touchgfx::Color::getColorFromRGB(153, 153, 153));
    Header_Text.setLinespacing(0);
    Header_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XGA9));
    add(Header_Text);

    System_Allarm_Text.setXY(29, 65);
    System_Allarm_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    System_Allarm_Text.setLinespacing(0);
    System_Allarm_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CAKJ));
    add(System_Allarm_Text);

    Alarm_confirmation_text.setXY(16, 212);
    Alarm_confirmation_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Alarm_confirmation_text.setLinespacing(0);
    Alarm_confirmation_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J7M8));
    add(Alarm_confirmation_text);

    Permission_ON.setXY(127, 100);
    Permission_ON.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_TINY_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_TINY_OUTLINE_PRESSED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    Permission_ON.setIconXY(5, 5);
    Permission_ON.setAction(buttonCallback);
    add(Permission_ON);

    Permission_OFF.setXY(47, 100);
    Permission_OFF.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_TINY_OUTLINE_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_TINY_OUTLINE_PRESSED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_CLEAR_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    Permission_OFF.setIconXY(5, 5);
    Permission_OFF.setAction(buttonCallback);
    add(Permission_OFF);

    box1.setPosition(67, 178, 90, 25);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    add(box1);

    textArea1.setXY(97, 179);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1307).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.resizeToCurrentText();
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_X4VI));
    add(textArea1);

    Brightness_level.setPosition(-1, 0, 240, 320);
    Brightness_level.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Brightness_level.setAlpha(0);
    add(Brightness_level);
}

Alarm_SettingsViewBase::~Alarm_SettingsViewBase()
{

}

void Alarm_SettingsViewBase::setupScreen()
{

}

void Alarm_SettingsViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Menu_Button)
    {
        //MenuNav
        //When Menu_Button clicked change screen to MenuDropdown_1
        //Go to MenuDropdown_1 with no screen transition
        application().gotoMenuDropdown_1ScreenNoTransition();
    }
    if (&src == &Permission_ON)
    {
        //btn_Permission_ON
        //When Permission_ON clicked call virtual function
        //Call btn_Permission_ON
        btn_Permission_ON();
    }
    if (&src == &Permission_OFF)
    {
        //btn_Permission_OFF
        //When Permission_OFF clicked call virtual function
        //Call btn_Permission_OFF
        btn_Permission_OFF();
    }
}
