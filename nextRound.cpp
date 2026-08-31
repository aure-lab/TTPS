#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    
    int n;
    int k;
    int ganadores = 0;
    
    cin >> n;
    cin >> k;
    
    vector<int> participantes(n);
    
    for (int i = 0; i<n; i++){
        cin >> participantes[i];
    }
    
     for (int i = 0; i<n; i++){
        if ((participantes[i] >= participantes[k-1]) and (participantes[i] > 0))
            ganadores ++;
    }
    
    
    cout << ganadores;
    return 0;
}
