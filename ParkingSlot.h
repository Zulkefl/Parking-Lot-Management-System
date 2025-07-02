#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include "Vehicle.h"

class ParkingSlot {
private:
    int slotNumber;
    bool isOccupied;
    Vehicle* parkedVehicle;

public:
    ParkingSlot(int num);
    ~ParkingSlot();

    bool getIsOccupied();
    void parkVehicle(Vehicle* v);
    void removeVehicle(int exitHour);
    void displaySlotDetails();
};

#endif
