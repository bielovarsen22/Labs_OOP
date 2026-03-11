#include <iostream>
#include "Class_Route.h"

using namespace std;

Route::Route()
    : Route("Unknown", "Unknown", 0.0) {
}

Route::Route(string startPoint, string endPoint, double distance)
    : startPoint(startPoint), endPoint(endPoint), distance(distance) {
}

Route::Route(string startPoint, string endPoint)
    : Route(startPoint, endPoint, 100.0) {
}

Route::~Route()
{
    cout << "Route destroyed\n";
}

void Route::changeDistance(double newDistance)
{
    distance = newDistance;
}

void Route::printInfo() const
{
    cout << "Route: " << startPoint
        << " -> " << endPoint
        << " | Distance: " << distance << " km" << endl;
}