#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

struct arista {
    int u, v;
    ll w;
    bool operator<(const arista& other) const { return w < other.w; }
    arista(int u, int v, ll w) : u(u), v(v), w(w) {}
};

struct DSU {
    vi link, sz;

    DSU(int tam) {
        link.resize(tam + 5), sz.resize(tam + 5);
        forn(i, tam + 5) link[i] = i, sz[i] = 1;
    }

    int find(int x) { return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(int a, int b) { return find(a) == find(b); }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        link[b] = a;
    }
};

vector<arista> kruskal(int n, vector<arista>& g) {
    sort(all(g));
    DSU dsu(n);
    vector<arista> mst;
    for (arista e : g) {
        if (!dsu.same(e.v, e.u)) {
            dsu.join(e.v, e.u);
            mst.pb(e);
        }
    }
    return mst;
}

int main() {
    int n, m, a, b;
    ll c;
    cin >> n >> m;
    vector<arista> g;
    forn(i, m) {
        cin >> a >> b >> c;
        g.pb(arista(a, b, c));
    }
    vector<arista> r = kruskal(n, g);
    if (r.size() != n-1)
        cout << "IMPOSSIBLE" << "\n";
    else{
        ll cant = 0;
        for (arista e : r) cant += e.w;
            cout << cant << "\n";
    }
        
    return 0;
}
