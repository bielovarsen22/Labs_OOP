#include <iostream>
#include "Class_transport.h"

using namespace std;

// static змінна
int Transport::count = 0;

// конструктори
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

// copy constructor
Transport::Transport(const Transport& other)
{
    brand = other.brand;
    model = other.model;
    year = other.year;
    mileage = other.mileage;
    fuel = other.fuel;

    count++;
}

// move constructor
Transport::Transport(Transport&& other)
{
    brand = move(other.brand);
    model = move(other.model);
    year = other.year;
    mileage = other.mileage;
    fuel = other.fuel;

    count++;
}

// деструктор
Transport::~Transport()
{
    count--;
    cout << "Transport destroyed\n";
}

// методи
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

// this
void Transport::setMileage(double mileage)
{
    this->mileage = mileage;
}

// static метод
void Transport::showCount()
{
    cout << "Number of Transport objects: " << count << endl;
}

// оператор +
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

// оператор -
Transport Transport::operator-()
{
    return Transport(
        brand,
        model,
        year,
        mileage,
        -fuel
    );
}

// <<
ostream& operator<<(ostream& out, const Transport& t)
{
    out << t.brand << " " << t.model << " "
        << t.year << " " << t.mileage << " " << t.fuel;
    return out;
}

// >>
istream& operator>>(istream& in, Transport& t)
{
    cout << "Enter brand model year mileage fuel: ";
    in >> t.brand >> t.model >> t.year >> t.mileage >> t.fuel;
    return in;
}