/// MAX FLOW = MIN CUT

#include<bits/stdc++.h>
#define LIM 110
#define vi vector<int>
#define pb push_back
#define IM 10000007

using namespace std;

int m,n,w, row[LIM], col[LIM], grid[LIM][LIM];
int graph[LIM][LIM], st,ed;
bool allow[LIM][LIM], dr[LIM], dc[LIM];

int bfs() {
    int cap = -1;
    int keys[LIM], par[LIM], vis[LIM];
    memset(keys, -1, sizeof(keys));
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    keys[st] = IM;
    queue<int>q;
    q.push(st);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;

        if(u == ed) {
            cap = keys[u];
            break;
        }

        for(int v=0; v<=ed; v++) {
            if(graph[u][v] > 0 && v != par[u] && !vis[v]) {
                if(keys[v] == -1 || min(keys[u],graph[u][v]) < keys[v]) {
                    keys[v] = min(keys[u],graph[u][v]);
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    }

    if(cap == -1) return cap;

    int v = ed;
    int u = par[v];
    while(u != -1) {
        graph[u][v] -= cap;
        graph[v][u] += cap;
        u = par[u];
        v = par[v];
    }
    return cap;
}

int flow() {
    int ans = 0;
    while(true) {
        int temp = bfs();
        if(temp <= 0) break;
        ans += temp;
    }
    return ans;
}

void print() {
//    cout << "GRAPH" << endl;
//    for(int i=0; i<=m+n+1; i++) {
//        for(int j=0; j<=m+n+1; j++) {
//            cout << graph[i][j] ;
//        }
//        cout << endl;
//    }
//    cout << "GRID " << endl;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
//            cout << grid[i][j] ;
            printf("%d", grid[i][j]);
        }
        printf("\n");
//        cout << endl;
    }
//    getchar();
}

int f() {
    memset(grid, 0, sizeof grid);
    int tar = 0, bb = 0;
    for(int i=1; i<=m; i++) tar += row[i];
    for(int i=1; i<=n; i++) bb += col[i];
    int got = flow();

//    cout << tar << ' ' << bb << ' ' << got << endl;

    if(tar != got || bb != got) return -1;

//    gcopy();

//    cout << "INIT " << endl;


//     print();

    for(int u=1; u<=m; u++) {
        for(int v=m+1; v<=n+m; v++) {
            if(graph[u][v]) {
                grid[u][v-m] = 0;
                graph[u][v] = 0;
//                cout << u << ' ' << v << " jayga moto" << endl;
            }
            else {
                graph[st][u]++; graph[u][v]++; graph[v][ed]++;
                graph[u][st]--; graph[v][u]--; graph[ed][v]--;
                graph[u][v] = 0;

//                cout << "REVERSED ";
//                print();

                int temp = flow(); //gcopy();

//                cout << "EKHN " << temp << endl;

                if(temp) {
                    grid[u][v-m] = 0; //graph[u][v]
//                    cout << u << ' ' << v << ' ' << "charao chole " << endl;

                }
                else {
                    graph[st][u]--; graph[u][v]--; graph[v][ed]--;
                    graph[u][st]++; graph[v][u]++; graph[ed][v]++;
                    graph[u][v] = 0;
                    grid[u][v-m] = 1;
//                    cout << u << ' ' << v << " CHARA CHOLE NA " << endl;
                }
            }
//            getchar();
//            print();
        }

    }

//    print();




    return 0;
}

int main() {
//    freopen("1330i.txt", "r", stdin);
//    freopen("1330o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(graph, 0, sizeof(graph));
        scanf("%d %d", &m,&n);
        st = 0; ed = m+n+1;

        for(int i=1; i<=m; i++) {
            scanf("%d", &row[i]);
            graph[st][i] = row[i];
        }
        for(int i=1; i<=n; i++) {
            scanf("%d", &col[i]);
            graph[m+i][ed] = col[i];
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                graph[i][m+j] = 1;
            }
        }

//        for(int i=0; i<=ed; i++) {
//            for(int j=0; j<=ed; j++) {
//                cout << graph[i][j] << ' ' ;
//            }
//            cout << endl;
//        }

        if(f() == -1) printf("Case %d: impossible\n", t);
        else {
            printf("Case %d:\n", t);
            for(int i=1; i<=m; i++) {
                for(int j=m+1; j<=m+n; j++) {
                    printf("%d", grid[i][j-m]);
                }
                printf("\n");
            }
        }
//        cout << f() << endl;
    }
    return 0;
}
