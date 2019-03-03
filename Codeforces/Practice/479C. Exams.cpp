#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

bool compare(const pair<int,int>&i, const pair<int,int>&j){
    if(i.first == j.first) return i.second < j.second;
    return i.first < j.first;
}

int main() {

    int n;
    vector<pii> dates;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a,b;
        scanf("%d %d", &a,&b);
        dates.push_back( mp(a,b) );
    }
    sort(dates.begin(), dates.end(), compare);

//    for(int i=0; i<n; i++) printf("%d %d\n", dates[i].first, dates[i].second);

    int ans = min( dates[0].first, dates[0].second );
    for(int i=1; i<n; i++) {
        if(dates[i].second >= ans) ans = dates[i].second;
        else ans = dates[i].first;
    }

    printf("%d\n", ans);

    return 0;
}
