#include<bits/stdc++.h>

using namespace std;

int n,k, sz;
string s;

int check() {

//    cout << "NOW START with " << s << endl;

    for(int i=sz-1; i>=0; i--) {

//        cout << "now checking " << i << endl;
//        cout << i << ' ' << s[i] << ' ' << i-1 << ' ' << s[i-1] << ' ' << i-2 << ' ' << s[i-2] << endl;

        if(s[i]-'a' >= k ) {
            s[i] = 'a';
            if(i>0) s[i-1]++;
            else return -1;
        }
        if(s[i-1]-'a' >= k ) {
            s[i-1] = 'a';
            if(i>1) s[i-2]++;
            else return -1;
        }


        if(i > 0 && s[i]-'a' == (s[i-1]-'a')%k) return 0;
        if(i > 1 && s[i]-'a' == (s[i-2]-'a')%k) return 0;
    }

    return 1;
}

int main() {

    scanf("%d %d", &n, &k);
    cin >> s;
    sz = s.size();

//    int cnt = 0, x = n/k, y = n%k ;
//    int hi = x * k*(k+1)/2   +   k*(k+1)/2 - (k-y)*( (k-y)+1)/2;
    long long int ten = 1, hi = 0, x = k;
    for(int i = 0; i<sz; i++) {
        hi = hi*10 + x;
        x--;
        if(!x) x = k;
    }
//    cout << hi << endl;

    int nw = 0;
    for(int i=0; i<n; i++) nw += s[i]-'a'+1;
//    cout << nw << endl;
    if(nw >= hi) {
        cout << "NO" << endl;
        return 0;
    }

    s[sz-1]++;

    while(1) {
        int bl = check();
//        cout << bl << " now " << s << endl;
        if(bl == 0) {
            s[sz-1]++;
        }
        else if(bl == 1){
            cout << s << endl;
            break;
        }
        else {
            cout << "NO" << endl;
            break;
        }
    }

    return 0;

}
