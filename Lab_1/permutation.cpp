#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

void permute(string &s, int l, int r) {
    if (l == r) {
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]); 
    }
}

int main() {
    cout << "InputSize\tAverageTime(us)\n";

    for (int size = 3; size <= 10; size++) {

        string s = "";
        for (int i = 0; i < size; i++)
            s += char('A' + i);  

        long long totalTime = 0;

        for (int i = 0; i < 100; i++) {

            auto start = high_resolution_clock::now();
            permute(s, 0, size - 1);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start);
            totalTime += duration.count();
        }

        double avgTime = (double)totalTime / 100;
        cout << size << "\t\t" << avgTime << endl;
    }

    return 0;
}


