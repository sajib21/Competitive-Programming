#include<bits/stdc++.h>

using namespace std;

int n, numCnt[10000007], mx = 0, szv=0;
vector<int>numVec, primeVec;

int primeSv[10000007];

void sieve(int n) {

    int sq = sqrt(n);
    //cout << "max sq " << sq << endl;
    primeVec.push_back(2);
    for(int i=4; i<=n; i+=2 ) primeSv[i] = -1;
    for(int i=3; i<=sq; i+=2) {
        if(!primeSv[i]) {
            primeVec.push_back(i);
            for(int j=i+i; j<=n; j+=i) primeSv[j] = -1;
        }
    }
    for(int i=sq+1; i<=n; i++) if(!primeSv[i]) primeVec.push_back(i);

//    for(int i = 1; i<=20; i++) cout << i << ' ' << primeSv[i] << endl;
}

void include(int n) {

//    int sq = sqrt(n);
    //int sz = primeVec.size();
    if(primeSv[n] != -1) primeSv[n] += numCnt[n];
    int ss = n/2;
    for(int i=0; i<szv && primeVec[i]<=ss; i++) {
        if(n%primeVec[i] == 0) {
            primeSv[ primeVec[i] ] += numCnt[ n ];
            //int ss = n/primeVec[i];
            //if(primeSv[ss] != -1 && ss != primeVec[i]) primeSv[ss] += numCnt[n];
        }

    }
}

int main() {

    scanf("%d", &n);
    int t = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        if(!numCnt[t]) numVec.push_back(t);
        numCnt[t]++;
        mx = max(mx, t);
    }

    sieve(mx);

    int sz = numVec.size(); szv = primeVec.size();
    for(int i=0; i<sz; i++) {
        include(numVec[i]);
    }



    sz = primeVec.size();
    for(int i=1; i<sz; i++) {
        primeSv[ primeVec[i] ] += primeSv[ primeVec[i-1] ];
    }

    int q, l,r, mxp =  primeVec[ sz-1 ];
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%d %d", &l, &r);
        l--;
        l = min(mxp, l);
        r = min(mxp, r);

        while(primeSv[l] == -1) l--;
        while(primeSv[r] == -1) r--;

//        cout << "query " << l << ' ' << r << endl;

        printf("%d\n", primeSv[r] - primeSv[l]);
    }
//    for(int i = 1; i<=52; i++) cout << i << ' ' << primeSv[i] << endl;

    return 0;
}
