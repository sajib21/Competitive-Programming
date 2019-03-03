#include <stdio.h>

int main()
{
    int N,j=0;

    scanf ("%d",&N);

    int ara[N];
    for (j=0;j<N;j++) {
    scanf ("%d", &ara[j]);
    }

    printf ("%d",ara[j/2]);

    return 0;
}
