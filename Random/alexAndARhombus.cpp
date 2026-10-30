#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main (){
    int n;
    cin >> n;

    vi dp (n+1);
    dp[0]=0;
    dp[1]=1;

    for (int i=2;i<=n;i++){
        dp[i] = dp[i-1] + ((2*i)+((i-2)*2));
    }
    cout << dp[n];
}