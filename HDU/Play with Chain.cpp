#include <bits/stdtr1c++.h>

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
    }

    inline void update(){
        subtree = 1;
        if (l) subtree += l->subtree;
        if (r) subtree += r->subtree;
    }
} pool[MAXN]; /// Maximum number of nodes in treap

struct Treap{
    int idx;
    struct node* root;

    /// Lazy propagation
    inline void push(node* cur){
        if (!cur || !cur->lazy) return;
        cur->update();

        swap(cur->l, cur->r);

        if (cur->l) cur->l->lazy ^= 1;
        if (cur->r) cur->r->lazy ^= 1;
        cur->lazy = 0;
    }

    /// Update root node from left child, right child and itself!
    inline void join(node* cur){
        if (!cur) return;

        cur->update();

        if (cur->l) push(cur->l);
        if (cur->r) push(cur->r);
    }

    /// Merges two treaps l and r
    inline void merge(node* &cur, node* l, node* r){
        push(l), push(r); /// Lazy propagation
        if (!l || !r) cur = l ? l : r;
        else if (l->priority > r->priority) merge(l->r, l->r, r), cur = l;
        else merge(r->l, l, r->l), cur = r;
        if (cur) join(cur); /// Update root node from left child, right child and itself!
    }

    /// Splits treap cur, counter is the implicit key on subtree size
    inline void split(node* cur, node* &l, node* &r, int key, int counter = 0){
        if (!cur){
            l = r = 0;
            return;
        }

        push(cur); /// Lazy propagation
        int cur_key = counter + (cur->l ? cur->l->subtree : 0);
        if (key <= cur_key) split(cur->l, l, cur->l, key, counter), r = cur;
        else split(cur->r, cur->r, r, key, cur_key + 1), l = cur;
        if (cur) join(cur); /// Update root node from left child, right child and itself!
    }

    /// Faster insert when appending to the end, appends node v to the end of the array
    inline void build(int i, int v){
        pool[idx] = node(v);
        merge(root, root, &pool[idx++]);
    }

    /// Builds an implicit treap from an array and returns pointer to the root in O(n)
    inline node* build(int i, int j, int* ar){
        int k = (i + j) >> 1;
        pool[idx] = node(ar[k], (j - i + 1));
        node *cur = &pool[idx++];
        if (i < k) cur->l = build(i, k - 1, ar);
        if (j > k) cur->r = build(k + 1, j, ar);
        join(cur);
        return cur;
    }

    /// Inserts a number in the i'th position with value v
    inline void insert(int i, long long v){
        node *l, *r;
        split(root, l, r, i);
        pool[idx] = node(v);
        merge(root, l, &pool[idx++]); /// New node created here
        merge(root, root, r);
    }

    /// Adds v to the segment [a:b]
    inline void update(int a, int b, long long v){
        node *l, *r, *m;
        split(root, l, r, a - 1);
        split(r, m, r, b - a + 1);
        m->lazy += v;
        merge(m, m, r);
        merge(root, l, m);
    }

    /// Returns the sum of the segment[a:b]
    inline int query(int a){
        node *l, *r, *m;
        split(root, l, r, a - 1);
        split(r, m, r, 1);

        long long res = m->val;
        merge(m, m, r);
        merge(root, l, m);
        return res;
    }

    Treap(){
        srand(time(0));
        idx = 0, root = 0;
    }

    inline int size(){
        if (root) return root->subtree;
        return 0;
    }

    void cut(int a, int b, int c) {
        node *u, *v, *w;
        split(root, root, u, a-1);
        split(u, u, v, b-a+1);
        merge(root, root, v);

        split(root, root, v, c);
        merge(root, root, u);
        merge(root, root, v);
    }

    void flip(int a, int b) {
        node *u, *v, *w;

        split(root, root, u, a-1);
        split(u, u, v, b-a+1);
        u->lazy ^= 1;
        merge(u, u,v);
        merge(root, root, u);
    }
};

int main(){
    int t, n, q, i, j, k, f, l, r, x, v;
    char cmd[10];

//    scanf("%d", &t);
    while(true){
        Treap T = Treap();
        scanf("%d %d", &n, &q);

        if(n == -1) return 0;

        for (i = 1; i <= n; i++) T.insert(i, i);

        while (q--){
            scanf("%s", cmd);

            if(cmd[0] == 'C') {
                scanf("%d %d %d", &l, &r, &x);
                T.cut(l,r, x);
            }
            else {
                scanf("%d %d", &l, &r);
                T.flip(l,r);
//                for(int i=1; i<=n; i++) cout << T.query(i) << ' '; cout << endl;
            }


        }

        bool ff = false;
        for(int i=1; i<=n; i++) {
            if(ff) printf(" ");
            ff = true;
            printf("%d", T.query(i));
        }
        printf("\n");


    }



    return 0;
}
