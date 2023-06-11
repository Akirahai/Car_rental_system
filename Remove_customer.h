#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Remove customers from the list
// void removeCustomer(vector<Customer>& customers, const string& licensePlate) {
//     auto customer = find_if(customers.begin(), customers.end(), [&](const Customer& c) { 
//         return c.getLicensePlate() == licensePlate; 
//     });
//     
//     if (customer != customers.end()) {
//         // Print removed car details to display.txt file 
//         displayFile << "Removed customers:" << endl;
//         displayFile << "License Plate: " << customer -> getLicensePlate() << endl;
//         displayFile << "Name: " << customer->getName() << endl;
//         displayFile << "Age: " << customer->getAge() << endl;
//         displayFile << "Phone Number: " << customer->getPhoneNumber() << endl;
//         displayFile << "Citizenship ID: " << customer->getCitizenshipID() << endl;
//         displayFile << endl;
//         displayFile.close();

//         // Remove car from vector
//         customers.erase(customer);
//         cout << "Customer removed successfully." << endl;

//         saveCustomers(customers);  // Save the updated car list to the file
//     } else {
//         displayFile << "Customer not found." << endl;
//         displayFile.close();
//     }
// }

// int main() {
//     vector<Customer> customers = loadCustomers();

//     string licensePlate;
//     cout << "Enter the license plate of the car to remove: ";
//     getline(cin, licensePlate);
//     removeCustomer(customers, licensePlate);
//     system("start notepad.exe display.txt");
// }


void removeCustomer(vector<Customer>& customers, vector<Car>& cars, const string& licensePlate) {
    auto customer = find_if(customers.begin(), customers.end(), [&](const Customer& c) { 
        return c.getLicensePlate() == licensePlate; 
    });
    ofstream displayFile("display.txt", ios::trunc); 
    if (customer != customers.end()) {
        Customer removedCustomer = *customer;  // Store the removed customer
        customers.erase(customer);
        displayFile << "Customer removed successfully." << endl;
        displayFile << endl;
        saveCustomers(customers);  // Save the updated customer list to the file


        // Change the status of the car to "Available"
        auto car = find_if(cars.begin(), cars.end(), [&](const Car& c) {
            return c.getLicensePlate() == licensePlate;
        });
        if (car != cars.end()) {
            car->setAvailability(true);
            saveCars(cars);  // Save the updated car list to the file
        }

        // Print removed customer details
        displayFile << "Removed customer details:" << endl;
        displayFile << "License Plate: " << removedCustomer.getLicensePlate() << endl;
        displayFile << "Name: " << removedCustomer.getName() << endl;
        displayFile << "Age: " << removedCustomer.getAge() << endl;
        displayFile << "Phone Number: " << removedCustomer.getPhoneNumber() << endl;
        displayFile << "Citizenship ID: " << removedCustomer.getCitizenshipID() << endl;
        displayFile << "Change the corresponding car status to \"Available\"." << endl;
    } else {
        displayFile << "Customer not found." << endl;
        
    }
    displayFile.close();
}


