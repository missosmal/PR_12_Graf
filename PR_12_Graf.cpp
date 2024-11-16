#include <iostream>
#include <cstring>
#include <cstdlib> // для atoi
using namespace std;

void task1() {
    setlocale(0, "");
    cout << "Введите строку символов с одной открывающейся и одной закрывающейся скобкой: ";
    char str[100];
    cin.ignore(); // Очистка буфера после предыдущего ввода
    cin.getline(str, 100);

    char* start = strchr(str, '('); // Поиск открывающейся скобки
    char* end = strchr(str, ')');   // Поиск закрывающейся скобки

    if (start && end && start < end) {
        cout << "Символы внутри скобок: ";
        for (char* p = start + 1; p < end; ++p) {
            cout << *p;
        }
        cout << endl;
    }
    else {
        cout << "Скобки не найдены или расположены некорректно." << endl;
    }
}

void task2() {
    setlocale(0, "");
    cout << "Введите строку символов: ";
    char str[100];
    cin.ignore(); // Очистка буфера после предыдущего ввода
    cin.getline(str, 100);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') str[i] = 'b';
        else if (str[i] == 'A') str[i] = 'B';
        else if (str[i] == 'b') str[i] = 'a';
        else if (str[i] == 'B') str[i] = 'A';
    }

    cout << "Результат: " << str << endl;
}

void task3() {
    setlocale(0, "");
    cout << "Введите арифметическое выражение (формата A op B): ";
    char str[100];
    cin.ignore(); // Очистка буфера после предыдущего ввода
    cin.getline(str, 100);

    int A, B;
    char op;
    scanf_s(str, "%d %c %d", &A, &op, &B);

    int result;
    switch (op) {
    case '+': result = A + B; break;
    case '-': result = A - B; break;
    case '*': result = A * B; break;
    case '/':
        if (B != 0)
            result = A / B;
        else {
            cout << "Ошибка: деление на ноль!" << endl;
            return;
        }
        break;
    default:
        cout << "Ошибка: некорректная операция!" << endl;
        return;
    }

    cout << "Результат: " << A << " " << op << " " << B << " = " << result << endl;
}

int main() {
    setlocale(0, "");
    int choice;

    do {
        cout << "Выберите задачу:\n";
        cout << "1 - Задача 1: Вывод символов между скобками\n";
        cout << "2 - Задача 2: Замена символов a/A и b/B\n";
        cout << "3 - Задача 3: Вычисление арифметического выражения\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Выход из программы.\n"; break;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
