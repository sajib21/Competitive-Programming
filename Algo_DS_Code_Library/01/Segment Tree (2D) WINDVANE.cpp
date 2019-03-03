char dir[] = {'N', 'W', 'S', 'E' };

struct info{
    int x,y,z;
    info() {x = y = z = 0;}
    info(int xx, int yy = 0, int zz = 0) {
        x = xx; y = yy; z = zz;
    }
};

int m,n,q;
char grid[LIM+10][LIM+10];
int val[LIM+10][LIM+10];
int segTree[4*LIM+10][4*LIM+10];

void updateX(int node, int st, int ed, int stC, int edC, int lr, int rr, int lc, int rc, int val);
void updateY(int row, int node, int st, int ed, int l, int r, int val);
int queryX(int node, int st, int ed, int stC, int edC, int r, int c, int prop);
int queryY(int row, int node, int st, int ed, int c, int prop);

void updateX(int node, int st, int ed, int stC, int edC, int lr, int rr, int lc, int rc, int val) {
    if(ed < lr || st > rr) return;
    if(st >= lr && ed <= rr) {
        updateY(node, 1, stC,edC, lc,rc, val);
        return;
    }
    segVar;
    updateX(lft, st, md, stC, edC, lr, rr, lc, rc, val);
    updateX(rgt,md+1,ed, stC, edC, lr, rr, lc, rc, val);
}
void updateY(int row, int node, int st, int ed, int l, int r, int val) {
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[row][node] = (segTree[row][node]+val +4) % 4;
        return;
    }
    segVar;
    updateY(row, lft, st,md, l,r, val); updateY(row, rgt, md+1,ed, l,r, val);
}

int queryX(int node, int st, int ed, int stC, int edC, int r, int c, int prop = 0) {
    prop = (prop + queryY(node, 1, 1,n, c,0) +4) % 4;
    if(ed < r || st > r) return 0;
    if(st >= r && ed <= r) return prop;
    segVar;
    if(r <= md) return queryX(lft, st, md, stC, edC, r,c, prop);
    else return queryX(rgt, md+1,ed, stC,edC, r,c, prop);
}
int queryY(int row, int node, int st, int ed, int c, int prop = 0) {
    prop = (prop + segTree[row][node] +4) % 4;
    if(ed < c || st > c) return 0;
    if(st >= c && ed <= c) return prop;
    segVar;
    if(c <= md) return queryY(row, lft, st, md, c, prop);
    else return queryY(row, rgt, md+1,ed , c, prop);
}

int main() {
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++) scanf("%s", grid[i]);
    for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) {
        if(grid[i-1][j-1] == 'N') val[i][j] = 0;
        else if(grid[i-1][j-1] == 'W') val[i][j] = 1;
        else if(grid[i-1][j-1] == 'S') val[i][j] = 2;
        else if(grid[i-1][j-1] == 'E') val[i][j] = 3;
    }
    scanf("%d", &q);
    while(q--) {
        char c[3]; int x,y, xa,ya,xb,yb, v;
        scanf("%s", c);
        if(c[0] == 'C') {
            scanf("%d %d %d %d %d", &xa,&ya,&xb,&yb,&v);
            if(!v) v = -1;
            updateX(1, 1,m, 1,n, xa,xb, ya,yb, v);
        }
        else {
            scanf("%d %d", &x,&y);
            int an = (val[x][y] + queryX(1, 1,m, 1,n, x,y) +4) % 4;
            printf("%c\n", dir[an%4]);
        }
    }

    return 0;
}

