#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <clocale>

int main() 
{
    setlocale(LC_ALL, "Russian");

 
    std::vector<std::string> V = 
    {
        "APPLE", "BANANA", "ORANGE", "GRAPE", "LEMON",
        "PEACH", "CHERRY", "MANGO", "KIWI", "PLUM", "BALOON"
    };

    std::cout << "Исходный вектор:\n";
    for (const auto& word : V) 
    {
        std::cout << word << " ";
    }
    std::cout << "\n\n";

    std::map<char, std::string> M;

  
    for (auto it = V.rbegin(); it != V.rend(); ++it)
    {
        std::string word = *it;  
        char lastLetter = word.back();

        auto mit = M.find(lastLetter);

        if (mit == M.end())
        {
            M[lastLetter] = "";
        }
        else
        {
            if (!mit->second.empty())
            {
                mit->second += " ";
            }
            mit->second += word;
        }
    }

    std::cout << "Результат (буква + строка из слов, кроме последнего):\n";
    for (const auto& pair : M) 
    {
        if (pair.second.empty()) 
        {
            std::cout << pair.first << " - пустая строка\n";
        }
        else
        {
            std::cout << pair.first << " - \"" << pair.second << "\"\n";
        }
    }

    return 0;
}