#include "RCCarLibrary.h"

SoftwareSerial bt(TX, RX);

RCCar::RCCar()
{
    _speed = defaultSpeed;
}

void RCCar::setFrontMotorPin(uint8_t l_pin, uint8_t r_pin)
{
}

void RCCar::setBackMotorPin(uint8_t l_pin, uint8_t r_pin)
{
}

void RCCar::setSpeedPin(uint8_t sp_l_pin, uint8_t sp_r_pin)
{
}

void RCCar::setSpeedMotor(uint8_t speed)
{
    if (speed <= 500)
    {
        _speed = speed;
    }
}

void RCCar::_initSpeed(bool isForward = true)
{
    if (isForward)
    {
        analogWrite(sp_l_pin, _speed);
        analogWrite(sp_r_pin, _speed);
    }
    analogWrite(sp_l_pin, 200);
    analogWrite(sp_r_pin, 200);
}

void RCCar::_stopSpeed()
{
    analogWrite(sp_l_pin, disable);
    analogWrite(sp_r_pin, disable);
}
void RCCar::_toRight()
{
    _initSpeed();
}
void RCCar::_toLeft()
{
    _initSpeed();
}
void RCCar::_backward()
{
    _initSpeed(false);
}
void RCCar::_forward()
{
    _initSpeed();
}
void RCCar::_stop()
{
    digitalWrite(fl_pin, enable);
    digitalWrite(fr_pin, enable);
    digitalWrite(bl_pin, enable);
    digitalWrite(br_pin, enable);
    _stopSpeed();
}

void RCCar::process()
{
    if (bt.available())
    {
        char value = bt.read();
        Serial.println(value);

        switch (value)
        {
        case 'T':
            _forward();
            break;
        case 'B':
            _backward();
            break;
        case 'L':
            _toLeft();
            break;
        case 'R':
            _toRight();
            break;
        case 'S':
            _stop();
        default:
            Serial.println("Value is not match");
            break;
        }
    }
}