1  // UVa1628 Pizza Delivery
 2  // Rujia Liu
3 #include <cstdio>
 4 #include <cstring>
 5 #include <algorithm>
 6  using  namespace std;
 7
8  const  int maxn = 100 + 5 ;
 9
10  int kase, n ;
 11  int p [maxn], v [maxn];
 12  int d [maxn] [maxn] [maxn] [ 2 ];
 13  int vis [maxn] [maxn] [maxn] [ 2 ];
 14
15  //Considered E ~ S already, need to Still CNT Delivery to people.
 16  // POS S = 0 means AT, AT means POS. 1 = E
. 17  int DP ( int S, int E, int CNT, int POS) {
 18 is    IF ( cnt == 0 ) return  0 ;           // cnt == 0 return
19
20    int & ans = d [s] [e] [cnt] [pos];           // memory search
21    if (vis [s] [e] [ cnt] [pos] == kase) return ans;
 22    vis [s] [e] [cnt] [pos] = kase;
 23
24    ans = 0 ;
 25    // The part of the enumeration between i and the previous interval will not be fed by default // Compare max_ans
26    if (! Pos ) {                          // pos == s
27      for ( int i = 0 ; I <S; I ++)   // S-> I   // I on the left side section
28        ANS = max (ANS, V [I] - CNT * ABS (P [I] - P [S]) + DP (I , E, CNT - . 1 , 0 ));
 29      // ANS = max (ANS, known enough future value + the value of the sub-questions)
30      for ( int I = E + . 1 ; I <n-; I ++) //s-> i // i to the right of the interval
31        ans = max (ans, v [i] - cnt * abs (p [i] - p [s]) + dp (s, i, cnt - 1 , 1 ) );
 32    }
 33    else {                              // pos == e
34      for ( int i = 0 ; i <s; i ++)   // e-> i   // i on the left side of the interval
35        ans = max (ans, v [i ] - cnt * abs (p [i] - p [e]) + dp (i, e, cnt- 1 , 0 ));
 36      for ( int i = e + 1 ; i <n; i ++) // e -> i  // I of the right section
37 [        ANS = max (ANS, V [I] - CNT * ABS (P [I] - P [E]) + DP (S, I, CNT - . 1 , . 1 ));
 38 is    }
 39    return ans;
 40  }
 41
42  // DP To enumerate all cases with the best possible odds can not be missed otherwise the problem may not be optimal.
43
44  int main () {
 45    int T;
 46    scanf ( " % d " , & T);
 47    memset (vis, 0 , sizeof (vis));
 48    for (kase = 1 ; kase <= T; kase ++ ) {
49      Scanf ( " % D " , & n-);
 50      for ( int I = 0 ; I <n-; I ++) Scanf ( " % D " , & P [I]);    // position []
51 is      for ( int I = 0 ; i <n; i ++) scanf ( " % d " , & v [i]);    // Formerly []
52
53      int ans = 0 ;
 54      for ( int k = 1 ; k <= n; k ++)       / / Enumerate the number of meals
55        for( int i = 0 ; i <n; i ++)      // Enumerate the first person who sent the meal
56          ans = max (ans, v [i] - k * abs (p [i]) + dp (i, I, K - . 1 , 0 ));   // enumeration Comparative make_max
57 is      the printf ( " % D \ n- " , ANS);
 58    }
 59    return  0 ;
 60 }
