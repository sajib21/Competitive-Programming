#include <bits/stdc++.h>

using namespace std;

int objects,  prices[1010], weights[1010], total, capacity, dp[1010][35];

int getMax(int obj, int w) {

    if(obj == objects) return 0;

    if(dp[obj][w] != -1) return dp[obj][w];
    else {
        int cost1, cost2;
        if(w+weights[obj] <= capacity)
            cost1 = prices[obj] + getMax(obj+1, w+weights[obj]);
        else
            cost1 = 0;

        cost2 = getMax(obj+1, w);

        dp[obj][w] = max(cost1, cost2);
        return dp[obj][w];
    }
}

int main() {
    int t, persons;
    scanf("%d", &t);

    while(t--) {

        total = 0;


        scanf("%d", &objects);
        for(int i=0; i<objects; i++) {
            scanf("%d %d", &prices[i], &weights[i]);
        }
        scanf("%d", &persons);
        for(int i=0; i<persons; i++) {
            scanf("%d", &capacity);
            memset(dp, -1, sizeof(dp));
            int temp;
            temp = getMax(0,0);
            total += temp;
            //total += getMax(0, 0);
//            printf("now = %d\n",temp);
        }

        printf("%d\n", total);
    }

}
