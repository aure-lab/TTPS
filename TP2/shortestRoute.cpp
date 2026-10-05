#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long tipo;
const int MAXN = 200005;

struct arista {
    int x; tipo w;
    arista (int x, tipo w){
        this->x =x;
        this->w = w;
    }
};

struct nodo {
    tipo d, v, a;
    bool operator<(const nodo& x) const {return d > x.d;}
};

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
    vector<nodo> ans(n+1);
    vector<bool> visto(n+1, false);
    priority_queue<nodo> p; p.push({0,start,-1});
    while(!p.empty()) {
        nodo it=p.top(); p.pop();
        if(visto[it.v]) continue;
        else {
            ans[it.v] = it; visto[it.v] = true;
            for(arista u : g[it.v]) {
                if(!visto[u.x]) p.push({it.d + u.w, u.x, it.v});
            }
        }
    }
    return ans;
}



int main (){

    tipo n,m,c;
    cin >> n >> m;
    int a,b;
    vector<vector<arista>> g (n+1);
    for (int i=0; i <m; i++){
        cin >> a >> b >> c;
        g[a].push_back(arista(b,c));
    }

    vector <nodo> r = Dijkstra(1,n,g);

    for (int i=1; i<r.size(); i++){
        cout << r[i].d << " "; 
    }
    cout << "\n";
}