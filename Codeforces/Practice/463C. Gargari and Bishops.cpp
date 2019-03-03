#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll num[2003][2003], sumL[2003][2003], sumR[2003][2003];

int main() {

    int n;

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%I64d", &num[i][j]);
            sumL[i][j] = num[i][j] + sumL[i-1][j+1];
            sumR[i][j] = num[i][j] + sumR[i-1][j-1];
        }
    }
    ll ansOdd = 0, ansEven = 0;
    int oddX = 1, oddY = 1, evenX = 1, evenY = 2;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int t = min(j-1, n-i);
            //ll takeL = sumL[i+t][j-t];
            int tt = min(n-j , n-i);
            //ll takeR = sumR[i+tt][j+tt];

            if( (i + j) % 2 ) {
                ll temp = sumL[i+t][j-t] + sumR[i+tt][j+tt] - num[i][j];
                if( temp > ansOdd) {
                    ansOdd = temp;
                    oddX = i; oddY = j;

                }
            }
            else {
                ll temp = sumL[i+t][j-t] + sumR[i+tt][j+tt] - num[i][j];
                if(temp > ansEven) {
                    ansEven = temp;
                    evenX = i; evenY = j;
                }
            }
        }
    }

    //cout << ansOdd << ' ' << ansEven << endl;

    printf("%I64d\n", ansOdd+ansEven);
//    printf("%I64d\n", );
    printf("%d %d %d %d\n", oddX, oddY, evenX, evenY);

    return 0;
}
