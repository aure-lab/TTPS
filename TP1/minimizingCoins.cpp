#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MOD =1e9+7;
const int INF = 1e9;
int main() {
	int n;
    int x;
	cin >> n;
    cin >> x;
    vector <int> v (n);
    vector<int> dp (x+1, INF);
    for (int i=0; i<n ; i++)
        cin >> v[i];
	sort (v.begin(), v.end());
    dp[0] = 0;
    for (int i=1; i<x+1; i++){
        for (int j=0; j<n; j++){
            if (i-v[j] >= 0)
                dp[i] = min(dp[i], (dp[i-v[j]]+1) % MOD);
            else break;
        }
    }
    if (dp[x] == INF) cout << -1;
    else cout << dp[x];
}
