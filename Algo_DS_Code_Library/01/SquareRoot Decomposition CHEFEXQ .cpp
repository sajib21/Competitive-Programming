#include <bits/stdc++.h>
#define ll long long int
#define LIM 200000
#define LT  420
#define MX 1200000
#define vii vector<int>

using namespace std;

int n,q, ara[LIM+10], cum[LIM+10];

struct SqrtDecom {
    int data[LIM+10], sz;
    int segNum, segSize ;
    int val[LT+2][MX+10], prop[LT+10];

    SqrtDecom() { memset(val, 0, sizeof val); memset(prop, 0, sizeof prop); }

    void init() {
        sz = n;
        for(int i=0; i<n; i++) data[i] = cum[i];

        segSize = sqrt(sz);
        segNum = sqrt(sz) + 5;
        for(int i=0; i<sz; i++) {
            int segPos = i/segSize;
            val[segPos][ data[i] ]++;
        }
    }

    void update(int pos, int x) {
        int curSeg = pos/segSize;
        int cur = curSeg*segSize;
        int pre = prop[curSeg];
        prop[curSeg] = 0;

        while(cur < pos) {
            val[curSeg][ data[cur] ]--;
            data[cur] ^= pre;
            val[curSeg][ data[cur] ]++;
            cur++;
        }
        cur = (curSeg+1)*segSize;

        while(pos < cur) {
            val[curSeg][ data[pos] ]--;
            data[pos] ^= pre^x;
            val[curSeg][ data[pos] ]++;
            pos++;
        }

        curSeg++;
        while(curSeg < segNum) prop[curSeg++] ^= x;
    }

    int query(int pos, int x) {
        int ans = 0;
        int rgtSeg = pos/segSize;

        for(int p = 0; p < rgtSeg; p++) {
            ans += val[p][ x^prop[p] ];
        }
        int cur = rgtSeg*segSize;
        while(cur <= pos) ans += ( (prop[rgtSeg]^data[cur++]) == x);
        return ans;
    }
};


SqrtDecom tree;

int main() {
    scanf("%d %d", &n,&q);
    for(int i=0; i<n; i++) scanf("%d", &ara[i]);
    cum[0] = ara[0];
    for(int i=1; i<n; i++) cum[i] = cum[i-1] ^ ara[i];

    tree.init();

    while(q--) {
        int t,i,x;
        scanf("%d %d %d", &t,&i,&x); i--;
        if(t == 1) {
            tree.update(i, ara[i]^x);
            ara[i] = x;
        }
        else {
            printf("%d\n", tree.query(i, x));
        }
    }
    return 0;
}
