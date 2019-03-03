#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int n,ara[50005];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(ara, 0, sizeof(ara));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
//            int x;
            scanf("%d", &ara[i]);
//            ara[x]++;
        }
        sort(ara+1, ara+n+1);

        int divine = 1;
//        cout << "BUG " << divine << endl;
        bool flag = false;
        for(int i=1; i<=n; i++) {
            if(i <= divine) {
                divine = max(divine, ara[i]);
                continue;
            }
            if(divine >= ara[i]) {
//                ans = ara[i];
//                break;
//                if(flag)
                    divine = max(divine, i);
//                divine = i + 1;
                flag = true;
            }
            else break;
        }
        printf("Case %d: %d\n", t, divine);
    }

    return 0;
}

