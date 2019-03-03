#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 1001
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

#define ___ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n,q;
bool flag[LIM+10][LIM+10];
int bitTree[LIM+10][LIM+10];
int mxx = 0;

void update(int x, int y, int val) {

    while(x <= LIM) {
        int ty = y;
        while(ty <= LIM) {
            bitTree[x][ty] += val;
            ty += (ty & -ty);
        }
        x += (x & -x);
    }
}

int query(int x, int y) {

    int sum = 0;
    while(x > 0) {
        int ty = y;
        while(ty > 0) {
            sum += bitTree[x][ty];
            ty -= (ty & -ty);
        }
        x -= (x & -x);
    }
    return sum;
}


int main() {

    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {
        memset(bitTree, 0, sizeof(bitTree));
        memset(flag, 0, sizeof(flag));
        printf("Case %d:\n", t);
        scanf("%d", &q);
        while(q--) {
            int c;
            scanf("%d", &c);
            if(c == 0) {
                int x,y;
                scanf("%d %d", &x,&y);
                x++; y++;
                if(!flag[x][y]) update(x,y, 1);
                flag[x][y] = 1;
            }
            else {
                int stx,sty, edx,edy;
                scanf("%d %d %d %d", &stx,&sty,&edx,&edy);
                stx++; sty++; edx++; edy++;
                int ans = query(edx,edy) - query(edx,sty-1) - query(stx-1,edy) + query(stx-1, sty-1);
                printf("%d\n", ans);
            }

//            for(int i=1; i<=5; i++) {
//                for(int j=1; j<=5; j++) {
//                    cout << bitTree[i][j] << ' ';
//                }
//                cout << endl;
//            }

        }

    }

    return 0;
}
