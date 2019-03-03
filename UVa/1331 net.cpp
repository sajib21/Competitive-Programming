#include <iostream>
#include <algorithm>
#include <cmath>
#include<bits/stdc++.h>

#define EPS 1e-6
using namespace std;
int T, N;
struct point
{
    double x, y;
} pts[55];
double area(point a, point b, point c)
{
    return fabs((b.x - a.x)* (c.y - a.y) - (c.x-a.x) * (b.y-a.y)) / 2.0;
}
bool legit(int i, int j, int k)
{
    double oris = area(pts[i], pts[j], pts[k]);
    for (int x = 0; x < N; x++)
    {
        if (x==i||x==j||x==k) continue;
        double sum = area(pts[i], pts[j], pts[x]) + area(pts[i], pts[k], pts[x]) + area(pts[k], pts[j], pts[x]);
        if (fabs(sum - oris) < EPS) return false;
    }
    return true;
}
double dp[55][55];
double recur(int st, int ed)
{
    if (dp[st][ed] != -1.0) return dp[st][ed];
    if (st+1 == ed ) return  dp[st][ed] = -10.0;
    double ans = 100000000.0;
    for (int i = st + 1; i < ed; i++)
    {
        if (legit(st,ed,i))
        {
            if (st + 2 == ed)
                ans = area(pts[st], pts[i], pts[ed]);
            else
                ans = min(ans, max(area(pts[st], pts[i], pts[ed]), max(recur(st,i), recur(i,ed)) ) );
        }
    }
    return dp[st][ed] = ans;
}
int main()
{
//    freopen("1331i.txt", "r", stdin);
//    freopen("1331a.txt", "w", stdout);


    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%lf%lf", &pts[i].x, &pts[i].y);
            for (int j = 0; j < N; j++)
                dp[i][j] = -1.0;
        }

        printf("%.1lf\n",recur(0, N-1));
    }
}
