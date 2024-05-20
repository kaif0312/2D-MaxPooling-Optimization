#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // For max_element
#include <limits> // For numeric_limits
#include "optimized_1.h"
#include "optimized_2.h"
#include "naive2.h"
#include "naive.h"
// #include "naive_parallel.h"
using namespace std;


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
     int m, k;
    cout << "Enter the size of the matrix (m x m): ";
    cin >> m; // Input matrix size
    cout << "Enter the size of the window (k x k): ";
    cin >> k; // Input window size

    // Generate a random matrix
    vector<vector<int>> matrix(m, vector<int>(m));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = rand() % 100; // Random values between 0 and 99
        }
    }
    // cout << "Generated Matrix:" << endl;
    // printMatrix(matrix);
    // cout << endl;

    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> resultVeryNaive = naive::getKMax(matrix, k);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationVeryNaive = end - start;
    // cout << "Naive max pooling result:" << endl;
    // printMatrix(resultVeryNaive);
    cout << "Very Naive max pooling duration: " << durationVeryNaive.count() << " seconds" << endl;
    // Measure performance of each algorithm
    start = chrono::high_resolution_clock::now();
    vector<vector<int>> resultNaive = naive2::maxSliding_2d_Window(matrix, k);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationNaive = end - start;
    // cout << "Naive max pooling result:" << endl;
    // printMatrix(resultNaive);
    cout << "Naive max pooling duration: " << durationNaive.count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    vector<vector<int>> resultOptimized = optimized_1::maxSliding_2d_Window(matrix, k);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationOptimized = end - start;
    // cout << "Optimized max pooling result:" << endl;
    // printMatrix(resultOptimized);
    cout << "Max Heap Optimization duration: " << durationOptimized.count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    vector<vector<int>> resultOptimized2 = optimized_2::maxSliding_2d_Window(matrix, k);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> durationOptimized2 = end - start;
    // cout << "Optimized2 max pooling result:" << endl;
    // printMatrix(resultOptimized2);
    cout << "Queue Dequeue Optimization duration: " << durationOptimized2.count() << " seconds" << endl;




    return 0;
}
