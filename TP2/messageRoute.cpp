#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs (vector <vector<int>>& g, vector<bool>& visitado, int n){
    vector <int> camino;
    vector padre(n+1,-1);
    queue <int> c;
    c.push(1);
    visitado[1] = true;
    while (!c.empty()){
        int t = c.front();
        c.pop();
        for (int v : g[t]){
            if (!visitado [v]){
                if (v == n){
                    padre[n] = t;
                    int i = n;
                    while (i != -1){
                        camino.push_back(i);
                        i = padre [i];
                    }
                    reverse(camino.begin(), camino.end());
                    return camino;
                }
                else {
                    padre[v] = t;
                    visitado[v] = true;
                    c.push(v);
                }
            }
        }
    }
    
    return {};
}



int main() {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> g (n+1);
    vector <bool> visitado (n+1, false);
    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector <int> result = bfs (g, visitado, n);
    if (result.size() == 0)
        cout << "IMPOSSIBLE" << "\n";
    else{
        cout << result.size() << "\n";
        for (int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
    }
}
