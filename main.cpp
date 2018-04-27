#include <iostream>
#include <fstream>
#include <cstring>
#include "GramaticaRegulata.h"

using namespace std;

int main() {
    int numarCuvinte, i;
    GramaticaRegulata gramatica("gramaticaregulata.in");
    ifstream f("cuvinte.in");
    f >> numarCuvinte;
    for (i = 0; i < numarCuvinte; i++) {
        char *cuvant = new char[101];
        f >> cuvant;
        if (strcmp(cuvant, "_") == 0) //daca am cuvantul vid
            cuvant[0] = '\0';
        if (gramatica.verificare(cuvant))
            cout << "Cuvantul " << cuvant << " apartine limbajului generat de gramatica" << '\n';
        else cout << "Cuvantul " << cuvant << " nu apartine limbajului generat de gramatica" << '\n';
        delete[] cuvant;
        gramatica.reinitializareSimbolCurent();
    }
    f.close();
    return 0;
}
