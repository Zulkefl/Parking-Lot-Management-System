#include "Vehicle.h"

Vehicle::Vehicle(string number, int hour) {
    vehicleNumber = number;
    entryHour = hour;
}

Vehicle::~Vehicle() {}

string Vehicle::getVehicleNumber() {
    return vehicleNumber;
}

void Vehicle::displayDetails() {
    cout << "Vehicle Number: " << vehicleNumber << endl;
    cout << "Entry Time (Hour): " << entryHour << endl;
}

Car::Car(string number, int hour) : Vehicle(number, hour) {}

float Car::calculateParkingFee(int exitHour) {
    int hours = exitHour - entryHour;
    if (hours <= 0) hours = 1;
    return hours * 50.0;
}

Bike::Bike(string number, int hour) : Vehicle(number, hour) {}

float Bike::calculateParkingFee(int exitHour) {
    int hours = exitHour - entryHour;
    if (hours <= 0) hours = 1;
    return hours * 20.0;
}

Truck::Truck(string number, int hour) : Vehicle(number, hour) {}

float Truck::calculateParkingFee(int exitHour) {
    int hours = exitHour - entryHour;
    if (hours <= 0) hours = 1;
    return hours * 100.0;
}