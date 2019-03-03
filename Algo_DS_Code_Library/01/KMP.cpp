/// if you use kmp on non-string problem, make sure data is not kept in
/// string, strings can only hold char which has max value of 255

#include<bits/stdc++.h>

using namespace std;

string text, pattern;
int sizeText, sizePattern;
int prefix[LIM];
vector<int>results;

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

void matchingCheck() {
    int i=1, j=1, k=1;
    while(i < sizeText) {
        while(j < sizePattern && text[i] == pattern[j]) i++ , j++;
        if(j == sizePattern) results.push_back(k);
        if(prefix[j-1] > 0) k = i - prefix[j-1];
        else {
            if(i == k) i++;
            k = i;
        }
        if(j > 1) j = prefix[j-1] + 1;
    }
}

int main() {

    cin >> text;
    cin >> pattern;

    text = "0" + text;
    pattern = "0" + pattern;

//    cout << text << ' ' << pattern << endl;

    sizeText = text.size(), sizePattern = pattern.size();

//    cout << sizeText << endl;

    generatePrefix();
    matchingCheck();

    cout << "PREFIX" << endl;
    for(int i=0; i<pattern.size(); i++) cout << prefix[i] << ' '; cout << endl;

    cout << "RESULTS " << endl;
    for(int i=0; i<results.size(); i++)  cout << results[i] << ' ';
    cout << endl;

    return 0;
}
