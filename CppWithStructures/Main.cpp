#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <stdexcept>
using namespace std;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;

    void setValues(double len, double clr, double vol, double power, double dia, const string& col, const string& transType) {
        length = len;
        clearance = clr;
        engineVolume = vol;
        enginePower = power;
        wheelDiameter = dia;
        color = col;
        transmissionType = transType;
    }

    void displayValues() const {
        cout << "Car details: \n";
        cout << "length: " << length << " m\n";
        cout << "clearance: " << clearance << " cm\n";
        cout << "engine volume: " << engineVolume << " L\n";
        cout << "engine power: " << enginePower << " hp\n";
        cout << "wheel diameter: " << wheelDiameter << " inches\n";
        cout << "color: " << color << "\n";
        cout << "transmission type: " << transmissionType << "\n";
    }

    void searchValue(int choice) const {
        switch (choice) {
        case 1:
            cout << "Color of the car: " << color << "\n";
            break;
        case 2:
            cout << "Length: " << length << " m\n";
            break;
        case 3:
            cout << "Clearance: " << clearance << " cm\n";
            break;
        case 4:
            cout << "Engine: " << engineVolume << " L\n";
            break;
        case 5:
            cout << "Eengine: " << enginePower << " HP\n";
            break;
        case 6:
            cout << "Wheel: " << wheelDiameter << " inches\n";
            break;
        case 7:
            cout << "Transmission: " << transmissionType << "\n";
            break;
        default:
            cout << "Invalid choice ;(\n";
            break;
        }
    }
};

bool isAlpha(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

void inputCarValues(Car& car) {
    double length, clearance, engineVolume, enginePower, wheelDiameter;
    string color, transmissionType;

    cout << "Enter car's length (in meters): ";
    while (!(cin >> length) || length <= 0) {
        cout << "Invalid input!(\n"
           << "Enter a positive num" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the car's length (in meters): ";
    }

    cout << "Enter the car's clearance (in cm): ";
    while (!(cin >> clearance) || clearance <= 0) {
        cout << "Invalid input!(\n"
            << "Enter a positive num" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the car's clearance (in cm): ";
    }

    cout << "Enter the engine's volume (in liters): ";
    while (!(cin >> engineVolume) || engineVolume <= 0) {
        cout << "Invalid input!(\n"
            << "Enter a positive num" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the engine's volume (in liters): ";
    }

    cout << "Enter the engine's power (in horsepower): ";
    while (!(cin >> enginePower) || enginePower <= 0) {
        cout << "Invalid input!(\n"
            << "Enter a positive num" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the engine's power (in horsepower): ";
    }

    cout << "Enter the wheel diameter (in inches): ";
    while (!(cin >> wheelDiameter) || wheelDiameter <= 0) {
        cout << "Invalid input!(\n"
            << "Enter a positive num" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the wheel diameter (in inches): ";
    }

    cout << "Enter the car's color (only letters): ";
    cin.ignore();
    while (true) {
        getline(cin, color);
        if (isAlpha(color)) {
            break;
        }
        else {
            cout << "Enter with letters only\n";
            cout << "Enter the car's color (only letters): ";
        }
    }

    cout << "Enter the transmission type (only letters): ";
    while (true) {
        getline(cin, transmissionType);
        if (isAlpha(transmissionType)) {
            break;
        }
        else {
            cout << "Enter with letters only\n";
            cout << "Enter the transmission type (only letters): ";
        }
    }

    car.setValues(length, clearance, engineVolume, enginePower, wheelDiameter, color, transmissionType);
}

struct Complex {
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex add(const Complex& other) const {
        return Complex(this->real + other.real, this->imag + other.imag);
    }

    Complex subtract(const Complex& other) const {
        return Complex(this->real - other.real, this->imag - other.imag);
    }

    Complex multiply(const Complex& other) const {
        return Complex(
            this->real * other.real - this->imag * other.imag,
            this->real * other.imag + this->imag * other.real
        );
    }

    Complex divide(const Complex& other) const {
        if (other.real == 0 && other.imag == 0) {
            throw runtime_error("Division by zero complex num O_O");
        }
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (this->real * other.real + this->imag * other.imag) / denominator,
            (this->imag * other.real - this->real * other.imag) / denominator
        );
    }

    void print() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i";
    }
};

Complex inputComplex(const string& prompt) {
    double real, imag;
    while (true) {
        cout << prompt;
        cin >> real >> imag;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "Invalid input!(\n"
                << "Try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return Complex(real, imag);
        }
    }
}

int main() {
    int taskChoice;

    while (true) {
        cout << "Choose a task:\n";
        cout << "1. work with complex numbers\n";
        cout << "2. work with car information\n";
        cout << "3. exit ^^\n";
        cout << "Enter your choice (1-3): ";

        while (!(cin >> taskChoice) || taskChoice < 1 || taskChoice > 3) {
            cout << "Enter a num between 1 and 3\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (taskChoice == 1) {
            Complex num1 = inputComplex("Enter first complex num (real and imaginary parts separated by space): ");
            Complex num2 = inputComplex("Enter second complex num (real and imaginary parts separated by space): ");

            int operationChoice;
            while (true) {
                cout << "\nChoose an operation:\n";
                cout << "1. addition\n";
                cout << "2. subtraction\n";
                cout << "3. multiplication\n";
                cout << "4. division\n";
                cout << "5. back to main menu\n";
                cout << "Your choice: ";

                while (!(cin >> operationChoice) || operationChoice < 1 || operationChoice > 5) {
                    cout << "Enter a num between 1 and 5\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (operationChoice == 5) {
                    break;
                }

                try {
                    Complex result;
                    switch (operationChoice) {
                    case 1:
                        result = num1.add(num2);
                        cout << "Result: ";
                        result.print();
                        break;
                    case 2:
                        result = num1.subtract(num2);
                        cout << "Result: ";
                        result.print();
                        break;
                    case 3:
                        result = num1.multiply(num2);
                        cout << "Result: ";
                        result.print();
                        break;
                    case 4:
                        result = num1.divide(num2);
                        cout << "Result: ";
                        result.print();
                        break;
                    }
                    cout << endl;
                }
                catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
            }
        }
        else if (taskChoice == 2) {
            Car car;
            inputCarValues(car);

            car.displayValues();

            int searchChoice;
            cout << "\nSelect a parameter to search for:\n";
            cout << "1. color\n";
            cout << "2. length\n";
            cout << "3. clearance\n";
            cout << "4. engine volume\n";
            cout << "5. engine power\n";
            cout << "6. wheel diameter\n";
            cout << "7. transmission type\n";
            cout << "Enter your choice (1-7): ";
            while (!(cin >> searchChoice) || searchChoice < 1 || searchChoice > 7) {
                cout << "Enter a number between 1 and 7\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            car.searchValue(searchChoice);
        }
        else if (taskChoice == 3) {
            cout << "Exiting the program :3\n";
            break;
        }
    }

    return 0;
}
