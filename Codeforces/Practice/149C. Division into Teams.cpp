#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

bool cmp(pii a, pii b) {

    return a.first > b.first;
}

int main() {

    int n;
    pii ara[100005];

    ara[0].first = ara[0].second = 0;

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i].first);
        ara[i].second = i;
    }

    sort(ara, ara+n+1, cmp);

    //for(int i=0; i<n; i++) printf("%d %d\n", ara[i].first, ara[i].second);

    printf("%d\n%d", (n+1)/2, ara[0].second);
    for(int i=2; i<n; i+=2) printf(" %d", ara[i].second);
    printf("\n");

    printf("%d\n%d", n/2, ara[1].second);
    for(int i=3; i<n; i+=2) printf(" %d", ara[i].second);
    printf("\n");

    return 0;

}
