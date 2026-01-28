#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] & 1) == (arr[i + 1] & 1)) {
            return (arr[i] + arr[i + 1]) / 2;
        }
    }
    return -1;
}

int main() {

  int arr[20];
        
    for(int i=0;i<20;i++)
{
   cin>> arr[i];
}   
         cout<<findMissing(arr, 20);
           

    return 0;
}

