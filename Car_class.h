
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


class Date {
public:
    int day;
    int month;
    int year;

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    static Date getCurrentDate() {
        time_t currentTime = time(nullptr);
        tm* formattedTime = localtime(&currentTime);

        Date currentDate(
            formattedTime->tm_mday,
            1 + formattedTime->tm_mon,
            1900 + formattedTime->tm_year
        );

        return currentDate;
    }

    int compareDates(const Date& other) const {
        if (year != other.year) {
            return year - other.year;
        } else if (month != other.month) {
            return month - other.month;
        } else {
            return day - other.day;
        }
    }
};


// Create class car
class Car {
private:
    string brand;
    string model;
    string licensePlate;
    string color;
    Date manufacturingDay;
    bool available;

public:
    Car(const string& brand, const string& model, const string& licensePlate, const string& color,
        const Date& manufacturingDay, bool available = true)
        : brand(brand), model(model), licensePlate(licensePlate), color(color),
          manufacturingDay(manufacturingDay), available(available) {}


    // Print details of cars to console
    void printDetails() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "License Plate: " << licensePlate << endl;
        cout << "Color: " << color << endl;
        cout << "Manufacturing Day: " << manufacturingDay.day << "-" << manufacturingDay.month << "-" << manufacturingDay.year << endl;
        cout << "Status: " << (available ? "Available" : "Not Available") << endl;
        cout << endl;
    }

    // Print details of cars to display.txt
    void printDetailsToFile() const {
        ofstream displayFile("display.txt", ios::trunc);
        if (displayFile) {
            displayFile << "Added car:" << endl;
            displayFile << "Brand: " << brand << endl;
            displayFile << "Model: " << model << endl;
            displayFile << "License Plate: " << licensePlate << endl;
            displayFile << "Color: " << color << endl;
            displayFile << "Manufacturing Day: " << manufacturingDay.day << "-" << manufacturingDay.month << "-" << manufacturingDay.year << endl;
            displayFile << "Status: " << (available ? "Available" : "Not Available") << endl;
            displayFile << endl;
            displayFile.close();
        } else {
            cout << "Failed to open display.txt." << endl;
        }
    }

    void setAvailability(bool available) {
        this->available = available;
    }

    string getLicensePlate() const {
        return licensePlate;
    }

    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    bool isAvailable() const {
        return available;
    }

    Date getManufacturingDay() const {
        return manufacturingDay;
    }

    string getColor() const {
        return color;
    }
};


// Create class customer

class Customer {
private:
    string licensePlate;
    string name;
    int age;
    string phoneNumber;
    string citizenshipID;


public:
    Customer(const string& licensePlate, const string& name, int age, const string& phoneNumber, const string& citizenshipID)
        : licensePlate(licensePlate), name(name), age(age), phoneNumber(phoneNumber), citizenshipID(citizenshipID) {}

    const string& getLicensePlate() const {
        return licensePlate;
    }

    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    const string& getPhoneNumber() const {
        return phoneNumber;
    }

    const string& getCitizenshipID() const {
        return citizenshipID;
    }


};




// Save cars to file
void saveCars(const vector<Car>& cars) {
    ofstream file("cars.txt", ios::trunc);
    if (file.is_open()) {
        for (const Car& car : cars) {
            file << car.getBrand() << " " << car.getModel() << " " << car.getLicensePlate() << " "
                 << car.getColor() << " " << car.getManufacturingDay().day << " "
                 << car.getManufacturingDay().month << " " << car.getManufacturingDay().year << " "
                 << car.isAvailable() << endl;
        }
        file.close();
        cout << "Cars saved successfully." << endl;
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

// Load cars from file
vector<Car> loadCars() {
    vector<Car> cars;
    ifstream file("cars.txt");
    if (file) {
        string brand, model, licensePlate, color;
        int day, month, year;
        bool a;
        while (file >> brand >> model >> licensePlate >> color >> day >> month >> year >> a) {
            Date manufacturingDay(day, month, year);
            cars.push_back(Car(brand, model, licensePlate, color, manufacturingDay, a));
        }
        file.close();
    }
    return cars;
}


// Save customers to file
void saveCustomers(const vector<Customer>& customers) {
    ofstream file("customers.txt", ios::trunc);
    if (file.is_open()) {
        for (const Customer& customer : customers) {
            file << customer.getLicensePlate() << " " << customer.getName() << " " << customer.getAge() << " "
                 << customer.getPhoneNumber() << " " << customer.getCitizenshipID() << endl;
        }
        file.close();
        cout << "Customers saved successfully." << endl;
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}


// Load customers from file
vector<Customer> loadCustomers() {
    vector<Customer> customers;
    ifstream file("customers.txt");
    if (file) {
        string licensePlate, name, phoneNumber, citizenshipID;
        int age;
        while (file >> licensePlate >> name >> age >> phoneNumber >> citizenshipID) {
            Customer customer(licensePlate, name, age, phoneNumber, citizenshipID);
            customers.push_back(customer);
        }
        file.close();
    }
    return customers;
}

