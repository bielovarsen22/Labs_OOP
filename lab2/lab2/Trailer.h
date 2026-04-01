#ifndef TRAILER_H
#define TRAILER_H

#include <iostream>
using namespace std;

class Trailer
{
private:
    double loadCapacity;

public:
    Trailer(double loadCapacity = 5000)
        : loadCapacity(loadCapacity) {
    }

    void show() const
    {
        cout << "Trailer capacity: " << loadCapacity << " kg\n";
    }
};

#endif