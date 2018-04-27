#include <fstream>
#include <iostream>
#include "GramaticaRegulata.h"

using namespace std;

/**
 * constructor gramatica regulata
 * @param numele fisierului in care este definita gramatica
 */
GramaticaRegulata::GramaticaRegulata(const char *fisier) {
    numarSimboluriNeterminale = numarSimboluriTerminale = numarProductii = 0;
    ifstream f(fisier);
    int i;
    f >> numarSimboluriNeterminale;
    simboluriNeterminale = new char[numarSimboluriNeterminale];
    for (i = 0; i < numarSimboluriNeterminale; i++)
        f >> simboluriNeterminale[i];
    f >> numarSimboluriTerminale;
    simboluriTerminale = new char[numarSimboluriTerminale];
    for (i = 0; i < numarSimboluriTerminale; i++)
        f >> simboluriTerminale[i];
    f >> numarProductii;
    reguliDeProductie = new productie[numarProductii];
    for (i = 0; i < numarProductii; i++) {
        f >> reguliDeProductie[i].simbolNeterminal1;
        f >> reguliDeProductie[i].simbolTerminal;
        f >> reguliDeProductie[i].simbolNeterminal2;
    }
    f.close();
    simbolCurent = 'S'; //simbolul de start este mereu S
}

/**
 * destructor
 */
GramaticaRegulata::~GramaticaRegulata() {
    delete[] simboluriNeterminale;
    delete[] simboluriTerminale;
    delete[] reguliDeProductie;
}

/**
 * afisare gramatica regulata
 */
void GramaticaRegulata::afisare() {
    int i;
    cout << numarSimboluriNeterminale << endl;
    for (i = 0; i < numarSimboluriNeterminale; i++)
        cout << simboluriNeterminale[i] << ' ';
    cout << endl << numarSimboluriTerminale << endl;
    for (i = 0; i < numarSimboluriTerminale; i++)
        cout << simboluriTerminale[i] << ' ';
    cout << endl << numarProductii << endl;
    for (i = 0; i < numarProductii; i++) {
        cout << reguliDeProductie[i].simbolNeterminal1 << ' ';
        cout << reguliDeProductie[i].simbolTerminal << ' ';
        cout << reguliDeProductie[i].simbolNeterminal2 << endl;
    }
    cout << simbolCurent;
}