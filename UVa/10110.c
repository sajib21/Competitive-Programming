#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int a;
    float b;
    while (scanf("%u",&a)==1) {
        if (a==0) break;

        b=sqrt(a);
        if (b== (int) b) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
