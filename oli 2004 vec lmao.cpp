#include <iostream>
#include <fstream>

using namespace std;

ifstream in("sir.in");
ofstream out("sir.out");

int n, cifVec[10], nrGen, aux, nr;

void citesteVec(int mNr) {
    while (mNr > 0)
    {
        if (mNr % 10 != 0)
            cifVec[mNr % 10]++;
        mNr /= 10;
    }
}

void genereazaNr() {
    nrGen = 0;
    for (int i = 1; i <= 9; i++) {
        if (cifVec[i] != 0) {
            nrGen *= 10;
            nrGen += cifVec[i];
        }
    }
}

void resetVec() {
    for (int i = 1; i <= 9; i++)
        cifVec[i] = 0;
}

void citeste() {
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> nr;
        citesteVec(nr);
    }
}

int main()
{
    citeste();
    genereazaNr();
    while (nrGen > 9)
    {
        resetVec();
        citesteVec(nrGen);
        genereazaNr();
    }
    out << nrGen;
}