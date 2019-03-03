#include<bits/stdc++.h>
#define ll long long int
#define LIM 256
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define pii pair<ll,int>
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;


typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//ordered_set X[10];

int n,m, a[LIM][LIM], A,B;
ll sum[LIM][LIM];

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%lld", &a[i][j]);

    scanf("%d %d", &A, &B);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            sum[i][j] = a[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++) {
        for(int k=1; k<=i; k++) {
            ordered_set ase;
//            ase.insert(pii(0,0));
            for(int j=1; j<=m; j++) {
                ase.insert(pii(sum[i][j-1]-sum[k-1][j-1], j));
                int temp = ase.order_of_key(pii(sum[i][j]-sum[k-1][j]-A, INT_MAX)) - ase.order_of_key(pii(sum[i][j]-sum[k-1][j]-B, INT_MIN) );
                ans += temp;
//                cout << "IN " << i << ' ' << j << ' ' << k << ' ' << temp << " : " << sum[i][j]-A << ' ' << ase.order_of_key(pii(sum[i][j]-A, INT_MAX)) << ' ' << ase.order_of_key(pii(sum[i][j]-B, INT_MIN) ) << endl;
//                for(auto it : ase) cout << it.ff << ' '; cout << endl;

            }
        }
    }

    cout << ans << endl;
}
