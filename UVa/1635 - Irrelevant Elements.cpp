#include<bits/stdc++.h>
#define LIM 100000
#define ll long long int
#define pb push_back

using namespace std;

bool isPrime[LIM+100];
vector<int>primes;
int sz;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=3; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
    sz = primes.size();
}

int n,m, mpc[30], npc[30];
vector<int>mp, ans;

int main() {
    genSieve();
    while(scanf("%d %d", &n, &m) != EOF) {
        n--;
        mp.clear();
        ans.clear();
        memset(mpc, 0, sizeof mpc);
        memset(npc, 0, sizeof npc);
        int in = 0;
        for(int i=0; i<sz && primes[i]*primes[i] <= m; i++) {
            int p = primes[i];
            if(m%p) continue;
            mp.pb(p);
            int cnt = 0;
            while(m%p==0) {
                cnt++;
                m /= p;
            }
            mpc[in] += cnt;
            in++;
        }

        if(m > 1) {
            mp.pb(m);
            mpc[in] = 1;
            in++;
        }

//        cout << "DONE " << endl;
        for(int r=1; r<n; r++) {
//            cout << r << endl;
            int num;
            num = (n-r+1);
            for(int i=0; i<mp.size() && num >= mp[i]; i++) {
                while(num%mp[i]==0){
                    npc[i]++;
                    num /= mp[i];
                }
            }
            num = r;
            for(int i=0; i<mp.size() && num >= mp[i]; i++) {
                while(num%mp[i]==0){
                    npc[i]--;
                    num /= mp[i];
                }
            }
            bool f = true;
            for(int i=0; f && i<mp.size(); i++) if(npc[i] < mpc[i]) f = false;
            if(f) ans.pb(r+1);
        }
        printf("%d\n", ans.size());
        for(int i=0; i<ans.size(); i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
