#include <iostream>
#include <fstream>
#include <string>

using namespace std;



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

bool loginUser() {
    string password;
    cout << "Enter your password: ";
    getline(cin, password);
    system("taskkill /im notepad.exe /f 1>NULL");

    ifstream userFile("user.txt");

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

