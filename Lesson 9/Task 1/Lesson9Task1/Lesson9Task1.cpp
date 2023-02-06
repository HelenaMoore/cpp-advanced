#include <iostream>
#include <vector>

template <class T>
void moveVectors(std::vector<T>& a, std::vector<T>& b)
{
    b = std::move(a);
}

int main(int argc, char** argv)
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    moveVectors(one, two);
    
    for (auto const& print_one : one) { std::cout << print_one << " "; }
    std::cout << std::endl;
    for (auto const& print_two : two) { std::cout << print_two << " "; }

    return 0;
}