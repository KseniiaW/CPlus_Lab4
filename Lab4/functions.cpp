#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include "functions.h"
using namespace std;

// Task1
int Myroot(double a, double b, double c, double& x1, double& x2) {
    if (a == 0) {
        if (b == 0) {
            return -1;
        }
        x1 = x2 = -c / b;
        return 0; 
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        return 1;
    }
    else if (discriminant == 0) {
        x1 = x2 = -b / (2 * a);
        return 0;
    }
    else {
        return -1;
    }
}

// Task2
bool Input(int& a, int& b) {
    cout << "Введите два целых числа: ";

    if (!(cin >> a >> b)) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    if (a == b) {
        cout << "Предупреждение: числа равны" << endl;
    }

    return true;
}