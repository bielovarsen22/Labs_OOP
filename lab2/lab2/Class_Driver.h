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

    static int count;

public:
    Driver();
    Driver(string name, int experience, string licenseNumber);
    Driver(string name);

    Driver(const Driver& other);   
    Driver(Driver&& other);

    ~Driver();

    void changeExperience(int years);
    void exp(double exp);
    void printInfo() const;

    void setExperience(double experience);

    static void showCount();

    Driver operator+(const Driver& other);

    friend ostream& operator<<(ostream& out, const Driver& d);
    friend istream& operator>>(istream& in, Driver& d);


};

#endif