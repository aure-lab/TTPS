#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector <int> peso(n);
    vector <int> valor(n);

    for (int i= 0; i<n; i++){
        cin >> peso[i];
    }

    for (int i=0; i<n; i++){
        cin >> valor[i];
    }

    vector <int> anterior (x+1,0);

    vector <int> actual (x+1);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=x; j++){
            if ((j - peso[i-1]) >= 0)
                actual[j] = max (valor[i-1] + anterior[j-peso[i-1]],  anterior[j]);
            else
                actual[j] = anterior[j];
        }
        swap(anterior, actual);
    } 
    
    cout << anterior[x] << "\n";
}
