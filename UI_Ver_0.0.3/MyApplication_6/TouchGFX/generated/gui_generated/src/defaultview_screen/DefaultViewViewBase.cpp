/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/defaultview_screen/DefaultViewViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DefaultViewViewBase::DefaultViewViewBase() :
    buttonCallback(this, &DefaultViewViewBase::buttonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 240, 320);
    box1.setColor(touchgfx::Color::getColorFromRGB(43, 43, 43));
    add(box1);

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
    SwipeContainer.setPageIndicatorXY(90, 240);
    SwipeContainer.setSwipeCutoff(50);
    SwipeContainer.setEndSwipeElasticWidth(50);

    SwipeContainerCarbon.setWidth(240);
    SwipeContainerCarbon.setHeight(261);
    Carbon_Text.setXY(32, 26);
    Carbon_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Carbon_Text.setLinespacing(0);
    Carbon_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XRTI));
    SwipeContainerCarbon.add(Carbon_Text);

    Carbon_Val.setXY(91, 64);
    Carbon_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Carbon_Val.setLinespacing(0);
    Carbon_ValBuffer[0] = 0;
    Carbon_Val.setWildcard(Carbon_ValBuffer);
    Carbon_Val.resizeToCurrentText();
    Carbon_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GP4Z));
    SwipeContainerCarbon.add(Carbon_Val);

    CarbonCirc_Val.setXY(65, 107);
    CarbonCirc_Val.setProgressIndicatorPosition(0, 0, 110, 110);
    CarbonCirc_Val.setRange(0, 100);
    CarbonCirc_Val.setCenter(55, 55);
    CarbonCirc_Val.setRadius(50);
    CarbonCirc_Val.setLineWidth(10);
    CarbonCirc_Val.setStartEndAngle(0, 180);
    CarbonCirc_Val.setCapPrecision(180);
    CarbonCirc_Val.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_CIRCLEPROGRESS_BACKGROUNDS_SMALL_ID));
    CarbonCirc_ValPainter.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    CarbonCirc_Val.setPainter(CarbonCirc_ValPainter);
    CarbonCirc_Val.setValue(60);
    SwipeContainerCarbon.add(CarbonCirc_Val);

    SwipeContainer.add(SwipeContainerCarbon);

    SwipeContainerPressure_1.setWidth(240);
    SwipeContainerPressure_1.setHeight(261);
    Presure_Text_1.setXY(76, 23);
    Presure_Text_1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Presure_Text_1.setLinespacing(0);
    Presure_Text_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q09J));
    SwipeContainerPressure_1.add(Presure_Text_1);

    Presure_Val_1.setXY(91, 60);
    Presure_Val_1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Presure_Val_1.setLinespacing(0);
    Presure_Val_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NW7Q));
    SwipeContainerPressure_1.add(Presure_Val_1);

    PresureCirc_Val_1.setXY(65, 107);
    PresureCirc_Val_1.setProgressIndicatorPosition(0, 0, 110, 110);
    PresureCirc_Val_1.setRange(0, 100);
    PresureCirc_Val_1.setCenter(55, 55);
    PresureCirc_Val_1.setRadius(50);
    PresureCirc_Val_1.setLineWidth(10);
    PresureCirc_Val_1.setStartEndAngle(0, 360);
    PresureCirc_Val_1.setCapPrecision(180);
    PresureCirc_Val_1.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_CIRCLEPROGRESS_BACKGROUNDS_SMALL_ID));
    PresureCirc_Val_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    PresureCirc_Val_1.setPainter(PresureCirc_Val_1Painter);
    PresureCirc_Val_1.setValue(60);
    SwipeContainerPressure_1.add(PresureCirc_Val_1);

    SwipeContainer.add(SwipeContainerPressure_1);

    SwipeContainerAmbient_1.setWidth(240);
    SwipeContainerAmbient_1.setHeight(261);
    Ambient_Text_1.setXY(54, 23);
    Ambient_Text_1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Ambient_Text_1.setLinespacing(0);
    Ambient_Text_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6FIR));
    SwipeContainerAmbient_1.add(Ambient_Text_1);

    Ambient_Val_1.setXY(91, 60);
    Ambient_Val_1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Ambient_Val_1.setLinespacing(0);
    Ambient_Val_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A0ZD));
    SwipeContainerAmbient_1.add(Ambient_Val_1);

    AmbientCirc_Val_1.setXY(65, 107);
    AmbientCirc_Val_1.setProgressIndicatorPosition(0, 0, 110, 110);
    AmbientCirc_Val_1.setRange(0, 100);
    AmbientCirc_Val_1.setCenter(55, 55);
    AmbientCirc_Val_1.setRadius(50);
    AmbientCirc_Val_1.setLineWidth(10);
    AmbientCirc_Val_1.setStartEndAngle(0, 360);
    AmbientCirc_Val_1.setCapPrecision(180);
    AmbientCirc_Val_1.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_CIRCLEPROGRESS_BACKGROUNDS_SMALL_ID));
    AmbientCirc_Val_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    AmbientCirc_Val_1.setPainter(AmbientCirc_Val_1Painter);
    AmbientCirc_Val_1.setValue(60);
    SwipeContainerAmbient_1.add(AmbientCirc_Val_1);

    SwipeContainer.add(SwipeContainerAmbient_1);

    SwipeContainerHumidity_1.setWidth(240);
    SwipeContainerHumidity_1.setHeight(261);
    Humidity_Text_1.setXY(76, 23);
    Humidity_Text_1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Humidity_Text_1.setLinespacing(0);
    Humidity_Text_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LAVD));
    SwipeContainerHumidity_1.add(Humidity_Text_1);

    Humidity_Val_1.setXY(91, 60);
    Humidity_Val_1.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    Humidity_Val_1.setLinespacing(0);
    Humidity_Val_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PG2R));
    SwipeContainerHumidity_1.add(Humidity_Val_1);

    HumidityCirc_Val_1.setXY(65, 107);
    HumidityCirc_Val_1.setProgressIndicatorPosition(0, 0, 110, 110);
    HumidityCirc_Val_1.setRange(0, 100);
    HumidityCirc_Val_1.setCenter(55, 55);
    HumidityCirc_Val_1.setRadius(50);
    HumidityCirc_Val_1.setLineWidth(10);
    HumidityCirc_Val_1.setStartEndAngle(0, 360);
    HumidityCirc_Val_1.setCapPrecision(180);
    HumidityCirc_Val_1.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_CIRCLEPROGRESS_BACKGROUNDS_SMALL_ID));
    HumidityCirc_Val_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    HumidityCirc_Val_1.setPainter(HumidityCirc_Val_1Painter);
    HumidityCirc_Val_1.setValue(60);
    SwipeContainerHumidity_1.add(HumidityCirc_Val_1);

    SwipeContainer.add(SwipeContainerHumidity_1);

    SwipeContainerTemperature.setWidth(240);
    SwipeContainerTemperature.setHeight(261);
    TempIn_Val.setXY(91, 60);
    TempIn_Val.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    TempIn_Val.setLinespacing(0);
    TempIn_Val.setTypedText(touchgfx::TypedText(T___SINGLEUSE_L6YL));
    SwipeContainerTemperature.add(TempIn_Val);

    TempIn_Text.setXY(51, 0);
    TempIn_Text.setColor(touchgfx::Color::getColorFromRGB(0, 247, 255));
    TempIn_Text.setLinespacing(0);
    TempIn_Text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YJPG));
    SwipeContainerTemperature.add(TempIn_Text);

    TempInCirc_Val.setXY(65, 107);
    TempInCirc_Val.setProgressIndicatorPosition(0, 0, 110, 110);
    TempInCirc_Val.setRange(0, 100);
    TempInCirc_Val.setCenter(55, 55);
    TempInCirc_Val.setRadius(50);
    TempInCirc_Val.setLineWidth(10);
    TempInCirc_Val.setStartEndAngle(0, 360);
    TempInCirc_Val.setCapPrecision(180);
    TempInCirc_Val.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_CIRCLEPROGRESS_BACKGROUNDS_SMALL_ID));
    TempInCirc_ValPainter.setColor(touchgfx::Color::getColorFromRGB(0, 240, 255));
    TempInCirc_Val.setPainter(TempInCirc_ValPainter);
    TempInCirc_Val.setValue(60);
    SwipeContainerTemperature.add(TempInCirc_Val);

    SwipeContainer.add(SwipeContainerTemperature);

    SwipeContainer.setSelectedPage(0);
    add(SwipeContainer);

    digitalClock1.setPosition(9, 292, 98, 28);
    digitalClock1.setColor(touchgfx::Color::getColorFromRGB(0, 234, 255));
    digitalClock1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UQLB));
    digitalClock1.displayLeadingZeroForHourIndicator(true);
    digitalClock1.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock1.setTime24Hour(10, 10, 0);
    add(digitalClock1);

    box2.setPosition(0, 0, 240, 52);
    box2.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    box2.setAlpha(17);
    add(box2);

    box2_1.setPosition(-1, 292, 241, 32);
    box2_1.setColor(touchgfx::Color::getColorFromRGB(56, 89, 255));
    box2_1.setAlpha(17);
    add(box2_1);
}

DefaultViewViewBase::~DefaultViewViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
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
}

void DefaultViewViewBase::handleTickEvent()
{
    //Interaction1
    //When every N tick call virtual function
    //Call function1
    function1();
}
