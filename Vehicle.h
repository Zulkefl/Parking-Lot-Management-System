#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleNumber;
    int entryHour;

public:
    Vehicle(string number, int hour);
    virtual ~Vehicle();

    string getVehicleNumber();
    virtual float calculateParkingFee(int exitHour) = 0;
    virtual void displayDetails();
};

class Car : public Vehicle {
public:
    Car(string number, int hour);
    float calculateParkingFee(int exitHour) override;
};

class Bike : public Vehicle {
public:
    Bike(string number, int hour);
    float calculateParkingFee(int exitHour) override;
};

class Truck : public Vehicle {
public:
    Truck(string number, int hour);
    float calculateParkingFee(int exitHour) override;
};

#endif
