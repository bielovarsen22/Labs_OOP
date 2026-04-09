#include <iostream>
#include "Car.h"
#include "Truck.h"

using namespace std;

void show(const Transport& t)
{
    t.printInfo();
    t.moves();
}

int main()
{
    cout << "================ CAR =================\n";

    Car car1("BMW", "M3", 2020, 15000, 60, 5, 3.0);
    car1.printInfo();

    cout << "\n===== POLYMORPHISM =====\n";

    Transport* t;

    t = new Car("Audi", "A4", 2019, 12000, 55, 5, 2.0);
    t->printInfo(); // Car

    show(*t);

    t = new Truck("MAN", "TGX", 2021, 200000, 400, 2, 12.0, 18000);
    t->printInfo(); // Truck

    show(*t);

    delete t;

    cout << "\n================ END PROGRAM =================\n";

    return 0;
}