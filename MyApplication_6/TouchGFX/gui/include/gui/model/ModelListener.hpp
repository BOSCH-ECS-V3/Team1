#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateValue(int state)
    {
    	// Test func
    };

    virtual void current_Clock(int Clock_Values[3])
    {
    	// send current clock to presenter
    };

    virtual void current_Date_value(int current_Date_value[3])
    {
    	// send current date to presenter
    };
    virtual void updated_Clock(int Clock_Values[3])
    {
    	// receiving Clock Setting from View->Clock page
    };
    virtual void current_Sensor_values(int current_Sensor_values[5] , int GAS_Preheat_FLAG)
    {
    	// sending current sensor values to presenter Default page
    };
    virtual void SEND_Permission(int Permission_STATE)
    {
    	// receive from view
    };
    virtual void RECEIVE_Permission(int Permission_STATE)
    {
    	// send to view
    };
    virtual void SEND_Error_ID(int Error_ID , int SNOOZE_FLAG_TEMPIN , int SNOOZE_FLAG_GAS , int SNOOZE_FLAG_TEMPOUT , int SNOOZE_FLAG_HUMIDITY, int SNOOZE_FLAG_PRESSURE ,int  SNOOZE_FLAG_AMBIENT)
    {
    	// send Error_ID to the view -> Default page
    }

    virtual void set_screen_brightness(int brightness)
    {
    	// send Screen brightness to view -> Default page
    }

    virtual void STATISTICS_tempIN(int statistics_tempIN[24], int tempIN_index , int average_day)
    {
    	// send statistics array and index to view page of tempIN
    }
    virtual void STATISTICS_tempOUT(int statistics_tempOUT[24], int statistics_index)
    {
    	// send statistics array and index  to view page of tempOUT
    }
    virtual void STATISTICS_humidity(int statistics_humidity[24], int statistics_index)
    {
    	// send statistics array and index to view page of Humidity statistics
    }
    virtual void STATISTICS_gas(int statistics_gas[24], int statistics_index)
    {
    	// send statistics array and index to view page of Gas
    }
    virtual void STATISTICS_pressure(int statistics_pressure[24] , int statistics_index)
    {
    	// send statistics array and index to view page of Pressure
    }
    virtual void STATISTICS_ambient(int statistics_ambient[24] , int statistics_index)
    {
    	// send statistics array and index to view page of Ambient
    }
    virtual void send_average_TempIN(int average_day , int average_week , int average_month)
    {

    }
    virtual void send_average_TempOUT(int avrDayTempOUT_res , int avrWeekTempOUT_res , int avrMonthTempOUT_res)
    {

    }
    virtual void send_average_Humidity(int avrDayHumidity_res , int avrWeekHumidity_res , int avrMonthHumidity_res)
    {

    }
    virtual void send_average_Pressure(int avrDayPressure_res , int avrWeekPressure_res , int avrMonthPressure_res)
    {

    }
    virtual void send_average_Gas(int avrDayGas_res , int avrWeekGas_res , int avrMonthGas_res)
    {

    }
    virtual void send_average_Ambient(int avrDayAmbient_res , int avrWeekAmbient_res , int avrMonthAmbient_res)
    {

    }

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
