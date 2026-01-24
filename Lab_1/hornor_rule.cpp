#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Horner's Rule function
long long horner(const vector<int>& coeff, int x, int index) {
    // Base case: last coefficient
    if (index == coeff.size() - 1)
        return coeff[index];

    // Recursive call
    return coeff[index] + x * horner(coeff, x, index + 1);
}

int main() {

    int repetitions = 100;
    int x = 2;

    cout << "Degree\tAverageTime(us)\n";

    for (int degree = 100; degree <= 1000; degree += 100) {

        vector<int> coeff(degree + 1, 1); // all coefficients = 1
        long long totalTime = 0;

        for (int i = 0; i < repetitions; i++) {

            auto start = high_resolution_clock::now();
            horner(coeff, x,0);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start);
            totalTime += duration.count();
        }

        double avgTime = (double)totalTime / repetitions;
        cout << degree << "\t" << avgTime << endl;
    }

    return 0;
}
