#include <Arduino.h>
#include <SoftwareSerial.h>

#ifndef RCCARLIBRARY_H
#define RCCARLIBRARY_H

#define enable 0x01
#define disable 0x0
#define defaultSpeed 255

#define TX 12
#define RX 13
class RCCar
{
public:
    RCCar();
    void setFrontMotorPin(uint8_t l_pin, uint8_t r_pin);
    void setBackMotorPin(uint8_t l_pin, uint8_t r_pin);

    void setSpeedPin(uint8_t l_pin, uint8_t r_pin);
    void setSpeedMotor(uint8_t speed);

    void process();

private:
    uint8_t fl_pin, fr_pin;
    uint8_t bl_pin, br_pin;

    uint8_t sp_l_pin, sp_r_pin;

    uint8_t _speed;

    void _toRight();
    void _toLeft();
    void _backward();
    void _forward();
    void _stop();

    void _initSpeed(bool isForward = true);
    void _stopSpeed();
};
#endif