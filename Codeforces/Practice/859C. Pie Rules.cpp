#include<bits/stdc++.h>

using namespace std;



int main() {
    int n, a, u=0,v=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        if(i%2) v += a;
        else u += a;
    }
    cout << u << ' ' << v << endl;
}
