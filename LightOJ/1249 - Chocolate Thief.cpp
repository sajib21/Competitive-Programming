#include<bits/stdc++.h>

using namespace std;

struct info {

    char nm[25];
    int sz;
    info() {}
    info(char nnm[], int ss) {
        strcpy(nm, nnm);
        sz = ss;
    }
    bool operator < (const info &b) const {
        return sz < b.sz;
    }
};

int n;
info ppl[110];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            char nm[25];
            int a,b,c;
            scanf("%s %d %d %d", nm, &a,&b,&c);
            ppl[i] = info(nm, a*b*c);
        }
        sort(ppl, ppl+n);
        if(ppl[n-1].sz == ppl[n-2].sz) printf("Case %d: no thief\n", t);
        else printf("Case %d: %s took chocolate from %s\n", t, ppl[n-1].nm, ppl[0].nm);
    }
    return 0;
}
