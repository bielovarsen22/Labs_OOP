#ifndef CLASS_TRANSPORT_H
#define CLASS_TRANSPORT_H

#include <string>
using namespace std;


class Transport
{
private:
    string brand;
    string model;
    int year;
    double mileage;
    double fuel;

public:
    Transport();
    Transport(string brand, string model, int year, double mileage, double fuel);
    Transport(string brand, string model);
    ~Transport();

    void refuel(double amount);
    void drive(double distance);
    void printInfo() const;
};
#endif