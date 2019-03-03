#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)

using namespace std;

int n,q, ara[LIM+10];
int BIT[LIM+10];

void update(int indx, int val) {

    while(indx <= n) {
        BIT[indx] += val;
        indx += (indx & -indx);
    }
}
int query(int indx) {
    int sum = 0;
    while(indx > 0) {
        sum += BIT[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(BIT, 0, sizeof(BIT));
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        for(int i=1; i<=n; i++) update(i, ara[i]);

//        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            int a,b,c;
            scanf("%d", &c);
            if(c==1) {
                scanf("%d", &a); a++;
                int ans = query(a) - query(a-1);
                printf("%d\n", ans);
                update(a, -ans);
            }
            else if(c==2) {
                scanf("%d %d", &a, &b); a++;
                update(a, b);
            }
            else {
                scanf("%d %d", &a,&b);
                a++; b++;
                printf("%d\n", query(b) - query(a-1));
            }
        }
    }
    return 0;
}
