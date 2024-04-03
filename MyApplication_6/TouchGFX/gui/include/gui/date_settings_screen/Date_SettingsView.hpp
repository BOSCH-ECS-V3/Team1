#ifndef DATE_SETTINGSVIEW_HPP
#define DATE_SETTINGSVIEW_HPP

#include <gui_generated/date_settings_screen/Date_SettingsViewBase.hpp>
#include <gui/date_settings_screen/Date_SettingsPresenter.hpp>

class Date_SettingsView : public Date_SettingsViewBase
{
public:
    Date_SettingsView();
    virtual ~Date_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DATE_SETTINGSVIEW_HPP
