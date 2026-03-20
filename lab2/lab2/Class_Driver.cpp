#include <iostream>
#include "Class_Driver.h"

using namespace std;

int Driver::count = 0;

Driver::Driver()
    : Driver("Unknown", 0, "None") {
}

Driver::Driver(string name, int experience, string licenseNumber)
    : name(name), experience(experience), licenseNumber(licenseNumber)
{
    count++;
}

Driver::Driver(string name)
    : Driver(name, 1, "Temporary") {
}

Driver::~Driver()
{
    cout << "Driver destroyed\n";
}

void Driver::changeExperience(int years)
{
    experience += years;
}
void Driver::exp(double exp) 
{
    experience += exp;
}
void Driver::printInfo() const
{
    cout << "Driver: " << name
        << " | Experience: " << experience
        << " | License: " << licenseNumber << endl;
}
Driver::Driver(const Driver& other)
{
    name = other.name;
    experience = other.experience;
    licenseNumber = other.licenseNumber;   

    count++;
}
Driver::Driver(Driver&& other)
{
    name = move(other.name);
    experience = other.experience;
    licenseNumber = other.licenseNumber;

    count++;
}
void Driver::setExperience(double experience)
{
    this->experience = experience;
}
void Driver::showCount()
{
    cout << "Number of Driver objects: " << count << endl;
}

Driver Driver::operator+(const Driver& other)
{
    return Driver(
        name,
        experience + other.experience,
        licenseNumber
    );
}
ostream& operator<<(ostream& out, const Driver& d)
{
    out << d.name << " " << d.experience<< " "
        << d.licenseNumber << " ";
    return out;
}


istream& operator>>(istream& in, Driver& d)
{
    cout << "Enter name, experience, licenseNumber : ";
    in >> d.name >> d.experience >> d.licenseNumber ;
    return in;
}