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

    };

    virtual void current_Clock(int Clock_Values[3])
    {
    	// send current clock to presenter
    };

    virtual void updated_Clock(int Clock_Values[3])
    {

    };

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
