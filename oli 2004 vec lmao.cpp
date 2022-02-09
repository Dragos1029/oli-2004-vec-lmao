#include <iostream>
#include <fstream>

using namespace std;

ifstream in("sir.in");
ofstream out("sir.out");

int n, nr, cifVec[10];

void citeste() {
    in >> nr;
    while (nr > 0)
    {
        if (nr % 10 != 0)
            cifVec[nr % 10]++;
        nr /= 10;
    }
}

int main()
{
    in >> n;
    for (int i = 1; i <= n; i++)
        citeste();

}