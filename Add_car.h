#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;





// Check if the car number is valid
int carno_check(const std::string& str)
{
    int size = str.length();
    if (size != 9 && size != 8)
        return 0;
    if (size == 8)
        if (!isdigit(str[0]) || !isdigit(str[1]) || !isalpha(str[2]) || !isdigit(str[4]) || !isdigit(str[5]) ||
            !isdigit(str[6]) || !isdigit(str[7]))
            return 0;

    if (size == 9)
        if (!isdigit(str[0]) || !isdigit(str[1]) || !isalpha(str[2]) || !isdigit(str[4]) || !isdigit(str[5]) ||
            !isdigit(str[6]) || !isdigit(str[7]) || !isdigit(str[8]))
            return 0;
            
    if (str[3] != '-')
        return 0;

    return 1;
}


// Add car to the vector and file
void addCar(vector<Car>& cars, const string& brand, const string& model, const string& licensePlate, const string& color,
            const Date& manufacturingDay) {
    // Check if the car already exists
    for (const Car& car : cars) {
        if (car.getLicensePlate() == licensePlate) {
            cout << "Error: Car with license plate " << licensePlate << " already exists." << endl;
        
            ofstream displayFile("display.txt", ios::trunc);
            displayFile << "Error: Car with license plate " << licensePlate << " already exists." << endl;

            return;
        }
    }
    // Add car to the vector and files
    Car newCar(brand, model, licensePlate, color, manufacturingDay);
    cars.push_back(newCar);
    cout << "Car with license plate " << licensePlate << " added successfully." << endl;
    saveCars(cars);

    cout << "Car added successfully." << endl;

    // Print car details to file
    newCar.printDetailsToFile();
}



// int main() {
//     // Load cars from file
//     vector<Car> cars = loadCars();

//     // Create a Date object
//     Date manufacturingDay(3, 12, 2004);

//     // Add car to the vector
//     addCar(cars, "Toyota", "Camry", "ABC123", "Red", manufacturingDay);

//     // Print car details to display.txt file
//     system("start notepad.exe display.txt");

//     return 0;
// }
