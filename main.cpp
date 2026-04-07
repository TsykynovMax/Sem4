#include <iostream>
#include <deque>
#include <string>
#include <sstream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::deque<int> D;
    std::string line;

    std::cout << "Введите элементы дека: ";
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int value;
    while (ss >> value) {
        D.push_back(value);
    }

    int N = D.size();

    std::cout << "Исходный дек: ";
    for (int x : D) std::cout << x << " ";
    std::cout << std::endl;

    auto i = D.begin();

    for (int k = 0; k < N / 4; ++k) {
        i = D.erase(++i);
    }

    std::cout << "Дек после удаления: ";
    for (int x : D) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}