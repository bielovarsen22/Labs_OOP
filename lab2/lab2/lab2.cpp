#include <iostream>
#include "Car.h"
#include "Truck.h"

using namespace std;

int main()
{
    cout << "================ CAR =================\n";

    Car car1("BMW", "M3", 2020, 15000, 60, 5, 3.0);
    car1.printCarInfo();

    cout << "\n================ COPY =================\n";

    Car car2 = car1; // copy constructor
    car2.printCarInfo();

    cout << "\n================ MOVE =================\n";

    Car car3 = move(car1); // move constructor
    car3.printCarInfo();

    cout << "\n================ ASSIGNMENT =================\n";

    Car car4;
    car4 = car3; // operator=
    car4.printCarInfo();

    cout << "\n================ OPERATORS =================\n";

    Transport t1("Audi", "A6", 2018, 10000, 50);
    Transport t2("Toyota", "Camry", 2017, 8000, 40);

    Transport t3 = t1 + t2;
    t3.printInfo();

    Transport t4 = ++t1;
    t4.printInfo();

    cout << "\n================ TRUCK =================\n";

    Truck truck1("Volvo", "FH16", 2022,
        250000, 300,
        2, 12.8, 20000);

    truck1.printTruckInfo();

    cout << "\n================ COPY TRUCK =================\n";

    Truck truck2 = truck1;
    truck2.printTruckInfo();

    cout << "\n================ MOVE TRUCK =================\n";

    Truck truck3 = move(truck1);
    truck3.printTruckInfo();

    cout << "\n================ INPUT / OUTPUT =================\n";

    Transport t5;
    cin >> t5;
    cout << t5 << endl;

    cout << "\n================ OBJECT COUNT =================\n";
    Transport::showCount();

    cout << "\n================ END PROGRAM =================\n";

    return 0;
}