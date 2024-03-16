# HomeAssistantEntities
[![PlatformIO CI](https://github.com/Johboh/HomeAssistantEntities/actions/workflows/platformio.yaml/badge.svg)](https://registry.platformio.org/libraries/johboh/HomeAssistantEntities)
[![ESP-IDF CI](https://github.com/Johboh/HomeAssistantEntities/actions/workflows/espidf.yaml/badge.svg)](https://components.espressif.com/components/johboh/homeassistantentities)
[![GitHub release](https://img.shields.io/github/release/Johboh/HomeAssistantEntities.svg)](https://github.com/Johboh/HomeAssistantEntities/releases)
[![Clang-format](https://github.com/Johboh/HomeAssistantEntities/actions/workflows/clang-format.yaml/badge.svg)](https://github.com/Johboh/HomeAssistantEntities)

Arduino (using Arduino IDE or PlatformIO) and ESP-IDF (using Espressif IoT Development Framework or PlatformIO) compatible library for providing sensors and actuators to Home Assistant using MQTT.

Home Assistant has a well defined way of defining sensors and actuators using MQTT. This library register a device with one or mulitple sensors and provide a way to publish new values for them, as well as listen for commands from Home Assistant.

### Currently supported sensors
- Atmospheric Preassure (hPa)
- Binary Sensor / Boolean
- Brightness (%)
- Door (open/closed)
- Humidity (%)
- Json (raw "json"-sensor)
- Lock (locked/unlocked)
- Motion (detected/not detected)
- Number
- Sound (detected/not detected)
- String (raw "String"-sensor)
- Temperature (°C/°F)
- Voltage (mV/V)
- Weight (g/kg)

### Currently supported actuators (and sensors)
- Curtain (open/opening, close/closing, position)
- Event
- Light (brightness, rgb, effect)
- Select
- Switch (on/off)


### Installation
#### PlatformIO (Arduino or ESP-IDF):
Add the following to `libs_deps`:
```
   Johboh/HomeAssistantEntities@^7.0.5
```
#### Espressif IoT Development Framework:
In your existing `idf_component.yml` or in a new `idf_component.yml` next to your main component:
```
dependencies:
  johboh/HomeAssistantEntities:
    version: ">=7.0.5"
```

### Examples
- [Arduino: Sensors](examples/arduino/sensors/Sensors.ino)
- [Arduino: Actuators](examples/arduino/actuators/Actuators.ino)
- [ESP-IDF: Sensors](examples/espidf/sensors/main/main.cpp)
- [ESP-IDF: Actuators](examples/espidf/actuators/main/main.cpp)

### Functionallity verified on the following platforms and frameworks
- ESP32 (tested with PlatformIO [espressif32@6.4.0](https://github.com/platformio/platform-espressif32) / [arduino-esp32@2.0.11](https://github.com/espressif/arduino-esp32) / [ESP-IDF@4.4.6](https://github.com/espressif/esp-idf) / [ESP-IDF@5.1.2](https://github.com/espressif/esp-idf) on ESP32-S2 and ESP32-C3)
- ESP8266 (tested with PlatformIO [espressif8266@4.2.1](https://github.com/platformio/platform-espressif8266) / [ardunio-core@3.1.2](https://github.com/esp8266/Arduino))

Newer version most probably work too, but they have not been verified.

### Dependencies
- https://github.com/Johboh/nlohmann-json @^3.11.3
- *An MQTT implementation is required.* There is a copy of [IMQTTRemote](https://github.com/Johboh/MQTTRemote/blob/main/includes/IMQTTRemote.h) in this library from [Johboh/MQTTRemote](https://github.com/Johboh/MQTTRemote). You can either add a dependency on [MQTTRemote](https://github.com/Johboh/MQTTRemote) to get a fully working MQTT client (the examples are using this dependency), or you can implement/adapt/forward to your own MQTT implementation. This library only depend on the [IMQTTRemote](https://github.com/Johboh/MQTTRemote/blob/main/includes/IMQTTRemote.h) interface.
- Needs C++17 for `std::optional`.
  - For PlatformIO in `platformio.ini`:
    ```C++
    build_unflags=-std=gnu++11 # "Disable" C++11
    build_flags=-std=gnu++17 # "Enable" C++17
    ```
