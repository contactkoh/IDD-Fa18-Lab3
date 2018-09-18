# Data Logger (and using cool sensors!)

*A lab report by HONGYUN (Kevin) OH*
ho247@cornell.edu

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 0 ~ 1023
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**
10 bits (10-bit ADC. so 2^10 = 1024 ) 
(reference: https://learn.sparkfun.com/tutorials/analog-to-digital-conversion )

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**
 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/RGB1.jpg)
 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/RGB2.jpg)

  I used the sample code and the RGB LED and 3 resistors. 3 resistors going to the RGB leds and the Common Anode going to the +5V. 
It changes colors RGB by looping. 

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot
 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/force1.jpg)
 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/force2.jpg)

**a. What voltage values do you see from your force sensor?**
About 400(when not pressed) ~ 1023(when pressed. 5V max)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**
If I apply force(press), it goes up (max 1023, 5v max) , so I think it has linear characteristic, but also maxed at certain ranges so that it is working like a log (logarithmic) function. 

**c.In Examples->Basic->Fading the LED values range from 0-255. What do you have to do so that you get the full range of output voltages from the LED when using your FSR to change the LED color?


Video:   [Changing LED color using FSR](https://youtu.be/5opCuWPJ3xo)


The FSR is supposed to be reading 0~1023.  Therefore, to change the COLOR of the LED, I use the RGB color LED as the output.
Depending of the analogRead value, if the FSR is pressed (say, reading 1023 when pressed), the variable 'brightness' would go into the if statement below to change the color. 

brightness = analogRead(A0);
  
  if (brightness <=0 || brightness >= 1023) {
    setColor(255, 0, 0);  // change the color
    delay(2000);
  }

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**
About 100 Ohms seems to get a reasonable range of voltages for this task. We only had 1 kind of resistors in the Tinkerkit. 

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**
The more stimulus/pressure it is applied to FSR, the Voltage goes up and resistance goes down (V=IR). So it has a linear characteristic but within a maximum range (like a log or logarithmic relationship). 

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

First colume of X represents raw values, as well as the Y and Z. 
Second colume of X represents the raw value scaled down by 2^8.  So, X is close to 0 when placed parallel to the ground.


VIDEO:  [Changing LED color using FSR](https://youtu.be/Y0H5mGHPpmQ)


Code:  (https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/accelerometer_TEST.ino)

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/Accelerametor1.jpg)

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/Accelerometer2.jpg)



### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**
The voltage seems to increase as I place my finger closer to the black sensor on the proximity sensor. If I move away my finger from the sensor, it drops instantaneously. The metrics are shown in the serial monitor as below. Also, it is largely in line with their datasheet as the closer the distance the higher the voltage, and vice versa. 

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/diagram.jpg)

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/proximity1.jpg)


**b. Upload your merged code to your lab report repository and link to it here.**
I merged the accelerometor (displayed on LCD) and the proximity (displayed on serial monitor). 

Code:  (https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/accel_and_proxy.ino)

VIDEO:  [Accelerometer & Proximity](https://youtu.be/FqHYhkXnpKs)


## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

I studied the Nokia site link and tried to figure it out but it was too hard for me to do all these+ this within the given time, and everything was taking way too long time, coming from a non-electrical, non-hardware, business background.  
https://learn.adafruit.com/nokia-5110-3310-monochrome-lcd/wiring


## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM


**a. Does it matter what actions are assigned to which state? Why?**

When the SwitchState.ino runs, the map function returns a state value (0,1,or 2) taking into the range value (0~1024). 
Depending on the state, each state would call a different method in a different file. 
When Pot is turned up, "Reading from EEPROM" starts and values are read in. Last state is saved and when the POT is turned down back, the "DONE READING" and then "WRITING TO EEPROM" are printed. 

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/EEPROM1.jpg)
 
 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/EEPROM2.jpg)


**b. Why is the code here all in the setup() functions and not in the loop() functions?**
Because each State in each of the three cases is called on and started when the main SwitchState calls them. Each state is then clearing the EEPROM and is run when it is called. 
On the coding side, the main SwitchState loop calls for each of the 3 cases in each of the methods in each 3 files (for the 3 states). 
Each state method then calls the setup()functions of its own state file, to start its own State.

**c. How many byte-sized data samples can you store on the Atmega328?**
Arduino Uno with Atmega328 has 1 kbyte of EEPROM storage. So it seems it can hold 1000 byte-sized data samples. 
(reference: https://www.arduino.cc/en/Tutorial/EEPROMClear )

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**
Perhaps I can use the highbyte() and lowbyte() functions in Arduino. Because int value in Arduino is 16 bits, taking the top 8 bits or low 8 bits would allow me to reduce it to byte-sized.  
(Reference: http://forum.arduino.cc/index.php?topic=72993.0 )

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**
If using a variable bigger than a byte, then need to store the value in more than one byte.
Arduino's EEPROM is addressed by the byte, so use the consecutive addresses to store values in other variable types.
e.g. 
eeAddress += sizeof(float); //Move address to the next byte after float 'f'.
(Reference: http://forum.arduino.cc/index.php?topic=41720.0
https://www.arduino.cc/en/Reference/EEPROMPut  )


**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

Code:  (https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/SwitchState2_Test.ino)

Added the following to the SwitchState file:

  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/Serial1.jpg)


### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**


 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/statediag2.jpg)


### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

The data logger is based off of the SwitchState code samples.
It goes from State 2 --> 1 --> 0  if I turn the potentiometer up, and then 0 --> 1 --> 2 if turn the potentiometer back to 0.

I changed the Reading from EEPROM section so that the bytes read are converted to char

  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    //Serial.println(value);

    // convert byte to char
    char packetBuffer;
    packetBuffer = (char) value;
    Serial.println((char) packetBuffer);

  }
  
  I also changed the String input from "Hello cornell tech" to "Recorded Data" which is recorded and replayed back (See Video below)
  (Unfortunately, even after trying for many hours and much energy, I couldn't afford to spend more energy and time to dig deeper. )
  
Code:  (https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/SwitchState2.ino)

This is my Data logger: 


VIDEO:  [Data Logger](https://youtu.be/Wmf9rBSRRck)


This was the sample SwitchState code that ran successfully:


VIDEO:  [Data Logger](https://youtu.be/BaGjbQpQC7E)

