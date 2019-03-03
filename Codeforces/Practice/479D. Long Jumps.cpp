#include<bits/stdc++.h>
#define LIM 100000
using namespace std;

int main() {

	int n,l,x,y, ara[LIM+10];
	map<int, int> mp;
	cin >> n >> l >> x >> y;
	for(int i=0; i<n; i++) {
		scanf("%d", &ara[i]);
		mp[ ara[i] ] = 1;
	}
	int cx=1, cy=1;

	for(int i=0; i<n; i++) {
		if( mp[ ara[i]+x ] || mp[ ara[i]-x ]) {
			cx = 0;
			break;
		}
	}

	 for(int i=0; i<n; i++) {
		if( mp[ ara[i]+y ] || mp[ ara[i]-y ]) {
			cy = 0;
			break;
		}
	}

	if((cx+cy) == 0) {
		cout << 0 << endl;
		return 0;
	}

	if(cx+cy==2) {
		if(x==y) {
			cout << 1 << endl << x << endl;
			return 0;
		}

		for(int i=0; i<n; i++) {
            if(mp[ ara[i]+x+y ] ) {
                cout << 1 << endl << ara[i]+x << endl;
                return 0;
            }
        }
        for(int i=0; i<n; i++) {
            if(mp[ ara[i]+x-y ]) {
                if(ara[i]+x <= l) {
                    cout << 1 << endl << ara[i]+x << endl;
                    return 0;
                }
                else if(ara[i]-y >= 0) {
                    cout << 1 << endl << ara[i]-y << endl;
                    return 0;
                }

            }
            if(mp[ ara[i]-x+y ]) {
                if(ara[i]+y <= l) {
                    cout << 1 << endl << ara[i]+y << endl;
                    return 0;
                }
                else if(ara[i]-x >= 0) {
                    cout << 1 << endl << ara[i]-x << endl;
                    return 0;
                }

            }
        }

        cout << 2 << endl;
        cout << x << ' ' << y << endl;

		return 0;
	}

	cout << 1 << endl;
	if(cx) cout << x << endl;
	else cout << y << endl;

	return 0;
}
