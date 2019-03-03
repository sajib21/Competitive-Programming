#include<bits/stdc++.h>

using namespace std;

int get(char ch[]) {

    int ans = 0;
    for(int i=0; i<8; i++) ans = ans*2 + (ch[i] - '0');
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int a,b,c,d;
        char p[9],q[9],r[9],s[9];
        scanf("%d.%d.%d.%d", &a,&b,&c,&d);
        scanf("%8s.%8s.%8s.%8s", p,q,r,s);

        int w = get(p) , x = get(q) , y = get(r) , z = get(s) ;
        if(a == w && b == x && c == y && d == z) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);

//        printf("%s\n", p);
    }
    return 0;
}
