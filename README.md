# About
This is part of the documentation for the ***"Weather Station"*** project. 
The project, as the name implies, aims to create a functioning weather station using
the **STM32F429I_DISCO** board, a couple of modules and for visualization we use TouchGFX.
# Functionality

The **Weather Station** developed by our team has the following funcitons and features:

 1. *Monitoring of different environmental parameters.*. 
    - Temperature outside and inside.
     - Pressure
     - Humidity
     - Ambient Light
     - Carbon Monoxide
     
 2. *User Interface ( using **TouchGFX** ).* 
		    	 - An easy-to-understand UI is included in this project with 		 menus to navigate data and settings.
 3. *Command Line Interface.* 
		 - This system allows a developer to directly influence the UI and Data on the board.
		 - It can help with debugging and gathering data. *More in the **Getting Started** section*
4. *~~Statistics throughout the day and over a period of time.~~*  *LIES* 
	- daily
	- weekly
	- monthly
5.  *Alarms for high and dangerous readings.*

# The Modules
 4. **Carbon Monoxide Gas Sensor MQ7** - The MQ7 is a simple-to-use Carbon Monoxide (CO) sensor suitable for sensing CO concentrations in the air. It can detect CO-gas concentrations anywhere from 20 to 2000ppm.

 5. **Ambient Light Sensor SKU_DFR0026** - This module can help you to detect the light density of your enviroment and reflect this information back via an analog voltage signal to your controller.

 6. **BME680 Environmental Sensor** -This is a low power gas, pressure, temperature & humidity sensor based on ***BOSCH BME680*** sensor. It is a 4-in-1 multi-functional MEMS environmental sensor which integrates VOC (Volatile Organic Compounds) sensor, temperature sensor, humidity sensor and barometer.

*Additional documentation for the sensors:*

[**MQ7**](https://wiki.dfrobot.com/Carbon_Monoxide_Gas_Sensor_MQ7___SKU_SEN0132_)  


[**SKU_DFR0026**](https://wiki.dfrobot.com/DFRobot_Ambient_Light_Sensor_SKU_DFR0026) 


[**BME680**](https://wiki.dfrobot.com/Gravity__I2C_BME680_Environmental_Sensor__VOC,_Temperature,_Humidity,_Barometer__SKU__SEN0248)


# Schematic




# Getting Started

 Once the components are connected correctly, we are ready to test out the program! 
 
Firstly you will need a program to flash the board with the code. 
Our personal recommendation is to use the [**STM32IDE**](https://www.st.com/en/development-tools/stm32cubeide.html)


Second, you will have to import the project into the **IDE**. Then we can finally flash our code on the board.

**NOTE:** *There may be issues upon importing, linked with directories and file locating. A simple fix would be to ****clean the project** -> **build** -> **no errors** -> **flash*****.

If everything is done correctly you should see the screen on the board display the **UI**!
Feel free to interact and see how our **Weather Station** works!

You can use the touchscreen to navigate the menus and settings, but you can also use the
**Command Line Interface**!
To access the **CLI** you have to know to which port on your **PC** you have connected the board. That is as simple as opening **device manager** on windows( *sorry linux users :c* ) -> **Ports**. 

Now we can use the built-in console by our **stm32IDE** or something like [**PuTTy**](https://www.putty.org/).
Once the console is open we need to set the **frequency** and correct **COM** port.
Upon connecting the user can see the list of available commands by typing: **HELP**

# Structure
 
# Tests

# Error Codes