#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, num[205];
    int lowVal = INT_MAX, lowIn, hiVal = INT_MIN, hiIn;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &num[i]);
        if(num[i] <= lowVal) {
            lowVal = num[i];
            lowIn = i;
        }
        if(num[i] > hiVal) {
            hiVal = num[i];
            hiIn = i;
        }
    }

    if(hiIn < lowIn) {
        printf("%d\n", hiIn + n - lowIn - 1);
    }
    else {
        printf("%d\n", hiIn + n - lowIn -1 -1);
    }

    return 0;

}
