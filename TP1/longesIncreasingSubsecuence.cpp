#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MOD =1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>v (n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> dp(n,1);

    for (int i =1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(v[j] < v[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
    