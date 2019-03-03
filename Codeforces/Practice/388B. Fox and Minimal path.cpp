#include <bits/stdc++.h>
#define vii vector<int>
#define LIM 1010
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

int n,k,d, grid[1010][1010], NODES=0;
vii graph[LIM];

int f(int rem) {
    if(!rem) return 0;
    return 1 + f(rem/2);
}

void h(int u, int cur) {
    if(cur == 1) {
        grid[u][1] = grid[1][u] = 1;
        return;
    }
    int v = ++NODES;
    grid[u][v] = grid[v][u] = 1;
    h(v, cur-1);
}

void g(int u, int v, int rem, int cur) {
    if(cur == 1) {
        grid[u][1] = grid[1][u] = grid[v][1] = grid[1][v] = 1;
        return;
    }
    int w,x;
    if(rem&1) {
        w = ++NODES;
        if(NODES == 1) w = ++NODES;
        grid[u][w] = grid[w][u] = grid[v][w] = grid[w][v] = 1;
        h(w, cur-1);
        rem--;
    }
    w = ++NODES; if(NODES == 1) w = ++NODES;
    x = ++NODES;
    grid[u][w] = grid[w][u] = grid[u][x] = grid[x][u] = 1;
    grid[v][w] = grid[w][v] = grid[v][x] = grid[x][v] = 1;
    g(w,x, rem/2, cur-1);
}

int main() {
    scanf("%d", &k);
    d = f(k);
    g(0,0, k, d);
    if(NODES < 2) NODES++;
    printf("%d\n", NODES+1);
    for(int u=0; u<=NODES; u++) {
        for(int v=0; v<=NODES; v++) {
            if(grid[u][v]) printf("Y");
            else           printf("N");
        }
        printf("\n");
    }
}
