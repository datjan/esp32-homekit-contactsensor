# esp32-homekit-contactsensor
This is a native HomeKit contact sensor with ESP32 based on potential free contacts.
It is working with the old and new HomeKit-Architecture (Changes in 2022/2023)


![alt text](https://github.com/datjan/esp32-homekit-contactsensor/blob/main/homekit-example.png?raw=true)


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
https://github.com/HomeSpan/HomeSpan
```

Following Arduino->Tools settings should be used
```
Partition Scheme: Default 4MB with ffat
```

## Upload to device
Following files needs to be uploaded to the ESP32
```
esp32-homekit-contactsensor.ino
DEV_Identify.h
DEV_ContactSensors.h
```

## Setup
Setup via Arduino serial monitor (115200 baud).

Configuration HomeKit code (123-55-222)
```
S 12355222
```

Configuration Wifi connection
```
W
```

In case of the ESP32 ist restarting/showing errors after doing some commands, try to disconnect the power source and boot it again.

## Add device to Homekit
The device can be added to homekit like every other homekit device, but with the help of the other devices search in home app.
