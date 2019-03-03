#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, ladies[50005], q, luchu;

    while(scanf("%d", &n) != EOF) {

        for(int i=0; i<n; i++) scanf("%d", &ladies[i]);
        scanf("%d", &q);
        for(int i=0; i<q; i++) {
            scanf("%d", &luchu);

            int low = lower_bound(ladies, ladies+n, luchu) - ladies - 1;
            int hig = upper_bound(ladies, ladies+n, luchu) - ladies;

            if(low < 0) printf("X"); else printf("%d", ladies[low]);
            if(hig == n) printf(" X\n"); else printf(" %d\n", ladies[hig]);
        }
    }

    return 0;

}
