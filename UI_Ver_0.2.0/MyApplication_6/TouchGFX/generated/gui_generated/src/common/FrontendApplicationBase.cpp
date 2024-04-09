/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <gui/defaultview_screen/DefaultViewView.hpp>
#include <gui/defaultview_screen/DefaultViewPresenter.hpp>
#include <gui/menudropdown_screen/MenuDropdownView.hpp>
#include <gui/menudropdown_screen/MenuDropdownPresenter.hpp>
#include <gui/about_screen/AboutView.hpp>
#include <gui/about_screen/AboutPresenter.hpp>
#include <gui/time_settings_screen/Time_SettingsView.hpp>
#include <gui/time_settings_screen/Time_SettingsPresenter.hpp>
#include <gui/date_settings_screen/Date_SettingsView.hpp>
#include <gui/date_settings_screen/Date_SettingsPresenter.hpp>
#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsideView.hpp>
#include <gui/statistics_temperature_inside_screen/Statistics_Temperature_InsidePresenter.hpp>
#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsideView.hpp>
#include <gui/statistics_temperature_outside_screen/Statistics_Temperature_OutsidePresenter.hpp>
#include <gui/statistics_humidity_screen/Statistics_HumidityView.hpp>
#include <gui/statistics_humidity_screen/Statistics_HumidityPresenter.hpp>
#include <gui/statistics_presure_screen/Statistics_PresureView.hpp>
#include <gui/statistics_presure_screen/Statistics_PresurePresenter.hpp>
#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1View.hpp>
#include <gui/statistics_ambient_1_screen/Statistics_Ambient_1Presenter.hpp>
#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorView.hpp>
#include <gui/statistics_gas_sensor_screen/Statistics_Gas_sensorPresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_PORTRAIT);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableDecompressorL8_All();
}

/*
 * Screen Transition Declarations
 */

// DefaultView

void FrontendApplicationBase::gotoDefaultViewScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoDefaultViewScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoDefaultViewScreenNoTransitionImpl()
{
    touchgfx::makeTransition<DefaultViewView, DefaultViewPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// MenuDropdown

void FrontendApplicationBase::gotoMenuDropdownScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoMenuDropdownScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMenuDropdownScreenNoTransitionImpl()
{
    touchgfx::makeTransition<MenuDropdownView, MenuDropdownPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// About

void FrontendApplicationBase::gotoAboutScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoAboutScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoAboutScreenNoTransitionImpl()
{
    touchgfx::makeTransition<AboutView, AboutPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Time_Settings

void FrontendApplicationBase::gotoTime_SettingsScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoTime_SettingsScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoTime_SettingsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Time_SettingsView, Time_SettingsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Date_Settings

void FrontendApplicationBase::gotoDate_SettingsScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoDate_SettingsScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoDate_SettingsScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Date_SettingsView, Date_SettingsPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Statistics_Temperature_Inside

void FrontendApplicationBase::gotoStatistics_Temperature_InsideScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStatistics_Temperature_InsideScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStatistics_Temperature_InsideScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Statistics_Temperature_InsideView, Statistics_Temperature_InsidePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Statistics_Temperature_Outside

void FrontendApplicationBase::gotoStatistics_Temperature_OutsideScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStatistics_Temperature_OutsideScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStatistics_Temperature_OutsideScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Statistics_Temperature_OutsideView, Statistics_Temperature_OutsidePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Statistics_Humidity

void FrontendApplicationBase::gotoStatistics_HumidityScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStatistics_HumidityScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStatistics_HumidityScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Statistics_HumidityView, Statistics_HumidityPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Statistics_Presure

void FrontendApplicationBase::gotoStatistics_PresureScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStatistics_PresureScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStatistics_PresureScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Statistics_PresureView, Statistics_PresurePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Statistics_Ambient_1

void FrontendApplicationBase::gotoStatistics_Ambient_1ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStatistics_Ambient_1ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStatistics_Ambient_1ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Statistics_Ambient_1View, Statistics_Ambient_1Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Statistics_Gas_sensor

void FrontendApplicationBase::gotoStatistics_Gas_sensorScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStatistics_Gas_sensorScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStatistics_Gas_sensorScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Statistics_Gas_sensorView, Statistics_Gas_sensorPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
