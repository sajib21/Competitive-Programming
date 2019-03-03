#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    int hamB = 0, hamS = 0, hamC = 0;
    char cc;
    for(int i=0; ;i++) {
        scanf("%c", &cc);

        if(cc == 'B') hamB++;
        else if(cc == 'S') hamS++;
        else if(cc == 'C') hamC++;

        if(cc == '\n') {
            //ingr[i] = 0;
            break;
        }
    }

    //cout << hamB << ' ' << hamS << ' ' << hamC << endl;

    int b,s,c;
    scanf("%d %d %d", &b,&s,&c);
    int pB, pS, pC;
    scanf("%d %d %d", &pB, &pS, &pC);

    ll r;
    scanf("%I64d", &r);

    int tm = min( b/(hamB == 0 ? INT_MAX : hamB) , min( s/(hamS == 0 ? INT_MAX : hamS) , c/(hamC == 0 ? INT_MAX : hamC) ) );
    ll ans = 0;

    b -= tm*hamB; s -= tm*hamS; c -= tm*hamC;
    if(b<0 || s<0 || c<0) {
        b += tm*hamB; s += tm*hamS; c += tm*hamC;
    }
    else ans += tm;

    //cout << tm << endl << ' ' << b << ' ' << s << ' ' << c << endl;

    if(!hamB) b = 0;
    if(!hamS) s = 0;
    if(!hamC) c = 0;


    while(b || s || c ) {

        int addPrice = 0;
        if(b >= hamB) b -= hamB;
        else addPrice += (hamB-b)*pB, b=0;
        if(s >= hamS) s -= hamS;
        else addPrice += (hamS-s)*pS, s=0;
        if(c >= hamC) c -= hamC;
        else addPrice += (hamC-c)*pC, c=0;

//        cout << addPrice << endl;

        if(addPrice <= r) {
            r -= addPrice;
            ans++;
        }
        else break;
    }

    ll pHam = hamB*pB + hamS*pS + hamC*pC;
    ans += (r/pHam);

    cout << ans << endl;


//    cout << pHam << endl;
//    printf("%I64d\n", r/pHam + (r%pHam + xx)/pHam );

    return 0;


}
