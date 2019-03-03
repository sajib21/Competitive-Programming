#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set X;

int n,m, x;
char cmd[10];

int f(int x) {
    int lo=0, hi = 1e9;
    while(lo < hi) {
        int md = (lo+hi)/2;
        int in = X.order_of_key(md+1);
        if(md-in >= x) hi = md;
        else lo = md+1;
    }
    return hi;
}

int main() {
    scanf("%d %d", &n, &m);

//    X.insert(-1);
    while(m--) {
        scanf("%s %d", cmd, &x);
        int in = f(x);
//        cout << "IN " << in << endl;
        if(cmd[0] == 'L') {
            printf("%d\n", in);
        }
        else {
            X.insert( in );
        }
    }

}
