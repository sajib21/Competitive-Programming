#include<bits/stdc++.h>

using namespace std;

long long int n, sum[500005], totalSum=0;

int main() {

    scanf("%I64d", &n);
    sum[0] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%I64d", &sum[i]);
        totalSum += sum[i];
        sum[i] += sum[i-1];
    }

    if(totalSum%3) {
        printf("0\n");
        return 0;
    }

    totalSum /= 3;
    long long int ans = 0, tmp = 0;

    if(sum[1] == totalSum) tmp++;
    for(int i=2; i<n; i++) {
        if(sum[i] == 2*totalSum) ans += tmp;
        if(sum[i] == totalSum) tmp++;
    }
    printf("%I64d\n", ans);

    return 0;

}
