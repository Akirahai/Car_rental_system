#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


// Print car details
void printCarDetails(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "No cars available." << endl;
        return;
    }
    
    // Print car details to console
    for (const Car& car : cars) {
        car.printDetails();
    }

    // Print car details to display.txt file
    ofstream displayFile("display.txt", ios::trunc);
    if (displayFile) {
        for (const Car& car : cars) {
            displayFile << "License Plate: " << car.getLicensePlate() << endl;
            displayFile << "Brand: " << car.getBrand() << endl;
            displayFile << "Model: " << car.getModel() << endl;
            displayFile << "Color: " << car.getColor() << endl;
            displayFile << "Manufacturing Day: " << car.getManufacturingDay().day << "-" << car.getManufacturingDay().month << "-" << car.getManufacturingDay().year << endl;
            displayFile << "Status: " << (car.isAvailable() ? "Available" : "Not Available") << endl;
            displayFile << endl;
        }
        displayFile.close();
    } else {
        cout << "Error: Unable to open display.txt file." << endl;
    }
}


// Print customers details
void printCustomerDetails(const vector<Customer>& customers, const vector<Car>& cars) {
    ofstream displayFile("display.txt", ios::trunc);
    displayFile << "Customer Details:" << endl;
    displayFile << "-----------------" << endl;

    if (customers.empty()) {
        cout << "No customer details available." << endl;
        displayFile << "No customer details available." << endl;
        displayFile.close();
        return;
    }

    cout << "Customer Details:" << endl;
    cout << "-----------------" << endl;

    for (const Customer& customer : customers) {
        cout << "License Plate: " << customer.getLicensePlate() << endl;
        cout << "Name: " << customer.getName() << endl;
        cout << "Age: " << customer.getAge() << endl;
        cout << "Phone Number: " << customer.getPhoneNumber() << endl;
        cout << "Citizenship ID: " << customer.getCitizenshipID() << endl;
        cout << endl;
    }

    for (const Customer& customer : customers) {
        displayFile << "License Plate: " << customer.getLicensePlate() << endl;
        displayFile << "Name: " << customer.getName() << endl;
        displayFile << "Age: " << customer.getAge() << endl;
        displayFile << "Phone Number: " << customer.getPhoneNumber() << endl;
        displayFile << "Citizenship ID: " << customer.getCitizenshipID() << endl;
        displayFile << endl;

        auto car = find_if(cars.begin(), cars.end(), [&](const Car& c) {
            return c.getLicensePlate() == customer.getLicensePlate();
        });
        displayFile << "Car Details:" << endl;
        displayFile << "Brand: " << (*car).getBrand() << endl;
        displayFile << "Model: " << (*car).getModel() << endl;
        displayFile << "Color: " << (*car).getColor() << endl;
        displayFile << "Manufacturing Day: " << (*car).getManufacturingDay().day << "-" << (*car).getManufacturingDay().month << "-" << (*car).getManufacturingDay().year << endl;
        displayFile << endl;

    displayFile.close();
    }
}

// int main() {
//     // Load cars from file
//     vector<Car> cars = loadCars();
//     printCarDetails(cars);
// }