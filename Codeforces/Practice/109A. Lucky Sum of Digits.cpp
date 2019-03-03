#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int mod = n%7;

    if(mod % 4) {
        int seven = n/7, four = mod/4;
        for(int i=0; i<4 && seven; i++) {
            seven--; mod += 7;
            if(mod % 4 == 0) {
                four = mod/4;
                for(int i=0; i<four; i++) printf("4");
                for(int i=0; i<seven; i++) printf("7");
                printf("\n");
                return 0;
            }
        }
        printf("-1");
    }
    else {
        int seven = n/7, four = mod/4;
        for(int i=0; i<four; i++) printf("4");
        for(int i=0; i<seven; i++) printf("7");
        printf("\n");
    }

    return 0;
}
