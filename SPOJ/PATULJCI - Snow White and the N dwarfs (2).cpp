#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

struct query {
    int st, ed, indx, ans,id;
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

int n,c,q, ara[300003], flag[100010], cnt;
query queries[100005];

int main() {

    int T;
//    cin >> T;
    T= 1;
    for(int t=1; t<=T; t++) {

        memset(flag, 0, sizeof(flag));
        memset(queries, 0, sizeof(queries));
        ara[0] = 100005;
//        cnt = 0;

        scanf("%d %d", &n, &c);



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
            while(rgt >= queries[i].ed) {
                flag[ ara[rgt] ]--;

                if( lft >= queries[i].st && flag[ ara[rgt] ] > (queries[i].ed-queries[i].st+1)/2) {
                    queries[i].ans = 1;
                    queries[i].id = ara[rgt];
                }

                rgt--;
            }
            while(lft <= queries[i].st) {
                flag[ ara[lft] ]--;

                if( rgt <= queries[i].ed && flag[ ara[lft] ] > (queries[i].ed-queries[i].st+1)/2) {
                    queries[i].ans = 1;
                    queries[i].id = ara[lft];
                }
                lft++;
            }

            while(rgt < queries[i].ed) {
                rgt++;
                flag[ ara[rgt] ]++;
                if( lft >= queries[i].st && flag[ ara[rgt] ] > (queries[i].ed-queries[i].st+1)/2) {
                    queries[i].ans = 1;
                    queries[i].id = ara[rgt];
                }
            }

            while(lft > queries[i].st) {
                lft--;
                flag[ ara[lft] ]++;
                if( rgt <= queries[i].ed && flag[ ara[lft] ] > (queries[i].ed-queries[i].st+1)/2) {
                    queries[i].ans = 1;
                    queries[i].id = ara[lft];
                }
            }

        }

        sort(queries, queries+q, cmp2);

//        printf("Case %d:\n", t);
        for(int i=0; i<q; i++) {
            if(queries[i].ans) printf("yes %d\n", queries[i].id);
            else printf("no\n");
        }

    }

    return 0;


}
