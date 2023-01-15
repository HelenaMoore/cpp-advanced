#include <algorithm>
#include <iostream>
#include <vector>

class Functor 
{
private:
    int counter = 0;
    int sum = 0;

public:
    Functor() : counter { 0 }, sum { 0 } {}
    void operator()(int number)
    {
        if (number % 3 == 0)
        {
            ++counter;
            sum += number;
        }
    }

    int getSum()
    {
        return sum;
    }

    int getCount()
    {
        return counter;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> array{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    std::for_each(array.begin(), array.end(), [](int n)
        {
            std::cout << n << " ";
        });
    std::cout << std::endl;

    Functor f;
    f = std::for_each(array.begin(), array.end(), f);
    std::cout << "[OUT]: getSum() = " << f.getSum() << std::endl;
    std::cout << "[OUT]: getCount() = " << f.getCount() << std::endl;

    return 0;
}