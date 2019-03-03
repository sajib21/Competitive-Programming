#include<bits/stdc++.h>
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2
#define ll long long int

using namespace std;

string game;
int sz;
int grundy[4][110][4];

int getGrundy(int left, int dot, int right) {

//    cout << left << ' ' << dot << ' ' << right << endl;

    if(!dot) return 0;
    if( (left == right && left != '.') && dot == 1) return 1;
    if(dot == 1 && (!left || !right) ) return 1;
    if(grundy[left][dot][right] != -1) return grundy[left][dot][right];

    set<int>st;

    if(left != CIRCLE) st.insert( getGrundy(CIRCLE, dot-1, right) );
    if(left != CROSS) st.insert( getGrundy(CROSS, dot-1, right) );

    for(int i=1; i<=dot-2; i++) { ///I DONT KNOW WHY i <= (dot-1)/2 DIDNT WORK!!
        st.insert( getGrundy(left, i, CIRCLE) ^ getGrundy(CIRCLE, dot-i-1, right) );
        st.insert( getGrundy(left, i, CROSS) ^ getGrundy(CROSS, dot-i-1, right) );
    }

    if(right != CIRCLE) st.insert( getGrundy(left, dot-1, CIRCLE) );
    if(right != CROSS) st.insert( getGrundy(left, dot-1, CROSS) );

    int ans = 0;
    while(st.find(ans) != st.end()) ans++;
//    cout << ans << endl;
    return grundy[left][dot][right] = ans;
}

int main() {

    memset(grundy, -1, sizeof(grundy));
    grundy[CIRCLE][1][CROSS] = grundy[CROSS][1][CIRCLE] = 0;

    getGrundy(0, 100, 0);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        cin >> game;
        int pre = 0; bool play = true;
        sz = game.size();
        for(int i=0; i<sz; i++) if(game[i] != '.') pre++;

        int i=0, cl=0, cd=0, cr=0, cnt;
        if(game[i] == 'O') cr = CIRCLE, i++;
        else if(game[i] == 'X') cr = CROSS, i++;

        ll xorSum = 0;

        for( ; i<sz; i++) {

//            cout << "BUG" << endl;

            cl = cr;
            cnt = 0;
            while(game[i] == '.' && i<sz) i++, cnt++;
            if(i<sz) {
                if(game[i] == 'O') cr = CIRCLE;
                else cr = CROSS;

//                cout << "IF " << cl << ' ' << cnt << ' ' << cr << endl;
                xorSum ^= getGrundy(cl, cnt, cr);
            }
            else {
                cr = EMPTY;
//                cout << "ELSE " << cl << ' ' << cnt << ' ' << cr << endl;
                xorSum ^= getGrundy(cl, cnt, cr);
            }
        }

        if(xorSum) {
            if(pre%2==0) printf("Case %d: Yes\n", t);
            else printf("Case %d: No\n", t);
        }
        else {
            if(pre%2==0) printf("Case %d: No\n", t);
            else printf("Case %d: Yes\n", t);
        }
    }

    return 0;

}
