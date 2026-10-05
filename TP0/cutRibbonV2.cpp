#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main (){

    int n, a, b , c;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    vector <int> v =  {a,b,c};
    int aux = n; 
    int maximo = -999;
    int cant = 0;
    int result= 0;
    for (int i= 0; i< n + 1; i++){
        for (int j = 0; j< n + 1; j++){
            result = i*a + j*b;
            int falta = n - result;
            if (falta < 0) break;
            if ((falta % c) != 0) continue;
            cant = i + j + (falta / c);
            maximo = max(maximo, cant);
        }
    }
    
    cout << maximo<< "\n";

    return 0;

} 