#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

float transportEmission() {
    float km, typeFactor;
    int vehicleType;
    cout << "\nSelect your transport type:\n";
    cout << "1. Car (Petrol)\n2. Bike\n3. Bus\n4. Train\n5. Bicycle/Walk\n";
    cout << "Enter choice: ";
    cin >> vehicleType;

    switch (vehicleType) {
        case 1: typeFactor = 0.192; break;
        case 2: typeFactor = 0.082; break;
        case 3: typeFactor = 0.105; break;
        case 4: typeFactor = 0.041; break;
        case 5: typeFactor = 0.0; break;
        default: typeFactor = 0.0;
    }

    cout << "Enter average distance travelled per day (in km): ";
    cin >> km;
    return km * typeFactor * 30;
}

float electricityEmission() {
    float units;
    cout << "\nEnter average monthly electricity usage (in kWh): ";
    cin >> units;
    return units * 0.85;
}

float dietEmission() {
    int choice;
    cout << "\nSelect your diet type:\n1. Vegetarian\n2. Non-Vegetarian\n3. Vegan\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) return 150;
    else if (choice == 2) return 300;
    else return 100;
}

int main() {
    float tEmission = transportEmission();
    float eEmission = electricityEmission();
    float dEmission = dietEmission();
    float totalEmission = tEmission + eEmission + dEmission;

    cout << fixed << setprecision(2);
    cout << "\n===== MONTHLY CARBON FOOTPRINT REPORT =====\n";
    cout << "Transport Emissions: " << tEmission << " kg CO2\n";
    cout << "Electricity Emissions: " << eEmission << " kg CO2\n";
    cout << "Diet Emissions: " << dEmission << " kg CO2\n";
    cout << "-------------------------------------------\n";
    cout << "Total Monthly Carbon Emission: " << totalEmission << " kg CO2\n";

    if (totalEmission < 250)
        cout << "Low Footprint.\n";
    else if (totalEmission < 500)
        cout << "Moderate Footprint.\n";
    else
        cout << "High Footprint.\n";

    ofstream file("carbon_report.txt", ios::app);
    file << "Total Monthly Carbon Emission: " << totalEmission << " kg CO2\n";
    file.close();

    cout << "\nReport saved to 'carbon_report.txt'.\n";
    return 0;
}