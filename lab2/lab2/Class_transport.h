#ifndef CLASS_TRANSPORT_H
#define CLASS_TRANSPORT_H

#include <string>
#include <iostream>
using namespace std;


class Transport
{
private:
    string brand;
    string model;
    int year;
    double mileage;
    double fuel;

    static int count;

public:
    Transport();
    Transport(string brand, string model, int year, double mileage, double fuel);
    Transport(string brand, string model);

    Transport(const Transport& other);   
    Transport(Transport&& other);        

    virtual ~Transport();

    Transport& operator=(const Transport& other);

    void refuel(double amount);
    void drive(double distance);
    void printInfo() const;

    
    void setMileage(double mileage);

    
    static void showCount();

    
    Transport operator+(const Transport& other);
    Transport operator++();

    
    friend ostream& operator<<(ostream& out, const Transport& t);
    friend istream& operator>>(istream& in, Transport& t);
};

#endif