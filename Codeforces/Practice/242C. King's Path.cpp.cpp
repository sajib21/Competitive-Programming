#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define MAX 1000000009

using namespace std;

int dr[] = {-1, -1, -1,  0,  0, +1, +1, +1};
int dc[] = {-1,  0, +1, -1, +1, -1,  0, +1};

int x0,y0, x1,y1, n, r,a,b;
map<pii,bool>ase;
map<pii,int>vis;

bool valid(int r, int c) {
    return (r >= 0 && r < MAX && c >= 0 && c < MAX &&
            (ase.find(pii(r,c)) != ase.end()) && (vis.find(pii(r,c)) == vis.end()) );
}

int main() {
    scanf("%d %d %d %d", &x0,&y0, &x1,&y1);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &r,&a,&b);
        for(int i=a; i<=b; i++) ase[ pii(r,i) ] = 1;
    }

    queue<pii>q;
    q.push(pii(x0,y0));
    vis[ pii(x0,y0) ] = 0;

    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        int ur = cur.ff, uc = cur.ss;

//        if(ur == x1 && uc == y1) break;

        for(int i=0; i<8; i++) {
            int vr = ur+dr[i];
            int vc = uc+dc[i];

            if(!valid(vr,vc)) continue;

            vis[ pii(vr,vc) ] = vis[ pii(ur,uc) ] + 1;
            q.push(pii(vr,vc));
        }
    }

    if(vis.find(pii(x1,y1)) == vis.end()) cout << -1 << endl;
    else cout << vis[ pii(x1,y1) ] << endl;
}
