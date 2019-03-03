#include<bits/stdc++.h>

using namespace std;

struct car {

    int price, cap;
};

bool cmp(car a, car b) {
    return a.cap < b.cap;
}
car cars[200005];
int n,k,s,t, station[200005], maxDist = 0;

int go(int in) {

    if(cap < maxDist) return 0;

    int tmp = 0;
    for(int i=1; i<=k; i++) {
        tmp += min(station[i]-station[i-1], cap - (station[i]-station[i-1]) );
    }
    return tmp;
}

int main() {



    scanf("%d %d %d %d", &n, &k, &s, &t);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &cars[i].price, &cars[i].cap);
    }
    sort(cars, cars+n, cmp);
//    for(int i=0; i<n; i++) cout << cars[i].price << endl;

    station[0] = 0;
    for(int i=1; i<=k; i++) scanf("%d", &station[i]);
    sort(station, station+k+1);

    for(int i=1; i<=k; i++) maxDist = max(maxDist, station[i] - station[i-1]);



//    cout << "boro is " << maxDist << endl;

    int rem = 0;
    if(s*2 > t) rem = s*2 - t;

    int i=0, j = n-1;

    int strt = j, mid;

    while(i < j) {

        mid = (i+j)/2;
        int temp = go(mid);
        if(cars[mid].cap == maxDist) {
            if(mid < strt) strt = mid;
            j = mid-1;
        }
        else if(cars[mid].cap < maxDist) {
            i = mid+1;
        }
        else {
//            strt = mid;
            j = mid+1;
        }
    }
    if( (cars[strt].cap == maxDist)) {
        if(cars[mid].cap == maxDist && mid < strt) strt = mid;
    }
    else {
        if()
    }




    for(int i=0; i<n; i++) {
        if(cars[i].cap >= maxDist+rem) {
            printf("%d\n", cars[i].price);
            return 0;
        }
    }

    printf("-1");
    return 0;


}
