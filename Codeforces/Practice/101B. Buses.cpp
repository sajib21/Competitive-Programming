#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff  first
#define ss  second
#define mpr make_pair
#define LIM 100000
#define MAX 1000000000
#define MOD 1000000007

using namespace std;

int n,m;
pii bus[LIM+100];
int dp[LIM+100];

int f(int in) {
    if(in == m) {

    }
    if(dp[in] != -1) return dp[in];

}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++) scnaf("%d %d", &bus[i].ff, &bus[i].ss);
    sort(bus, bus+m);
    printf("%d\n", f(0));

}
