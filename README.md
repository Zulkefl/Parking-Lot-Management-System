# Parking Lot Management System - C++ (OOP Project)

This is my **3rd Semester Object-Oriented Programming (OOP) Project**, developed using C++. The project demonstrates how core OOP concepts and file handling can be applied to solve real-world problems like managing a parking lot.

## Project Overview

The Parking Lot Management System helps manage vehicle parking in a simple and efficient way. It allows you to park different types of vehicles, remove them, calculate parking fees, check the current status of the parking lot, and maintain a proper history of all parking activities using file handling.

The project is designed to be simple and easy to use through the terminal.

## Features

✔ Park different types of vehicles (Car, Bike, Truck)
✔ Remove vehicles and calculate parking fees based on parked time
✔ Check current parking lot status
✔ Parking history is stored in a file for future reference
✔ Option to clear parking history anytime during program execution\\

## Technologies Used

C++ programming language
Object-Oriented Programming (Classes, Inheritance, Polymorphism)
File handling using fstream
Terminal-based interface

## Project Structure

The project is divided into separate files to follow good coding practices:

Vehicle.h and Vehicle.cpp - Vehicle base class and derived classes for Car, Bike, and Truck
ParkingSlot.h and ParkingSlot.cpp - Handles individual parking slots
ParkingLot.h and ParkingLot.cpp - Manages the entire parking lot
main.cpp - Program starting point
ParkingData.txt - Stores all parking history

## Parking History File

The system automatically creates a file called `ParkingData.txt`. It stores:

* Details of parked vehicles
* When a vehicle is removed
* The calculated parking fee

You can view this file anytime to check the complete history. The file can also be cleared using the menu option in the program.

## Educational Purpose

This project was created as a part of my **3rd Semester OOP course**. It helped me understand:

* How to apply OOP concepts practically
* Class relationships and inheritance in C++
* How to use file handling effectively
* Developing a complete, working system using C++

## About Me

I am currently pursuing my BSCS degree and this is my 3rd semester project. I developed this system to improve my understanding of Object-Oriented Programming and practical C++ development.

If you like the project or want to learn from it, feel free to use it or modify it for your own learning.

## License

This project is created for learning and educational purposes only.
