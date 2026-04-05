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

    std::cout << "исходный вектор:\n";
    for (const auto& word : V) 
    {
        std::cout << word << " ";
    }
    std::cout << "\n\n";

    std::map<char, std::string> M;

  
    for (int i = V.size() - 1; i >= 0; --i) 
    {
        std::string word = V[i];
        char lastLetter = word.back();

        auto it = M.find(lastLetter);

        if (it == M.end()) 
        {
            M[lastLetter] = "";
        }
        else
        {
            if (!it->second.empty()) 
            {
                it->second += " ";  
            }
            it->second += word;
        }
    }

    std::cout << "Результат (буква + строка из слов, кроме последнего):\n";
    for (const auto& pair : M) {
        if (pair.second.empty()) {
            std::cout << pair.first << " - пустая строка\n";
        }
        else {
            std::cout << pair.first << " - \"" << pair.second << "\"\n";
        }
    }

    return 0;
}
