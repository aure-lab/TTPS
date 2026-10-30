#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const double EPS = 1e-9;
const long double PI = acos(-1.0);

struct punto {
    int x, y;
    
    double arg() {
        long double angle = atan2l(y,x);
        if(angle < -EPS) angle += PI * 2;
        return angle;
    }
};



int main (){
    FIN;
    int n;
    cin >> n;
    vector <punto> v(n);
    vector <double> res;
    forn (i,n)
        cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), [](punto a, punto b) {
        return a.arg() < b.arg();
    });

    double a1,a2;
    for (int i=0; i<n-1; i++){
        a1 = v[i].arg();
        a2 = v[i+1].arg();
        res.push_back(fabs(a1 -a2));

    }
    a1 = v[n-1].arg();
    a2 = v[0].arg() + 2*PI;
    res.push_back(fabs(a1-a2));

    double maximo= *max_element(res.begin(), res.end());
    double ans = (2 * PI - maximo) * 180.0 / PI; //* 180.0 / PI convierte a grados
            //* (2 * PI - maximo) le resta una vuelta completa
    
    cout << fixed << setprecision(10) << ans;
}