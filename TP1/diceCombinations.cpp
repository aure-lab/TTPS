#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long MOD =1e9+7;

vector <long long> memo (1000005, 0);

int solve (long long n){
    if (memo[n] != 0) return memo[n];
    else{
        for (int i=1; i<=6; i++){
            if (n-i == 0) {
                memo[n]++;
                break;   
            }
            else
                memo[n] = ( memo[n] + solve (n-i)) % MOD;
        }
    }
    return memo[n];
}
int main() {
	long long n;
    cin >> n;
    cout << solve (n);
    return 0;

}