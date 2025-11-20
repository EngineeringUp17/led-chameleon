# LED RGB Chameleon

This is a modified version of the code from [this project](https://www.instructables.com/Electronic-Chameleon/).  
See the original website for all credits and build instructions. However in general, Engineering Up students will want to:
1. Wire up the color sensor to the Arduino as shown in the project page linked above. NOTE: sometimes color sensors have different pinouts. It is critical that each signal goes to the correct poin on the Arduino (VCC -> Vin, S3 -> D7, S2 -> D6, etc...) 
2. Connect the Arduino to a computer, and upload the code that is offered by the project page
3. Open the serial monitor in the Arduino IDE to make sure the color sensor is outputting numbers that change when different colors are presented in front of the sensor.
4. Unplug the Arduino from the computer and wire up the LED strip as shown in the project page linked above
5. Plug the Arduino back into the computer to have it run and see if the LEDs light up when a color is presented to the color sensor. The LEDs will remain off if nothing is detected, but if a bright color (Blue, red, pink, white, orange) is presented to the sensor, it should show on the LEDs 
