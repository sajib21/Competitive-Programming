#include<bits/stdc++.h>
#define LIM 50000
#define ll long long int

using namespace std;

struct node {

    ll total, bestSum, prefixSum, suffixSum;

    node() {
        total = INT_MIN, bestSum = INT_MIN, prefixSum = INT_MIN, suffixSum = INT_MIN;
    }
    node(ll t, ll b, ll p, ll s) {
        total = t, bestSum = b, prefixSum = p, suffixSum = s;
    }
};

int n,m, ara[LIM + 10];
node segTree[6*LIM + 100];
int x1,Y1,x2,y2;

void initMax(int indx, int st, int ed) {

    if(st == ed) {
        segTree[indx] = node(ara[st], ara[st], ara[st], ara[st]);
        return;
    }

    int lft = indx << 1 , rgt = (indx << 1) + 1 , mid = (st+ed)/2;
    initMax(lft, st,mid);
    initMax(rgt, mid+1, ed);

    segTree[indx].total = segTree[lft].total + segTree[rgt].total;
    segTree[indx].prefixSum = max(segTree[lft].prefixSum , segTree[lft].total + segTree[rgt].prefixSum);
    segTree[indx].suffixSum = max(segTree[rgt].suffixSum , segTree[rgt].total + segTree[lft].suffixSum);
    segTree[indx].bestSum   = max(segTree[lft].suffixSum + segTree[rgt].prefixSum , max(segTree[lft].bestSum , segTree[rgt].bestSum));
}

node queryMax(int indx, int st, int ed, int l, int r) {
//    if(st > Y1 || ed < x2) return node();
    if(l > r) return node(0,0,0,0);

//    node sg = segTree[indx];
//    cout << indx << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << sg.total << ' ' << sg.bestSum << ' ' << sg.prefixSum << ' ' << sg.suffixSum << endl;
//    getchar();

    if(ed < l || st > r) return node(0,INT_MIN,INT_MIN,INT_MIN);
    if(st >= l && ed <= r) return segTree[indx];

    int lft = indx << 1 , rgt = (indx << 1) + 1 , mid = (st+ed)/2;
    node left = queryMax(lft, st,mid, l,r) , right = queryMax(rgt, mid+1, ed, l,r);

    node temp;
    temp.total = left.total + right.total;
    temp.prefixSum = max(left.prefixSum , left.total + right.prefixSum);
    temp.suffixSum = max(right.suffixSum , right.total + left.suffixSum);
    temp.bestSum   = max(left.suffixSum + right.prefixSum , max(left.bestSum , right.bestSum));
//    if(indx == 4) cout << "EK THK DUI " << temp.total << ' ' << temp.bestSum << ' ' << temp.prefixSum << ' ' << temp.suffixSum << endl;
    return temp;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        initMax(1, 1,n);

//        cout << segTree[1].bestSum << ' ' << segTree[1].prefixSum << ' ' << segTree[1].suffixSum << ' ' << segTree[1].total << endl;

        scanf("%d", &m);
        while(m--) {
    //        int c, x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&Y1, &x2,&y2);
    //        if(c == 0) update(1, 1,n, l, r);

            if(Y1 < x2) {
//                int ans = 0;
//                ans += prefixSum[x2-1] - prefixSum[Y1];
//                ans += querySuf(1, 1,n, x1,Y1) - suffixSum[Y1+1] + queryPre(1, 1,n, x2,Y2) - prefixSum[x2-1];
//                cout << prefixSum[x2-1] << ' ' << prefixSum[Y1] << ' ' << querySuf(1, 1,n, x1,Y1) << ' ' << suffixSum[Y1+1] << ' ' <<  queryPre(1, 1,n, x2,Y2) << ' ' << prefixSum[x2-1] << endl;
//                cout << "IN " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

//                cout << "CHK " << queryMax(1, 1,n, Y1+1,x2-1).total << endl;
//                cout << ' ' << queryMax(1, 1,n, x1,Y1).suffixSum  << endl;
//                cout << queryMax(1, 1,n, x2,y2).prefixSum << endl;
                printf("%lld\n", queryMax(1, 1,n, Y1+1,x2-1).total + queryMax(1, 1,n, x1,Y1).suffixSum + queryMax(1, 1,n, x2,y2).prefixSum);
            }
            else {
//                x2 = Y1+1;
                ll ans1 = 0, ans2=0;
                ans1 += queryMax(1, 1,n, x1,Y1).suffixSum + queryMax(1, 1,n, Y1+1,y2).prefixSum;
//                cout << queryMax(1, 1,n, x1,Y1).suffixSum << ' ' << queryMax(1, 1,n, Y1+1,y2).prefixSum << endl;
//                cout << "L " << querySuf(1, 1,n, x1,Y1) << ' ' << suffixSum[Y1+1]  << ' ' <<  queryPre(1, 1,n, Y1+1,Y2)  << ' ' <<  prefixSum[Y1] << ' ' << endl;
                ans2 += queryMax(1, 1,n, x1,x2-1).suffixSum + queryMax(1, 1,n, x2,y2).prefixSum;
//                cout << queryMacx(1, 1,n, x1,x2-1).suffixSum << ' ' << queryMax(1, 1,n, x2,y2).prefixSum << endl;
//                cout << "R " << querySuf(1, 1,n, x1,x2-1)  << ' ' <<  suffixSum[x2]  << ' ' <<  queryPre(1, 1,n, x2,Y2)  << ' ' <<  prefixSum[x2-1]  << ' ' << endl;
//                cout << queryMax(1, 1,n, x2,Y1).bestSum << endl;
                printf("%lld\n", max( x2==Y1? ara[x2] : queryMax(1, 1,n, x2,Y1).bestSum , max(ans1,ans2) ));
//                printf("%d\n", querySuf(1, 1,n, x2,Y2)+queryPre(1, 1,n, x1,Y1)-suffixSum[1]);
            }


//            printf("%lld\n", queryMax(1, 1,n, x1,y2).bestSum);
        }

    }



    return 0;
}
