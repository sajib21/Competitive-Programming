#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int a=-1,b=-1;
    int c=-1,d=-1;

    for(int i=0; i<n-1; i++) if(s[i] == 'A' && s[i+1] == 'B') {
        a = i;
        break;
    }
    for(int i=n-2; i>=0; i--) if(s[i] == 'A' && s[i+1] == 'B') {
        c = i;
        break;
    }

    for(int i=1; i<n; i++) if(s[i] == 'A' && s[i-1] == 'B') {
        d = i;
        break;
    }
    for(int i=n-1; i>0; i--) if(s[i] == 'A' && s[i-1] == 'B') {
        b = i;
        break;
    }

//    cout << a << ' ' << c << ' ' << b << ' ' << d << endl;

    if(a == -1 || b == -1) cout << "NO" << endl;
    else if(a <= b) {
        if(b-a >= 3) cout << "YES" << endl;
        else if(d < c) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}
