#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        if(n == 1 || n == 64 || n == 729 || n == 4096 || n == 15625 || n == 46656 || n == 117649 || n == 262144 || n == 531441 || n == 1000000 ||
           n == 1771561 || n == 2985984 || n == 4826809 || n == 7529536 || n == 11390625 || n == 16777216 || n == 24137569 || n == 34012224 ||
           n == 47045881 || n == 64000000 || n == 85766121)
           printf("Special\n");
        else printf("Ordinary\n");
    }
}
