#include <iostream>
#include "Class_Driver.h"

using namespace std;

Driver::Driver()
    : Driver("Unknown", 0, "None") {
}

Driver::Driver(string name, int experience, string licenseNumber)
    : name(name), experience(experience), licenseNumber(licenseNumber) {
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

void Driver::printInfo() const
{
    cout << "Driver: " << name
        << " | Experience: " << experience
        << " | License: " << licenseNumber << endl;
}
