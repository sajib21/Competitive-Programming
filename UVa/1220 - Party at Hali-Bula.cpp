#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define LIM 200

using namespace std;

struct info {
    int x,y;
    info() {x = 0; y = 1;}
    info(int xx, int yy) { x= xx; y = yy; }
    info operator + (const info &b) const {
        info temp = info(x+b.x , y*b.y);
        if(temp.y > 1) temp.y = 2;
        return temp;
    }
};

int n, id;
map<string, int> mp;
vii graph[LIM+10];
info dp[LIM+10][3];

info f(int u, int last) {
    if(dp[u][last].x != -1) return dp[u][last];
    int sz = graph[u].size();
    info ans = info(), temp = info();
    for(int i=0; i<sz; i++) {
        int v = graph[u][i];
        ans = ans + f(v, 0);
    }
//    if(u == 1) cout << u << ' ' << last << ' ' << ans.x << ' ' << ans.y << endl;
    if(!last) {
        for(int i=0; i<sz; i++) {
            int v = graph[u][i];
            temp = temp + f(v, 1);
        }
        temp.x++;
//        if(u == 1) cout << u << ' ' << last << ' ' << temp.x << ' ' << temp.y << endl;
    }
    if(temp.x > ans.x) ans = temp;
    else if(temp.x == ans.x && temp.x) ans.y += temp.y;
    if(ans.y > 1) ans.y = 2;
//    if(u == 1) cout << u << ' ' << last << ' ' << ans.x << ' ' << ans.y << endl;
    return dp[u][last] = ans;

}

int main() {
//    freopen("1220i.txt", "r", stdin);
//    freopen("1220o.txt", "w", stdout);
//    int t = 0;
    while(scanf("%d", &n)) {
        if(!n) return 0;
        memset(graph, NULL, sizeof graph);
        memset(dp, -1, sizeof dp);
        mp.clear();
        char a[110], b[110];

        scanf("%s", a);
        mp[ a ] = 1;
        id = 2;

        for(int i=2; i<=n; i++) {
            scanf("%s %s", a, b);
            if(!mp[ a ]) mp[ a ] = id++;
            if(!mp[ b ]) mp[b] = id++;
            graph[ mp[b] ].pb(mp[a]);
        }
        info ans = f(1, 0);
        printf("%d ", ans.x);
        if(ans.y == 1) printf("Yes\n");
        else printf("No\n");

//        t++;
//
//        if(t == 100) return 0;

//        cout << dp[1][0].x << ' ' << dp[1][0].y << endl;

    }

}
