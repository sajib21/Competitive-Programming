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

    int xx = 0;
    if(hamB) xx+= b*pB;
    if(hamS) xx+= s*pS;
    if(hamC) xx+= c*pC;
//    r += b*pB + s*pS + c*pC;

    cout << r << endl;

    ll pHam = hamB*pB + hamS*pS + hamC*pC;

    cout << pHam << endl;

    printf("%I64d\n", r/pHam + (r%pHam + xx)/pHam );

    return 0;


}
