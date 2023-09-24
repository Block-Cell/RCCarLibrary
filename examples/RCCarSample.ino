#include <RCCarLibrary.h>

RCCar car = RCCar();

void setup()
{
    car.setFrontMotorPin(12, 13);
    car.setBackMotorPin(12, 13);
    car.setSpeedPin(12,14);
    car.setSpeedMotor(300);
}
void loop()
{
    car.process();
}