#include<bits/stdc++.h>
#define MN -1000

using namespace std;

int needed[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n,m;
int dp[110][3030];
int dr[110][3030];

int f(int rem, int mod) {
//    cout << rem << ' ' << mod << endl; getchar();
    if(dp[rem][mod] != -1) return dp[rem][mod];
    int ans = MN, dir = -1;
    if(mod == 0) ans = 0;
    for(int i=9; i>=0; i--) if(rem >= needed[i]) {
        int temp = 1 + f(rem-needed[i] , (mod*10 + i) % m);
        if(temp > ans) {
            ans = temp;
            dir = i;
        }
    }
    dr[rem][mod] = dir;
    return dp[rem][mod] = ans;
}

void print(int rem, int mod) {
    int ans = dp[rem][mod];
    int dir = dr[rem][mod];

    if(ans == 0) {
        printf("\n");
        return;
    }

    printf("%d", dir);
    print(rem-needed[dir], (mod*10 + dir) % m );
}

int main() {
    int tt = 1;
    while(scanf("%d", &n) && n) {
        scanf("%d", &m);
        memset(dp, -1, sizeof dp);
        memset(dr, -1, sizeof dr);
//        cout << f(n,0) << endl;
        f(n,0);
        printf("Case %d: ", tt++);
        if(dp[n][0] == 0) printf("-1\n");
        else print(n,0);
    }
    return 0;
}
