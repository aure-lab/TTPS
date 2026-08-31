#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve (vector<int> v, int n, int cantCortes, int& maximo){
    if (n == 0){
        if (cantCortes > maximo)
            maximo = cantCortes;
    }
    else{
        for (int i = 0; i<3; i++){
            if((n - v[i]) >= 0)
                solve(v, n - v[i], cantCortes + 1, maximo);
        }
    }
}

int main() {
	int n, a, b, c;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	vector <int> v= {a, b, c};
	int maximo = -999;
    if ((v[0] == 1) or (v[1] == 1) or (v[2] == 1)){
        cout << n;
    }
    else{
        solve (v,n,0,maximo);
        cout << maximo;
    }
}
