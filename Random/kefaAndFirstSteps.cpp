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
    vi v(n);
    forn (i,n)
        cin >> v[i];
    
    vi dp (n+1,1);

    for (int i=1; i<n; i++){
        if (v[i] >= v[i-1]){
            dp[i] = dp[i-1] +1;
        }
    }
    cout << *max_element(dp.begin(),dp.end());
}