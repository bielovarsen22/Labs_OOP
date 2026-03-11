#include <iostream>
#include "Class_transport.h"
#include "Class_Driver.h"
#include "Class_Route.h"

using namespace std;

int main()
{
    Transport t1("BMW", "M3", 2005, 10000, 60);
    Driver d1("Ivan Petrenko", 5, "AB123456");
    Route r1("Kyiv", "Lviv", 540);

    t1.printInfo();
    d1.printInfo();
    r1.printInfo();

    return 0;
}