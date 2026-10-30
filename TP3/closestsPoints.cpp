#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vii vector<pair<ll,ll>>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main (){
    int n;
    ll x, y;
    cin >> n;
    
    vector<pair<ll, ll>> v;
    vector<double> res; 

    forn(i, n) {
        cin >> x >> y;
        v.pb({x, y});
    }

    double cuenta; 
    forn(i, n) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            ll dx = v[j].first - v[i].first;
            ll dy = v[j].second - v[i].second;

            cuenta = sqrt(dx * dx + dy * dy);
            res.pb(cuenta);
        }
    }
    
    cout << fixed << setprecision(10) << *min_element(res.begin(), res.end()) << "\n";

    return 0;
}