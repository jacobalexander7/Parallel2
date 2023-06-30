// Jacob Coomer
// CSC 4300 Chapter 8
// This program sums a vector of range(1, 100) using parallel programming 
// from the <thread> library

#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

using namespace std;

void calculate_partial_sum(const vector<int>& v, int start, int end, int& result) {
    result = accumulate(v.begin() + start, v.begin() + end, 0);
}

int main() {
    // Initialize a vector with values from 1 to 100
    vector<int> v(100);
    iota(v.begin(), v.end(), 1);

    // Storing the partial sums 
    int sum1 = 0;
    int sum2 = 0;

    // Create threads to calculate partial sums
    thread t1(calculate_partial_sum, cref(v), 0, v.size() / 2, ref(sum1));
    thread t2(calculate_partial_sum, cref(v), v.size() / 2, v.size(), ref(sum2));

    // Wait for threads to finish
    t1.join();
    t2.join();
    
    // Output should be 5050, the sum of numbers 1 - 100
    int total = (int)sum1 + (int)sum2;

    cout << "Sum is: " << total << endl;

    return 0;
}