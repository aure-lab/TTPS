#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int find (vector <int>& p,  int x){
    if (x != p[x]){
        p[x] = find (p, p[x]);
    }
    return p[x];
}

void join (vector <int>& p, int x, int y, vector <int>& rank, int& maximo, int& cant){
    int a = find (p, x);
    int b = find (p, y);

    if (a == b) return;
    else if (rank[a] > rank[b]){
        p[b] = a;
        rank[a] += rank[b];
        maximo = max(maximo, rank[a]);
    }
    else{
        p[a] = b;
        rank[b] += rank[a];
        maximo = max(maximo, rank[b]);
    }
    cant--;

}



int main(){
    FIN;
    int n,m,a,b,maximo;
    maximo = -1;
    cin >> n >> m; 
    
    vector <int> rank (n+1, 1);
    vector <int> p (n+1);

    for (int i=0; i<= n; i++){
        p[i]=i;
    }

    vector <vector<long long >>  g (n+1);
    int cant = n;
    
    for (int i=0; i< m; i++){
        cin >> a; 
        cin >> b;
        
        join (p, a, b, rank, maximo, cant);
        cout << cant << " " << maximo << "\n";
    }
}