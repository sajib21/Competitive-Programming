#include<bits/stdc++.h>
#define LIM     10004
#define vi      vector<int>
#define pb(x)   push_back(x)

using namespace std;

int n, x[LIM], y[LIM];
char fin[300];
string str;
vi nxt[300];

char f(char u, int in) {
//    cout << "IN " << u << ' ' << in << endl; getchar();
    if(in > n) return fin[u] = u;
//    if(fin[u] != -1) return fin[u];
    char ans = u;

    while(in <= n && x[in] != u) in++;
    if(in <= n) {
        in++;
        ans = f(y[in-1], in);
    }

//    cout << "IN " << u << ' ' << in << ' ' << ans << endl; getchar();
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(fin, -1, sizeof fin);
        for(int i='A'; i<='Z'; i++) nxt[i].clear();

        cin >> str;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            getchar();
            scanf("%c %c", &y[i], &x[i]);
            nxt[ x[i] ].pb(y[i]);
        }

//        cout << "GO " << endl;
//        for(char i='A'; i<='Z'; i++) cout << "FIN " << i << ' ' << f(i, 1) << endl;
        for(char i='A'; i<='Z'; i++) {
            fin[i] = f(i,1);
//            cout << "FIN " << i << ' ' << fin[i] << endl;
        }
//        for(char i='A'; i<='Z'; i++) cout << i << ' ' << fin[i] << endl;

        for(int i=0; i<str.size(); i++) {
//            cout << str[i] << ' ' << fin[ str[i] ] << endl;
            printf("%c", fin[ str[i] ]);
        }
        printf("\n");
    }
}
