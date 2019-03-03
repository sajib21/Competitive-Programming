//#include<iostream>
#include<stdio.h>
#include<algorithm>
//#include <string.h>
#define LIM 10000

using namespace std;

struct info {
    int h,a,c;
    bool operator < (const info &b) const {
        return a < b.a;
    }
};

int k; // h[404], a[404], c[404];
int dp[401][40001];
bool dr[401][40001];
info d[404];

int f(int in, int cur) {
//    cout << "IN " << in << ' ' << cur << endl; getchar();
    if(in == k) return cur;
    if(dr[in][cur]) return dp[in][cur];
    dr[in][cur] = 1;
    int ans = 0;
    for(int i=0; i<=d[in].c; i++) {
        if(cur+d[in].h*i <= d[in].a) ans = max(ans, f(in+1, cur+d[in].h*i));
    }
    return dp[in][cur] = ans;
}

int main() {
    scanf("%d", &k);
    for(int i=0; i<k; i++) scanf("%d %d %d", &d[i].h, &d[i].a, &d[i].c);
    sort(d, d+k);

//    cout << rand() << endl;
//    return 0;

//    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0,0));

    return 0;
}
