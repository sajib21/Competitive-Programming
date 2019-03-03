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

int n,k,x, p,q;
double A, B;

double getExp(int in, double perm) {
//    cout << in << ' ' << perm << endl;
//    getchar();
    if(in == k) {
        if(!in) return ( perm*(A+B) - in*perm/q * B ) / (n-q);
        return ( perm*(A+B) - in*perm/q * B ) / (n-q);
    }
    if(!in) return ( perm*(A+B) - in*perm/q * B + getExp(in+1, perm*(q-in)) ) / (n-in);
    return ( perm*(A+B - B*in/q ) + (q-in)*getExp(in+1, perm*(q-in)) ) / (n-in);
}

int main() {

//    freopen("1395i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        A = B = 0;
        p = q = 0;
        scanf("%d %d", &n,&k);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            if(x > 0) A += x , p++;
            else B -= x , q++;
        }
//        cout << "BUG" << endl;
        if(!p) printf("Case %d: -1\n", t);
        if(!q) printf("Case %d: %.10lf\n", t, A/p);
        else printf("Case %d: %.10lf\n", t, getExp(0, 1));
    }

    return 0;
}
