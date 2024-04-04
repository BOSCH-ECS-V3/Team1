#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



Model::Model() : modelListener(0) , Button_state(240) //, SensorValues{}
{

}

void Model::tick()
{


	// Test sending info to View

	modelListener->updateValue(Button_state);
	//modelListener->update_sensor_values(SensorValues);

}
