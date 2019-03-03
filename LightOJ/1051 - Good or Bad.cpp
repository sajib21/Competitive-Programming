#include<bits/stdc++.h>
#define VOWEL 1
#define CONSO 2
#define QMARK 3
#define BAD 1
#define MIXED 2
#define GOOD 3

using namespace std;

string seq;
int sz;
bool isMix;

int getCon(int indx, int lastMainLetter, int lastLetter, int lastCount, bool ifQ, int QIndx, bool extra) {

    if(indx == sz) {
        if(isMix == true) return MIXED;
        else return GOOD;
    }

    if(seq[indx] == '?') {
        if(lastLetter == VOWEL || (lastLetter == QMARK && lastMainLetter == VOWEL) ) {
            if(lastCount == 2) {
                if(extra == true) {
                    if(lastLetter == VOWEL)
                        return getCon(indx+1, CONSO, CONSO, 1, false, 0, false);
                    else return getCon(indx+1, VOWEL, VOWEL, 1, false, 0, false);
                }
                isMix = true;
                if(!ifQ) return getCon(indx+1, VOWEL, QMARK, 1, true, indx, true);
                else return getCon(indx+1, VOWEL, QMARK, 1, true, indx, false);
            }
            else return getCon(indx+1, VOWEL, QMARK, lastCount+1, true, indx, false);
        }
        else if(lastLetter == CONSO || lastMainLetter == CONSO) {
            if(lastCount == 4) {
                if(extra == true) {
                    if(lastLetter == CONSO)
                        return getCon(indx+1, VOWEL, VOWEL, 1, false, 0, false);
                    else return getCon(indx+1, CONSO, CONSO, 1, false, 0, false);
                }
                isMix = true;
                if(!ifQ) return getCon(indx+1, CONSO, QMARK, 1, true, indx, true);
                else return getCon(indx+1, CONSO, QMARK, 1, true, indx, false);
            }
            else return getCon(indx+1, CONSO, QMARK, lastCount+1, true, indx, false);
        }
        if(lastMainLetter == 0) {
            if(lastCount == 2) {
                isMix = true;
                return getCon(indx+1, lastMainLetter, QMARK, 1, true, indx, false);
            }
            else return getCon(indx+1, lastMainLetter, QMARK, lastCount+1, true, indx, false);
        }
    }

    else if(seq[indx] == 'A' || seq[indx] == 'E' || seq[indx] == 'I' || seq[indx] == 'O' || seq[indx] == 'U') {
        if(lastLetter == VOWEL || lastLetter == QMARK) {
            if(lastLetter == QMARK && lastCount == 1 && extra == true) {
                if(!(seq[indx-2] == 'A' || seq[indx-2] == 'E' || seq[indx-2] == 'I' || seq[indx-2] == 'O' || seq[indx-2] == 'U'))
                    return getCon(indx+1, VOWEL, VOWEL, lastCount+1, ifQ, QIndx, extra);
                else return getCon(indx+1, VOWEL, VOWEL, 1, false, 0, false);
            }



            else if(lastMainLetter == CONSO) {
                if(seq[indx-1] == '?' && seq[indx-2] == '?') isMix = true;
                return getCon(indx+1, VOWEL, VOWEL, 2, ifQ, QIndx, false);
            }

            else if(lastCount == 2) {
                if(!ifQ) return BAD;
                else {
                    if(extra == true) return BAD;
                    isMix = true;
                    return getCon(indx+1, VOWEL, VOWEL, indx-QIndx, false, 0, false);
                }
            }
            return getCon(indx+1, VOWEL, VOWEL, lastCount+1, ifQ, QIndx, extra);
        }
        else {
            return getCon(indx+1, VOWEL, VOWEL, 1, false, 0, false);
        }

    }

    else {
        if(lastLetter == CONSO || lastLetter == QMARK) {
            if(lastLetter == QMARK && lastCount == 1 && extra == true) {
                if((seq[indx-2] == 'A' || seq[indx-2] == 'E' || seq[indx-2] == 'I' || seq[indx-2] == 'O' || seq[indx-2] == 'U'))
                    return getCon(indx+1, CONSO, CONSO, lastCount+1, ifQ, QIndx, extra);
                else return getCon(indx+1, CONSO, CONSO, 1, false, 0, false);
            }

            else if(lastMainLetter == VOWEL) {
                return getCon(indx+1, CONSO, CONSO, 2, ifQ, QIndx, false);
            }

            else if(lastCount == 4) {
                if(!ifQ) return BAD;
                else {
                    if(extra == true) return BAD;
                    isMix = true;
                    return getCon(indx+1, CONSO, CONSO, indx-QIndx, false, 0, false);
                }
            }
            return getCon(indx+1, CONSO, CONSO, lastCount+1, ifQ, QIndx, extra);
        }
        else {
            return getCon(indx+1, CONSO, CONSO, 1, false, 0, false);
        }
    }

}

int main() {

    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        isMix = false;
        cin >> seq;
        sz = seq.size();

        int res1 = getCon(0,0,0,0,0,0,0);

        if(res1 == GOOD ) printf("Case %d: GOOD\n", t);
        else if(res1 == BAD) printf("Case %d: BAD\n", t);
        else printf("Case %d: MIXED\n", t);
    }

    return 0;
}
