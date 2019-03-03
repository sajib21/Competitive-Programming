#include<bits/stdc++.h>

using namespace std;

int nums[111];
int lSum, rSum, dif;

int maxDif(int st, int ed, int player) {

    int sumLeft = 0;
    for(int i=st; i<=ed; i++) {
        sumLeft += nums[i];
    }
}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    }

    maxDif(0, n-1, 1);
}
