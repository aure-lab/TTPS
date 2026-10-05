#include <bits/stdc++.h>
#include <vector>;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0 ; i<n ; i++){
        cin >> v[i];
    }
    for (int i=0 ; i<n ; i++){
        if (v[i].length() > 10){
            cout << v[i][0] << v[i].length() -2 << v[i].back() << "\n";
        }
        else {
            cout << v[i] << "\n";
        }
    }
    return 0;
}
