#include <iostream>
#include <deque>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::deque<int> D = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; 

    int N = D.size();

    std::cout << "»сходный дек: ";
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
