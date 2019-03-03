#include <bits/stdtr1c++.h>

#define MAX 1048576
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

/// Fast Walsh-Hadamard Transformation in n log n
namespace fwht{ /// hash = 840614
    const int OR = 0;
    const int AND = 1;
    const int XOR = 2;

    long long P1[MAX], P2[MAX];

    void walsh_transform(long long* ar, int n, int flag = XOR){
        if (n == 0) return;

        int i, m = n / 2;
        walsh_transform(ar, m, flag);
        walsh_transform(ar + m, m, flag);

        for (i = 0; i < m; i++){ /// Don't forget modulo if required
            long long x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = x + y;
            if (flag == AND) ar[i] = x + y, ar[i + m] = y;
            if (flag == XOR) ar[i] = x + y, ar[i + m] = x - y;
        }
    }

    void inverse_walsh_transform(long long* ar, int n, int flag = XOR){
        if (n == 0) return;

        int i, m = n / 2;
        inverse_walsh_transform(ar, m, flag);
        inverse_walsh_transform(ar + m, m, flag);

        for (i = 0; i < m; i++){ /// Don't forget modulo if required
            long long x = ar[i], y = ar[i + m];
            if (flag == OR) ar[i] = x, ar[i + m] = y - x;
            if (flag == AND) ar[i] = x - y, ar[i + m] = y;
            if (flag == XOR) ar[i] = (x + y) >> 1, ar[i + m] = (x - y) >> 1; /// Modular inverse if required here
        }
    }

    vector <long long> convolution(int n, long long* A, long long* B, int flag = XOR){
        assert(__builtin_popcount(n) == 1); /// n must be a power of 2
        for (int i = 0; i < n; i++) P1[i] = A[i];
        for (int i = 0; i < n; i++) P2[i] = B[i];

        walsh_transform(P1, n, flag);
        walsh_transform(P2, n, flag);
        for (int i = 0; i < n; i++) P1[i] = P1[i] * P2[i];
        inverse_walsh_transform(P1, n, flag);
        return vector<long long> (P1, P1 + n);
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i or j] += A[i] * B[j]
    vector <long long> or_convolution(int n, long long* A, long long* B){
        return convolution(n, A, B, OR);
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i and j] += A[i] * B[j]
    vector <long long> and_convolution(int n, long long* A, long long* B){
        return convolution(n, A, B, AND);
    }

    /// For i = 0 to n - 1, j = 0 to n - 1
    /// v[i xor j] += A[i] * B[j]
    vector <long long> xor_convolution(int n, long long* A, long long* B){
        return convolution(n, A, B, XOR);
    }
}

int n;
long long A[MAX], B[MAX], C[MAX];

void brute(){
    int i, j;
    clr(C);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            C[i ^ j] += (A[i] * B[j]);
        }
    }
}

int main(){
    int i, j, k, l, x;

    n = 1 << 15;
    for (i = 0; i < n; i++) A[i] = ran(1, 1000000);
    for (i = 0; i < n; i++) B[i] = ran(1, 1000000);
    brute();
    unsigned long long h1 = 0, h2 = 0;
    for (i = 0; i < n; i++) h1 = (h1 * 1000000007) + C[i] + 97;

    vector <long long> v = fwht::xor_convolution(n, A, B);
    for (i = 0; i < n; i++) h2 = (h2 * 1000000007) + v[i] + 97;

    dbg(h1);
    dbg(h2);
    return 0;
}
