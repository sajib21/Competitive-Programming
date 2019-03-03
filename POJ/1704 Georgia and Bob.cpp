#include<iostream>
#include<stdio.h>
#include<algorithm>
#define LIM 10000

using namespace std;

int n, ara[LIM+100];

int main() {

    int t;
    cin >> t;

    while(t--) {

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }
        sort(ara, ara+n);

//        int i=1;

//        if(ara[i-1] == 1) while(ara[i] == ara[i-1]+1) i++;

        int i = 1, xorSum = 0;
        for(i=n-1; i>0; i-=2) {
            xorSum ^= ara[i]-ara[i-1] - 1;
//            cout << ara[i] - 1 - i << endl;
        }
        if(!i) xorSum ^= ara[i] - 1;

        if(xorSum) printf("Georgia will win\n");
        else printf("Bob will win\n");
    }

    return 0;
}



