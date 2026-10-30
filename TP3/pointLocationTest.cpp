#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < (n); i++)

int main() {
    int t;
    cin >> t;
    forn (i,t) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

        if (cross > 0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }
}