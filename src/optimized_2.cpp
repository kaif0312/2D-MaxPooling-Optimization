#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <limits>
using namespace std;
namespace optimized_2{
class MaxQ {
public:
    queue<int> q;
    deque<int> dq;

    void push(int x) {
        q.push(x);
        while (!dq.empty() && x > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void pop() {
        if (q.front() == dq.front()) {
            q.pop();
            dq.pop_front();
        } else {
            q.pop();
        }
    }

    int max() {
        return dq.front();
    }
};

vector<int> maxSliding_1d_Window(vector<int>& v, int k) {
    MaxQ q;
    int n = v.size();
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        q.push(v[i]);
    }
    for (int i = k; i < n; i++) {
        ans.push_back(q.max());
        q.pop();
        q.push(v[i]);
    }
    ans.push_back(q.max());
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