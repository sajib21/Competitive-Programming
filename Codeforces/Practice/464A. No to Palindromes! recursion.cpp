#include<bits/stdc++.h>

using namespace std;

int n,k, sz;
string s;

bool check(int pos) {

    if(pos == n) return 1;

    for( ; s[pos] - 'a' < k; s[pos]++ ) {

        if(pos > 0 && s[pos] == s[pos-1]) continue;
        if(pos > 1 && s[pos] == s[pos-2]) continue;

        if(check(pos+1)) return 1;
    }

    s[pos] = 'a';
    return 0;
}

int main() {

    scanf("%d %d", &n, &k);
    cin >> s;
    sz = s.size();

//    long long int ten = 1, hi = 0, x = k;
//    for(int i = 0; i<sz; i++) {
//        hi = hi*10 + x;
//        x--;
//        if(!x) x = k;
//    }
//    cout << hi << endl;
//
//    int nw = 0;
//    for(int i=0; i<n; i++) nw += s[i]-'a'+1;
//    cout << nw << endl;
//    if(nw >= hi) {
//        cout << "NO" << endl;
//        return 0;
//    }

    s[sz-1]++;

    if(check(0)) cout << s << endl;
    else cout << "NO" << endl;

    return 0;

}
