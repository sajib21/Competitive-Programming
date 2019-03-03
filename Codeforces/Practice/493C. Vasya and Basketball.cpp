#include<bits/stdc++.h>
#define MX 200005
#define ll long long int

using namespace std;

int n,m;
ll p1[MX], p2[MX];

int main() {



//    while(1) {

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &p1[i]);
    scanf("%d", &m);
    for(int i=1; i<=m; i++) scanf("%lld", &p2[i]);

    sort(p1, p1+n+1);
    sort(p2, p2+m+1);

    int resp1 = n, resp2 = m, cnt=0, ans=0;
    int a = n, b = m;
    while(a || b) {
        if(p1[a] > p2[b]) {
            cnt++;a--;
            if(cnt >= ans) {
                ans = cnt;
                resp1 = a;
                resp2 = b;
            }
        }
        else if(p1[a] < p2[b]) {
            cnt--; b--;
        }
        else {
            int t1=1,t2=1;
            while(p1[a] == p1[a-1]) t1++, a--;
            while(p2[b] == p2[b-1]) t2++, b--;
            cnt += t1-t2;

            a--, b--;
            if(cnt >= ans) {
                ans = cnt;
                resp1 = a;
                resp2 = b;
            }
        }
//        cout << cnt << ' ' << resp1 << ' ' << resp2 << endl;
    }

//    cout << resp1 << ' ' << resp2 << endl;

    printf("%d:%d\n", 2*resp1 + 3*(n-resp1), 2*resp2 + 3*(m-resp2) );

//    }
    return 0;



}
