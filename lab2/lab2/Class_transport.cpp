#include <iostream>
#include "Class_transport.h"

using namespace std;


Transport::Transport()
    : Transport("Unknown", "Unknown", 0, 0.0, 0.0) {
}

Transport::Transport(string brand, string model, int year, double mileage, double fuel)
    : brand(brand), model(model), year(year), mileage(mileage), fuel(fuel) {
}

Transport::Transport(string brand, string model)
    : Transport(brand, model, 2022, 0.0, 50.0) {
}

Transport::~Transport()
{
    cout << "Transport destroyed\n";
}

void Transport::refuel(double amount)
{
    fuel += amount;
}

void Transport::drive(double distance)
{
    mileage += distance;
    fuel -= distance * 0.1;
}

void Transport::printInfo() const
{
    cout << "Transport: " << brand << " " << model
        << " | Year: " << year
        << " | Mileage: " << mileage
        << " | Fuel: " << fuel << endl;
}