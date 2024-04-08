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
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
