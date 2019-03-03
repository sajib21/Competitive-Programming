#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int i=1,j=n;

    int in = 1;

    while(i <= j) {
        if(in) printf("%d ", i++);
        else   printf("%d ", j--);
        in ^= 1;
    }

}
