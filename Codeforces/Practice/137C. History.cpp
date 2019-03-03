#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

bool comp(pii a, pii b) {

    return a.second > b.second;
}

int main() {

    int n;
    scanf("%d", &n);
    pii tim[100005];
    for(int i=0; i<n; i++) {
        scanf("%d %d", &tim[i].first, &tim[i].second);
    }

    sort(tim, tim+n, comp);

    int cnt = 0;
    int l = tim[0].first, r = tim[0].second;

    for(int i=1; i<n; i++) {
        if(tim[i].first > l) cnt++;
        else l = tim[i].first;
    }

    printf("%d\n", cnt);

    return 0;
}
