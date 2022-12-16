#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> array{ 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    std::for_each(array.begin(), array.end(), [](const int n) 
        { 
            std::cout << n << " ";
        });
    std::cout << std::endl;

    std::for_each(array.begin(), array.end(), [](int& n)
        {
            if (n % 2 != 0)
            {
                n *= 3;
            }
        });

    std::cout << "Выходные данные: ";
    std::for_each(array.begin(), array.end(), [](const int n)
        {
            std::cout << n << " ";
        });

    return 0;
}
