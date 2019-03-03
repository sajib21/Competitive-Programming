#include<bits/stdc++.h>
#define pii pair<int,int>
#define mpr make_pair
#define LIM 6000
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
//#define ff first
//#define ss second

using namespace std;

struct info {
    int ff,ss, ans;
    info() {ff = ss = ans;}
    info(int f, int s, int a) {
        ff = f; ss = s; ans = a;
    }
};

int n;
info ara[3030];
int segTree[4*LIM + 100];

bool cmpff(info a, info b) { return a.ff < b.ff; }
bool cmpss(info a, info b) { return a.ss < b.ss; }

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = st;
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1, ed);
    int a = segTree[lft], b = segTree[rgt];
    if(ara[ a ].ff-ara[a-1].ff > ara[b].ff-ara[b-1].ff) segTree[node] = a;
    else segTree[node] = b;
    return;
}

int query(int node, int st, int ed, int l, int r) {
    if(st > r || ed < l) return -1;
//    if(st > r) return r;
//    if(ed < l) return l;
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    int a = query(lft, st,md, l,r), b = query(rgt, md+1, ed, l,r);
    if(a == -1) return b;
    if(b == -1) return a;
    if(ara[ a ].ff-ara[a-1].ff > ara[b].ff-ara[b-1].ff) return a;
    else return b;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i].ff);
        ara[i].ss = i;
    }
    n++;

    sort(ara+1, ara+n, cmpff);
    ara[0].ff = ara[1].ff; ara[0].ss = ara[1].ss;
    init(1, 1,n-1);


//        for(int i=1; i<n; i++) cout << ara[i].ff << ' ' ; cout << endl;

    int x,y,z, p;
    int a=-1,b=-1,c=-1,d=-1,e=-1;
    int crossa, crossb, crossc;
    for(int i=n-1; i>2; i--) { ///ei porjonto 1st er
        for(int j=i-1; j>1; j--) { ///ei porjonto 2nd er
            x = n-i; y = (n-x)-j;
            if(x > 2*y || y > 2*x) continue;
//            if(!x || !y) continue;
            int zmin = max( (x+1)/2 , (y+1)/2 );
            int zmax = min( 2*x, 2*y );
            int l = max(1, j-zmax) , r = max(1, j-zmin);

//            cout << "TEST " << j << ' ' << i << ' ' << x << ' ' << y << ' ' << l << ' ' << r << endl; getchar();
            if(l >= j || r >= j) continue;
            int k = query(1, 1,n-1, l, r );
            if(k == -1) continue;



//            for(int k=j-1; k>0; k--) {

//                x = n-i; y = (n-x)-j; z = (n-x-y)-k; p = (n-x-y-z);
//                if(x <= 2*y && y <= 2*x && y <= 2*z && z <= 2*y && x <= 2*z && z <= 2*x) {
//                    cout << i << ' ' << j << ' ' << k << endl; //getchar();
                    if(ara[i].ff - ara[i-1].ff > a) {
                        a = ara[i].ff - ara[i-1].ff;
                        b = ara[j].ff - ara[j-1].ff;
                        c = ara[k].ff - ara[k-1].ff;
                        crossa = i; crossb = j; crossc = k;
                    }
                    else if(ara[i].ff - ara[i-1].ff == a) {
                        if(ara[j].ff - ara[j-1].ff > b) {
                            b = ara[j].ff - ara[j-1].ff;
                            c = ara[k].ff - ara[k-1].ff;
                            crossa = i; crossb = j; crossc = k;
                        }
                        else if(ara[j].ff - ara[j-1].ff == b) {
                            if(ara[k].ff - ara[k-1].ff > c) {
                                c = ara[k].ff - ara[k-1].ff;
                                crossa = i; crossb = j; crossc = k;
                            }
//                            else if(ara[k].ff - ara[k-1].ff == c)
                        }
                    }
//                    cout << a << ' ' << b << ' ' << c << endl; getchar();
//                }
//            }
//                cout << k << ' ' << j << ' ' << i << " AND " << crossc << ' ' << crossb << ' ' << crossa <<    endl; getchar();
        }
    }
//    cout << "CROSS " << crossa << ' ' << crossb <<  ' ' << crossc << endl;
    int id = 1;
    for(int i=n-1; i>0; i--) {
        ara[i].ans = id;
//        cout << i << ' ' << id << ' ' << n << endl;
        if(i == crossa || i == crossb || i == crossc) id++;
    }

//    for(int i=1; i<n; i++) {
//        if(i != 1) printf(" ");
//        if(ara[i].ans < 4) printf("%d", ara[i].ans);
//        else printf("%d", -1);
//    }
//    printf("\n");

    sort(ara+1, ara+n, cmpss);

    for(int i=1; i<n; i++) {
        if(i != 1) printf(" ");
        if(ara[i].ans < 4) printf("%d", ara[i].ans);
        else printf("%d", -1);
    }
    printf("\n");

    return 0;
}
