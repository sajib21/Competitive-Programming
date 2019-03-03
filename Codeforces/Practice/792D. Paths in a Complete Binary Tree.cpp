#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int
#define vi vector<ll>
#define pb(x) push_back(x)
#define pp( ) pop_back()

using namespace std;

ll n,x;
int q,sz;
char seq[LIM];

int main() {
    scanf("%lld %d", &n,&q);
    while(q--) {
        scanf("%lld %s", &x, seq);
        sz = strlen(seq);
        vi st,ed;
        ll lo, hi, cur;
        st.pb(1); ed.pb(n);

        while(!st.empty()) {
            ll lo = st.back(), hi = ed.back();
            cur = (lo+hi)/2;
            if(cur == x) break;
            else if(cur < x) {
                st.pb(cur+1); ed.pb(hi);
            }
            else {
                st.pb(lo); ed.pb(cur-1);
            }
        }

        int i = 0;

//        ll lo,hi,cur;

        while(i < sz) {
            lo = st.back(), hi = ed.back();
            cur = (lo+hi)/2;
            if(lo == hi && seq[i] != 'U') {
                i++;
            }
            else if(st.size() == 1 && seq[i] == 'U') {
                i++;
            }
            else if(seq[i] == 'L') {
                st.pb(lo);
                ed.pb(cur-1);
                i++;
            }
            else if(seq[i] == 'R') {
                st.pb(cur+1);
                ed.pb(hi);
                i++;
            }
            else {
                st.pp();
                ed.pp();
                i++;
            }
        }

        lo = st.back(), hi = ed.back();
        cur = (lo+hi)/2;

        printf("%lld\n", cur);
    }
}
