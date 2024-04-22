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
    virtual void current_Sensor_values(int current_Sensor_values[5])
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
    virtual void SEND_Error_ID(int Error_ID)
    {
    	// send Error_ID to the view -> Default page
    }

    virtual void set_screen_brightness(int brightness)
    {
    	// send Screen brightness to view -> Default page
    }

    virtual void STATISTICS_tempIN(int statistics_tempIN[24], int tempIN_index)
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

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
