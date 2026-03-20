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

    static int count;

public:
    Route();
    Route(string startPoint, string endPoint, double distance);
    Route(string startPoint, string endPoint);

    Route(const Route& other);   
    Route(Route&& other);

    ~Route();

    void changeDistance(double newDistance);
    void Routes(double distan);
    void printInfo() const;

    void setDistance(double distance);

    static void showCount();

    Route operator+(const Route& other);

    friend ostream& operator<<(ostream& out, const Route& r);
    friend istream& operator>>(istream& in, Route& r);
};

#endif