#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
T squaring(T &a)
{
    return a = a * a;
}

template <>
std::vector<int> squaring(std::vector<int> &a)
{
    std::for_each(a.begin(), a.end(), [](int& n)
        {
            n = n * n;
        });
    return a;
}

int main(int argc, char** argv)
{
    int input_number = 4;
    std::cout << "[IN]: " << input_number << std::endl;
    std::cout << "[OUT]: " << squaring(input_number) << std::endl;

    std::vector<int> input_arr{ -1, 4, 8 };

    std::cout << "[IN]: ";
    std::for_each(input_arr.begin(), input_arr.end(), [](int n)
        {
            std::cout << n << " ";
        });
    std::cout << std::endl;
    
    squaring(input_arr);

    std::cout << "[OUT]: ";
    std::for_each(input_arr.begin(), input_arr.end(), [](int n)
        {
            std::cout << n << " ";
        });

    return 0;
}