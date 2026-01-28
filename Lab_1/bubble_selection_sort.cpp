#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                minIdx = j;
        }
        swap(arr[i], arr[min]);
    }
}

int main() {
cout << "InputSize\tBubbleSort(ms)\tSelectionSort(ms)\n";

    for (int n = 1000; n <= 7000; n += 1000) {

        vector<int> original(n);
        for (int i = 0; i < n; i++)
            original[i] = rand() % 100000;

        long long bubbleTime = 0;
        long long selectionTime = 0;

        for (int i = 0; i <100 i++) {
            vector<int> arr = original;

            auto start = high_resolution_clock::now();
            bubbleSort(arr);
            auto end = high_resolution_clock::now();

            bubbleTime += duration_cast<milliseconds>(end - start).count();
        }

        for (int i = 0; i <100; i++) {
            vector<int> arr = original;

            auto start = high_resolution_clock::now();
            selectionSort(arr);
            auto end = high_resolution_clock::now();

            selectionTime += duration_cast<milliseconds>(end - start).count();
        }

        cout << n << "\t\t" << bubbleTime / 100 << "\t\t" << selectionTime / 100 << endl;
    }

    return 0;
}


