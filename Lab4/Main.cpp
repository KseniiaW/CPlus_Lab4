#include <iostream>
#include <limits>
#include "functions.h"
using namespace std;

void task1() {
    cout << "\n=== ЗАДАНИЕ 1: КОРНИ КВАДРАТНОГО УРАВНЕНИЯ ===" << endl;

    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    double x1, x2;
    int result = Myroot(a, b, c, x1, x2);

    cout << "Уравнение: " << a << "x² + " << b << "x + " << c << " = 0" << endl;

    switch (result) {
    case 1:
        cout << "Два различных корня:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        break;
    case 0:
        cout << "Один корень (кратности 2):" << endl;
        cout << "x1 = x2 = " << x1 << endl;
        break;
    case -1:
        cout << "Действительных корней нет" << endl;
        break;
    default:
        cout << "Неизвестный результат" << endl;
    }
}

void task2() {
    cout << "\n=== ЗАДАНИЕ 2: ВВОД ДАННЫХ С ПРОВЕРКОЙ ===" << endl;

    int a, b;

    if (!Input(a, b)) {
        cerr << "Ошибка ввода данных!" << endl;
        return;
    }

    int s = a + b;
    cout << "Сумма чисел: " << a << " + " << b << " = " << s << endl;

    int diff = a - b;
    int product = a * b;

    cout << "Разность: " << a << " - " << b << " = " << diff << endl;
    cout << "Произведение: " << a << " * " << b << " = " << product << endl;

    if (b != 0) {
        double quotient = static_cast<double>(a) / b;
        cout << "Частное: " << a << " / " << b << " = " << quotient << endl;
    }
    else {
        cout << "Деление на ноль невозможно" << endl;
    }
}

int main() {
    system("chcp 1251");

    int choice;
    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1. Корни квадратного уравнения" << endl;
        cout << "2. Ввод данных с проверкой" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание: ";

        if (!(cin >> choice)) {
            cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}