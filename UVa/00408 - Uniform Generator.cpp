#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {

//    if(!b) return a;
//    return gcd(b, a%b);

    while(b) {
        int temp = a;

        a = b;
        b = temp % b;
    }

    return a;
}

int main() {

    int step, mod;
    while(scanf("%d %d", &step, &mod) != EOF) {

        if(!step || !mod) {
            printf("%10d%10d    Good Choice\n\n", step, mod);
        }

        else {
            if(gcd(step,mod) == 1) {
                printf("%10d%10d    Good Choice\n\n", step, mod);
            }
            else {
                printf("%10d%10d    Bad Choice\n\n", step, mod);
            }
        }
    }

    return 0;

}
