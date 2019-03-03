#include<bits/stdc++.h>

using namespace std;

struct info{
    int u;
    string seq;
    info() {}
    info(int uu, string ss) {
        u = uu; seq = ss;
    }
    bool operator < (const info &b) const {
        return seq.size() < b.seq.size() || seq < b.seq
    }
};

int main() {
    while(scanf("%s", &str)) {

    }
}
