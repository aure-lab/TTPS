#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

int main (){
    int n;
    int x,y;
    
    cin >> n;
    vector<int> v(n);
    
    forn (i,n){
        cin>> x >> y;
        v[i] = x;
    }

    sort(v.begin(),v.end());

    vector <double> res (n-1,-1);
    forn (i,n-1){
        res[i] = v[i+1] - v[i];
    }

    cout << fixed << setprecision(10) << *max_element(res.begin(),res.end()) << "\n";

}