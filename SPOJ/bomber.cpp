#include<bits/stdc++.h>
using namespace std;

int grundy[110][110];
int st[100000];

int getGrundy(int n, int m) {
//    cout << "IN " << n << ' ' << m << endl;
    if(!n || !m) return 0;
    if(n ==1 && m==1) return 1;
    if(grundy[n][m] != -1) return grundy[n][m];
//    set<int>st;
    vector<int>st;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=m; j++) {
            int g = getGrundy(i-1 , j-1) ^ getGrundy(i-1 , m-j) ^ getGrundy(n-i , j-1) ^ getGrundy(n-i , m-j);
//            cout << n << ' ' << m << ' ' << g << endl;
//                st[g] = 1;
            st.push_back(g);
//            st.insert(g);
        }
    }
    sort(st.begin(), st.end());

    int i, sz = st.size() , j;
    for(i=0, j=0; j < sz; i++, j++) {
        while(st[j+1] == st[j]) j++;
        if(st[j] != i) {
            break;
        }
    }

//    int ans = 1;
//    while(st[ans]) ans++;
//    while(st.find(ans) != st.end()) ans++;
//    cout << "FINAL " << n << ' ' << m << ' ' << ans << endl;

    return grundy[n][m] = i;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(grundy, -1, sizeof(grundy));
    grundy[1][1] = 1;

    getGrundy(100,100);

//    for(int i=1; i<=10; i++) {
//        for(int j=1; j<=10; j++) {
//            if(grundy[i][j]) cout << "GAME "<< i << ' ' << j << " : " << "W" << endl;
//            else cout << "GAME "<< i << ' ' << j << " : " << "L" << endl;
//        }
//    }


    int t;
    cin >> t;
    while(t--) {
        int n,m;
        scanf("%d %d", &n,&m);
        if( grundy[n][m] ) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
