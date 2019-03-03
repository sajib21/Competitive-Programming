///HEADERS
#include    <bits/stdtr1c++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int k;
    char str[2000], prop[30];
    string pat;
    scanf("%s", str);
    pat = str;
    pat = "0"+pat;
    scanf("%s", prop);
    scanf("%d", &k);

    int sz = pat.size();

    int bad[2000]; bad[0] = 0;
    for(int i=1; i<sz; i++) {
        if(prop[ pat[i]-'a' ] == '0') bad[i] = 1;
    }
    for(int i=1; i<sz; i++) bad[i] += bad[i-1];

//    for(int i=0; i<sz; i++) cout << bad[i] << ' ' ; cout << endl;

    ull p1=117,p2=31, hash1[2000],hash2[2000];
    hash1[0] = hash2[0] = 0;
    for(int i=1; i<sz; i++) {
        hash1[i] = hash1[i-1]*p1 + pat[i]-'a'+1;
//        hash2[i] = hash2[i-1]*p2 + pat[i]-'a'+1;
//        cout << hash1[i] << ' ' ;
    }
//    cout << endl;

    ull ex1[2000], ex2[2000];
    ex1[0] = ex2[0] = 1;
    for(int i=1; i<sz; i++) {
        ex1[i] = ex1[i-1]*p1;
//        ex2[i] = ex2[i-1]*p2;
//        cout << ex1[i] << ' ' ;
    }
//    cout << endl;

    tr1::unordered_map<ll,bool>mp1,mp2;

    int ans = 0;
    for(int i=0; i<sz; i++) {
        for(int j=i+1; j<sz; j++) {
            ll h1 = hash1[j] - hash1[i]*ex1[j-i];
//            ull h2 = hash2[j] - hash2[i]*ex2[j-i];

//            cout << "CHECKING " << i+1 << ' ' << j << ' ' << ' ' << h1 << ' ' << h2 << ' ' << bad[j]-bad[i] << endl; getchar();

            if(bad[j]-bad[i] > k) break;
            else if(!mp1[h1] ) {
//                cout << "INS " << i+1 << ' ' << j << ' ' <<  endl;
//                cout << "INSERTED " << endl; getchar();
                mp1[h1] = 1;
//                mp2[h2] = 1;
                ans++;
            }
//            else break;
        }
    }
    printf("%d\n", ans);

    return 0;
}
