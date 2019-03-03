///je poth e aschi oi poth e ferot jabo.
/// for ex, R U L D korle hoyto R U poth e kono bomb pabe na bt L U poth e thik e bomb pete pare


#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

bool comp(pii p1, pii p2) {

//    if( !p1.second && !p2.second && p1.first <= 0 && p2.first <= 0) return p1.first > p2.first;
//    if( !p1.first && !p2.first && p1.second <= 0 && p2.second <= 0) return p1.first > p2.first;
//
//    if(p1.first <=0 && p2.first <=0) {
//        if(p1.first == p2.first) {
//            return p1.second < p2.second;
//        }
//        else {
//            return p1.first > p2.first;
//        }
//    }

    if(p1.first == p2.first) {
        if(p1.second <= 0 && p2.second <= 0) return p1.second > p2.second;
        else return p1.second < p2.second;
    }
    else {
        if(p1.first <= 0 && p2.first <= 0) return p1.first > p2.first;
        else return p1.first < p2.first;
    }
}

//bool func_name(pair<int, int> p1, pair<int, int> p2)
//{
//       if(p1.second() < p2.second() )return 0;
//       return 1;
//}

int main() {

    int n;
    pii ara[100005];
    scanf("%d", &n);

    int ans = 0;
    for(int i=0; i<n; i++) {
        //int x,y;
        scanf("%d %d", &ara[i].first,&ara[i].second);
        ans += 2;
        if(ara[i].first) ans += 2;
        if(ara[i].second) ans += 2;
        //ans += abs(araX[i])*2 + abs(araY[i])*2 + 2;
    }

    sort(ara, ara+n, comp);

//    for(int i=0; i<n; i++) printf("%d %d\n", ara[i].first, ara[i].second);

    printf("%d\n", ans);

    for(int i=0; i<n; i++) {
        //int dx = abs(araX[i]);
        if(ara[i].first > 0) printf("1 %d R\n", abs(ara[i].first));
        else if(ara[i].first < 0) printf("1 %d L\n", abs(ara[i].first));
        if(ara[i].second > 0) printf("1 %d U\n", abs(ara[i].second));
        else if(ara[i].second < 0) printf("1 %d D\n", abs(ara[i].second));
        printf("2\n");
        if(ara[i].second > 0) printf("1 %d D\n", abs(ara[i].second));
        else if(ara[i].second < 0) printf("1 %d U\n", abs(ara[i].second));
        if(ara[i].first > 0) printf("1 %d L\n", abs(ara[i].first));
        else if(ara[i].first < 0) printf("1 %d R\n", abs(ara[i].first));
        printf("3\n");
    }

    return 0;

}
