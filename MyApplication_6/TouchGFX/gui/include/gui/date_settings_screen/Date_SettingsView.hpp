#ifndef DATE_SETTINGSVIEW_HPP
#define DATE_SETTINGSVIEW_HPP
#define January 1
#define February 2
#define March 3
#define April 4
#define May 5
#define June 6
#define July 7
#define August 8
#define September 9
#define October 10
#define November 11
#define December 12

#include <gui_generated/date_settings_screen/Date_SettingsViewBase.hpp>
#include <gui/date_settings_screen/Date_SettingsPresenter.hpp>

class Date_SettingsView : public Date_SettingsViewBase
{
public:
    Date_SettingsView();
    virtual ~Date_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent(); // update Date view screen
    virtual void Days_Val_Up();
    virtual void Days_Val_Down();
    virtual void Months_Val_Up();
    virtual void Months_Val_Down();
    virtual void Years_Val_Up();
    virtual void Years_Val_Down();
    virtual void Update_Date();
    virtual void current_Date_value(int current_Date_value[]);
    virtual void set_screen_brightness(int brightness);
    //virtual void current_Date(int Date_Values[]);


    int updated_Days = 15;
    int updated_Month = 04;
    int updated_Year = 2020;

    int current_Days ;
    int current_Month ;
    int current_Year ;

protected:
};

#endif // DATE_SETTINGSVIEW_HPP
