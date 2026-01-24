#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Given recursive function
int findTips(double v)
{
    if (v < 1.0)
        return 0;

    return 1 + findTips(v - 0.425);
}

int main() {

    int repetitions = 100;

    cout << "Input(v)\tAverageTime(us)\n";

    for (double v = 5; v <= 50; v += 5) {

        long long totalTime = 0;

        for (int i = 0; i < repetitions; i++) {

            auto start = high_resolution_clock::now();
            findTips(v);
            auto end = high_resolution_clock::now();

            totalTime += duration_cast<microseconds>(end - start).count();
        }

        double avgTime = (double)totalTime / repetitions;
        cout << v << "\t\t" << avgTime << endl;
    }

    return 0;
}