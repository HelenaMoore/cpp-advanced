#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <math.h>

void countSin(double angle)
{
    std::cout << "sin: " << sin(angle) << " ";
}

void countCos(double angle)
{
    std::cout << "cos: " << cos(angle) << " ";
}

void printAngle(int angle)
{
    std::cout << angle << " * 3.1415926 / 180 ";
}

double calcRad(int angle)
{
    printAngle(angle);
    return angle * 3.1415926 / 180;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    
    std::cout << "[Входные данные]: ";

    std::vector<double> angles = {calcRad(30), calcRad(60), calcRad(90)};

    std::cout << std::endl << "[Выходные данные]:" << std::endl;

    std::vector<std::function<void(double)>> functions = { countSin, countCos };


    for (const auto& angle : angles)
    {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }

    return 0;
}
