#include <bits/stdc++.h>
#define ll long long int
#define vii     vector<ll>
#define pb      push_back
#define pp      pop_back

using namespace std;


const int N = 2e5 + 5;
long long a[N], b[N];
long long dp[N];
int n;
struct ConvexHullTrick{
    vector<long long>A, B;
    int len, ptr;
    ConvexHullTrick(int N){
        A.resize(N);
        B.resize(N);
        len = 0;
    }
    void addLine(long long a, long long b){
        while(len >= 2 && (B[len-2] - B[len-1]) * 1.0 / (B[len-1] - b) >= (A[len-1] -A[len-2]) * 1.0 / (a - A[len-1]))
            --len;

        A[len] = a;
        B[len] = b;
        ++len;
    }
    long long qry(long long x){
        ptr = min(ptr, len - 1);
        while(ptr + 1 < len && A[ptr+1] * x + B[ptr+1] <= A[ptr] * x + B[ptr]) {

            ++ptr;
        }
        return A[ptr] * x + B[ptr];
    }

    void printHull() {
        cout << "HULL" << endl;
        for(int i=0; i<len; i++) cout << i << " : " << A[i] << ' ' << B[i] << endl;
    }
};
int main(){
//    scanf("%d", &n);
//    for(int i = 0; i < n; scanf("%lld", a + i++));
//    for(int i = 0; i < n; scanf("%lld", b + i++));

    ConvexHullTrick cht(10);

    cht.addLine(1, 0);
    cht.addLine(0, 2);
//    cht.addLine(-1, 0);

    cht.printHull();

    while(true) {
        ll x;
        cin >> x;
        cout << cht.qry(x) << endl;
    }

//    for(int i = 1; i < n; i++){
//        dp[i] = CHT.qry(a[i]);
//        CHT.addLine(b[i], dp[i]);
//    }
////    for(int i=0; i<n; i++) cout << dp[i] << ' ' ; cout << endl;
//    printf("%lld\n", CHT.qry(a[n-1]));
}
