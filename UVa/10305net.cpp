#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define N 1000000

using namespace std;

int main() {

    int n;
    int m;

    while ( scanf ("%d %d", &n, &m ) ) {
        if ( n == 0 && m == 0 )
            break;

        vector <int> matrix [100 + 2];
        int indegree [100 + 2];
        memset (indegree, 0, 102 * sizeof (int));

        for ( int i = 0; i < m; i++ ) {
            int x;
            int y;

            scanf ("%d %d", &x, &y);

            matrix [x].push_back (y);
            indegree [y]++;
        }

        queue <int> Q;

        for ( int i = 1; i <= n; i++ ) {
            if ( indegree [i] == 0 )
                Q.push (i);
        }

        vector <int> sortedList;

        while ( !Q.empty () ) {
            int pop = Q.front ();
            Q.pop ();

            sortedList.push_back (pop);

            for ( unsigned int i = 0; i < matrix [pop].size (); i++ ) {
                indegree [matrix [pop] [i]]--;
                if ( indegree [matrix [pop] [i]] == 0 )
                    Q.push (matrix [pop] [i]);
            }
        }

        printf ("%d", sortedList [0]);

        for ( unsigned int i = 1; i < sortedList.size (); i++ )
            printf (" %d", sortedList [i]);

        printf ("\n");
    }
    return 0;
}
