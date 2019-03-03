#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define ll long long int

using namespace std;
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#define TEST(s) if (!(s)) { cout << __LINE__ << " " << #s << endl; exit(-1); }


struct bigint : vector<long long> {
  // smaller B ==> larger deals / slower operations
  // B = 100000000  (10^8) ==> it deals with 10^645636
  // B = 1000000000 (10^9) ==> it deals with 10^7378
  static constexpr int B = 1000000, W = log10(B);
  char sign;
  bigint& trim() {
    while (!empty() && !back()) pop_back();
    if (empty()) sign = 1;
    return *this;
  }
  bigint(long long v = 0) : sign(1) {
    if (v < 0) { sign = -1; v = -v; }
    while (v > 0) {
      push_back(v % B);
      v /= B;
    }
  }
  bigint(string s) : sign(+1) {
    int e = 0;
    for (; e < s.size() && s[e] <= '0' || s[e] >= '9'; ++e)
      if (s[e] == '-') sign = -sign;
    for (int i = s.size()-1; i >= e; i -= W) {
      push_back(0);
      for (int j = max(e, i - W + 1); j <= i; ++j)
        back() = 10 * back() + (s[j] - '0');
    }
    trim();
  }
  bigint operator-() const {
    bigint x = *this;
    if (!empty()) x.sign = -x.sign;
    return x;
  }
  operator vector<long long>(); // protect from unexpected casts

  bigint &operator+=(bigint x);
};

// input and output
ostream &operator<<(ostream &os, const bigint &x) {
  if (x.sign < 0) os << '-';
  os << (x.empty() ? 0 : x.back());
  for (int i = (int)x.size()-2; i >= 0; --i)
    os << setfill('0') << setw(bigint::W) << x[i];
  return os;
}
istream &operator>>(istream &is, bigint &x) {
  string s;
  is >> s;
  x = bigint(s);
  return is;
}

bigint operator-(bigint x, bigint y);
bigint operator+(bigint x, bigint y) {
  if (x.sign != y.sign) return x - (-y);
  if (x.size() < y.size()) swap(x, y);
  int c = 0;
  for (int i = 0; i < y.size(); ++i) {
    x[i] += y[i] + c;
    c = (x[i] >= bigint::B);
    if (c) x[i] -= bigint::B;
  }
  if (c) x.push_back(c);
  return x;
}
bigint operator-(bigint x, bigint y) {
  if (x.sign != y.sign) return x + (-y);
  int sign = x.sign;
  x.sign = y.sign = +1;
  if (x < y) {
    swap(x, y);
    sign = -sign;
  }
  int c = 0;
  for (int i = 0; i < x.size(); ++i) {
    x[i] -= (i < y.size() ? y[i] : 0) + c;
    c = (x[i] < 0);
    if (c) x[i] += bigint::B;
  }
  x.sign = sign;
  return x.trim();
}
bigint operator*(bigint x, int y) {
  if (y == 0) return bigint(0);
  if (y < 0) { x.sign = -x.sign; y = -y; }
  int c = 0;
  for (int i = 0; i < x.size() || c; ++i) {
    if (i == x.size()) x.push_back(0);
    x[i] = x[i] * y + c;
    c = x[i] / bigint::B;
    if (c) x[i] %= bigint::B;
  }
  return x;
}
bigint operator*(int x, bigint y) { return y * x; }

// Karatsuba multiplication
bigint operator*(bigint x, bigint y) {
  if (x.empty()||y.empty()) return bigint(0);
  function<void(long long*, int, long long*, int, long long*)>
    rec = [&](long long *x, int xn, long long *y, int yn, long long *z) {
    if (xn < yn) { swap(xn, yn); swap(x, y); }
    fill(z, z+xn+yn, 0);
    if (yn <= 2) {
      for (int i = 0; i < xn; ++i)
        for (int j = 0; j < yn; ++j)
          z[i+j] += x[i] * y[j];
    } else {
      int m = (xn+1)/2, n = min(m, yn);
      for (int i = 0; i+m < xn; ++i) x[i] += x[i+m];
      for (int j = 0; j+m < yn; ++j) y[j] += y[j+m];
      rec(x, m, y, n, z+m);
      for (int i = 0; i+m < xn; ++i) x[i] -= x[i+m];
      for (int j = 0; j+m < yn; ++j) y[j] -= y[j+m];
      long long p[2*m+2];
      rec(x, m, y, n, p);
      for (int i = 0; i < m+n; ++i) { z[i] += p[i]; z[i+m] -= p[i]; }
      rec(x+m, xn-m, y+m, yn-n, p);
      for (int i = 0; i < xn+yn-m-n; ++i) { z[i+m] -= p[i]; z[i+2*m] += p[i]; }
    }
  };
  bigint z; z.resize(x.size()+y.size()+2);
  z.sign = x.sign * y.sign;
  rec(&x[0], x.size(), &y[0], y.size(), &z[0]);
  for (int i = 0; i+1 < z.size(); ++i) { // be careful with overflow
    z[i+1] += z[i] / bigint::B;
    z[i] %= bigint::B;
    if (z[i] < 0) {
      z[i+1] -= 1;
      z[i] += bigint::B;
    }
  }
  return z.trim();
}
bigint pow(bigint x, int b) {
  bigint y(1);
  for (; b > 0; b /= 2) {
    if (b % 2) y = y * x;
    x = x * x;
  }
  return y;
}

pair<bigint, int> divmod(bigint x, int y) {
  if (y < 0) { x.sign = -x.sign; y = -y; }
  int rem = 0;
  for (int i = x.size()-1; i >= 0; --i) {
    x[i] += rem * bigint::B;
    rem = x[i] % y;
    x[i] /= y;
  }
  return {x.trim(), rem};
}
bigint operator/(bigint x, int y) { return divmod(x, y).fst; }
bigint operator%(bigint x, int y) { return divmod(x, y).snd; }

// Knuth's algorithm D
pair<bigint, bigint> divmod(bigint x, bigint y) {
  auto norm = bigint::B / (y.back() + 1);
  int qsign = x.sign * y.sign, rsign = x.sign;
  x = x * norm; x.sign = +1;
  y = y * norm; y.sign = +1;
  bigint q, r;
  for (int i = (int)x.size()-1; i >= 0; --i) {
    r.insert(r.begin(), x[i]);
    long long d = ((r.size()   > y.size() ? bigint::B * r[y.size()] : 0)
                 + (r.size()+1 > y.size() ? r[y.size()-1] : 0)) / y.back();
    r = r - y * d;
    while (r.sign < 0) { r = r + y; d -= 1; }
    q.push_back(d);
  }
  reverse(all(q));
  q.sign = qsign; r.sign = rsign;
  return make_pair(q.trim(), divmod(r.trim(), norm).fst);
}
bigint operator/(bigint x, bigint y) { return divmod(x, y).fst; }
bigint operator%(bigint x, bigint y) { return divmod(x, y).snd; }





int cont[20] = {0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1};
vii graph[20];
char seq[15];
bigint dp[1010][20][4];

int conv(string str) {
    int ans = 0;
    for(int i=0; i<str.size(); i++) {
        ans = ans*10 + (str[i]-'0');
    }
    return ans;
}

void print(vector<int> sol) {
    cout << "SOL " ;
    for(int i=0; i<sol.size(); i++) cout << sol[i] << ' ' ; cout << endl;
}
void print(bigint ans, int cnt = 0) {
    cout << ans << endl; return;


    bigint zero = 0;
    if(ans==zero) return;
    print(ans/10, cnt+1);
    cout << ans%10;
    if(cnt && cnt%3==0) printf(",");
    return;
}

bigint f(int n, int u, int con, vector<int> sol) {
//    cout << n << ' ' << u << ' ' << con << ' ' ; print(sol); getchar();
    if(n == 0) {
        int ret = (con == 1) && (u == 1 || u == 2);
//        if(ret) {
//            print(sol); getchar();
//        }
        return ret;
    }

    bigint min1 = -1;
    if(dp[n][u][con]==min1) return dp[n][u][con];
    bigint ans = 0;

    if(con == 2) {

        ans = ans + f(n-1, 1, 1, sol);
        ans = ans + f(n-1, 9, 2, sol);
        ans = ans + f(n-1, 14, 1, sol);
        ans = ans + f(n-1, 15, 1, sol);
        return dp[n][u][con] = ans;
    }

    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        sol.pb(v);
        if(v >= 16) ans = ans + f(n-1, v, 0, sol );
        else if(v >= 14) {
            if(con) ans = ans + f(n-1, v, con, sol);
        }
        else if(v == 8) ans = ans + f(n-1, v, 2, sol);
        else
            ans = ans + f(n-1, v, con | cont[v], sol );
        sol.pop_back();
    }
    return dp[n][u][con] = ans;
}

int main() {
//    freopen("24.txt", "w", stdout);

    graph[3].pb(5);
    graph[4].pb(2); graph[4].pb(3); graph[4].pb(8); graph[4].pb(10); graph[4].pb(12);
    graph[5].pb(2); graph[5].pb(3); graph[5].pb(8); graph[5].pb(10); graph[5].pb(12);
    graph[6].pb(7); graph[6].pb(9); //graph[6].pb(14); graph[6].pb(15);
    graph[7].pb(2); graph[7].pb(3); graph[7].pb(8); graph[7].pb(10); graph[7].pb(12);
    graph[8].pb(1); graph[8].pb(9); graph[8].pb(14); graph[8].pb(15);
    graph[9].pb(1); graph[9].pb(7); graph[9].pb(9); graph[9].pb(14); graph[9].pb(15);

    graph[10].pb(11); graph[10].pb(16);
    graph[11].pb(2); graph[11].pb(3); graph[11].pb(8); graph[11].pb(10); graph[11].pb(12);
    graph[12].pb(13); graph[12].pb(17);
    graph[13].pb(2); graph[13].pb(3); graph[13].pb(8); graph[13].pb(10); graph[13].pb(12);

    graph[14].pb(13); graph[14].pb(17);
    graph[15].pb(11); graph[15].pb(16);
//    graph[16].pb(1);
    graph[16].pb(7); graph[16].pb(9);
//    graph[17].pb(1);
    graph[17].pb(7); graph[17].pb(9);


//    memset(dp, -1, sizeof dp);

    for(int i = 0 ; i < 1004 ; i++)
            for(int j = 0 ; j < 20 ; j++)
                for(int k =0 ; k > 4 ; k++)
                    dp[i][j][k] = -1;
    int t=1;
    while(scanf("%s", seq)) {
        if(!strcmp("#", seq)) return 0;
        int n = conv(seq);
//        cout << n << endl;
        vector<int>sol4, sol6;
        sol4.pb(4); sol6.pb(6);
        printf("%d: ", n);
        bigint ans = 2* (f(n-1, 4, 1, sol4)+f(n-1, 6, 0, sol6));
        print(ans);
        printf("\n");
    }
    return 0;
}
