#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

#include "Car.h"
#include "Truck.h"

using namespace std;



void saveDatabase(const vector<unique_ptr<Transport>>& catalog) {
    ofstream out("database.txt");
    if (!out) throw runtime_error("Could not open file for writing!");

    for (const auto& item : catalog) {
        
        if (dynamic_cast<Truck*>(item.get())) out << "TRUCK: ";
        else if (dynamic_cast<Car*>(item.get())) out << "CAR: ";
        else out << "T ";

        out << *item << endl; 
    }
}

void loadDatabase(vector<unique_ptr<Transport>>& catalog) {
    ifstream in("database.txt");
    if (!in) return; 

    string type;
    while (in >> type) {
        unique_ptr<Transport> ptr;
        if (type == "TRUCK:") ptr = make_unique<Truck>();
        else if (type == "CAR:") ptr = make_unique<Car>();
        else ptr = make_unique<Transport>();

        in >> *ptr; 
        catalog.push_back(move(ptr));
    }
}

void logAction(const string& message) {
    ofstream log("history.txt", ios::app);
    if (log) log << message << endl;
}



void adminMenu(vector<unique_ptr<Transport>>& catalog) {
    int choice;
    while (true) {
        cout << "\n--- ADMINISTRATOR MENU ---\n";
        cout << "1. Add a car (Car)\n";
        cout << "2. Add a truck (Truck)\n";
        cout << "3. View the database\n";
        cout << "0. Back\nChoice: ";
        cin >> choice;

        try {
            if (choice == 0) break;
            if (choice == 1) {
                auto c = make_unique<Car>();
                cin >> *c;
                catalog.push_back(move(c));
                logAction("Admin added a car.");
            }
            else if (choice == 2) {
                auto t = make_unique<Truck>();
                cin >> *t;
                catalog.push_back(move(t));
                logAction("Admin added a truck.");
            }
            else if (choice == 3) {
                for (const auto& item : catalog) item->printInfo();
            }
            saveDatabase(catalog);
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void userMenu(const vector<unique_ptr<Transport>>& catalog) {
    int choice;
    while (true) {
        cout << "\n--- USER MENU ---\n";
        cout << "1. View products\n";
        cout << "2. Buy (test drive)\n";
        cout << "0. Back\nChoice: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice == 1) {
            if (catalog.empty()) cout << "The store is empty.\n";
            for (const auto& item : catalog) item->printInfo();
        }
        else if (choice == 2) {
            cout << "You have chosen transport\n";
            logAction("User viewed transport");
        }
    }
}

int main() {
    vector<unique_ptr<Transport>> catalog;

    try {
        loadDatabase(catalog);
    }
    catch (...) {
        cout << "Error loading database.\n";
    }

    int role;
    while (true) {
        cout << "\n=== SHOP TRANSPORT SYSTEM ===\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as user\n";
        cout << "0. Exit\nChoice: ";
        if (!(cin >> role)) break;

        if (role == 0) break;

        if (role == 1) {
            string pass;
            cout << "Password: ";
            cin >> pass;
            if (pass == "admin") adminMenu(catalog);
            else cout << "Incorrect password!\n";
        }
        else if (role == 2) {
            userMenu(catalog);
        }
    }

    cout << "The program is complete. The data is saved.\n";
    return 0;
}