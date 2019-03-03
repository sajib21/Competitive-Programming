#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define vp vector<pii>
#define pb(x) push_back(x)
#define inf 1000000000

using namespace std;

int dR[] = {-1,  0,  0, +1};
int dC[] = { 0, -1, +1,  0};

int n,m,p,x, grid[303][303], dp[303][303], vis[303][303];
vp a[300*300+3];

void brute(int x) {
    for(int i=0; i<a[x-1].size(); i++) {
        pii u = a[x-1][i];
        for(int j=0; j<a[x].size(); j++) {
            pii v = a[x][j];
            dp[ v.ff ][ v.ss ] = min(dp[v.ff][v.ss],
                dp[u.ff][u.ss] + abs(v.ff-u.ff)+abs(v.ss-u.ss));
        }
    }
}

bool cmp(pii a, pii b) {
    return dp[a.ff][a.ss] < dp[b.ff][b.ss];
}
void bfs(int x) {
//    cout << "COLOR " << x << endl;
    memset(vis, -1, sizeof vis);
    queue<pii>q;
    vector<pii>temp;
    for(int i=0; i<a[x-1].size(); i++) {
        pii u = a[x-1][i];
        temp.pb(u);
        vis[u.ff][u.ss] = dp[u.ff][u.ss];
    }
    sort(temp.begin(), temp.end(), cmp);
    int in = 0;
    vis[temp[in].ff ][temp[in].ss ] = dp[ temp[in].ff ][ temp[in].ss ];
    q.push(temp[in++]);
//    for(int i=0; i<temp.size(); i++) q.push(temp[i]);

    while(!q.empty()) {
        pii U = q.front();
        int ur = U.ff, uc = U.ss;
        q.pop();

//        cout << ur << ' ' << uc << ' ' << vis[ur][uc] << endl; getchar();

        while(in < temp.size() && dp[ temp[in].ff ][ temp[in].ss ] <= vis[ur][uc]+1) {
//                    vis[ temp[in].ff ][ temp[in].ss ] = dp[ temp[in].ff ][ temp[in].ss ];
            q.push(temp[in++]);
        }


        for(int i=0; i<4; i++) {
            int vr = ur + dR[i];
            int vc = uc + dC[i];

            if(vr < 0 || vr == n || vc < 0 || vc == m || vis[vr][vc] != -1 || grid[vr][vc] == x-1) continue;

//            if( !(vr < 0 || vr == n || vc < 0 || vc == m) && vis[vr][vc] == -1) {
                vis[vr][vc] = vis[ur][uc] + 1;



                q.push(pii(vr,vc));



//            }
        }
    }

    for(int i=0; i<a[x].size(); i++) {
        pii u = a[x][i];
        dp[u.ff][u.ss] = min(dp[u.ff][u.ss], vis[u.ff][u.ss]);
    }
}

int main() {
    scanf("%d %d %d", &n,&m,&p);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &x);
            grid[i][j] = x;
            a[x].pb(pii(i,j));
        }
    }

    for(int i=0; i<=300; i++) for(int j=0; j<=300; j++) dp[i][j] = inf;
//    memset(dp, 127, sizeof dp);

    for(int i=0; i<a[1].size(); i++) {
        dp[ a[1][i].ff ][ a[1][i].ss ] = a[1][i].ff + a[1][i].ss;
    }

    for(int c=2; c<=p; c++) {
        if(a[c-1].size()*a[c].size() <= n*m) brute(c);
        else bfs(c);
    }

    printf("%d\n", dp[ a[p][0].ff ][ a[p][0].ss ]);
}
