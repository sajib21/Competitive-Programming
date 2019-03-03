#include<bits/stdc++.h>

using namespace std;

int p,q,r,s, x,y, a,b;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d:%d %d:%d", &p,&q,&r,&s);
        x = p*60 + q; y = r*60 + s;
        scanf("%d:%d %d:%d", &p,&q,&r,&s);
        a = p*60 + q; b = r*60 + s;

        if( (a >= x && a <= y) || (b >= x && b <= y) ) printf("Case %d: Mrs Meeting\n", t);
        else if( (x >= a && x <= b) || (y >= a && y <= b) ) printf("Case %d: Mrs Meeting\n", t);
        else printf("Case %d: Hits Meeting\n", t);
    }

}
//scanf("%d:%d %d:%d", &p,&q,&r,&s);
//Case 2: Hits Meeting
//Case 3: Mrs Meeting
