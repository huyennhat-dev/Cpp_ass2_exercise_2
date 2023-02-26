#include <iostream>
#include <fstream>

using namespace std;

// Function to calculate the total charges for an in-patient
double calculateCharges(int days, double dailyRate, double medCharges, double servicesCharges) {
    if (days < 0 || dailyRate < 0 || medCharges < 0 || servicesCharges < 0) {
        return -1; // Error: Invalid input
    }
    return days * dailyRate + medCharges + servicesCharges;
}

// Function to calculate the total charges for an out-patient
double calculateCharges(double medCharges, double servicesCharges) {
    if (medCharges < 0 || servicesCharges < 0) {
        return -1; // Error: Invalid input
    }
    return medCharges + servicesCharges;
}

int main() {
    ofstream outFile;
    outFile.open("patient_report.txt");

    int patientType;
    int days;
    double dailyRate;
    double medCharges;
    double servicesCharges;

    cout << "Was the patient an in-patient or an out-patient?" << endl;
    cout << "Enter 1 for in-patient, 2 for out-patient: ";
    cin >> patientType;

    if (patientType == 1) {
        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;

        cout << "Enter the daily rate: ";
        cin >> dailyRate;

        cout << "Enter the hospital medication charges: ";
        cin >> medCharges;

        cout << "Enter the charges for hospital services: ";
        cin >> servicesCharges;

        double totalCharges = calculateCharges(days, dailyRate, medCharges, servicesCharges);
        if (totalCharges < 0) {
            cout << "Error: Invalid input." << endl;
            return 1;
        }
        outFile << "Patient Type: In-Patient" << endl;
        outFile << "Number of Days: " << days << endl;
        outFile << "Daily Rate: " << dailyRate << endl;
        outFile << "Medication Charges: " << medCharges << endl;
        outFile << "Service Charges: " << servicesCharges << endl;
        outFile << "Total Charges: $" << totalCharges << endl;
    }
    else if (patientType == 2) {
        cout << "Enter the charges for hospital services: ";
        cin >> servicesCharges;

        cout << "Enter the hospital medication charges: ";
        cin >> medCharges;

        double totalCharges = calculateCharges(medCharges, servicesCharges);
        if (totalCharges < 0) {
            cout << "Error: Invalid input." << endl;
            return 1;
        }
        outFile << "Patient Type: Out-Patient" << endl;
        outFile << "Medication Charges: " << medCharges << endl;
        outFile << "Service Charges: " << servicesCharges << endl;
        outFile << "Total Charges: $" << totalCharges << endl;
    }
    else {
        cout << "Invalid input. Please enter 1 or 2." << endl;
        return 1;
    }

    outFile.close();
    cout << "Patient report written to file." << endl;

    return 0;
}
