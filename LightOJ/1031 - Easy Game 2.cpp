#include<bits/stdc++.h>
#define IM 10000000
using namespace std;

int n;
int dp[110][110];
int num[110];
//int leftTotal[110], rightTotal[110];

int getMax(int left, int right) {

    if(right-left == 1) return 0;

    if(dp[left][right] != IM) return dp[left][right];

    //int temp1 = INT_MIN, temp2 = INT_MIN;
    int dif = INT_MIN;

    int sum = 0;
    for(int i=left+1; i<right; i++) {
        //if(leftTotal[i]-leftTotal[left] > temp1)
            {
            //getchar();
            //temp1 = leftTotal[i] - leftTotal[left];
            sum += num[i];
            //cout << i << " te temp1 " << temp1 << endl;
            //cout << "ekhn hisab hobe " << i << " er with right " << right << endl;
            //dif = max(dif, temp1 - getMax(i, right) );
            dif = max(dif, sum - getMax(i, right) );
            //cout << "left theke " << i << " niye " << dif << endl;
        }
    }
    sum = 0;
    for(int i=right-1; i>left; i--) {
        //if(rightTotal[i]-rightTotal[right] > temp2)
            {
            //getchar();
            //temp2 = rightTotal[i]-rightTotal[right];
            sum += num[i];
            //cout << i << " te temp2 " << temp2 << endl;
            //cout << "ekhn hisab hobe " << i << " er with left " << left << endl;
            //dif = max(dif, temp2 - getMax(left, i));
            dif = max(dif, sum - getMax(left, i));
            //cout << "right theke " << i << " niye " << dif << endl;
        }
    }
    //cout << left << ' ' << right << ' ' << dif << endl;
    return dp[left][right] = dif;
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        //memset(dp, -1, sizeof(dp));
        for(int i=0; i<=103; i++)
        for(int j=0; j<=103; j++)
            dp[i][j] = IM;


        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d", &num[i]);

        //leftTotal[0] = rightTotal[n+1] = 0;
        //for(int i=1; i<=n; i++) leftTotal[i] = leftTotal[i-1] + num[i];
        //for(int i=n; i>0; i--) rightTotal[i] = rightTotal[i+1] + num[i];

        //cout << getMax(0, n+1) << endl;
        printf("Case %d: %d\n", t, getMax(0, n+1));
    }

    return 0;
}
