#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) {
        return false;
    }
    return true;
}

template <typename T>
void enterNumber (T& varLink, string label) {
    string str_input;
    cout << label;
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << label << " = ";
        getline(cin, str_input);
    }
    varLink = stoi(str_input);
}

double enterX(){
    double x = 0;
    enterNumber(x, "Введите х: ");
    return x;
};

double enterY(){
    double y = 0;
    enterNumber(y, "Введите у: ");
    return y;
}

double enterZ(){
    double z = 0;
    enterNumber(z, "Введите z: ");
    return z;
}

double sumOfDecimals(double x, double y, double z){
    return (x - int(x)) + (y - int(y)) + (z - int(z));
}

double sumOfIntegers(double x, double y, double z){
    return int(x) + int(y) + int(z);
}

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Enter x", []() { enterX(); }}},
        {2, {"Enter y", []() { enterY(); }}},
        {3, {"Enter z", []() { enterZ(); }}},
        {4, {"Calculate the sum of the decimals", []() { sumOfDecimals(enterX(), enterY(), enterZ()); }}},
        {5, {"Calculate the sum of integers", []() { sumOfIntegers(enterX(), enterY(), enterZ()); }}}
    };

    int choice = 0;

    while (true) {
        cout << "Меню:" << endl;
        for (const auto& item:menu) {
            cout << "Task " << item.first << ". " <<item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        enterNumber(choice, "Input number of menu: ");
        if (choice == 0) {
            cout << "2025 Mil Otto" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }
        cout << endl;
    }
    return 0;
}