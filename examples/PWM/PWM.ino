#include <ESP32PWM.h>

// PWM Functionality for ESP32 Platforms
// 2018 Ian McLinden <https://github.com/ianmclinden>

// Demonstrates basic PWM functionality
// Updated - 16 Sept 2018
// Based on the Arduino > Analog > Fading Code example created 1 Nov 2008
//  by David A. Mellis, anad modified 30 Aug 2011 by Tom Igoe
//
//  http://www.arduino.cc/en/Tutorial/Fading


// ESP32 Blue LED Pin
#define LED_BUILTIN 2
#define LED_PWM_FREQUENCY 1000

// Create our PWM devide on Pin 9, using the default PWM  frequncy (500 Hz)
ESP32PWM led(LED_BUILTIN);

//  To specify the PWM base frequency at construction, use 
//ESP32PWM led(LED_BUILTIN, LED_PWM_FREQUENCY);

void setup() {
    // Frequency can also be set during runtime
    led.setFrequency(LED_PWM_FREQUENCY);
    led.begin();
}

void loop() {
    // fade in from min to max in increments of 5 points:
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
        // sets the value (range from 0 to 255):
        led.analogWrite(fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }
    
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
        // sets the value (range from 0 to 255):
        led.analogWrite(fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }

    // To toggle PWM output, use enable() or disable()
    led.disable();
    led.analogWrite(255); // This will not PWM until we enable again
    delay(500);
    led.analogWrite(0);
    led.enable();
    
}