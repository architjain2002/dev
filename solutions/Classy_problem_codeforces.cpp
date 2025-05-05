// #include <bits/stdc++.h>
// https://codeforces.com/contest/1036/problem/C
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
    long long combination(int pos, int count, int tight, vector<vector<vector<long long>>>& dp, string& nums) {
        if (pos == nums.size()) {
            if (count <= 3) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[pos][count][tight] != -1) return dp[pos][count][tight];

        int upperLimit = (tight == 1) ? (nums[pos] - '0') : 9;

        long long ans = 0;

        for (int i = 0; i <= upperLimit; i++) {
            int newTight = tight && (i == upperLimit);
            int newCount = count + (i != 0);
            if(newCount <=3){
                ans = ans + combination(pos + 1, newCount, newTight, dp, nums);
            }
        }

        return dp[pos][count][tight] = ans;
    }

public:
    long long solve(long long L, long long R) {
        string left = to_string(L - 1);
        string right = to_string(R);

        vector<vector<vector<long long>>> dp(20, vector<vector<long long>>(4, vector<long long>(2, -1)));

        long long rightAns = combination(0, 0, 1, dp, right);
        dp.assign(20, vector<vector<long long>>(4, vector<long long>(2, -1)));
        long long leftAns = combination(0, 0, 1, dp, left);

        return rightAns - leftAns;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;

    while(T--){
        long long L,R;
        cin >> L >> R;

        Solution sol;
        long long ans = sol.solve(L,R);
        cout << ans << endl;
    }

    return 0;
}