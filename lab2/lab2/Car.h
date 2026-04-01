#ifndef CAR_H
#define CAR_H

#include "Class_transport.h"
#include "Engine.h"

class Car : public Transport
{
protected:
    int seats;
    Engine engine;

public:
    Car();
    Car(string brand, string model, int year,
        double mileage, double fuel,
        int seats, double engineVolume);

    Car(const Car& other);
    Car(Car&& other);

    Car& operator=(const Car& other);

    virtual ~Car();

    void printCarInfo() const;
};

#endif