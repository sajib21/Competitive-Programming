#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t,T;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {

        int n;
        scanf("%d",&n);

        int my[53], op[53];
        for(int i=0; i<n; i++) scanf("%d", &my[i]);
        for(int i=0; i<n; i++) scanf("%d", &op[i]);

        sort(my, my+n);
        sort(op, op+n);

        int win = 0, draw = 0;
        int i=0, j=0;

        while(i < n && j < n)
        {
            if(my[i] < op[j]) i++;
            else if(my[i] > op[j])
            {
                win++;
                i++;
                j++;
            }
            else
            {
                if(i > j) {
                    draw++;
                    i++;
                    j++;
                }
                else i++;
            }
        }

        printf("Case %d: %d\n",t, win*2 + draw);
    }

    return 0;
}
