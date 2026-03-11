#include <iostream>
#include "Class_transport.h"
#include "Class_Driver.h"

using namespace std;

int main()
{
    Transport t1("BMW", "M3", 2005, 10000, 60);
    Driver d1("Ivan Petrenko", 5, "AB123456");
   
    t1.printInfo();
    d1.printInfo();

    return 0;
}