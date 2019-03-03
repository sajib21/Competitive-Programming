#include<bits/stdc++.h>
#define IM 1000000
#define ll long long int

using namespace std;

string pola, maiya;
int polaLen, maiyaLen;
int len;
ll ways;

ll dpLen[33][33];
ll dpWays[33][33][63];

int getMaxLen(int konPola, int konMaiya) {

    if(konPola == polaLen && konMaiya == maiyaLen) return 0;
    if(konPola > polaLen || konMaiya > maiyaLen) return IM;

    if(dpLen[konPola][konMaiya] != -1) return dpLen[konPola][konMaiya];

    int temp;

    if(pola[konPola] == maiya[konMaiya]) temp = getMaxLen(konPola+1, konMaiya+1);
    else temp = min( getMaxLen(konPola+1, konMaiya), getMaxLen(konPola, konMaiya+1) );

    return dpLen[konPola][konMaiya] = temp+1;
}

ll getWays(int konPola, int konMaiya, int currentLen) {

    if(konPola == polaLen && konMaiya == maiyaLen) {
        if(currentLen == len) return 1;
        return 0;
    }
    if(konPola > polaLen || konMaiya > maiyaLen) return 0;

    if(dpWays[konPola][konMaiya][currentLen] != -1) return dpWays[konPola][konMaiya][currentLen];

    ll temp;

    if(pola[konPola] == maiya[konMaiya]) temp = getWays(konPola+1, konMaiya+1, currentLen+1);
    else temp = getWays(konPola+1, konMaiya, currentLen+1) + getWays(konPola, konMaiya+1, currentLen+1);

    return dpWays[konPola][konMaiya][currentLen] = temp;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        memset(dpLen, -1, sizeof(dpLen));
        memset(dpWays, -1, sizeof(dpWays));

        cin >> pola >> maiya;
        polaLen = pola.size();
        maiyaLen = maiya.size();

        len = getMaxLen(0,0);
        ways = getWays(0,0, 0);

        printf("Case %d: %d %lld\n", t, len, ways);
    }

    return 0;
}
