#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

// casi criba
int main (){
    FIN;
    vector<bool> v;
    ll q,l,r;
    cin >> q;

    forn (i,q){
        cin >> l >> r;
        v.resize(r+1,false);
        v[1] = true;
        for (int j=2; j<=r; j++){
            if (v[j]) continue;
            else {
                int k =2;
                while ((j*k)<=r){
                    v[j*k] = true;
                    k++;
                }
            }
        }
        int cont = 0;
        for (int i=l; i<=r; i++)
            if (!v[i]) cont ++;
        cout << cont << "\n";
    }
}