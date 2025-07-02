#include "ParkingLot.h"
#include <iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream clearFile("ParkingData.txt", ios::trunc);
    clearFile.close();
    int size;
    cout << "Welcome to Parking Lot Management System!\n";
    cout << "Enter total number of parking slots: ";
    cin >> size;

    ParkingLot lot(size);
    int choice;

    do {
        cout << "\n----- Main Menu -----\n";
        cout << "1. Park a Vehicle\n";
        cout << "2. Remove a Vehicle\n";
        cout << "3. Show Parking Lot Status\n";
        cout << "4. Show Parking History\n";
        cout << "5. Clear Parking History\n"; 
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: lot.parkVehicle(); break;
        case 2: lot.removeVehicle(); break;
        case 3: lot.displayParkingStatus(); break;
        case 4: lot.showParkingHistory(); break;
        case 5: lot.clearParkingHistory(); break;
        case 6: cout << "Thank you! Exiting...\n"; break;
       
        default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
   

    return 0;
}
