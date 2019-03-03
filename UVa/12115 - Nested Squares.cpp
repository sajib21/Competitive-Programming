#include<bits/stdc++.h>

using namespace std;

int q, n, r1,c1, r2,c2;
char str[50004];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T;t++) {
        scanf("%s %d", &str, &q);
        n = strlen(str);

        printf("Square %d:\n", t);
        for(int qq=1; qq<=q; qq++) {
            scanf("%d %d %d %d", &r1,&c1, &r2,&c2);
            r1--; c1--; r2--; c2--;

            printf("Query %d:\n", qq);
            for(int i=r1; i<=r2; i++) {
//                cout << "COL" << endl;
                for(int j=c1; j<=c2; j++) {
                    int u=i, v=j;
                    if(u >= n) u = 2*n-u-2;
                    if(v >= n) v = 2*n-v-2;
//                    cout << i << ' ' << j << ' ' << u << ' ' << v << endl;
                    printf("%c", str[ min(u,v) ] );
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}
