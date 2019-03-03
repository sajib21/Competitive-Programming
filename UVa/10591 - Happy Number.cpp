#include<bits/stdc++.h>

using namespace std;

int happy[800] = {-1, 1, -1, -1, -1, -1, -1, 1, -1,-1, 1, -1, -1, 1, 0};

int checkHappy(int n) {

    if(happy[n] != 0) return happy[n];

    int DSsum=0, nn=n;
    while(nn) {
        DSsum += (nn%10)*(nn%10);
        nn /= 10;
    }

    return happy[n] = checkHappy(DSsum);
    //else return happy[DS]
}

void happyGen() {

    for(int i=1; i<800; i++) {
        checkHappy(i);
    }

}

int main() {

    int t,T;
    scanf("%d", &T);

    happyGen();

    for(t=1; t<=T; t++) {

        int n;
        scanf("%d", &n);

        int DSsum=0, nn=n;
        while(nn) {
            DSsum += (nn%10)*(nn%10);
            nn /= 10;
        }


        if(checkHappy(DSsum) == 1) printf("Case #%d: %d is a Happy number.\n", t, n);
        else printf("Case #%d: %d is an Unhappy number.\n", t,n);
    }

    return 0;
}
