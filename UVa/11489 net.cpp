#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;


int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    int cases = 0;

    while ( testCase-- ) {
        char num [1000 + 10];
        scanf ("%s", num);

        int freq [10 + 3];
        memset (freq, 0, sizeof (freq));

        int sum = 0;

        for ( int i = 0; num [i]; i++ ) {
            sum += num [i] - '0';
            freq [num [i] - '0']++;
        }

        int allowed_move = freq [3] + freq [6] + freq [9];

        printf ("Case %d: ", ++cases);

        bool s_win = true;

        if ( sum % 3 == 0 ) {
            if ( allowed_move % 2 == 0 ) s_win = false;
        }

        else if ( sum % 3 == 1 ) {
            if ( freq [1] || freq [4] || freq [7] ) {
                if ( allowed_move % 2 ) s_win = false;
            }
            else s_win = false;
        }

        else {
            if ( freq [2] || freq [5] || freq [8] ) {
                if ( allowed_move % 2 ) s_win = false;
            }
            else s_win = false;
        }

        if ( s_win ) printf ("S\n");
        else printf ("T\n");

    }

    return 0;
}
