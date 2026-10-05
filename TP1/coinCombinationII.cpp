#include <bits/stdc++.h>
#include <vector>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int MOD =1e9+7;
 
int main(){
    FIN;
    int n;
    int x;
    cin >> n;
    cin >> x;
    vector<int> v (n);
    for (int i= 0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    vector<int> dp (x+1, 0);
    dp[0]=1;
    for (int j=0; j<n; j++){
        for (int i=1; i<x+1; i++){
            if(i-v[j] >= 0){
                dp[i] = (dp [i] + dp[i-v[j]] ) % MOD;
            }
            else break;
        }
    }
    cout << dp[x];
 
    return 0;
}