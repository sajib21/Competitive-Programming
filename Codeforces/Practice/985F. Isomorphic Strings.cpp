#include<bits/stdc++.h>
#define LIM 200005
#define LOG 18
#define bit bitset<26>

using namespace std;

int n,m, x,y,z, ex[20];
char str[LIM];
bit sparse[LIM][20];

int main() {
    ex[0] = 1;
    for(int i=1; i<LOG; i++) ex[i] = ex[i-1]*2;

    scanf("%d %d", &n,&m);
    scanf("%s", str);

    for(int i=0; i<n; i++) sparse[i][0][str[i]-'a'] = 1;
//    int ex = 1;
    for(int p=1; p<LOG; p++) {
        for(int i=0; i<n; i++) {
            sparse[i][p] = sparse[i][p-1] | sparse[ i+ex[p-1] ][p-1];
        }
    }

    while(m--) {
        scanf("%d %d %d", &x,&y,&z); x--; y--;
        bit a,b;
        int up, len;

        up = LOG-1; len = z;
        while(up >= 0) {
            if(ex[up] <= len) {
//                cout << "ADDING A : " << x << ' ' << up << ' ' << sparse[x][up] << endl;
                a |= sparse[x][up];
                x += ex[up];
                len -= ex[up];
            }
            up--;
        }

        up = LOG-1; len = z;
        while(up >= 0) {
            if(ex[up] <= len) {
//                cout << "ADDING B : " << y << ' ' << up << ' ' << sparse[y][up] << endl;
                b |= sparse[y][up];
                y += ex[up];
                len -= ex[up];
            }
            up--;
        }
//        cout << a << ' ' << b << endl;
//        cout << a.count() << ' ' << b.count() << endl;
        if(a.count() == b.count()) printf("YES\n");
        else printf("NO\n");
    }
}
