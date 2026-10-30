#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;


int main (){
    int n;
    cin >> n;
    vector<int>v (n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> dp(n,1);

    for (int i =1; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[j] % v[i] == 0){
                dp[i] = max(dp[i], dp[j]+1);
                break;
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}