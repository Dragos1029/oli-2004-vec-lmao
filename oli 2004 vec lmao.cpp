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
    citeste();              //citim din fisier si punem in vec
    genereazaNr();          //generam nr. folosind valorile din vec
    while (nrGen > 9)       //repetam pana cand gasim nr. cerut
    {
        resetVec();         //resetam vec la 0
        citesteVec(nrGen);  //citim din nr. si punem in vec
        genereazaNr();      //generam un nr. nou
    }
    out << nrGen;
}