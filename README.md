# RCCarLibrary Arduino Project Documentation

## Overview

The RCCarLibrary is an Arduino library designed to control a simple remote-controlled car using Bluetooth communication. This library allows you to control the car's movements, including forward, backward, left, and right turns, as well as stopping the car. You can integrate this library into your Arduino project to build your own remote-controlled car.

## Features

- Control the car's movements via Bluetooth commands.
- Adjustable speed control.
- Easy integration with Arduino projects.

## Usage

### Installation

1. Download the `RCCarLibrary` from the GitHub repository (insert link here).
2. Extract the library and place it in the Arduino libraries folder (usually located in `Documents/Arduino/libraries` on Windows or `~/Documents/Arduino/libraries` on macOS).

### Hardware Setup

To use the RCCarLibrary, you need to connect the hardware as follows:

- Connect the Bluetooth module to pins 12 (TX) and 13 (RX).
- Connect the front motor pins to the appropriate motor driver pins.
- Connect the back motor pins to the motor driver pins.
- Optionally, connect speed control pins to pins 12 and 14 for PWM speed control.

### Arduino Sketch

```cpp
#include <RCCarLibrary.h>

RCCar car = RCCar();

void setup()
{
    car.setFrontMotorPin(FRONT_LEFT_PIN, FRONT_RIGHT_PIN);
    car.setBackMotorPin(BACK_LEFT_PIN, BACK_RIGHT_PIN);
    car.setSpeedPin(SPEED_LEFT_PIN, SPEED_RIGHT_PIN);
    car.setSpeedMotor(DEFAULT_SPEED);
}

void loop()
{
    car.process();
}
```

- Include the `RCCarLibrary` at the beginning of your Arduino sketch.
- Create an instance of the `RCCar` class.
- Set the pins for the front and back motors and, if applicable, the speed control pins.
- Set the initial speed using `setSpeedMotor`.
- In the `loop` function, call `car.process()` to listen for Bluetooth commands and control the car accordingly.

### Bluetooth Commands

You can control the car using the following Bluetooth commands:

- 'T' - Move forward.
- 'B' - Move backward.
- 'L' - Turn left.
- 'R' - Turn right.
- 'S' - Stop the car.

## Customization

You can customize this library to fit your specific hardware setup or requirements. You may need to modify the pin assignments, speed settings, or add additional functionality to suit your project.

## Contributing

Contributions to this project are welcome. If you have suggestions, bug reports, or want to add new features, please open an issue or submit a pull request on the GitHub repository.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
