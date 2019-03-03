#include<bits/stdc++.h>
#define LIM 100000
#define vii vector<int>
#define pb push_back

using namespace std;

int n, pcnt[LIM+100];
char seq[LIM+100];
vii pac;
int md;
bool iff = false;

bool f(int in) {
    if(in >= n) return true;
    if(seq[in] == '.') return f(in+1);
    int nxt = lower_bound(pac.begin(), pac.end(), in) - pac.begin();

    if(nxt == pac.size()) return false;
    int dist = pac[nxt]-in;
    if(dist > md) return false;
    int af = pac[nxt] + max( max(md-2*dist, 0) , (md-dist)/2 ) + 1;
    if(nxt == pac.size() - 1) return f(af);
    return f( min(af, pac[nxt+1]) );
}

int main() {
    scanf("%d", &n);
    scanf("%s", seq);
    for(int i=0; i<n; i++) if(seq[i] == 'P') pac.pb(i);

    int lo = 1, hi = 2*LIM+1;
    while(lo < hi) {
        md = (lo+hi) / 2;
        if(f(0)) hi = md;
        else lo = md+1;
    }
    printf("%d\n", hi);
    return 0;
}
