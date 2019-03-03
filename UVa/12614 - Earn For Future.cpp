#include<bits/stdc++.h>
#define vi vector<int>
#define SZ 32
#define vb vector< bitset<SZ> >
#define pb(x) push_back(x)

using namespace std;

int n,x;

void printinfo(vb rem) {
    for(int i=0; i<rem.size(); i++) cout << rem[i] << endl;
}

int f(int in, vb rem, int cur) {
//    cout << in << ' ' << cur << endl;
//    printinfo(rem);
//    getchar();

    if(in < 0) return cur;
    bool g = false;
    vb temp;
    for(int i=0; i<rem.size(); i++) {
        if(rem[i][in]) {
            g = true;
            temp.pb(rem[i]);
        }
    }
    if(g) return f(in-1, temp, cur*2+1);
    else  return f(in-1, rem,  cur*2);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        vb rem; bitset<SZ> temp;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            temp = x;
            rem.pb(temp);
        }

//        for(int i=0; i<rem.size(); i++) cout <<rem[i] << endl;

        int ans = f(SZ-1, rem, 0);
        printf("Case %d: %d\n", t, ans);
    }
}
