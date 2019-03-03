#include<bits/stdc++.h>

using namespace std;

struct res {
    int which;
    int weight;
    res(int ww, int ii) {
        which = ww;
        weight = ii;
    }
};

int n,k[55], brace[55][55];
int grundy[55][55][55];
vector<res>ans;

bool cmp(res a, res b) {
    if(a.which == b.which) return a.weight < b.weight;
    return a.which < b.which;
}

int getGrundy(int which, int st, int ed) {

//    int &ret = brace[which];

    if(grundy[which][st][ed] != -1) return grundy[which][st][ed];

    set<int>sety;

//    int flag[1010];
//    memset(flag, 0, sizeof(flag));

    for(int mv=st; mv<ed; mv++) {
        int tempXor = 0;
        int l, r, x=st;

        for(x=st; x<ed; ) {
            while(x < ed && brace[which][x] >= brace[which][mv]) x++;
            l = x;
            while(x < ed && brace[which][x] < brace[which][mv]) x++;
            r = x;
            if(l < r) tempXor ^= getGrundy(which, l,r);
            l = r;
        }
//        if(st == 0 && ed == k[which]) cout << "B4 MEX " << tempXor << endl;
//        if(tempXor >= 1000)
//            tempXor = 1000;
//        flag[tempXor] = 1;
        sety.insert(tempXor);
//        st.insert(tempXor);
    }

    int ans = 0;
//    while(flag[ans]) ans++;
    while(sety.find(ans) != sety.end()) ans++;
    return grundy[which][st][ed] = ans;
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        memset(grundy, -1, sizeof(grundy));
        int xorSum = 0;
        ans.clear();

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &k[i]);
            for(int j=0; j<k[i]; j++) scanf("%d", &brace[i][j]);
            int inx = getGrundy(i, 0, k[i]);
            xorSum ^= inx;
//            cout << inx << endl;
        }

//        cout << "ANSWER" << endl;

        if(xorSum) {
            for(int which=0; which<n; which++) {

                int flag[100100];
                memset(flag, 0,sizeof(flag));

                for(int mv=0; mv<k[which]; mv++) {

                    if( flag[ brace[which][mv] ] ) continue;

                    int tempXor = 0;
                    int l, r, x;

                    for(x=0; x<k[which]; ) {
                        while(x < k[which] && brace[which][x] >= brace[which][mv]) x++;
                        l = x;
                        while(x < k[which] && brace[which][x] < brace[which][mv]) x++;
                        r = x;
                        if(l < r) tempXor ^= getGrundy(which, l,r);
                    }
                    if( (xorSum ^ getGrundy(which, 0, k[which]) ^ tempXor) == 0 ) {
                        ans.push_back(res(which+1, brace[which][mv]));
                        flag[ brace[which][mv] ] = 1;
//                        tempXor = 1;
//                        ans1.push_back(which);
//                        ans2.push_back(mv);
                    }
//                    cout << mv << ' ' << xorSum << ' ' << getGrundy(which, 0, k[which]) << ' ' << (xorSum ^ getGrundy(which,0,k[which]) ) << ' ' << tempXor << endl;
                }
            }
        }

        if(xorSum) {
            printf("Case %d: Aladdin\n", t);
            sort(ans.begin(), ans.end(), cmp);
            int sz = ans.size();
            printf("(%d %d)", ans[0].which, ans[0].weight);
            for(int i=1; i<sz; i++) {
//                if( (ans[i].which != ans[i-1].which) )
//                    printf(" (%d %d)", ans[i].which, ans[i].weight );
//                else if( ans[i].weight != ans[i-1].weight )
                printf("(%d %d)", ans[i].which, ans[i].weight );
            }
            printf("\n");
        }
        else printf("Case %d: Genie\n", t);
    }
    return 0;
}
