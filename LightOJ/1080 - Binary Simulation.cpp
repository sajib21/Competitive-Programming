#include<bits/stdc++.h>

using namespace std;

int tree[3*100005] ;

int n,q, sz, l,r;
char ch, bin[100005];

void update(int node, int st, int ed, int l, int r) {

//    cout << st << ' ' << ed << ' ' << l << ' ' << r << endl;
//    getchar();
    if(ed < l || st > r ) return ;
    if(st >= l && ed <= r) {
        tree[node]++;
        return;
    }

    int left = 2*node, right = 2*node + 1, mid = (st+ed)/2;
    update(left, st,mid, l,r);
    update(right, mid+1, ed, l,r);
//    tree[node].prop = tree[left].prop + tree[right].prop;
}

int query(int node, int st, int ed, int l, int carry = 0) {

    if(ed < l || st >  l) return 0;
    if(st == l && ed == l) return tree[node] + carry;
    int left = 2*node, right = 2*node + 1, mid = (st+ed)/2;
    return query(left, st,mid, l, carry+tree[node]) + query(right, mid+1,ed, l, carry+tree[node]);
}

int main() {

    int T,t;
    cin >> T;
    for(t=1; t<=T; t++) {
        memset(tree, 0, sizeof(tree));
//        cin >> n;
        scanf("%s", bin);
        n = strlen(bin);

        scanf("%d", &q); getchar();
        printf("Case %d:\n", t);
        while(q--) {
            scanf("%c", &ch);
            if(ch == 'I') {
                scanf("%d %d", &l,&r);
                update(1, 1,n, l,r);
            }
            else {
                scanf("%d", &l);
                int tmp = query(1, 1,n, l);
//                cout << "tmp e " << tmp << endl;
                if(tmp % 2 ) printf("%d\n", !(bin[l-1]-'0'));
                else printf("%d\n", bin[l-1]-'0');
            }
            getchar();
        }
    }

}
