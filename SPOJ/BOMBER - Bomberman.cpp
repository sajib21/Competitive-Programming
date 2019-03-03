#include<bits/stdc++.h>
#define pb push_back
#define ll long long int

using namespace std;

int grundy[102][102];

//ll cnt = 1;
//ll mx = 0;


int getGrundy(int n, int m) {
//    cout << "IN " << n << ' ' << m << endl;
//    cnt++;
    if(!n || !m) return 0;
//    if(n ==1 && m==1) return 1;
    if(grundy[n][m] != -1) return grundy[n][m];
//    cnt++;
//    set<int>st;
//    vector<int>st;
    int flag[103] = {0};

    int limN = (n+1)/2 , limM = (m+1)/2;
    for(int i=1; i<=limN; i++) {
        for(int j=1; j<=limM; j++) {
            int g = getGrundy(i-1 , j-1) ^ getGrundy(i-1 , m-j) ^ getGrundy(n-i , j-1) ^ getGrundy(n-i , m-j);
//            cout << n << ' ' << m << ' ' << g << endl;
//                st[g] = 1;
//            st.pb(g);
//            cout << g << ' ';
//            mx = max(mx, (ll)g);
            g = min(100, g);
            flag[g] = 1;
//            st.insert(g);
        }
    }
//    sort(st.begin(), st.end());

//    int i, sz = st.size() , j;
//    for(i=0, j=0; j < sz; i++, j++) {
//        while(st[j+1] == st[j]) j++;
//        if(st[j] != i) {
//            break;
//        }
//    }

    int ans = 0;
    while(flag[ans] && ans < 101) ans++;
//    while(st.find(ans) != st.end()) ans++;
//    cout << "FINAL " << n << ' ' << m << ' ' << ans << endl;

//    return grundy[n][m] = i;
    return grundy[n][m] = ans;
}
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    memset(grundy, -1, sizeof(grundy));
    grundy[0][1] = grundy[1][0] = 0;
    grundy[1][1] = 1;

    getGrundy(100,100);
    cout << mx << endl;
//
//    cout << cnt << " BAR DHUKSE " << endl;

//    return 0;

    int t;
//    cin >> t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n,&m);
        if( grundy[n][m] ) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
