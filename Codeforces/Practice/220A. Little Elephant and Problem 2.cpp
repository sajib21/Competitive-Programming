#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, t;
    scanf("%d", &n);
    int ara1[100005], ara2[100005];
    for(int i=0; i<n; i++) {
        scanf("%d", &t);
        ara1[i] = ara2[i] = t;
    }

    sort(ara2, ara2+n);
    int c = 0;
    for(int i=0; c<=2 && i<n; i++) {
        if(ara1[i] != ara2[i]) c++;
    }

    if(c <= 2) printf("YES\n");
    else printf("NO\n");

    return 0;
}
