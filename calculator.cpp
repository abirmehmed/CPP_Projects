#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Simple Calculator" << endl;
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch(operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            if(num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            else
                cout << "Error! Division by zero is not allowed.";
            break;
        default:
            cout << "Error! Invalid operation.";
    }

    return 0;
}
