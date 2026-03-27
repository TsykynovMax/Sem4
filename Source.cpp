#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string filename = "name.txt";

    std::ifstream input_file(filename);
    if (!input_file.is_open())
    {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return 1;
    }

    std::istream_iterator<int> input_begin(input_file);
    std::istream_iterator<int> input_end;

    std::vector<int> numbers(input_begin, input_end);

    int position = 0;
    auto is_even_position = [&position](int) mutable
        {
        position++;
        return position % 2 == 0;
        };

    std::remove_copy_if(numbers.begin(), numbers.end(),
        std::ostream_iterator<int>(std::cout, " "),
        is_even_position);

    std::cout << std::endl;

    return 0;
}