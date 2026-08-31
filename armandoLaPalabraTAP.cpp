#include <bits/stdc++.h>
using namespace std;


int main() {
    string tap = "TAP";
    int cont = 0;
    string s;
    cin >> s;
    int i = 0;
    while ((i<10)and(cont<3)){
        if (s[i] == tap[cont])
            cont++;
        i++;
    }
    
    if(cont == 3)
        cout << "S";
    else
        cout << "N";
        
    return 0;
}
