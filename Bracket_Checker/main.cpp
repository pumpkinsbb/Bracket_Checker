#include <iostream>
#include <stack>
#include <map>
#include <string>
#include "windows.h"
using namespace std;

bool areBracketsBalanced(const string& str) {
    stack<char> s;
    map<char, char> brackets = { {')','('}, {']','['}, {'}','{'} };
    for (char c : str) {
        if (brackets.count(c)) {
            if (s.empty() || s.top() != brackets[c]) return false;
            s.pop();
        }
        else if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
    }
    return s.empty();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    cout << "Введи рядок з дужками: ";
    getline(cin, input);

    if (areBracketsBalanced(input)) {
        cout << "Дужки розставлені правильно.\n";
    }
    else {
        cout << "Є помилки в розстановці дужок.\n";
    }

    return 0;
}
