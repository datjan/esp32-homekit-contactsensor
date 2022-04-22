# esp32-homekit-contactsensor
This is a native HomeKit contact sensor with ESP32 based on potential free contacts.

## Hardware
The following hardware is required:
```
- ESP32
- Resistors 10kOhm
- Potential free contacts (from your security system like ABUS Terxon)
```

Connection:
ESP32 -> Potential free contact
```
3V3 -> Potential free contact
GPIO18 -> Potential free contact
GPIO18 -> 10kOhm -> GND
```


![alt text](https://github.com/datjan/esp32-homekit-contactsensor/blob/main/connection-schema.png?raw=true)


## Development
This sketch is for following development environment
```
Arduino
```

Following libraries are required
```
https://github.com/datjan/HomeSpan  (fork from https://github.com/HomeSpan/HomeSpan)
```

## Upload to device
Following files needs to be uploaded to the ESP32
```
esp32-homekit-contactsensor.ino
DEV_Identify.h
DEV_SecuritySystems.h
```

## Setup
Setup via Arduino serial monitor.

Configuration HomeKit code (123-55-222)
```
S 12355222
```

Configuration Wifi connection
```
W
```

## Add device to Homekit
The device can be added to homekit like every other homekit device.
