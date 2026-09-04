#include <bits/stdc++.h>
#include <vector>
using namespace std;


vector <int> memo (4005, -1);

int solve (vector<int> v, int n, int cantCortes, int& maximo){
    if(memo[n] != -1)
        return memo [n];
    else{
        for (int i = 0; i<3; i++){
            if((n - v[i]) == 0) {
                maximo = max(maximo, cantCortes + 1);
            }
            else {
                if ( n - v[i]  > 0)
                    memo [n-v[i]] = solve(v, n - v[i], cantCortes + 1, maximo);
            }
        }           
        return cantCortes;
    }
}

int main() {
	int n, a, b, c;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	vector <int> v= {a, b, c};
	sort (v.begin(), v.end());
	int maximo = -999;
    if ((v[0] == 1) or (v[1] == 1) or (v[2] == 1)){
        cout << n;
    }
    else{
        solve (v,n,0,maximo);
        cout << maximo;
    }
}
