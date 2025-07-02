#include "ParkingSlot.h"
#include <iostream>
#include <fstream>
using namespace std;

ParkingSlot::ParkingSlot(int num) {
    slotNumber = num;
    isOccupied = false;
    parkedVehicle = nullptr;
}

ParkingSlot::~ParkingSlot() {
    if (parkedVehicle != nullptr) {
        delete parkedVehicle;
    }
}

bool ParkingSlot::getIsOccupied() {
    return isOccupied;
}

void ParkingSlot::parkVehicle(Vehicle* v) {
    parkedVehicle = v;
    isOccupied = true;
    cout << "Vehicle parked in Slot #" << slotNumber << endl;

    ofstream file("ParkingData.txt", ios::app);
    if (file.is_open()) {
        file << "PARKED - Slot #" << slotNumber << " - Vehicle: "
            << parkedVehicle->getVehicleNumber() << endl;
        file.close();
    }
}

void ParkingSlot::removeVehicle(int exitHour) {
    if (isOccupied && parkedVehicle != nullptr) {
        cout << "Vehicle Details:" << endl;
        parkedVehicle->displayDetails();
        float fee = parkedVehicle->calculateParkingFee(exitHour);
        cout << "Parking Fee: Rs." << fee << endl;

        ofstream file("ParkingData.txt", ios::app);
        if (file.is_open()) {
            file << "REMOVED - Slot #" << slotNumber << " - Vehicle: "
                << parkedVehicle->getVehicleNumber() << " - Exit Hour: "
                << exitHour << " - Fee: Rs." << fee << endl;
            file.close();
        }

        delete parkedVehicle;
        parkedVehicle = nullptr;
        isOccupied = false;

        cout << "Slot #" << slotNumber << " is now empty." << endl;
    }
    else {
        cout << "Slot is already empty." << endl;
    }
}

void ParkingSlot::displaySlotDetails() {
    cout << "Slot #" << slotNumber << " - ";
    if (isOccupied) {
        cout << "Occupied by Vehicle " << parkedVehicle->getVehicleNumber() << endl;
    }
    else {
        cout << "Empty" << endl;
    }
}
