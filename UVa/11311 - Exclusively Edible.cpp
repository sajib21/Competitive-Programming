#include<bits/stdc++.h>

using namespace std;

int n,m,r,c;
int grundy[50][50][50][50];

int getGrundy(int rows, int cols, int r, int c) {

    if(grundy[rows][cols][r][c] != -1) return grundy[rows][cols][r][c];

    int st[2500] = {0};

    for(int i=r; i<rows-1; i++) st[ getGrundy(i+1, cols, r, c) ] = 1;
    for(int i=r; i > 0;    i--) st[ getGrundy(rows-i, cols, (rows-i)-(rows-r), c) ] = 1;
    for(int i=c; i<cols-1; i++) st[ getGrundy(rows, i+1, r, c) ] = 1;
    for(int i=c; i > 0;    i--) st[ getGrundy(rows, cols-i, r, (cols-i)-(cols-c)) ] = 1;

    int ans = 0;
    while(st[ans]) ans++;
    return grundy[rows][cols][r][c] = ans;
}

int main() {

    memset(grundy, -1, sizeof(grundy));

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &n,&m, &r,&c);
        if(getGrundy(n,m,r,c)) printf("Gretel\n");
        else printf("Hansel\n");
    }
    return 0;
}


