#include <bits/stdc++.h>
#include <vector> 
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	
	int par = 0; 
	int impar=0;
	
	for (int i=0; i<n; i++){
	    cin >> v[i];
	}
	
	for (int i=0; i<n; i++){
	    if (v[i]%2 == 0)
	        par++;
	    else
	        impar++;   
	}
	
    int x;
    if (par>impar)
        x=0;
    else
        x=1;
        
    int pos;
    for (int i=0; i<n; i++){
        if(v[i] %2 != x){
            pos = i+1;
            break;
        }
    }
    
    cout << pos;
    return 0;
}
