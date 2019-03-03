#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 200

using namespace std;

vector<int>primes;
int primeFlag[LIM+10], ans[1050][1050];

void sv() {

    for(int i=4; i<=LIM; i+=2) primeFlag[i] = true;
    for(int i=3; i<=20; i+=2) if(!primeFlag[i]) for(int j=2*i; j<=LIM; j+=i) primeFlag[j] = true;
    for(int i=2; i<=LIM; i++) if(!primeFlag[i]) primes.pb(i);
}

void genn(int n) {

    if(n==2) {
        ans[n][0] = 1;
        return;
    }
    genn(n-1);
    int nn = n;

    int sz = primes.size();
    for(int i=0; i<sz; i++) {
        int div = primes[i] , cnt = 0;

        while(n > 1 && n%div==0) {
            n /= div;
            cnt++;
        }
        ans[nn][i] = ans[nn-1][i] + cnt;
    }
}

int main() {

    sv();

    genn(LIM);

//    for(int i=0; i<primes.size(); i++) cout << ' ' << primes[i] ; cout << endl;
//    for(int i=2; i<=20; i++) {
//        for(int j=0; j<primes.size(); j++) {
//            cout << ' ' << ans[i][j] ;
//        }
//        cout << endl;
//    }

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d =", t, n);
        bool flas = false;
        for(int i=0; primes[i] <= n; i++) {
            if(ans[n][i]) {
                if(flas) printf(" *");
                if(!flas) flas = true;
                printf(" %d (%d)", primes[i], ans[n][i]);
            }
        }
        printf("\n");
    }

    return 0;
}
