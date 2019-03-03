#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define ll long long int

using namespace std;

int cont[20] = {0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1};
vii graph[20];
char seq[15];
ll dp[1010][20][2];

int conv(string str) {
    int ans = 0;
    for(int i=0; i<str.size(); i++) {
        ans = ans*10 + (str[i]-'0');
    }
    return ans;
}

void print(vector<int> sol) {
    cout << "SOL " ;
    for(int i=0; i<sol.size(); i++) cout << sol[i] << ' ' ; cout << endl;
}

ll f(int n, int u, int con, vector<int> sol) {
//    cout << n << ' ' << u << ' ' << con << ' ' ; print(sol); getchar();
    if(n == 0) {
        int ret = con && (u == 1 || u == 2);
        if(ret) {
//            print(sol); getchar();
        }
        return ret;
    }
//    if(dp[n][u][con] != -1) return dp[n][u][con];
    ll ans = 0;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        sol.pb(v);
        ans += f(n-1, v, con | cont[v], sol );
        sol.pop_back();
    }
    return dp[n][u][con] = ans;
}

int main() {
    graph[3].pb(5);
    graph[4].pb(2); graph[4].pb(3); graph[4].pb(8); graph[4].pb(10); graph[4].pb(12);
    graph[5].pb(2); graph[5].pb(3); graph[5].pb(10); graph[5].pb(12);
    graph[6].pb(7); graph[6].pb(9); //graph[6].pb(14); graph[6].pb(15);
    graph[7].pb(2); graph[7].pb(3); graph[7].pb(8);
    graph[8].pb(1); graph[8].pb(9); graph[8].pb(10); graph[8].pb(12); graph[8].pb(14); graph[8].pb(15);
    graph[9].pb(1); graph[9].pb(7); graph[9].pb(9);

    graph[10].pb(11);
    graph[11].pb(2); graph[11].pb(3); graph[11].pb(8);
    graph[12].pb(13);
    graph[13].pb(2); graph[13].pb(3); graph[13].pb(8);

    graph[14].pb(13); graph[14].pb(17);
    graph[15].pb(11); graph[15].pb(16);
    /* graph[16].pb(1); */ graph[16].pb(7); graph[16].pb(9);
    /* graph[17].pb(1); */ graph[17].pb(7); graph[17].pb(9);


    memset(dp, -1, sizeof dp);
    int t=1;
    while(scanf("%s", seq)) {
        if(!strcmp("#", seq)) return 0;
        int n = conv(seq);
//        cout << n << endl;
        vector<int>sol4, sol6;
        sol4.pb(4); sol6.pb(6);
        printf("%d: %d\n", t++, 2* (f(n-1, 4, 1, sol4)+f(n-1, 6, 0, sol6)) );
    }
}
