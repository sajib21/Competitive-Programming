/* IT WAS TECHNICAL FOR ME AS I'M NEW.
 IN PREVIOUS GRUNDY GAMES, WE WERE GOING IN NEW STATE IN THE SAME GAME.
 FOR EXAMPLE, TAKING 2 FROM 5 COINS WILL TAKE US TO THE STATE FOR 3 COINS IN THE SAME GAME.
 BUT IN THIS PROBLEM, WHEN WE TAKE FEW COINS WE DON'T TAKE THEM OURSELVES, WE JUST MAKE DIVISION WHICH MEANS THAT NOW WE HAVE TWO GAMES.
 FOR EXAMPLE, WHEN WE DIVIDE 7 COINS INTO 3 AND 4, THE NEXT PLAYER WOULD HAVE A CHOICE OF DIVIDING 3 OR 4 COINS WHICH MEANS THAT HE
 HAS TWO GAMES TO CHOOSE FROM. AND WE TAKE XOR OF GRUNDIES OF DIFFERENT GAME.
 SO TO COUND A GRUNDY, WE HAD TO XOR THE GRUNDIES OF EACH MOVE BECAUSE THEY WERE TWO SEPARATE GAMES THEN, THEN CHOOSE MEX FROM THESE GRUNDIES.
*/



#include<bits/stdc++.h>
#define MX 10010

using namespace std;

int grundy[MX+10];

int getGrundy(int n) {

    if(grundy[n] != -1) return grundy[n];

    set<int>st;
    int lim = n/2;
    for(int i=1; i<=lim; i++) {
        if(n-i != i) {
            st.insert( getGrundy(i) ^ getGrundy(n-i) );
        }
    }

    int ans = 0;
    while(st.find(ans) != st.end()) ans++;
    return grundy[n] = ans;
}

int main() {

    memset(grundy, -1, sizeof(grundy));
    grundy[0] = grundy[1] = grundy[2] = 0;

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int n, c, xorSum = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &c);
            xorSum ^= getGrundy(c);
        }
        if(xorSum) printf("Case %d: Alice\n", t);
        else printf("Case %d: Bob\n", t);
    }

    return 0;

}
