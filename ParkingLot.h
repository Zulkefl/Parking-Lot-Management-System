#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "ParkingSlot.h"

class ParkingLot {
private:
    ParkingSlot** slots;
    int totalSlots;
    static int totalVehiclesParked;

public:
    ParkingLot(int size);
    ~ParkingLot();
    void parkVehicle();
    void removeVehicle();
    void displayParkingStatus();
    void showParkingHistory();
    void clearParkingHistory();

};

#endif
