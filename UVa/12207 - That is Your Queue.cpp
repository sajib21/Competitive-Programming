#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int p,n, x;
int cmd[1010], ex[1010];
char str[2];

int main() {
//    vi xx;
//    xx.pb(0); xx.pb(1);
//    xx.erase(xx.begin());
//    cout << xx.size() << ' ' << xx[0] << endl;

    int t=1;
    while( scanf("%d %d", &p, &n) ) {
        if(!p && !n) return 0;

        vi cur;
        for(int i=1; i<=min(p,n); i++) cur.pb(i);

        for(int i=0; i<n; i++) {
            scanf("%s", str);
            if(str[0] == 'N') cmd[i] = 0;
            else {
                cmd[i] = 1;
                scanf("%d", &x);
                ex[i] = x;
                if(x > min(p,n)) cur.pb(x);
            }
        }

        printf("Case %d:\n", t++);
        for(int i=0; i<n; i++) {
            if(cmd[i] == 0) {
                x = cur[0];
                printf("%d\n", x);
                cur.erase(cur.begin());
                cur.pb(x);
            }
            else {
                x = ex[i];
                cur.erase( find(cur.begin(), cur.end(), x) );
                cur.insert(cur.begin(), x);
            }
        }
    }
}
