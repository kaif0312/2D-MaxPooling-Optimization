#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <limits>
using namespace std;
namespace optimized_1{
vector<int> maxSliding_1d_Window(vector<int>& arr, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int> > heap;
 
    // Initialize the heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });
 
    // The maximum element in the first window
    ans.push_back(heap.top().first);
 
    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {
 
        // Add the current element to the heap
        heap.push({ arr[i], i });
 
        // Remove elements that are outside the current
        // window
        while (heap.top().second <= i - k)
            heap.pop();
 
        // The maximum element in the current window
        ans.push_back(heap.top().first);
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
