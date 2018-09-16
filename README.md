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
The voltage seems to increase as I place my finger closer to the black sensor on the proximity sensor. If I move away my finger from the sensor, it drops instantaneously. The metrics are shown in the serial monitor as below.

 ![alt text](https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/proximity1.jpg)


**b. Upload your merged code to your lab report repository and link to it here.**
I merged the accelerometor (displayed on LCD) and the proximity (displayed on serial monitor). 

Code:  (https://github.com/contactkoh/IDD-Fa18-Lab3/blob/master/accel_and_proxy.ino)

VIDEO:  [Accelerometer & Proximity](https://youtu.be/FqHYhkXnpKs)


## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
