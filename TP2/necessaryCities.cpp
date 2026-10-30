#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vii vector<pair<ll,ll>>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

struct edge{ ll u, v, id; };

struct graph{
    int n;
    vector<vii> adj; // (to, id)
    vector<edge> edges;
    graph(int _n) : n(_n), adj(_n) {}

    void add_edge(ll u, ll v){
		ll id = edges.size();
        adj[u].pb({v, id}); adj[v].pb({u, id});
        edges.pb({u, v, id});
    }

    int add_node(){ adj.pb({}); return n++; }
    vii& operator[](ll u) { return adj[u]; }
};

struct BCC{
    int n; graph adj;
    vector<vi> comps;
    vi num, low, art, stk, bridge;
    BCC(graph &_adj): n(_adj.n), adj(_adj){
        num.resize(n), low.resize(n), art.resize(n), bridge.resize(adj.edges.size());
        for (ll u = 0, t; u < n; ++u) if (!num[u]) dfs(u, -1, t = 0);
    }

    void dfs(ll v, ll p, ll &t){
        num[v] = low[v] = ++t;
        stk.pb(v);

        for(auto [u, id]: adj[v]) if (u != p){
            if (!num[u]){
                dfs(u, v, t);
                low[v] = min(low[v], low[u]);
				
				if(low[u] > num[v]) bridge[id] = true;
                if(low[u] >= num[v]){
                    art[v] = (num[v] > 1 || num[u] > 2);

                    comps.pb({v});
                    while (comps.back().back() != u)
                        comps.back().pb(stk.back()), stk.pop_back();
                }
            }
            else low[v] = min(low[v], num[u]);
        }
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    graph g(n);
    ll a, b;
    forn(i,m){
        cin >> a >> b;
        a--; b--;
        g.add_edge(a,b);
    }
    BCC bbc (g);

    vi res;
    forn(i, n){
        if (bbc.art[i]){
            res.pb(i+1);
        }
    }

    cout << res.size() << "\n";
    for (auto v : res ){
        cout << v << " ";
    }
    cout << "\n";
    return 0;

}