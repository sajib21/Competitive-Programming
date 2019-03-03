#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    scanf("%d %d", &n,&m);
    if(n < m) swap(n,m);

    printf("%d %d\n", n-1, m);

    return 0;

}
