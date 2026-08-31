#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long m;
	cin >> m;
	long long a;
	cin >> a;
	
	long long intermedio1 = (n/a);
	if ((n % a) != 0)
	    intermedio1 ++;
	long long intermedio2 = (m/a);
	if ((m % a) != 0)
	    intermedio2 ++;
	long long result = intermedio1 * intermedio2;
    cout << result;
    
    return 0;
}
