#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 200000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
//#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int n, cnt;
string a,b;
map<string, int>mp;
int par[LIM+10];
int net[LIM+10];

int findPar(int x) {
    if(par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

int main() {

//    freopen("11503i.txt", "r", stdin);
//    freopen("11503o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        mp.clear();
        scanf("%d", &n);
        cnt = 0;
        for(int i=1; i<=2*n; i++) par[i] = i;
        for(int i=1; i<=2*n; i++) net[i] = 1;

        for(int i=0; i<n; i++) {
            cin >> a >> b;
            int x,y;
            if(!mp[a]) mp[a] = ++cnt;
            if(!mp[b]) mp[b] = ++cnt;
            x = mp[a] , y = mp[b];



            int px = findPar(x) , py = findPar(y);

            if(px == py) {
                printf("%d\n", net[px]);
                continue;
            }
//            cout << px << ' ' << py << ' ' << net[px] << ' ' << net[py] << endl;
            if(net[px] > net[py]) {
                net[px] += net[py]; par[py] = px;
                printf("%d\n", net[px]);
            }
            else {
                net[py] += net[px];
                par[px] = py;
                printf("%d\n", net[py]);
            }
        }
    }

    return 0;
}
