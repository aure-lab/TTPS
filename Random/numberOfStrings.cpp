#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define forr(i, a, b) for(int i=(a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)

ll MOD = 998244353;
ll n, k, a;
ll binpow(ll a, ll b){
	ll res = 1;
	while (b > 0){
		if (b % 2 == 1) res=res * a % MOD;
		a=a*a%MOD;
		b/=2;
	}
	return res;
}
ll factorial(ll a){
	ll res = 1;
	forr(i, 1, a+1){
		res=res*i%MOD;
	}
	//cout << "FACTORIAL DE " << a << ": " << res << endl;
	return res;
}

ll inverso_modular(ll x, ll m=MOD) { return binpow(x, m-2); }

ll tomadoDe(ll j, ll b){
	ll num1 = factorial(j);
	ll num2 = factorial(b);
	ll num3 = factorial(j-b);
	ll res1 = num2*num3%MOD;
	res1= inverso_modular(res1, MOD);
	ll resp = num1*res1%MOD;
	//cout << "RESULTADO TOMADO DE: " << resp << endl;
	return resp;
}

ll cantidadDeA(){
	ll p1 = binpow(a, 2);
	ll resultado = n-k-2;
	ll p2 = binpow(a-1, resultado);
	ll fin =p1*p2%MOD; 
	//cout << p1 << " " << p2 << endl;
	return fin;
}

void solve(){
	
	cin >> n >> k >> a;
	
	if (n == 1) {
        cout << (k == 0 ? a % MOD : 0) << "\n";
        return;
    }
	
	if (k > n-2) {
		cout << 0 << "\n";
		return;
	}
	
	if (k == n-2){
		cout << cantidadDeA() << "\n";
		return;
	}
	
	
	ll fin = cantidadDeA();
	//cout << "cant a : " << fin << endl;
	ll p2=tomadoDe(n-2,k);
	ll p1= fin*p2%MOD;
	
	cout << p1 << "\n";
}

int main(){
	int t = 1;
	
	forn(i, t){
		solve();
	}
	return 0;
}

