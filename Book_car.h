#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>


// #include "Car_class.h"


void bookCar(vector<Car>& cars, vector<Customer>& customers, const string& licensePlate) {
    auto car = find_if(cars.begin(), cars.end(), [&](const Car& c) {
        return c.getLicensePlate() == licensePlate;
    });

    ofstream displayFile("display.txt", ios::trunc);
    if (car != cars.end()) {
        if (car->isAvailable()) {
            car->setAvailability(false);
            saveCars(cars);

            // Get customer information
            string name, phoneNumber, citizenshipID;
            int age;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter your phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter your citizenship ID: ";
            getline(cin, citizenshipID);

            // Create a new Customer object
            Customer customer(licensePlate, name, age, phoneNumber, citizenshipID);

            // Add the customer to the vector
            customers.push_back(customer);

            // Save customer information to file
            saveCustomers(customers);

            displayFile << "Car booked successfully: " << endl;
            displayFile << "License Plate: " << (*car).getLicensePlate() << endl;
            displayFile << "Brand: " << (*car).getBrand() << endl;
            displayFile << "Model: " << (*car).getModel() << endl;
            displayFile << "Color: " << (*car).getColor() << endl;
            displayFile << "Manufacturing Day: " << (*car).getManufacturingDay().day << "-" << (*car).getManufacturingDay().month << "-" << (*car).getManufacturingDay().year << endl;
            displayFile << "Status: " << ((*car).isAvailable() ? "Available" : "Not Available") << endl;
            displayFile << "-------------------------"<< endl;

            displayFile << "Customer Details:" << endl;
            displayFile << "Name: " << customer.getName() << endl;
            displayFile << "Age: " << customer.getAge() << endl;
            displayFile << "Phone Number: " << customer.getPhoneNumber() << endl;
            displayFile << "Citizenship ID: " << customer.getCitizenshipID() << endl;
            displayFile << endl;


        } else {
            displayFile << "Car is not available for booking." << endl;
        }
    } else {
        displayFile << "Car not found." << endl;
    }
    displayFile.close();
}



// int main() {

//     vector<Car> cars = loadCars();

//     vector<Customer> customers = loadCustomers();

//     string licensePlate;
//     cout << "Enter the license plate of the car to book: ";
//     getline(cin, licensePlate);
//     bookCar(cars, customers, licensePlate);
//     system("start notepad.exe display.txt");
// }