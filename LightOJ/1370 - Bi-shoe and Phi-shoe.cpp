#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 1000003
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int phi[MAX+100], phiNum[MAX+1000];
void totient(){
    long long i,j;
//    phi[1] = 1;
    for( i=2;i<=MAX;i++){
        if( phi[i]==0){
            phi[i] = i-1;
            for( j = i*2; j<=MAX; j+=i){
                if( phi[j] == 0 )phi[j] = j;
                phi[j] /= i ;
                phi[j] *= (i-1) ;
            }
        }
    }
    for(int i=1; i<=MAX; i++) if(!phiNum[ phi[i] ]) phiNum[ phi[i] ] = i;
    int nsi=MAX;
    for(int i=MAX-1; i>0; i--) {
        if(!phiNum[i]) phiNum[i] = nsi;
        else phiNum[i] = min(phiNum[i], nsi);
        nsi = min(nsi, phiNum[i]);
    }
}

int n,x;
ll ans;

int main() {
    totient();

//    for(int i=990; i<=1010; i++) cout << i << " PHI " << phi[i] << " PHINUM " << phiNum[i] << endl;
//    cout << phi[MAX] << ' ' << phiNum[MAX] << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        ans = 0;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            ans += phiNum[x];
//            cout << "COUNTING " << phiNum[x] << endl;
        }
        printf("Case %d: %lld Xukha\n", t, ans);
    }
    return 0;
}
