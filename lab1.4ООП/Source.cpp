#include "IntegerArray.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void printMenu() {
    cout << "1. Ініціалізувати масив" << endl;
    cout << "2. Додавання другого масиву" << endl;
    cout << "3. Відображення масиву" << endl;
    cout << "4. Додайте два масиви" << endl;
    cout << "5. Відніміть два масиви" << endl;
    cout << "6. Помножити масив на скаляр" << endl;
    cout << "7. Розділити масив на скаляр" << endl;
    cout << "8. Exit" << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int lower, upper;
    cout << "Enter lower and upper bounds for the arrays: ";
    cin >> lower >> upper;

    IntegerArray array1(lower, upper);
    IntegerArray array2(lower, upper);

    cout << "Enter " << upper - lower + 1 << " integers for the first array:" << endl;
    array1.Read();

    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter initial value for the second array: ";
            cin >> value;
            array2.Init(value);
            break;
        }
        case 2:
            cout << "Enter " << upper - lower + 1 << " integers for the second array:" << endl;
            array2.Read();
            break;
        case 3:
            cout << "First array:" << endl;
            array1.Display();
            cout << "Second array:" << endl;
            array2.Display();
            break;
        case 4: {
            try {
                IntegerArray result = array1.add(array2);
                cout << "Result of addition:" << endl;
                result.Display();
            }
            catch (const std::invalid_argument& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 5: {
            try {
                IntegerArray result = array1.subtract(array2);
                cout << "Result of subtraction:" << endl;
                result.Display();
            }
            catch (const std::invalid_argument& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 6: {
            int scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            try {
                IntegerArray result = array1.multiply(scalar);
                cout << "Result of multiplication:" << endl;
                result.Display();
            }
            catch (const std::invalid_argument& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 7: {
            int scalar;
            cout << "Enter scalar value: ";
            cin >> scalar;
            try {
                IntegerArray result = array1.divide(scalar);
                cout << "Result of division:" << endl;
                result.Display();
            }
            catch (const std::invalid_argument& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 8:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
