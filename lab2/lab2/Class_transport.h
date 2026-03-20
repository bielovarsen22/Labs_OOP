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

    // 🔥 Конструктори
    Transport(const Transport& other);   // copy
    Transport(Transport&& other);        // move

    ~Transport();

    void refuel(double amount);
    void drive(double distance);
    void printInfo() const;

    // this
    void setMileage(double mileage);

    // static
    static void showCount();

    // оператори
    Transport operator+(const Transport& other);
    Transport operator-();

    // потоки
    friend ostream& operator<<(ostream& out, const Transport& t);
    friend istream& operator>>(istream& in, Transport& t);
};

#endif