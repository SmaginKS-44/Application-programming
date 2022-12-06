#include <iostream>
#include <string>
#include <random>
using namespace std;
int main()
{
    const int nrolls = 10000;  // number of experiments
    const int nstars = 100;    // maximum number of stars to distribute
    const int nintervals = 20; // number of intervals
    const int first = -5;      // first interval
    int n;
    int value;
    int counter;
    int result;
    cin >> n;
    vector<int> new_results(0); // use to store all the results from iterations
    vector<int> results_vec(0); // use to store the number of iterations for each number

    for (int i = 0; i < n; i++)
    {

        cin >> value;
        results_vec.push_back(value);
        while (true)
        {
            value = value * value;

            value = (value % 1000000) / 100;

            if (find(results_vec.begin(), results_vec.end(), value) == results_vec.end())
            {
                results_vec.push_back(value);
            }
            else
            {
                counter = results_vec.size();
                new_results.push_back(counter);
                break;
            }

        }
    std::default_random_engine generator;
    std::extreme_value_distribution<double> distribution1(1.0, 3.0);
    std::normal_distribution<double> distribution(1.0, 3.0);
    
    int pi[nintervals] = {};

    for (int i = 0; i < nrolls; ++i) {
        double number = distribution1(generator);
        if ((number >= -5.0) && (number < 15.0)) ++pi[int(number - first)];
    }

    std::cout << "extreme_value_distribution :" << std::endl;

    for (int i = 0; i < nintervals; ++i) {
        std::cout.width(2); std::cout << float(first + i) << "..";
        std::cout.width(2); std::cout << float(first + i + 1) << ": ";
        std::cout << std::string(pi[i] * nstars / nrolls, '*') << std::endl;
    }

    int p[nintervals] = {};

    for (int i = 0; i < nrolls; ++i) {
        double number = distribution(generator);
        if ((number >= -5.0) && (number < 15.0)) ++p[int(number - first)];
    }

    std::cout << "extreme_value_distribution (2.0,6.0):" << std::endl;

    for (int i = 0; i < nintervals; ++i) {
        std::cout.width(2); std::cout << float(first + i) << "..";
        std::cout.width(2); std::cout << float(first + i + 1) << ": ";
        std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
    }
    int p3[nintervals] = {};

    for (int i = 0; i < nrolls; ++i) {
        double number = new_results;
        if ((number >= -5.0) && (number < 15.0)) ++p3[int(number - first)];
    }

    std::cout << "extreme_value_distribution (2.0,6.0):" << std::endl;

    for (int i = 0; i < nintervals; ++i) {
        std::cout.width(2); std::cout << float(first + i) << "..";
        std::cout.width(2); std::cout << float(first + i + 1) << ": ";
        std::cout << std::string(p3[i] * nstars / nrolls, '*') << std::endl;
    }
    return 0;
}