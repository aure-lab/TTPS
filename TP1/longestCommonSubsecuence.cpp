#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
	int n,m;
	cin >> n >> m;
	vector<long long> v1(n);
	vector<long long> v2(m);
	
	forn (i,n)
	    cin >> v1[i];
	   
	forn (i,m)
	    cin >> v2[i];
	    
    vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));
    
    for (int i =1; i<=n; i++){
        for (int j=1;j<=m; j++){
            if (v1[i-1] == v2[j-1])
                dp[i][j] = max (dp[i-1][j-1]+1, dp[i][j]);
            else
                dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << "\n";

    int i= n;
    int j = m;
    vector<long long> res;
    while ((j>0) and (i>0)){
        if (v1[i-1] == v2[j-1]){
            res.push_back(v1[i-1]);
            i--;j--;
        }
        else
            if (dp[i][j-1] > dp[i-1][j]) j--;
            else i--;
    }
    reverse(res.begin(),res.end());
    forn (i,res.size())
        cout << res[i] << " ";
    cout << "\n";
    

}
