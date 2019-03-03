#include <bits/stdc++.h>

using namespace std;

int gold[35];
int tim[35];

int main()
{

    while(1)
    {
        int t,w;
        cin >> t >> w;
        //double time = 1.0*t/w;
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> tim[i] >> gold[i];
            tim[i] *= (3*w);
        }

    }
}
