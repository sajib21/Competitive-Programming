#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, q, t, a , k;
    vector<int> stk, keep;

    n = 1;
    stk.push_back(0);
    keep.push_back(0);
    double curAvg = 0;

    scanf("%d", &q);

    for(int i=0; i<q; i++) {

        scanf("%d", &t);

        if(t == 1) {
            scanf("%d %d", &a, &k);
            curAvg = curAvg + 1.0*a*k/n;
//            for(int j=0; j<a; j++) stk[j] += k;
            keep[a-1] += k;
            printf("%.8lf\n", curAvg);

//            for(int x=0; x<stk.size(); x++) cout << stk[x] << ' ';
//            cout << endl;
        }
        else if(t == 2) {
            scanf("%d", &k);
            curAvg = curAvg*n/(n+1) + 1.0*k/(n+1);
            stk.push_back(k);
            keep.push_back(0);
            n++;

            printf("%.8lf\n", curAvg);
        }
        else {
            //cout << stk.back() << ' ' << keep.back() << endl;
            curAvg = curAvg*n/(n-1) - 1.0*(stk.back() + keep.back())/(n-1);
            stk.pop_back();
            keep[n-2] += keep[n-1];
            keep.pop_back();
            n--;
            printf("%.8lf\n", curAvg);
        }
    }

    return 0;
}
