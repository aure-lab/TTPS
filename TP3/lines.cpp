#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const double EPSILON = 10e-9;

// a = y1 - y2
// b = x2 - x1
// c = x1*y2 - x2*y1

struct punto {
    long double x, y;

};

struct linea {
    long double a,b,c;
    linea (punto p1, punto p2){
        if (p1.x == p2.x) {   // vertical
            a = 1.0;
            b = 0.0;
            c = -p1.x;
        } else {
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(a * p1.x) - (b * p1.y);
        }
    }

};

bool parallel (linea l1, linea l2){
    return fabs(l1.a -l2.a) <= EPSILON and fabs (l1.b-l2.b) <= EPSILON;
}

bool same (linea l1, linea l2){
    return parallel(l1,l2) and fabs(l1.c - l2.c) <= EPSILON;
}

punto intersect (linea l1, linea l2){
    punto p;
    p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > EPSILON)
        p.y = -(l1.a * p.x + l1.c) / l1.b;
    else 
        p.y = -(l2.a * p.x +l2.c ) / l2.b;
    return p;
}

int main (){
    FIN;
    int t;
    long long x, y;
    cin >> t;
    punto p1,p2;
    forn (j,t){

        cin >> x;
        cin >> y;
        p1.x = x; 
        p1.y = y;
        cin >> x;
        cin >> y;
        p2.x = x;
        p2.y = y;
        linea l1 (p1,p2);
        cin >> x;
        cin >> y;
        p1.x = x; 
        p1.y = y;
        cin >> x;
        cin >> y;
        p2.x = x;
        p2.y = y;
        linea l2 (p1,p2);
        
        if (same (l1,l2))
            cout << "SAME" << "\n";
        else
            if (parallel(l1,l2))
                cout << "PARALLEL" << "\n";
        else{
            p1 = intersect(l1,l2);
            cout <<fixed << setprecision (10) << p1.x << " " << p1.y << "\n";
        }
    }
}