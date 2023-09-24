#include <Arduino.h>
#include <SoftwareSerial.h>

#ifndef RCCARLIBRARY_H
#define RCCARLIBRARY_H

#define enable 0x01
#define disable 0x0
#define defaultSpeed 255
class RCCar
{
public:
    RCCar();
    void setFrontMotorPin(int l_pin, int r_pin);
    void setBackMotorPin(int l_pin, int r_pin);

    void setSpeedPin(int sp_l_pin, int sp_r_pin);
    void setSpeedMotor(int speed);

    void process();

private:
    int fl_pin, fr_pin;
    int bl_pin, br_pin;

    int sp_l_pin, sp_r_pin;

    int _speed;

    void _toRight();
    void _toLeft();
    void _backward();
    void _forward();
    void _stop();

    void _initSpeed(bool isForward = true);
    void _stopSpeed();
};
#endif