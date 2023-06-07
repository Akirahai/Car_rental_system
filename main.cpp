#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Car_class.h"
#include "Add_car.h"
#include "Print_car_details.h"
#include "Remove_car.h"
#include "Car_status.h"
#include "Book_car.h"
using namespace std;


int main() {
    vector<Car> cars = loadCars();

    vector<Customer> customers = loadCustomers();

    string choice;
    while (choice != "0") {
        cout << "Car Rental System\n\n";
        cout << "1. Book a car\n";
        cout << "2. Add a car\n";
        cout << "3. Print car details\n";
        cout << "4. Print car status\n";
        cout << "5. Remove a car\n";
        cout << "6. Print customer details\n";
        cout << "0. Quit\n\n";
        cout << "Enter your choice: ";
        getline(cin, choice);
        cout << endl;
        system("taskkill /im notepad.exe /f");
        if (choice == "1") {
            printCarStatus_Available(cars);
            system("start notepad.exe display.txt");

            string licensePlate;
            cout << "Enter the license plate of the car to book: ";
            getline(cin, licensePlate);
            bookCar(cars, customers, licensePlate);
            system("start notepad.exe display.txt");


        } else if (choice == "2") {
            string brand, model, licensePlate, color;
            int day, month, year;
            cout << "Enter the car details:\n";
            cout << "Brand: ";
            getline(cin, brand);
            cout << "Model: ";
            getline(cin, model);
            cout << "License Plate: ";
            getline(cin, licensePlate);
            while (!carno_check(licensePlate)) {
                cout << "Invalid License Plate format. Please enter again: ";
                getline(cin, licensePlate);
            }
            cout << "Color: ";
            getline(cin, color);
            cout << "Manufacturing Day:\n";
            cout << "Day (dd): ";
            cin >> day;
            cout << "Month (mm): ";
            cin >> month;
            cout << "Year (yyyy): ";
            cin >> year;
            cin.ignore();
            Date manufacturingDay(day, month, year);

            addCar(cars, brand, model, licensePlate, color, manufacturingDay);
            system("start notepad.exe display.txt");


        } else if (choice == "3") {
            printCarDetails(cars);
            system("start notepad.exe display.txt");

        } else if (choice == "4") {
            int cho = 1;
            
            while (cho != 0) {
                cout << endl;
                cout << "Chose status to print:\n";
                cout << "0. Quit\n";
                cout << "1. Available cars\n";
                cout << "2. Unavailable cars\n";
                cout << "Enter your choice: ";
                cin >> cho;
                cin.ignore();
                cout << endl;
                if (cho == 1) {
                    printCarStatus_Available(cars);
                    system("start notepad.exe display.txt");
                }

                else if (cho == 2) {
                    printCarStatus_Unavailable(cars, customers);
                    system("start notepad.exe display.txt");
                }

                else if (cho != 0) {
                    cout << "Invalid choice." << endl;
                }
            }

        } else if (choice == "5") {
            printCarDetails(cars);
            system("start notepad.exe display.txt");

            string licensePlate;
            cout << "Enter the license plate of the car to remove: ";
            getline(cin, licensePlate);
            removeCar(cars, licensePlate);
            system("start notepad.exe display.txt");


        } else if (choice == "6") {
            printCustomerDetails(customers, cars);
            system("start notepad.exe display.txt");

        } else if (choice != "0") {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
    
    return 0;
}
