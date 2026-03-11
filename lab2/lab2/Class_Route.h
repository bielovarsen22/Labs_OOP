#ifndef CLASS_ROUTE_H
#define CLASS_ROUTE_H

#include <string>
using namespace std;

class Route
{
private:
    string startPoint;
    string endPoint;
    double distance;

public:
    Route();
    Route(string startPoint, string endPoint, double distance);
    Route(string startPoint, string endPoint);
    ~Route();

    void changeDistance(double newDistance);
    void printInfo() const;
};

#endif