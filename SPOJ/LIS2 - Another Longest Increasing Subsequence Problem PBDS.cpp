#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define LIM 100005
#define MX 100000
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;
using namespace __gnu_pbds;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set X[10];

ordered_set segTree[4*LIM];

int query(int node, int st, int ed, int p, int v) {
    if(st > p) return 0;
    if(ed <= p) return segTree[node].
}

int main() {

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x[i],&y[i]);
        temp.pb(x[i]);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    int t = 1;
    map<int,int>mp;
    for(int i=0; i<temp.size(); i++) mp[ temp[i] ] = t++;
    for(int i=0; i<n; i++) x[i] = mp[ x[i] ];

    int ans = 0;
    for(int i=0; i<n; i++) {

        ans = max(ans, query(1, 1,MX, x[i], y[i]) );
    }



    X[0].insert(10);
    X[0].erase(10);
//    cout << (X.find(10) != X.end()) << endl;
//
//
//    X.insert(1);
//    X.insert(2);
//    X.insert(4);
//    X.insert(8);
//    X.insert(16);
//    cout<<*X.find_by_order(1)<<endl; // 2
//    cout<<*X.find_by_order(2)<<endl; // 4
//    cout<<*X.find_by_order(4)<<endl; // 16
//    cout<<(X.end()==X.find_by_order(6))<<endl; // true
//
//    cout<<X.order_of_key(-5)<<endl;  // 0
//    cout<<X.order_of_key(1)<<endl;   // 0
//    cout<<X.order_of_key(3)<<endl;   // 2
//    cout<<X.order_of_key(4)<<endl;   // 2
//    cout<<X.order_of_key(400)<<endl; // 5
//    cout << X.order_of_key(16) << endl;
//
//    X.erase(*X.find_by_order(1));           // erases the 2nd element

    return 0;
}
