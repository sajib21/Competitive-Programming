#include<bits/stdc++.h>

using namespace std;

char num[1000006];
int cnt[12];
int mejhikmamoni[] = {1869, 1968, 1689, 6198, 1698, 1986, 1896};


/*
0 1869
1 1968
2 1689
3 6198
4 1698
5 1986
6 1896

*/

int main() {
//    cout << 2255781698 % 7 << endl;
//    cout << 1111111112222222233333333334444444455555555556666677777777777788888888899999999999189600000000000000 % 7 << endl;
    scanf("%s", num);
    int n = strlen(num);

    for(int i=0; i<n; i++) {
        cnt[ num[i]-'0' ]++;
    }
    cnt[1]--; cnt[6]--; cnt[8]--; cnt[9]--;

    int mod = 0;

    bool ff = false;
    for(int i=1; i<10; i++) {
        for(int j=0; j<cnt[i]; j++) {
            mod = (mod*10 + i) % 7;
            printf("%d", i);
            ff = true;
        }
    }


    if(!ff) {
        printf("1869");
        for(int i=0; i<cnt[0]; i++) printf("0");
        return 0;
    }

    for(int j=0; j<cnt[0]; j++) {
        mod = (mod*10) % 7;
        printf("0");
    }
    for(int j=0; j<4; j++) {
        mod = (mod*10) % 7;
    }

//    cout << "PRE " << mod << endl;

    printf("%d", mejhikmamoni[ (7-mod)%7 ] );

//    for(int j=0; j<cnt[0]; j++) printf("0");

}
