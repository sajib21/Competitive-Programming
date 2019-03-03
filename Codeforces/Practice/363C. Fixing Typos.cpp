#include<bits/stdc++.h>

using namespace std;

int main() {

    string seq;
    cin >> seq;

    int len = seq.size();
    int bl = 0;

    printf("%c", seq[0]);
    for(int i=1; i<len; i++) {

        if(seq[i] != seq[i-1]) {
            if(bl == 0) {
                printf("%c", seq[i]);
            }
            else if(bl == 1) {
                printf("%c", seq[i]);
                bl = 2;
            }
            else {
                printf("%c", seq[i]);
                bl = 0;
            }
        }
        else {
            if(bl == 0) {
                printf("%c", seq[i]);
                bl = 1;
            }
            else if(bl == 2) {

            }
        }
    }

    printf("\n");
    return 0;
}
