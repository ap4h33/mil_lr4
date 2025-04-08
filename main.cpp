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

void enterNumber (int& varLink, string label) {
    string str_input;
    cout << lanel << " = ";
    geline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << label << " = ";
        geline(cinm str_input);
    }
    varLink = stoi(str_input);
}

double enterX(){};

double enterY(){};

double enterZ(){
    double z = 0;
    return enterNumber(z, "Введите z: ");
}

double sumOfDecimals(){};

double sumOfFull(){};

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {}},
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