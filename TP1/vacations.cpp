#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main (){
    FIN;
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i,n){
        cin >> v[i];
    }

    int anterior = 0;
    int cont = 0;
    forn (i,n){
        if ((anterior == 1) and (v[i] == 2 or v[i] == 3)) {
            anterior = 2; // gym
        }
        else if ((anterior == 2) and (v[i] == 1 or v[i] == 3)) {
            anterior = 1; // contest
        }
        else if (anterior == 0){
            if (v[i] == 3){
                if (i+1 == n) break;
                int j = i + 1;
                int tres = 0;
                while (j < n and v[j] == 3){
                    tres++;
                    j++;
                }
                if (j == n) {
                    anterior = 1;        
                }
                else if (tres % 2 == 0){
                    if (v[j] == 1) anterior = 2;
                    else anterior = 1;
                }
                else {
                    if (v[j] != 0) anterior = v[j];
                    else anterior = 1;
                }
            }
            else {
                if (v[i] == 0) cont++;
                anterior = v[i];
            }
        }
        else {
            anterior = 0;
            cont++;
        }
    }

    cout << cont << "\n";
}