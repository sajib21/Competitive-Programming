#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

class ConvexHull {
private:
    int head, tail;
    long long A[N], B[N];
public:
    void init() { head = tail = 0; }
    bool bad(int l1, int l2, int l3) {
        return (long double) (B[l3] - B[l1]) / (A[l1] - A[l3]) < (long double) (B[l2] - B[l1]) / (A[l1] - A[l2]);
    }
    void add(long long a, long long b) {
        A[tail] = a; B[tail++] = b;
        while (tail > 2 && bad(tail - 3, tail - 2, tail - 1)) {
            A[tail - 2] = A[tail - 1];
            B[tail - 2] = B[tail - 1];
            tail--;
        }
    }
    long long query(long long x) {
        if (head >= tail) head = tail - 1;
        while (head < tail - 1
               && A[head + 1] * x + B[head + 1] >= A[head] * x + B[head]) head++;
        return A[head] * x + B[head];
    }

    void printHull() {
        cout << "HULL" << endl;
        for(int i=head; i<tail; i++) cout << i << " : " << A[i] << ' ' << B[i] << endl;
    }

} hull;

int n, a, b, c;
long long sum[N];

long long f(long long x) { return a * x * x + b * x + c; }

void load() {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", sum + i);
        sum[i] += sum[i - 1];
    }
}

void process() {
    hull.init();
    long long cost = f(sum[1]);
    hull.add(-2 * a * sum[1], cost + a * sum[1] * sum[1] - b * sum[1]);
//    cout << "INS " << cost << ' ' << a * sum[1] * sum[1] << ' ' << - b * sum[1] << endl;

    for (int i = 2; i <= n; ++i) {
//        hull.printHull();
        cost = f(sum[i]) + max(0ll, hull.query(sum[i]));
//        cout << cost << ' ' << hull.query(sum[i]) << endl;

        hull.add(-2 * a * sum[i], cost + a * sum[i] * sum[i] - b * sum[i]);
    }
    printf("%lld\n", cost);

//    hull.printHull();

}

int main() {
    //freopen("in.txt", "r", stdin);
 //   freopen("output.out", "w", stdout);

    int test; scanf("%d", &test);
    while (test--) {
        load();
        process();
    }

    return 0;
}
