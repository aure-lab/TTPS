#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

vi v;

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

int main (){
    int t;
    cin >> t;
    ll n,x,y;

    forn (i,t){
        cin >> n >> x >> y;
        v.resize(n);
        DSU dsu = DSU (n);
        forn (i,n){
            cin >> v[i];
        }
        vi v2 = v;
        sort (v2.begin(),v2.end());

        map<int, int> idx; //! valor -> índice
        forn(i, n) idx[v[i]] = i;

        DSU dsu(n);
        forn(j, n) {
            auto it = idx.find(v[j] - x);
            if (it != idx.end()) dsu.join(j, it->second);

            it = idx.find(v[j] - y);
            if (it != idx.end()) dsu.join(j, it->second);
        }

        string s = "YES\n";
         bool ok = true;
        forn(w, n) {
            if (v[w] != v2[w]) {
                int pos = idx[v2[w]];
                if (!dsu.same(pos, w)) { ok = false; break; }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}