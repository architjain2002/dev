#include <bits/stdc++.h>
using namespace std;


class Solution{
    private:
        void combination(int k, int i, vector<int>& arr, vector<vector<int>>& ans, vector<int> sol){
            if(k == 0) {
                ans.push_back(sol);
                return;
            }

            for(int ii=i;ii<arr.size();ii++){
                sol.push_back(arr[ii]);;
                combination(k-1,ii+1,arr, ans, sol);
                sol.pop_back();
            }
        }
    public:
        int solve(vector<int>& arr, int k){
            vector<vector<int>> ans;

            combination(k,0,arr,ans,{});
            for (int i = 0; i < ans.size(); i++)
            {
                for(int j=0;j<k;j++){
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    Solution sol;
    sol.solve(arr, k);

    return 0;
}