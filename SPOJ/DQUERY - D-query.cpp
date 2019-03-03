#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

struct query {
    int st, ed, indx, ans;
};

int rootN;

bool cmp(query q1, query q2) {

    int seg1 = q1.st/rootN, seg2 = q2.st/rootN;
    if(seg1 == seg2) return q1.ed < q2.ed;
    return seg1 < seg2;
}
bool cmp2(query q1, query q2) {
    return q1.indx < q2.indx;
}

int n,q, ara[30003], flag[1000100], cnt;
query queries[200005];

int main() {

    int T;
//    cin >> T;
    T= 1;
    for(int t=1; t<=T; t++) {

        memset(flag, 0, sizeof(flag));
        memset(queries, 0, sizeof(queries));
        ara[0] = 1000005;
//        cnt = 0;

        scanf("%d", &n);
        rootN = sqrt(n);
        for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
        scanf("%d", &q);
        for(int i=0; i<q; i++) {
            scanf("%d %d", &queries[i].st, &queries[i].ed);
            queries[i].indx = i;
        }

        sort(queries, queries+q, cmp);

//        cout << "QUERIES" << endl;
//        for(int i=0; i<q; i++) cout << queries[i].st << ' ' << queries[i].ed << endl;
        int lft=0, rgt=0, cnt = 0;
        for(int i=0; i<q; i++) {
//            cnt = 0;
            while(rgt < queries[i].ed) {
                rgt++;
                if(!flag[ ara[rgt] ]) cnt++;
                flag[ ara[rgt] ]++;
            }
            while(rgt > queries[i].ed) {
                flag[ ara[rgt] ]--;
                if(!flag[ ara[rgt] ]) cnt--;
                rgt--;
            }
            while(lft < queries[i].st) {
                flag[ ara[lft] ]--;
                if(!flag[ ara[lft] ]) cnt--;
                lft++;
            }
            while(lft > queries[i].st) {
                lft--;
                if(!flag[ ara[lft] ]) cnt++;
                flag[ ara[lft] ]++;
            }
            queries[i].ans = cnt;
        }

        sort(queries, queries+q, cmp2);

//        printf("Case %d:\n", t);
        for(int i=0; i<q; i++) printf("%d\n", queries[i].ans);
    }

    return 0;


}
