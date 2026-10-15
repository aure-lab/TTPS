#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vii vector<pair<ll,ll>>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back


// Topological sort
// Complexity: O(n+m)
vi tsort(vector<vi> &g, int n){  // lexicographically largest topological sort
    vi r; priority_queue<ll> q;
    vi d(2*n);
    forn(i, n) for(ll j: g[i]) d[j]++;
    forn(i, n) if(!d[i]) q.push(i);
    while(!q.empty()){
        ll x=q.top(); q.pop(); r.pb(x);
        for(ll j: g[x]){
            d[j]--;
            if(!d[j]) q.push(j);
        }
    }
    return r;
}

int main(){
    int t,n,m; 
    ll a,b;
    cin >> t;
    forn(i,t){
        cin >> n >> m;
        vector<vi> g(n);
        forn(i,n) for(int j=i+1;j<n;j++) g[i].pb(j); 
        forn(i,m){
            cin >> a >> b;
            a--; b--;
            auto it = find(all(g[a]), b);
            g[a].erase(it); 
        }
        vi res = tsort(g,n);

        for (int i: res){
            cout << i+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
// * ?????