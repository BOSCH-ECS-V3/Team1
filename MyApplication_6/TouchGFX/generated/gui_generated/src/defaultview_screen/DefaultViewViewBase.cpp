/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/defaultview_screen/DefaultViewViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DefaultViewViewBase::DefaultViewViewBase() :
    buttonCallback(this, &DefaultViewViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    Backround.setPosition(0, 0, 240, 320);
    Backround.setColor(touchgfx::Color::getColorFromRGB(43, 43, 43));
    add(Backround);

    Menu_Button.setXY(197, 7);
    Menu_Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_PRESSED_ID));
    Menu_Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_68EU));
    Menu_Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Menu_Button.setAction(buttonCallback);
    add(Menu_Button);

    textArea1.setXY(27, 13);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(153, 153, 153));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6NB9));
    add(textArea1);

    SwipeContainer.setXY(0, 31);
    SwipeContainer.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SWIPECONTAINER_SMALL_OFF_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SWIPECONTAINER_SMALL_ON_NORMAL_ID));
    SwipeContainer.setPageIndicatorXY(84, 240);
    SwipeContainer.setSwipeCutoff(50);
    SwipeContainer.setEndSwipeElasticWidth(50);

    SwipeContainerHumidity.setWidth(240);
    SwipeContainerHumidity.setHeight(261);
    Humidity_Text.setXY(76, 30);
    Humidity_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Humidity_Text.setLinespacing(0);
    Humidity_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SC46));
    SwipeContainerHumidity.add(Humidity_Text);

    Humidity_Val.setXY(81, 109);
    Humidity_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Humidity_Val.setLinespacing(0);
    Unicode::snprintf(Humidity_ValBuffer, HUMIDITY_VAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_TRUT).getText());
    Humidity_Val.setWildcard(Humidity_ValBuffer);
    Humidity_Val.resizeToCurrentText();
    Humidity_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ED8P));
    SwipeContainerHumidity.add(Humidity_Val);

    SwipeContainer.add(SwipeContainerHumidity);

    SwipeContainerCarbon.setWidth(240);
    SwipeContainerCarbon.setHeight(261);
    Carbon_Text.setXY(32, 26);
    Carbon_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Carbon_Text.setLinespacing(0);
    Carbon_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XRTI));
    SwipeContainerCarbon.add(Carbon_Text);

    Carbon_Val.setXY(42, 109);
    Carbon_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Carbon_Val.setLinespacing(0);
    Unicode::snprintf(Carbon_ValBuffer, CARBON_VAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_9KGC).getText());
    Carbon_Val.setWildcard(Carbon_ValBuffer);
    Carbon_Val.resizeToCurrentText();
    Carbon_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GP4Z));
    SwipeContainerCarbon.add(Carbon_Val);

    Preheat_msg.setPosition(0, 6, 250, 250);
    Preheat_box.setPosition(20, 103, 202, 48);
    Preheat_box.setColor(touchgfx::Color::getColorFromRGB(0, 59, 64));
    Preheat_msg.add(Preheat_box);

    Preheat_text.setXY(67, 115);
    Preheat_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Preheat_text.setLinespacing(0);
    Preheat_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FDI4));
    Preheat_msg.add(Preheat_text);

    SwipeContainerCarbon.add(Preheat_msg);

    SwipeContainer.add(SwipeContainerCarbon);

    SwipeContainerPressure_1.setWidth(240);
    SwipeContainerPressure_1.setHeight(261);
    Presure_Text.setXY(55, 30);
    Presure_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Presure_Text.setLinespacing(0);
    Presure_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QJ73));
    SwipeContainerPressure_1.add(Presure_Text);

    Presure_Val.setXY(83, 109);
    Presure_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Presure_Val.setLinespacing(0);
    Unicode::snprintf(Presure_ValBuffer, PRESURE_VAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JVDX).getText());
    Presure_Val.setWildcard(Presure_ValBuffer);
    Presure_Val.resizeToCurrentText();
    Presure_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MJ6R));
    SwipeContainerPressure_1.add(Presure_Val);

    SwipeContainer.add(SwipeContainerPressure_1);

    SwipeContainerAmbient_1.setWidth(240);
    SwipeContainerAmbient_1.setHeight(261);
    Ambient_Text.setXY(55, 30);
    Ambient_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Ambient_Text.setLinespacing(0);
    Ambient_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VIA7));
    SwipeContainerAmbient_1.add(Ambient_Text);

    Ambient_Val.setXY(81, 109);
    Ambient_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Ambient_Val.setLinespacing(0);
    Unicode::snprintf(Ambient_ValBuffer, AMBIENT_VAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_VYLX).getText());
    Ambient_Val.setWildcard(Ambient_ValBuffer);
    Ambient_Val.resizeToCurrentText();
    Ambient_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9KQX));
    SwipeContainerAmbient_1.add(Ambient_Val);

    SwipeContainer.add(SwipeContainerAmbient_1);

    SwipeContainerTemperature_Inside.setWidth(240);
    SwipeContainerTemperature_Inside.setHeight(261);
    TempIn_Val.setXY(81, 109);
    TempIn_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    TempIn_Val.setLinespacing(0);
    Unicode::snprintf(TempIn_ValBuffer, TEMPIN_VAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_E5QY).getText());
    TempIn_Val.setWildcard(TempIn_ValBuffer);
    TempIn_Val.resizeToCurrentText();
    TempIn_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BF3J));
    SwipeContainerTemperature_Inside.add(TempIn_Val);

    TempIn_Text.setXY(55, 30);
    TempIn_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    TempIn_Text.setLinespacing(0);
    TempIn_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NIUA));
    SwipeContainerTemperature_Inside.add(TempIn_Text);

    SwipeContainer.add(SwipeContainerTemperature_Inside);

    SwipeContainerTemperature_Outside.setWidth(240);
    SwipeContainerTemperature_Outside.setHeight(261);
    TempOut_Val.setXY(81, 109);
    TempOut_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    TempOut_Val.setLinespacing(0);
    Unicode::snprintf(TempOut_ValBuffer, TEMPOUT_VAL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IV5N).getText());
    TempOut_Val.setWildcard(TempOut_ValBuffer);
    TempOut_Val.resizeToCurrentText();
    TempOut_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7E1H));
    SwipeContainerTemperature_Outside.add(TempOut_Val);

    TempOut_Text.setXY(55, 30);
    TempOut_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    TempOut_Text.setLinespacing(0);
    TempOut_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZFWW));
    SwipeContainerTemperature_Outside.add(TempOut_Text);

    SwipeContainer.add(SwipeContainerTemperature_Outside);

    SwipeContainer.setSelectedPage(1);
    add(SwipeContainer);

    digitalClock1.setPosition(9, 292, 98, 28);
    digitalClock1.setColor(touchgfx::Color::getColorFromRGB(0, 234, 255));
    digitalClock1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UQLB));
    digitalClock1.displayLeadingZeroForHourIndicator(true);
    digitalClock1.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock1.setTime24Hour(10, 10, 0);
    digitalClock1.setVisible(false);
    add(digitalClock1);

    Header.setPosition(0, 0, 240, 52);
    Header.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    Header.setAlpha(17);
    add(Header);

    Footer.setPosition(-1, 292, 241, 32);
    Footer.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    Footer.setAlpha(17);
    add(Footer);

    Alert_cover.setPosition(0, 0, 250, 320);
    Alert_cover.setVisible(false);
    Backround_1.setPosition(0, 0, 240, 320);
    Backround_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Backround_1.setAlpha(150);
    Alert_cover.add(Backround_1);

    Error_msg_backround.setPosition(14, 164, 215, 63);
    Error_msg_backround.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Error_msg_backround.setAlpha(150);
    Alert_cover.add(Error_msg_backround);

    Error.setXY(84, 70);
    Error.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ALERT_ERROR_70_70_FF0000_SVG_ID));
    Alert_cover.add(Error);

    Error_code.setXY(47, 40);
    Error_code.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    Error_code.setLinespacing(0);
    Unicode::snprintf(Error_codeBuffer, ERROR_CODE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_MEFF).getText());
    Error_code.setWildcard(Error_codeBuffer);
    Error_code.resizeToCurrentText();
    Error_code.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HAUQ));
    Alert_cover.add(Error_code);

    Snooze_button.setXY(71, 253);
    Snooze_button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUND_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUND_PRESSED_ID));
    Snooze_button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_TTSL));
    Snooze_button.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Snooze_button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Snooze_button.setAction(buttonCallback);
    Alert_cover.add(Snooze_button);

    Error_text.setXY(21, 169);
    Error_text.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    Error_text.setLinespacing(0);
    Unicode::snprintf(Error_textBuffer, ERROR_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_VN7N).getText());
    Error_text.setWildcard(Error_textBuffer);
    Error_text.resizeToCurrentText();
    Error_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_595W));
    Alert_cover.add(Error_text);

    add(Alert_cover);

    Brightness_level.setPosition(-20, -12, 282, 345);
    Brightness_level.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    Brightness_level.setAlpha(101);
    add(Brightness_level);
}

DefaultViewViewBase::~DefaultViewViewBase()
{

}

void DefaultViewViewBase::setupScreen()
{

}

void DefaultViewViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &Menu_Button)
    {
        //DropDownFunc
        //When Menu_Button clicked change screen to MenuDropdown_1
        //Go to MenuDropdown_1 with no screen transition
        application().gotoMenuDropdown_1ScreenNoTransition();
    }
    if (&src == &Snooze_button)
    {
        //Alert_cover_hide
        //When Snooze_button clicked hide Alert_cover
        //Hide Alert_cover
        Alert_cover.setVisible(false);
        Alert_cover.invalidate();
        //Snooze_btn_pressed
        //When Snooze_button clicked call virtual function
        //Call Snooze_btn_pressed
        Snooze_btn_pressed();
    }
}

void DefaultViewViewBase::handleTickEvent()
{
    //Interaction1
    //When every N tick call virtual function
    //Call function1
    function1();
}
