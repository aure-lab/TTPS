#include <bits/stdc++.h>
#include <vector>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MOD =1e9+7;
vector <int> memo (1000005, -1);

int solve (int x, int n, vector<int>& v){
    if (memo[x] != -1) return memo [x];
    memo [x]=0;
    for (int i=0; i<n; i++){
        if (x-v[i] < 0) break;
        if (x-v[i] == 0){
            memo[x] = (memo[x] +1) % MOD;
        }
        else
            memo [x] = (memo[x] + solve(x-v[i], n, v)) % MOD;
    }
    return memo[x];
}

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
    cout << solve(x, n, v);
    return 0;
}
