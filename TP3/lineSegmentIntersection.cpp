#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct punto {
    long long x, y;

};

struct segmento {
    punto p1, p2;
    segmento (punto punto1, punto punto2){
        p1 = punto1;
        p2 = punto2;
    }
};

int sentido (punto& p1, punto& p2, punto& p3){
    long long cross = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (cross > 0) return 1;
    else if (cross < 0) return -1;
    else return 0;
}


bool point_in_box (punto p1, punto p2, punto p){
    return (p.x >= min (p1.x,p2.x) and (p.x <= max (p1.x,p2.x))
            and (p.y >= min(p1.y,p2.y)) and (p.y <= max (p1.y,p2.y)));
}

int main (){
    FIN;
    int t;
    long long x, y;
    cin >> t;
    punto p1,p2,p3,p4;
    forn (j,t){

        cin >> x;
        cin >> y;
        p1.x = x; 
        p1.y = y;
        cin >> x;
        cin >> y;
        p2.x = x;
        p2.y = y;
        segmento s1 (p1,p2);

        cin >> x;
        cin >> y;
        p3.x = x; 
        p3.y = y;
        cin >> x;
        cin >> y;
        p4.x = x;
        p4.y = y;
        segmento s2 (p3,p4);

        int d1,d2,d3,d4;
        d1 = sentido (s2.p1, s2.p2, s1.p1);
        d2 = sentido (s2.p1, s2.p2, s1.p2);
        d3 = sentido (s1.p1, s1.p2, s2.p1);
        d4 = sentido (s1.p1, s1.p2, s2.p2);
        if (((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)))
            cout << "YES\n";
        else 
            if ((d1==0 and point_in_box(s2.p1,s2.p2,s1.p1))
                or (d2==0 and point_in_box(s2.p1,s2.p2,s1.p2))
                or (d3==0 and point_in_box(s1.p1,s1.p2,s2.p1))
                or (d4==0 and point_in_box(s1.p1,s1.p2,s2.p2)))
                cout << "YES\n";
            else 
                cout << "NO\n";

    }
}