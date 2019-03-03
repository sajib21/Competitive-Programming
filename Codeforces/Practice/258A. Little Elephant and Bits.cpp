#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s;
    n = s.size();

    int in = 0;
    for(int i=0; i<n; i++) if(s[i] == '0') {
        in = i; break;
    }
    for(int i=0; i<n; i++) if(i != in) cout << s[i] ;
    cout << endl;

}
