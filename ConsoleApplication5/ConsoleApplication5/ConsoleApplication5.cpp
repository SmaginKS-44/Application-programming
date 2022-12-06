#include <iostream>
#include <string>
#include <random>

int main()
{
    const int nrolls = 10000;  // кількість експериментів
    const int nstars = 100;    // максимальна кількість для розповсюдження
    const int nintervals = 20; // кількість інтервалів
    const int first = -5;      // перший інтервал

    std::default_random_engine generator;
    std::extreme_value_distribution<double> distribution1(1.0, 3.0); // фунція фишера
    std::normal_distribution<double> distribution(1.0, 3.0);// фунція монте карло
    std::normal_distribution<double> distribution3(1.0, 2.0);
    int pi[nintervals] = {};
    // передача данних в фунцію фішера 
    for (int i = 0; i < nrolls; ++i) {
        double number = distribution1(generator);
        if ((number >= -5.0) && (number < 15.0)) ++pi[int(number - first)];
    }

    std::cout << "extreme_value_distribution:" << std::endl;
    // Відображенн гістограми
    for (int i = 0; i < nintervals; ++i) {
        std::cout.width(2); std::cout << float(first + i) << "..";
        std::cout.width(2); std::cout << float(first + i + 1) << ": ";
        std::cout << std::string(pi[i] * nstars / nrolls, '*') << std::endl;
    }

    int p[nintervals] = {};
    // передача данних в фунцію фішера цисел монте карло
    for (int i = 0; i < nrolls; ++i) {
        double number = distribution(generator);
        if ((number >= -5.0) && (number < 15.0)) ++p[int(number - first)];
    }

    std::cout << "extreme_value_distribution monte carlo:" << std::endl;
    // Відображенн гістограм
    for (int i = 0; i < nintervals; ++i) {
        std::cout.width(2); std::cout << float(first + i) << "..";
        std::cout.width(2); std::cout << float(first + i + 1) << ": ";
        std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
    }
    int p3[nintervals] = {};
    // передача данних в фунцію фішера цисел неймана
    for (int i = 0; i < nrolls; ++i) {
        double number = distribution3(generator);
        if ((number >= -5.0) && (number < 15.0)) ++p3[int(number - first)];
    }

    std::cout << "extreme_value_distribution von neumann:" << std::endl;
    // Відображенн гістограм
    for (int i = 0; i < nintervals; ++i) {
        std::cout.width(2); std::cout << float(first + i) << "..";
        std::cout.width(2); std::cout << float(first + i + 1) << ": ";
        std::cout << std::string(p3[i] * nstars / nrolls, '*') << std::endl;
    }
    return 0;
}