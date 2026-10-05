#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main (){

    int n;

    cin >> n;
    
    vector <int> v (n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int maximo = *max_element(v.begin(), v.end()) + 1;

    vector <long long> cont (maximo+1, 0);

    vector <long long> dp (maximo+1, 0);

    for (int i: v){
        cont[i]++;
    }

    dp[1] = cont [1];
    dp[2] = cont [2] * 2;
    for (int i = 3; i<= maximo; i++){
        dp[i] = (cont[i]* i) + max(dp[i-2], dp[i-3]);
    }

    cout << *max_element(dp.begin(), dp.end());

}