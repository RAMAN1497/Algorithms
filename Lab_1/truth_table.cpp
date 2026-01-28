#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool a[20];   // Array to store T/F values

// Recursive Backtracking Truth Table Generator
void BTT(int k, int n)
{
    if (k > n)
    {
        return;
    }

    a[k] = true;      
    BTT(k + 1, n);    

    a[k] = false;     
    BTT(k + 1, n);    
}

int main()
{

    cout << "Inputs(n)\tAverageTime(us)\n";

    for (int n = 2; n <= 15; n++)
    {
        long long totalTime = 0;

        for (int i = 0; i < 100; i++)
        {
            auto start = high_resolution_clock::now();
            BTT(1, n);
            auto end = high_resolution_clock::now();

            totalTime += duration_cast<microseconds>(end - start).count();
        }

        double averageTime = (double)totalTime / 100;
        cout << n << "\t\t" << averageTime << endl;
    }

    return 0;

}
