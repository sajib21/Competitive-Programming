#include<bits/stdc++.h>
#define LIM 200
#define pb push_back

using namespace std;

string str;
vector<int>ans;
int sz, grundy[5][LIM][5];

int getGrundy(int leftX, int dot, int rightX) {

    if(grundy[leftX][dot][rightX] != -1) return grundy[leftX][dot][rightX];

    set<int>st;

    int x, y;
    if(leftX) x = 2;
    else x = 0;
    if(rightX) y = 2;
    else y = 0;

    for( ; x<dot; x++) {
        if(dot - x - 1 >= y) {
            int in = getGrundy(leftX,x,1) ^ getGrundy(1,dot-x-1,rightX);
            st.insert(in);
        }
    }
    int ans = 0;
    while(st.find(ans) != st.end()) ans++;
    grundy[leftX][dot][rightX] = ans;

    return ans;
}

int main() {



    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        memset(grundy, -1, sizeof(grundy));
        ans.clear();

        cin >> str;
        int sz = str.size();
        int xorSum = 0;
        int cnta, cntb=0;

        for(int i=2; i<sz; i++) {
            if(str[i-2] == 'X' && str[i-1] == '.' && str[i] == 'X') ans.pb(i-1);
            else if(str[i-2] == '.' && str[i-1] == 'X' && str[i] == 'X') ans.pb(i-2);
            else if(str[i-2] == 'X' && str[i-1] == 'X' && str[i] == '.') ans.pb(i);
        }
        if(!ans.empty()) {
            xorSum = 1;
            goto here;
        }

        while(str[cntb] == 'X') cntb++;

        for(int i=cntb; i<sz; ) {
            int cntd = 0;
            cnta = cntb;
            cntb = 0;
            while(i<sz && str[i] == '.') i++, cntd++;
            while(i<sz && str[i] == 'X') i++, cntb++;

            int ans = getGrundy(cnta, cntd, cntb);
            xorSum ^= ans;
        }

        if(xorSum) {

            int leftX, rightX=0, in = 0;
            while(str[rightX] == 'X') rightX++;
            in += rightX;

            for(int i=rightX; i<sz; ) {
                int dot = 0;
                leftX = rightX;
                rightX = 0;
                while(i<sz && str[i] == '.') i++, dot++;
                while(i<sz && str[i] == 'X') i++, rightX++;

                int x, y;
                if(leftX) x = 2;
                else x = 0;
                if(rightX) y = 2;
                else y = 0;

                for( ; x<dot; x++) {
                    if(dot - x - 1 >= y) {
                        int inx = getGrundy(leftX,x,1) ^ getGrundy(1,dot-x-1,rightX);
                        if(inx == (xorSum ^ grundy[leftX][dot][rightX]) ) {
                            ans.pb(in+x);
                        }
                    }
                }
                in += (dot+rightX);
            }
        }

        here :

        if(xorSum) {
            sort(ans.begin(), ans.end());
            int sz = ans.size();
            printf("Case %d: %d", t, ans[0]+1);
            for(int i=1; i<sz; i++) if(ans[i] != ans[i-1]) printf(" %d", ans[i]+1); printf("\n");
        }
        else printf("Case %d: 0\n", t);
    }

    return 0;
}
