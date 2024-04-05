/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/time_settings_screen/Time_SettingsViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

Time_SettingsViewBase::Time_SettingsViewBase() :
    buttonCallback(this, &Time_SettingsViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 240, 320);
    box1.setColor(touchgfx::Color::getColorFromRGB(43, 43, 43));
    add(box1);

    textArea1.setXY(20, 15);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IAKU));
    add(textArea1);

    Menu_Button.setXY(197, 7);
    Menu_Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_PRESSED_ID));
    Menu_Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_JSVE));
    Menu_Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setAction(buttonCallback);
    add(Menu_Button);

    digitalClock1.setPosition(20, 106, 197, 43);
    digitalClock1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    digitalClock1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8O7C));
    digitalClock1.displayLeadingZeroForHourIndicator(true);
    digitalClock1.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock1.setTime24Hour(12, 30, 0);
    add(digitalClock1);

    digitalClock_RealTime.setPosition(20, 53, 197, 43);
    digitalClock_RealTime.setColor(touchgfx::Color::getColorFromRGB(41, 115, 120));
    digitalClock_RealTime.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4AD3));
    digitalClock_RealTime.displayLeadingZeroForHourIndicator(true);
    digitalClock_RealTime.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock_RealTime.setTime24Hour(12, 30, 0);
    add(digitalClock_RealTime);

    Submit_Clock.setXY(65, 261);
    Submit_Clock.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_TINY_ROUNDED_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_TINY_ROUNDED_DISABLED_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    Submit_Clock.setIconXY(30, 0);
    Submit_Clock.setAction(buttonCallback);
    add(Submit_Clock);

    Hours_Val_Up.setXY(29, 160);
    Hours_Val_Up.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_UP_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_UP_50_50_E8F6FB_SVG_ID));
    Hours_Val_Up.setIconXY(-7, -7);
    Hours_Val_Up.setAction(buttonCallback);
    add(Hours_Val_Up);

    Minutes_Val_Up.setXY(107, 160);
    Minutes_Val_Up.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_UP_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    Minutes_Val_Up.setIconXY(-7, -7);
    Minutes_Val_Up.setAction(buttonCallback);
    add(Minutes_Val_Up);

    Hour_Val_Down.setXY(29, 210);
    Hour_Val_Down.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_DOWN_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_DOWN_50_50_E8F6FB_SVG_ID));
    Hour_Val_Down.setIconXY(-7, -7);
    Hour_Val_Down.setAction(buttonCallback);
    add(Hour_Val_Down);

    Minutes_Val_Down.setXY(107, 210);
    Minutes_Val_Down.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_DOWN_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_DOWN_50_50_E8F6FB_SVG_ID));
    Minutes_Val_Down.setIconXY(-7, -7);
    Minutes_Val_Down.setAction(buttonCallback);
    add(Minutes_Val_Down);

    Seconds_Val_Up.setXY(175, 160);
    Seconds_Val_Up.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_UP_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_DONE_50_50_E8F6FB_SVG_ID));
    Seconds_Val_Up.setIconXY(-7, -7);
    Seconds_Val_Up.setAction(buttonCallback);
    add(Seconds_Val_Up);

    Seconds_Val_Down.setXY(175, 210);
    Seconds_Val_Down.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_DOWN_50_50_E8F6FB_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_DOWN_50_50_E8F6FB_SVG_ID));
    Seconds_Val_Down.setIconXY(-7, -7);
    Seconds_Val_Down.setAction(buttonCallback);
    add(Seconds_Val_Down);
}

Time_SettingsViewBase::~Time_SettingsViewBase()
{

}

void Time_SettingsViewBase::setupScreen()
{

}

void Time_SettingsViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Menu_Button)
    {
        //Interaction1
        //When Menu_Button clicked change screen to MenuDropdown_1
        //Go to MenuDropdown_1 with no screen transition
        application().gotoMenuDropdown_1ScreenNoTransition();
    }
    if (&src == &Hours_Val_Up)
    {
        //Hours_Up
        //When Hours_Val_Up clicked call virtual function
        //Call Hours_Up
        Hours_Up();
    }
    if (&src == &Hour_Val_Down)
    {
        //Hours_Down
        //When Hour_Val_Down clicked call virtual function
        //Call Hours_Down
        Hours_Down();
    }
    if (&src == &Minutes_Val_Up)
    {
        //Minutes_Up
        //When Minutes_Val_Up clicked call virtual function
        //Call Minutes_Up
        Minutes_Up();
    }
    if (&src == &Minutes_Val_Down)
    {
        //Minutes_Down
        //When Minutes_Val_Down clicked call virtual function
        //Call Minutes_Down
        Minutes_Down();
    }
    if (&src == &Seconds_Val_Up)
    {
        //Seconds_Up
        //When Seconds_Val_Up clicked call virtual function
        //Call Seconds_Up
        Seconds_Up();
    }
    if (&src == &Seconds_Val_Down)
    {
        //Seconds_Down
        //When Seconds_Val_Down clicked call virtual function
        //Call Seconds_Down
        Seconds_Down();
    }
    if (&src == &Submit_Clock)
    {
        //Set_Current_Time
        //When Submit_Clock clicked call virtual function
        //Call Set_Current_Time
        Set_Current_Time();
    }
}
