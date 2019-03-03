#include<bits/stdc++.h>
#define LIM 1000006
using namespace std;

int n, nxt[LIM], a[LIM], b[LIM], pre[LIM], x,y, age[LIM], pore[LIM];
vector<int>l,r;

int main() {
    scanf("%d", &n);
//    memset(nxt, -1, sizeof nxt);
//    memset(pre, -1, sizeof pre);

    for(int i=0; i<n; i++) {
        scanf("%d %d", &x,&y);
        nxt[x] = y;
        pre[y] = x;
        age[x] = pore[y] = 1;
        a[i] = x; b[i] = y;
    }
    for(int i=0; i<n; i++) {
        int u = b[i];
        if(u && !age[u]) y = b[i];
        u = a[i];
        if(u && !pore[u]) x = a[i];
    }

    if(n%2==0) {
        int u = x;
        while(u) {
            l.push_back(u);
            u = nxt[u];
        }
        u = y;
        while(u) {
            r.push_back(u);
            u = pre[u];
        }
        reverse(r.begin(), r.end());

//        cout << "P " << x << ' ' << y << ' ' << l.size() << ' ' << r.size() << endl;


        for(int i=0; i<l.size(); i++) {
            if(i) printf(" ");
            printf("%d %d", l[i], r[i]);
        }
        printf("\n");
    }
    else {
        int u = x;
        while(u) {
            l.push_back(u);
            u = nxt[u];
        }
        u = 0;
        while(pre[u]) {
            r.push_back(pre[u]);
            u = pre[u];
        }
        reverse(r.begin(), r.end());

//        cout << "P " << x << ' ' << y << ' ' << l.size() << ' ' << r.size() << endl;


        for(int i=0; i<l.size()-1; i++) {
            if(i) printf(" ");
            printf("%d %d", l[i], r[i]);
        }
        printf(" %d\n", l.back());
    }

    return 0;
}
