#include "Car.h"

Car::Car()
    : Transport(), seats(5), engine(1.6)
{
}

Car::Car(string brand, string model, int year,
    double mileage, double fuel,
    int seats, double engineVolume)
    : Transport(brand, model, year, mileage, fuel),
    seats(seats),
    engine(engineVolume)
{
}

Car::Car(const Car& other)
    : Transport(other),
    seats(other.seats),
    engine(other.engine)
{
}

Car::Car(Car&& other)
    : Transport(move(other)),
    seats(other.seats),
    engine(other.engine)
{
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        Transport::operator=(other);
        seats = other.seats;
        engine = other.engine;
    }
    return *this;
}

Car::~Car()
{
    cout << "Car destroyed\n";
}

void Car::printCarInfo() const
{
    printInfo();
    cout << "Seats: " << seats << endl;
    engine.show();
}