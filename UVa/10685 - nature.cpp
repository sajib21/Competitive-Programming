#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

int rep[MAX], rnk[MAX];
int maximum = 0;

int cycle(int n) {
    if(rep[n] == n) return n;
    else return rep[n] = cycle(rep[n]);
}

void unite(int u, int v) {
    int pu = cycle(u), pv = cycle(v);
    if(rnk[pu] < rnk[pv]) {
        rep[pu] = pv;
        rnk[pv] += rnk[pu];
        //maximum = max(maximum, rnk[pv]);
    }
    else {
        rep[pv] = pu;
        rnk[pu] += rnk[pv];
        //maximum = max(maximum, rnk[pu]);
    }

}


int main() {
    int c,r;
    string s1,s2,s3;

    map<string,int>mp;

    while(scanf("%d %d", &c,&r) && !(!c && !r) ) {

        maximum = 0;

        for(int i =0; i<c; i++) {
            rep[i] = i;
            rnk[i] = 1;
        }

        for(int i=0; i<c; i++) {
            cin >> s1;
            mp[s1] = i;
        }

        for(int i=0; i<r; i++) {
            cin >> s2 >> s3;
            int u = mp[s2];
            int v = mp[s3];

            if(cycle(u) != cycle(v)) {
                unite(u,v);
            }
        }

        for(int i=0; i<c; i++) maximum = max(maximum, rnk[i]);

        cout << maximum << endl;


    }

    return 0;
}
