#include <bits/stdc++.h>
#include <vector>;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int x;
    for (int i=0 ; i<n ; i++){
        for (int j=0; j<3; j++){
            cin >> x;
            v[i] += x;
        }
    }
    x = 0;
    for (int i=0 ; i<n ; i++){
        if( v[i] >= 2){
            x++;
        }
    }
    cout << x;
    return 0;
}
