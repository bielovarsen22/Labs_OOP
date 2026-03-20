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

    cout << "<--------------------------------------------------------------->\n";
    cout << "                            Copy                                 \n";

    Transport t2 = t1;
    t2.printInfo();
    Driver d2 = d1;
    d1.printInfo();
    Route r2 = r1;
    r1.printInfo();


    cout << "<--------------------------------------------------------------->\n";
    cout << "                            Move                                 \n";

    Transport t3 = move(t1);
    t3.printInfo();
    Driver d3 = move(d1);
    d3.printInfo();
    Route r3 = move(r1);
    r3.printInfo();

    cout << "<--------------------------------------------------------------->\n";
    cout << "                             this                                 \n";

    t3.drive(10);
    t3.refuel(20);
    t3.printInfo();
    d3.exp(10);
    d3.printInfo();
    r3.Routes(100);
    r3.printInfo();

    cout << "<--------------------------------------------------------------->\n";
    cout << "                             Const                                 \n";

    const Transport t4("Audi", "A6", 2010, 12000, 70);
    t4.printInfo();
    const Driver d4("Petro", 6, "AB654321");
    d4.printInfo();
    const Route r4("Odesha", "Lviv", 640);
    r4.printInfo();

    cout << "<--------------------------------------------------------------->\n";
    cout << "                             operator+                                 \n";

    Transport t5("Toyota", "Camry", 2015, 8000, 65);
    t5.printInfo();
    Transport t6 = t3 + t5;
    t6.printInfo();

    Driver d5 = d3 + d4;
    d5.printInfo();

    Route r5 = r3 + r4;
    r5.printInfo();

    cout << "<--------------------------------------------------------------->\n";
    cout << "                             operator-                                 \n";
    Transport t7 = -t5;
    cout << t7 << endl;

    cout << "<--------------------------------------------------------------->\n";
    cout << "                             (>>,<<)                                \n";
    Transport t8;
    cin >> t8;
    cout << t8 << endl;

    Driver d6;
    cin >> d6;
    cout << d6 << endl;

    Route r6;
    cin >> r6;
    cout << r6 << endl;

    cout << "<--------------------------------------------------------------->\n";
    cout << "                             obj                                \n";
    Transport::showCount();
    Driver::showCount();
    Route::showCount();

    cout << "<--------------------------------------------------------------->\n";

    return 0;
}