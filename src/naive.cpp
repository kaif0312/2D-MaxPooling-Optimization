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