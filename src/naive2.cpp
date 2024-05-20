#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <limits>
// #include <naive.h>
using namespace std;
namespace naive2{
vector<int> maxSliding_1d_Window(vector<int>& arr, int k)
{
    vector<int> ans;
    int j, max;
    int n = arr.size();
    for (int i = 0; i <= n - k; i++) {
        max = arr[i];
 
        for (j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
    ans.push_back(max);
    }
    return ans;
}
vector<vector<int>> maxSliding_2d_Window(vector<vector<int>>& v, int k) {
    int n = v.size();
    int m = v[0].size();

    // Calculating sliding window horizontally
    vector<vector<int>> horizontal;
    for (int i = 0; i < n; i++) {
        vector<int> part = maxSliding_1d_Window(v[i], k);
        horizontal.push_back(part);

    }
    // for (auto& row : horizontal) {
    //     for (int num : row) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> final(n - k + 1, vector<int>(m - k + 1, numeric_limits<int>::min())); // Initialize with INT_MIN
    int c = 0;

    // Calculating sliding window vertically
    for (int j = 0; j < horizontal[0].size(); j++) {
        vector<int> v;
        for (int i = 0; i < horizontal.size(); i++) {
        v.push_back(horizontal[i][j]);
        }
        
        vector<int> tmp = maxSliding_1d_Window(v,k);

        // Pushing the result into the resultant matrix
        for (int index = 0; index < n - k + 1; index++) {
            final[index][c] = tmp[index];
        }
        c++;
    }


    // Return final matrix
    return final;
}
}