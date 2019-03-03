/*
problem: Optimize the innermost loop
for(k=1; k<=g; k++) {
    for(i=k; i<=n; i++) {
        for(j=k; j<=i; j++) {
            dp[k][i] = min(dp[k][i], cost(j,i)+dp[k-1][j-1]);
        }
    }
}

say, P[k][i] is the first j value for which,
dp[k][i] = cost(j,i)+dp[k-1][j-1]
if for fixed k, P[k][0] <= P[k][1] <= P[k][2] .... (monotone)
then

*/

#include<bits/stdc++.h>
#define LIM 4004
#define MAX 1000000000
#define ll long long int

using namespace std;

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}


int n,g, a[LIM][LIM];
int S[LIM][LIM], dp[808][LIM], P[808][LIM];
/// dp[g][i] mane g ta group diya i er ag porjonto

void makeSparse() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            S[i][j] = S[i][j-1] + a[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            S[i][j] += S[i-1][j];
        }
    }
}

int cost(int i, int j) {
    if(i > j) return 0;
    i--;
    return S[j][j] - 2*S[i][j] + S[i][i];
}

void f(int g, int st, int ed, int l, int r) {
//    cout << "IN: " << g << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << endl;
//    getchar();
    if(st >= ed) return;
    int md = (st+ed)/2;
    dp[g][md] = MAX;

    for(int i=l; i<=r; i++) {
//        cout << "TEST: " << i << ' ' << cost(i+1,md) << ' ' << dp[g-1][i] << endl; getchar();
        ll temp = cost(i,md) + dp[g-1][i-1];
        if(i==l || temp < dp[g][md]) {
            dp[g][md] = temp;
            P[g][md] = i;
        }
    }

//    cout << "GOT: " << g << ' ' << md << ' ' << dp[g][md] << endl; getchar();

    f(g, st,md,   l, P[g][md]);
    f(g, md+1,ed, P[g][md], r);
}

int main() {
    fastscan(n); fastscan(g);
//    scanf("%d %d", &n,&g);
//    cout << n << g << endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            fastscan(a[i][j]);
//            scanf("%d", &a[i][j]);
        }
    }
    makeSparse();

    for(int i=1; i<=n; i++) dp[1][i] = cost(1,i);

    for(int k=2; k<=g; k++) f(k, 1,n+1, 1,n);

    printf("%d\n", dp[g][n]/2 );

//    main();

}

