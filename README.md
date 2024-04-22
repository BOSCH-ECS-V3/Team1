
# About

This is part of the documentation for the ***"Weather Station"*** project.

The project, as the name implies, aims to create a functioning weather station using

the **STM32F429I_DISCO** board, a couple of modules and for visualization we use TouchGFX.

# Functionality

  

The **Weather Station** developed by our team has the following funcitons and features:

  

1.  *Monitoring of different environmental parameters.*.

	- Temperature outside and inside.

	- Pressure

	- Humidity

	- Ambient Light

	- Carbon Monoxide

2.  *User Interface ( using **TouchGFX** ).*

	- An easy-to-understand UI is included in this project with menus to navigate data and settings.

3.  *Command Line Interface.*

	- This system allows a developer to directly influence the UI and Data on the board.

	- It can help with debugging and gathering data. *More in the **Getting Started** section*

4.  *~~Statistics throughout the day and over a period of time.~~*  *LIES*

	- daily

	- weekly

	- monthly

5.  *Alarms for high and dangerous readings.*

  

# The Modules

4.  **Carbon Monoxide Gas Sensor MQ7** - The MQ7 is a simple-to-use Carbon Monoxide (CO) sensor suitable for sensing CO concentrations in the air. It can detect CO-gas concentrations anywhere from 20 to 2000ppm.

  

5.  **Ambient Light Sensor SKU_DFR0026** - This module can help you to detect the light density of your enviroment and reflect this information back via an analog voltage signal to your controller.

  

6.  **BME680 Environmental Sensor** -This is a low power gas, pressure, temperature & humidity sensor based on ***BOSCH BME680*** sensor. It is a 4-in-1 multi-functional MEMS environmental sensor which integrates VOC (Volatile Organic Compounds) sensor, temperature sensor, humidity sensor and barometer.

  

	*Additional documentation for the sensors:*

  

	[**MQ7**](https://wiki.dfrobot.com/Carbon_Monoxide_Gas_Sensor_MQ7___SKU_SEN0132_)

  
  

	[**SKU_DFR0026**](https://wiki.dfrobot.com/DFRobot_Ambient_Light_Sensor_SKU_DFR0026)

  
  

	[**BME680**](https://wiki.dfrobot.com/Gravity__I2C_BME680_Environmental_Sensor__VOC,_Temperature,_Humidity,_Barometer__SKU__SEN0248)

  
  

# Schematics

![](https://i.ibb.co/FKxLTm0/mq7.png)

**Specifications:**
-   Power supply needs: **5V**
-   Interface type: **Analog**
-   Pin Definition: 
	- 1- **Output**
	-  2- **VCC** 
	- 3- **GND**
-   High sensitivity to **carbon monoxide**
-   Fast response
-   Stable and long life
-   Size: **40x20mm**


Before we start working with the gas sensor we need to power it properly using **5V** and **GND** from the microcontroller. Then we need to read the returned analog value using the **ADC**, but since the maximum we can read with it is **3V**, we need to make a voltage divider whose coefficient we use to correctly calculate the return value.

![](https://i.ibb.co/qmXmxzv/AMB.png)

**Specifications:**

-   Supply Voltage: **3.3V** to **5V**
-   Illumination range : **1 Lux** to **6000 Lux**
-   Responsive time : **15us**
-   Interface: **Analog**
-   Size: **22x30mm**

We **power** this sensor in the same way, being careful not to connect the wires incorrectly. The sensor also returns an analog value that we read using an **ADC** (different channel) and convert **the value** into **a percentage**

![enter image description here](https://i.ibb.co/brPXSxd/BME.png)

**Specifications:**
-   Input Voltage: **3.3V~5.0V**
-   Operating Current: **5mA** (*25mA in VOC*)
-   Wire Connector: **Gravity I2C**
-   Connector in Reserve: **SPI**
-   Temperature Measurement Range: **-40℃~ 85℃**
-   Temperature Measurement Precision: **±1.0℃** (*0~65℃*)
-   Humidity Measurement Range: **0-100**% *r.H*
-   Humidity Measurement Precision: **±3**% r.H.(***20-80**% r.H. **25℃***)
-   Atmospheric Pressure Measurement Range: **300-1100**hPa
-   Atmospheric Pressure Measurement Precision: **±0.6**hPa(***300-1100**hPa,0~65℃*)
-   IAQ (*Indoor Air Quality*) Range: **0-500** (*the larger the worse*)
-   Module Size: **30 × 22**(*mm*) / **1.18 x0.87**(*inches*).

After successfully powering the sensor, we have to choose what type of communication we will use **I2C** or **SPI** (*the microcontroller supports both types of communication*). In our case, we have chosen **I2C,** which means we need **2** **additional buses** for clock and for data. We have initialized pins **PA8**(**SCL**) and **PC9**(**SDA**) to which we connect the wires from the sensor correctly.

**NOTE:** *We can connect more than one sensor, but its address must be different.*

![enter image description here](https://i.ibb.co/vz2xrCw/Connections.png)


**In the end, everything should look like this.**

**NOTE:** Any connection changes must be made with the power off, otherwise unexpected conditions may occur.

The final step is to initialize all the pins needed for the **Weather Station** to work!
In order to do so we will utilize the tools available in the **STM32CubeIDE**!
From there we will enable a **UART Communication channel**
 and an **ADC Channel** with pins: ****PA5** & **PA7****


# Getting Started

  

Once the components are connected correctly, we are ready to test out the program!

Firstly you will need a program to flash the board with the code.

Our personal recommendation is to use the [**STM32IDE**](https://www.st.com/en/development-tools/stm32cubeide.html)

  
  

Second, you will have to import the project into the **IDE**. Then we can finally flash our code on the board.

  

**NOTE:**  *There may be issues upon importing, linked with directories and file locating. A simple fix would be to ****clean the project** -> **build** -> **no errors** -> **flash*****.

  

If everything is done correctly you should see the screen on the board display the **UI**!

Feel free to interact and see how our **Weather Station** works!

  

You can use the touchscreen to navigate the menus and settings, but you can also use the

**Command Line Interface**!

To access the **CLI** you have to know to which port on your **PC** you have connected the board. That is as simple as opening **device manager** on windows( *sorry linux users :c* ) -> **Ports**. 

  

Now we can use the built-in console by our **stm32IDE** or something like [**PuTTy**](https://www.putty.org/).

Once the console is open we need to set the **frequency** and correct **COM** port.

Upon connecting the user can see the list of available commands by typing: **HELP**

  

# Architecture
![enter image description here](https://i.ibb.co/qxk34Sm/architecture.png)

 **Architecture** describes the conceptual model of software. At the top is the **user's code** 
 all **algorithms**, implementations, etc. written by us for the system to function properly. The operating system used by the system is **[FreeRTOS](https://www.freertos.org/)** **which allows multiple programs to execute at the same time.**
For an interface providing the necessary information to the user in a clear and understandable way, we used **TouchGFX.** All the components presented below represent the initialized modules without which data collection, processing and presentation **would not be possible.**

# Tests

  

# Error Codes

| Modules  | Error |Error Code |
| --|--|--|
| MQ7|**UNPLUGGED**  |	|
|SKU:DFR0026|**UNPLUGGED**	|	|
|BME680	|**UNPLUGGED**	|	|