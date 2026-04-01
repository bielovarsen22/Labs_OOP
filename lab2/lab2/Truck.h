#ifndef TRUCK_H
#define TRUCK_H

#include "Car.h"
#include "Trailer.h"

class Truck : public Car
{
private:
    Trailer trailer;
    double maxLoad;

public:
    Truck();
    Truck(string brand, string model, int year,
        double mileage, double fuel,
        int seats, double engineVolume,
        double maxLoad);

    ~Truck();

    void printTruckInfo() const;
};

#endif