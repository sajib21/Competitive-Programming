//#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <string.h>
#define LIM 10000

using namespace std;

struct info {
    int h,a,c;
    bool operator < (const info &b) const {
        return a < b.a;
    }
};

int k; // h[404], a[404], c[404];
int dp[40100];
bool dr[40100];
info d[404];


int main() {
    scanf("%d", &k);
    for(int i=0; i<k; i++) scanf("%d %d %d", &d[i].h, &d[i].a, &d[i].c);
    sort(d, d+k);

    memset(dr, 0, sizeof dr);

    dr[0] = 1;
    dp[0] = 0;

    for(int i=0; i<k; i++) {
        memset(dp, 0, sizeof dp);
        for(int h=d[i].h; h<=d[i].a; h++) if(!dr[h]) {
            int p = h - d[i].h;
            if(dr[p] && dp[p] < d[i].c) {
                dr[h] = 1; dp[h] = dp[p]+1;
            }
        }
    }

    for(int h=d[k-1].a; h>=0; h--) if(dr[h]) {
        printf("%d\n", h);
        break;
    }

    return 0;
}
