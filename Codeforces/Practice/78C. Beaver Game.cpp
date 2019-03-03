#include<bits/stdc++.h>

using namespace std;

int n,m,k;

int f(int x) {
    set<int>ase;

    if(x%2==0 && x/2 >= k) ase.insert(0);
    int sq = sqrt(x);
    for(int d=3; d<=sq; d+=2) {
        if(x%d) continue;
        int q = x/d;
        if(q >= k) ase.insert(f(q));
        if(d >= k) ase.insert(f(d));
    }
    if(1 < m && 1 >= k && x%2) ase.insert(0);

    int mex = 0;
    for(auto it : ase) {
        if(it == mex) mex++;
        else return mex;
    }
    return mex;
}

int main() {
    scanf("%d %d %d", &n,&m,&k);
    if(n%2==0) printf("Marsel\n");
    else {
        if(f(m)) printf("Timur\n");
        else printf("Marsel\n");
    }
}

///830273749 999999937 1
