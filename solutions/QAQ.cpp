#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


class Solution{
    
private:
    int lcs(string& str, string& pat, int n, int m, vector<vector<int>>& dp){
        if(n == 0 && m==0) return 1;
        if(n == 0) return 0;
        if(m == 0) return 1;

        if(dp[n][m] != -1) return dp[n][m];

        if(str[n-1] == pat[m-1]){
            return dp[n][m] = lcs(str, pat, n-1,m, dp) + lcs(str, pat, n-1, m-1, dp);    
        }
        else{
            return dp[n][m] = lcs(str, pat, n-1,m, dp);
        }
    }
public:
    ll solve(string& str) {
        string pat = "QAQ";
        vector<vector<int>> dp(str.size()+1, vector<int>(pat.size()+1,-1));
        
        return lcs(str, pat, str.size(), pat.size(), dp);
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str;
    cin >> str;
    Solution sol;
    ll ans = sol.solve(str);
    cout << ans << endl;

    return 0;
}