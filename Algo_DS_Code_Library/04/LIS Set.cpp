#include<bits/stdc++.h>
#define LIM 100005
#define MAX 100000

using namespace std;

int n, a[LIM];
set<int>L;

int LIS() {
    L.clear();

    for(int i=1; i<=n; i++) {
        set<int>::iterator it = L.lower_bound(a[i]);
        if(it != L.end()) L.erase(it);
        L.insert(a[i]);

    }
    return L.size();
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    cout << LIS() << endl;
}
