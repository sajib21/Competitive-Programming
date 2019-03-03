#include<bits/stdc++.h>

using namespace std;

int n, dp[110][110], dr[110][110], ad[110][110];
char str[110];

bool chk(int a, int b) { return (str[a] == '(' && str[b] == ')') || (str[a] == '[' && str[b] == ']') ; }
char gt(int a) {
    if(str[a] == '(') return ')' ;
    if(str[a] == '[') return ']' ;
    if(str[a] == ')') return '(' ;
    if(str[a] == ']') return '[' ;
}

int f(int lft, int rgt) {
    if(lft > rgt) return 0;
    if(dp[lft][rgt] != -1) return dp[lft][rgt];
    int ans = INT_MAX, dir, add=0, added;
    if(str[lft] == ')' || str[lft] == ']') {
        ans = 1 + f(lft+1, rgt);
        dir = lft+1;
        add = 2;
    }
    else {
        for(int i=lft+1; i<=rgt; i++) if(chk(lft, i)) {
            int temp = f(lft+1, i-1) + f(i+1, rgt);
            if(temp < ans) {
                ans = temp;
                dir = i;
            }
        }
        for(int i=lft; i<=rgt; i++) {
            int temp = 1 + f(lft+1, i) + f(i+1, rgt);
            if(temp < ans) {
                ans = temp;
                dir = i;
                add = 1;
            }
        }
    }
    dr[lft][rgt] = dir;
    ad[lft][rgt] = add;
    return dp[lft][rgt] = ans;
}

void print(int lft, int rgt) {
    if(lft > rgt) return;
    int dir = dr[lft][rgt], add = ad[lft][rgt];
    if(add == 0) {
        printf("%c", str[lft]);
        print(lft+1, dir-1);
        printf("%c", gt(lft) );
        print(dir+1, rgt);
    }
    else if(add == 1) {
        printf("%c", str[lft]);
        print(lft+1, dir);
        printf("%c", gt(lft) );
        print(dir+1, rgt);
    }
    else {
        printf("%c", gt(lft) );
        printf("%c", str[lft] );
        print(lft+1, rgt);
    }
}

int main() {
//    freopen("1626o.txt", "w", stdout);
    int T;
    scanf("%d", &T);getchar();
    for(int t=1; t<=T; t++) {
        if(t > 1) printf("\n");
        getchar(); gets(str);
//        scanf("%s", str);
        memset(dp, -1, sizeof dp);
        memset(dr, -1, sizeof dr);
        memset(ad,  0, sizeof ad);
        n = strlen(str);
        f(0, n-1);
//        cout << dp[0][n-1] << endl;

        print(0, n-1); printf("\n");


    }
}
