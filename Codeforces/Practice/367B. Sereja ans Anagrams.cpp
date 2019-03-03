#include<bits/stdc++.h>
#define LIM 200005

using namespace std;

int n,m,p, a[LIM], b[LIM];
map<int,int>goal, cur;

int main() {
    scanf("%d %d %d", &n, &m, &p);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);

    for(int i=0; i<m; i++) goal[ b[i] ]++;

    for(int i=0; i<min(n,p); i++) {
        for(int j=0; ; j+=p) {

        }
    }
}
