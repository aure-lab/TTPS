#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct punto {
    long long x, y;

};

long long area_triangulo (punto a, punto b, punto c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


int main (){
    FIN;
    int n;
    cin >> n;
    long long x,y;
    long long suma=0;
    vector <punto> v(n);
    forn (i,n){
        cin >> x >> y;
        v[i].x = x;
        v[i].y = y;
    }

    for (int i = 1; i<n-1; i++){
        suma += area_triangulo(v[0], v[i], v[i+1]);
    }

    cout << abs(suma)  << "\n"; //! EL FABS VA A LO ULTIMO PORQUE SINO NO SE RESTAN LAS AREAS 
    return 0;
}