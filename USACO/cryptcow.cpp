/*
ID: Jugglebrosjr2
LANG: C++
TASK: cryptcow
*/
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MOD 7900001
typedef unsigned int u32;

bitset<MOD> hashTable;

u32 elfHash(void *key, int len) {
    unsigned char *p = static_cast<unsigned char*>(key);
    u32 ret = 0, g;
    for (int i = 0; i < len; i++) {
        ret = (ret << 4) + p[i];
        g = ret & 0xf0000000L;
        if (g) {
            ret ^= g >> 24;
        }
        ret &= ~g;
    }
    return ret % MOD;
}

bool decrypt(char* src, int srcLen, char* targ, int targLen) {
    if (srcLen < targLen || (srcLen - targLen) % 3 != 0) {
        return false;
    }

    if (srcLen == targLen) {
        for (int i = 0; i < srcLen; i++) {
            if (src[i] != targ[i]) {
                return false;
            }
        }
        return true;
    }

    u32 h = elfHash(src, srcLen);
    if (hashTable[h]) {
        return false;
    }
    hashTable[h] = true;

    int cPos[srcLen], oPos[srcLen], wPos[srcLen], pos[srcLen];
    int cNum = 0, oNum = 0, wNum = 0, posNum = 0;
    for (int i = 0; i < srcLen; i++) {
        if (src[i] == 'C') {
            cPos[cNum++] = i;
            pos[posNum++] = i;
        } else if (src[i] == 'O') {
            oPos[oNum++] = i;
            pos[posNum++] = i;
        } else if (src[i] == 'W') {
            wPos[wNum++] = i;
            pos[posNum++] = i;
        }
    }

    if (cNum == 0 || oNum == 0 || wNum == 0
            || srcLen - posNum != targLen
            || cNum != oNum || oNum != wNum
            || oPos[0] < cPos[0] || wPos[0] < cPos[0]
            || cPos[cNum - 1] > wPos[wNum - 1]
            || oPos[oNum - 1] > wPos[wNum - 1]) {
        return false;
    }
    for (int i = 0; i < cPos[0]; i++) {
        if (src[i] != targ[i]) {
            return false;
        }
    }

    pos[posNum++] = srcLen;
    char substr[srcLen];
    //cout << srcLen << '\n';
    //cout << src << '\n';
    for (int i = 0; i < posNum; i++) {
        int start = (i == 0 ? 0 : pos[i - 1] + 1);
        if (pos[i] > pos[i - 1] + 1) {
            for (int j = start; j < pos[i]; j++) {
                substr[j - start] = src[j];
            }
            substr[pos[i] - start] = '\0';
            if (!strstr(targ, substr)) {
                return false;
            }
            //cout << substr << '\n';
        }
    }
    //cout << "\n";

    for (int i = 0; i < cNum; i++) {
        for (int j = 0; j < oNum; j++) {
            for (int k = wNum - 1; k >= 0; k--) {
                if (cPos[i] < oPos[j] && oPos[j] < wPos[k]) {
                    //cout << cPos[i] << ' ' << oPos[j] << ' ' << wPos[k] << '\n';
                    char newSrc[srcLen - 2];
                    for (int m = 0; m < cPos[i]; m++) {
                        //cout << m << ' ' << m << '\n';
                        newSrc[m] = src[m];
                    }
                    for (int m = oPos[j] + 1; m < wPos[k]; m++) {
                        //cout << m << ' ' << cPos[i] + m - oPos[j] - 1 << '\n';
                        newSrc[cPos[i] + m - oPos[j] - 1] = src[m];
                    }

                    for (int m = cPos[i] + 1; m < oPos[j]; m++) {
                        //cout << m << ' ' << wPos[k] - oPos[j] + m - 2 << '\n';
                        newSrc[wPos[k] - oPos[j] + m - 2] = src[m];
                    }
                    for (int m = wPos[k] + 1; m < srcLen; m++) {
                        //cout << m << ' ' << m - 3 << '\n';
                        newSrc[m - 3] = src[m];
                    }
                    newSrc[srcLen - 3] = '\0';
                    //cout << newSrc << '\n';
                    if (decrypt(newSrc, srcLen - 3, targ, targLen)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ifstream fin("cryptcow.in");
    ofstream fout("cryptcow.out");
    string targS = "Begin the Escape execution at the Break of Dawn";
    string srcS;
    getline(fin, srcS);
    char targ[targS.size() + 1];
    for (int i = 0; i < targS.size(); i++) {
        targ[i] = targS.at(i);
    }
    targ[targS.size()] = '\0';
    char src[srcS.size() + 1];
    for (int i = 0; i < srcS.size(); i++) {
        src[i] = srcS.at(i);
    }
    src[srcS.size()] = '\0';
    bool reached = decrypt(src, srcS.size(), targ, targS.size());
    if (reached) {
        fout << "1 " << (reached ? (srcS.size() - targS.size()) / 3 : 0) << '\n';
    } else {
        fout << "0 0\n";
    }
    return 0;
}
