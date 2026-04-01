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

void Truck::printTruckInfo() const
{
    printCarInfo();
    cout << "Max load: " << maxLoad << " kg\n";
    trailer.show();
}