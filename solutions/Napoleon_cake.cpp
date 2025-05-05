#include <iostream>
#include <vector>
#include <algorithm> // Added for std::max

using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        // kadane's algorithm
        // Calculate the maximum reach from right to left
        int maxReach = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxReach = max(maxReach, arr[i]);
            if (maxReach > 0) {
                ans[i] = 1;
                maxReach--;
            }
        }

        return ans;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution sol;
        vector<int> ans = sol.solve(arr);

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}