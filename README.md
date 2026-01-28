# Algorithms

1. Power of x^n using Binary Exponentiation Recursive

Aim
To efficiently compute the value of x raised to the power n with minimum time complexity.

Algorithm

int power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int half = power(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}


Time Complexity
Time O(log n)
Space O(log n)

Use Case
Used in cryptographic algorithms such as RSA and Diffie Hellman.
Fast modular exponentiation in competitive programming.
Efficient computation of large powers.

2. Permutations of a String

Aim
To generate all permutations of a given string and analyze execution time as input size increases.

Algorithm

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


Time Complexity
Time O(n x n!)
Space O(n)

Use Case
Used in combinatorics, password generation, brute force search, and anagram problems.

3. Horner Rule

Aim
To evaluate a polynomial efficiently using recursion.

Algorithm

long long horner(const vector<int>& coeff, int x, int index) {
    if (index == coeff.size() - 1)
        return coeff[index];

    return coeff[index] + x * horner(coeff, x, index + 1);
}


Time Complexity
Time O(n)
Space O(1) iterative and O(n) recursive

Use Case
Used in polynomial evaluation, numerical methods, and compiler design.

4. Tower of Hanoi

Aim
To solve the Tower of Hanoi problem recursively and analyze execution time.

Algorithm

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0)
        return;

    hanoi(n - 1, source, destination, auxiliary);
    hanoi(n - 1, auxiliary, source, destination);
}


Time Complexity
Time O(2^n)
Space O(n)

Use Case
Classic example of recursion and divide and conquer strategy.

5. Bubble Sort and Selection Sort

Aim
To sort arrays of different sizes and compare execution time of Bubble Sort and Selection Sort.

Algorithm Bubble Sort

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


Algorithm Selection Sort

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}


Time Complexity
Bubble Sort O(n^2)
Selection Sort O(n^2)

Use Case
Used for educational purposes and small datasets.

6. Missing Number using LSB

Aim
To find a missing number in consecutive integers using bitwise operations.

Algorithm

int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] & 1) == (arr[i + 1] & 1)) {
            return (arr[i] + arr[i + 1]) / 2;
        }
    }
    return -1;
}


Time Complexity
Time O(n)
Space O(1)

Use Case
Used in bitwise problem solving and detecting missing elements.

7. findTips

Aim
To find the number of tips of balls until its velocity becomes less than 1.

Algorithm

int findTips(double v) {
    if (v < 1.0)
        return 0;

    return 1 + findTips(v - 0.425);
}


Time Complexity
Time O(v)
Space O(v)

Use Case
Used to understand recursion depth and linear recursion behavior.

8. Truth Table Generation

Aim
To generate truth tables for n boolean variables and analyze exponential growth.

Algorithm

void BTT(int k, int n) {
    if (k > n) {
        return;
    }

    a[k] = true;
    BTT(k + 1, n);

    a[k] = false;
    BTT(k + 1, n);
}


Time Complexity
Time O(2^n)
Space O(n)

Use Case
Used in digital logic design, boolean algebra, and circuit analysis.

9. Linear Search

Aim
To search for a given key element in an array using linear search.

Algorithm

void linear_search(int arr[], int n) {
    int target = rand();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            break;
        }
    }
}


Time Complexity
Best case O(1)
Average case O(n)
Worst case O(n)
Space O(1)

Use Case
Suitable for small datasets and unsorted arrays.
