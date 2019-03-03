#include<bits/stdc++.h>
#define LIM 100000
using namespace std;

int k;
double prob[LIM+10];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%d", &k);
        prob[1] = 1;
        int i;
        for(i=2; i<k && prob[i-1] >= 0.5 ; i++) prob[i] = prob[i-1] * (k-(i-1)) / k;
            ///THERES NO NEED TO CALCULATE AFTER 0.5. SO IT DECREASES TEH O(N) LOOP IN AROUND SQRT(N) TO LOG(N)
            ///OTHERWISE TLE

        int lo = 0, hi = i;

        while(lo < hi) {

            int md = (lo+hi)/2;

            if(prob[md] >= .5) {
                lo = md;
            }
            else if(prob[md] < .5) {
                hi = md;
            }


            if(lo + 1 == hi) break;
        }
        printf("Case %d: %d\n", t, lo);

    }
    return 0;
}
