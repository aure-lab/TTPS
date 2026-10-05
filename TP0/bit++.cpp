#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int x = 0;
    int n;
    string op;
    
    cin >> n;
    
    
    for (int i = 0; i<n; i++){
        cin >> op;
        if((op == "++X") or (op == "X++"))
            x++;
        else if ((op == "--X") or (op == "X--"))
            x--;
    }
    
    
    cout << x;
    return 0;
}
