#include<bits/stdc++.h>
#define LIM 200000
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

int n,m;
string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char seq[LIM+100], temp[LIM+100];
int segTree[3*LIM+100];

int init(int node, int st, int ed) {
    if(st == ed) return segTree[node] = 1;
    segVar;
    return segTree[node] = init(lft, st,md) + init(rgt, md+1,ed);
}

int query(int node, int st, int ed, int p) {
    segVar;
    if(st == ed) return st;
    if(p <= segTree[lft]) return query(lft, st,md, p);
    else return query(rgt, md+1, ed, p-segTree[lft]);
}

void update(int node, int st, int ed, int p) {

    if(ed < p || st > p) return;

//    cout << node << ' ' << st << ' ' << ed << ' ' << p << endl; getchar();

    if(st >= p && ed <= p) {
        segTree[node] = 0;
        return;
    }
    segVar;
    update(lft, st,md, p); update(rgt, md+1,ed, p);
    segTree[node] = segTree[lft] + segTree[rgt];
}

int main() {
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

    while(m--) {

        int x,y,z;
        char c;
        scanf("%d %d %c", &x,&y,&c);
        if(c >= '0' && c <= '9') z = c - '0';
        else if(c >= 'a' && c <= 'z') z = c - 'a' + 10;
        else if(c >= 'A' && c <= 'Z') z = c - 'A' + 10 + 26;

        queue<int>q;
        while(x <= y) {
            int in = query(1, 1,n, x);
            if(seq[in] == z) q.push(in);
            x++;
        }

        while(!q.empty()) {
            update(1, 1,n, q.front());
            q.pop();
        }


//        int rem = segTree[1]; cout << "SO " << rem << endl;
//        for(int i=1; i<=rem; i++) printf("%c", code[ seq[ query(1, 1,n, i) ] ]);
//        printf("\n");


    }

    int rem = segTree[1];
//    for(int i=1; i<=rem; i++) cout << query(1,1,n, i) << ' ';
    for(int i=1; i<=rem; i++) printf("%c", code[ seq[ query(1, 1,n, i) ] ]);
    printf("\n");

    return 0;
}
