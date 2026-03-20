#include <iostream>
#include "Class_Route.h"

using namespace std;

int Route::count = 0;

Route::Route()
    : Route("Unknown", "Unknown", 0.0) {
}

Route::Route(string startPoint, string endPoint, double distance)
    : startPoint(startPoint), endPoint(endPoint), distance(distance) {
    count++;
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

Route::Route(const Route& other)
{
    startPoint = other.startPoint;
    endPoint = other.endPoint;
    distance = other.distance;

    count++;
}

Route::Route(Route&& other)
{
    startPoint = move(other.startPoint);
    endPoint = move(other.endPoint);
    distance = other.distance;

    count++;
}

void Route::setDistance(double distance)
{
    this->distance = distance;
}

void Route::Routes(double distan)
{
    distance += distan;
}

void Route::showCount()
{
    cout << "Number of Route objects: " << count << endl;
}

Route Route::operator+(const Route& other)
{
    return Route(
        startPoint,
        endPoint,
        distance + other.distance
    );
}

ostream& operator<<(ostream& out, const Route& r)
{
    out << r.startPoint << " " << r.endPoint << " "
        << r.distance;
    return out;
}

istream& operator>>(istream& in, Route& r)
{
    cout << "Enter startPoint, endPoint, distance : ";
    in >> r.startPoint >> r.endPoint >>r.distance;
    return in;
}