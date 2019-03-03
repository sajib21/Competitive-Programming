/*
Maximum Manhattan distance:

dist(P1, P2) = |x1 - x2| + |y1 - y2|
             = max(  x1 - x2 +  y1 - y2,
                    -x1 + x2 +  y1 - y2,
                     x1 - x2 + -y1 + y2,
                    -x1 + x2 + -y1 + y2) )
             = max(  ( x1 + y1) - ( x2 + y2),
                     (-x1 + y1) - (-x2 + y2),
                     ( x1 - y1) - ( x2 - y2),
                     (-x1 - y1) - (-x2 - y2) )
             = max( f1(P1) - f1(P2),
                    f2(P1) - f2(P2),
                    f3(P1) - f3(P2),
                    f4(P1) - f4(P2) )
where f1(P) = x+y, f2(P) = -x+y, f3(P) = x-y, f4(P) = -x-y

max(P1,P2){dist(P1,P2)}
    = max(P1,P2){max(f1(P1)-f1(P2),f2(P1)-f2(P2),f3(P1)-f3(P2),f4(P1)-f4(P2))}
    = max( maxP{f1(P)}-minP{f1(P)} , maxP{f2(P)}-minP{f2(P)} ,
           maxP{f3(P)}-minP{f3(P)} , maxP{f4(P)}-minP{f4(P)} )

*/

#include<bits/stdc++.h>
#define LIM 200005
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

struct point {
    int x,y;
    point() {}
    point(int xx, int yy) {
        x = xx; y = yy;
    }

    int f1() { return + x + y; }
    int f2() { return - x + y; }
    int f3() { return + x - y; }
    int f4() { return - x - y; }

};

int n, x,y, temp;
int maxf[5], minf[5];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=4; i++) maxf[i] = INT_MIN;
    for(int i=1; i<=4; i++) minf[i] = INT_MAX;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x,&y);
        temp = point(x,y).f1(); maxf[1] = max(maxf[1], temp); minf[1] = min(minf[1], temp);
        temp = point(x,y).f2(); maxf[2] = max(maxf[2], temp); minf[2] = min(minf[2], temp);
        temp = point(x,y).f3(); maxf[3] = max(maxf[3], temp); minf[3] = min(minf[3], temp);
        temp = point(x,y).f4(); maxf[4] = max(maxf[4], temp); minf[4] = min(minf[4], temp);
    }

    int ans = 0;
    for(int i=1; i<=4; i++) ans = max(ans, maxf[i]-minf[i] );

    cout << "Maximum Manhattan Distance: " << ans << endl;

}
