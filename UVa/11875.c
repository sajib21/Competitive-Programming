#include <stdio.h>

int main()
{
    int T, N, i=1, j=0;
    scanf("%d", &T);
    while(i<=T)
    {
        scanf("%d", &N);
        int age[N];
        for(j=0; j<N; j++) scanf("%d", &age[j]);
        printf("Case %d: %d\n", i, age[j/2]);
        i++;
    }
    return 0;

}
