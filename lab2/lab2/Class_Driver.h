#ifndef CLASS_DRIVER_H
#define CLASS_DRIVER_H

#include <string>
using namespace std;

class Driver
{
private:
    string name;
    int experience;
    string licenseNumber;

public:
    Driver();
    Driver(string name, int experience, string licenseNumber);
    Driver(string name);
    ~Driver();

    void changeExperience(int years);
    void printInfo() const;
};

#endif