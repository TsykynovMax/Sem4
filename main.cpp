#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <iterator>

void printDeque(const std::deque<int>& D, const std::string& message)
{
    std::cout << message;
    for (int x : D) std::cout << x << " ";
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::deque<int> D;
    std::string line;

    std::cout << "Введите элементы дека: ";
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(D));

    int n = D.size();

    printDeque(D, "Исходный дек: ");

    auto i = D.begin();

    for (size_t k = 0; k < n / 4; ++k) {
        i = D.erase(++i);
    }

    printDeque(D, "Дек после удаления: ");

    return 0;
}