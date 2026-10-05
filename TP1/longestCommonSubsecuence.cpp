#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MOD =1e9+7;
int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    vector <int> v1 (n);
    vector<int> v2 (m);

    for (int i=0; i<n; i++){
        cin >> v1[i];
    }
    for (int i=0; i<m; i++){
        cin >> v2[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 0;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if (v1[i-1] == v2[j-1]){
                dp[i][j] = max (dp[i][j], dp[i-1][j-1] + 1);
            }
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    vector <int> result;
    cout << dp[n][m] << "\n";
    int i = n; 
    int j= m;
    
        while ((j>0) && (i>0)){
            if (v1[i-1] == v2[j-1]){
                result.push_back(v1[i-1]);
                j--; i--;
            }
            else{
                if (dp[i-1][j] >= dp[i][j-1]) i--;
                else j--;
            }  
        }
    reverse(result.begin(), result.end());
    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    
}
