#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iterator>
#include <clocale>

using namespace std::placeholders;

struct point
{
    int x;
    int y;
    std::string s;

    point() : x(0), y(0), s("") {}

    point(int x_, int y_, const std::string& s_) : x(x_), y(y_), s(s_) {}

    bool operator<(const point& other) const
    {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    point operator*(int k) const
    {
        point result;
        result.x = k * x;
        result.y = k * y;
        result.s = s;
        return result;
    }

    point operator+(const point& other) const
    {
        point result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.s = s;
        return result;
    }
};

std::istream& operator>>(std::istream& is, point& p)
{
    is >> p.x >> p.y >> p.s;
    return is;
}

std::ostream& operator<<(std::ostream& os, const point& p)
{
    os << p.x << " " << p.y << " " << p.s;
    return os;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int K = 0;
    std::string name1 = "";
    std::string name2 = "";

    std::cout << "Введите число K: ";
    std::cin >> K;
    std::cout << "Введите имя первого файла: ";
    std::cin >> name1;
    std::cout << "Введите имя второго файла: ";
    std::cin >> name2;

    std::ifstream file1(name1);
    if (!file1.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл " << name1 << std::endl;
        return 1;
    }

    std::vector<point> V1;
    std::copy(
        std::istream_iterator<point>(file1),
        std::istream_iterator<point>(),
        std::back_inserter(V1)
    );
    file1.close();

    std::ifstream file2(name2);
    if (!file2.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл " << name2 << std::endl;
        return 1;
    }

    std::vector<point> V2;
    std::copy(
        std::istream_iterator<point>(file2),
        std::istream_iterator<point>(),
        std::back_inserter(V2)
    );
    file2.close();

    if (V1.size() != V2.size())
    {
        std::cout << "Ошибка: файлы содержат разное количество элементов!" << std::endl;
        std::cout << "V1: " << V1.size() << ", V2: " << V2.size() << std::endl;
        return 1;
    }

    std::vector<point> result(V1.size());

    for (size_t i = 0; i < V1.size(); ++i)
    {
        result[i] = (V1[i] * K) + V2[i];
    }

    std::cout << "\nРезультат преобразований:\n";
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    return 0;
}