#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
using namespace std;

class Engine
{
private:
    double volume;

public:
    Engine(double volume = 1.6) : volume(volume) {}

    void show() const
    {
        cout << "Engine volume: " << volume << "L\n";
    }
};

#endif