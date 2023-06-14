#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

string getPassword() {
    string password;
    char ch;

    while ((ch = _getch()) != '\r') {     // Read characters until Enter is pressed
    // _getch() is used to read character without displaying it.

        if (ch == '\b') {  // Handle backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password += ch;
        }
    }

    return password;
}

bool loginUser() {
    string password;

    cout << "Enter your password: ";
    password = getPassword();
    cout << endl;

    ifstream userFile("user.txt");

    string storedPassword;
    getline(userFile, storedPassword);

    if (password == storedPassword) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Incorrect password." << endl;
        return false;
    }
}



bool isUserRegistered() {
    ifstream userFile("user.txt");
    return userFile.good();
}

bool registerUser() {
    string password;
    cout << "Enter a password: ";
    getline(cin, password);

    ofstream userFile("user.txt");
    if (!userFile) {
        cout << "Error opening user file." << endl;
        return false;
    }

    userFile << password;
    cout << "Registration successful!" << endl;

    return true;
}


void changePassword() {
    string newPassword;
    cout << "Enter a new password: ";
    getline(cin, newPassword);

    ofstream userFile("user.txt");
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

    ifstream userFile("user.txt");
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

