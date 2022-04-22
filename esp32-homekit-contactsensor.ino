/*********************************************************************************
 *  MIT License
 *  
 *  Copyright (c) 2020 Gregg E. Berman
 *  
 *  https://github.com/HomeSpan/HomeSpan
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 ********************************************************************************/
/*


ESP32 -> Potential free contact sensor
3V3 -> Potential free contact sensor
GPIO18 -> Potential free contact sensor
GPIO18 -> 10kOhm -> GND

*/

#include "HomeSpan.h"         // https://github.com/datjan/HomeSpan  (fork from https://github.com/HomeSpan/HomeSpan)
#include "DEV_Identify.h"  
#include "DEV_ContactSensors.h"  

// Pins
int pinState = 18;




void setup() {                
 
  Serial.begin(115200);       

  // Pins to Input
  pinMode(pinState, INPUT_PULLDOWN); // Default state LOW
  

  homeSpan.begin(Category::Sensors,"ESP32 Contact");   
      
  new SpanAccessory();                                                          
    new DEV_Identify("Contact Sensor","DATJAN","datjan.esp32.002","esp32-homekit-contactsensor","1.0",0);
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
    new DEV_ContactSensor(); 
    

} 


void loop(){
  
  homeSpan.poll();         // run HomeSpan!
  
} // end of loop()
