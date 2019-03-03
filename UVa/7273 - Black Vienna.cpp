#include<bits/stdc++.h>
#define LIM 60
#define vii vector<int>
#define pb push_back

using namespace std;

int n,m=26, a,b,c;
char inv[60][4];
int pl[60], op[60];
vii g[LIM], rg[LIM];
int vis[LIM], comp[LIM], cp;
stack<int>stk;

int bar(int x) { return (x+m)%(2*m); }

void dfs(int u) {
    int bu = bar(u);
    if(u == a || u == b || u == c || bu == a || bu == b || bu == c) return;
    vis[u] = 1;
    int sz = g[u].size();
    for(int i=0; i<sz; i++) {
        int v = g[u][i];
        if(!vis[v]) dfs(v);
    }
    stk.push(u);
}

void dfs2(int u) {
    int bu = bar(u);
    if(u == a || u == b || u == c || bu == a || bu == b || bu == c) return;
    vis[u] = 1; comp[u] = cp;
    int sz = rg[u].size();
    for(int i=0; i<sz; i++) {
        int v = rg[u][i];
        if(!vis[v]) dfs2(v);
    }
}

bool makeGraph() {
    memset(g, NULL, sizeof g);
    memset(rg, NULL, sizeof rg);

    for(int i=0; i<n; i++) {
        int x = inv[i][0] , y = inv[i][1] ;
//        cout << "MAKING " << i << ' ' << x << ' ' << y << ' ' << pl[i] << ' ' << op[i] << endl; getchar();

        if(x == a || x == b || x == c) {
            if(op[i] == 2) return false;
//            cout << "STILL IN " << endl;
            if(op[i] == 0)  {
                if(y == a || y == b || y == c) continue;
                if(pl[i] == 1) { g[y].pb(bar(y));        rg[bar(y)].pb(y); }
                else           { g[bar(y)].pb(y);        rg[y].pb(bar(y)); }
                continue;
            }
            if(op[i] == 1) {
                if(y == a || y == b || y == c) return false;
                if(pl[i] == 1) { g[bar(y)].pb(y);        rg[y].pb(bar(y)); }
                else           { g[y].pb(bar(y));        rg[bar(y)].pb(y); }
            }
            continue;
        }
        if(y == a || y == b || y == c) {
            if(op[i] == 2) return false;
            if(op[i] == 0) {
                if(x == a || x == b || x == c) continue;
                if(pl[i] == 1) { g[x].pb(bar(x));        rg[bar(x)].pb(x); }
                else           { g[bar(x)].pb(x);        rg[x].pb(bar(x)); }
                continue;
            }
            if(op[i] == 1) {
                if(pl[i] == 1) { g[bar(x)].pb(x);        rg[x].pb(bar(x)); }
                else           { g[x].pb(bar(x));        rg[bar(x)].pb(x); }
            }
            continue;
        }

        ///graph like this : true : card in 1st player , false : card in 2nd player (cuz each card must be present except bv)
        if(op[i] == 1) { /// XOR : x -> !y : y -> !x || !x -> y : !y -> x
                g[x].pb(bar(y));            rg[bar(y)].pb(x);
                g[y].pb(bar(x));            rg[bar(x)].pb(y);
                g[bar(x)].pb(y);            rg[y].pb(bar(x));
                g[bar(y)].pb(x);            rg[x].pb(bar(y));
        }
        else if(op[i] == 0) {
            if(pl[i] == 1) { /// x -> !x || y -> !y
                g[x].pb(bar(x));        rg[bar(x)].pb(x);
                g[y].pb(bar(y));        rg[bar(y)].pb(y);
            }
            else { /// !x -> x || !y -> y
                g[bar(x)].pb(x);       rg[x].pb(bar(x));
                g[bar(y)].pb(y);       rg[y].pb(bar(y));
            }
        }
        else {
            if(pl[i] == 1) { /// !x -> x || !y -> y
                g[bar(x)].pb(x);       rg[x].pb(bar(x));
                g[bar(y)].pb(y);       rg[y].pb(bar(y));
            }
            else { /// x -> !x || y -> !y
                g[x].pb(bar(x));        rg[bar(x)].pb(x);
                g[y].pb(bar(y));        rg[bar(y)].pb(y);
            }
        }
    }
//    if(a == 3 && b == 4 && c == 5) {
//        cout << "GRAPH" << endl;
//        for(int i=0; i<2*m; i++) {
//            cout << i << " : " << g[i].size() << " : " ;
//            for(int j=0; j<g[i].size(); j++) cout << (int) g[i][j] << ' ' ;
//            cout << endl;
//        } getchar();
//    }
    return true;
}

bool sat() {
    memset(vis, 0, sizeof vis);
    for(int u=0; u<2*m; u++) if(!vis[u]) dfs(u);
    cp = 0;
    memset(vis, 0, sizeof vis);
    memset(comp, 0, sizeof comp);
    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if(u == a || u == b || u == c || vis[u]) continue;
        cp++;
        dfs2(u);
    }
//    if(a == 3 && b == 4 && c == 5) {
//        cout << "COMP" << endl;
//        for(int i=0; i<2*m; i++) cout << i << ' ' << comp[i] << endl;
//    }
//
//    cout << "EI PORJONTO" << endl; getchar();
//    for(int i=0; i<m; i++) if(i != a && i != b && i != c) cout << i << ' ' << comp[i] << ' ' << comp[bar(i)] << endl;
//    getchar();
    for(int u=0; u<m; u++) if(u !=a && u != b && u != c && comp[u] == comp[bar(u)]) return false;
    return true;
}

int main() {
//    freopen("7273i.txt", "r", stdin);
//    freopen("7273o.txt", "w", stdout);

    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++) scanf("%s %d %d", inv[i], &pl[i], &op[i]);
        for(int i=0; i<n; i++) inv[i][0] -= 'A' , inv[i][1] -= 'A';

        int ans = 0;
        for(a=0; a<26; a++) {
            for(b=a+1; b<26; b++) {
                for(c=b+1; c<26; c++) {
//                    cout << "TEST " << a << ' ' << b << ' ' << c << endl;
                    if(!makeGraph()) continue;

                    ans += sat();
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
11
GU 1 1
ML 1 0
WE 1 1
IN 1 0
EA 2 2
VP 2 0
NT 2 2
UY 2 1
TQ 2 1
LH 2 0
UL 2 0
*/
