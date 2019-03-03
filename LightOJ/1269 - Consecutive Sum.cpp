#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 50000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

struct node {
    bool endPoint;
    node *go[2];
    node() { endPoint = false; go[0] = go[1] = NULL; }
};

void addWord(int num, node *root) {
    int ara[33];
    for(int i=32; i>0; i--) {
        ara[i] = num % 2;
        num /= 2;
    }

    node *cur = root;
    for(int i=1; i<=32; i++) {
        int nw = ara[i];
        if(cur->go[nw] == NULL) cur->go[nw] = new node();
        cur = cur->go[nw];
    }
    cur->endPoint = true;
}

ll chkWord(int num, node *root) {
    int ara[33];
    for(int i=32; i>0; i--) {
        ara[i] = num % 2;
        num /= 2;
    }

    ll ans = 0;
    node *cur = root;
    for(int i=1; i<=32; i++) {
        int nw = !ara[i];
        if(cur->go[nw] == NULL) nw = !nw;
        cur = cur->go[nw];
        ans = ans*2 + nw^ara[i];
    }
    return ans;
}

ll chkWord2(int num, node *root) {
    int ara[33];
    for(int i=32; i>0; i--) {
        ara[i] = num % 2;
        num /= 2;
    }

    ll ans = 0;
    node *cur = root;
    for(int i=1; i<=32; i++) {
        int nw = ara[i];
        if(cur->go[nw] == NULL) nw = !nw;
        cur = cur->go[nw];
        ans = ans*2 + nw^ara[i];
    }
    return ans;
}

void deleteTrie(node *root) {
    if(root->go[0]) deleteTrie(root->go[0]);
    if(root->go[1]) deleteTrie(root->go[1]);
    delete(root);
}

int n, ara[LIM+10] , xorSum[LIM+10];
node *root;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        root = new node();
        scanf("%d", &n);
        addWord(0, root);
        for(int i=1; i<=n; i++) {
            scanf("%d", &ara[i]);
            xorSum[i] = xorSum[i-1] ^ ara[i];
            addWord(xorSum[i], root);
        }
        ll mxx = 0, mnn = INT_MAX;
        for(int i=1; i<=n; i++) mxx = max( mxx, chkWord(xorSum[i], root) );
        for(int i=1; i<=n; i++) mnn = min( mnn, chkWord2(xorSum[i], root) );

        printf("Case %d: %lld %lld\n", t, mxx, mnn);
        deleteTrie(root);
    }
        return 0;
}
