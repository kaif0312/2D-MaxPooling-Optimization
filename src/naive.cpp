#include <iostream>
#include <vector>
#include <climits>
using namespace std;

namespace naive {
vector<vector<int>> getKMax(const vector<vector<int>>& matrix, int k) {
    int m = matrix.size(); // Get the size of the matrix
    vector<vector<int>> result;

    for (int i = 0; i <= m - k; ++i) {
        vector<int> row;
        for (int j = 0; j <= m - k; ++j) {
            int maxVal = INT_MIN;
            for (int p = i; p < i + k; ++p) {
                for (int q = j; q < j + k; ++q) {
                    maxVal = max(maxVal, matrix[p][q]);
                }
            }
            row.push_back(maxVal);
        }
        result.push_back(row);
    }

    return result;
}
}

// int main() {
//     // Example matrix
//     vector<vector<int>> matrix = {
//         {1, 2, 3, 4, 5},
//         {6, 7, 8, 9, 10},
//         {11, 12, 13, 14, 15},
//         {16, 17, 18, 19, 20},
//         {21, 0, 23, 0, 25}
//     };

//     int k = 3; // Size of the kernel

//     // Function call
//     vector<vector<int>> result = naive::getKMax(matrix, k);

//     // Print the result
//     for (const auto& row : result) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
