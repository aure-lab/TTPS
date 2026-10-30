#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <vector>
#define vi vector<int>
#define vii vector<pair<ll,ll>>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

int sentido (ll x1,ll x2,ll x3,ll y1,ll y2,ll y3){
    ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross > 0) return 1;
    else if (cross < 0) return -1;
    else return 0;
}

int main (){
    int n;
    vii v;
    cin >> n; 
    ll x, y;
    forn (i,n){
        cin >> x >> y;
        v.pb({x,y});
    }
    
    if (n<3)
        cout <<  "NO" << "\n";
    
    else {
        bool ok = true;
        int s = sentido(v[0].first, v[1].first, v[2].first, v[0].second, v[1].second, v[2].second);
        int i = 3;
        while ((i<n) and (ok)){
            ok = s == sentido(v[i-2].first, v[i-1].first, v[i].first, v[i-2].second, v[i-1].second, v[i].second);
            i++;
        }
        if (ok)
            ok = s == sentido(v[i-2].first, v[i-1].first, v[0].first, v[i-2].second, v[i-1].second, v[0].second);
        
        if (ok) cout << "YES" << "\n";
        else cout <<  "NO" << "\n";
    }
    return 0;
}