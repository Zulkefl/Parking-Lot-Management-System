#include "ParkingLot.h"
#include <iostream>
#include <fstream>
using namespace std;

int ParkingLot::totalVehiclesParked = 0;

ParkingLot::ParkingLot(int size) {
    totalSlots = size;
    slots = new ParkingSlot * [totalSlots];
    for (int i = 0; i < totalSlots; i++) {
        slots[i] = new ParkingSlot(i + 1);
    }
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < totalSlots; i++) {
        delete slots[i];
    }
    delete[] slots;
}

void ParkingLot::clearParkingHistory() {
    ofstream file("ParkingData.txt", ios::trunc);
    file.close();
    cout << "Parking history cleared.\n";
}


void ParkingLot::parkVehicle() {
    string number;
    int hour, choice;

    cout << "Enter Vehicle Number: ";
    cin >> number;
    cout << "Enter Entry Time (Hour 0-23): ";
    cin >> hour;

    cout << "Select Vehicle Type:\n1. Car\n2. Bike\n3. Truck\nChoice: ";
    cin >> choice;

    Vehicle* v = nullptr;
    switch (choice) {
    case 1: v = new Car(number, hour); break;
    case 2: v = new Bike(number, hour); break;
    case 3: v = new Truck(number, hour); break;
    default: cout << "Invalid choice!\n"; return;
    }

    for (int i = 0; i < totalSlots; i++) {
        if (!slots[i]->getIsOccupied()) {
            slots[i]->parkVehicle(v);
            totalVehiclesParked++;
            return;
        }
    }

    cout << "Parking Lot is FULL! No space available.\n";
    delete v;
}

void ParkingLot::removeVehicle() {
    int slotNum, exitHour;
    cout << "Enter Slot Number to Remove Vehicle: ";
    cin >> slotNum;
    if (slotNum < 1 || slotNum > totalSlots) {
        cout << "Invalid Slot Number.\n";
        return;
    }

    cout << "Enter Exit Time (Hour 0-23): ";
    cin >> exitHour;

    if (slots[slotNum - 1]->getIsOccupied()) {
        slots[slotNum - 1]->removeVehicle(exitHour);
        totalVehiclesParked--;
    }
    else {
        cout << "Slot is already empty.\n";
    }
}

void ParkingLot::displayParkingStatus() {
    cout << "\n--- Parking Lot Status ---\n";
    for (int i = 0; i < totalSlots; i++) {
        slots[i]->displaySlotDetails();
    }
    cout << "Total Vehicles Parked: " << totalVehiclesParked << endl;
}

void ParkingLot::showParkingHistory() {
    ifstream file("ParkingData.txt");
    string line;
    cout << "\n--- Parking Lot History ---\n";
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "No parking history found.\n";
    }
}