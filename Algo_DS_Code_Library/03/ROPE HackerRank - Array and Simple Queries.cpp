/**
logn e kora jabe: substr, insert, erase, size
**/

#include <bits/stdc++.h>
#include <ext/rope> //header with rope

using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff

int n,m;
rope<int> rp;

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) {
        int v;
        scanf("%d", &v);
        rp.append(v);
    }

    while(m--) {
        int c,l,r;
        scanf("%d %d %d", &c, &l, &r);
        l--; r--;

        rope<int>temp = rp.substr(l, r-l+1);
        rp.erase(l, r-l+1);
        if(c == 1) rp.insert(rp.mutable_begin(), temp);
        else rp.insert(rp.mutable_end(), temp);
    }

    cout << abs(rp[0] - rp.back()) << endl;
    bool ff = false;
    for(auto it : rp) {
        if(ff) printf(" ");
        ff = true;
        printf("%d", it);
    }
    cout << endl;

    return 0;
}


