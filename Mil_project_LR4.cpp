#include <iostream>

function<void()> EnterNumber(int& varLink, strting label); 

int EnterX();

int EnterY();

int EnterZ();

int DecimalSum();

int IntegralSum();

struct MenuItem {
    std::String title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"", EnterX()}},
        {2, {"", EnterY()}},
        {3 {"", EnterZ()}},
        {4, {"", DecimalSum()}},
        {5, {"", IntegralSum()}}
    };

    int choice = 0;

    while (true) {
        std::cout << "Меню:\n";
        for (const auto& item:menu) {
            std::cout << "Task" << item.first << ". " << item.second.title << std::endl;
        }
        std::cout << "0. Выход\n";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "2025 Otto Mil\n";
            break;
        }
        std::cout << std::endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            std::cout << "Некорректный ввод.";
        }
        std::cout << std::endl;
    }

    return 0;
}