
//////////////////////////
//   DEVICE-SPECIFIC    //
//////////////////////////

struct DEV_ContactSensor : Service::ContactSensor {     // A ContactSensor

  SpanCharacteristic *current;            // reference to the SecuritySystemCurrentState Characteristic (specific to ContactSensor)

  DEV_ContactSensor() : Service::ContactSensor(){       // constructor() method
        
    current=new Characteristic::ContactSensorState(1);              // initial value of 1 = open - 0 = closed

    
    Serial.print("Configuring ContactSensor");   // initialization message
    Serial.print("\n");

  } // end constructor

  boolean update(){                              // update() method

    // see HAP Documentation for details on what each value represents

    // State
    uint8_t contactstate = 1;  
    
    // Pins
    int pinState = 18;

    // Get state
    if (digitalRead(pinState) == HIGH) { contactstate = 0; LOG1("State: Closed"); } // Closed
    else { contactstate = 1; } // Open

    // Change state
    current->setVal(contactstate);
    
    
    return(true);                               // return true
  
  } // update

  void loop(){                                     // loop() method

    // State
    uint8_t contactstate = 1;  
    
    // Pins
    int pinState = 18;

    // Get state
    if (digitalRead(pinState) == HIGH) { contactstate = 0; LOG1("State: Closed"); } // Closed
    else { contactstate = 1; } // Open

    // Exit in case of no state changes
    if(current->getVal()==contactstate) { return; }        // if current-state matches target-state there is nothing do -- exit loop()

    // Change state
    current->setVal(contactstate);
       
  } // loop
  
};
