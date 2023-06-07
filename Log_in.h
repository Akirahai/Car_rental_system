#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string USER_FILE = "user.txt";

bool isUserRegistered() {
    ifstream userFile(USER_FILE);
    return userFile.good();
}

bool registerUser() {
    string password;
    cout << "Enter a password: ";
    getline(cin, password);

    ofstream userFile(USER_FILE);
    if (!userFile) {
        cout << "Error opening user file." << endl;
        return false;
    }

    userFile << password;
    cout << "Registration successful!" << endl;

    return true;
}

bool loginUser() {
    string password;
    cout << "Enter your password: ";
    getline(cin, password);
    system("taskkill /im notepad.exe /f 1>NULL");

    ifstream userFile(USER_FILE);

    string storedPassword;
    getline(userFile, storedPassword);

    if (password == storedPassword) {
        ofstream displayFile("display.txt", ios::trunc);
        displayFile << "Login successful!" << endl;
        displayFile.close();
        return true;
    } else {
        cout << "Incorrect password." << endl;
        return false;
    }
}

void changePassword() {
    string newPassword;
    cout << "Enter a new password: ";
    getline(cin, newPassword);

    ofstream userFile(USER_FILE);
    if (!userFile) {
        cout << "Error opening user file." << endl;
        return;
    }

    userFile << newPassword;
    ofstream displayFile("display.txt", ios::trunc);
    displayFile << "Password changed successfully!" << endl;
    displayFile.close();
}

void sendPasswordByEmail() {
    string email;
    cout << "Enter your email address: ";
    getline(cin, email);

    ifstream userFile(USER_FILE);
    if (!userFile) {
        cout << "Error opening user file." << endl;
        return;
    }

    string storedPassword;
    getline(userFile, storedPassword);

    // Simulate sending the password by email
    ofstream displayFile("display.txt", ios::trunc);
    displayFile << "Password sent to email: " << email << endl;
    displayFile.close();
}



// int main() {
//     if (isUserRegistered()) {
//         string c;
//         while (c != "0") {
//             cout << "Car Rental System\n\n";
//             cout << "1. Login\n";
//             cout << "2. Forgot Password\n";
//             cout << "0. Quit\n\n";
//             cout << "Enter your choice: ";
//             getline(cin, c);
//             cout << endl;

//             if (c == "1") {
//                 while (true) {
//                     if (loginUser()) {
//                         string subc;
//                         while (subc != "0") {
//                             cout << "1. Change Password\n";
//                             cout << "0. Quit\n";
//                             cout << "Enter your choice: ";
//                             getline(cin, subc);
//                             cout << endl;

//                             if (subc == "1") {
//                                 changePassword();
//                             } else if (subc != "0") {
//                                 cout << "Invalid c. Please try again." << endl;
//                             }
//                         }
//                         break;
//                     }
//                 }
//             } else if (c == "2") {
//                 sendPasswordByEmail();
//             } else if (c != "0") {
//                 cout << "Invalid c. Please try again." << endl;
//             }

//             cout << endl;
//         }
//     } else {
//         registerUser();
//     }

//     return 0;
// }
