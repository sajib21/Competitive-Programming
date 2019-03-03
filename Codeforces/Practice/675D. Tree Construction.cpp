#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n,x, a[LIM];
set<int>ase;
map<int,int>par, lft, rgt;

int main() {
    scanf("%d", &n);

    scanf("%d", &a[0]);
    ase.insert(a[0]);

    for(int i=1; i<n; i++) {
        scanf("%d", &x);
        a[i] = x;
        set<int>::iterator it = ase.lower_bound(x);

        if(it == ase.end()) {
            it--;
            int p = *it;
            rgt[p] = x;
            par[x] = p;
        }

        else {
            int p = *it;
            if(lft.find(p) == lft.end()) {
                lft[p] = x;
                par[x] = p;
            }
            else {
                it--;
                p = *it;
                rgt[p] = x;
                par[x] = p;
            }
        }

        ase.insert(x);
    }


    for(int i=1; i<n; i++) printf("%d ", par[ a[i] ]);

}
