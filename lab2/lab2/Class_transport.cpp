#include <iostream>
#include "Class_transport.h"

using namespace std;


int Transport::count = 0;


Transport::Transport()
    : Transport("Unknown", "Unknown", 0, 0.0, 0.0)
{
}

Transport::Transport(string brand, string model, int year, double mileage, double fuel)
    : brand(brand), model(model), year(year), mileage(mileage), fuel(fuel)
{
    count++;
}

Transport::Transport(string brand, string model)
    : Transport(brand, model, 2022, 0.0, 50.0)
{
}


Transport::Transport(const Transport& other)
{
    brand = other.brand;
    model = other.model;
    year = other.year;
    mileage = other.mileage;
    fuel = other.fuel;

    count++;
}


Transport::Transport(Transport&& other)
{
    brand = move(other.brand);
    model = move(other.model);
    year = other.year;
    mileage = other.mileage;
    fuel = other.fuel;

    count++;
}


Transport::~Transport()
{
    count--;
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

void Transport::setMileage(double mileage)
{
    this->mileage = mileage;
}


void Transport::showCount()
{
    cout << "Number of Transport objects: " << count << endl;
}


Transport Transport::operator+(const Transport& other)
{
    return Transport(
        brand,
        model,
        year,
        mileage + other.mileage,
        fuel + other.fuel
    );
}


Transport Transport::operator++()
{
    return Transport(
        brand,
        model,
        year,
        mileage,
        ++fuel
    );
}


ostream& operator<<(ostream& out, const Transport& t)
{
    out << t.brand << " " << t.model << " "
        << t.year << " " << t.mileage << " " << t.fuel;
    return out;
}


istream& operator>>(istream& in, Transport& t)
{
    cout << "Enter brand model year mileage fuel: ";
    in >> t.brand >> t.model >> t.year >> t.mileage >> t.fuel;
    return in;
}

Transport& Transport::operator=(const Transport& other)
{
    if (this != &other)
    {
        brand = other.brand;
        model = other.model;
        year = other.year;
        mileage = other.mileage;
        fuel = other.fuel;
    }
    return *this;
}