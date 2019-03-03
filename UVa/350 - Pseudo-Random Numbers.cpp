#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    int z,i,m,l;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        scanf("%d %d %d %d", &z, &i, &m, &l);
        if(!z && !i && !m && !l) return 0;
        int cur, p1, p2;
        cur = p1 = p2 = l;

//        while(true) {
//            cout << p1 << endl;
//            p1 = (z*p1 + i+ m) % m;
//            getchar();
//        }

        do{
            p1 = (z*p1 + i + m) % m;
            p2 = (z*p2 + i + m) % m;
            p2 = (z*p2 + i + m) % m;
//            cout << p1 << ' ' << p2 << endl;
        }while(p1 != p2);

        p1 = cur;
        while(p1 != p2) {
            p1 = (z*p1 + i + m) % m;
            p2 = (z*p2 + i + m) % m;
        }
        cur = p1;
        int cnt = 0;
        do{
            p1 = (z*p1 + i + m) % m;
            cnt++;
        }while(p1 != cur);
        printf("Case %d: %d\n",t, cnt);
    }

    return 0;
}

