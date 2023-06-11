#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
// # include "Car_class.h"

void removeCar(vector<Car>& cars, const string& licensePlate) {
    auto car = find_if(cars.begin(), cars.end(), [&](const Car& c) { 
        return c.getLicensePlate() == licensePlate;
    });
    ofstream displayFile("display.txt", ios::trunc); 
    if (car != cars.end()) {
        // Print removed car details to display.txt file 
        displayFile << "Removed car:" << endl;
        displayFile << "License Plate: " << (*car).getLicensePlate() << endl;
        displayFile << "Brand: " << (*car).getBrand() << endl;
        displayFile << "Model: " << (*car).getModel() << endl;
        displayFile << "Color: " << (*car).getColor() << endl;
        displayFile << "Manufacturing Day: " << (*car).getManufacturingDay().day << "-" << (*car).getManufacturingDay().month << "-" << (*car).getManufacturingDay().year << endl;
        displayFile << "Status: " << ((*car).isAvailable() ? "Available" : "Not Available") << endl;
        displayFile << endl;
        displayFile.close();

        // Remove car from vector
        cars.erase(car);
        cout << "Car removed successfully." << endl;

        saveCars(cars);  // Save the updated car list to the file
    } else {
        displayFile << "Car not found." << endl;
        displayFile.close();
    }
}


// int main() {
//     vector<Car> cars = loadCars();

//     string licensePlate;
//     cout << "Enter the license plate of the car to remove: ";
//     getline(cin, licensePlate);
//     removeCar(cars, licensePlate);
//     system("start notepad.exe display.txt");
// }