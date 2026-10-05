#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

void DFS (int v, vector <vector<int>>& g, vector <bool>& visitado ){
    visitado[v] = true;
    for (int a: g[v]){
        if (!visitado[a])
            DFS(a,g,visitado);
    }
}

int main (){
    int n,m,a,b;
    int cont = -1;

    cin >> n >> m;
    vector <vector<int>> g (n+1);

    vector <bool> visitado (n+1, false);

    for (int i =0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector <int> r;

    for (int i=1; i<=n; i++ ){
        if (! visitado[i]){
            if (i!=1){
                cont++;
                r.push_back(i-1);
                r.push_back(i);
            }
            DFS(i, g, visitado);
        }
    }

    cout << cont << "\n";
    for( int i = 0; i< r.size()/2; i+=2){
        cout << r[i] << " " << r[i+1];
    }

}