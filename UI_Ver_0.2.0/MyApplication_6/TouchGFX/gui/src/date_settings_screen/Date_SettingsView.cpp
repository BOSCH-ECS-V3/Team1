#include <gui/date_settings_screen/Date_SettingsView.hpp>

Date_SettingsView::Date_SettingsView()
{

}

void Date_SettingsView::setupScreen()
{
	Date_SettingsViewBase::setupScreen();
}

void Date_SettingsView::tearDownScreen()
{
	Date_SettingsViewBase::tearDownScreen();
}

void Date_SettingsView::handleTickEvent()
{
    Unicode::snprintf(current_Days_ValBuffer, CURRENT_DAYS_VAL_SIZE, "%d", current_Days);
    Unicode::snprintf(current_Months_ValBuffer, CURRENT_MONTHS_VAL_SIZE, "%d",current_Month);
    Unicode::snprintf(current_Year_ValBuffer, CURRENT_YEAR_VAL_SIZE, "%d",current_Year);

    current_Days_Val.invalidate();
    current_Months_Val.invalidate();
    current_Year_Val.invalidate();
}

void Date_SettingsView::Days_Val_Up()
{
	updated_Days++;
	Unicode::snprintf(Days_ValBuffer, DAYS_VAL_SIZE, "%d", updated_Days);
	Days_Val.invalidate();
}
void Date_SettingsView::Days_Val_Down()
{
	updated_Days--;
	Unicode::snprintf(Days_ValBuffer, DAYS_VAL_SIZE, "%d", updated_Days);
	Days_Val.invalidate();
}
void Date_SettingsView::Months_Val_Up()
{
	updated_Month++;
	Unicode::snprintf(Months_ValBuffer, MONTHS_VAL_SIZE, "%d",updated_Month );
	Months_Val.invalidate();

}
void Date_SettingsView::Months_Val_Down()
{
	updated_Month--;
	Unicode::snprintf(Months_ValBuffer, MONTHS_VAL_SIZE, "%d",updated_Month );
	Months_Val.invalidate();
}
void Date_SettingsView::Years_Val_Up()
{
	updated_Year++;
	Unicode::snprintf(Year_ValBuffer, YEAR_VAL_SIZE, "%d", updated_Year);
	Year_Val.invalidate();

}
void Date_SettingsView::Years_Val_Down()
{
	updated_Year--;
	Unicode::snprintf(Year_ValBuffer, YEAR_VAL_SIZE, "%d", updated_Year);
	Year_Val.invalidate();
}
void Date_SettingsView::Update_Date()
{
	// when submit button is clicked , update current date

	current_Days = updated_Days;
    current_Month = updated_Month;
    current_Year = updated_Year;

    Unicode::snprintf(current_Days_ValBuffer, CURRENT_DAYS_VAL_SIZE, "%d", updated_Days);
    Unicode::snprintf(current_Months_ValBuffer, CURRENT_MONTHS_VAL_SIZE, "%d",updated_Month);
    Unicode::snprintf(current_Year_ValBuffer, CURRENT_YEAR_VAL_SIZE, "%d",updated_Year);

    current_Days_Val.invalidate();
    current_Months_Val.invalidate();
    current_Year_Val.invalidate();

	// pass updated values to the module
	int updated_values[3]={updated_Days, updated_Month, updated_Year};
	presenter->update_Date(updated_values);
}
void Date_SettingsView::current_Date_value(int current_Date_value[])
{
	// current date values coming from model
	current_Year = current_Date_value[2];
	current_Month = current_Date_value[1];
	current_Days = current_Date_value[0];
}
