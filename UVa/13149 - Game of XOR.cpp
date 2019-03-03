#include<bits/stdc++.h>
#define MOD 342307123
#define LIM 100005
#define ll long long int

using namespace std;

int n, a,b;
char str[LIM], seq1[LIM], seq2[LIM];

ll one[5][10004], zero[5][10004], temp[5];

int main() {
//    freopen("in.txt", "r", stdin);
    one[0][1] = one[1][1] = 0; /// 00, 01
    one[2][1] = one[3][1] = 1;

    for(int i=2; i<=10000; i++) {
        temp[0] = one[0][i-1] + one[0][i-1];
        temp[1] = one[1][i-1] + one[3][i-1];
        temp[2] = one[3][i-1] + one[2][i-1];
        temp[3] = one[2][i-1] + one[1][i-1];
        temp[0] %= MOD; temp[1] %= MOD; temp[2] %= MOD; temp[3] %= MOD;
        one[0][i] = temp[0]; one[1][i] = temp[1]; one[2][i] = temp[2]; one[3][i] = temp[3];
    }

    zero[0][1] = zero[1][1] = 1; /// 00, 01
    zero[2][1] = zero[3][1] = 0;

    for(int i=2; i<=10000; i++) {
        temp[0] = zero[0][i-1] + zero[0][i-1];
        temp[1] = zero[1][i-1] + zero[3][i-1];
        temp[2] = zero[3][i-1] + zero[2][i-1];
        temp[3] = zero[2][i-1] + zero[1][i-1];
        temp[0] %= MOD; temp[1] %= MOD; temp[2] %= MOD; temp[3] %= MOD;
        zero[0][i] = temp[0]; zero[1][i] = temp[1]; zero[2][i] = temp[2]; zero[3][i] = temp[3];
    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%s %d", str, &n); strcat(str, "0");
        scanf("%d", &a); if(n > 1) scanf("%s", seq1);
        scanf("%d", &b); if(n > 1) scanf("%s", seq2);

        ll ans1 = 0, ans0 = 0;
        for(int i=a; i<b; i++) {
            int in = (str[i]-'0')*2 + (str[i+1]-'0');
            ans0 += zero[in][n]; ans1 += one[in][n];
            ans0 %= MOD; ans1 %= MOD;
        }

//        cout << "BUG" << endl;

        int ina = str[a]-'0', inb = str[a+1]-'0';
        for(int i=0; i<n-1; i++) {
            if(seq1[i] == 'D') {
                inb = ina ^ inb;
            }
            else {
                int in = ina ^ inb;
                ans0 -= zero[ina*2+in][n-i-1];
                ans1 -= one[ina*2+in][n-i-1];
                ans0 %= MOD; ans1 %= MOD;
                ina = in;
            }
        }

        ina = str[b]-'0', inb = str[b+1]-'0';
//        cout << ina << ' ' << inb << endl;
        for(int i=0; i<n-1; i++) {
            if(seq2[i] == 'D') {
                inb = ina ^ inb;
            }
            else {
                int in = ina ^ inb;
                ans0 += zero[ina*2+in][n-i-1];
                ans1 += one[ina*2+in][n-i-1];
                ans0 %= MOD; ans1 %= MOD;
                ina = in;
            }
        }
        ans0 += zero[ina*2+inb][1];
        ans1 += one[ina*2+inb][1];

        ans0 %= MOD; ans1 %= MOD;
        ans0 += MOD; ans1 += MOD;
        ans0 %= MOD; ans1 %= MOD;

        printf("Case %d: %lld %lld\n", t, ans0, ans1);
    }
}
