#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;

    // !!! All variables in model.cpp should be declared here to pass them to the presentor->view
    int Button_state = 100 ;

    /*
   struct SensorValues{
    	double Temperature_Inside_Value ;
    	double Humidity_Value ;
    	double Ambient_Value ;
    	double Gas_Value ;
    	double Pressure_Value ;
    	double Temperature_Outside_Value ;
    };
    */




};

#endif // MODEL_HPP
