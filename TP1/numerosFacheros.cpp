#include <bits/stdc++.h>
#include <vector> 
using namespace std;

long long MOD =1e9+7;

vector<vector<long long>> memo(200005, vector<long long>(10, -1));

long long solve (int k, int x){
    if (memo [k][x] != -1 ) return memo[k][x];
    
    if (k == 1) {memo[k][x] = 1;}
    else{
        if (x == 1) {memo [k][x] = solve (k-1, 3);}
        else{
            if (x == 9){ memo [k][x] = solve (k-1, 7);}
            else {memo [k][x] = solve (k-1, x-2) + solve (k-1, x+2)%MOD;}
        }
    }
    return memo [k][x];
}

int main() {
	long long k; 
    cin >> k;

    cout << ((((solve(k,1) + solve(k,3))%MOD + solve(k,5))%MOD + solve(k,7))%MOD + solve (k,9))%MOD << "\n";

    return 0;
}
