#include <bits/stdc++.h>
#include <string>
using namespace std;


int main() {
    string v = "AEIYOUaeiyou";
    string s;
    char c;
    cin >> s;
    for (int i=0; i<s.length(); i++){
        c = s[i];
        if (v.find(c) == std::string::npos)
            cout<<  "." << static_cast<char>(tolower(c));
    }
    return 0;
}
