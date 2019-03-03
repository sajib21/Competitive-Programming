#include<bits/stdc++.h>
#define LIM 200000
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

int n,m;
string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char seq[LIM+5000], temp[LIM+100];
int segTree[4*LIM+10];
int countTree[4*LIM+10][63];
bool prop[4*LIM+10][63];

void propagate(int node) {
    int lft = node*2, rgt = node*2 + 1;
    for(int i=0; i<62; i++) if(prop[node][i]) {
//        if(node == 1 && i < 10) cout << "PROPED " << node << ' ' << i << endl;
        segTree[node] -= countTree[node][i];
        countTree[node][i] = 0;
        if(lft <= LIM) prop[lft][i] = 1;
        if(rgt <= LIM) prop[rgt][i] = 1;
        prop[node][i] = 0;
    }
}

void init(int node, int st, int ed) {
    if(st == ed) {
        countTree[node][ seq[st] ] = 1;
        segTree[node] = 1;
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = segTree[lft] + segTree[rgt];
    for(int i=0; i<62; i++) countTree[node][i] = countTree[lft][i] + countTree[rgt][i];
}

bool f = false;

int query(int node, int st, int ed, int p) {
////    if(segTree[node] < p) return -1;
//    if(f) {
//        cout << node << ' ' << st << ' ' << ed << ' ' << segTree[node] << ' ' << p << endl;
////        getchar();
//    }
    segVar;
    if(st == ed) return st;
    propagate(lft);

    if(p <= segTree[lft]) return query(lft, st,md, p);
    else {
        propagate(rgt);
        return query(rgt, md+1, ed, p-segTree[lft]);
    }
}

void update(int node, int st, int ed, int l, int r, int c) {
    segVar;
    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        segTree[node] -= countTree[node][c];
        countTree[node][c] = 0;
        segVar;
        if(st != ed) prop[lft][c] = 1;
        if(st != ed) prop[rgt][c] = 1;
        return;
    }
    propagate(lft); propagate(rgt);

    update(lft, st,md, l,r, c); update(rgt, md+1,ed, l,r, c);
    segTree[node] = segTree[lft] + segTree[rgt];
    for(int i=0; i<62; i++) countTree[node][i] = countTree[lft][i] + countTree[rgt][i];
}

void log() {
    cout << "CHECKING SEGTREE" << endl;
    for(int i=1; i<=8; i++) cout << i << ' ' << segTree[i] << endl;
    cout << "CHECKING CNTTREE" << endl;
    for(int i=1; i<=8; i++) {
        cout << i << " : ";
        for(int j=0; j<62; j++) if((j >= 10 && j <= 13) || (j >= 10+26 && j <= 10+26+3)) cout << ' ' << countTree[i][j] ;
        cout << endl;
    }
    cout << "CURRENT" << endl;
    int rem = segTree[1];
    for(int i=1; i<=rem; i++) printf("%c", code[ seq[ query(1, 1,n, i) ] ]);
    printf("\n");
}

int main() {
//    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    scanf("%d %d", &n,&m);
    scanf("%s", seq);
//    cin >> seq;
    strcpy(temp, "0");
    strcat(temp, seq);
    strcpy(seq, temp);

    for(int i=1; i<=n; i++) {
        if(seq[i] >= '0' && seq[i] <= '9') seq[i] = seq[i] - '0';
        else if(seq[i] >= 'a' && seq[i] <= 'z') seq[i] = seq[i] - 'a' + 10;
        else if(seq[i] >= 'A' && seq[i] <= 'Z') seq[i] = seq[i] - 'A' + 10 + 26;
    }
    init(1, 1,n);

//    cout << "BUG" << endl;

    while(m--) {

        int x,y,z;
        char c;
        scanf("%d %d %c", &x,&y,&c);
        if(c >= '0' && c <= '9') z = c - '0';
        else if(c >= 'a' && c <= 'z') z = c - 'a' + 10;
        else if(c >= 'A' && c <= 'Z') z = c - 'A' + 10 + 26;

        int l = query(1, 1,n, x);
        int r = query(1, 1,n, y);
        update(1, 1,n, l,r, z);
    }

//    cout << "BUG" << endl;

    int rem = segTree[1];

    f = true;
//    cout << rem << endl;
//    cout << query(1, 1,n, 103524) << endl;
//    for(int i=1; i<=rem; i++) {cout << i << ' '; cout << query(1,1,n, i) << endl;}
    for(int i=1; i<=rem; i++) {
//        cout << i << ' ' ;
        printf("%c", code[ seq[ query(1, 1,n, i) ] ]);
    }
    printf("\n");

    return 0;
}
