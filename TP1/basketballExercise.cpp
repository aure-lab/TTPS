#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

int main (){
    FIN;
    int n;
    cin >> n;
    vector<int> v1 (n);
    vector<int> v2 (n);
    forn (i,n)
        cin >> v1[i];
    forn (i,n)
        cin >> v2[i];

    vector <vector<ll>> dp(n);

    ll equipo1 = 0;
    ll equipo2 = 0;

    forn (i,n){
        ll a = max (equipo1, v1[i] + equipo2);
        ll b = max (equipo2, v2[i] + equipo1);
        equipo1 = a;
        equipo2 = b;
    }

    cout << max (equipo1, equipo2) << "\n";


    
}