#include "Truck.h"

Truck::Truck()
    : Car(), trailer(5000), maxLoad(5000)
{
}

Truck::Truck(string brand, string model, int year,
    double mileage, double fuel,
    int seats, double engineVolume,
    double maxLoad)
    : Car(brand, model, year, mileage, fuel, seats, engineVolume),
    trailer(maxLoad),
    maxLoad(maxLoad)
{
}

Truck::~Truck()
{
    cout << "Truck destroyed\n";
}

void Truck::printInfo() const
{
    Car::printInfo();
    cout << "Max load: " << maxLoad << " kg\n";
    trailer.show();
}

double Truck::getEfficiency() const
{
    return 50.0 / maxLoad; // умовно
}