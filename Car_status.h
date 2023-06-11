
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>


// #include "Car_class.h"

using namespace std;

// Print car status which are available
void printCarStatus_Available(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "No cars available." << endl;
        return;
    }

    bool availableCarsPresent = false;


    ofstream displayFile("display.txt", ios::trunc); // Print car status to display.txt file
    // Check if available cars exist
    for (const Car& car : cars) {
        if (car.isAvailable()) {
            availableCarsPresent = true;
            break;
        }
    }

    // Print available cars with detailed info
    displayFile << "Available cars with detailed info:" << endl;
    displayFile << "---------------------------------" << endl;
    if (availableCarsPresent) {
        int i = 0;
        for (const Car& car : cars) {
            if (car.isAvailable()) {
                i+=1;
                displayFile << i << ". " ;
                displayFile << "License Plate: " << car.getLicensePlate() << endl;
                displayFile << "Brand: " << car.getBrand() << endl;
                displayFile << "Model: " << car.getModel() << endl;
                displayFile << "Color: " << car.getColor() << endl;
                displayFile << "Manufacturing Day: " << car.getManufacturingDay().day << "-" << car.getManufacturingDay().month << "-" << car.getManufacturingDay().year << endl;
                displayFile << endl;
            }
        }
        cout << endl;
    }
    else {
        displayFile << "No cars available." << endl;
    }

    displayFile.close();
}

// Print car status which are unavailable

void printCarStatus_Unavailable(const vector<Car>& cars, const vector<Customer>& customers) {
    if (cars.empty()) {
        cout << "You have no cars" << endl;
        return;
    }

    bool unavailableCarsPresent = false;

    ofstream displayFile("display.txt", ios::trunc); // Print car status to display.txt file

    // Check if unavailable cars exist
    for (const Car& car : cars) {
        if (!car.isAvailable()) {
            unavailableCarsPresent = true;
            break;
        }
    }

    // Print unavailable cars with detailed info and customer details
    displayFile << "Unavailable cars with detailed info and customer details:" << endl;
    displayFile << "----------------------------------------------------" << endl;
    if (unavailableCarsPresent) {
        int i = 0;
        for (const Car& car : cars) {
            if (!car.isAvailable()) {
                i+=1;
                displayFile << i << ". " ;
                displayFile << "License Plate: " << car.getLicensePlate() << endl;
                displayFile << "Brand: " << car.getBrand() << endl;
                displayFile << "Model: " << car.getModel() << endl;
                displayFile << "Color: " << car.getColor() << endl;
                displayFile << "Manufacturing Day: " << car.getManufacturingDay().day << "-" << car.getManufacturingDay().month << "-" << car.getManufacturingDay().year << endl;
                displayFile << "--------" << endl;
                displayFile << "Customer Details:" << endl;

                // Find the customer information for the current car
                auto customer = find_if(customers.begin(), customers.end(), [&](const Customer& c) {
                    return c.getLicensePlate() == car.getLicensePlate();
                });

                if (customer != customers.end()) {
                    displayFile << "Name: " << customer->getName() << endl;
                    displayFile << "Age: " << customer->getAge() << endl;
                    displayFile << "Phone Number: " << customer->getPhoneNumber() << endl;
                    displayFile << "Citizenship ID: " << customer->getCitizenshipID() << endl;
                }

                displayFile << endl;
            }
        }
        cout << endl;
    } else {
        displayFile << "No cars unavailable." << endl;
    }

    displayFile.close();
}

// int main() {
//     vector<Car> cars = loadCars();

//     int choice;
//     cout << "Chose status to print:\n";
//     cout << "1. Available cars\n";
//     cout << "2. Unavailable cars\n";
//     cin >> choice;
//     if (choice == 1) printCarStatus_Available(cars);
//     else if (choice == 2) printCarStatus_Unavailable(cars);
//     else {
//         cout << "Invalid choice." << endl;
//     }
//     system("start notepad.exe display.txt");
// }

