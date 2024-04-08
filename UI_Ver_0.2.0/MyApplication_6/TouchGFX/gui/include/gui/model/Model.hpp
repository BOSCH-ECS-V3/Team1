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

    void update_Clock(int Clock_Valued[3]);
    void update_Date(int updated_Date_Values[3]);

protected:
    ModelListener* modelListener;

    // !!! All variables in model.cpp should be declared here to pass them to the presentor->view
    int Button_state = 100 ;

    int tickCounter = 0;

    int Clock_Values[3]={0,0,0};

    int current_Date_values[3]={4,4,2024};

    int current_Sensor_values[6]={0,0,0,0,0,0};


};

#endif // MODEL_HPP
