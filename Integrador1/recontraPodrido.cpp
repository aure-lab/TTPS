#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < (n); i++)


struct Point {
	long double x, y;
};

struct arista {
    int u, v;
    double w;
    bool operator<(const arista& other) const { return w < other.w; }
    arista(int u, int v, double w) : u(u), v(v), w(w) {}
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

double distancia(Point a, Point b) {
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}


int main (){
    FIN;
    int n;
    vector<Point> v(n);
    ll x,y;
    forn (i,n){
        cin >> x>> y;
        v[i].x=x;
        v[i].y=y;
    }

    vector<arista> g;
    arista a;

    forn (i,n){
        forn (j,n){
            if (i==j) continue;
            a.u = i;
            a.v = j;
            a.w = distancia(v[i],v[j]);
        }
    }
    vector<arista> res = kruskal(n*n, g);

    double maximo = -1;
    forn (i, res.size()){
        maximo = max (maximo, res[i].w);
    }

    cout << fixed << setprecision(10) << maximo << "\n"; 


}