#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main (){
    int n,v;
    cin >> n >> v;

    if (n-1<=v){
        cout << n-1 << "\n";
    }

    else{
        int fuel=v;
        vi dp(n+1);
        dp[1] = v;
        for (int i=2; i<=n; i++){
            fuel--;
            dp[i] = dp[i-1];
            if (fuel < (n-i)){
                dp[i] = dp[i] + i;
                fuel++;
            }
            else continue;
        }
        cout << dp[n] << "\n";
    }
}