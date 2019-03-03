#include <bits/stdtr1c++.h>
#define ll long long int

#define MAXN 200010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

/// Implicit treap for SPOJ Horrible, Range updates and range queries

struct node{
    node *l, *r;
    int subtree, priority;
    long long sum, val, lazy;
    long prf, suf, mxx;
    inline node(){
        l = r = 0;
    }

    inline node(long long v, int p){
        l = r = 0;
        priority = p;
        subtree = 1, val = sum = v, lazy = 0;
    }

    inline node(long long v){
        l = r = 0;
        priority = rand();
        subtree = 1, val = sum = v, lazy = 0;
        prf = suf = mxx = v;
    }

    inline void update(){
        subtree = 1;
        if (l) subtree += l->subtree;
        if (r) subtree += r->subtree;
    }
} pool[MAXN]; /// Maximum number of nodes in treap

ll gprf(node * p) {
    if(p) return p->prf;
    return 0;
}
ll gsuf(node * p) {
    if(p) return p->suf;
    return 0;
}
ll gmxx(node * p) {
    if(p) return p->mxx;
    return INT_MIN;
}
ll gsum(node * p) {
    if(p) return p->sum;
    return 0;
}

struct Treap{
    int idx;
    struct node* root;

    /// Update root node from left child, right child and itself!
    inline void join(node* cur){
        if (!cur) return;

        cur->update();

        cur->sum = gsum(cur->l) + cur->val + gsum(cur->r);
        cur->prf = max(gprf(cur->l), gsum(cur->l) + cur->val + max(0LL, gprf(cur->r)) );
        cur->suf = max(gsuf(cur->r), gsum(cur->r) + cur->val + max(0LL, gsuf(cur->l)) );
        cur->mxx = max( max(gmxx(cur->l), gmxx(cur->r)) , max(0LL, gsuf(cur->l)) + cur->val + max(0LL, gprf(cur->r)) );

    }

    /// Merges two treaps l and r
    inline void merge(node* &cur, node* l, node* r){
        if (!l || !r) cur = l ? l : r;
        else if (l->priority > r->priority) merge(l->r, l->r, r), cur = l;
        else merge(r->l, l, r->l), cur = r;
        join(cur); /// Update root node from left child, right child and itself!
    }

    /// Splits treap cur, counter is the implicit key on subtree size
    inline void split(node* cur, node* &l, node* &r, int key, int counter = 0){
        if (!cur){
            l = r = 0;
            return;
        }

        int cur_key = counter + (cur->l ? cur->l->subtree : 0);
        if (key <= cur_key) split(cur->l, l, cur->l, key, counter), r = cur;
        else split(cur->r, cur->r, r, key, cur_key + 1), l = cur;
        join(cur); /// Update root node from left child, right child and itself!
    }

    /// Inserts a number in the i'th position with value v
    inline void insert(int i, long long v){
        node *l, *r;
        split(root, l, r, i-1);
        pool[idx] = node(v);
        merge(root, l, &pool[idx++]); /// New node created here
        merge(root, root, r);
    }

    ///Erase the number which is currently in position p
    inline void erase(int p) {
        node *l, *r, *m, *n;
        split(root, l, r, p - 1);
        split(r, m, n, 1);
        merge(root, l, n);
        join(root);
    }

    /// Adds v to the segment [a:b]
    inline void update(int p, long long v){
        node *l, *r, *m;
        split(root, l, r, p - 1);
        split(r, m, r, 1);
        m->val = m->prf = m->suf = m->sum = m->mxx = v;
        merge(m, m, r);
        merge(root, l, m);
    }

    /// Returns the sum of the segment[a:b]
    inline long long query(int a, int b){
        node *l, *r, *m;
        split(root, l, r, a - 1);
        split(r, m, r, b - a + 1);

        long long res = m->mxx;
        merge(m, m, r);
        merge(root, l, m);
        return res;
    }

    Treap(){
        srand(time(0));
        idx = 0, root = 0;
    }
};

int main(){
    int t, n, q, i, j, k, f, l, r, x, v;

    Treap T = Treap();

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        T.insert(i, x);
    }

    scanf("%d", &q);
    while (q--){
        int cmd;
        int x,y;
        scanf("%d", &cmd);
        if(cmd == 0) {
            scanf("%d %d", &x, &y);
            T.update(x, y);
        }
        else {
            scanf("%d %d", &x,&y);
            if(x > y) swap(x,y);
            printf("%lld\n", T.query(x,y));
        }
    }
    return 0;
}

